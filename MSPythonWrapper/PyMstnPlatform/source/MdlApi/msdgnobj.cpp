/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MdlApi\msdgnobj.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/MdlApi/msdgnobj.fdf>



static const char * __doc_MstnPlatform_MstnDgnFile_GetModelItemByName =R"doc(Retrieve the model index item using a model name.

:param pDgnFile:
    The file containing the model.

:param modelName:
    The name of the model to retreive.

:returns:
    NULL if the indicated model does not exist in the file, otherwise
    a pointer to the model index item. @Group " DgnFile Functions "
    @See ModelItem.GetData ModelItem.GetName
    ModelItem.GetDescription

Remark:
    )doc";

static const char * __doc_MstnPlatform_MstnDgnFile_GetModelItemById =R"doc(Retrieve the model index item using a model ID.

:param pDgnFile:
    The file containing the model.

:param modelID:
    The ID of the model to retreive.

:returns:
    NULL if the indicated model does not exist in the file, otherwise
    a pointer to the model index item. @Group " DgnFile Functions "
    @See ModelItem.GetData ModelItem.GetName
    ModelItem.GetDescription

Remark:
    )doc";

static const char * __doc_MstnPlatform_MstnDgnFile_GetModelCount =R"doc(Remark:
    )doc";

static const char * __doc_MstnPlatform_MstnDgnFile_GetModelRefList =R"doc(Create a DgnModelRefList containing an entry for each of the loaded
models in the specified design file. Note, any DgnModelRefList created
with this function must be freed by calling <a
href=" usmthModelRefList.Free htm ">ModelRefList.Free</a>.

:param DgnFile:
    Is a reference to the design file containing the models to add to
    the list. @Remarks The returned model ref must be freed by the
    caller.

:returns:
    A pointer to the DgnModelRefList that has an entry for each model
    in the design file. @Group " DgnFile Functions "

Remark:
    )doc";

static const char * __doc_MstnPlatform_MstnDgnFile_IsProtected =R"doc(@Description Check if the specified file is encrypted (e.g., for
digital rights management)

:param file:
    the DgnFile of interest. @Return true if file is encrypted

Remark:
    

)doc";

static const char * __doc_MstnPlatform_MstnDgnFile_CheckRights =R"doc(@Description Check if the specified rights are granted to the current
user for the specified file.

Remark:
    s The rights parameter can be one or more of the following values
    OR'd together:

* DgnPlatform::DGNFILE_RIGHT_Print -- Print, print preview, e-plot,
etc.

* DgnPlatform::DGNFILE_RIGHT_Export -- SaveAs, Export, Copy to
clipboard, File Fence, etc.

* DgnPlatform::DGNFILE_RIGHT_Edit -- Modify file contents (implies not
read-only)

* DgnPlatform::DGNFILE_RIGHT_Unlimited -- All rights, present and
future

:param DgnFile:
    the DgnFile of interest. @Param(input) rights the rights to query
    @Param(input) displayError display error message in message center if
    rights not granted? Else return ERROR silently @Return SUCCESS if
    all of the rights are granted.

Remark:
    

)doc";

static const char * __doc_MstnPlatform_MstnDgnFile_HasPendingChanges =R"doc(@Description Determines if a design file has pending chages.
@Param(input) DgnFile is a reference to the design file of interest
@Return true if the design file has changes that have not been saved;
false otherwise.

Remark:
    

)doc";

static const char * __doc_MstnPlatform_MstnDgnFile_GetMasterFile =R"doc(@Description Get the DgnFile for the current master file. @Return
The DgnFileP for the current master file.

Remark:
)doc";




