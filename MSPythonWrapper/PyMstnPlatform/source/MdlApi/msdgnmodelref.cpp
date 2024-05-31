/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MdlApi\msdgnmodelref.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/MdlApi/msdgnmodelref.fdf>
#include <Mstn/MdlApi/msmodel.fdf>


static const char * __doc_MstnPlatform_ModelRef_GetTransient =R"doc(Remark:
    )doc";

static const char * __doc_MstnPlatform_ModelRef_IsDefault =R"doc(Remark:
    )doc";

static const char * __doc_MstnPlatform_ModelRef_GetModelType =R"doc(Remark:
    )doc";

static const char * __doc_MstnPlatform_ModelRef_IsSheet =R"doc(Remark:
    )doc";

static const char * __doc_MstnPlatform_ModelRef_IsTransient =R"doc(Remark:
    )doc";

static const char * __doc_MstnPlatform_ModelRef_Is3D =R"doc(Remark:
    )doc";

static const char * __doc_MstnPlatform_ModelRef_GetElementRef =R"doc(Remark:
    )doc";

static const char * __doc_MstnPlatform_ModelRef_GetChildCount =R"doc(Remark:
    )doc";

static const char * __doc_MstnPlatform_ModelRef_IsEmpty =R"doc(Remark:
    )doc";

static const char * __doc_MstnPlatform_ModelRef_GetAttachmentID =R"doc(Remark:
    )doc";

static const char * __doc_MstnPlatform_ModelRef_GetEof =R"doc(Remark:
    )doc";

static const char * __doc_MstnPlatform_ModelRef_LoadReferenceModels =R"doc(Loads the reference models attached to the specified modelRef. By
default, reference models are loaded only for the active modelRef (and
its descendants), and child DgnModelRefP's for other modelRefs are not
created. When this function is called, the child DgnModelRefPs will be
created so they can be iterated using ModelRefIterator.Create.

Parameter ``modelRef``:
    The modelRef for which the reference DgnModelRefPs are to be
    created.

Parameter ``loadCache``:
    true if caches should be loaded for reference models, false if
    only modelRefs should be created.

Parameter ``loadRasterRefs``:
    true if raster reference files should be loaded, false if not.

Parameter ``loadUndisplayedRefs``:
    true if even undisplayed reference files should be loaded.

Returns:
    SUCCESS or a nonzero error code. @Group " Models "

Remark:
    )doc";

static const char * __doc_MstnPlatform_ModelRef_GetUorScaleBetweenModels =R"doc(Remark:
    )doc";

static const char * __doc_MstnPlatform_ModelRef_GetDgnFile =R"doc(Remark:
    )doc";

static const char * __doc_MstnPlatform_ModelRef_GetDgnModel =R"doc(Remark:
    )doc";

static const char * __doc_MstnPlatform_ModelRef_CopyModel =R"doc(@Description Copy a model from one location to another. This function
handles copying levels, styles, etc. necessary for elements in the
model. @Remarks Export rights for the source modelRef and edit rights
for the destination file are checked. @Param[out] returnDestModelRef
Working model ref for resulting model. If NULL is not passed for this
parameter, the resulting modelRef must be freed using
ModelRef.FreeWorking. @Param[in] sourceModelRef Model to copy.
@Param[in] destFile File in which the model should be written.
@Param[in] pDestModelName Name for the copied model. @Param[in]
pDestModelDescr Description for the copied model; may be NULL. @Return
SUCCESS if the model was copied successfully; error returns are
defined in mdlerrs.r.h. @See DgnFileObj.CreateModel

Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_ModelRef_CheckAllRightsIncludingProtectedRefs =R"doc(@Description Check if the specified rights are granted to the current
user for the given model and all references, including the references
that could not be opened because the user lacked viewing access.
@Param[in] modelRef The modelRef to check. @Param[in] rights the
rights to query. See DgnFileObj.CheckRights for a description of
the rights values. @Param[in] displayError Determines whether an error
should be displayed in the message center, a pop-up dialog, or the
function should return silently. @Return SUCCESS if all of the rights
are granted for all files. MDLERR_RIGHT_NOT_GRANTED if any of the
opened references do not have the specified rights, or if there were
references that could not be opened because the user did not have any
access rights to the file.

