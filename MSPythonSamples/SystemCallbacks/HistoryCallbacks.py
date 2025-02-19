# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''

import os
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

FILE = os.path.abspath(__file__)

'''
set configuration variable MS_DESIGN_HISTORY as below to enable all operations of Design History:
create=1;delete=1;commit=1;browse=1;tag=1;changedesc=1;changeauthor=1;combine=1;retire=1;setrevisionformat=1;setversion=1;autoupgrade=1
'''


# Callback that is called before changes are committed to design history
def OnPreCommit(file, parms):
    if file is not None:
        message = "[file]: " + str(file.GetFileName())
    else:
        message = "[file]: None"
    
    message += "\n"
    if file is not None:
        message += "[parms desc]: " + str(parms.desc)
    else:
        message += "[parms]: None"
    print("Callback OnPreCommit:\n" + message)

# Callback that is called after a set of changes is committed to design history
def OnPostCommit(info, file, infoObject, status):
    if file is not None:
        message = "[info desc]: " + str(info.desc)
    else:
        message = "[info]: None"

    message += "\n"
    if file is not None:
        message += "[file]: " + str(file.GetFileName())
    else:
        message += "[file]: None"

    message += "\n"
    if file is not None:
        message += "[infoObject desc]: " + str(infoObject.GetDescription())
    else:
        message += "[infoObject]: None"

    message += "\n"
    message += "status: " + str(status)
    print("Callback OnPostCommit:\n" + message)

# Callback that is called before design history is initialized in file
def OnPreCreate(file):
    if file is not None:
        message = "[file]: " + str(file.GetFileName())
    else:
        message = "[file]: None"
    print("Callback OnPreCreate:\n" + message)
    return BentleyStatus.eSUCCESS

# Callback that is called after design history is initialized in a file
def OnPostCreate(file):
    if file is not None:
        message = "[file]: " + str(file.GetFileName())
    else:
        message = "[file]: None"
    print("Callback OnPostCreate:\n" + message)

# Callback that is called before design history is deleted from a file
def OnPreDelete(file):
    if file is not None:
        message = "[file]: " + str(file.GetFileName())
    else:
        message = "[file]: None"
    print("Callback OnPreDelete:\n" + message)
    return BentleyStatus.eSUCCESS

# Callback that is called after design history is deleted from a file
def OnPostDelete(file, status):
    if file is not None:
        message = "[file]: " + str(file.GetFileName())
    else:
        message = "[file]: None"

    message += "\n"
    message += "status: " + str(status)
    print("Callback OnPostDelete:\n" + message)

# Callback that is called before revisions in history are netted out and combined
def OnPreCombine(file, start, end):
    if file is not None:
        message = "[file]: " + str(file.GetFileName())
    else:
        message = "[file]: None"

    message += "\n"
    message += "start: " + str(start)

    message += "\n"
    message += "end: " + str(end)

    print("Callback OnPreCombine:\n" + message)
    return BentleyStatus.eSUCCESS

# Callback that is called after revisions in history are netted out and combined, or after the attempt to combine fails
def OnPostCombine(file, start, end, status):
    if file is not None:
        message = "[file]: " + str(file.GetFileName())
    else:
        message = "[file]: None"

    message += "\n"
    message += "start: " + str(start)

    message += "\n"
    message += "end: " + str(end)

    message += "\n"
    message += "status: " + str(status)
    print("Callback OnPostCombine:\n" + message)

# Callback that is called before revisions in history are removed
def OnPreDeleteEarlyRevisions(file, tooOld):
    if file is not None:
        message = "[file]: " + str(file.GetFileName())
    else:
        message = "[file]: None"

    message += "\n"
    message += "tooOld: " + str(tooOld)
    print("Callback OnPreDeleteEarlyRevisions:\n" + message)
    return BentleyStatus.eSUCCESS

