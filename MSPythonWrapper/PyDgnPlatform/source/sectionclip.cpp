/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\sectionclip.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/SectionClip.h>



static const char * __doc_Bentley_DgnPlatform_SectionClipElementHandler_CreateClipObject =R"doc(Creates the clip object from the clip element and

:returns:
    a reference counted pointer to the object created.)doc";

static const char * __doc_Bentley_DgnPlatform_IHasViewClipObject_GetClipObject =R"doc(Gets the pointer to the clip object IViewClipObject using the clip
element.

:param clipElement:
    the clip data of the clip element.

:returns:
    the pointer to the clip object IViewClipObject.)doc";

static const char * __doc_Bentley_DgnPlatform_IViewClipObject_SetPointCloudProjectPoints =R"doc(Sets project points flag to indicate that the PointCloud will project
the points. param(input) flag pass 1 for project and zero for unproject.)doc";

static const char * __doc_Bentley_DgnPlatform_IViewClipObject_GetPointCloudProjectPoints =R"doc(Gets project points flag to indicate that the PointCloud will project
the points.

:returns:
    the project points flag.)doc";

static const char * __doc_Bentley_DgnPlatform_IViewClipObject_SetPointCloudTolerance =R"doc(Set the tolerance use by Point Cloud to a user defined value
newTolerance.

:param newTolerance:
    the value to be assigned to the tolerance use by Point Cloud)doc";

static const char * __doc_Bentley_DgnPlatform_IViewClipObject_GetPointCloudTolerance =R"doc(Gets tolerance use by Point Cloud.

:returns:
    the tolerance for PointCloud.)doc";

static const char * __doc_Bentley_DgnPlatform_IViewClipObject_SetWidth =R"doc(Set the width of the clip element to a user defined value newWidth.

:param newWidth:
    the value to be assigned to the width of the clip element.

:returns:
    width of the clip element to a user defined value newWidth.)doc";

static const char * __doc_Bentley_DgnPlatform_IViewClipObject_GetWidth =R"doc(Gets width of the clip element.

:returns:
    the width of the clip element.)doc";

static const char * __doc_Bentley_DgnPlatform_IViewClipObject_SetPreserveUp =R"doc(@verbatim IHasViewClipObject* hasViewClipObject = dynamic_cast
<IHasViewClipObject*> (&clipEEH.GetHandler ()) ; IViewClipObjectPtr
clipObjPtr = hasViewClipObject->GetClipObject (clipEEH) ;
clipObjPtr->SetPreserveUp (true) ; @endverbatim)doc";

static const char * __doc_Bentley_DgnPlatform_IViewClipObject_GetPreserveUp =R"doc(@verbatim IHasViewClipObject* hasViewClipObject = dynamic_cast
<IHasViewClipObject*> (&clipEEH.GetHandler ()) ; IViewClipObjectPtr
clipObjPtr = hasViewClipObject->GetClipObject (clipEEH) ; bool getFlag
= clipObjPtr->GetPreserveUp () ; @endverbatim)doc";

static const char * __doc_Bentley_DgnPlatform_IViewClipObject_ToElement =R"doc(Creates and modifies an element from the clip data.

:param eeh:
    to edit the clip data of the clip element.

:param templateEH:
    const pointer to a clip element previously created and points to
    null if the element is getting created for the first time.

:param modelRef:
    instance of DgnModelRef,that provides access to a model in
    Bentley::DgnPlatform::DgnFile.

:returns:
    the new created or modified element from the clip data.)doc";

static const char * __doc_Bentley_DgnPlatform_IViewClipObject_CopyCrops =R"doc(@verbatim EditElementHandle sourceClipEEH; EditElementHandle
destinationClipEEH; IHasViewClipObject* hasViewClipObject =
dynamic_cast <IHasViewClipObject*> (&sourceClipEEH.GetHandler ());
IViewClipObjectPtr sourceClipObjPtr = hasViewClipObject->GetClipObject
(sourceClipEEH) ; hasViewClipObject = dynamic_cast
<IHasViewClipObject*> (&destinationClipEEH.GetHandler ());
IViewClipObjectPtr destinationClipObjPtr =
hasViewClipObject->GetClipObject (destinationClipEEH) ;
destinationClipObjPtr->CopyCrops (sourceClipObjPtr.get()) ;
@endverbatim)doc";

