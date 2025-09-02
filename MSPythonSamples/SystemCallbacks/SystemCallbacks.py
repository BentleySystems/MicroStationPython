# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $


import os
from tkinter import messagebox
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *

'''
Sample demonstrating how system callback works in Python
'''

FILE = os.path.abspath(__file__)

def OnNewDesignFile(file, reason):
    """
    Callback function that is triggered when a new design file is created or closed.

    :param file: The design file that triggered the callback.
    :type file: str
    :param reason: The reason for the callback trigger.
    :type reason: NewDesignFileReason
    """
    if reason == NewDesignFileReason.eSYSTEM_NEWFILE_CLOSE:
        message = "[file]: " + str(file)
        message += "\n"
        message += "[reason]: " + str(reason)
        print("Callback OnNewDesignFile:\n" + message)

def OnUnloadProgram(reason):
    """
    Callback function that is triggered when a program is unloaded.

    :param reason: The reason for unloading the program.
    :type reason: str
    """
    message = "[reason]: " + str(reason)
    print("Callback OnUnloadProgram:\n" + message)

def OnFileSaveAs(postSave, destinationFileName):
    """
    Callback function that is triggered after a file is saved with a new name.

    :param postSave: A boolean indicating whether the save operation was successful.
    :type postSave: bool
    :param destinationFileName: The name of the file after it has been saved.
    :type destinationFileName: str
    """
    message = "[post save]: " + str(postSave)
    message += "\n"
    message += "[destination file name]: " + str(destinationFileName)
    print("Callback OnFileSaveAs:\n" + message)

def OnFileSave(when, changesFlag, reason, timestamp, file):
    """
    Callback function that is triggered when a file is saved.

    :param when: The time when the file was saved.
    :type when: str
    :param changesFlag: A flag indicating the changes made to the file.
    :type changesFlag: bool
    :param reason: The reason for saving the file.
    :type reason: str
    :param timestamp: The timestamp of the save event.
    :type timestamp: str
    :param file: The file object that was saved.
    :type file: object or None
    
    :return: None
    """
    message = "[when]: " + str(when)
    message += "\n"
    message += "[changes flag]: " + str(changesFlag)
    message += "\n"
    message += "[reason]: " + str(reason)
    message += "\n"
    message += "[time stamp]: " + str(timestamp)
    if file is not None:
        message += "\n"
        message += "[file]: " + str(file.GetFileName())
    print("Callback OnFileSave:\n" + message)

def OnFenceChange(changeType):
    """
    Callback function that handles changes to the system fence.

    :param changeType: The type of change that occurred. This should be one of the values from the FenceChangedType enumeration.
    :type changeType: FenceChangedType

    The function prints a message indicating whether a system fence was created or cleared based on the changeType provided.
    """
    if FenceChangedType.eSYSTEM_FENCE_CREATED == changeType:
        message = "[change type]: " + str(changeType)
        print("Callback OnFenceChange, Fence created:\n" + message)
    elif FenceChangedType.eSYSTEM_FENCE_CLEARED == changeType:
        message = "[change type]: " + str(changeType)
        print("Callback OnFenceChange, Fence cleared:\n" + message)

def OnCompressDgnFile(errorMessage, type):
    """
    Callback function for handling DGN file compression events.

    This function is called when a DGN file compression event occurs. It checks the type of compression event
    and assigns an error message if the event type is `ePRE_COMPRESS_DGNFILE`.

    :param errorMessage: An object that allows assigning an error message.
    :type errorMessage: ErrorMessage
    :param type: The type of compression event.
    :type type: CompressType
    
    :return: The status of the compression event handling.
    :rtype: BentleyStatus
    """
    if CompressType.ePRE_COMPRESS_DGNFILE == type:
        errorMessage.AssignA("Compress error test!")
        message = "[type]: " + str(type)
        print("Callback OnCompressDgnFile:\n" + message)
        return BentleyStatus.eERROR

def OnCompressDgnModel(dgnModel, type):
    """
    Callback function that is triggered when a DGN model is compressed.

    :param dgnModel: The DGN model object that is being compressed.
    :type dgnModel: object
    :param type: The type of compression being performed.
    :type type: str
    """
    message = "[dgnModel]: " + str(dgnModel.GetModelName())
    message += "\n"
    message += "[type]: " + str(type)
    print("Callback OnCompressDgnModel:\n" + message)

def OnDgnFileLoaded(dgnFile):
    """
    Callback function that is triggered when a DGN file is loaded.

    :param dgnFile: The DGN file object that has been loaded.
    :type dgnFile: object
    """
    message = "[dgnFile]: " + str(dgnFile.GetFileName ())
    print("Callback OnDgnFileLoaded:\n" + message)

def OnDgnFileUnloading(dgnFile):
    """
    Callback function that is triggered when a DGN file is unloading.

    :param dgnFile: The DGN file that is being unloaded.
    :type dgnFile: object
    """
    message = "[dgnFile]: " + str(dgnFile.GetFileName ())
    print("Callback OnDgnFileUnloading:\n" + message)

def OnQueryHasPending(dgnFile):
    """
    Callback function that checks if there are any pending queries for the given DGN file.

    :param dgnFile: The DGN file object to check for pending queries.
    :type dgnFile: DgnFile
    
    :return: Always returns True.
    :rtype: bool
    """
    message = "[dgnFile]: " + str(dgnFile.GetFileName ())
    print("Callback OnQueryHasPending:\n" + message)
    return True

def OnDgnCacheUnloading(dgnModel): 
    """
    Callback function that is triggered when a DGN cache is unloading.

    :param dgnModel: The DGN model that is unloading. It is expected to have methods `GetModelId` and `GetModelName`.
    :type dgnModel: object
    """
    message = ""
    if dgnModel is not None and dgnModel.GetModelId() >= 0:
        message += "[dgnModel]: " + str(dgnModel.GetModelName())
    else:
        message += "[dgnModel Id]: " + str(dgnModel.GetModelId())
    print("Callback OnDgnCacheUnloading:\n" + message)

def OnMasterfileClosed(): 
    """
    Callback function that is triggered when the master file is closed.

    This function is intended to be used as a callback and will execute
    when the master file is closed. It currently prints a message to the console.

    :return: None
    """
    print("Callback OnMasterfileClosed.")

