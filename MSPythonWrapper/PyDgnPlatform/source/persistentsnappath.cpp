/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\persistentsnappath.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/PersistentSnapPath.h>



static const char * __doc_Bentley_DgnPlatform_PersistentSnapPath_GetDescription =R"doc(Get description for debugging purposes)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentSnapPath_DisclosePointers =R"doc(Report all ElementRefs on the path (including reference attachment
elements)

Parameter ``refs``:
    where to store target ElementRefs

Parameter ``homeModel``:
    the model that contains the dependent element)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentSnapPath_OnPreprocessCopyRemapIds =R"doc(Phase II of copying a persistent display path:remap the display's IDs
to copied target elements

Parameter ``unused``:
    for future use. Always pass false.

Parameter ``hostElement``:
    The host element

Returns:
    non-zero error status if the remapping failed and the displaypath
    should be dropped

See also:
    OnPreprocessCopy)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentSnapPath_OnPreprocessCopy =R"doc(Phase I of copying a persistent display path:deep-copy target
elements and/or replace stored IDs with remap keys

Parameter ``opt``:
    How to handle the references contained in the display path

Parameter ``cc``:
    The copy context

Parameter ``hostElement``:
    The element that contains the XAttribute

Returns:
    non-zero error status if the display path cannot be copied and
    should be dropped

Remark:
    s After this function returns, this persistent display path should
    be stored until OnPreprocessCopyRemapIds is called.

See also:
    OnPreprocessCopyRemapIds)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentSnapPath_SetDoDeepCopy =R"doc(Store a note that captures root deep-copying preference.

Remark:
    s OnPreprocessCopy does *not* check this flag. Instead, the owner
    of the PSP must check it and decide what to do with it.)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentSnapPath_SetPayloadData =R"doc(Add, replace, or delete payload data)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentSnapPath_GetPayloadData =R"doc(Get the payload data

Parameter ``bytes``:
    payload data

Parameter ``nbytes``:
    number of bytes of payload data

Remark:
    s The caller must *not* free the returned pointer.

Remark:
    s The caller must *not* modify the custom data using the returned
    pointer.

Remark:
    s You can add payload data to any kind of snap, including custom
    data.)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentSnapPath_IsStaticDPoint3d =R"doc(Query if this PSP contains only static (x,y,z) data. To get the point,
call EvaluatePoint)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentSnapPath_SetCustomKeypointData =R"doc(Set or update the custom keyoint data associated with this snap

Parameter ``data``:
    custom data

Parameter ``nbytes``:
    number of bytes of custom data

Remark:
    s The function converts the snap to a " custom " snap. See
    SetPayloadData to add additional data to a snap.)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentSnapPath_GetCustomKeypointData =R"doc(Get the custom keypoint data associated with this snap

Returns:
    ERROR if there is no custom data

Parameter ``data``:
    pointer to saved custom data

Parameter ``nbytes``:
    number of bytes of custom data

Remark:
    s The caller must *not* free the returned pointer.

Remark:
    s The caller must *not* modify the custom data using the returned
    pointer.)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentSnapPath_GetPaths =R"doc(Get the target element(s) identified by the snap Optionaly, get the
assoc point data)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentSnapPath_DependsOnElementRef =R"doc(Does the moniker depend on this ElementRefP? If host and target are in
same model and if target is not a shared cell instance, then this is
the same as EvaluateElementRef() == target. For non-simple paths, then
this will recognize the moniker's dependence on the reference
attachment element, parts of the shared cell instance path, etc.)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentSnapPath_EvaluateReferenceAttachment =R"doc(Get the reference attachment used to access the (first) target
element.

See also:
    GetPaths to retrieve both targets of an intersection snap

Remark:
    s *Note:* See PersistentElementPath::EvaluateElement for the
    lifetime of the modelref contained in the returned handle.)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentSnapPath_EvaluateElement =R"doc(Get target element.

See also:
    GetPaths to retrieve both targets of an intersection snap

Remark:
    s *Note:* See PersistentElementPath::EvaluateElement for the
    lifetime of the modelref contained in the returned handle.)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentSnapPath_IsTargetAvailable =R"doc(Query if all targets can be found)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentSnapPath_HasTwoPaths =R"doc(Query if snap has two targets)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentSnapPath_EvaluateAssocPoint =R"doc(Compute the location identified by an AssocPoint