# Callback that is called after revisions in history are removed, or if the attempt to delete revisions failed
def OnPostDeleteEarlyRevisions(file, tooOld, status):
    if file is not None:
        message = "[file]: " + str(file.GetFileName())
    else:
        message = "[file]: None"

    message += "\n"
    message += "tooOld: " + str(tooOld)

    message += "\n"
    message += "status: " + str(status)
    print("Callback OnPostDeleteEarlyRevisions:\n" + message)

# Callback that is called before the description and/or user name of the specified revision are modified
def OnPreUpdateRevisionUserDesc(file, rev, user, desc):
    if file is not None:
        message = "[file]: " + str(file.GetFileName())
    else:
        message = "[file]: None"

    message += "\n"
    message += "rev: " + str(rev)

    message += "\n"
    message += "user: " + str(user)

    message += "\n"
    message += "desc: " + str(desc)

    print("Callback OnPreUpdateRevisionUserDesc:\n" + message)
    return BentleyStatus.eSUCCESS

# Callback that is called after the description and/or user name, or if the attempt to change the data failed
def OnPostUpdateRevisionUserDesc(file, rev, user, desc, status):
    if file is not None:
        message = "[file]: " + str(file.GetFileName())
    else:
        message = "[file]: None"

    message += "\n"
    message += "rev: " + str(rev)

    message += "\n"
    message += "user: " + str(user)

    message += "\n"
    message += "desc: " + str(desc)

    message += "\n"
    message += "status: " + str(status)
    print("Callback OnPostUpdateRevisionUserDesc:\n" + message)

# Callback that is called to format history revision number
def OnFormatRevisionNumber(buf, num, maxbuf, file):
    if (maxbuf > 13 + len(num)):
        buf.AssignA("9999")
        buf.AppendA(num)

    message = "num: " + num
    message += "\n"
    message += "maxbuf: " + str(maxbuf)

    message += "\n"
    if file is not None:
        message += "[file]: " + str(file.GetFileName())
    else:
        message += "[file]: None"

    print("Callback OnFormatRevisionNumber:\n" + message)
    return BentleyStatus.eSUCCESS

# Callback that is called when design history needs to allow the user to interactively compare revisions of an element
def OnCompareElements(affinity, file, model, preChange, postChange, title, preChangeDescription, postChangeDescription):
    if affinity is not None:
        affinity.value = 100
        return BentleyStatus.eSUCCESS

    if file is not None:
        message = "[file]: " + str(file.GetFileName())
    else:
        message = "[file]: None"

    message += "\n"
    message += "model Id: " + str(model)

    message += "\n"
    message += "preChange: " + str(preChange)

    message += "\n"
    message += "postChange: " + str(postChange)

    message += "\n"
    message += "title: " + str(title)

    message += "\n"
    message += "preChangeDescription: " + str(preChangeDescription)

    message += "\n"
    message += "postChangeDescription: " + str(postChangeDescription)

    print("Callback OnCompareElements:\n" + message)
    return BentleyStatus.eSUCCESS

# Callback that is called when design history needs to interactively display the properties of an element to the user
def OnDisplayElement(affinity, file, model, element, descriptionString, changeTypeString):
    if affinity is not None:
        affinity.value = 100
        return BentleyStatus.eSUCCESS

    if file is not None:
        message = "[file]: " + str(file.GetFileName())
    else:
        message = "[file]: None"

    message += "\n"
    message += "model Id: " + str(model)

    message += "\n"
    message += "element: " + str(element)

    message += "\n"
    message += "description: " + str(descriptionString)

    message += "\n"
    message += "change type: " + str(changeTypeString)

    print("Callback OnDisplayElement:\n" + message)
    return BentleyStatus.eSUCCESS

# Callback that is called when design history needs to show the user a description of an element
def OnDescribeElement(affinity, type, name, file, model, element, maxtype, maxname):
    if affinity is not None:
        affinity.value = 1
        return BentleyStatus.eSUCCESS

    if file is not None:
        message = "[file]: " + str(file.GetFileName())
    else:
        message = "[file]: None"

    message += "\n"
    message += "type: " + str(type)

    message += "\n"
    message += "name: " + str(name)

    message += "\n"
    message += "model Id: " + str(model)

    message += "\n"
    message += "element: " + str(element)

    message += "\n"
    message += "max type: " + str(maxtype)

    message += "\n"
    message += "max name: " + str(maxname)

    if (maxtype > 0):
        type.AssignA("My " + type.GetWCharCP())
    if (maxname > 0):
        name.AssignA("My Name 001")

    print("Callback OnDescribeElement:\n" + message)
    return BentleyStatus.eSUCCESS

