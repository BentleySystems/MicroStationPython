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


'''
Sample demonstrating how to use the HistoryCallback  API
'''

FILE = os.path.abspath(__file__)

'''
set configuration variable MS_DESIGN_HISTORY as below to enable all operations of Design History:
create=1;delete=1;commit=1;browse=1;tag=1;changedesc=1;changeauthor=1;combine=1;retire=1;setrevisionformat=1;setversion=1;autoupgrade=1
'''


# Callback that is called before changes are committed to design history
def OnPreCommit(file, parms):
    """
    Callback function that is triggered before a commit operation.
    
    :param file: The file object involved in the commit operation. Can be None.
    :type file: File or None
    :param parms: Parameters associated with the commit operation.
    :type parms: Parameters
    """
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
    """
    Callback function that is triggered after a commit operation.
    
    :param info: An object containing information about the commit.
    :type info: object
    :param file: The file object associated with the commit.
    :type file: object or None
    :param infoObject: An object containing additional information about the commit.
    :type infoObject: object
    :param status: The status of the commit operation.
    :type status: object
    """
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
    """
    Callback function that is triggered before a file is created.

    :param file: The file object that is about to be created. It can be None.
    :type file: File or None
    
    :return: Status indicating the success of the operation.
    :rtype: BentleyStatus
    """
    if file is not None:
        message = "[file]: " + str(file.GetFileName())
    else:
        message = "[file]: None"
    print("Callback OnPreCreate:\n" + message)
    return BentleyStatus.eSUCCESS

# Callback that is called after design history is initialized in a file
def OnPostCreate(file):
    """
    Callback function that is triggered after a file is created.

    :param file: The file object that was created. If the file is None, it indicates that no file was created.
    :type file: File or None
    """
    if file is not None:
        message = "[file]: " + str(file.GetFileName())
    else:
        message = "[file]: None"
    print("Callback OnPostCreate:\n" + message)

# Callback that is called before design history is deleted from a file
def OnPreDelete(file):
    """
    Callback function that is triggered before a file is deleted.

    :param file: The file object that is about to be deleted. Can be None.
    :type file: File or None
    
    :return: Status of the callback execution.
    :rtype: BentleyStatus
    """
    if file is not None:
        message = "[file]: " + str(file.GetFileName())
    else:
        message = "[file]: None"
    print("Callback OnPreDelete:\n" + message)
    return BentleyStatus.eSUCCESS

# Callback that is called after design history is deleted from a file
def OnPostDelete(file, status):
    """
    Callback function that is triggered after a file is deleted.
    
    :param file: The file object that was deleted. Can be None.
    :type file: File or None
    :param status: The status of the delete operation.
    :type status: int
    """
    if file is not None:
        message = "[file]: " + str(file.GetFileName())
    else:
        message = "[file]: None"

    message += "\n"
    message += "status: " + str(status)
    print("Callback OnPostDelete:\n" + message)

