/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\test\pycheckers.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include "checkers.cpp"

/*---------------------------------------------------------------------------------**//**
* Class generator for Check.
* @bsimethod                                                                       9/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_Checkers(py::module_& m)
    {
    //===================================================================================
    // struct Check created for geom API tests
    py::class_<Check> c1(m, "Check");

    //===================================================================================
    // Enum ToleranceSelect
    py::enum_< ToleranceSelect>(m, "ToleranceSelect", py::arithmetic())
        .value("eToleranceSelect_default", ToleranceSelect_default)
        .value("eToleranceSelect_Loose", ToleranceSelect_Loose)
        .value("eToleranceSelect_Tight", ToleranceSelect_Tight)
        .value("eToleranceSelect_Medium", ToleranceSelect_Medium)
        .value("eToleranceSelect_NearMachine", ToleranceSelect_NearMachine)
        .export_values();

    c1.def_static("Start", &Check::Start);
    c1.def_static("End", &Check::End);
    c1.def_static("Tol", py::overload_cast<double>(&Check::Tol), "a"_a);
    c1.def_static("Tol", py::overload_cast<double,double>(&Check::Tol), "a"_a, "b"_a);
    c1.def_static("Tol", py::overload_cast<double, double, double, double>(&Check::Tol), "a"_a, "b"_a, "c"_a, "d"_a=0.0);

    c1.def_static("Tol", py::overload_cast<DPoint2dCR>(&Check::Tol), "Q"_a);
    c1.def_static("Tol", py::overload_cast<DPoint3dCR>(&Check::Tol), "Q"_a);
    c1.def_static("Tol", py::overload_cast<DPoint4dCR>(&Check::Tol), "Q"_a);
    c1.def_static("Tol", py::overload_cast<DPoint2dCR, DPoint2dCR>(&Check::Tol), "Q"_a, "R"_a);
    c1.def_static("Tol", py::overload_cast<DPoint3dCR, DPoint3dCR>(&Check::Tol), "Q"_a, "R"_a);
    c1.def_static("Tol", py::overload_cast<DPoint4dCR, DPoint4dCR>(&Check::Tol), "Q"_a, "R"_a);

    c1.def_static("NearZero", &Check::NearZero, "a"_a, "name"_a=NULL, "refValue"_a = 0.0);

    c1.def_static("ExactDouble", &Check::ExactDouble, "a"_a, "b"_a, "pName"_a = NULL);
    c1.def_static("Exact", &Check::Exact, "a"_a, "b"_a, "pString"_a = NULL);
    c1.def_static("ExactRange", &Check::ExactRange, "a"_a, "b"_a, "pString"_a = NULL);

    c1.def_static("Near", [](double a, double b, char const* pName, double refValue)
                            {
                            return Check::Near(a, b, pName, refValue);
                            }, "a"_a, "b"_a, "pName"_a = NULL, "refValue"_a = 0.0);

    c1.def_static("Contains", &Check::Contains, "a"_a, "b"_a, "pName"_a = NULL);
    c1.def_static("LE_Toleranced", &Check::LE_Toleranced, "a"_a, "b"_a);

    c1.def_static("Near", [](DPoint2dCR a, DPoint2dCR b, char const* pName, double refValue)
                            {
                            return Check::Near(a, b, pName, refValue);
                            }, "a"_a, "b"_a, "pName"_a = NULL, "refValue"_a = 0.0);

    c1.def_static("Near", [](DPoint3dCR a, DPoint3dCR b, char const* pName, double refValue)
                            {
                            return Check::Near(a, b, pName, refValue);
                            }, "a"_a, "b"_a, "pName"_a = NULL, "refValue"_a = 0.0);

    c1.def_static("Near", [](DPoint2dCP a, DPoint2dCP b, int n, char const* pName, double refValue)
                            {
                            return Check::Near(a, b, n, pName, refValue);
                            }, "a"_a, "b"_a, "n"_a, "pName"_a = NULL, "refValue"_a = 0.0);

    c1.def_static("Near", [](DPoint3dCP a, DPoint3dCP b, int n, char const* pName, double refValue)
                            {
                            return Check::Near(a, b, n, pName, refValue);
                            }, "a"_a, "b"_a, "n"_a, "pName"_a = NULL, "refValue"_a = 0.0);

    c1.def_static("Near", [](DPoint2dCR xy, double x, double y, char const* pName, double refValue)
                            {
                            return Check::Near(xy, x, y, pName, refValue);
                            }, "xy"_a, "x"_a, "y"_a, "pName"_a = NULL, "refValue"_a = 1.0);

    c1.def_static("Near", [](DPoint3dCR xyz, double x, double y, double z, char const* pName, double refValue)
                            {
                            return Check::Near(xyz, x, y, z, pName, refValue);
                            }, "xyz"_a, "x"_a, "y"_a, "z"_a, "pName"_a = NULL, "refValue"_a = 1.0);

    c1.def_static("Near", [](DRange2dCR a, DRange2dCR b, char const* pName, double refValue)
                            {
                            return Check::Near(a, b, pName, refValue);
                            }, "a"_a, "b"_a, "pName"_a = NULL, "refValue"_a = 1.0);

    c1.def_static("Near", [](DRange3dCR a, DRange3dCR b, char const* pName, double refValue)
                            {
                            return Check::Near(a, b, pName, refValue);
                            }, "a"_a, "b"_a, "pName"_a = NULL, "refValue"_a = 0.0);

    c1.def_static("NearMoments", &Check::NearMoments, "axes0"_a, "moment0"_a, "axes1"_a, "moment1"_a);

    c1.def_static("Near", [](DPoint4dCR a, DPoint4dCR b, char const* pName, double refValue)
                            {
                            return Check::Near(a, b, pName, refValue);
                            }, "a"_a, "b"_a, "pName"_a = NULL, "refValue"_a = 0.0);

    c1.def_static("Near", [](RotMatrixCR a, RotMatrixCR b, char const* pName, double refValue)
                            {
                            return Check::Near(a, b, pName, refValue);
                            }, "a"_a, "b"_a, "pName"_a = NULL, "refValue"_a = 0.0);

    c1.def_static("TrueZero", &Check::TrueZero, "a"_a, "pName"_a=NULL);

    c1.def_static("Near", [](TransformCR a, TransformCR b, char const* pName, double refValue)
                            {
                            return Check::Near(a, b, pName, refValue);
                            }, "a"_a, "b"_a, "pName"_a = NULL, "refValue"_a = 0.0);

    c1.def_static("Near", [](DMatrix4d a, DMatrix4d b, char const* pName, double refValue)
                            {
                            return Check::Near(a, b, pName, refValue);
                            }, "a"_a, "b"_a, "pName"_a = NULL, "refValue"_a = 0.0);

    c1.def_static("Near", [](DSegment3dCR a, DSegment3dCR b, char const* pString, double refValue)
                            {
                            return Check::Near(a, b, pString, refValue);
                            }, "a"_a, "b"_a, "pString"_a = NULL, "refValue"_a = 0.0);

    c1.def_static("Near", [](DEllipse3dCR a, DEllipse3dCR b, char const* pString, double refValue)
                            {
                            return Check::Near(a, b, pString, refValue);
                            }, "a"_a, "b"_a, "pString"_a = NULL, "refValue"_a = 0.0);

    c1.def_static("Near", [](DConic4dCR a, DConic4dCR b, char const* pName, double refValue)
                            {
                            return Check::Near(a, b, pName, refValue);
                            }, "a"_a, "b"_a, "pName"_a = NULL, "refValue"_a = 0.0);

    c1.def_static("NearPeriodic", py::overload_cast<double, double, char const*>(&Check::NearPeriodic), "thetaA"_a, "thetaB"_a, "pString"_a);
    c1.def_static("NearPeriodic", py::overload_cast<Angle, Angle, char const*>(&Check::NearPeriodic), "thetaA"_a, "thetaB"_a, "pString"_a=NULL);

    c1.def_static("Near", [](Angle thetaA, Angle thetaB, char const* pString)
                            {
                            return Check::Near(thetaA, thetaB, pString);
                            }, "thetaA"_a, "thetaB"_a, "pString"_a = NULL);

    c1.def_static("Parallel", &Check::Parallel, "a"_a, "b"_a, "pName"_a = NULL, "refValue"_a = 0.0);
    c1.def_static("Perpendicular", &Check::Perpendicular, "a"_a, "b"_a, "pName"_a = NULL, "refValue"_a = 0.0);

    c1.def_static("Bool", &Check::Bool, "a"_a, "b"_a, "pName"_a = NULL);
    c1.def_static("Int", &Check::Int, "a"_a, "b"_a, "pName"_a = NULL);
    c1.def_static("IsFalse", &Check::False, "a"_a, "pName"_a = NULL);
    c1.def_static("IsTrue", &Check::True, "b"_a, "pName"_a = NULL);
    c1.def_static("LessThanOrEqual", &Check::LessThanOrEqual, "a"_a, "b"_a, "pString"_a = NULL);
    c1.def_static("Size", &Check::Size, "a"_a, "b"_a, "pName"_a = NULL);
    c1.def_static("Ptrdiff", &Check::Ptrdiff, "a"_a, "b"_a, "pName"_a = NULL);

    c1.def_static("Near", py::overload_cast<bvector<int>&, bvector<int>&, char const*>(&Check::template Near<int>));
    c1.def_static("Near", py::overload_cast<bvector<double>&, bvector<double>&, char const*>(&Check::template Near<double>));
    c1.def_static("Near", py::overload_cast<bvector<DPoint3d>&, bvector<DPoint3d>&, char const*>(&Check::template Near<DPoint3d>));
    c1.def_static("StartScope", [](char const* name)
                                {
                                return Check::StartScope (name);
                                }, "name"_a);
    c1.def_static("EndScope", &Check::EndScope);
    c1.def_static("PushTolerance", &Check::PushTolerance, "s"_a);
    c1.def_static("PopTolerance", &Check::PopTolerance);
    c1.def_static("Shift", py::overload_cast<double, double, double>(&Check::Shift), "dx"_a, "dy"_a, "dz"_a = 0.0);
    c1.def_static("Shift", py::overload_cast<DVec3dCR>(&Check::Shift), "shift"_a);
    c1.def_static("SetTransform", &Check::SetTransform, "transform"_a);
    c1.def_static("SaveTransformed", [](CurveVectorCR data)
        {
            return Check::SaveTransformed(data);
        }, "data"_a);
    c1.def_static("SaveTransformedMarker", &Check::SaveTransformedMarker, "data"_a, "markerSize"_a = 0.1);
    c1.def_static("ClearGeometry", &Check::ClearGeometry, "name"_a, "saveIModelJson"_a = true);

    py::class_<SaveAndRestoreCheckTransform> c2(m, "SaveAndRestoreCheckTransform");
    c2.def(py::init<>());
    c2.def(py::init<double, double, double>(), "dxFinal"_a, "dyFinal"_a, "dzFinal"_a);
    c2.def("DoShift", &SaveAndRestoreCheckTransform::DoShift);
    c2.def("SetShift", &SaveAndRestoreCheckTransform::SetShift, "dx"_a, "dy"_a, "dz"_a);

    }