See also:
    digitalRights_checkRights

Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_ModelRef_CheckAllRights =R"doc(@Description Check if the specified rights are granted to the current
user for the given model and all references @Param[in] modelRef The
modelRef to check. @Param[in] rights the rights to query. See
DgnFileObj.CheckRights for a description of the rights values.
@Param[in] displayError Determines whether an error should be
displayed in the message center, a pop-up dialog, or the function
should return silently. @Return SUCCESS if all of the rights are
granted for all files.

See also:
    digitalRights_checkRights

Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_ModelRef_CheckAllRightsIfDisplayed =R"doc(@Description Check if the specified rights are granted to the current
user for the given model and all references that are displayed in the
selected view(s). @Param[in] modelRef The modelRef to check.
@Param[in] rights the rights to query. See DgnFileObj.CheckRights
for a description of the rights values. @Param[in] view the view to
query or ANY_VIEW. @Param[in] displayError Determines whether an error
should be displayed in the message center, a pop-up dialog, or the
function should return silently. @Return SUCCESS if all of the rights
are granted for all files in the specified view.

See also:
    ModelRef.CheckAllRights

See also:
    digitalRights_checkRights

Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_ModelRef_GetDisplayName =R"doc(@Description Gets the string that MicroStation uses to display the
name of the modelRef in its user interface. If the modelRef is a
reference, the string consists of the logical name (if there is any),
followed by the file name, followed by the model name (if there is
more than one model in the file). @Param[in] modelRef the model for
which to retrieve the name @Param[out] displayName the display name.
@Param[in] maxChars the size of displayName, in MSWChars. @Param[in]
separator the separator to use. Maximum size allowed is 10 wide chars.
If NULL is passed in, ", " will be used by default. @Return
MDLERR_NAMETOOLONG if name does not fit, MDLERR_BADMODELREF if invalid
modelRef. @Remarks To ensure that displayName is large enough, supply
a buffer that holds MAX_MODEL_DISPLAY_LENGTH MSWChars.

See also:
    RefFile.GetInfo Bentley Systems

)doc";

static const char * __doc_MstnPlatform_ModelRef_GetRange =R"doc(@Description Gets the range for the specified modelRef. This
calculates the range for all geometry in a model - it does not ignore
elements that are not displayed in the input view. This function is
relatively fast. It does not iterate through the model but uses a
range that is stored internally. @Param[in] modelRef the model to get
the range for. @Param[out] pRange the model range

Parameter ``viewIndex``:
    index of view, used to get the clip volume of the view.

Parameter ``transformP``:
    NULL or transform to apply before calculating range.

Parameter ``includeChildren``:
    true to include the range of child references. @Return SUCCESS if
    the requested params were acceptable, otherwise ERROR

Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_ModelRef_SetDefaultBackgroundColor =R"doc(@Description Sets the model background color to the default value for
that model type. This has an effect only on sheet models, because
there is no default background color for normal models.. @Param[in]
modelRefP the modelRef for which the default background color is set.

Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_ModelRef_FreeWorking =R"doc(@Description Frees modelRef's created using ModelRef.CreateWorking
or ModelRef.CreateWorkingByName. @Param[in] modelRef the modelRef
to free. @Return SUCCESS if the model ref is freed, MDLERR_BADMODELREF
if the modelRef specified is not a working modelRef. @Remarks Only
modelRefs created with ModelRef.CreateWorking or
ModelRef.CreateWorkingByName can be freed using this function. An
attempt to free other modelRefs causes a returns value of
MDLERR_BADMODELREF.

