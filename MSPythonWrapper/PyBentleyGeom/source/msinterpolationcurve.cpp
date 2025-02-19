/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\msinterpolationcurve.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"



static const char * __doc_Bentley_Geom_MSInterpolationCurve_Zero =R"doc(Clear to zero state. DOES NOT RELEASE MEMORY.)doc";

static const char * __doc_Bentley_Geom_MSInterpolationCurve_CopyFrom =R"doc(Allocate memory for the B-spline curve and copies all data from the
input inerpolation curve.)doc";

static const char * __doc_Bentley_Geom_MSInterpolationCurve_AllocateKnots =R"doc(Allocate specified number of knots. Optionally copy in knots from
buffer.)doc";

static const char * __doc_Bentley_Geom_MSInterpolationCurve_AllocateFitPoints =R"doc(Allocate specified number of fit points. Optionally copy in points
from buffer.)doc";

static const char * __doc_Bentley_Geom_MSInterpolationCurve_ReleaseMem =R"doc(Free the memory allocated to the poles of the interpolation curve.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_MSInterpolationCurve(py::module_& m)
    {
    //===================================================================================
    // struct MSInterpolationCurve
    py::class_<MSInterpolationCurve> c1(m, "MSInterpolationCurve");
    py::class_<RefCountedMSInterpolationCurve, std::unique_ptr<RefCountedMSInterpolationCurve, py::nodelete>, MSInterpolationCurve> c2(m, "RefCountedMSInterpolationCurve");

    c1.def(py::init<>());
    c1.def_static("Create", &MSInterpolationCurve::CreatePtr);
    c1.def("ReleaseMem", &MSInterpolationCurve::ReleaseMem, DOC(Bentley, Geom, MSInterpolationCurve, ReleaseMem));

    c1.def("AllocateFitPoints", &MSInterpolationCurve::AllocateFitPoints, "count"_a, "data"_a = nullptr, DOC(Bentley, Geom, MSInterpolationCurve, AllocateFitPoints));
    c1.def("AllocateKnots", &MSInterpolationCurve::AllocateKnots, "count"_a, "data"_a = nullptr, DOC(Bentley, Geom, MSInterpolationCurve, AllocateKnots));
    c1.def("CopyFrom", &MSInterpolationCurve::CopyFrom, "source"_a, DOC(Bentley, Geom, MSInterpolationCurve, CopyFrom));
    c1.def("Zero", &MSInterpolationCurve::Zero, DOC(Bentley, Geom, MSInterpolationCurve, Zero));

    c1.def_property_readonly("Order", &MSInterpolationCurve::GetOrder);
    c1.def("GetOrder", &MSInterpolationCurve::GetOrder);

    c1.def("InitFromPointsAndEndTangents",
           py::overload_cast<DPoint3dArray&, bool, double, DPoint3d*, bool, bool, bool, bool>(&MSInterpolationCurve::InitFromPointsAndEndTangents),
           "inPoints"_a, "removeData"_a, "removeTol"_a, "endTangents"_a, "closedCurve"_a, "colinearTangents"_a, "chordLenTangents"_a, "naturalTangents"_a);

    c1.def("Populate", [] (MSInterpolationCurveR self, int order, bool periodic, int isChordLenKnots, int isColinearTangents, int isChordLenTangents, int isNaturalTangents,
                           DPoint3dArray const& fitPoints, DoubleArray const& knots, DVec3dCP pStartTangent, DVec3dCP pEndTangent)
           {
           auto retVal = self.Populate(order, periodic, isChordLenKnots, isColinearTangents, isChordLenTangents, isNaturalTangents,
                                       fitPoints.data(), (int) fitPoints.size(), knots.data(), (int) knots.size(), pStartTangent, pEndTangent);
           return retVal;
           }, "order"_a, "periodic"_a, "isChordLenKnots"_a, "isColinearTangents"_a, "isChordLenTangents"_a, "isNaturalTangents"_a, "fitPoints"_a, "knots"_a, "startTangent"_a, "endTangent"_a);

    c1.def("Populate", [] (MSInterpolationCurveR self, int order, bool periodic, int isChordLenKnots, int isColinearTangents, int isChordLenTangents, int isNaturalTangents,
                           std::vector<DPoint3d> const& fitPoints, std::vector<double> const& knots)
           {
           auto retVal = self.Populate(order, periodic, isChordLenKnots, isColinearTangents, isChordLenTangents, isNaturalTangents,
                                     fitPoints.data(), (int) fitPoints.size(), knots.data(), (int) knots.size());
           return retVal;
           }, "order"_a, "periodic"_a, "isChordLenKnots"_a, "isColinearTangents"_a, "isChordLenTangents"_a, "isNaturalTangents"_a, "fitPoints"_a, "knots"_a);

    c1.def("AlmostEqual", &MSInterpolationCurve::AlmostEqual, "other"_a, "tolerance"_a);  

    c1.def("__repr__", [] (MSInterpolationCurve& self)
           {
           return "(order:{})"_s.format(self.GetOrder());
           });

    c1.def("__copy__", [](const MSInterpolationCurve& self)
        {
        return MSInterpolationCurve(self);
        });
    }