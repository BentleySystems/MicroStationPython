/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MdlApi\changetrack.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/MdlApi/changetrack.fdf>
#include <pybind11/functional.h>
#include "CallbackHelper.h"


static const char* __doc_Bentley_MstnPlatform_ChangeTrackCallback_AddChangedFunction = R"doc(@Description An MDL application can use this to set a function to be
called whenever an element is directly changed in MicroStation.
@Remarks <i>NOTE</i>: A single MDL application can have multiple
callbacks for the same event. If <code>newFunc</code> is NULL, then
*all* callbacks for this event for this MDL application are removed.
To remove callback individually use ChangeTrackCallback.RemoveChangedFunction. 
@Param(input) newFunc The new function to call, or NULL.
@Param(input) funcID Unique ID of the callback function that user defines.)doc";

static const char* __doc_Bentley_MstnPlatform_ChangeTrackCallback_RemoveChangedFunction = R"doc(@Description Removes a callback function previously installed using
ChangeTrackCallback.AddChangedFunction 
@Param(input) oldFunc The callback function to remove.
@Param(input) funcID Unique ID of the callback function that user defines.)doc";

static const char* __doc_Bentley_MstnPlatform_ChangeTrackCallback_AddUndoRedoFunction = R"doc(@Description An MDL application can use this to set a function to be
called whenever an element is changed by either the Undo or Redo
command in MicroStation. @Remarks <i>NOTE</i>: A single MDL
application can have multiple callbacks for the same event. If
<code>newFunc</code> is NULL, then *all* callbacks for this event for
this MDL application are removed. To remove callback individually use
ChangeTrackCallback.RemoveUndoRedoFunction.
@Param(input) newFunc The new function to call, or NULL.
@Param(input) funcID Unique ID of the callback function that user defines.)doc";

static const char* __doc_Bentley_MstnPlatform_ChangeTrackCallback_RemoveUndoRedoFunction = R"doc(@Description Removes a callback function previously installed using
ChangeTrackCallback.AddUndoRedoFunction 
@Param(input) oldFunc The callback function to remove.
@Param(input) funcID Unique ID of the callback function that user defines.)doc";

static const char* __doc_Bentley_MstnPlatform_ChangeTrackCallback_AddXAttributeChangedFunction = R"doc(@Description An MDL application can use this to set a function to be
called whenever an XAttribute is directly changed in MicroStation.
@Remarks <i>NOTE</i>: A single MDL application can have multiple
callbacks for the same event. If <code>newFunc</code> is NULL, then
*all* callbacks for this event for this MDL application are removed.
To remove callback individually use
ChangeTrackCallback.RemoveXAttributeChangedFunction. 
@Param(input) newFunc The new function to call, or NULL.
@Param(input) funcID Unique ID of the callback function that user defines.)doc";

static const char* __doc_Bentley_MstnPlatform_ChangeTrackCallback_RemoveXAttributeChangedFunction = R"doc(@Description Removes a callback function previously installed using
ChangeTrackCallback.AddXAttributeChangedFunction 
@Param(input) oldFunc The callback function to remove.
@Param(input) funcID Unique ID of the callback function that user defines.)doc";

static const char* __doc_Bentley_MstnPlatform_ChangeTrackCallback_AddUndoRedoXAttributeFunction = R"doc(@Description An MDL application can use this to set a function to be
called whenever an XAttribute is changed by either the Undo or Redo
command in MicroStation. @Remarks <i>NOTE</i>: A single MDL
application can have multiple callbacks for the same event. If
<code>newFunc</code> is NULL, then *all* callbacks for this event for
this MDL application are removed. To remove callback individually use
ChangeTrackCallback.RemoveXAttributeUndoRedoFunction. 
@Param(input)newFunc The new function to call, or NULL.
@Param(input) funcID Unique ID of the callback function that user defines.)doc";