def OnSetModelChangeFunction(modelRef, changeTypeId): 
    """
    Callback function that handles model change events.

    :param modelRef: Reference to the model object. If None, indicates no model reference.
    :type modelRef: object or None
    :param changeTypeId: Identifier for the type of change that occurred.
    :type changeTypeId: int
    """
    if modelRef is not None:
        message = "[modelRef]: " + str(modelRef.GetDgnModel().GetModelName())
    else:
        message = "[modelRef]: " + str(modelRef)
    message += "\n"
    message += "[change type Id]: " + str(changeTypeId)
    print("Callback OnSetModelChangeFunction:\n" + message)

def OnModelRefDestroy(modelRef): 
    """
    Callback function that is triggered when a model reference is destroyed.

    :param modelRef: The model reference that is being destroyed. It can be None.
    :type modelRef: object or None
    """
    if modelRef is not None:
        message = "[modelRef]: " + str(modelRef.GetDgnModel().GetModelName())
    else:
        message = "[modelRef]: " + str(modelRef)
    print("Callback OnModelRefDestroy:\n" + message)

def OnExitDesignFileState(): 
    """
    Callback function that is triggered when exiting the design file state.

    This function is called to perform any necessary cleanup or finalization
    tasks when the design file state is exited. It currently prints a message
    indicating that the callback has been triggered.
    """
    print("Callback OnExitDesignFileState.")

def OnMessageCenterWrite(messageType, messageInput, detail, detailMessageAttributes):
    """
    Callback function that handles message center write events.

    :param messageType: The type of the message.
    :type messageType: str
    :param messageInput: The content of the message.
    :type messageInput: str
    :param detail: Additional details about the message.
    :type detail: str
    :param detailMessageAttributes: Attributes related to the detail message.
    :type detailMessageAttributes: dict
    """
    message = "[message type]: " + str(messageType)
    message += "\n"
    message += "[message]: " + str(messageInput)
    message += "\n"
    message += "[detail]: " + str(detail)
    message += "\n"
    message += "[detail message attributes]: " + str(detailMessageAttributes)
    print("Callback OnMessageCenterWrite:\n" + message)

def OnPromptOutput(text, combinedText, fieldNumber):
    """
    Callback function that processes and prints prompt output details.

    :param text: The text output from the prompt.
    :type text: str
    :param combinedText: The combined text output from the prompt.
    :type combinedText: str
    :param fieldNumber: The field number associated with the prompt output.
    :type fieldNumber: int
    """
    message = "[text]: " + str(text)
    message += "\n"
    message += "[combined text]: " + str(combinedText)
    message += "\n"
    message += "[field number]: " + str(fieldNumber)
    print("Callback OnPromptOutput:\n" + message)

def OnStatusOutput(text, fieldNumber):
    """
    Callback function that handles status output.

    :param text: The status message to be output.
    :type text: str
    :param fieldNumber: The field number associated with the status message.
    :type fieldNumber: int
    """
    message = "[text]: " + str(text)
    message += "\n"
    message += "[field number]: " + str(fieldNumber)
    print("Callback OnStatusOutput:\n" + message)

def OnApplicationAreaChange(): 
    """
    Callback function that gets triggered when the application area changes.

    This function is called automatically by the system when there is a change
    in the application area. It currently prints a message indicating that the
    callback has been triggered.

    Note:
        This is a sample callback function and can be modified to include
        additional logic as needed.

    """
    print("Callback OnApplicationAreaChange.")

def OnReferenceBeforeAttach(fileName, parentModelRef):
    """
    Callback function that is triggered before a reference is attached.

    :param fileName: The name of the file to be attached.
    :type fileName: str
    :param parentModelRef: The reference to the parent model. Can be None.
    :type parentModelRef: ModelReference or None
    
    :return: Status of the operation.
    :rtype: BentleyStatus
    """
    message = "[file name]: " + str(fileName)
    message += "\n"
    if parentModelRef is not None:
        message += "[parent modelRef]: " + str(parentModelRef.GetDgnModel().GetModelName())
    else:
        message += "[parent modelRef]: " + str(parentModelRef)
    print("Callback OnReferenceBeforeAttach:\n" + message)
    return BentleyStatus.eSUCCESS

def OnReferenceAttach(fileName, fullSavedPath, parentModelRef, providerId, attachmentId):
    """
    Callback function triggered when a reference is attached.

    :param fileName: The name of the file being attached.
    :type fileName: str
    :param fullSavedPath: The full saved path of the file being attached.
    :type fullSavedPath: str
    :param parentModelRef: The reference to the parent model. Can be None.
    :type parentModelRef: object or None
    :param providerId: The ID of the provider.
    :type providerId: int
    :param attachmentId: The ID of the attachment.
    :type attachmentId: int
    
    :return: Status of the operation.
    :rtype: BentleyStatus
    """
    message = "[file name]: " + str(fileName)
    message += "\n"
    message += "[full saved path]: " + str(fullSavedPath)
    message += "\n"
    if parentModelRef is not None:
        message += "[parent modelRef]: " + str(parentModelRef.GetDgnModel().GetModelName())
    else:
        message += "[parent modelRef]: " + str(parentModelRef)
    message += "\n"
    message += "[provider Id]: " + str(providerId)
    message += "\n"
    message += "[attachment Id]: " + str(attachmentId)
    print("Callback OnReferenceAttach:\n" + message)
    return BentleyStatus.eSUCCESS

def OnReferenceAttached(modelRef,  cause):
    """
    Callback function that is triggered when a reference is attached to a model.

    :param modelRef: The reference to the model being attached. If None, indicates no model reference.
    :type modelRef: object
    :param cause: The cause or reason for the attachment.
    :type cause: str
    """
    message = ""
    if modelRef is not None:
        message += "[modelRef]: " + str(modelRef.GetDgnModel().GetModelName())
    else:
        message += "[modelRef]: " + str(modelRef)
    message += "\n"
    message += "[cause]: " + str(cause)
    print("Callback OnReferenceAttached:\n" + message)

