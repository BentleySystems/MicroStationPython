/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\itxnmanager.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ITxnManager.h>



static const char * __doc_Bentley_DgnPlatform_ITxnManager_IsUndoInProgress =R"doc(Query if undo/redo is in progress)doc";

static const char * __doc_Bentley_DgnPlatform_ITxnManager_ReinstateTxn =R"doc(Reinstate the most recent previously applied and then reversed
transaction. Since at any time multiple transactions can be reversed,
it may take multiple calls to this method to reinstate all reversed
operations.

Returns:
    SUCCESS if a reversed transaction was reinstated, ERROR if no
    transactions were reversed.)doc";

static const char * __doc_Bentley_DgnPlatform_ITxnManager_ClearReversedTxns =R"doc(Clear vestiges of any reversed transactions from memory. Reversed
transactions can be reinstated. Therefore, they still occupy memory in
the cache and in the transaction buffer. This method clears them and
makes them non-reinstateable.

Remark:
    s If any transactions are reversed, the Transaction Manager will
    automatically call this method before any new element changes can
    be journalled. That is, after a reverse, ClearReversedTxns is
    implied if anything other than Reinstate happens.)doc";

static const char * __doc_Bentley_DgnPlatform_ITxnManager_CancelToPos =R"doc(Reverse and then cancel all element changes back to a previously saved
TxnPos. This method is the same as calling ReverseToPos followed (on
successful return) by ClearReversedTxns, and is provided as a
convenience.

Parameter ``pos``:
    a TxnPos obtained from a previous call to GetCurrTxnPos.

Parameter ``callRestartFunc``:
    whether to restart the current tool afterwards, only the current
    tool should pass false.

Returns:
    SUCCESS if the transactions were reversed and cleared, ERROR if
    TxnPos is invalid.)doc";

static const char * __doc_Bentley_DgnPlatform_ITxnManager_GetCurrTxnPos =R"doc(Get the current TxnPos.

Returns:
    the current TxnPos. This value can be saved and later used to
    reverse changes that happen after this time.

See also:
    ReverseToPos CancelToPos)doc";

static const char * __doc_Bentley_DgnPlatform_ITxnManager_ReverseToPos =R"doc(Reverse all element changes back to a previously saved TxnPos.

Parameter ``pos``:
    a TxnPos obtained from a previous call to GetCurrTxnPos.

Returns:
    SUCCESS if the transactions were reversed, ERROR if TxnPos is
    invalid.

See also:
    GetCurrTxnPos CancelToPos)doc";

static const char * __doc_Bentley_DgnPlatform_ITxnManager_ReverseAll =R"doc(Reverse all element changes back to the beginning of the session.

Parameter ``prompt``:
    display a dialog warning the user of the severity of this action
    and giving an opportunity to cancel.)doc";

static const char * __doc_Bentley_DgnPlatform_ITxnManager_ReverseToMark =R"doc(Reverse all element changes back to the most recent Mark. Marks are
created by issuing the MicroStation " Mark " command.)doc";

static const char * __doc_Bentley_DgnPlatform_ITxnManager_ReverseSingleTxn =R"doc(Reverse (undo) the most recent transaction.

Parameter ``callRestartFunc``:
    whether to restart the current tool afterwards, only the current
    tool should pass false.)doc";

static const char * __doc_Bentley_DgnPlatform_ITxnManager_ReverseTxns =R"doc(Reverse (undo) the most recent transaction(s).

Parameter ``numActions``:
    the number of transactions to reverse. If numActions is greater
    than 1, the entire set of transactions will be reinstated together
    when/if ReinstateTxn is called (e.g., the user issues the
    MicroStation " REDO " command.)

Parameter ``warnIfNotActiveModel``:
    Warn user if **any** elements in the about-to-be-reversed
    transaction are from a model other than the currently active
    model. The user may then choose to abort the operation. If false,
    don't warn the user and always reverse the transaction whether it
    involves elements from non-active models or not.

Remark:
    s Reversed Transactions can be reinstated by calling ReinstateTxn.
    To completely remove all vestiges of (including the memory used
    by) a transaction, call ClearReversedTxns.

See also:
    ReinstateTxn ClearReversedTxns)doc";

static const char * __doc_Bentley_DgnPlatform_ITxnManager_RedoIsPossible =R"doc(Query if there are currently any reinstateable (redoable) changes in
the Transaction Manager

Returns:
    True if there are currently any reinstateable (redoable) changes
    in the Transaction Manager.)doc";

static const char * __doc_Bentley_DgnPlatform_ITxnManager_HasEntries =R"doc(Query if there are currently any reversible (undoable) changes in the
Transaction Manager

Returns:
    true if there are currently any reversible (undoable) changes in
    the Transaction Manager.)doc";

static const char * __doc_Bentley_DgnPlatform_ITxnManager_GetCurrGroupStartPos =R"doc(Returns:
    The TxnPos of the beginning of the innermost Transaction Group. If
    no Transaction Group is active, the TxnPos will be zero.)doc";

static const char * __doc_Bentley_DgnPlatform_ITxnManager_GetTxnGroupCount =R"doc(Return the number of entries in the current Transaction Group.)doc";

static const char * __doc_Bentley_DgnPlatform_ITxnManager_EndTxnGroup =R"doc(Close the current Transaction Group.)doc";