static const char* __doc_Bentley_MstnPlatform_ChangeTrackCallback_RemoveUndoRedoXAttributeFunction = R"doc(@Description Removes a callback function previously installed using
ChangeTrackCallback.AddXAttributeUndoRedoFunction 
@Param(input) oldFunc The callback function to remove.
@Param(input) funcID Unique ID of the callback function that user defines.)doc";

static const char* __doc_Bentley_MstnPlatform_ChangeTrackCallback_AddUndoRedoFinishedFunction = R"doc(@Description An MDL application can use this to set a function to be
called after undo or redo command has completed. This means that all
of the changes between the start and end marks have been undone or
redone. @Remarks <i>NOTE</i>: A single MDL application can have
multiple callbacks for the same event. If <code>newFunc</code> is
NULL, then *all* callbacks for this event for this MDL application are
removed. To remove callback individually use
ChangeTrackCallback.RemoveUndoRedoFinishedFunction. 
@Param(input) newFunc The new function to call, or NULL.
@Param(input) funcID Unique ID of the callback function that user defines.)doc";

static const char* __doc_Bentley_MstnPlatform_ChangeTrackCallback_RemoveUndoRedoFinishedFunction = R"doc(@Description Removes a callback function previously installed using
ChangeTrackCallback.AddUndoRedoFinishedFunction 
@Param(input) oldFunc The callback function to remove.
@Param(input) funcID Unique ID of the callback function that user defines.)doc";

static const char* __doc_Bentley_MstnPlatform_ChangeTrackCallback_AddMarkFunction = R"doc(@Description An MDL application can use this to set a function to be
called when a change track "mark" happens. A mark signals the end of a
logically related set of changes. A mark generally means that a
Command just completed, but it may also occur in between commands.
@Remarks <i>NOTE</i>: A single MDL application can have multiple
callbacks for the same event. If <code>newFunc</code> is NULL, then
*all* callbacks for this event for this MDL application are removed.
To remove callback individually use
ChangeTrackCallback.RemoveMarkFunction. 
@Param(input) newFunc The new function to call, or NULL.
@Param(input) funcID Unique ID of the callback function that user defines.)doc";

static const char* __doc_Bentley_MstnPlatform_ChangeTrackCallback_RemoveMarkFunction = R"doc(@Description Removes a callback function previously installed using
ChangeTrackCallback.AddMarkFunction 
@Param(input) oldFunc The callback function to remove.
@Param(input) funcID Unique ID of the callback function that user defines.)doc";

static const char* __doc_Bentley_MstnPlatform_ChangeTrackCallback_AddTransientChangedFunction = R"doc(@Description An MDL application can use this to set a function to be
called when a transient element is directly changed in MicroStation.
@Remarks <i>NOTE</i>: A single MDL application can have multiple
callbacks for the same event. If <code>newFunc</code> is NULL, then
*all* callbacks for this event for this MDL application are removed.
To remove callback individually use
ChangeTrackCallback.RemoveTransientChangedFunction. 
@Param(input) newFunc The new function to call, or NULL.
@Param(input) funcID Unique ID of the callback function that user defines.)doc";

static const char* __doc_Bentley_MstnPlatform_ChangeTrackCallback_RemoveTransientChangedFunction = R"doc(@Description Removes a callback function previously installed using
ChangeTrackCallback.AddTransientChangedFunction 
@Param(input) oldFunc The callback function to remove.
@Param(input) funcID Unique ID of the callback function that user defines.)doc";

using namespace std;

function<void(XAttributeHandleCP, DgnPlatform::ChangeTrackInfo*, BoolWrapper*)> ChangeTrackFunc_XAttributeChangedHelper::m_callbackFuncs[MAX_CHANGETRACKFUNC_XATTRIBUTECHANGED_COUNT];
typename ChangeTrackFunc_XAttributeChangedHelper::ChangeTrackFunc_XAttributeChangedPtrType ChangeTrackFunc_XAttributeChangedHelper::m_callbackPtrs[MAX_CHANGETRACKFUNC_XATTRIBUTECHANGED_COUNT] = { 0 };
string ChangeTrackFunc_XAttributeChangedHelper::m_callbackIDs[MAX_CHANGETRACKFUNC_XATTRIBUTECHANGED_COUNT];