def OnReferenceAttachQueue(state):
    """
    Callback function that is triggered when a reference is attached to the queue.

    :param state: The state information related to the reference attachment.
    :type state: Any
    """
    message = "[state]: " + str(state)
    print("Callback OnReferenceAttachQueue:\n" + message)

def OnReferenceDetach(modelRef):
    """
    Callback function that is triggered when a reference is detached.

    :param modelRef: The reference model that is being detached. It can be None.
    :type modelRef: ModelReference or None
    
    :return: Status of the operation.
    :rtype: BentleyStatus
    """
    message = ""
    if modelRef is not None:
        message += "[modelRef]: " + str(modelRef.GetDgnModel().GetModelName())
    else:
        message += "[modelRef]: " + str(modelRef)
    print("Callback OnReferenceDetach:\n" + message)
    return BentleyStatus.eSUCCESS

def OnReferenceDetached(modelRef, fileName, cause):
    """
    Callback function that is triggered when a reference is detached.

    :param modelRef: The reference to the model that is being detached. 
                     If None, indicates that no model reference is available.
    :type modelRef: object or None
    :param fileName: The name of the file from which the reference is detached.
    :type fileName: str
    :param cause: The cause or reason for the detachment.
    :type cause: str
    """
    message = ""
    if modelRef is not None:
        message += "[modelRef]: " + str(modelRef.GetDgnModel().GetModelName())
    else:
        message += "[modelRef]: " + str(modelRef)
    message += "\n"
    message += "[file name]: " + str(fileName)
    message += "\n"
    message += "[cause]: " + str(cause)
    print("Callback OnReferenceDetached:\n" + message)

def OnReferenceModified(oldRef, newRef, modelRef, changesWritten, isUndo):
    """
    Callback function that is triggered when a reference is modified.

    :param oldRef: The old reference object before modification. Can be None.
    :type oldRef: object or None
    :param newRef: The new reference object after modification. Can be None.
    :type newRef: object or None
    :param modelRef: The model reference object associated with the modification. Can be None.
    :type modelRef: object or None
    :param changesWritten: Indicates whether the changes were written to the file.
    :type changesWritten: bool
    :param isUndo: Indicates whether the modification is an undo operation.
    :type isUndo: bool
    """
    message = ""
    if oldRef is not None:
        message += "[old reference]: " + str(oldRef.GetAttachFileName())
    else:
        message += "[old reference]: " + str(oldRef)

    message += "\n"
    if newRef is not None:
        message += "[new reference]: " + str(newRef.GetAttachFileName())
    else:
        message += "[new reference]: " + str(newRef)

    message += "\n"
    if modelRef is not None:
        message += "[modelRef]: " + str(modelRef.GetDgnModel().GetModelName())
    else:
        message += "[modelRef]: " + str(modelRef)

    message += "\n"
    message += "[changes written]: " + str(changesWritten)
    message += "\n"
    message += "[is undo]: " + str(isUndo)
    print("Callback OnReferenceModified:\n" + message)

def OnReferenceNesting(refModelRef, nestFlag, nestDepth, previousNestFlag, previousNestDepth, changeExisting):
    """
    Callback function that handles reference nesting events.

    :param refModelRef: The reference model object. If None, indicates no reference model.
    :type refModelRef: object or None
    :param nestFlag: The current nesting flag.
    :type nestFlag: bool
    :param nestDepth: The current nesting depth.
    :type nestDepth: int
    :param previousNestFlag: The previous nesting flag.
    :type previousNestFlag: bool
    :param previousNestDepth: The previous nesting depth.
    :type previousNestDepth: int
    :param changeExisting: Flag indicating whether to change existing settings.
    :type changeExisting: bool
    """
    message = ""
    if refModelRef is not None:
        message += "[referenced modelRef]: " + str(refModelRef.GetDgnModel().GetModelName())
    else:
        message += "[referenced modelRef]: " + str(refModelRef)
    message += "\n"
    message += "[nest flag]: " + str(nestFlag)
    message += "\n"
    message += "[nest depth]: " + str(nestDepth)
    message += "\n"
    message += "[previous nest flag]: " + str(previousNestFlag)
    message += "\n"
    message += "[previous nest depth]: " + str(previousNestDepth)
    message += "\n"
    message += "[change existing]: " + str(changeExisting)
    print("Callback OnReferenceNesting:\n" + message)

def OnBeforeReferenceWrite(modelRef, newAttachment):
    """
    Callback function that is triggered before a reference is written.

    :param modelRef: The model reference object. If not None, it provides access to the DGN model.
    :type modelRef: object or None
    :param newAttachment: The new attachment information.
    :type newAttachment: object
    
    :return: None
    :rtype: None
    """
    message = ""
    if modelRef is not None:
        message += "[modelRef]: " + str(modelRef.GetDgnModel().GetModelName())
    else:
        message += "[modelRef]: " + str(modelRef)
    message += "\n"
    message += "[new attachment]: " + str(newAttachment)
    print("Callback OnBeforeReferenceWrite:\n" + message)

def OnFileOutdated(dgnFile, modelRef, reason):
    """
    Callback function that is triggered when a file is outdated.
    
    :param dgnFile: The design file object that is outdated. Can be None.
    :type dgnFile: object or None
    :param modelRef: The model reference object associated with the design file. Can be None.
    :type modelRef: object or None
    :param reason: The reason why the file is considered outdated.
    :type reason: str
    
    :return: Always returns True.
    :rtype: bool
    """
    message = ""
    if dgnFile is not None:
        message += "[dgnFile]: " + str(dgnFile.GetFileName())
    else:
        message += "[dgnFile]: " + str(dgnFile)

    message += "\n"
    if modelRef is not None:
        message += "[modelRef]: " + str(modelRef.GetDgnModel().GetModelName())
    else:
        message += "[modelRef]: " + str(modelRef)
    message += "\n"
    message += "[reason]: " + str(reason)
    print("Callback OnFileOutdated:\n" + message)
    return True

