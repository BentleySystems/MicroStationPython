/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\handler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/Handler.h>



static const char * __doc_Bentley_DgnPlatform_TransformInfo_SetAnnotationScale =R"doc(Set annotation scale)doc";

static const char * __doc_Bentley_DgnPlatform_TransformInfo_GetAnnotationScale =R"doc(Get annotation scale)doc";

static const char * __doc_Bentley_DgnPlatform_TransformInfo_SetAnnotationScaleAction =R"doc(Set annotation scale action)doc";

static const char * __doc_Bentley_DgnPlatform_TransformInfo_GetAnnotationScaleAction =R"doc(Get annotation scale action)doc";

static const char * __doc_Bentley_DgnPlatform_TransformInfo_SetOptions =R"doc(Set element-specific transform options.

See also:
    TransformOptionValues)doc";

static const char * __doc_Bentley_DgnPlatform_TransformInfo_GetOptions =R"doc(Check element-specific transform options.

See also:
    TransformOptionValues)doc";

static const char * __doc_Bentley_DgnPlatform_TransformInfo_SetMirrorPlane =R"doc(If this is a mirroring transform, set the plane across which the
element is to be mirrored.)doc";

static const char * __doc_Bentley_DgnPlatform_TransformInfo_GetMirrorPlane =R"doc(If this is a mirroring transform, get the plane across which the
element is to be mirrored.)doc";

static const char * __doc_Bentley_DgnPlatform_TransformInfo_GetTransform =R"doc(Get pointer to the transformation matrix)doc";





/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_Handler(py::module_& m)
    {
    //===================================================================================
    // struct TransformInfo
    py::class_< TransformInfo> c1(m, "TransformInfo");

    c1.def(py::init<>());
    c1.def(py::init<TransformCR>(), "trans"_a);

    c1.def_property_readonly("Transform", &TransformInfo::GetTransformR);
    c1.def("GetTransform", &TransformInfo::GetTransformR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, TransformInfo, GetTransform));
    
    c1.def_property("MirrorPlane",
                    py::cpp_function(&TransformInfo::GetMirrorPlane, py::return_value_policy::reference_internal),
                    py::cpp_function(&TransformInfo::SetMirrorPlane));
    c1.def("GetMirrorPlane", &TransformInfo::GetMirrorPlane, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, TransformInfo, GetMirrorPlane));
    c1.def("SetMirrorPlane", &TransformInfo::SetMirrorPlane, "mirrorPlane"_a, DOC(Bentley, DgnPlatform, TransformInfo, SetMirrorPlane));
    
    c1.def_property("Options", &TransformInfo::GetOptions, &TransformInfo::SetOptions);
    c1.def("GetOptions", &TransformInfo::GetOptions, DOC(Bentley, DgnPlatform, TransformInfo, GetOptions));
    c1.def("SetOptions", &TransformInfo::SetOptions, "options"_a, DOC(Bentley, DgnPlatform, TransformInfo, SetOptions));
    
    c1.def_property("AnnotationScaleAction", &TransformInfo::GetAnnotationScaleAction, &TransformInfo::SetAnnotationScaleAction);
    c1.def("GetAnnotationScaleAction", &TransformInfo::GetAnnotationScaleAction, DOC(Bentley, DgnPlatform, TransformInfo, GetAnnotationScaleAction));
    c1.def("SetAnnotationScaleAction", &TransformInfo::SetAnnotationScaleAction, "action"_a, DOC(Bentley, DgnPlatform, TransformInfo, SetAnnotationScaleAction));
    
    c1.def_property("AnnotationScale", &TransformInfo::GetAnnotationScale, &TransformInfo::SetAnnotationScale);
    c1.def("GetAnnotationScale", &TransformInfo::GetAnnotationScale, DOC(Bentley, DgnPlatform, TransformInfo, GetAnnotationScale));
    c1.def("SetAnnotationScale", &TransformInfo::SetAnnotationScale, "annotationScale"_a, DOC(Bentley, DgnPlatform, TransformInfo, SetAnnotationScale));

    //===================================================================================
    // enum class ExposeChildrenReason
    py::enum_< ExposeChildrenReason>(m, "ExposeChildrenReason")
        .value("eQuery", ExposeChildrenReason::Query)
        .value("eEdit", ExposeChildrenReason::Edit)
        .export_values();

    //===================================================================================
    // enum class SupportOperation
    py::enum_< SupportOperation>(m, "SupportOperation")
        .value("eSelection", SupportOperation::Selection)
        .value("eCellGroup", SupportOperation::CellGroup)
        .value("eCellUnGroup", SupportOperation::CellUnGroup)
        .value("eTransientManipulators", SupportOperation::TransientManipulators)
        .value("eCacheCutGraphics", SupportOperation::CacheCutGraphics)
        .value("eLineStyle", SupportOperation::LineStyle)
        .value("eCustomHilite", SupportOperation::CustomHilite)
        .export_values();

    //===================================================================================
    // struct Handler
    py::class_<Handler
        , std::unique_ptr<Handler, py::nodelete>
    > c3(m, "Handler");

    py::class_<Handler::Extension> c3_1(c3, "Extension");
    
    c3.def_static("GetInstance", &Handler::GetInstance, py::return_value_policy::reference_internal);
    c3.def("GetDisplayHandler", &Handler::GetDisplayHandler, py::return_value_policy::reference_internal);
    c3.def("GetITransactionHandler", &Handler::GetITransactionHandler, py::return_value_policy::reference_internal);
    c3.def("GetIDependencyHandler", &Handler::GetIDependencyHandler, py::return_value_policy::reference_internal);
    c3.def("ApplyTransform", &Handler::ApplyTransform, "eeh"_a, "transform"_a);
    c3.def("FenceStretch", &Handler::FenceStretch, "eeh"_a, "transfrom"_a, "fp"_a, "options"_a);
    c3.def("FenceClip", &Handler::FenceClip, "inside"_a, "outside"_a, "eh"_a, "fp"_a, "options"_a);
    c3.def("ConvertTo3d", &Handler::ConvertTo3d, "eeh"_a, "elevation"_a);
    c3.def("ConvertTo2d", &Handler::ConvertTo2d, "eeh"_a, "flattenTrans"_a, "flattenDir"_a);
    c3.def("GetDescription", &Handler::GetDescription, "eh"_a, "string"_a, "desiredLength"_a);
    c3.def("GetTypeName", &Handler::GetTypeName, "string"_a, "desiredLength"_a);
    c3.def("QueryProperties", &Handler::QueryProperties, "eh"_a, "context"_a);
    c3.def("EditProperties", &Handler::EditProperties, "eeh"_a, "context"_a);
    c3.def("ExposeChildren", &Handler::ExposeChildren, "eh"_a, "reason"_a);
    }