# Callback that is called before changes are restored from design history
def OnPreRestore(file, targetRev):
    if file is not None:
        message = "[file]: " + str(file.GetFileName())
    else:
        message = "[file]: None"

    message += "\n"
    message += "target revison: " + str(targetRev)

    print("Callback OnPreRestore:\n" + message)
    return BentleyStatus.eSUCCESS

# Callback that is called after changes are restored from design history
def OnPostRestore(file, targetRev):
    if file is not None:
        message = "[file]: " + str(file.GetFileName())
    else:
        message = "[file]: None"

    message += "\n"
    message += "target revison: " + str(targetRev)
    print("Callback OnPostRestore:\n" + message)

# Set history callbacks
def AddCallbacks():
    HistoryCallback.AddCommitPreFunction(OnPreCommit, FILE + ".OnPreCommit") # Add callback which is called before changes are committed to design history
    HistoryCallback.AddCommitPostFunction(OnPostCommit, FILE + ".OnPostCommit") # Add callback which is called after a set of changes is committed to design history
    HistoryCallback.AddCreatePreFunction(OnPreCreate, FILE + ".OnPreCreate") # Add callback which is called before design history is initialized in file
    HistoryCallback.AddCreatePostFunction(OnPostCreate, FILE + ".OnPostCreate") # Add callback which is called after design history is initialized in a file
    HistoryCallback.AddDeletePreFunction(OnPreDelete, FILE + ".OnPreDelete") # Add callback which is called before design history is deleted from a file
    HistoryCallback.AddDeletePostFunction(OnPostDelete, FILE + ".OnPostDelete") # Add callback which is called after design history is deleted from a file
    HistoryCallback.AddCombinePreFunction(OnPreCombine, FILE + ".OnPreCombine") # Add callback which is called before revisions in history are netted out and combined
    HistoryCallback.AddCombinePostFunction(OnPostCombine, FILE + ".OnPostCombine") # Add callback which is called after revisions in history are netted out and combined, or after the attempt to combine fails
    HistoryCallback.AddDeleteEarlyRevisionsPreFunction(OnPreDeleteEarlyRevisions, FILE + ".OnPreDeleteEarlyRevisions") # Add callback which is called before revisions in history are removed
    HistoryCallback.AddDeleteEarlyRevisionsPostFunction(OnPostDeleteEarlyRevisions, FILE + ".OnPostDeleteEarlyRevisions") # Add callback which is called after revisions in history are removed, or if the attempt to delete revisions failed
    HistoryCallback.AddUpdateRevisionUserDescPreFunction(OnPreUpdateRevisionUserDesc, FILE + ".OnPreUpdateRevisionUserDesc") # Add callback which is called before the description and/or user name of the specified revision are modified
    HistoryCallback.AddUpdateRevisionUserDescPostFunction(OnPostUpdateRevisionUserDesc, FILE + ".OnPostUpdateRevisionUserDesc") # Add callback which is called after the description and/or user name, or if the attempt to change the data failed
    HistoryCallback.AddFmtRevisionNumberFunction(OnFormatRevisionNumber, FILE + ".OnFormatRevisionNumber") # Add callback which is called to format history revision number
    HistoryCallback.AddCompareElementsFunction(OnCompareElements, FILE + ".OnCompareElements") # Add callback which is called when design history needs to allow the user to interactively compare revisions of an element
    HistoryCallback.AddDisplayElementFunction(OnDisplayElement, FILE + ".OnDisplayElement") # Add callback which is called when design history needs to interactively display the properties of an element to the user
    HistoryCallback.AddDescribeElementFunction(OnDescribeElement, FILE + ".OnDescribeElement") # Add callback which is called when design history needs to show the user a description of an element
    HistoryCallback.AddRestorePreFunction(OnPreRestore, FILE + ".OnPreRestore") # Add callback which is called before changes are restored from design history
    HistoryCallback.AddRestorePostFunction(OnPostRestore, FILE + ".OnPostRestore") # Add callback which is called after changes are restored from design history