def OnElmDscrCopy(eeh, sourceModelRef, destModelRef, preCopy):
    """
    Callback function that is triggered during the element descriptor copy process.
    
    :param eeh: Element handle, which provides access to the element being copied.
    :type eeh: ElementHandle or None
    :param sourceModelRef: Reference to the source model from which the element is being copied.
    :type sourceModelRef: ModelReference or None
    :param destModelRef: Reference to the destination model to which the element is being copied.
    :type destModelRef: ModelReference or None
    :param preCopy: Boolean flag indicating whether the callback is being called before the copy operation.
    :type preCopy: bool
    
    :returns: None
    :rtype: None
    This function constructs a message containing details about the element being copied, the source model,
    the destination model, and whether the callback is being called before the copy operation. The message
    is then printed to the console.
    """
    message = ""
    if eeh is not None:
        message = "[element Id]: " + str(eeh.GetElementId())
    else:
        message = "[element Id]: " + str(eeh)

    message += "\n"
    if sourceModelRef is not None:
        message += "[source modelRef]: " + str(sourceModelRef.GetDgnModel().GetModelName())
    else:
        message += "[source modelRef]: " + str(sourceModelRef)

    message += "\n"
    if destModelRef is not None:
        message += "[dest modelRef]: " + str(destModelRef.GetDgnModel().GetModelName())
    else:
        message += "[dest modelRef]: " + str(destModelRef)

    message += "\n"
    message += "[pre copy]: " + str(preCopy)
    print("Callback OnElmDscrCopy:\n" + message)

def OnSaveSettings():
    """
    Callback function that is triggered when settings are saved.

    This function is intended to be used as a callback and will be called
    automatically when the save settings event occurs. It currently prints
    a message indicating that the OnSaveSettings callback has been triggered.

    :return: None
    """
    print("Callback OnSaveSettings.")

def OnAcsOperation(name, description, acsType, changeTypeId, acs, eventType):
    """
    Callback function that handles ACS operations and logs the details.

    :param name: The name associated with the ACS operation.
    :type name: str
    :param description: A description of the ACS operation.
    :type description: str
    :param acsType: The type of ACS.
    :type acsType: str
    :param changeTypeId: The ID representing the type of change.
    :type changeTypeId: int
    :param acs: The ACS object, which may be None.
    :type acs: object or None
    :param eventType: The type of event.
    :type eventType: int
    """
    message = "[name]: " + str(name)
    message += "\n"
    message += "[description]: " + str(description)
    message += "\n"
    message += "[acs type]: " + str(acsType)
    message += "\n"
    message += "[change type Id]: " + str(changeTypeId)
    message += "\n"
    if acs is not None:
        message += "[acs]: " + str(acs.GetName())
    else:
        message += "[acs]: " + str(acs)
    message += "\n"
    message += "[event type]: " + str(int(eventType))
    print("Callback OnAcsOperation:\n" + message)

def OnSelectedViewChanged(oldViewIndex, newViewIndex, isFromButtonEvent):
    """
    Callback function that is triggered when the selected view changes.

    :param oldViewIndex: The index of the previously selected view.
    :type oldViewIndex: int
    :param newViewIndex: The index of the newly selected view.
    :type newViewIndex: int
    :param isFromButtonEvent: Indicates whether the change was triggered by a button event.
    :type isFromButtonEvent: bool
    """
    message = "[old view index]: " + str(oldViewIndex)
    message += "\n"
    message += "[new view index]: " + str(newViewIndex)
    message += "\n"
    message += "[is from button event]: " + str(isFromButtonEvent)
    print("Callback OnSelectedViewChanged:\n" + message)

def OnBeforeViewsOpen():
    """
    Callback function that is triggered before views are opened.

    This function is called to perform any necessary actions or checks
    before the views in the application are opened.

    :return: None
    """
    print("Callback OnBeforeViewsOpen.")

def OnViewGroupCacheChange(name, description, changeTypeId):
    """
    Callback function that handles changes in the view group cache.

    :param name: The name of the view group.
    :type name: str
    :param description: A description of the change.
    :type description: str
    :param changeTypeId: The type ID of the change.
    :type changeTypeId: int
    """
    message = "[name]: " + str(name)
    message += "\n"
    message += "[description]: " + str(description)
    message += "\n"
    message += "[change type Id]: " + str(changeTypeId)
    print("Callback OnViewGroupCacheChange:\n" + message)

def OnMonitorViewCommands(starting):
    """
    Callback function that handles monitor view commands.

    This function is triggered to handle commands related to the monitor view.
    It prints a message indicating whether the monitoring has started or not.

    :param starting: A boolean value indicating the state of the monitor view.
                     True if the monitoring is starting, False otherwise.
    :type starting: bool
    """
    message = "[starting]: " + str(starting)
    print("Callback OnMonitorViewCommands:\n" + message)

def OnLockChanged(eventType):
    """
    Callback function that is triggered when the lock state changes.

    :param eventType: The type of event that triggered the callback.
    :type eventType: str
    """
    message = "[eventType]: " + str(eventType)
    print("Callback OnLockChanged:\n" + message)

def OnActiveParamChanged(paramType):
    """
    Callback function that is triggered when an active parameter changes.

    :param paramType: The type of the parameter that has changed.
    :type paramType: Any
    """
    message = "[param type]: " + str(paramType)
    print("Callback OnActiveParamChanged:\n" + message)

def OnUpdateSequenceChanged(modelRef, sequence):
    """
    Callback function that is triggered when the update sequence changes.
    
    :param modelRef: Reference to the model. If not None, it is expected to have a method `GetDgnModel` 
                     which returns an object with a method `GetModelName`.
    :type modelRef: object or None
    :param sequence: The sequence that has changed. It is expected to be an iterable.
    :type sequence: iterable or None
    
    :returns: None
    :rtype: None
    """
    message = ""
    if modelRef is not None:
        message += "[modelRef]: " + str(modelRef.GetDgnModel().GetModelName())
    else:
        message += "[modelRef]: " + str(modelRef)

    message += "\n"
    if sequence is not None:
        message += "[sequence count]: " + str(len(sequence))
    else:
        message += "[sequence]: " + str(sequence)
    print("Callback OnUpdateSequenceChanged:\n" + message)