static const char * __doc_Bentley_DgnPlatform_ITxnManager_StartTxnGroup =R"doc(Start a new Transaction Group. Transaction Groups are used to cause
element changes that would normally be considered separate
transactions to be " grouped " into a single transaction. This means
that when the user issues the " undo " command, the entire group of
changes is undone as a single action. Groups can be nested, and until
the outermost group is closed, all element changes constitute a single
transaction.

Parameter ``startNewTxn``:
    if true, and if there is no current Transaction Group, and if
    there are pending changes, then start a new group. Otherwise
    changes from this group are included with the previous changes.

Remark:
    s This method should *always* be paired with a call to
    EndTxnGroup.)doc";

static const char * __doc_Bentley_DgnPlatform_ITxnManager_Deactivate =R"doc(Turn off the Transaction Manager. After this, changes to elements will
not be journalled. Turning off the Transaction Manager also
permanently clears any journalled changes. Therefore, turning the
Transaction Manager off and then back on has the effect of clearing
it.

See also:
    Activate)doc";

static const char * __doc_Bentley_DgnPlatform_ITxnManager_Activate =R"doc(Turn on the Transaction Manager. After this, all changes to elements
in transactable files will be journalled. @See
DgnFile::SetTransactable

See also:
    Deactivate)doc";

static const char * __doc_Bentley_DgnPlatform_ITxnManager_IsActive =R"doc(Query if the Transaction Manager is currently active

Returns:
    True if the Transaction Manager is currently active.

See also:
    Activate)doc";

static const char * __doc_Bentley_DgnPlatform_ITxnManager_DropTxnMonitor =R"doc(Drop a TxnMonitor. Releases reference to monitor.

Parameter ``monitor``:
    a monitor to drop)doc";

static const char * __doc_Bentley_DgnPlatform_ITxnManager_AddTxnMonitor =R"doc(Add a TxnMonitor. Adds a reference to monitor.

Parameter ``monitor``:
    a monitor to add)doc";

static const char * __doc_Bentley_DgnPlatform_ITxnManager_FindElement =R"doc(Find the pre-change state of an element in the undo buffer.

Parameter ``model``:
    the model that contains or contained the element

Parameter ``eid``:
    the ElementId of the element to find

Parameter ``start``:
    the start of the range to search

Parameter ``end``:
    the end of the range to search

Parameter ``action``:
    the type of change to search for)doc";

static const char * __doc_Bentley_DgnPlatform_ITxnManager_SetCurrentTxn =R"doc(Set the current ITxn

Parameter ``newTxn``:
    the ITxn implementation that is to handle changes in the current
    transaction)doc";

static const char * __doc_Bentley_DgnPlatform_ITxnManager_GetCurrentTxn =R"doc(Get the current transaction)doc";

static const char * __doc_Bentley_DgnPlatform_ITxnManager_CloseCurrentTxn =R"doc(End the current transaction, either committing or cancelling the
changes made. If changes are to be discarded, then this function will
call CancelToPos. If changes are to be retained, then this function
will invoke TxnMonitor callbacks and then set a closing mark. The
closing mark designates that all of the preceding changes are to be
undone together as a single operation, and that future changes are to
be undone separately.

Parameter ``[in]``:
    doValidate if true, calls ValidateCurrentTxn before committing the
    transaction.

Remark:
    s If there is a Transaction Group active, the effect of this
    method is only to validate the transaction, if requested. @See
    SetCommitChanges.)doc";

static const char * __doc_Bentley_DgnPlatform_ITxnManager_ValidateCurrentTxn =R"doc(Validate the changes in the current transaction by notifying the
dependency manager. Note that validation often causes further changes
to elements. These changes become part of the current transaction.

Remark:
    s This function calls TxnMonitors.)doc";

static const char * __doc_Bentley_DgnPlatform_ITxnManager_GetManager =R"doc(Get the transaction manager)doc";

static const char * __doc_Bentley_DgnPlatform_ITxn_SaveModelProperties =R"doc(Update the model's properties

Parameter ``model``:
    The model whose properties are to be saved.

Parameter ``bSaveSettings``:
    If true, the non-undoable attributes of the model are also saved
    and journaled in undo. This is rarely needed. Normally, non-
    undoable attributes are not saved until the user does save
    settings and are not saved in the undo buffer.

Parameter ``forceSave``:
    If true, the equality comparison is skipped and model properties
    are saved even if no changes are found. This is needed when model
    is recreated and OnModelChange event have to be triggered.

Remark:
    s To change a model's properties you must make a copy of the
    model's ModelInfo. Modify the copy then apply the changes back to
    the model by calling DgnFile::ProcessChanges in order to make
    persistable changes actually persistent.

Remark:
    s Invokes DgnModel::SaveModelInfo, TxnMonitor::_OnModelChange)doc";

static const char * __doc_Bentley_DgnPlatform_ITxn_DeleteModel =R"doc(Delete a model. Functions that look up models such as
DgnFile::FindModelIdByName and model collections such as ModelIndex
will *not* return a deleted model.

Parameter ``dgnModel``:
    The DgnModel holding the model to be deleted.

Remark:
    s This function does not actually remove the model from the
    physical file. Call DgnFile::ProcessChanges to remove deleted
    models from a file.

Remark:
    s Deleting a model causes all DgnAttachments that currently point
    to the model to drop their pointers to it. This does not, however,
    cause the attachments themselves to be deleted.

Remark:
    s Invokes TxnMonitor::_OnModelChange)doc";

static const char * __doc_Bentley_DgnPlatform_ITxn_CreateNewModel =R"doc(Create a new model in the specified file and make it a root. The model
is assigned the next available ModelId.