static const char * __doc_Bentley_DgnPlatform_IViewClipObject_FromElement =R"doc(**Reads the clip data from a clip element**

:param elem:
    retrieves the clip data from clip element to control the element
    actions.

:returns:
    the clip data from a clip element.)doc";

static const char * __doc_Bentley_DgnPlatform_IViewClipObject_GetPoints =R"doc(Obtains the data points of the clipped volume.

:param points:
    reference to the vector containing the 3D points.

:param iFromPoint:
    initial index point of the clip volume.

:param numPoints:
    number of index points of the clip volume.

:returns:
    the data points of the clipped volume.

See also:
    SetPoints.)doc";

static const char * __doc_Bentley_DgnPlatform_IViewClipObject_SetPoints =R"doc(@verbatim IHasViewClipObject* hasViewClipObject = dynamic_cast
<IHasViewClipObject*> (&clipEEH.GetHandler ()) ; IViewClipObjectPtr
clipObjPtr = hasViewClipObject->GetClipObject (clipEEH) ; size_t
numPoints = clipObjPtr->GetNumPoints () ; DPoint3dVector clipPoints;
clipObjPtr->GetPoints (clipPoints, 0, numPoints) ;
clipObjPtr->SetPoints (numPoints,clipPoints.data()) ; @endverbatim)doc";

static const char * __doc_Bentley_DgnPlatform_IViewClipObject_SetRotationMatrix =R"doc(Sets the rotation matrix of the element to a defined matrix and set
the orientation in the 3D space.

:returns:
    the orientation details in the 3D space of the element to be
    clipped, in the form of the defined matrix.

See also:
    GetRotationMatrix .)doc";

static const char * __doc_Bentley_DgnPlatform_IViewClipObject_GetRotationMatrix =R"doc(@verbatim IHasViewClipObject* hasViewClipObject = dynamic_cast
<IHasViewClipObject*> (&clipEEH.GetHandler ()) ; IViewClipObjectPtr
clipObjPtr = hasViewClipObject->GetClipObject (clipEEH) ; RotMatrix
rMatrix; rMatrix = clipObjPtr->GetRotationMatrix ();
clipObjPtr->SetRotationMatrix (rMatrix); @endverbatim)doc";

static const char * __doc_Bentley_DgnPlatform_IViewClipObject_SetCrop =R"doc(@verbatim IHasViewClipObject* hasViewClipObject = dynamic_cast
<IHasViewClipObject*> (&clipEEH.GetHandler ()) ; IViewClipObjectPtr
clipObjPtr = hasViewClipObject->GetClipObject (clipEEH) ;
clipObjPtr->SetCrop (CLIPVOLUME_CROP_Front, true) ; @endverbatim)doc";

static const char * __doc_Bentley_DgnPlatform_IViewClipObject_GetCrop =R"doc(@verbatim IHasViewClipObject* hasViewClipObject = dynamic_cast
<IHasViewClipObject*> (&clipEEH.GetHandler ()) ; IViewClipObjectPtr
clipObjPtr = hasViewClipObject->GetClipObject (clipEEH) ; bool
cropFlag = clipObjPtr->GetCrop (CLIPVOLUME_CROP_Front) ; @endverbatim)doc";

static const char * __doc_Bentley_DgnPlatform_IViewClipObject_SetSize =R"doc(@verbatim IHasViewClipObject* hasViewClipObject = dynamic_cast
<IHasViewClipObject*> (&clipEEH.GetHandler ()) ; IViewClipObjectPtr
clipObjPtr = hasViewClipObject->GetClipObject (clipEEH) ;
clipObjPtr->SetSize (CLIPVOLUME_SIZE_FrontDepth, true) ; @endverbatim)doc";