def OnDimStyleChange(modelRef, styleIdIn, changeType):
    """
    Callback function that is triggered when a dimension style changes.
    
    :param modelRef: Reference to the model where the dimension style change occurred.
    :type modelRef: object
    :param styleIdIn: Identifier of the dimension style that has changed.
    :type styleIdIn: int
    :param changeType: Type of change that occurred to the dimension style.
    :type changeType: int
    """
    message = ""
    if modelRef is not None:
        message += "[modelRef]: " + str(modelRef.GetDgnModel().GetModelName())
    else:
        message += "[modelRef]: " + str(modelRef)

    message += "\n"
    message += "[style Id]: " + str(styleIdIn)
    message += "\n"
    message += "[change type]: " + str(changeType)
    print("Callback OnDimStyleChange:\n" + message)

def OnTextStyleChange(modelRef, styleId, changeTypeId):
    """
    Callback function that is triggered when a text style change occurs.
    
    :param modelRef: Reference to the model where the text style change occurred. 
                     If `None`, it indicates that the model reference is not available.
    :type modelRef: object or None
    :param styleId: Identifier of the text style that has changed.
    :type styleId: int
    :param changeTypeId: Identifier of the type of change that occurred.
    :type changeTypeId: int
    """
    message = ""
    if modelRef is not None:
        message += "[modelRef]: " + str(modelRef.GetDgnModel().GetModelName())
    else:
        message += "[modelRef]: " + str(modelRef)

    message += "\n"
    message += "[style Id]: " + str(styleId)
    message += "\n"
    message += "[change type]: " + str(changeTypeId)
    print("Callback OnTextStyleChange:\n" + message)

def OnLevelChange(modelRef, levelId, changeTypeId):
    """
    Callback function that is triggered when there is a change in the level.
    
    :param modelRef: Reference to the model. If not None, it provides access to the model's name.
    :type modelRef: object
    :param levelId: Identifier for the level that has changed.
    :type levelId: int
    :param changeTypeId: Identifier for the type of change that occurred.
    :type changeTypeId: int
    """
    message = ""
    if modelRef is not None:
        message += "[modelRef]: " + str(modelRef.GetDgnModel().GetModelName())
    else:
        message += "[modelRef]: " + str(modelRef)

    message += "\n"
    message += "[level Id]: " + str(levelId)
    message += "\n"
    message += "[change type]: " + str(changeTypeId)
    print("Callback OnLevelChange:\n" + message)

def OnLevelPreChange(modelRef, levelIdIn, changeType):
    """
    Callback function that is triggered before a level change occurs.
    
    :param modelRef: Reference to the model. If not None, it provides the model name.
    :type modelRef: object
    :param levelIdIn: Identifier for the level that is changing.
    :type levelIdIn: int
    :param changeType: Type of change that is occurring.
    :type changeType: int
    
    :return: Status of the callback execution.
    :rtype: BentleyStatus
    """
    message = ""
    if modelRef is not None:
        message += "[modelRef]: " + str(modelRef.GetDgnModel().GetModelName())
    else:
        message += "[modelRef]: " + str(modelRef)

    message += "\n"
    message += "[level Id]: " + str(levelIdIn)
    message += "\n"
    message += "[change type]: " + str(changeType)
    print("Callback OnLevelPreChange:\n" + message)
    return BentleyStatus.eSUCCESS

def OnLevelMaskCachePreChange(modelRef, viewNumber):
    """
    Callback function that is triggered before the level mask cache changes.
    
    :param modelRef: Reference to the model. If not None, it provides access to the model's name.
    :type modelRef: object or None
    :param viewNumber: The number of the view that is being affected.
    :type viewNumber: int
    """
    message = ""
    if modelRef is not None:
        message += "[modelRef]: " + str(modelRef.GetDgnModel().GetModelName())
    else:
        message += "[modelRef]: " + str(modelRef)

    message += "\n"
    message += "[viewNumber]: " + str(viewNumber)
    print("Callback OnLevelMaskCachePreChange:\n" + message)

def OnLevelMaskCachePostChange(modelRef, viewNumber):
    """
    Callback function that is triggered after the level mask cache changes.
    
    :param modelRef: Reference to the model. If not None, it provides access to the model's name.
    :type modelRef: object or None
    :param viewNumber: The number of the view that has changed.
    :type viewNumber: int
    """
    message = ""
    if modelRef is not None:
        message += "[modelRef]: " + str(modelRef.GetDgnModel().GetModelName())
    else:
        message += "[modelRef]: " + str(modelRef)

    message += "\n"
    message += "[viewNumber]: " + str(viewNumber)
    print("Callback OnLevelMaskCachePostChange:\n" + message)

def OnFilterChange(filterTableName, filterId, changeTypeId):
    """
    Callback function that is triggered when a filter changes.

    :param filterTableName: The name of the filter table.
    :type filterTableName: str
    :param filterId: The ID of the filter.
    :type filterId: int
    :param changeTypeId: The type of change that occurred.
    :type changeTypeId: int
    """
    message = "[filter table name]: " + str(filterTableName)
    message += "\n"
    message += "[filter Id]: " + str(filterId)
    message += "\n"
    message += "[change type]: " + str(changeTypeId)
    print("Callback OnFilterChange:\n" + message)

def OnMonitorBatchProcessing(state):
    """
    Callback function that handles batch processing monitoring.

    :param state: The current state of the batch processing.
    :type state: Any
    """
    message = "[state]: " + str(state)
    print("Callback OnMonitorBatchProcessing:\n" + message)

def OnWorkspaceChanged():
    """
    Callback function that is triggered when the workspace changes.

    This function is called automatically whenever there is a change in the workspace.
    It prints a message indicating that the workspace has changed.
    """
    print("Callback OnWorkspaceChanged.")

def OnMainToolBoxTaskChanged(previousPath, newPath):
    """
    Callback function that is triggered when the main toolbox task changes.

    :param previousPath: The previous path of the toolbox task.
    :type previousPath: str
    :param newPath: The new path of the toolbox task.
    :type newPath: str
    """
    message = "[previous path]: " + str(previousPath)
    message += "\n"
    message += "[new path]: " + str(newPath)
    print("Callback OnMainToolBoxTaskChanged:\n" + message)