# Callback that is called before revisions in history are netted out and combined
def OnPreCombine(file, start, end):
    """
    Callback function that is called before combining files.
    
    :param file: The file object to be combined. Can be None.
    :type file: File or None
    :param start: The start position for combining.
    :type start: int
    :param end: The end position for combining.
    :type end: int
    
    :return: Status of the operation.
    :rtype: BentleyStatus
    """
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
    """
    Callback function that is triggered after a combine operation.
    
    :param file: The file object involved in the combine operation. Can be None.
    :type file: File or None
    :param start: The start time of the combine operation.
    :type start: int
    :param end: The end time of the combine operation.
    :type end: int
    :param status: The status of the combine operation.
    :type status: str
    """
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
    """
    Callback function that is triggered before early revisions of a file are deleted.
    :param file: The file object that is being processed. Can be None.
    :type file: File or None
    :param tooOld: A flag indicating whether the file is considered too old.
    :type tooOld: bool
    
    :return: Status of the callback execution.
    :rtype: BentleyStatus
    """
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
    """
    Callback function that is triggered after early revisions of a file are deleted.
    
    :param file: The file object that had its early revisions deleted. Can be None.
    :type file: File or None
    :param tooOld: A flag indicating whether the file was too old.
    :type tooOld: bool
    :param status: The status of the deletion process.
    :type status: str
    
    :return: None
    :rtype: None
    """
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
    """
    Callback function that is triggered before updating the revision user description.
    
    :param file: The file object associated with the revision. Can be None.
    :type file: File or None
    :param rev: The revision number.
    :type rev: int
    :param user: The user who made the revision.
    :type user: str
    :param desc: The description of the revision.
    :type desc: str
    
    :return: Status of the operation.
    :rtype: BentleyStatus
    """
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
    """
    Callback function that is triggered after a revision user description is updated.
    
    :param file: The file object associated with the revision. Can be None.
    :type file: File or None
    :param rev: The revision number.
    :type rev: int
    :param user: The user who made the update.
    :type user: str
    :param desc: The description provided by the user.
    :type desc: str
    :param status: The status of the update.
    :type status: str
    """
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
    """
    Callback function to format the revision number.
    This function assigns and appends a formatted revision number to the buffer
    and prints a message containing the revision number, maximum buffer size, 
    and file information.
    
    :param buf: The buffer to which the formatted revision number is assigned and appended.
    :type buf: Buffer
    :param num: The revision number to be formatted.
    :type num: str
    :param maxbuf: The maximum size of the buffer.
    :type maxbuf: int
    :param file: The file object containing the file name.
    :type file: File or None
    
    :return: Status of the operation.
    :rtype: BentleyStatus
    """
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
    """
    Callback function that compares elements and logs the changes.
    
    :param affinity: An object that may have its value set to 100 if not None.
    :type affinity: object or None
    :param file: The file object being compared.
    :type file: object or None
    :param model: The model ID being compared.
    :type model: int
    :param preChange: The state of the element before the change.
    :type preChange: object
    :param postChange: The state of the element after the change.
    :type postChange: object
    :param title: The title of the comparison.
    :type title: str
    :param preChangeDescription: Description of the element before the change.
    :type preChangeDescription: str
    :param postChangeDescription: Description of the element after the change.
    :type postChangeDescription: str
    
    :return: Status of the comparison.
    :rtype: BentleyStatus
    """
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
    """
    Callback function that handles the display of an element.
    
    :param affinity: An object that may have its value set to 100 if not None.
    :type affinity: object or None
    :param file: The file object containing the element, or None.
    :type file: object or None
    :param model: The model ID associated with the element.
    :type model: int
    :param element: The element to be displayed.
    :type element: object
    :param descriptionString: A string describing the element.
    :type descriptionString: str
    :param changeTypeString: A string describing the type of change.
    :type changeTypeString: str
    
    :return: A status code indicating success.
    :rtype: BentleyStatus
    """
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
    """
    Callback function to describe an element.
    
    :param affinity: Affinity object, if not None, its value is set to 1.
    :type affinity: Affinity
    :param type: Type of the element.
    :type type: ElementType
    :param name: Name of the element.
    :type name: ElementName
    :param file: File object, used to get the file name.
    :type file: File
    :param model: Model ID of the element.
    :type model: int
    :param element: Element object.
    :type element: Element
    :param maxtype: Maximum type value.
    :type maxtype: int
    :param maxname: Maximum name value.
    :type maxname: int
    
    :return: Status of the operation.
    :rtype: BentleyStatus
    """
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
    """
    Callback function that is called before a file is restored to a specific revision.
    
    :param file: The file object to be restored. Can be None.
    :type file: File or None
    :param targetRev: The target revision to which the file should be restored.
    :type targetRev: int
    
    :return: Status of the operation.
    :rtype: BentleyStatus
    """
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
    """
    Callback function that is triggered after a file is restored to a specific revision.
    
    :param file: The file object that was restored. Can be None.
    :type file: File or None
    :param targetRev: The target revision number to which the file was restored.
    :type targetRev: int
    """
    if file is not None:
        message = "[file]: " + str(file.GetFileName())
    else:
        message = "[file]: None"

    message += "\n"
    message += "target revison: " + str(targetRev)
    print("Callback OnPostRestore:\n" + message)

# Set history callbacks
def AddCallbacks():
    """
    Registers various callback functions for design history events.

    This function adds pre and post callback functions for different events related to design history such as commit, create, delete, combine, update, format, compare, display, describe, and restore. Each callback is associated with a specific event and is called at appropriate times during the event's lifecycle.

    Callbacks:
        - OnPreCommit: Called before changes are committed to design history.
        - OnPostCommit: Called after changes are committed to design history.
        - OnPreCreate: Called before design history is initialized in a file.
        - OnPostCreate: Called after design history is initialized in a file.
        - OnPreDelete: Called before design history is deleted from a file.
        - OnPostDelete: Called after design history is deleted from a file.
        - OnPreCombine: Called before revisions in history are combined.
        - OnPostCombine: Called after revisions in history are combined or if the attempt fails.
        - OnPreDeleteEarlyRevisions: Called before revisions in history are removed.
        - OnPostDeleteEarlyRevisions: Called after revisions in history are removed or if the attempt fails.
        - OnPreUpdateRevisionUserDesc: Called before the description and/or user name of a revision are modified.
        - OnPostUpdateRevisionUserDesc: Called after the description and/or user name are modified or if the attempt fails.
        - OnFormatRevisionNumber: Called to format history revision number.
        - OnCompareElements: Called to allow the user to interactively compare revisions of an element.
        - OnDisplayElement: Called to interactively display the properties of an element to the user.
        - OnDescribeElement: Called to show the user a description of an element.
        - OnPreRestore: Called before changes are restored from design history.
        - OnPostRestore: Called after changes are restored from design history.
    """
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
    """
    Remove all registered history callbacks.

    This function removes various callbacks related to design history operations.
    The callbacks are removed in the following order:
    
    - Commit Pre Function
    - Commit Post Function
    - Create Pre Function
    - Create Post Function
    - Delete Pre Function
    - Delete Post Function
    - Combine Pre Function
    - Combine Post Function
    - Delete Early Revisions Pre Function
    - Delete Early Revisions Post Function
    - Update Revision User Description Pre Function
    - Update Revision User Description Post Function
    - Format Revision Number Function
    - Compare Elements Function
    - Display Element Function
    - Describe Element Function
    - Restore Pre Function
    - Restore Post Function

    Each callback is identified by a unique string combining the file name and the callback name.
    """
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
    