/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\solidkernel.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/SolidKernel.h>



static const char * __doc_Bentley_DgnPlatform_ISubEntity_GetSubEntityType =R"doc(Get the topology type for this sub-entity.

Returns:
    The sub-entity type.)doc";

static const char * __doc_Bentley_DgnPlatform_ISolidKernelEntity_PostMultiplyEntityTransformInPlace =R"doc(PostMultiply the entity transform by the supplied (solid) transform

Parameter ``solidTransform``:
    The transform to post-multiply.)doc";

static const char * __doc_Bentley_DgnPlatform_ISolidKernelEntity_PreMultiplyEntityTransformInPlace =R"doc(PreMultiply the entity transform by the supplied (solid) transform

Parameter ``uorTransform``:
    The transform to pre-multiply.)doc";

static const char * __doc_Bentley_DgnPlatform_ISolidKernelEntity_SetEntityTransform =R"doc(Changes the solid to uor transform for the entity.

Parameter ``transform``:
    The new solid to uor transform.)doc";

static const char * __doc_Bentley_DgnPlatform_ISolidKernelEntity_GetEntityTransform =R"doc(Get the body to uor transform for this entity. This transform can have
translation, rotation, and scale. A distance of 1.0 in solid kernel
coordinates represents 1 meter, how many uors this represents is
determined by the transform scale. Typically the body to uor scale
comes from the model's unit settings (ModelInfo::GetSolidExtent). In
order to achieve a precision of 1.0e-8 for modeling operations, a
single body must fit inside a 1 km box centered at the origin (in
solid kernel coordinates not uors). In order to perform a boolean
operation between 2 bodies, the position of the tool body relative to
the target must also be within this 1 km size box. The body to uor
translation allows for a solid that will typically have a basis point
of 0,0,0 to be displayed at any uor location in a dgn model.

Returns:
    The solid kernel to uor transform for the entity.)doc";

static const char * __doc_Bentley_DgnPlatform_ISolidKernelEntity_GetEntityType =R"doc(Get the body type for this entity.

Returns:
    The solid kernel entity type.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_SolidKernel(py::module_& m)
    {
    //===================================================================================
    // struct ISolidKernelEntity
    py::class_< ISolidKernelEntity, ISolidKernelEntityPtr> c1(m, "ISolidKernelEntity");
    py::bind_vector< bvector<ISolidKernelEntityPtr> >(m, "ISolidKernelEntityPtrArray", py::module_local(false));

    if (true)
        {
        //===================================================================================
        // enum KernelEntityType
        py::enum_< ISolidKernelEntity::KernelEntityType>(c1, "KernelEntityType", py::arithmetic())
            .value("eEntityType_Solid", ISolidKernelEntity::EntityType_Solid)
            .value("eEntityType_Sheet", ISolidKernelEntity::EntityType_Sheet)
            .value("eEntityType_Wire", ISolidKernelEntity::EntityType_Wire)
            .value("eEntityType_Minimal", ISolidKernelEntity::EntityType_Minimal)
            .export_values();

        }

    c1.def("__eq__", [] (ISolidKernelEntityCR self, ISolidKernelEntityCR other) { return self.IsEqual(other); });
    
    c1.def_property_readonly("EntityType", &ISolidKernelEntity::GetEntityType);
    c1.def("GetEntityType", &ISolidKernelEntity::GetEntityType, DOC(Bentley, DgnPlatform, ISolidKernelEntity, GetEntityType));

    c1.def_property("EntityTransform", &ISolidKernelEntity::GetEntityTransform, &ISolidKernelEntity::SetEntityTransform);
    c1.def("GetEntityTransform", &ISolidKernelEntity::GetEntityTransform, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ISolidKernelEntity, GetEntityTransform));
    c1.def("SetEntityTransform", &ISolidKernelEntity::SetEntityTransform, "transform"_a, DOC(Bentley, DgnPlatform, ISolidKernelEntity, SetEntityTransform));

    c1.def("PreMultiplyEntityTransformInPlace", &ISolidKernelEntity::PreMultiplyEntityTransformInPlace, "uorTransform"_a, DOC(Bentley, DgnPlatform, ISolidKernelEntity, PreMultiplyEntityTransformInPlace));
    c1.def("PostMultiplyEntityTransformInPlace", &ISolidKernelEntity::PostMultiplyEntityTransformInPlace, "uorTransform"_a, DOC(Bentley, DgnPlatform, ISolidKernelEntity, PostMultiplyEntityTransformInPlace));

    //===================================================================================
    // struct ISubEntity
    py::class_< ISubEntity, ISubEntityPtr> c2(m, "ISubEntity");
    py::bind_vector< bvector<ISubEntityPtr> >(m, "ISubEntityPtrArray", py::module_local(false));

    if (true)
        {
        //===================================================================================
        // enum SubEntityType
        py::enum_< ISubEntity::SubEntityType>(c2, "ISubEntity", py::arithmetic())
            .value("eSubEntityType_Face", ISubEntity::SubEntityType_Face)
            .value("eSubEntityType_Edge", ISubEntity::SubEntityType_Edge)
            .value("eSubEntityType_Vertex", ISubEntity::SubEntityType_Vertex)
            .export_values();

        }

    c2.def("__eq__", [] (ISubEntityCR self, ISubEntityCR other) { return self.IsEqual(other); });
    c2.def_property_readonly("SubEntityType", &ISubEntity::GetSubEntityType);
    c2.def("GetSubEntityType", &ISubEntity::GetSubEntityType, DOC(Bentley, DgnPlatform, ISubEntity, GetSubEntityType));

    //===================================================================================
    // struct IFaceMaterialAttachments
    py::class_< IFaceMaterialAttachments, IFaceMaterialAttachmentsPtr> c4(m, "IFaceMaterialAttachments");

    }