def OnTaskNavigationTaskChanging(cancelTaskChange, currentPath, newPath):
    """
    Callback function that is triggered when a task navigation change is occurring.

    :param cancelTaskChange: A boolean-like object indicating whether the task change should be canceled.
    :type cancelTaskChange: bool
    :param currentPath: The current path of the task.
    :type currentPath: str
    :param newPath: The new path to which the task is navigating.
    :type newPath: str
    """
    message = "[cancel task change]: " + str(cancelTaskChange.value)
    message += "\n"
    message += "[current path]: " + str(currentPath)
    message += "\n"
    message += "[new path]: " + str(newPath)
    print("Callback OnTaskNavigationTaskChanging:\n" + message)

def OnActiveElementTemplateChanged(previousPath, newPath):
    """
    Callback function that is triggered when the active element template changes.

    :param previousPath: The file path of the previous active element template.
    :type previousPath: str
    :param newPath: The file path of the new active element template.
    :type newPath: str
    """
    message = "[previous path]: " + str(previousPath)
    message += "\n"
    message += "[new path]: " + str(newPath)
    print("Callback OnActiveElementTemplateChanged:\n" + message)

def OnClipboardUpdated():
    """
    Callback function that is triggered when the clipboard is updated.

    This function is called automatically whenever there is a change in the clipboard content.
    It prints a message indicating that the clipboard has been updated.
    """
    print("Callback OnClipboardUpdated.")

def OnDgnLibsChanged(selectors):
    """
    Callback function that is triggered when DGN libraries change.

    :param selectors: An integer representing the selectors that have changed.
    :type selectors: int
    """
    message = "[selectors]: " + str(int(selectors))
    print("Callback OnDgnLibsChanged:\n" + message)

def OnRibbonBackstageOpened():
    """
    Callback function that is triggered when the Ribbon Backstage is opened.

    This function is called automatically when the Ribbon Backstage view is opened.
    It prints a message indicating that the callback has been triggered.
    """
    print("Callback OnRibbonBackstageOpened.")