See also:
    ModelRef.CreateWorking ModelRef.CreateWorkingByName

Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_ModelRef_CreateWorkingByName =R"doc(@Description Creates a " working " DgnModelRefP that can be passed to
functions that take DgnModelRefP arguments. The ModelRef created must
be freed using ModelRef.FreeWorking. If the file specified as
dgnFileP is read-only, then the modelRef will be read-only also.
@Param[out] dgnModelRefP modelRef referring to the model created
@Param[in] dgnFileP the file object to search for the model @Param[in]
modelNameP the name of the model to find in the design file.
@Param[in] fillCache true if the cache for the model should be filled.
Operations like changing name, description, etc., can be performed
even if the cache is not filled. @Param[in] loadRefs true if the
caches for the model's attached references should also be loaded. The
fillCache argument must be true for this to work. @Return SUCCESS if
the modelRef is returned and filled as requested.

See also:
    ModelRef.CreateWorking

Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_ModelRef_CreateCacheSpecificWorking =R"doc(@Description Creates a " working " DgnModelRefP containing the specified
cache sections that can be passed to functions that take DgnModelRefP
arguments. The ModelRef created must be freed using
~mModelRef.FreeWorking. If the file specified as dgnFileP is read-
only, then the modelRef will be read-only also. @Param dgnModelRefP
OUT modelRef referring to the model created @Param dgnFileP IN the
file object to search for the model @Param modelID IN the ID of the
model to load @Param fillCache IN true if the cache for the model
should be filled. Operations like changing name, description, etc.,
can be performed even if the cache is not filled. @Param loadRefs IN
true if the caches for the model's attached references should also be
loaded. The fillCache argument must be true for this to work. @Param
includeUndisplayedRefs IN If true, load the caches for references that
are not displayed. The fillCache and loadRefs arguments must be true
for this to work. @Param sectionsToFill IN Specific cache sections to
fill. @Return SUCCESS if the modelRef is returned and filled as
requested. @ALinkJoin usmthModelRef.CreateWorkingC

)doc";

static const char * __doc_MstnPlatform_ModelRef_CreateWorking =R"doc(@Description Creates a " working " DgnModelRefP that can be passed to
functions that take DgnModelRefP arguments. The ModelRef created must
be freed using ModelRef.FreeWorking. If the file specified as
dgnFileP is read-only, then the modelRef will be read-only also.
@Param[out] dgnModelRefP modelRef referring to the model created
@Param[in] dgnFileP the file object to search for the model @Param[in]
modelID the ID of the model to load @Param[in] fillCache true if the
cache for the model should be filled. Operations like changing name,
description, etc., can be performed even if the cache is not filled.
@Param[in] loadRefs true if the caches for the model's attached
references should also be loaded. The fillCache argument must be true
for this to work. @Return SUCCESS if the modelRef is returned and
filled as requested.

See also:
    ModelRef.CreateWorkingByName

Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_ModelRef_ActivateAndDisplay =R"doc(@Description Activates and displays the specified modelRef. The
function checks if the model is displayed in the current views and, if
not, new views are opened with the modelRef as their root. @Param[in]
newModelRef the model to activate. The modelRef must be from the
current master file. @Return SUCCESS if the model is found and
activated successfully; otherwise, ERROR.

Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_ModelRef_DeleteModel =R"doc(@Description Deletes the specified model from the file that contains
it. @Param[in] modelRef the model to delete. @Param[in] deleteElements
If true, the model will not be deleted unless it is empty. If false,
all elements assigned to the model are also deleted. @Return SUCCESS
if the model is found and deleted successfully; otherwise, ERROR.
@Remarks This action is undoable if the model is deleted from the
master file

See also:
    ModelRef.IsReadOnly

Bentley Systems

Remark:
)doc";

