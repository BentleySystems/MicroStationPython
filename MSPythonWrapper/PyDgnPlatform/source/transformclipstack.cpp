/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\transformclipstack.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/TransformClipStack.h>



static const char * __doc_Bentley_DgnPlatform_TransformClipStack_GetSize =R"doc(Get the size of TransformClip states on the stack)doc";

static const char * __doc_Bentley_DgnPlatform_TransformClipStack_GetTransformScale =R"doc(Get the scale value of the transform state at the top of stack)doc";

static const char * __doc_Bentley_DgnPlatform_TransformClipStack_GetTransformFromTopToIndex =R"doc(Get the product of transform state at the top of the stack and at a
given index in the stack)doc";

static const char * __doc_Bentley_DgnPlatform_TransformClipStack_GetTransformFromIndex =R"doc(Get the transform state at a given index in the stack)doc";

static const char * __doc_Bentley_DgnPlatform_TransformClipStack_GetTransform =R"doc(Get the transform state at the top of stack)doc";

static const char * __doc_Bentley_DgnPlatform_TransformClipStack_GetInverseTransform =R"doc(Get the inverse of transform state at the top of stack)doc";

static const char * __doc_Bentley_DgnPlatform_TransformClipStack_GetClip =R"doc(Get the clip state at the top of the stack)doc";

static const char * __doc_Bentley_DgnPlatform_TransformClipStack_TestPoint =R"doc(Test if the given point is within the clip boundary of the
TransformClip at the top of the stack)doc";

static const char * __doc_Bentley_DgnPlatform_TransformClipStack_GetRayIntersection =R"doc(Test if the given ray intersects the clip boundary of the
TransformClip at the top of the stack. If it intersects, get the
distance to intersection.
Returns (Tuple, 0):
	retVal.

Returns (Tuple, 1):
	intersectDistance.

)doc";

static const char * __doc_Bentley_DgnPlatform_TransformClipStack_ClassifyPoints =R"doc(Classify the given points for containment within the clip boundary of
the TransformClip at the top of the stack)doc";

static const char * __doc_Bentley_DgnPlatform_TransformClipStack_ClassifyRange =R"doc(Classify the 8 corners of the given range for containment within the
clip boundary of the TransformClip at the top of the stack)doc";

static const char * __doc_Bentley_DgnPlatform_TransformClipStack_TestRay =R"doc(Test if the given ray intersects the clip boundary of the
TransformClip at the top of the stack)doc";

static const char * __doc_Bentley_DgnPlatform_TransformClipStack_IsViewIndependent =R"doc(Get the view-independent state of the TransformClip at the top of the
stack)doc";

static const char * __doc_Bentley_DgnPlatform_TransformClipStack_SetViewIndependent =R"doc(Set the view-independent state of the TransformClip at the top of the
stack)doc";

static const char * __doc_Bentley_DgnPlatform_TransformClipStack_PopAll =R"doc(Pop all TransformClip states from the stack)doc";

static const char * __doc_Bentley_DgnPlatform_TransformClipStack_Pop =R"doc(Pop the TransformClip state from the top of the stack)doc";

static const char * __doc_Bentley_DgnPlatform_TransformClipStack_PushIdentity =R"doc(Push an identity transform with no clipping)doc";

static const char * __doc_Bentley_DgnPlatform_TransformClipStack_PushClipPlaneSets =R"doc(Push a set of clip planes to the top of the stack)doc";

static const char * __doc_Bentley_DgnPlatform_TransformClipStack_PushClipPlanes =R"doc(Push clip planes to the top of the stack)doc";

static const char * __doc_Bentley_DgnPlatform_TransformClipStack_PushClip =R"doc(Push a clip vector to the top of the stack)doc";

static const char * __doc_Bentley_DgnPlatform_TransformClipStack_PushTransform =R"doc(Push a transform to the top of the stack)doc";

static const char * __doc_Bentley_DgnPlatform_TransformClipStack_Clear =R"doc(Clear existing items from the stack)doc";