def SetCallbacks():
    """
    Set various system callback functions.

    This function registers multiple callback functions to handle different system events.
    Each callback function is associated with a specific event and is set using the 
    corresponding `SystemCallback` method.

    The following callbacks are set:
    
    - OnNewDesignFile: Triggered when a new design file is created.
    - OnUnloadProgram: Triggered when the program is unloaded.
    - OnFileSaveAs: Triggered when a file is saved as a new file.
    - OnFileSave: Triggered when a file is saved.
    - OnFenceChange: Triggered when the fence changes.
    - OnCompressDgnFile: Triggered when a DGN file is compressed.
    - OnCompressDgnModel: Triggered when a DGN model is compressed.
    - OnDgnFileLoaded: Triggered when a DGN file is loaded.
    - OnDgnFileUnloading: Triggered when a DGN file is unloading.
    - OnQueryHasPending: Triggered when there is a query with pending status.
    - OnDgnCacheUnloading: Triggered when the DGN cache is unloading.
    - OnMasterfileClosed: Triggered when the master file is closed.
    - OnSetModelChangeFunction: Triggered when the model changes.
    - OnModelRefDestroy: Triggered when a model reference is destroyed.
    - OnExitDesignFileState: Triggered when exiting the design file state.
    - OnMessageCenterWrite: Triggered when writing to the message center.
    - OnPromptOutput: Triggered when there is prompt output.
    - OnStatusOutput: Triggered when there is status output.
    - OnApplicationAreaChange: Triggered when the application area changes.
    - OnReferenceBeforeAttach: Triggered before a reference is attached.
    - OnReferenceAttach: Triggered when a reference is attached.
    - OnReferenceAttached: Triggered after a reference is attached.
    - OnReferenceAttachQueue: Triggered when a reference attach queue is processed.
    - OnReferenceDetach: Triggered when a reference is detached.
    - OnReferenceDetached: Triggered after a reference is detached.
    - OnReferenceModified: Triggered when a reference is modified.
    - OnReferenceNesting: Triggered when reference nesting occurs.
    - OnBeforeReferenceWrite: Triggered before a reference is written.
    - OnFileOutdated: Triggered when a file is outdated.
    - OnElmDscrCopy: Triggered when an element description is copied.
    - OnSaveSettings: Triggered when settings are saved.
    - OnAcsOperation: Triggered during ACS operations.
    - OnSelectedViewChanged: Triggered when the selected view changes.
    - OnBeforeViewsOpen: Triggered before views are opened.
    - OnViewGroupCacheChange: Triggered when the view group cache changes.
    - OnMonitorViewCommands: Triggered to monitor view commands.
    - OnLockChanged: Triggered when a lock state changes.
    - OnActiveParamChanged: Triggered when an active parameter changes.
    - OnUpdateSequenceChanged: Triggered when the update sequence changes.
    - OnDimStyleChange: Triggered when the dimension style changes.
    - OnTextStyleChange: Triggered when the text style changes.
    - OnLevelChange: Triggered when a level changes.
    - OnLevelPreChange: Triggered before a level changes.
    - OnLevelMaskCachePreChange: Triggered before the level mask cache changes.
    - OnLevelMaskCachePostChange: Triggered after the level mask cache changes.
    - OnFilterChange: Triggered when a filter changes.
    - OnMonitorBatchProcessing: Triggered to monitor batch processing.
    - OnWorkspaceChanged: Triggered when the workspace changes.
    - OnMainToolBoxTaskChanged: Triggered when the main toolbox task changes.
    - OnTaskNavigationTaskChanging: Triggered when the task navigation task is changing.
    - OnActiveElementTemplateChanged: Triggered when the active element template changes.
    - OnClipboardUpdated: Triggered when the clipboard is updated.
    - OnDgnLibsChanged: Triggered when DGN libraries change.
    - OnRibbonBackstageOpened: Triggered when the ribbon backstage is opened.
    """
    SystemCallback.SetNewDesignFileFunction(OnNewDesignFile, FILE + ".OnNewDesignFile")
    SystemCallback.SetUnloadProgramFunction(OnUnloadProgram, FILE + ".OnUnloadProgram")
    SystemCallback.SetFileSaveAsFunction(OnFileSaveAs, FILE + ".OnFileSaveAs")
    SystemCallback.SetFileSaveFunction(OnFileSave, FILE + ".OnFileSave")
    SystemCallback.SetFenceChangedFunction(OnFenceChange, FILE + ".OnFenceChange")
    SystemCallback.SetCompressDgnFileFunction(OnCompressDgnFile, FILE + ".OnCompressDgnFile")
    SystemCallback.SetCompressDgnModelFunction(OnCompressDgnModel, FILE + ".OnCompressDgnModel")
    SystemCallback.SetDgnFileLoadedFunction(OnDgnFileLoaded, FILE + ".OnDgnFileLoaded")
    SystemCallback.SetDgnFileUnloadingFunction(OnDgnFileUnloading, FILE + ".OnDgnFileUnloading")
    SystemCallback.SetQueryHasPendingFunction(OnQueryHasPending, FILE + ".OnQueryHasPending")
    SystemCallback.SetDgnCacheUnloadingFunction(OnDgnCacheUnloading, FILE + ".OnDgnCacheUnloading")
    SystemCallback.SetMasterfileClosedFunction(OnMasterfileClosed, FILE + ".OnMasterfileClosed")
    SystemCallback.SetModelChangeFunction(OnSetModelChangeFunction, FILE + ".OnSetModelChangeFunction")
    SystemCallback.SetModelRefDestroyFunction(OnModelRefDestroy, FILE + ".OnModelRefDestroy")
    SystemCallback.SetExitDesignFileStateFunction(OnExitDesignFileState, FILE + ".OnExitDesignFileState")
    SystemCallback.SetMessageCenterWriteFunction(OnMessageCenterWrite, FILE + ".OnMessageCenterWrite")
    SystemCallback.SetPromptOutputFunction(OnPromptOutput, FILE + ".OnPromptOutput")
    SystemCallback.SetStatusOutputFunction(OnStatusOutput, FILE + ".OnStatusOutput")
    SystemCallback.SetApplicationAreaChangeFunction(OnApplicationAreaChange, FILE + ".OnApplicationAreaChange")
    SystemCallback.SetReferenceBeforeAttachFunction(OnReferenceBeforeAttach, FILE + ".OnReferenceBeforeAttach")
    SystemCallback.SetReferenceAttachFunction(OnReferenceAttach, FILE + ".OnReferenceAttach")
    SystemCallback.SetReferenceAttachedFunction(OnReferenceAttached, FILE + ".OnReferenceAttached")
    SystemCallback.SetReferenceAttachQueueFunction(OnReferenceAttachQueue, FILE + ".OnReferenceAttachQueue")
    SystemCallback.SetReferenceDetachFunction(OnReferenceDetach, FILE + ".OnReferenceDetach")
    SystemCallback.SetReferenceDetachedFunction(OnReferenceDetached, FILE + ".OnReferenceDetached")
    SystemCallback.SetReferenceModifiedFunction(OnReferenceModified, FILE + ".OnReferenceModified")
    SystemCallback.SetReferenceNestingFunction(OnReferenceNesting, FILE + ".OnReferenceNesting")
    SystemCallback.SetBeforeReferenceWriteFunction(OnBeforeReferenceWrite, FILE + ".OnBeforeReferenceWrite")
    SystemCallback.SetFileOutdatedFunction(OnFileOutdated, FILE + ".OnFileOutdated")
    SystemCallback.SetElmDscrCopyFunction(OnElmDscrCopy, FILE + ".OnElmDscrCopy")
    SystemCallback.SetSaveSettingsFunction(OnSaveSettings, FILE + ".OnSaveSettings")
    SystemCallback.SetAcsOperationFunction(OnAcsOperation, FILE + ".OnAcsOperation")
    SystemCallback.SetSelectedViewChangedFunction(OnSelectedViewChanged, FILE + ".OnSelectedViewChanged")
    SystemCallback.SetBeforeViewsOpenFunction(OnBeforeViewsOpen, FILE + ".OnBeforeViewsOpen")
    SystemCallback.SetViewGroupCacheChangeFunction(OnViewGroupCacheChange, FILE + ".OnViewGroupCacheChange")
    SystemCallback.SetMonitorViewCommandsFunction(OnMonitorViewCommands, FILE + ".OnMonitorViewCommands")
    SystemCallback.SetLockChangedFunction(OnLockChanged, FILE + ".OnLockChanged")
    SystemCallback.SetActiveParamChangedFunction(OnActiveParamChanged, FILE + ".OnActiveParamChanged")
    SystemCallback.SetUpdateSequenceChangedFunction(OnUpdateSequenceChanged, FILE + ".OnUpdateSequenceChanged")
    SystemCallback.SetDimStyleChangeFunction(OnDimStyleChange, FILE + ".OnDimStyleChange")
    SystemCallback.SetTextStyleChangeFunction(OnTextStyleChange, FILE + ".OnTextStyleChange")
    SystemCallback.SetLevelChangeFunction(OnLevelChange, FILE + ".OnLevelChange")
    SystemCallback.SetLevelPreChangeFunction(OnLevelPreChange, FILE + ".OnLevelPreChange")
    SystemCallback.SetLevelMaskCachePreChangeFunction(OnLevelMaskCachePreChange, FILE + ".OnLevelMaskCachePreChange")
    SystemCallback.SetLevelMaskCachePostChangeFunction(OnLevelMaskCachePostChange, FILE + ".OnLevelMaskCachePostChange")
    SystemCallback.SetFilterChangeFunction(OnFilterChange, FILE + ".OnFilterChange")
    SystemCallback.SetMonitorBatchProcessingFunction(OnMonitorBatchProcessing, FILE + ".OnMonitorBatchProcessing")
    SystemCallback.SetWorkspaceChangedFunction(OnWorkspaceChanged, FILE + ".OnWorkspaceChanged")
    SystemCallback.SetMainToolBoxTaskChangedFunction(OnMainToolBoxTaskChanged, FILE + ".OnMainToolBoxTaskChanged")
    SystemCallback.SetTaskNavigationTaskChangingFunction(OnTaskNavigationTaskChanging, FILE + ".OnTaskNavigationTaskChanging")
    SystemCallback.SetActiveElementTemplateChangedFunction(OnActiveElementTemplateChanged, FILE + ".OnActiveElementTemplateChanged")
    SystemCallback.SetClipboardUpdatedFunction(OnClipboardUpdated, FILE + ".OnClipboardUpdated")
    SystemCallback.SetDgnLibsChangedFunction(OnDgnLibsChanged, FILE + ".OnDgnLibsChanged")
    SystemCallback.SetRibbonBackstageOpenedFunction(OnRibbonBackstageOpened, FILE + ".OnRibbonBackstageOpened")