static const char * __doc_Bentley_DgnPlatform_IViewClipObject_GetSize =R"doc(@verbatim IHasViewClipObject* hasViewClipObject = dynamic_cast
<IHasViewClipObject*> (&clipEEH.GetHandler ()); IViewClipObjectPtr
clipObjPtr = hasViewClipObject->GetClipObject (clipEEH) ; double
frontSize = clipObjPtr->GetSize (CLIPVOLUME_SIZE_FrontDepth) ;
@endverbatim)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_SectionClip(py::module_& m)
    {
    //===================================================================================
    // enum class ClipVolumeSizeProp
    py::enum_< ClipVolumeSizeProp>(m, "ClipVolumeSizeProp")
        .value("eInvalid", ClipVolumeSizeProp::Invalid)
        .value("eTopHeight", ClipVolumeSizeProp::TopHeight)
        .value("eBottomHeight", ClipVolumeSizeProp::BottomHeight)
        .value("eFrontDepth", ClipVolumeSizeProp::FrontDepth)
        .value("eBackDepth", ClipVolumeSizeProp::BackDepth)
        .export_values();

    //===================================================================================
    // enum class ClipVolumeCropProp
    py::enum_< ClipVolumeCropProp>(m, "ClipVolumeCropProp")
        .value("eInvalid", ClipVolumeCropProp::Invalid)
        .value("eStartSide", ClipVolumeCropProp::StartSide)
        .value("eEndSide", ClipVolumeCropProp::EndSide)
        .value("eFront", ClipVolumeCropProp::Front)
        .value("eBack", ClipVolumeCropProp::Back)
        .value("eBottom", ClipVolumeCropProp::Bottom)
        .value("eTop", ClipVolumeCropProp::Top)
        .export_values();

    //===================================================================================
    // struct IViewClipObject
    py::class_< IViewClipObject, IViewClipObjectPtr> c1(m, "IViewClipObject");

    c1.def("GetSize", &IViewClipObject::GetSize, "clipVolumeSizeProp"_a, DOC(Bentley, DgnPlatform, IViewClipObject, GetSize));
    c1.def("SetSize", &IViewClipObject::SetSize, "clipVolumeSizeProp"_a, "size"_a, DOC(Bentley, DgnPlatform, IViewClipObject, SetSize));
    c1.def("GetCrop", &IViewClipObject::GetCrop, "clipVolumeCropProp"_a, DOC(Bentley, DgnPlatform, IViewClipObject, GetCrop));
    c1.def("SetCrop", &IViewClipObject::SetCrop, "clipVolumeCropProp"_a, "crop"_a, DOC(Bentley, DgnPlatform, IViewClipObject, SetCrop));

    c1.def_property("RotationMatrix", &IViewClipObject::GetRotationMatrix, &IViewClipObject::SetRotationMatrix);
    c1.def("GetRotationMatrix", &IViewClipObject::GetRotationMatrix, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, IViewClipObject, GetRotationMatrix));
    c1.def("SetRotationMatrix", &IViewClipObject::SetRotationMatrix, "rMatrix"_a, DOC(Bentley, DgnPlatform, IViewClipObject, SetRotationMatrix));
    
    c1.def("SetPoints", [] (IViewClipObject& self, DPoint3dArray const& points)
           {
           self.SetPoints(points.size(), points.data());
           }, "points"_a, DOC(Bentley, DgnPlatform, IViewClipObject, SetPoints));

    c1.def("SetPoints", [] (IViewClipObject& self, py::list const& points)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(points, cppPoints, DPoint3dArray, DPoint3d);
           self.SetPoints(cppPoints.size(), cppPoints.data());
           }, "points"_a, DOC(Bentley, DgnPlatform, IViewClipObject, SetPoints));
    
    c1.def("NumPoints", &IViewClipObject::GetNumPoints);
    c1.def("GetPoints", &IViewClipObject::GetPoints, "points"_a, "iFromPoint"_a, "numPoints"_a, DOC(Bentley, DgnPlatform, IViewClipObject, GetPoints));
    c1.def("FromElement", &IViewClipObject::FromElement, "elem"_a, DOC(Bentley, DgnPlatform, IViewClipObject, FromElement));
    c1.def("CopyCrops", &IViewClipObject::CopyCrops, "from"_a, DOC(Bentley, DgnPlatform, IViewClipObject, CopyCrops));
    c1.def("ToElement", &IViewClipObject::ToElement, "eeh"_a, "templateEH"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, IViewClipObject, ToElement));
    
    c1.def_property("PreserveUp", &IViewClipObject::GetPreserveUp, &IViewClipObject::SetPreserveUp);
    c1.def("GetPreserveUp", &IViewClipObject::GetPreserveUp, DOC(Bentley, DgnPlatform, IViewClipObject, GetPreserveUp));
    c1.def("SetPreserveUp", &IViewClipObject::SetPreserveUp, "flag"_a, DOC(Bentley, DgnPlatform, IViewClipObject, SetPreserveUp));
    
    c1.def_property("Width", &IViewClipObject::GetWidth, &IViewClipObject::SetWidth);
    c1.def("GetWidth", &IViewClipObject::GetWidth, DOC(Bentley, DgnPlatform, IViewClipObject, GetWidth));
    c1.def("SetWidth", &IViewClipObject::SetWidth, "width"_a, DOC(Bentley, DgnPlatform, IViewClipObject, SetWidth));
    
    c1.def_property("PointCloudTolerance", &IViewClipObject::GetPointCloudTolerance, &IViewClipObject::SetPointCloudTolerance);
    c1.def("GetPointCloudTolerance", &IViewClipObject::GetPointCloudTolerance, DOC(Bentley, DgnPlatform, IViewClipObject, GetPointCloudTolerance));
    c1.def("SetPointCloudTolerance", &IViewClipObject::SetPointCloudTolerance, "tolerance"_a, DOC(Bentley, DgnPlatform, IViewClipObject, SetPointCloudTolerance));
    
    c1.def_property("PointCloudProjectPoints", &IViewClipObject::GetPointCloudProjectPoints, &IViewClipObject::SetPointCloudProjectPoints);
    c1.def("GetPointCloudProjectPoints", &IViewClipObject::GetPointCloudProjectPoints, DOC(Bentley, DgnPlatform, IViewClipObject, GetPointCloudProjectPoints));
    c1.def("SetPointCloudProjectPoints", &IViewClipObject::SetPointCloudProjectPoints, "projectPoints"_a, DOC(Bentley, DgnPlatform, IViewClipObject, SetPointCloudProjectPoints));

    //===================================================================================
    // struct IHasViewClipObject
    py::class_< IHasViewClipObject, std::unique_ptr< IHasViewClipObject, py::nodelete> > c2(m, "IHasViewClipObject");

    c2.def("GetClipObject", &IHasViewClipObject::GetClipObject, "clipEH"_a, DOC(Bentley, DgnPlatform, IHasViewClipObject, GetClipObject));

    //===================================================================================
    // struct SectionClipElementHandler
    py::class_< SectionClipElementHandler
        , std::unique_ptr< SectionClipElementHandler, py::nodelete>
        , DisplayHandler
        , ITransactionHandler
        , IHasViewClipObject> c3(m, "SectionClipElementHandler");

    c3.def_static("CreateClipObject", py::overload_cast<>(&SectionClipElementHandler::CreateClipObject), DOC(Bentley, DgnPlatform, SectionClipElementHandler, CreateClipObject));
    c3.def_static("CreateClipObject", py::overload_cast<ElementHandleCR>(&SectionClipElementHandler::CreateClipObject), "clipEH"_a, DOC(Bentley, DgnPlatform, SectionClipElementHandler, CreateClipObject));
    }