Parameter ``file``:
    The file where the new model will be created.

Parameter ``name``:
    The name of the model to be created. Must be unique.

Parameter ``type``:
    Model type to create.

Parameter ``is3D``:
    True to create 3D model else a 2D model is created.

Parameter ``seedModel``:
    Seed model used to set default model settings. If NULL then the
    Default model will be used as seed.

Parameter ``modelId``:
    id for new model. Leave as INVALID_MODELID and it will be assigned
    a new valid id.

Remark:
    This function calls DgnFile::AddRootModel.

Returns (Tuple, 0):
    A pointer to a new DgnModel for the new model, or NULL if the
    model could not be created. See *error* for error details.


Returns (Tuple, 1):
	err.if not NULL, *error* is set to a non-zero error status if the
    return value is NULL. Possible values include:\li
    DGNMODEL_STATUS_InvalidModelName if name is NULL or cannot be used
    as a model name \li DGNMODEL_STATUS_DuplicateModelName if an
    existing model in this file already uses the specified name \li
    DGNMODEL_STATUS_NotFound if *seedModel* is NULL and if no default
    seed model can be found



)doc";

static const char * __doc_Bentley_DgnPlatform_ITxn_ReplaceElement =R"doc(Replace an existing element in a model with a different one.

Parameter ``el``:
    The element to be replaced.

Parameter ``in``:
    The ElementRefP of the element to be replaced. Must be a valid
    existing element.

Parameter ``opts``:
    options

Returns:
    SUCCESS if the element was replaced and out is non-NULL.)doc";

static const char * __doc_Bentley_DgnPlatform_ITxn_AddElement =R"doc(Add a new element to a model.

Remark:
    s *newEl* must already be associated with a model.

Parameter ``newEl``:
    The element to be added. Must hold an MSElementDescr.

Parameter ``opts``:
    options

Returns:
    SUCCESS if the element was added or non-zero indicating failure.
    Possible reasons for failure include:-- *newEl* is not associated
    with a model, -- the model is not writable, -- the element handler
    blocked the add, -- the element could not be assigned an
    ElementId, -- any scheduled XAttribute change failed.)doc";

static const char * __doc_Bentley_DgnPlatform_ITxn_DeleteElement =R"doc(Delete an element from a model.

Parameter ``elem``:
    The ElementRefP of the element to be deleted. Must be a valid
    existing element.

Parameter ``opts``:
    options

Returns:
    SUCCESS if the element was deleted.)doc";

static const char * __doc_Bentley_DgnPlatform_ITxn_ReplaceXAttributeData =R"doc(Replace an existing XAttribute with a new value. The size of the
XAttribute *can* change with this method.

Parameter ``xAttr``:
    An XAttributeHandle that refernces the XAttribute to replace.

Parameter ``data``:
    The new data to save in the XAttribute.

Parameter ``newSize``:
    The number of bytes in *data.*

Parameter ``opts``:
    options

Returns:
    SUCCESS if the data in *xAttr* was replaced.
    DGNMODEL_STATUS_InvalidXattribute if xAttr was not valid. Remarks
    Implementation must use DependencyMgrXAttributeChangeTracker)doc";

static const char * __doc_Bentley_DgnPlatform_ITxn_ModifyXAttributeData =R"doc(Modify all or part of an existing XAttribute. The size of the
XAttribute cannot be changed.

Parameter ``xAttr``:
    An XAttributeHandle that refernces the XAttribute to modify.

Parameter ``data``:
    The new data to save in the XAttribute.

Parameter ``start``:
    The starting byte number to replace with *data.*

Parameter ``length``:
    The number of bytes to replace with *data.*

Parameter ``opts``:
    options

Returns:
    SUCCESS if the data in *xAttr* was modified.
    DGNMODEL_STATUS_InvalidXattribute if xAttr was not valid. ERROR if
    attempting to write more data than exists in xAttr. Remarks
    Implementation must use DependencyMgrXAttributeChangeTracker)doc";

static const char * __doc_Bentley_DgnPlatform_ITxn_DeleteXAttribute =R"doc(Delete an existing XAttribute from an element.

Parameter ``xAttr``:
    An XAttributeHandle that refernces the XAttribute to delete.

Parameter ``opts``:
    options

Returns:
    SUCCESS if *xAttr* is valid and the XAttribute was deleted from
    the element. DGNMODEL_STATUS_InvalidXattribute if xAttr was not
    valid. Remarks Implementation must use
    DependencyMgrXAttributeChangeTracker)doc";

static const char * __doc_Bentley_DgnPlatform_ITxn_AddXAttribute =R"doc(@name XAttributes Add a new XAttribute to an existing element.

Parameter ``elRef``:
    The ElementRefP of the element.

Parameter ``handlerId``:
    The XAttributeHandlerId of the new XAttribute.

Parameter ``xAttrId``:
    The XAttributeId of the new XAttribute. If INVALID_XATTR_ID, then
    a new, unique, id will be assigned. The value of the new id will
    be returned in *outXAttrId.*

Parameter ``xAttrData``:
    A buffer of at least *length* bytes long that holds the value to
    be saved in the new XAttribute.

Parameter ``length``:
    The number of bytes in xAttrData.

Parameter ``outXAttrId``:
    Optional, the id of the new XAttribute. This is necessary only if
    *xAttrId* is INVALID_XATTR_ID, in which case the new XAttribute is
    assigned a new unique id.

Parameter ``opts``:
    options Remarks Implementation must use
    DependencyMgrXAttributeChangeTracker