def ClearCallbacks():
    """
    Clears all system callback functions by setting them to None.

    This function resets various system callbacks to their default state by 
    assigning None to each callback function. The callbacks affected include 
    design file functions, program unload functions, file save functions, 
    fence change functions, compression functions, file load/unload functions, 
    model change functions, reference attach/detach functions, view change 
    functions, level change functions, and many more.

    The following callbacks are cleared:
    - New Design File Function
    - Unload Program Function
    - File Save As Function
    - File Save Function
    - Fence Changed Function
    - Compress Dgn File Function
    - Compress Dgn Model Function
    - Dgn File Loaded Function
    - Dgn File Unloading Function
    - Query Has Pending Function
    - Dgn Cache Unloading Function
    - Masterfile Closed Function
    - Model Change Function
    - Model Ref Destroy Function
    - Exit Design File State Function
    - Message Center Write Function
    - Prompt Output Function
    - Status Output Function
    - Application Area Change Function
    - Reference Before Attach Function
    - Reference Attach Function
    - Reference Attached Function
    - Reference Attach Queue Function
    - Reference Detach Function
    - Reference Detached Function
    - Reference Modified Function
    - Reference Nesting Function
    - Before Reference Write Function
    - File Outdated Function
    - Elm Dscr Copy Function
    - Save Settings Function
    - Acs Operation Function
    - Selected View Changed Function
    - Before Views Open Function
    - View Group Cache Change Function
    - Monitor View Commands Function
    - Lock Changed Function
    - Active Param Changed Function
    - Update Sequence Changed Function
    - Dim Style Change Function
    - Text Style Change Function
    - Level Change Function
    - Level Pre Change Function
    - Level Mask Cache Pre Change Function
    - Level Mask Cache Post Change Function
    - Filter Change Function
    - Monitor Batch Processing Function
    - Workspace Changed Function
    - Main Tool Box Task Changed Function
    - Task Navigation Task Changing Function
    - Active Element Template Changed Function
    - Clipboard Updated Function
    - Dgn Libs Changed Function
    - Ribbon Backstage Opened Function
    """
    SystemCallback.SetNewDesignFileFunction(None, "")
    SystemCallback.SetUnloadProgramFunction(None, "")
    SystemCallback.SetFileSaveAsFunction(None, "")
    SystemCallback.SetFileSaveFunction(None, "")
    SystemCallback.SetFenceChangedFunction(None, "")
    SystemCallback.SetCompressDgnFileFunction(None, "")
    SystemCallback.SetCompressDgnModelFunction(None, "")
    SystemCallback.SetDgnFileLoadedFunction(None, "")
    SystemCallback.SetDgnFileUnloadingFunction(None, "")
    SystemCallback.SetQueryHasPendingFunction(None, "")
    SystemCallback.SetDgnCacheUnloadingFunction(None, "")
    SystemCallback.SetMasterfileClosedFunction(None, "")
    SystemCallback.SetModelChangeFunction(None, "")
    SystemCallback.SetModelRefDestroyFunction(None, "")
    SystemCallback.SetExitDesignFileStateFunction(None, "")
    SystemCallback.SetMessageCenterWriteFunction(None, "")
    SystemCallback.SetPromptOutputFunction(None, "")
    SystemCallback.SetStatusOutputFunction(None, "")
    SystemCallback.SetApplicationAreaChangeFunction(None, "")
    SystemCallback.SetReferenceBeforeAttachFunction(None, "")
    SystemCallback.SetReferenceAttachFunction(None, "")
    SystemCallback.SetReferenceAttachedFunction(None, "")
    SystemCallback.SetReferenceAttachQueueFunction(None, "")
    SystemCallback.SetReferenceDetachFunction(None, "")
    SystemCallback.SetReferenceDetachedFunction(None, "")
    SystemCallback.SetReferenceModifiedFunction(None, "")
    SystemCallback.SetReferenceNestingFunction(None, "")
    SystemCallback.SetBeforeReferenceWriteFunction(None, "")
    SystemCallback.SetFileOutdatedFunction(None, "")
    SystemCallback.SetElmDscrCopyFunction(None, "")
    SystemCallback.SetSaveSettingsFunction(None, "")
    SystemCallback.SetAcsOperationFunction(None, "")
    SystemCallback.SetSelectedViewChangedFunction(None, "")
    SystemCallback.SetBeforeViewsOpenFunction(None, "")
    SystemCallback.SetViewGroupCacheChangeFunction(None, "")
    SystemCallback.SetMonitorViewCommandsFunction(None, "")
    SystemCallback.SetLockChangedFunction(None, "")
    SystemCallback.SetActiveParamChangedFunction(None, "")
    SystemCallback.SetUpdateSequenceChangedFunction(None, "")
    SystemCallback.SetDimStyleChangeFunction(None, "")
    SystemCallback.SetTextStyleChangeFunction(None, "")
    SystemCallback.SetLevelChangeFunction(None, "")
    SystemCallback.SetLevelPreChangeFunction(None, "")
    SystemCallback.SetLevelMaskCachePreChangeFunction(None, "")
    SystemCallback.SetLevelMaskCachePostChangeFunction(None, "")
    SystemCallback.SetFilterChangeFunction(None, "")
    SystemCallback.SetMonitorBatchProcessingFunction(None, "")
    SystemCallback.SetWorkspaceChangedFunction(None, "")
    SystemCallback.SetMainToolBoxTaskChangedFunction(None, "")
    SystemCallback.SetTaskNavigationTaskChangingFunction(None, "")
    SystemCallback.SetActiveElementTemplateChangedFunction(None, "")
    SystemCallback.SetClipboardUpdatedFunction(None, "")
    SystemCallback.SetDgnLibsChangedFunction(None, "")
    SystemCallback.SetRibbonBackstageOpenedFunction(None, "")


if __name__ == "__main__":
    SetCallbacks()
    #ClearCallbacks()
