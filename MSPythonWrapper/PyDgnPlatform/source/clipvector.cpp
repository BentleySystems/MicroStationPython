/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\clipvector.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ClipVector.h>



/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ClipVector(py::module_& m)
    {
    //===================================================================================
    // struct ClipVector
    py::class_<ClipVector, ClipVectorPtr> c1(m, "ClipVector");

    c1.def(py::init(&ClipVector::Create));
    c1.def(py::init(&ClipVector::CreateCopy), "vector"_a);
    c1.def(py::init(&ClipVector::CreateFromPrimitive), "primitive"_a);

    c1.def_static("CreateFromGPA",
        [](GPArrayCR gpa, double chordTolerance, double angleTolerance, boost::optional<double> zLow, boost::optional<double> zHigh, TransformCP transform)
        {
            return ClipVector::CreateFromGPA(gpa, chordTolerance, angleTolerance, zLow.get_ptr(), zHigh.get_ptr(), transform);
        },
        "gpa"_a, "chordTolerance"_a, "angleTolerance"_a, "zLow"_a, "zHigh"_a, "transform"_a);
    
    c1.def_static("CreateFromCurveVector", 
                  [](CurveVectorCR curveVector, double chordTolerance, double angleTolerance, boost::optional<double> zLow, boost::optional<double> zHigh)
                  {
                      return ClipVector::CreateFromCurveVector(curveVector, chordTolerance, angleTolerance, zLow.get_ptr(), zHigh.get_ptr());
                  },
                  "curveVector"_a, "chordTolerance"_a, "angleTolerance"_a, "zLow"_a = nullptr, "zHigh"_a = nullptr);

    c1.def_static("CreateFromElement", 
                  &ClipVector::CreateFromElement, 
                  "eh"_a, "modelRef"_a, "viewport"_a = nullptr, "pass"_a = ClipVolumePass::Inside, "dvSettings"_a = nullptr, "displayCutGeometry"_a = true);

    c1.def_static("CreateFromModelRef", &ClipVector::CreateFromModelRef, "modelRef"_a, "viewport"_a, "transform"_a);

    c1.def("PointInside", &ClipVector::PointInside, "point"_a, "onTolerance"_a = 0.0);
    c1.def("SphereInside", &ClipVector::SphereInside, "point"_a, "radius"_a);
    c1.def("TransformInPlace", &ClipVector::TransformInPlace, "transform"_a);
    c1.def("Append", &ClipVector::Append, "clip"_a);
    c1.def("AppendCopy", &ClipVector::AppendCopy, "clip"_a);
    c1.def("ClipPolyface", &ClipVector::ClipPolyface, "polyface"_a, "output"_a, "triangulateOutput"_a);
    c1.def("SetInvisible", &ClipVector::SetInvisible, "invisible"_a);
    c1.def("GetRange", &ClipVector::GetRange, "range"_a, "transform"_a);
    
    c1.def_static("AppendShape", 
        [](ClipVectorPtr& clip, DPoint2dArray const& points, bool outside, boost::optional<double> zLow, boost::optional<double> zHigh, TransformCP transform, bool invisible)
        {
            return ClipVector::AppendShape(clip, &points[0], points.size(), outside, zLow.get_ptr(), zHigh.get_ptr(), transform, invisible);
        },
        "clip"_a, "points"_a, "outside"_a, "zLow"_a, "zHigh"_a, "transform"_a, "invisible"_a = false);

    c1.def_static("AppendShape", 
            [](ClipVectorPtr& clip, py::list const& points, bool outside, boost::optional<double> zLow, boost::optional<double> zHigh, TransformCP transform, bool invisible)
            {
                if (points.size() == 0)
                    throw std::invalid_argument("Invalid input: points cannot be empty");
                CONVERT_PYLIST_TO_NEW_CPPARRAY(points, cppPoints, DPoint2dArray, DPoint2d);
                return ClipVector::AppendShape(clip, &cppPoints[0], cppPoints.size(), outside, zLow.get_ptr(), zHigh.get_ptr(), transform, invisible);
            },
            "clip"_a, "points"_a, "outside"_a, "zLow"_a, "zHigh"_a, "transform"_a, "invisible"_a = false);
    
    c1.def_static("AppendPlanes", &ClipVector::AppendPlanes, "clip"_a, "planes"_a, "invisible"_a = false);
    c1.def("ParseClipPlanes", &ClipVector::ParseClipPlanes);
    c1.def("ExpandClipPlanes", &ClipVector::ExpandClipPlanes, "distance"_a);
    c1.def("ApplyCameraToPlanes", &ClipVector::ApplyCameraToPlanes, "focalLength"_a);   

    c1.def("ClassifyPointContainment", [] (ClipVectorCR self, std::vector<DPoint3d> const& points, bool ignoreMasks)
           {
           return self.ClassifyPointContainment(points.data(), points.size(), ignoreMasks);
           }, "points"_a, "ignoreMasks"_a = false);

    c1.def("ClassifyPointContainment", [] (ClipVectorCR self, py::list const& points, bool ignoreMasks)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(points, cppPoints, std::vector<DPoint3d>, DPoint3d)
           return self.ClassifyPointContainment(cppPoints.data(), cppPoints.size(), ignoreMasks);
           }, "points"_a, "ignoreMasks"_a = false);
    }