# Remove history callbacks
def RemoveCallbacks():
    HistoryCallback.RemoveCommitPreFunction(OnPreCommit, FILE + ".OnPreCommit") # Remove callback which is called before changes are committed to design history
    HistoryCallback.RemoveCommitPostFunction(OnPostCommit, FILE + ".OnPostCommit") # Remove callback which is called after a set of changes is committed to design history
    HistoryCallback.RemoveCreatePreFunction(OnPreCreate, FILE + ".OnPreCreate") # Remove callback which is called before design history is initialized in file
    HistoryCallback.RemoveCreatePostFunction(OnPostCreate, FILE + ".OnPostCreate") # Remove callback which is called after design history is initialized in a file
    HistoryCallback.RemoveDeletePreFunction(OnPreDelete, FILE + ".OnPreDelete") # Remove callback which is called before design history is deleted from a file
    HistoryCallback.RemoveDeletePostFunction(OnPostDelete, FILE + ".OnPostDelete") # Remove callback which is called after design history is deleted from a file
    HistoryCallback.RemoveCombinePreFunction(OnPreCombine, FILE + ".OnPreCombine") # Remove callback which is called before revisions in history are netted out and combined
    HistoryCallback.RemoveCombinePostFunction(OnPostCombine, FILE + ".OnPostCombine") # Remove callback which is called after revisions in history are netted out and combined, or after the attempt to combine fails
    HistoryCallback.RemoveDeleteEarlyRevisionsPreFunction(OnPreDeleteEarlyRevisions, FILE + ".OnPreDeleteEarlyRevisions") # Remove callback which is called before revisions in history are removed
    HistoryCallback.RemoveDeleteEarlyRevisionsPostFunction(OnPostDeleteEarlyRevisions, FILE + ".OnPostDeleteEarlyRevisions") # Remove callback which is called after revisions in history are removed, or if the attempt to delete revisions failed
    HistoryCallback.RemoveUpdateRevisionUserDescPreFunction(OnPreUpdateRevisionUserDesc, FILE + ".OnPreUpdateRevisionUserDesc") # Remove callback which is called before the description and/or user name of the specified revision are modified
    HistoryCallback.RemoveUpdateRevisionUserDescPostFunction(OnPostUpdateRevisionUserDesc, FILE + ".OnPostUpdateRevisionUserDesc") # Remove callback which is called after the description and/or user name, or if the attempt to change the data failed
    HistoryCallback.RemoveFmtRevisionNumberFunction(OnFormatRevisionNumber, FILE + ".OnFormatRevisionNumber") # Remove callback which is called to format history revision number
    HistoryCallback.RemoveCompareElementsFunction(OnCompareElements, FILE + ".OnCompareElements") # Remove callback which is called when design history needs to allow the user to interactively compare revisions of an element
    HistoryCallback.RemoveDisplayElementFunction(OnDisplayElement, FILE + ".OnDisplayElement") # Remove callback which is called when design history needs to interactively display the properties of an element to the user
    HistoryCallback.RemoveDescribeElementFunction(OnDescribeElement, FILE + ".OnDescribeElement") # Remove callback which is called when design history needs to show the user a description of an element
    HistoryCallback.RemoveRestorePreFunction(OnPreRestore, FILE + ".OnPreRestore") # Remove callback which is called before changes are restored from design history
    HistoryCallback.RemoveRestorePostFunction(OnPostRestore, FILE + ".OnPostRestore") # Remove callback which is called after changes are restored from design history


if __name__ == "__main__":
    AddCallbacks()
    RemoveCallbacks()
    