BEGIN_BENTLEY_MSTNPLATFORM_MSPYTHON_NAMESPACE
struct MstnDgnFile {};
END_BENTLEY_MSTNPLATFORM_MSPYTHON_NAMESPACE

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_msdgnobj(py::module_& m)
    {

    py::class_<Bentley::MstnPlatform::MSPython::MstnDgnFile> c1(m, "MstnDgnFile");

    c1.def_static("GetMasterFile", &mdlDgnFileObj_getMasterFile, py::return_value_policy::reference, DOC(MstnPlatform, MstnDgnFile, GetMasterFile));
    c1.def_static("HasPendingChanges", &mdlDgnFileObj_hasPendingChanges, "DgnFile"_a, DOC(MstnPlatform, MstnDgnFile, HasPendingChanges));

    c1.def_static("CreateModel", [] (DgnFileP dgnFileObj, DgnModelRefP seedModelRef, WCharCP modelName, WCharCP modelDescr, bool FromSeedForModelAndIs3d, DgnModelType modelType, bool Is3d)
          {
          DgnModelRefP        newModel = nullptr;
          bool                *is3d = FromSeedForModelAndIs3d ? nullptr : &Is3d;
          DgnModelType        *pModelType = FromSeedForModelAndIs3d ? nullptr : &modelType;
          auto retVal = mdlDgnFileObj_createModel(&newModel, dgnFileObj, seedModelRef, modelName, modelDescr, pModelType, is3d);
          return py::make_tuple(retVal, py::cast(newModel, py::return_value_policy::reference));
          }, "dgnFileObj"_a, "seedModelRef"_a, "modelName"_a, "modelDescr"_a, "FromSeedForModelAndIs3d"_a, "modelType"_a, "Is3d"_a);

    c1.def_static("FindModelIDByName", [] (DgnFileP dgnFileObj, WCharCP name)
          {
          ModelId modelId = -1;
          auto retVal = mdlDgnFileObj_findModelIDByName(dgnFileObj, &modelId, name);
          return py::make_tuple(retVal, modelId);
          }, "dgnFileObj"_a, "name"_a);

    c1.def_static("FindElemByID", &dgnFileObj_findElemByID, "dgnFile"_a, "elemId"_a, "dictionaryOnly"_a, py::return_value_policy::reference);

    py::enum_< MessageDestination>(m, "MessageDestination", py::arithmetic())
        .value("eMESSAGE_DEST_None", MESSAGE_DEST_None)
        .value("eMESSAGE_DEST_MessageCenter", MESSAGE_DEST_MessageCenter)
        .value("eMESSAGE_DEST_WarningDialog", MESSAGE_DEST_WarningDialog)
        .export_values();

    c1.def_static("CheckRights", &mdlDgnFileObj_checkRights, "dgnFileObj"_a, "rights"_a, "displayError"_a, DOC(MstnPlatform, MstnDgnFile, CheckRights));
    c1.def_static("IsProtected", &mdlDgnFileObj_isProtected, "dgnFileObj"_a, DOC(MstnPlatform, MstnDgnFile, IsProtected));
    c1.def_static("GetModelRefList", &mdlDgnFileObj_getModelRefList, "dgnFileObj"_a, py::return_value_policy::reference, DOC(MstnPlatform, MstnDgnFile, GetModelRefList));
    c1.def_static("GetModelCount", &mdlDgnFileObj_getModelCount, "dgnFileObj"_a, DOC(MstnPlatform, MstnDgnFile, GetModelCount));
    c1.def_static("GetModelItemById", &mdlDgnFileObj_getModelItemById, "dgnFileObj"_a, "modelId"_a, py::return_value_policy::reference, DOC(MstnPlatform, MstnDgnFile, GetModelItemById));
    c1.def_static("GetModelItemByName", &mdlDgnFileObj_getModelItemByName, "dgnFileObj"_a, "modelName"_a, py::return_value_policy::reference, DOC(MstnPlatform, MstnDgnFile, GetModelItemByName));

    c1.def_static("GetVersion", [] (DgnFileP dgnFileObj)
          {
          DgnFileFormatType  format;
          int majorVersion = 0;
          int minorVersion = 0;
          auto retVal = mdlDgnFileObj_getVersion(&format, &majorVersion, &minorVersion, dgnFileObj);
          return py::make_tuple(retVal, format, majorVersion, minorVersion);
          }, "dgnFilebj"_a);

    }