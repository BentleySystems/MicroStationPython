# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''

import os
from tkinter import messagebox
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *

FILE = os.path.abspath(__file__)

# Close dgn file to call this callback
def OnNewDesignFile(file, reason):
    if reason == NewDesignFileReason.eSYSTEM_NEWFILE_CLOSE:
        message = "[file]: " + str(file)
        message += "\n"
        message += "[reason]: " + str(reason)
        print("Callback OnNewDesignFile:\n" + message)

# Use keyin "python unload DgnFileCallbacks.py" to call this callback
def OnUnloadProgram(reason):
    message = "[reason]: " + str(reason)
    print("Callback OnUnloadProgram:\n" + message)

# Use Save As command or Export command to call this callback
def OnFileSaveAs(postSave, destinationFileName):
    message = "[post save]: " + str(postSave)
    message += "\n"
    message += "[destination file name]: " + str(destinationFileName)
    print("Callback OnFileSaveAs:\n" + message)

# Use Save command to call this callback
def OnFileSave(when, changesFlag, reason, timestamp, file):
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

# Use create fence command to call this callback
def OnFenceChange(changeType):
    if FenceChangedType.eSYSTEM_FENCE_CREATED == changeType:
        message = "[change type]: " + str(changeType)
        print("Callback OnFenceChange, Fence created:\n" + message)
    elif FenceChangedType.eSYSTEM_FENCE_CLEARED == changeType:
        message = "[change type]: " + str(changeType)
        print("Callback OnFenceChange, Fence cleared:\n" + message)

# Use Compress File command to call this callback
def OnCompressDgnFile(errorMessage, type):
    if CompressType.ePRE_COMPRESS_DGNFILE == type:
        errorMessage.AssignA("Compress error test!")
        message = "[type]: " + str(type)
        print("Callback OnCompressDgnFile:\n" + message)
        return BentleyStatus.eERROR

# Use Compress File command to call this callback
def OnCompressDgnModel(dgnModel, type):
    message = "[dgnModel]: " + str(dgnModel.GetModelName())
    message += "\n"
    message += "[type]: " + str(type)
    print("Callback OnCompressDgnModel:\n" + message)

# Open a file to call this callback
def OnDgnFileLoaded(dgnFile):
    message = "[dgnFile]: " + str(dgnFile.GetFileName ())
    print("Callback OnDgnFileLoaded:\n" + message)

# This doesn't seem to be called?
def OnDgnFileUnloading(dgnFile):
    message = "[dgnFile]: " + str(dgnFile.GetFileName ())
    print("Callback OnDgnFileUnloading:\n" + message)

# Save a file to call this callback
def OnQueryHasPending(dgnFile):
    message = "[dgnFile]: " + str(dgnFile.GetFileName ())
    print("Callback OnQueryHasPending:\n" + message)
    return True

# Open another dgn file to call this callback
def OnDgnCacheUnloading(dgnModel): 
    message = ""
    if dgnModel is not None and dgnModel.GetModelId() >= 0:
        message += "[dgnModel]: " + str(dgnModel.GetModelName())
    else:
        message += "[dgnModel Id]: " + str(dgnModel.GetModelId())
    print("Callback OnDgnCacheUnloading:\n" + message)

# Use Close File command to call this callback
def OnMasterfileClosed(): 
    print("Callback OnMasterfileClosed.")

# Create/delete/active... model to call this callback
def OnSetModelChangeFunction(modelRef, changeTypeId): 
    if modelRef is not None:
        message = "[modelRef]: " + str(modelRef.GetDgnModel().GetModelName())
    else:
        message = "[modelRef]: " + str(modelRef)
    message += "\n"
    message += "[change type Id]: " + str(changeTypeId)
    print("Callback OnSetModelChangeFunction:\n" + message)

# Use Close File command to call this callback
def OnModelRefDestroy(modelRef): 
    if modelRef is not None:
        message = "[modelRef]: " + str(modelRef.GetDgnModel().GetModelName())
    else:
        message = "[modelRef]: " + str(modelRef)
    print("Callback OnModelRefDestroy:\n" + message)

# Use Close File command to call this callback
def OnExitDesignFileState(): 
    print("Callback OnExitDesignFileState.")

# This callback will be called when a message is written to the Message Center
def OnMessageCenterWrite(messageType, messageInput, detail, detailMessageAttributes):
    message = "[message type]: " + str(messageType)
    message += "\n"
    message += "[message]: " + str(messageInput)
    message += "\n"
    message += "[detail]: " + str(detail)
    message += "\n"
    message += "[detail message attributes]: " + str(detailMessageAttributes)
    print("Callback OnMessageCenterWrite:\n" + message)

# This callback will be called when a prompt is written to the status bar
def OnPromptOutput(text, combinedText, fieldNumber):
    message = "[text]: " + str(text)
    message += "\n"
    message += "[combined text]: " + str(combinedText)
    message += "\n"
    message += "[field number]: " + str(fieldNumber)
    print("Callback OnPromptOutput:\n" + message)