Returns (Tuple,0):
    SUCCESS if the XAttribute was added to the ElementRefP.

Returns (Tuple,1):
	outXAttrId.

)doc";

static const char * __doc_Bentley_DgnPlatform_TxnElementWriteOptions_SetSaveInUndo =R"doc(Set the option to save in undo. Defaults to true.)doc";

static const char * __doc_Bentley_DgnPlatform_TxnElementWriteOptions_GetSaveInUndo =R"doc(Get the option to save in undo.)doc";

static const char * __doc_Bentley_DgnPlatform_TxnElementWriteOptions_SetCallAsynchs =R"doc(Set the option to call asynchs. Defaults to true.)doc";

static const char * __doc_Bentley_DgnPlatform_TxnElementWriteOptions_GetCallAsynchs =R"doc(Get the option to call asynchs.)doc";

static const char * __doc_Bentley_DgnPlatform_TxnMonitor__OnUndoInvalidated =R"doc(The undo buffer has become invalidated and reset during an undo
operation. This is a rare but drastic occurrence.)doc";

static const char * __doc_Bentley_DgnPlatform_TxnMonitor__OnModelUndoRedo =R"doc(A model change is being undone or redone.

Parameter ``model``:
    The model that is being changed.

Parameter ``modelInfo``:
    The pre- or post-change properties of the model.

Parameter ``reverseSettingsChanges``:
    If true, the model's settings (usually non-undoable) are also
    being changed.

Parameter ``isPreChange``:
    If true, undo/redo is about to be done. if false, undo/redo has
    been done.

Parameter ``isUndo``:
    If true, the model change is being undone. Else, the change is
    being redone.)doc";

static const char * __doc_Bentley_DgnPlatform_TxnMonitor__OnModelChange =R"doc(The specified model has been changed.

Parameter ``model``:
    The model that is being changed.

Parameter ``modelInfo``:
    If *isPreChange* is true, then model's info has not been changed
    yet, and *modelInfo* is the info that will be adopted. If
    *isPreChange* is false, then model's info has been changed, and
    *modelInfo* is the info that it had before the change.

Parameter ``isPreChange``:
    If true, the model is about to be changed. if false, the model has
    been changed.

Parameter ``info``:
    What kind of change was made.

Parameter ``cantBeUndoneFlag``:
    set this to true if the change should be non-undoable.

Remark:
    s setting cantBeUndoneFlag to true disables undo of all changes,
    not just this one.)doc";

static const char * __doc_Bentley_DgnPlatform_TxnMonitor__OnTxnBoundary =R"doc(The current transaction is closed -- called after the display is
updated.)doc";

static const char * __doc_Bentley_DgnPlatform_TxnMonitor__OnTxnClose =R"doc(The current transaction is closed -- called before the display is
updated.)doc";

static const char * __doc_Bentley_DgnPlatform_TxnMonitor__OnTxnValidate =R"doc(The current transaction is about to be closed.)doc";

static const char * __doc_Bentley_DgnPlatform_TxnMonitor__OnUndoRedoFinished =R"doc(Undo or redo is finished.

Parameter ``isUndo``:
    True indicates undo. False indicates redo.)doc";

static const char * __doc_Bentley_DgnPlatform_TxnMonitor__OnXAttributeUndoRedo =R"doc(An XAttribute change was undone or redone

Parameter ``xattr``:
    The XAttribute that is being changed.

Parameter ``originalChange``:
    The change that is being undone or redone.

Parameter ``isUndo``:
    If true, the change is being undone. Else, the change is being
    redone.

Parameter ``info``:
    What kind of change was made.)doc";

static const char * __doc_Bentley_DgnPlatform_TxnMonitor__OnElementUndoRedo =R"doc(An element change was undone or redone

Parameter ``afterUndoRedo``:
    The element after the change or NULL for delete.

Parameter ``beforeUndoRedo``:
    The element before the change or NULL for add.

Parameter ``originalChange``:
    The change that is being undone or redone

Parameter ``isUndo``:
    If true, the change is being undone. Else, the change is being
    redone.

Parameter ``info``:
    What kind of change was made.)doc";

static const char * __doc_Bentley_DgnPlatform_TxnMonitor__OnXAttributeChanged =R"doc(The specified XAttribute was changed

Parameter ``attr``:
    The XAttribute that was changed.

Parameter ``info``:
    What kind of change was made.

Parameter ``cantBeUndoneFlag``:
    Set this to true if the change should be non-undoable.

Remark:
    s setting cantBeUndoneFlag to true disables undo of all changes,
    not just this one.)doc";

static const char * __doc_Bentley_DgnPlatform_TxnMonitor__OnElementChanged =R"doc(The specified element was changed

Parameter ``newDscr``:
    The element after the change or NULL for delete.

Parameter ``oldDscr``:
    The element before the change or NULL for add.

Parameter ``info``:
    What kind of change was made.

Parameter ``cantBeUndoneFlag``:
    Set this to true if the change should be non-undoable.

Remark:
    s setting cantBeUndoneFlag to true disables undo of all changes,
    not just this one.)doc";