static const char * __doc_MstnPlatform_ModelRef_GetViewMask =R"doc(@Description Gets a bitmask representing the views that display the
specified modelRef. @Param[in] modelRef the model to get the view
bitmask for. @Return An integer value that is has one bit for each of
views 1 through 8 whether the modelRef is displayed in the
corresponding view. Bit 0 corresponds to " View 1 ".

See also:
    ModelRef.IsDisplayedInView Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_ModelRef_IsDisplayedInView =R"doc(@Description Determines whether the specified DgnPlatform::DgnModelRef
is displayed in the specified view. @Param[in] modelRef the the model
to query. @Param[in] viewIndex the view index to test. This value
should be in the range of 0 - (DgnPlatform::MAX_VIEWS-1), or the value
ANY_VIEW if the test is to see whether it is displayed in any view.
@Return true if the specified modelRef is currently displayed in the
given view. @Remarks A model is not displayed in a view if it is not
the root model for that view or one of its descendants. @Remarks If
the modelRef is a reference modelRef, it is not displayed in any view
if its display flag is turned off, or if the file or model referenced
could not be found. It is also not displayed in a particular view if
the level of its reference attachment element is turned off in that
view.

See also:
    ModelRef.GetViewMask

Bentley Systems

Remark:
)doc";

static const char * __doc_MstnPlatform_ModelRef_GetFileName =R"doc(@Description Gets the name of the file that contains the data for the
specified model. @Param[in] modelRef the model to query. @Param[out]
fileName buffer to hold the file name. @Param[in] fileNameBufSize size
of the buffer (in characters) pointed to by fileName. @Return SUCCESS
if the name is obtained without error; MDLERR_BADARG if modelRef was
invalid; MDLERR_BADMODELREF if the file could not be obtained.
@Remarks This function requires that the element cache exists for the
specified modelRef. For example, this function can fail if the
specified modelRef is a reference model that is not displayed, or is
not found. In this case, RefFile.GetRefParameter can be used to get
the file name stored in the reference attachment. @Remarks A more
modern version that returns a WString is
modelRef->GetDgnFileP()->GetFileName().

See also:
    ModelRef.GetDgnFile

Bentley Systems

Remark:

)doc";

static const char * __doc_MstnPlatform_ModelRef_AreSame =R"doc(@Description Determines whether two specified modelRefs are actually
the same. @Param[in] modelRef1 the first modelRef. @Param[in]
modelRef2 the second modelRef. @Return true if the two modelRefs the
same.

Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_ModelRef_IsReadOnly =R"doc(@Description Determines whether a modelRef is read-only. @Param[in]
modelRef the modelRef to test. @Return true if the specified model is
read-only.

See also:
    ModelRef.IsReference

Bentley Systems

Remark:
)doc";

static const char * __doc_MstnPlatform_ModelRef_IsNestedReference =R"doc(@Description Determines whether the specified reference model is
attached to another reference model. @Param[in] modelRef the model to
test. @Return true if the specified modelRef is referenced from
another referenced model.

See also:
    ModelRef.IsReference ModelRef.IsActiveModel

Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_ModelRef_GetParent =R"doc(@Description Gets the DgnModelRefP for the model that is the parent of
the specified modelRef. @Param[in] modelRef The model to get the
parent of. @Return The modelRef for the parent model of the specified
modelRef if a parent exists; otherwise, NULL. @Remarks Reference
attachments have a parent, but the active model does not. The parent
of a directly attached reference is the active model. The parent of a
nested reference is the model to which it is attached.

Bentley Systems

Remark:
)doc";

static const char * __doc_MstnPlatform_ModelRef_IsReference =R"doc(@Description Determines whether the specified modelRef is a reference
model. @Param[in] modelRef The model to test. @Return true if the
specified modelRef represents a reference model.

Bentley Systems

Remark:
)doc";

static const char * __doc_MstnPlatform_ModelRef_IsActiveModel =R"doc(@Description Determines whether the specified modelRef is the active
model. @Param[in] modelRef the model to test. @Return true, if the
modelRef is the currently active model.