# This callback will be called when a status message is written to the status bar
def OnStatusOutput(text, fieldNumber):
    message = "[text]: " + str(text)
    message += "\n"
    message += "[field number]: " + str(fieldNumber)
    print("Callback OnStatusOutput:\n" + message)

# This callback will be called when the Application Area is changed
# Open a dgn file can call into this callback
def OnApplicationAreaChange(): 
    print("Callback OnApplicationAreaChange.")

# Use Attach Reference command to call this callback
def OnReferenceBeforeAttach(fileName, parentModelRef):
    message = "[file name]: " + str(fileName)
    message += "\n"
    if parentModelRef is not None:
        message += "[parent modelRef]: " + str(parentModelRef.GetDgnModel().GetModelName())
    else:
        message += "[parent modelRef]: " + str(parentModelRef)
    print("Callback OnReferenceBeforeAttach:\n" + message)
    return BentleyStatus.eSUCCESS

# Use Attach Reference command to call this callback
def OnReferenceAttach(fileName, fullSavedPath, parentModelRef, providerId, attachmentId):
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

# Use Attach Reference command to call this callback
def OnReferenceAttached(modelRef,  cause):
    message = ""
    if modelRef is not None:
        message += "[modelRef]: " + str(modelRef.GetDgnModel().GetModelName())
    else:
        message += "[modelRef]: " + str(modelRef)
    message += "\n"
    message += "[cause]: " + str(cause)
    print("Callback OnReferenceAttached:\n" + message)

# Use Attach Reference command to call this callback
def OnReferenceAttachQueue(state):
    message = "[state]: " + str(state)
    print("Callback OnReferenceAttachQueue:\n" + message)

# Use Detach Reference command to call this callback
def OnReferenceDetach(modelRef):
    message = ""
    if modelRef is not None:
        message += "[modelRef]: " + str(modelRef.GetDgnModel().GetModelName())
    else:
        message += "[modelRef]: " + str(modelRef)
    print("Callback OnReferenceDetach:\n" + message)
    return BentleyStatus.eSUCCESS

# Use Detach Reference command to call this callback
def OnReferenceDetached(modelRef, fileName, cause):
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

# Use Move Reference to call this callback
def OnReferenceModified(oldRef, newRef, modelRef, changesWritten, isUndo):
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

# Use Attach Reference command to call this callback
def OnReferenceNesting(refModelRef, nestFlag, nestDepth, previousNestFlag, previousNestDepth, changeExisting):
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

# Use Attach Reference command to call this callback
def OnBeforeReferenceWrite(modelRef, newAttachment):
    message = ""
    if modelRef is not None:
        message += "[modelRef]: " + str(modelRef.GetDgnModel().GetModelName())
    else:
        message += "[modelRef]: " + str(modelRef)
    message += "\n"
    message += "[new attachment]: " + str(newAttachment)
    print("Callback OnBeforeReferenceWrite:\n" + message)

# Use Reload Reference command to call this callback
def OnFileOutdated(dgnFile, modelRef, reason):
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

# Use Copy command to call this callback
def OnElmDscrCopy(eeh, sourceModelRef, destModelRef, preCopy):
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

# Use Save Settings command to call this callback
def OnSaveSettings():
    print("Callback OnSaveSettings.")

# This callback will be called when an ACS is created, deleted, or modified
# You can operate in ACS Manager to call this callback
def OnAcsOperation(name, description, acsType, changeTypeId, acs, eventType):
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

# This callback will be called when selected view changed
# Use Ribbon command View->View Groups->Prev/Next to call this callback
def OnSelectedViewChanged(oldViewIndex, newViewIndex, isFromButtonEvent):
    message = "[old view index]: " + str(oldViewIndex)
    message += "\n"
    message += "[new view index]: " + str(newViewIndex)
    message += "\n"
    message += "[is from button event]: " + str(isFromButtonEvent)
    print("Callback OnSelectedViewChanged:\n" + message)

# This callback will be called just before the views open
# Use Ribbon command View->View Groups->Prev/Next to call this callback
def OnBeforeViewsOpen():
    print("Callback OnBeforeViewsOpen.")

# This callback will be called when ViewGroup cache changes
def OnViewGroupCacheChange(name, description, changeTypeId):
    message = "[name]: " + str(name)
    message += "\n"
    message += "[description]: " + str(description)
    message += "\n"
    message += "[change type Id]: " + str(changeTypeId)
    print("Callback OnViewGroupCacheChange:\n" + message)

# This callback will be called when MicroStation starts or exits from a viewing command.
# You can use Fit View command to call this callback
def OnMonitorViewCommands(starting):
    message = "[starting]: " + str(starting)
    print("Callback OnMonitorViewCommands:\n" + message)

# This callback will be called after one of the MicroStation "locks" has been changed
# You can change the Snap Mode to call this callback
def OnLockChanged(eventType):
    message = "[eventType]: " + str(eventType)
    print("Callback OnLockChanged:\n" + message)