static const char * __doc_Bentley_DgnPlatform_TransformClipStack_IsEmpty =R"doc(Check if the clip stack is empty)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_TransformClipStack(py::module_& m)
    {
    //===================================================================================
    // struct TransformClipStack
    py::class_< TransformClipStack, std::unique_ptr<TransformClipStack, py::nodelete> > c1(m, "TransformClipStack");

    c1.def("IsEmpty", &TransformClipStack::IsEmpty, DOC(Bentley, DgnPlatform, TransformClipStack, IsEmpty));
    c1.def("Clear", &TransformClipStack::Clear, DOC(Bentley, DgnPlatform, TransformClipStack, Clear));
    c1.def("PushTransform", &TransformClipStack::PushTransform, "transform"_a, DOC(Bentley, DgnPlatform, TransformClipStack, PushTransform));
    c1.def("PushClip", &TransformClipStack::PushClip, "clip"_a, DOC(Bentley, DgnPlatform, TransformClipStack, PushClip));
    
    c1.def("PushClipPlanes", [] (TransformClipStack& self, bvector<ClipPlane> const& planes)
           {
           self.PushClipPlanes(planes.data(), planes.size());
           }, "planes"_a, DOC(Bentley, DgnPlatform, TransformClipStack, PushClipPlanes));

    c1.def("PushClipPlanes", [] (TransformClipStack& self, py::list const& planes)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(planes, cppPlanes, bvector<ClipPlane>, ClipPlane);
           self.PushClipPlanes(cppPlanes.data(), cppPlanes.size());
           }, "planes"_a, DOC(Bentley, DgnPlatform, TransformClipStack, PushClipPlanes));

    c1.def("PushClipPlaneSets", &TransformClipStack::PushClipPlaneSets, "planes"_a, DOC(Bentley, DgnPlatform, TransformClipStack, PushClipPlaneSets));
    c1.def("PushIdentity", &TransformClipStack::PushIdentity, DOC(Bentley, DgnPlatform, TransformClipStack, PushIdentity));

    c1.def("Pop", &TransformClipStack::Pop, "viewContext"_a, DOC(Bentley, DgnPlatform, TransformClipStack, Pop));
    c1.def("PopAll", &TransformClipStack::PopAll, "viewContext"_a, DOC(Bentley, DgnPlatform, TransformClipStack, PopAll));
    c1.def("SetViewIndependent", &TransformClipStack::SetViewIndependent, DOC(Bentley, DgnPlatform, TransformClipStack, SetViewIndependent));
    c1.def("IsViewIndependent", &TransformClipStack::IsViewIndependent, DOC(Bentley, DgnPlatform, TransformClipStack, IsViewIndependent));
    c1.def("IncrementPushedToDrawGeom", &TransformClipStack::IncrementPushedToDrawGeom);
    c1.def("TestRay", &TransformClipStack::TestRay, "point"_a, "direction"_a, DOC(Bentley, DgnPlatform, TransformClipStack, TestRay));

    c1.def("ClassifyRange", 
           py::overload_cast<DRange3dCR, bool>(&TransformClipStack::ClassifyRange, py::const_),
           "range"_a, "ignoreMasks"_a = false, DOC(Bentley, DgnPlatform, TransformClipStack, ClassifyRange));

    c1.def("ClassifyRange", 
           py::overload_cast<ScanRangeCR, bool, bool>(&TransformClipStack::ClassifyRange, py::const_), 
           "range"_a, "is3d"_a = true, "ignoreMasks"_a = false, DOC(Bentley, DgnPlatform, TransformClipStack, ClassifyRange));

    c1.def("ClassifyPoints", [] (TransformClipStack const& self, DPoint3dArray const& points, bool ignoreMasks)
           {
           return self.ClassifyPoints(points.data(), points.size(), ignoreMasks);
           }, "points"_a, "ignoreMasks"_a = false, DOC(Bentley, DgnPlatform, TransformClipStack, ClassifyPoints));

    c1.def("ClassifyPoints", [] (TransformClipStack const& self, py::list const& points, bool ignoreMasks)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(points, cppPoints, DPoint3dArray, DPoint3d);
           return self.ClassifyPoints(cppPoints.data(), cppPoints.size(), ignoreMasks);
           }, "points"_a, "ignoreMasks"_a = false, DOC(Bentley, DgnPlatform, TransformClipStack, ClassifyPoints));

    c1.def("GetRayIntersection", [] (TransformClipStack const& self, DPoint3dCR point, DVec3dCR direction)
           {
           double intersectDistance = 0;
           auto retVal = self.GetRayIntersection(intersectDistance, point, direction);
           return py::make_tuple(retVal, intersectDistance);
           }, "points"_a, "direction"_a, DOC(Bentley, DgnPlatform, TransformClipStack, GetRayIntersection));

    c1.def("TestPoint", &TransformClipStack::TestPoint, "point"_a, DOC(Bentley, DgnPlatform, TransformClipStack, TestPoint));
    
    c1.def_property_readonly("Clip", &TransformClipStack::GetClip);
    c1.def("GetClip", &TransformClipStack::GetClip, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, TransformClipStack, GetClip));
    
    c1.def_property_readonly("DrawGeomClip", &TransformClipStack::GetDrawGeomClip);
    c1.def("GetDrawGeomClip", &TransformClipStack::GetDrawGeomClip, py::return_value_policy::reference_internal);
    
    c1.def("GetInverseTransform", &TransformClipStack::GetInverseTransform, "transform"_a, DOC(Bentley, DgnPlatform, TransformClipStack, GetInverseTransform));
    c1.def("GetTransform", &TransformClipStack::GetTransform, "transform"_a, DOC(Bentley, DgnPlatform, TransformClipStack, GetTransform));
    c1.def("GetTransformFromIndex", &TransformClipStack::GetTransformFromIndex, "transform"_a, "index"_a, DOC(Bentley, DgnPlatform, TransformClipStack, GetTransformFromIndex));
    c1.def("GetTransformFromTopToIndex", &TransformClipStack::GetTransformFromTopToIndex, "transform"_a, "index"_a, DOC(Bentley, DgnPlatform, TransformClipStack, GetTransformFromTopToIndex));
    
    c1.def_property_readonly("Transform", &TransformClipStack::GetTransformCP);
    c1.def("GetTransform", &TransformClipStack::GetTransformCP, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, TransformClipStack, GetTransform));
    
    c1.def_property_readonly("TransformScale", &TransformClipStack::GetTransformScale);
    c1.def("GetTransformScale", &TransformClipStack::GetTransformScale, DOC(Bentley, DgnPlatform, TransformClipStack, GetTransformScale));
    
    c1.def_property_readonly("Size", &TransformClipStack::GetSize);
    c1.def("GetSize", &TransformClipStack::GetSize, DOC(Bentley, DgnPlatform, TransformClipStack, GetSize));
    }