function<void(MSElementDescrP, MSElementDescrP, DgnPlatform::ChangeTrackInfo*, BoolWrapper*)> ChangeTrackFunc_ChangedHelper::m_callbackFuncs[MAX_CHANGETRACKFUNC_CHANGED_COUNT];
typename ChangeTrackFunc_ChangedHelper::ChangeTrackFunc_ChangedPtrType ChangeTrackFunc_ChangedHelper::m_callbackPtrs[MAX_CHANGETRACKFUNC_CHANGED_COUNT] = { 0 };
string ChangeTrackFunc_ChangedHelper::m_callbackIDs[MAX_CHANGETRACKFUNC_CHANGED_COUNT];

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_changetrack(py::module_& m)
    {
    py::class_<ChangeTrackCallback> c1(m, "ChangeTrackCallback"); 

    c1.def_static("AddChangedFunction", [] (function<void(MSElementDescrP, MSElementDescrP, DgnPlatform::ChangeTrackInfo*, BoolWrapper*)>& newFunc, const string& funcID)
          {
          return ChangeTrackCallback::AddChangedFunction(ChangeTrackFunc_ChangedHelper::SetCallback(newFunc, funcID));
          }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, ChangeTrackCallback, AddChangedFunction));

    c1.def_static("RemoveChangedFunction", [] (function<void(MSElementDescrP, MSElementDescrP, DgnPlatform::ChangeTrackInfo*, BoolWrapper*)>& oldFunc, const string& funcID)
          {
          return ChangeTrackCallback::RemoveChangedFunction(ChangeTrackFunc_ChangedHelper::SetCallback(oldFunc, funcID));
          }, "oldFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, ChangeTrackCallback, RemoveChangedFunction));

    c1.def_static("AddUndoRedoFunction", [] (function<ChangeTrackFunc_UndoRedo>& newFunc, const string& funcID)
          {
          ADD_FN_POINTER_CALLBACK_SIX_PARAMS(ChangeTrackCallback::AddUndoRedoFunction, MSElementDescrP, MSElementDescrP, DgnPlatform::ChangeTrackAction, bool, DgnPlatform::ChangeTrackInfo const*, DgnPlatform::ChangeTrackSource, void, newFunc, funcID);
          }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, ChangeTrackCallback, AddUndoRedoFunction));

    c1.def_static("RemoveUndoRedoFunction", [] (function<ChangeTrackFunc_UndoRedo>& oldFunc, const string& funcID)
          {
          ADD_FN_POINTER_CALLBACK_SIX_PARAMS(ChangeTrackCallback::RemoveUndoRedoFunction, MSElementDescrP, MSElementDescrP, DgnPlatform::ChangeTrackAction, bool, DgnPlatform::ChangeTrackInfo const*, DgnPlatform::ChangeTrackSource, void, oldFunc, funcID);
          }, "oldFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, ChangeTrackCallback, RemoveUndoRedoFunction));

    c1.def_static("AddXAttributeChangedFunction", [] (function<void(XAttributeHandleCP, DgnPlatform::ChangeTrackInfo*, BoolWrapper*)>& newFunc, const string& funcID)
          {
          return ChangeTrackCallback::AddXAttributeChangedFunction(ChangeTrackFunc_XAttributeChangedHelper::SetCallback(newFunc, funcID));
          }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, ChangeTrackCallback, AddXAttributeChangedFunction));

    c1.def_static("RemoveXAttributeChangedFunction", [] (function<void(XAttributeHandleCP, DgnPlatform::ChangeTrackInfo*, BoolWrapper*)>& oldFunc, const string& funcID)
          {
          return ChangeTrackCallback::RemoveXAttributeChangedFunction(ChangeTrackFunc_XAttributeChangedHelper::SetCallback(oldFunc, funcID));
          }, "oldFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, ChangeTrackCallback, RemoveXAttributeChangedFunction));

    c1.def_static("AddUndoRedoXAttributeFunction", [] (function<ChangeTrackFunc_UndoRedoXAttribute>& newFunc, const string& funcID)
          {
          ADD_FN_POINTER_CALLBACK_FIVE_PARAMS(ChangeTrackCallback::AddUndoRedoXAttributeFunction, XAttributeHandleCP, DgnPlatform::ChangeTrackAction, bool, DgnPlatform::ChangeTrackInfo const*, DgnPlatform::ChangeTrackSource, void, newFunc, funcID);
          }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, ChangeTrackCallback, AddUndoRedoXAttributeFunction));

    c1.def_static("RemoveUndoRedoXAttributeFunction", [] (function<ChangeTrackFunc_UndoRedoXAttribute>& oldFunc, const string& funcID)
          {
          ADD_FN_POINTER_CALLBACK_FIVE_PARAMS(ChangeTrackCallback::RemoveUndoRedoXAttributeFunction, XAttributeHandleCP, DgnPlatform::ChangeTrackAction, bool, DgnPlatform::ChangeTrackInfo const*, DgnPlatform::ChangeTrackSource, void, oldFunc, funcID);
          }, "oldFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, ChangeTrackCallback, RemoveUndoRedoXAttributeFunction));

    c1.def_static("AddUndoRedoFinishedFunction", [] (function<ChangeTrackFunc_UndoRedoFinished>& newFunc, const string& funcID)
          {
		  ADD_FN_POINTER_CALLBACK_ONE_PARAM(ChangeTrackCallback::AddUndoRedoFinishedFunction, bool, void, newFunc, funcID);
          }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, ChangeTrackCallback, AddUndoRedoFinishedFunction));

    c1.def_static("RemoveUndoRedoFinishedFunction", [] (function<ChangeTrackFunc_UndoRedoFinished>& oldFunc, const string& funcID)
          {
		  ADD_FN_POINTER_CALLBACK_ONE_PARAM(ChangeTrackCallback::RemoveUndoRedoFinishedFunction, bool, void, oldFunc, funcID);
          }, "oldFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, ChangeTrackCallback, RemoveUndoRedoFinishedFunction));

    c1.def_static("AddMarkFunction", [] (function<ChangeTrackFunc_Mark>& newFunc, const string& funcID)
          {
          ADD_FN_POINTER_CALLBACK_NO_PARAM(ChangeTrackCallback::AddMarkFunction, void, newFunc, funcID);
          }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, ChangeTrackCallback, AddMarkFunction));

    c1.def_static("RemoveMarkFunction", [] (function<ChangeTrackFunc_Mark>& oldFunc, const string& funcID)
          {
          ADD_FN_POINTER_CALLBACK_NO_PARAM(ChangeTrackCallback::RemoveMarkFunction, void, oldFunc, funcID);
          }, "oldFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, ChangeTrackCallback, RemoveMarkFunction));

    c1.def_static("AddTransientChangedFunction", [] (function<void(MSElementDescrP, MSElementDescrP, DgnPlatform::ChangeTrackInfo*, BoolWrapper*)>& newFunc, const string& funcID)
          {
          return ChangeTrackCallback::AddTransientChangedFunction(ChangeTrackFunc_ChangedHelper::SetCallback(newFunc, funcID));
          }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, ChangeTrackCallback, AddTransientChangedFunction));

    c1.def_static("RemoveTransientChangedFunction", [] (function<void(MSElementDescrP, MSElementDescrP, DgnPlatform::ChangeTrackInfo*, BoolWrapper*)>& oldFunc, const string& funcID)
          {
          return ChangeTrackCallback::RemoveTransientChangedFunction(ChangeTrackFunc_ChangedHelper::SetCallback(oldFunc, funcID));
          }, "oldFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, ChangeTrackCallback, RemoveTransientChangedFunction));
    }