# This callback will be called after one of the MicroStation "active parameters" has been changed
# You can change the Active Cell when using Place Active Cell command to call this callback
def OnActiveParamChanged(paramType):
    message = "[param type]: " + str(paramType)
    print("Callback OnActiveParamChanged:\n" + message)

# This callback will be called when the model update sequence is defined or modified
# You can add a reference to call this callback
def OnUpdateSequenceChanged(modelRef, sequence):
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

# This callback will be called each time a dimension style is added, deleted, or updated in a file
# You can make a demension active in Dimension Style dialog to call this callback
def OnDimStyleChange(modelRef, styleIdIn, changeType):
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

# This callback will be called each time a text style is added, deleted, or updated in a file
def OnTextStyleChange(modelRef, styleId, changeTypeId):
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

# This callback will be called when a level is changed
# You can create a level to call this callback
def OnLevelChange(modelRef, levelId, changeTypeId):
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

# This callback will be called before a level is changed
# You can delete a level to call this callback
def OnLevelPreChange(modelRef, levelIdIn, changeType):
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

# This callback will be called before the level mask cached is changed
# You can turn on/off a level display in Level Display dialog to call this callback
def OnLevelMaskCachePreChange(modelRef, viewNumber):
    message = ""
    if modelRef is not None:
        message += "[modelRef]: " + str(modelRef.GetDgnModel().GetModelName())
    else:
        message += "[modelRef]: " + str(modelRef)

    message += "\n"
    message += "[viewNumber]: " + str(viewNumber)
    print("Callback OnLevelMaskCachePreChange:\n" + message)

# This callback will be called before the level mask cached is changed
# You can turn on/off a level display in Level Display dialog to call this callback
def OnLevelMaskCachePostChange(modelRef, viewNumber):
    message = ""
    if modelRef is not None:
        message += "[modelRef]: " + str(modelRef.GetDgnModel().GetModelName())
    else:
        message += "[modelRef]: " + str(modelRef)

    message += "\n"
    message += "[viewNumber]: " + str(viewNumber)
    print("Callback OnLevelMaskCachePostChange:\n" + message)

# This callback will be called when the level filter is changed
# You can change the filter in Level Display dialog to call this callback
def OnFilterChange(filterTableName, filterId, changeTypeId):
    message = "[filter table name]: " + str(filterTableName)
    message += "\n"
    message += "[filter Id]: " + str(filterId)
    message += "\n"
    message += "[change type]: " + str(changeTypeId)
    print("Callback OnFilterChange:\n" + message)

# This callback will be called when Batch Processing start, pauses, resumes, and stops
# Operate in Batch Process dialog to call this callback
def OnMonitorBatchProcessing(state):
    message = "[state]: " + str(state)
    print("Callback OnMonitorBatchProcessing:\n" + message)

# This callback will be called when the workspace, project, or interface changes
# You can switch workset to call this callback
def OnWorkspaceChanged():
    print("Callback OnWorkspaceChanged.")

# This callback will be called after the current UI "main" task (e.g. via task navigation) has changed
# Switch between Dialog/ToolBox/ComboBox in "Select V8i mode" pulldown which is beside workflow pulldown to call this callback
def OnMainToolBoxTaskChanged(previousPath, newPath):
    message = "[previous path]: " + str(previousPath)
    message += "\n"
    message += "[new path]: " + str(newPath)
    print("Callback OnMainToolBoxTaskChanged:\n" + message)

# This callback will be called before the active task is changed
# Switch between Dialog/ToolBox/ComboBox in "Select V8i mode" pulldown which is beside workflow pulldown to call this callback
def OnTaskNavigationTaskChanging(cancelTaskChange, currentPath, newPath):
    message = "[cancel task change]: " + str(cancelTaskChange.value)
    message += "\n"
    message += "[current path]: " + str(currentPath)
    message += "\n"
    message += "[new path]: " + str(newPath)
    print("Callback OnTaskNavigationTaskChanging:\n" + message)

# This callback will be called after the active Element Template is changed
# You can set a template active in Element Template dialog to call this callback
def OnActiveElementTemplateChanged(previousPath, newPath):
    message = "[previous path]: " + str(previousPath)
    message += "\n"
    message += "[new path]: " + str(newPath)
    print("Callback OnActiveElementTemplateChanged:\n" + message)

# This callback will be called when the Clipboard has been updated
# You can use Copy command to call this callback
def OnClipboardUpdated():
    print("Callback OnClipboardUpdated.")

# This callback will be called when the set of DgnLibs has been changed
def OnDgnLibsChanged(selectors):
    message = "[selectors]: " + str(int(selectors))
    print("Callback OnDgnLibsChanged:\n" + message)

# This callback will be called when the Ribbon's Backstage is opened
def OnRibbonBackstageOpened():
    print("Callback OnRibbonBackstageOpened.")


def SetCallbacks():
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