See also:
    ModelRef.IsReference ustmthModelRef.IsNestedReferenceC

)doc";

static const char * __doc_MstnPlatform_ModelRef_InMasterFile =R"doc(@Description Determines whether the specified modelRef is contained in
the master file. @Param[in] modelRef the model to test. @Return true,
if the modelRef is valid and its data is stored in the current master
file.

See also:
    ModelRef.IsReference ModelRef.GetDgnFile

Bentley Systems

Remark:
)doc";

static const char * __doc_MstnPlatform_ModelRefList_Get =R"doc(Remark:
    )doc";

static const char * __doc_MstnPlatform_ModelRefList_GetCount =R"doc(Remark:
    )doc";

static const char * __doc_MstnPlatform_ModelRefList_Clone =R"doc(Remark:
    )doc";

static const char * __doc_MstnPlatform_ModelRefList_CopyContents =R"doc(Remark:
    )doc";

static const char * __doc_MstnPlatform_ModelRefList_Empty =R"doc(Remark:
    )doc";

static const char * __doc_MstnPlatform_ModelRefList_Remove =R"doc(Remark:
    )doc";

static const char * __doc_MstnPlatform_ModelRefList_Insert =R"doc(Remark:
    )doc";

static const char * __doc_MstnPlatform_ModelRefList_Add =R"doc(Remark:
    )doc";

static const char * __doc_MstnPlatform_ModelRefList_Free =R"doc(Remark:
    )doc";

static const char * __doc_MstnPlatform_ModelRefList_Create =R"doc(Remark:
    )doc";

static const char * __doc_MstnPlatform_ModelRefList_IsFound =R"doc(@Description Determines whether the specified modelRef is a member of
the list. @Param[in] modelRefList the list to search. @Param[in] entry
the modelRef to find in the list. @Return true if the specified entry
is found in the list.

See also:
    ModelRefList.Find

Bentley Systems

Remark:
)doc";

static const char * __doc_MstnPlatform_ModelRefList_Find =R"doc(@Description Gets the index of the specified modelRef in the list.
@Param[in] modelRefList the list to search for the modelRef.
@Param[in] entry the model to find in the list. @Return The index of
the modelRef in the list if it is found; the value -1 if the entry
isn't found.

See also:
    ModelRefList.GetCount ModelRefList.Get
    ModelRefList.IsFound

Bentley Systems

Remark:
)doc";




