/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\dsegment1d.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"



static const char * __doc_Bentley_Geom_DSegment1d_ReverseInPlace =R"doc(reverse the instance in place)doc";

static const char * __doc_Bentley_Geom_DSegment1d_Reverse =R"doc(return reverse of the instance)doc";

static const char * __doc_Bentley_Geom_DSegment1d_BetweenFractions =R"doc(Return a segment with endpoints at fractions of input segment.)doc";

static const char * __doc_Bentley_Geom_DSegment1d_NonZeroDirectedOverlap =R"doc(Find overlap of primary with clipper, treating single point
intersection as empty. If empty or single point, return false and
primary unchanged. If nonempty, result maintains orientation of
primary.)doc";

static const char * __doc_Bentley_Geom_DSegment1d_DirectedOverlap =R"doc(Find overlap of primary with clipper. If empty, return false and
primary unchanged. If nonempty, result maintains orientation of
primary. Note that single point intersection is non-empty.)doc";

static const char * __doc_Bentley_Geom_DSegment1d_Delta =R"doc(Return signed distance from start to end)doc";

static const char * __doc_Bentley_Geom_DSegment1d_Length =R"doc(Return absolute length of the segment.)doc";

static const char * __doc_Bentley_Geom_DSegment1d_PointToFraction =R"doc(Find fractional parameter for specified coordinate.

:returns:
    false if endpoints are identical.)doc";

static const char * __doc_Bentley_Geom_DSegment1d_FractionToPoint =R"doc(Return coordinate at fractional parameter from start to end.)doc";

static const char * __doc_Bentley_Geom_DSegment1d_IsReversed =R"doc(Exact equality test for reversed coordinates.)doc";

static const char * __doc_Bentley_Geom_DSegment1d_IsEqual =R"doc(Exact equality test.)doc";

static const char * __doc_Bentley_Geom_DSegment1d_IsStrictInterior =R"doc(Test if the EndPointProduct is strictly negative)doc";

static const char * __doc_Bentley_Geom_DSegment1d_EndPointProduct =R"doc(return (x-x0) * (x-x1). This is negative " inside " the interval)doc";

static const char * __doc_Bentley_Geom_DSegment1d_SetEnd =R"doc(Change end coordinate.)doc";

static const char * __doc_Bentley_Geom_DSegment1d_GetEnd =R"doc(Return end coordinate.)doc";

static const char * __doc_Bentley_Geom_DSegment1d_SetStart =R"doc(Change start coordinate.)doc";

static const char * __doc_Bentley_Geom_DSegment1d_GetStart =R"doc(Return start coordinate.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DSegment1d(py::module_& m)
    {
    //===================================================================================
    // struct DSegment1d
    py::class_<DSegment1d> c1(m, "DSegment1d");
    py::bind_vector<DSegment1dArray>(m, "DSegment1dArray", py::module_local(false));

    c1.def(py::init<>());
    c1.def(py::init<double>(), "x"_a);
    c1.def(py::init<double, double>(), "x0"_a, "x1"_a);   

    c1.def_property("Start", &DSegment1d::GetStart, &DSegment1d::SetStart);
    c1.def("GetStart", &DSegment1d::GetStart, DOC(Bentley, Geom, DSegment1d, GetStart));
    c1.def("SetStart", &DSegment1d::SetStart, "x"_a, DOC(Bentley, Geom, DSegment1d, SetStart));

    c1.def_property("End", &DSegment1d::GetEnd, &DSegment1d::SetEnd);
    c1.def("GetEnd", &DSegment1d::GetEnd, DOC(Bentley, Geom, DSegment1d, GetEnd));
    c1.def("SetEnd", &DSegment1d::SetEnd, "x"_a, DOC(Bentley, Geom, DSegment1d, SetEnd));

    c1.def("EndPointProduct", &DSegment1d::EndPointProduct, "x"_a, DOC(Bentley, Geom, DSegment1d, EndPointProduct));
    c1.def("IsStrictInterior", &DSegment1d::IsStrictInterior, "x"_a, DOC(Bentley, Geom, DSegment1d, IsStrictInterior));

    c1.def("IsEqual", &DSegment1d::IsEqual, "other"_a, DOC(Bentley, Geom, DSegment1d, IsEqual));            
    c1.def("IsReversed", &DSegment1d::IsReversed, "other"_a, DOC(Bentley, Geom, DSegment1d, IsReversed));

    c1.def("FractionToPoint", &DSegment1d::FractionToPoint, "fraction"_a, DOC(Bentley, Geom, DSegment1d, FractionToPoint));
            
    c1.def("PointToFraction", [] (DSegment1dCR self, double point)
        {
        double fraction = 0.0;
        bool bOk = self.PointToFraction(point, fraction);
        return py::make_tuple(bOk, fraction);
        }, "point"_a, DOC(Bentley, Geom, DSegment1d, PointToFraction));

    c1.def("Length", &DSegment1d::Length, DOC(Bentley, Geom, DSegment1d, Length));            
    c1.def("Delta", &DSegment1d::Delta, DOC(Bentley, Geom, DSegment1d, Delta));

    c1.def_static("DirectedOverlap", &DSegment1d::DirectedOverlap, "primary"_a, "clipper"_a, "result"_a, DOC(Bentley, Geom, DSegment1d, DirectedOverlap));            
    c1.def_static("NonZeroDirectedOverlap", &DSegment1d::NonZeroDirectedOverlap, "primary"_a, "clipper"_a, "result"_a, DOC(Bentley, Geom, DSegment1d, NonZeroDirectedOverlap));

    c1.def("BetweenFractions", &DSegment1d::BetweenFractions, "f0"_a, "f1"_a, DOC(Bentley, Geom, DSegment1d, BetweenFractions));            
    c1.def("Reverse", &DSegment1d::Reverse, DOC(Bentley, Geom, DSegment1d, Reverse));            
    c1.def("ReverseInPlace", &DSegment1d::ReverseInPlace, DOC(Bentley, Geom, DSegment1d, ReverseInPlace));

    c1.def("__repr__", [] (DSegment1d& self)
           {
           return "(Start:{}, End:{})"_s.format(self.GetStart(), self.GetEnd());
           });

    c1.def("__copy__", [](DSegment1d& self)
        {
        return DSegment1d(self);
        });
    }