Parameter ``pt``:
    the computed snap location

Parameter ``assoc``:
    the snap definition to evaluate

Parameter ``homeModel``:
    the model that contains the dependent element

Remark:
    s Calls the DisplayHandler::EvaluateSnap method.)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentSnapPath_EvaluatePoint =R"doc(Compute the point identified by the snap

Remark:
    s May call the DisplayHandler::EvaluateSnap method. pt[out] the
    point (transformed into the coordinate system of the home model
    aka " world cooordinates "))doc";

static const char * __doc_Bentley_DgnPlatform_PersistentSnapPath_FromPersistentElementPath =R"doc(Capture a PersistentElementPath with no particular point association

Remark:
    s This method makes a copy of the supplied PersistentElementPath.
    It does not save a reference to the actual object.)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentSnapPath_FromAssocPoint =R"doc(Capture an AssocPoint)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentSnapPath_SetHomeModelRef =R"doc(Set the home model ref)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentSnapPath_Clear =R"doc(Forget state)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentSnapPath_IsValid =R"doc(Query if Constructor worked)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_PersistentSnapPath(py::module_& m)
    {
    //===================================================================================
    // struct PersistentSnapPath
    py::class_< PersistentSnapPath> c1(m, "PersistentSnapPath");

    c1.def(py::init<DgnModelRefP>(), "homeModel"_a);    
    c1.def(py::init<DgnModelRefP, PersistentElementPathCR>(), "homeModel"_a, "pep"_a);
    c1.def(py::init<DPoint3dCR>(), "point"_a);
    c1.def(py::init<DgnModelRefP, AssocPointCR>(), "homeModel"_a, "assocPoint"_a);

    c1.def("IsValid", &PersistentSnapPath::IsValid, DOC(Bentley, DgnPlatform, PersistentSnapPath, IsValid));
    c1.def("Clear", &PersistentSnapPath::Clear, DOC(Bentley, DgnPlatform, PersistentSnapPath, Clear));
    c1.def_property("HomeModelRef", &PersistentSnapPath::GetHomeModelRefP, &PersistentSnapPath::SetHomeModelRef);
    c1.def("GetHomeModelRef", &PersistentSnapPath::GetHomeModelRefP, py::return_value_policy::reference_internal);
    c1.def("SetHomeModelRef", &PersistentSnapPath::SetHomeModelRef, "modelRef"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, PersistentSnapPath, SetHomeModelRef));

    c1.def("FromAssocPoint", &PersistentSnapPath::FromAssocPoint, "assocPoint"_a, DOC(Bentley, DgnPlatform, PersistentSnapPath, FromAssocPoint));
    
    c1.def("FromPersistentElementPath",
           py::overload_cast<PersistentElementPathCR>(&PersistentSnapPath::FromPersistentElementPath),
           "pep"_a, DOC(Bentley, DgnPlatform, PersistentSnapPath, FromPersistentElementPath));

    c1.def("FromPersistentElementPath", 
           py::overload_cast<DgnModelRefP, PersistentElementPathCR>(&PersistentSnapPath::FromPersistentElementPath),
           "homeModel"_a, "pep"_a, DOC(Bentley, DgnPlatform, PersistentSnapPath, FromPersistentElementPath));

    c1.def("EvaluatePoint", &PersistentSnapPath::EvaluatePoint, "pt"_a, DOC(Bentley, DgnPlatform, PersistentSnapPath, EvaluatePoint));
    c1.def_static("EvaluateAssocPoint", &PersistentSnapPath::EvaluateAssocPoint, "pt"_a, "assoc"_a, "homeModel"_a, DOC(Bentley, DgnPlatform, PersistentSnapPath, EvaluateAssocPoint));
    c1.def("HasTwoPaths", &PersistentSnapPath::HasTwoPaths, DOC(Bentley, DgnPlatform, PersistentSnapPath, HasTwoPaths));
    c1.def("IsTargetAvailable", &PersistentSnapPath::IsTargetAvailable, DOC(Bentley, DgnPlatform, PersistentSnapPath, IsTargetAvailable));
    c1.def("EvaluateElement", &PersistentSnapPath::EvaluateElement, "wantFirst"_a = true, DOC(Bentley, DgnPlatform, PersistentSnapPath, EvaluateElement));
    c1.def("EvaluateReferenceAttachment", &PersistentSnapPath::EvaluateReferenceAttachment, "wantFirst"_a = true, DOC(Bentley, DgnPlatform, PersistentSnapPath, EvaluateReferenceAttachment));
    c1.def("DependsOnElementRef", &PersistentSnapPath::DependsOnElementRef, "target"_a, DOC(Bentley, DgnPlatform, PersistentSnapPath, DependsOnElementRef));
    
    c1.def("GetPaths", [] (PersistentSnapPathCR self, AssocPoint* assoc)
           {
           DisplayPathPtr path1, path2;
           auto retVal = self.GetPaths(path1, path2, assoc);
           return py::make_tuple(retVal, path1, path2);
           }, "assoc"_a = nullptr, DOC(Bentley, DgnPlatform, PersistentSnapPath, GetPaths));

    c1.def("GetCustomKeypointData", [] (PersistentSnapPathCR self, py::bytearray& kpData)
           {
           byte const* data = nullptr;
           UInt32 dataSize = 0;
           auto retVal = self.GetCustomKeypointData(data, dataSize);
           if (retVal == SUCCESS && nullptr != data && dataSize > 0)
               kpData = py::bytearray((const char*) data, dataSize);
           return retVal;
           }, "kpData"_a, DOC(Bentley, DgnPlatform, PersistentSnapPath, GetCustomKeypointData));

    c1.def("SetCustomKeypointData", [] (PersistentSnapPathR self, py::bytes const& kpData)
           {
           std::string strData = kpData.cast<std::string>();
           if (!strData.empty())
               self.SetCustomKeypointData((const byte*) strData.data(), (UInt32) strData.size());
           }, "kpData"_a, DOC(Bentley, DgnPlatform, PersistentSnapPath, SetCustomKeypointData));

    c1.def("IsStaticDPoint3d", &PersistentSnapPath::IsStaticDPoint3d, DOC(Bentley, DgnPlatform, PersistentSnapPath, IsStaticDPoint3d));

    c1.def("GetPayloadData", [] (PersistentSnapPathCR self, py::bytearray& plData)
           {
           byte const* data = nullptr;
           UInt32 dataSize = 0;
           auto retVal = self.GetPayloadData((void const*&)data, dataSize);
           if (retVal == SUCCESS && nullptr != data && dataSize > 0)
               plData = py::bytearray((const char*) data, dataSize);
           return retVal;
           }, "plData"_a, DOC(Bentley, DgnPlatform, PersistentSnapPath, GetPayloadData));

    c1.def("SetPayloadData", [] (PersistentSnapPathR self, py::bytes const& plData)
           {
           std::string strData = plData.cast<std::string>();
           if (!strData.empty())
               self.SetPayloadData((const byte*) strData.data(), (UInt32) strData.size());
           }, "plData"_a, DOC(Bentley, DgnPlatform, PersistentSnapPath, SetPayloadData));

    c1.def_property("DoDeepCopy", &PersistentSnapPath::GetDoDeepCopy, &PersistentSnapPath::SetDoDeepCopy);
    c1.def("GetDoDeepCopy", &PersistentSnapPath::GetDoDeepCopy);
    c1.def("SetDoDeepCopy", &PersistentSnapPath::SetDoDeepCopy, "doDeepCopy"_a, DOC(Bentley, DgnPlatform, PersistentSnapPath, SetDoDeepCopy));

    c1.def("OnPreprocessCopy", &PersistentSnapPath::OnPreprocessCopy, "hostElement"_a, "copyContext"_a, "opt"_a, DOC(Bentley, DgnPlatform, PersistentSnapPath, OnPreprocessCopy));
    c1.def("OnPreprocessCopyRemapIds", &PersistentSnapPath::OnPreprocessCopyRemapIds, "hostElement"_a, "unused"_a = false, DOC(Bentley, DgnPlatform, PersistentSnapPath, OnPreprocessCopyRemapIds));
    c1.def("DisclosePointers", &PersistentSnapPath::DisclosePointers, "refs"_a, "homeModel"_a, DOC(Bentley, DgnPlatform, PersistentSnapPath, DisclosePointers));
    c1.def_property_readonly("Description", &PersistentSnapPath::GetDescription);
    c1.def("GetDescription", &PersistentSnapPath::GetDescription, DOC(Bentley, DgnPlatform, PersistentSnapPath, GetDescription));
    }