BEGIN_BENTLEY_MSTNPLATFORM_MSPYTHON_NAMESPACE
struct ModelRef {};
struct ModelRefList {};
struct ActiveModel {};
END_BENTLEY_MSTNPLATFORM_MSPYTHON_NAMESPACE

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_msdgnmodelref(py::module_& m)
    {
    py::class_<Bentley::MstnPlatform::MSPython::ModelRefList> c1(m, "ModelRefList"); 

    c1.def_static("Find", &mdlModelRefList_find, "modelRefList"_a, "entry"_a, DOC(MstnPlatform, ModelRefList, Find));
    c1.def_static("IsFound", &mdlModelRefList_isFound, "modelRefList"_a, "entry"_a, DOC(MstnPlatform, ModelRefList, IsFound));
    c1.def_static("Create", [] ()
          {
          DgnModelRefListP refList = nullptr;
          auto retVal = mdlModelRefList_create(&refList);
          return py::make_tuple(retVal, py::cast(refList, py::return_value_policy::take_ownership));
          }, DOC(MstnPlatform, ModelRefList, Create));

    c1.def_static("Free", [] (DgnModelRefListP modelRefList)
          {
          DgnModelRefListP modelRefList_ {modelRefList};
          return mdlModelRefList_free(&modelRefList_);
          }, "modelRefList"_a, DOC(MstnPlatform, ModelRefList, Free));

    c1.def_static("Add", &mdlModelRefList_add, "modelRefList"_a, "entry"_a, DOC(MstnPlatform, ModelRefList, Add));
    c1.def_static("Insert", &mdlModelRefList_insert, "modelRefList"_a, "insertBefore"_a, "entry"_a, DOC(MstnPlatform, ModelRefList, Insert));
    c1.def_static("Remove", &mdlModelRefList_remove, "modelRefList"_a, "entry"_a, DOC(MstnPlatform, ModelRefList, Remove));
    c1.def_static("Empty", &mdlModelRefList_empty, "modelRefList"_a, DOC(MstnPlatform, ModelRefList, Empty));
    c1.def_static("CopyContents", &mdlModelRefList_copyContents, "modelRefList"_a, "srcModelRefList"_a, DOC(MstnPlatform, ModelRefList, CopyContents));
    c1.def_static("Clone", &mdlModelRefList_clone, "modelRefList"_a, py::return_value_policy::take_ownership, DOC(MstnPlatform, ModelRefList, Clone));
    c1.def_static("GetCount", &mdlModelRefList_getCount, "modelRefList"_a, DOC(MstnPlatform, ModelRefList, GetCount));
    c1.def_static("Get", &mdlModelRefList_get, "modelRefList"_a, "index"_a, py::return_value_policy::reference, DOC(MstnPlatform, ModelRefList, Get));

    py::class_<Bentley::MstnPlatform::MSPython::ModelRef> c2(m, "ModelRef"); 

    c2.def_static("InMasterFile", &mdlModelRef_inMasterFile, "modelRef"_a, DOC(MstnPlatform, ModelRef, InMasterFile));
    c2.def_static("IsActiveModel", &mdlModelRef_isActiveModel, "modelRef"_a, DOC(MstnPlatform, ModelRef, IsActiveModel));
    c2.def_static("IsReference", &mdlModelRef_isReference, "modelRef"_a, DOC(MstnPlatform, ModelRef, IsReference));
    c2.def_static("GetParent", &mdlModelRef_getParent, "modelRef"_a, py::return_value_policy::reference, DOC(MstnPlatform, ModelRef, GetParent));
    c2.def_static("IsNestedReference", &mdlModelRef_isNestedReference, "modelRef"_a, DOC(MstnPlatform, ModelRef, IsNestedReference));
    c2.def_static("IsReadOnly", &mdlModelRef_isReadOnly, "modelRef"_a, DOC(MstnPlatform, ModelRef, IsReadOnly));
    c2.def_static("AreSame", &mdlModelRef_areSame, "modelRef1"_a, "modelRef2"_a, DOC(MstnPlatform, ModelRef, AreSame));
    
    c2.def_static("GetFileName", [] (DgnModelRefP modelRef, WStringR fileName)
          {
          WChar szName[512] = {0};
          auto retVal = mdlModelRef_getFileName(modelRef, szName, _countof(szName));
          fileName.assign(szName);
          return retVal;
          }, "modelRef"_a, "fileName"_a, DOC(MstnPlatform, ModelRef, GetFileName));

    c2.def_static("IsDisplayedInView", &mdlModelRef_isDisplayedInView, "modelRef"_a, "viewIndex"_a, DOC(MstnPlatform, ModelRef, IsDisplayedInView));
    c2.def_static("GetViewMask", &mdlModelRef_getViewMask, "modelRef"_a, DOC(MstnPlatform, ModelRef, GetViewMask));
    c2.def_static("DeleteModel", &mdlModelRef_deleteModel, "modelRef"_a, "deleteElements"_a, DOC(MstnPlatform, ModelRef, DeleteModel));
    c2.def_static("ActivateAndDisplay", &mdlModelRef_activateAndDisplay, "newModelRef"_a, DOC(MstnPlatform, ModelRef, ActivateAndDisplay));

    c2.def_static("CreateWorking", [] (DgnFileP dgnFile, ModelId modelId, bool fillCache, bool loadRefs)
          {
          DgnModelRefP modelRef = nullptr;
          auto retVal = mdlModelRef_createWorking(&modelRef, dgnFile, modelId, fillCache, loadRefs);
          return py::make_tuple(retVal, py::cast(modelRef, py::return_value_policy::reference));
          }, "dgnFile"_a, "modelId"_a, "fillCache"_a, "loadRefs"_a, DOC(MstnPlatform, ModelRef, CreateWorking));

    c2.def_static("CreateCacheSpecificWorking", [] (DgnFileP dgnFile, ModelId modelId, bool fillCache, bool loadRefs, bool includeUndisplayedRefs, 
                                                        DgnModelSections sectionsToFill)
          {
          DgnModelRefP modelRef = nullptr;
          auto retVal = mdlModelRef_createCacheSpecificWorking(&modelRef, dgnFile, modelId, fillCache, loadRefs, includeUndisplayedRefs, sectionsToFill);
          return py::make_tuple(retVal, py::cast(modelRef, py::return_value_policy::reference));
          }, "dgnFile"_a, "modelId"_a, "fillCache"_a, "loadRefs"_a, "includeUndisplayedRefs"_a, "sectionsToFill"_a, DOC(MstnPlatform, ModelRef, CreateCacheSpecificWorking));

    c2.def_static("CreateWorkingByName", [] (DgnFileP dgnFile, WCharCP modelName, bool fillCache, bool loadRefs)
          {
          DgnModelRefP modelRef = nullptr;
          auto retVal = mdlModelRef_createWorkingByName(&modelRef, dgnFile, modelName, fillCache, loadRefs);
          return py::make_tuple(retVal, py::cast(modelRef, py::return_value_policy::reference));
          }, "dgnFile"_a, "modelName"_a, "fillCache"_a, "loadRefs"_a, DOC(MstnPlatform, ModelRef, CreateWorkingByName));

    c2.def_static("FreeWorking", &mdlModelRef_freeWorking, "modelRef"_a, DOC(MstnPlatform, ModelRef, FreeWorking));
    c2.def_static("SetDefaultBackgroundColor", &mdlModelRef_setDefaultBackgroundColor, "modelRef"_a, DOC(MstnPlatform, ModelRef, SetDefaultBackgroundColor));
    c2.def_static("GetRange", &mdlModelRef_getRange, "modelRef"_a, "outRange"_a, "viewIndex"_a, "transform"_a, "includeChildren"_a, DOC(MstnPlatform, ModelRef, GetRange));
    
    c2.def_static("GetDisplayName", [] (DgnModelRefP modelRef, WStringR displayName, WCharCP separator)
          {
          WChar szName[512] = {0};
          auto retVal = mdlModelRef_getDisplayName(modelRef, szName, _countof(szName), separator);
          displayName.assign(szName);
          return retVal;
          }, "modelRef"_a, "displayName"_a, "separator"_a, DOC(MstnPlatform, ModelRef, GetDisplayName));

    c2.def_static("CheckAllRightsIfDisplayed", &mdlModelRef_checkAllRightsIfDisplayed, "modelRef"_a, "rights"_a, "view"_a, "diaplayError"_a, DOC(MstnPlatform, ModelRef, CheckAllRightsIfDisplayed));
    c2.def_static("CheckAllRights", &mdlModelRef_checkAllRights, "modelRef"_a, "rights"_a, "diaplayError"_a, DOC(MstnPlatform, ModelRef, CheckAllRights));
    c2.def_static("CheckAllRightsIncludingProtectedRefs", &mdlModelRef_checkAllRightsIncludingProtectedRefs, "modelRef"_a, "rights"_a, "diaplayError"_a, DOC(MstnPlatform, ModelRef, CheckAllRightsIncludingProtectedRefs));
    
    c2.def_static("CopyModel", [] (DgnModelRefP sourceModelRef, DgnFileP destFile, WCharCP destModelName, WCharCP destModelDescr)
          {
          DgnModelRefP destModelRef = nullptr;
          auto retVal = mdlModelRef_copyModel(&destModelRef, sourceModelRef, destFile, destModelName, destModelDescr);
          return py::make_tuple(retVal, py::cast(destModelRef, py::return_value_policy::reference));
          }, "sourceModelRef"_a, "destFile"_a, "destModelName"_a, "destModelDescr"_a, DOC(MstnPlatform, ModelRef, CopyModel));

    c2.def_static("GetDgnModel", &mdlModelRef_getDgnModel, "modelRef"_a, py::return_value_policy::reference, DOC(MstnPlatform, ModelRef, GetDgnModel));
    c2.def_static("GetDgnFile", &mdlModelRef_getDgnFile, "modelRef"_a, py::return_value_policy::reference, DOC(MstnPlatform, ModelRef, GetDgnFile));

    c2.def_static("GetUorScaleBetweenModels", [] (DgnModelRefCP srcModelRef, DgnModelRefCP dstModelRef)
          {
          double uorFactor = 0.0;
          auto retVal = mdlModelRef_getUorScaleBetweenModels(&uorFactor, srcModelRef, dstModelRef);
          return py::make_tuple(retVal, uorFactor);
          }, "srcModelRef"_a, "dstModelRef"_a, DOC(MstnPlatform, ModelRef, GetUorScaleBetweenModels));

    c2.def_static("LoadReferenceModels", &mdlModelRef_loadReferenceModels, "modelRef"_a, "loadCache"_a, "loadRasterRefs"_a, "loadUndisplayedRefs"_a, DOC(MstnPlatform, ModelRef, LoadReferenceModels));
    c2.def_static("GetEof", &mdlModelRef_getEof, "modelRef"_a, DOC(MstnPlatform, ModelRef, GetEof));
    c2.def_static("GetAttachmentID", &mdlModelRef_getAttachmentID, "modelRef"_a, DOC(MstnPlatform, ModelRef, GetAttachmentID));
    c2.def_static("IsEmpty", &mdlModelRef_isEmpty, "modelRef"_a, DOC(MstnPlatform, ModelRef, IsEmpty));
    c2.def_static("GetChildCount", &mdlModelRef_getChildCount, "modelRef"_a, "childTypeMask"_a, DOC(MstnPlatform, ModelRef, GetChildCount));
    c2.def_static("GetElementRef", &mdlModelRef_getElementRef, "modelRef"_a, "filePos"_a, py::return_value_policy::reference, DOC(MstnPlatform, ModelRef, GetElementRef));
    c2.def_static("Is3D", &mdlModelRef_is3D, "modelRef"_a, DOC(MstnPlatform, ModelRef, Is3D));
    c2.def_static("IsTransient", &mdlModelRef_isTransient, "modelRef"_a, DOC(MstnPlatform, ModelRef, IsTransient));
    c2.def_static("IsSheet", &mdlModelRef_isSheet, "modelRef"_a, DOC(MstnPlatform, ModelRef, IsSheet));
    c2.def_static("GetModelType", &mdlModelRef_getModelType, "modelRef"_a, DOC(MstnPlatform, ModelRef, GetModelType));
    c2.def_static("IsDefault", &mdlModelRef_isDefault, "modelRef"_a, DOC(MstnPlatform, ModelRef, IsDefault));
    c2.def_static("GetTransient", &mdlModelRef_getTransient, py::return_value_policy::reference, DOC(MstnPlatform, ModelRef, GetTransient));
    c2.def_static("GetUorPerMaster", &mdlModelRef_getUorPerMaster, "modelRef"_a);

    py::class_<Bentley::MstnPlatform::MSPython::ActiveModel> c3(m, "ActiveModel"); 

    c3.def_static("Is3d", &mdlActiveModel_is3d);
    c3.def_static("IsReadonly", &mdlActiveModel_isReadonly);
    }