//=======================================================================================
// Trampoline class for TxnMonitor.
// @bsiclass                                                                   02/23
//=======================================================================================
struct PyTxnMonitor : TxnMonitor
    {
    using IRefCounted::operator new;
    using IRefCounted::operator delete;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _OnElementChanged(MSElementDescrCP newDscr, MSElementDescrCP oldDscr, ChangeTrackInfoCP info, bool* cantBeUndoneFlag) override
        {
        try
            {
            py::gil_scoped_acquire gil;
            py::function pyfunc = py::get_override(this, "_OnElementChanged");
            if (pyfunc)
                {
                // _OnElementChanged(newDscr, oldDscr, info) -> cantBeUndoneFlag
                auto obj = pyfunc(newDscr, oldDscr, info);
                if (cantBeUndoneFlag)
                    *cantBeUndoneFlag = obj.cast<bool>();
                }
            else
                __super::_OnElementChanged(newDscr, oldDscr, info, cantBeUndoneFlag);
            }
        catch (std::exception& ex)
            {
            ScriptEngineManager::Get().InjectException(ex);
            }
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _OnXAttributeChanged(XAttributeHandleCR attr, ChangeTrackInfoCP info, bool* cantBeUndoneFlag) override
        {
        try
            {
            py::gil_scoped_acquire gil;
            py::function pyfunc = py::get_override(this, "_OnXAttributeChanged");
            if (pyfunc)
                {
                // _OnXAttributeChanged(attr, info) -> cantBeUndoneFlag
                auto obj = pyfunc(attr, info);
                if (cantBeUndoneFlag)
                    *cantBeUndoneFlag = obj.cast<bool>();
                }
            else
                __super::_OnXAttributeChanged(attr, info, cantBeUndoneFlag);
            }
        catch (std::exception& ex)
            {
            ScriptEngineManager::Get().InjectException(ex);
            }
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _OnElementUndoRedo(MSElementDescrCP afterUndoRedo, MSElementDescrCP beforeUndoRedo, ChangeTrackAction originalChange, bool isUndo, ChangeTrackSource source, ChangeTrackInfoCP info) override
        { PYBIND11_OVERRIDE_EX(void, TxnMonitor, _OnElementUndoRedo, afterUndoRedo, beforeUndoRedo, originalChange, isUndo, source, info); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _OnXAttributeUndoRedo(XAttributeHandleCR xattr, ChangeTrackAction originalChange, bool isUndo, ChangeTrackSource source, ChangeTrackInfoCP info) override
        { PYBIND11_OVERRIDE_EX(void, TxnMonitor, _OnXAttributeUndoRedo, xattr, originalChange, isUndo, source, info); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _OnUndoRedoFinished(bool isUndo) override
        { PYBIND11_OVERRIDE_EX(void, TxnMonitor, _OnUndoRedoFinished, isUndo); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _OnTxnValidate() override
        { PYBIND11_OVERRIDE_EX(void, TxnMonitor, _OnTxnValidate, ); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _OnTxnClose() override
        { PYBIND11_OVERRIDE_EX(void, TxnMonitor, _OnTxnClose, ); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _OnTxnBoundary() override
        { PYBIND11_OVERRIDE_EX(void, TxnMonitor, _OnTxnBoundary, ); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _OnModelChange(DgnModelP model, ModelInfoCP modelInfo, bool isPreChange, ChangeTrackInfoCR info, bool* cantBeUndoneFlag) override
        {
        try
            {
            py::gil_scoped_acquire gil;
            py::function pyfunc = py::get_override(this, "_OnModelChange");
            if (pyfunc)
                {
                // _OnModelChange(model, modelInfo, isPreChange, info) -> cantBeUndoneFlag
                auto obj = pyfunc(model, modelInfo, isPreChange, info);
                if (cantBeUndoneFlag)
                    *cantBeUndoneFlag = obj.cast<bool>();
                }
            else
                __super::_OnModelChange(model, modelInfo, isPreChange, info, cantBeUndoneFlag);
            }
        catch (std::exception& ex)
            {
            ScriptEngineManager::Get().InjectException(ex);
            }
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _OnModelUndoRedo(DgnModelP model, ModelInfoCP modelInfo, bool reverseSettingsChanges, bool isUndo, bool isPreChange, ChangeTrackSource source, ChangeTrackInfoCR info) override
        { PYBIND11_OVERRIDE_EX(void, TxnMonitor, _OnModelUndoRedo, model, modelInfo, reverseSettingsChanges, isUndo, isPreChange, source, info); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _OnUndoInvalidated() override
        { PYBIND11_OVERRIDE_EX(void, TxnMonitor, _OnUndoInvalidated, ); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual UInt32 AddRef() const override
        { PYBIND11_OVERRIDE_PURE_EXR(UInt32, TxnMonitor, AddRef, 0, ); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual UInt32 Release() const override
        { PYBIND11_OVERRIDE_PURE_EXR(UInt32, TxnMonitor, Release, 0, ); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ITxnManager(py::module_& m)
    {
    //===================================================================================
    // struct ChangeTrackInfo
    py::class_< ChangeTrackInfo> c1(m, "ChangeTrackInfo");

    c1.def_readwrite("action", &ChangeTrackInfo::action);
    c1.def_readwrite("processNumber", &ChangeTrackInfo::processNumber);
    c1.def_readwrite("funcName", &ChangeTrackInfo::funcname);
    c1.def_readwrite("idNumber", &ChangeTrackInfo::idNumber);
    
    //===================================================================================
    // enum class DgnECChangeType
    py::enum_< DgnPlatform::DgnECChangeType>(m, "DgnECChangeType")
        .value("eNone", DgnPlatform::DgnECChangeType::None)
        .value("eAdded", DgnPlatform::DgnECChangeType::Added)
        .value("eDeleted", DgnPlatform::DgnECChangeType::Deleted)
        .value("eModified", DgnPlatform::DgnECChangeType::Modified)
        .export_values();

    //===================================================================================
    // struct TxnPos
    py::class_<DgnPlatform::TxnPos> c2(m, "TxnPos");

    c2.def_readwrite("pos", &DgnPlatform::TxnPos::m_pos);

    //===================================================================================
    // struct TxnMonitor
    py::class_< TxnMonitor, RefCountedPtr<TxnMonitor>, PyTxnMonitor > c3(m, "TxnMonitor");

    c3.def(py::init<>());
    c3.def("_OnElementChanged", [] (TxnMonitor& self, MSElementDescrCP newDscr, MSElementDescrCP oldDscr, ChangeTrackInfoCP info)
           {
           bool cantBeUndoneFlag = false;
           self._OnElementChanged(newDscr, oldDscr, info, &cantBeUndoneFlag);
           return cantBeUndoneFlag;
           }, "newDscr"_a, "oldDscr"_a, "info"_a, DOC(Bentley, DgnPlatform, TxnMonitor, _OnElementChanged));

    c3.def("_OnXAttributeChanged", [] (TxnMonitor& self, XAttributeHandleCR attr, ChangeTrackInfoCP info)
           {
           bool cantBeUndoneFlag = false;
           self._OnXAttributeChanged(attr, info, &cantBeUndoneFlag);
           return cantBeUndoneFlag;
           }, "attr"_a, "info"_a, DOC(Bentley, DgnPlatform, TxnMonitor, _OnXAttributeChanged));

    c3.def("_OnElementUndoRedo", &TxnMonitor::_OnElementUndoRedo, "afterUndoRedo"_a, "beforeUndoRedo"_a, "originalChange"_a, "isUndo"_a, "source"_a, "info"_a, DOC(Bentley, DgnPlatform, TxnMonitor, _OnElementUndoRedo));
    c3.def("_OnXAttributeUndoRedo", &TxnMonitor::_OnXAttributeUndoRedo, "xAttr"_a, "originalChange"_a, "isUndo"_a, "source"_a, "info"_a, DOC(Bentley, DgnPlatform, TxnMonitor, _OnXAttributeUndoRedo));
    c3.def("_OnUndoRedoFinished", &TxnMonitor::_OnUndoRedoFinished, "isUndo"_a, DOC(Bentley, DgnPlatform, TxnMonitor, _OnUndoRedoFinished));
    c3.def("_OnTxnValidate", &TxnMonitor::_OnTxnValidate, DOC(Bentley, DgnPlatform, TxnMonitor, _OnTxnValidate));
    c3.def("_OnTxnClose", &TxnMonitor::_OnTxnClose, DOC(Bentley, DgnPlatform, TxnMonitor, _OnTxnClose));
    c3.def("_OnTxnBoundary", &TxnMonitor::_OnTxnBoundary, DOC(Bentley, DgnPlatform, TxnMonitor, _OnTxnBoundary));

    c3.def("_OnModelChange", [] (TxnMonitor& self, DgnModelP model, ModelInfoCP modelInfo, bool isPreChange, ChangeTrackInfoCR info)
           {
           bool cantBeUndoneFlag = false;
           self._OnModelChange(model, modelInfo, isPreChange, info, &cantBeUndoneFlag);
           return cantBeUndoneFlag;
           }, "model"_a, "modelInfo"_a, "isPreChange"_a, "info"_a, DOC(Bentley, DgnPlatform, TxnMonitor, _OnModelChange));

    c3.def("_OnModelUndoRedo", &TxnMonitor::_OnModelUndoRedo, "model"_a, "modelInfo"_a, "reverseSettingsChanges"_a, "isUndo"_a, "isPreChange"_a, "source"_a, "info"_a, DOC(Bentley, DgnPlatform, TxnMonitor, _OnModelUndoRedo));
    c3.def("_OnUndoInvalidated", &TxnMonitor::_OnUndoInvalidated, DOC(Bentley, DgnPlatform, TxnMonitor, _OnUndoInvalidated));

    //===================================================================================
    // struct TxnElementWriteOptions
    py::class_< TxnElementWriteOptions> c4(m, "TxnElementWriteOptions");

    c4.def(py::init<>());
    c4.def_property("CallAsynchs", &TxnElementWriteOptions::GetCallAsynchs, &TxnElementWriteOptions::SetCallAsynchs);
    c4.def("GetCallAsynchs", &TxnElementWriteOptions::GetCallAsynchs, DOC(Bentley, DgnPlatform, TxnElementWriteOptions, GetCallAsynchs));
    c4.def("SetCallAsynchs", &TxnElementWriteOptions::SetCallAsynchs, "value"_a, DOC(Bentley, DgnPlatform, TxnElementWriteOptions, SetCallAsynchs));

    c4.def_property("SaveInUndo", &TxnElementWriteOptions::GetSaveInUndo, &TxnElementWriteOptions::SetSaveInUndo);
    c4.def("GetSaveInUndo", &TxnElementWriteOptions::GetSaveInUndo, DOC(Bentley, DgnPlatform, TxnElementWriteOptions, GetSaveInUndo));
    c4.def("SetSaveInUndo", &TxnElementWriteOptions::SetSaveInUndo, "value"_a, DOC(Bentley, DgnPlatform, TxnElementWriteOptions, SetSaveInUndo));

    //===================================================================================
    // struct TxnElementAddOptions
    py::class_< TxnElementAddOptions, TxnElementWriteOptions> c5(m, "TxnElementAddOptions");

    c5.def(py::init<>());

    //===================================================================================
    // struct TxnXAttributeWriteOptions
    py::class_< TxnXAttributeWriteOptions> c6(m, "TxnXAttributeWriteOptions");

    c6.def(py::init<>());

    //===================================================================================
    /// struct TxnXAttributeAddOptions
    py::class_< TxnXAttributeAddOptions, TxnXAttributeWriteOptions> c7(m, "TxnXAttributeAddOptions");

    c7.def(py::init<>());

    //===================================================================================
    // struct ITxn
    py::class_< ITxn, std::unique_ptr<ITxn, py::nodelete> > c8(m, "ITxn");


    c8.def("AddXAttribute", [] (ITxn& self, ElementRefP elRef, XAttributeHandlerId handlerId, UInt32 xAttrId, py::bytes const& data, TxnXAttributeAddOptions const& opts)
           {
           UInt32 outXAttrId = -1;
           std::string strData = (std::string) data;
           auto retVal = self.AddXAttribute(elRef, handlerId, xAttrId, (const void*) strData.data(), (UInt32) strData.size(), &outXAttrId, opts);
           return py::make_tuple(retVal, outXAttrId);
           }, "elRef"_a, "handlerId"_a, "xAttrId"_a, "data"_a, "opts"_a = TxnXAttributeAddOptions(), DOC(Bentley, DgnPlatform, ITxn, AddXAttribute));

    c8.def("DeleteXAttribute", &ITxn::DeleteXAttribute, "xAttr"_a, "opts"_a = TxnXAttributeWriteOptions(), DOC(Bentley, DgnPlatform, ITxn, DeleteXAttribute));

    c8.def("ModifyXAttributeData", [] (ITxn& self, XAttributeHandleCR xAttr, py::bytes const& data, UInt32 start, TxnXAttributeWriteOptions const& opts)
           {
           std::string strData = (std::string) data;
           UInt32 length = (UInt32) strData.size();
           return self.ModifyXAttributeData(xAttr, (void const*)strData.data(), start, length, opts);           
           }, "xAttr"_a, "data"_a, "start"_a, "opts"_a = TxnXAttributeWriteOptions(), DOC(Bentley, DgnPlatform, ITxn, ModifyXAttributeData));

    c8.def("ReplaceXAttributeData", [] (ITxn& self, XAttributeHandleCR xAttr, py::bytes const& data, TxnXAttributeWriteOptions const& opts)
           {
           std::string strData = (std::string) data;
           UInt32 newSize = (UInt32) strData.size();
           return self.ReplaceXAttributeData(xAttr, (void const*) strData.data(), newSize, opts);
           }, "xAttr"_a, "data"_a, "opts"_a = TxnXAttributeWriteOptions(), DOC(Bentley, DgnPlatform, ITxn, ReplaceXAttributeData));

    c8.def("DeleteElement", &ITxn::DeleteElement, "elemRef"_a, "opts"_a = TxnElementWriteOptions(), DOC(Bentley, DgnPlatform, ITxn, DeleteElement));
    c8.def("AddElement", &ITxn::AddElement, "newEeh"_a, "opts"_a = TxnElementAddOptions(), DOC(Bentley, DgnPlatform, ITxn, AddElement));
    c8.def("ReplaceElement", &ITxn::ReplaceElement, "eeh"_a, "elemRef"_a, "opts"_a = TxnElementWriteOptions(), DOC(Bentley, DgnPlatform, ITxn, ReplaceElement));
    
    c8.def("CreateNewModel", [] (ITxn& self, DgnFileR file, WCharCP name, DgnModelType type, bool is3D, DgnModelCP seedModel, ModelId modelId)
           {
           DgnModelStatus err = DGNMODEL_STATUS_Success;
           auto retVal = self.CreateNewModel(&err, file, name, type, is3D, seedModel, modelId);
           return py::make_tuple(retVal, err);
           }, "dgnFile"_a, "modelName"_a, "modelType"_a, "is3D"_a, "seedModel"_a = nullptr, "modelId"_a = INVALID_MODELID, DOC(Bentley, DgnPlatform, ITxn, CreateNewModel));

    c8.def("CreateNewModel", [] (ITxn& self, DgnFileR file, ModelInfoCR modelInfo, ModelId modelId)
           {
           DgnModelStatus err = DGNMODEL_STATUS_Success;
           auto retVal = self.CreateNewModel(&err, file, modelInfo, modelId);
           return py::make_tuple(retVal, err);
           }, "dgnFile"_a, "modelInfo"_a, "modelId"_a = INVALID_MODELID, DOC(Bentley, DgnPlatform, ITxn, CreateNewModel));

    c8.def("DeleteModel", &ITxn::DeleteModel, "dgnModel"_a, DOC(Bentley, DgnPlatform, ITxn, DeleteModel));
    c8.def("SaveModelProperties", &ITxn::SaveModelProperties, "model"_a, "bSaveSettings"_a = false, "forceSave"_a = false, DOC(Bentley, DgnPlatform, ITxn, SaveModelProperties));
    
    //===================================================================================
    // struct ITxnManager
    py::class_< ITxnManager, std::unique_ptr<ITxnManager, py::nodelete>, DgnHost::HostObjectBase> c9(m, "ITxnManager");


    c9.def_property_readonly_static("Manager", [] (py::object const&) { return std::unique_ptr< ITxnManager, py::nodelete>(&ITxnManager::GetManager()); });
    c9.def_static("GetManager", [] () { return std::unique_ptr< ITxnManager, py::nodelete>(&ITxnManager::GetManager()); }, DOC(Bentley, DgnPlatform, ITxnManager, GetManager));

    c9.def("ValidateCurrentTxn", &ITxnManager::ValidateCurrentTxn, DOC(Bentley, DgnPlatform, ITxnManager, ValidateCurrentTxn));
    c9.def("CloseCurrentTxn", &ITxnManager::CloseCurrentTxn, "doValidate"_a, DOC(Bentley, DgnPlatform, ITxnManager, CloseCurrentTxn));
    c9.def("UpdateDisplay", &ITxnManager::UpdateDisplay, "andDraw"_a = true);

    c9.def_property_readonly_static("CurrentTxn", [] (py::object const&) { return std::unique_ptr<ITxn, py::nodelete>(&ITxnManager::GetCurrentTxn()); });
    c9.def_static("GetCurrentTxn", [] () { return std::unique_ptr<ITxn, py::nodelete>(&ITxnManager::GetCurrentTxn()); }, DOC(Bentley, DgnPlatform, ITxnManager, GetCurrentTxn));
    
    c9.def("SetCurrentTxn", &ITxnManager::SetCurrentTxn, "newTxn"_a, py::return_value_policy::reference_internal, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, ITxnManager, SetCurrentTxn));
    c9.def("FindElement", &ITxnManager::FindElement, "model"_a, "elementId"_a, "start"_a, "end"_a, "action"_a, DOC(Bentley, DgnPlatform, ITxnManager, FindElement));
    c9.def("AddTxnMonitor", &ITxnManager::AddTxnMonitor, "monitor"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, ITxnManager, AddTxnMonitor));
    c9.def("DropTxnMonitor", &ITxnManager::DropTxnMonitor, "monitor"_a, DOC(Bentley, DgnPlatform, ITxnManager, DropTxnMonitor));
    c9.def("IsActive", &ITxnManager::IsActive, DOC(Bentley, DgnPlatform, ITxnManager, IsActive));
    c9.def("Activate", &ITxnManager::Activate, DOC(Bentley, DgnPlatform, ITxnManager, Activate));
    c9.def("Deactivate", &ITxnManager::Deactivate, DOC(Bentley, DgnPlatform, ITxnManager, Deactivate));
    c9.def("StartTxnGroup", &ITxnManager::StartTxnGroup, "startNewTxn"_a, DOC(Bentley, DgnPlatform, ITxnManager, StartTxnGroup));
    c9.def("EndTxnGroup", &ITxnManager::EndTxnGroup, DOC(Bentley, DgnPlatform, ITxnManager, EndTxnGroup));

    c9.def_property_readonly("TxnGroupCount", &ITxnManager::GetTxnGroupCount);
    c9.def("GetTxnGroupCount", &ITxnManager::GetTxnGroupCount, DOC(Bentley, DgnPlatform, ITxnManager, GetTxnGroupCount));

    c9.def_property_readonly("CurrGroupStartPos", &ITxnManager::GetCurrGroupStartPos);
    c9.def("GetCurrGroupStartPos", &ITxnManager::GetCurrGroupStartPos, DOC(Bentley, DgnPlatform, ITxnManager, GetCurrGroupStartPos));

    c9.def("HasEntries", &ITxnManager::HasEntries, DOC(Bentley, DgnPlatform, ITxnManager, HasEntries));
    c9.def("RedoIsPossible", &ITxnManager::RedoIsPossible, DOC(Bentley, DgnPlatform, ITxnManager, RedoIsPossible));
    c9.def("ReverseTxns", &ITxnManager::ReverseTxns, "numActives"_a, "warnIfNotActiveModel"_a, DOC(Bentley, DgnPlatform, ITxnManager, ReverseTxns));
    c9.def("ReverseSingleTxn", &ITxnManager::ReverseSingleTxn, "callRestartFunc"_a = true, DOC(Bentley, DgnPlatform, ITxnManager, ReverseSingleTxn));
    c9.def("ReverseToMark", &ITxnManager::ReverseToMark, DOC(Bentley, DgnPlatform, ITxnManager, ReverseToMark));
    c9.def("ReverseAll", &ITxnManager::ReverseAll, "prompt"_a, DOC(Bentley, DgnPlatform, ITxnManager, ReverseAll));
    c9.def("ReverseToPos", &ITxnManager::ReverseToPos, "pos"_a, DOC(Bentley, DgnPlatform, ITxnManager, ReverseToPos));

    c9.def_property_readonly("CurrTxnPos", &ITxnManager::GetCurrTxnPos);
    c9.def("GetCurrTxnPos", &ITxnManager::GetCurrTxnPos, DOC(Bentley, DgnPlatform, ITxnManager, GetCurrTxnPos));

    c9.def("CancelToPos", &ITxnManager::CancelToPos, "pos"_a, "callRestartFunc"_a = true, DOC(Bentley, DgnPlatform, ITxnManager, CancelToPos));
    c9.def("ClearReversedTxns", &ITxnManager::ClearReversedTxns, DOC(Bentley, DgnPlatform, ITxnManager, ClearReversedTxns));
    c9.def("ReinstateTxn", py::overload_cast<>(&ITxnManager::ReinstateTxn), DOC(Bentley, DgnPlatform, ITxnManager, ReinstateTxn));
    c9.def("IsUndoInProgress", &ITxnManager::IsUndoInProgress, DOC(Bentley, DgnPlatform, ITxnManager, IsUndoInProgress));        

    }