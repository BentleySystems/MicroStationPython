/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\hitpath.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/HitPath.h>



static const char * __doc_Bentley_DgnPlatform_HitPath_GetDimensionParameters =R"doc(Get the parameters from a Hitpath, if it is a hit of a Dimension.

Parameter ``partName``:
    Complete part identifier for part of dimension located, use
    ADIM_GETTYPE, ADIM_GETSUB and ADIM_GETSEG to decompose.

Parameter ``pointNo``:
    Closest point on dimension element.

Parameter ``segment``:
    Selected dimension segment.

Parameter ``partType``:
    Type of selected part of dim, one of ADTYPE_xxx defined in
    mdldim.h.

Parameter ``partSubType``:
    Sub Type of selected part of dim, one of ADSUB_xxx defined in
    mdldim.h.

Returns:
    SUCCESS or ERROR)doc";

static const char * __doc_Bentley_DgnPlatform_HitPath_GetBSplineParameters =R"doc(Get the parameters from a Hitpath, if it is a hit of a Bspline

Parameter ``u``:
    U

Parameter ``v``:
    V

Returns:
    SUCCESS or ERROR)doc";

static const char * __doc_Bentley_DgnPlatform_HitPath_GetLinearParameters =R"doc(Get the parameters from a HitPath, if it is a hit of a linear element

Parameter ``hitSeg``:
    The coordinates of the segment on the element that caused the hit.

Parameter ``vertex``:
    The vertex number of the closest vertex to the test point.

Parameter ``segmentNumber``:
    The segment number of hitSeg.

Returns:
    SUCCESS or ERROR)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_HitPath(py::module_& m)
    {
    //===================================================================================
    // enum class HitPriority
    py::enum_< HitPriority>(m, "HitPriority")
        .value("eHighest", HitPriority::Highest)
        .value("eVertex", HitPriority::Vertex)
        .value("eOrigin", HitPriority::Origin)
        .value("eCellOrigin", HitPriority::CellOrigin)
        .value("eEdge", HitPriority::Edge)
        .value("eCompound", HitPriority::Compound)
        .value("eTestBox", HitPriority::TestBox)
        .value("eInterior", HitPriority::Interior)
        .export_values();

    //===================================================================================
    // enum class HitSource
    py::enum_< HitSource>(m, "HitSource")
        .value("eNone", HitSource::None)
        .value("eFromUser", HitSource::FromUser)
        .value("eMotionLocate", HitSource::MotionLocate)
        .value("eAccuSnap", HitSource::AccuSnap)
        .value("eTentativeSnap", HitSource::TentativeSnap)
        .value("eDataPoint", HitSource::DataPoint)
        .value("eApplication", HitSource::Application)
        .value("eEditAction", HitSource::EditAction)
        .value("eEditActionSS", HitSource::EditActionSS)
        .export_values();

    //===================================================================================
    // enum class HitGeomType
    py::enum_< HitGeomType>(m, "HitGeomType")
        .value("eNone", HitGeomType::None)
        .value("ePoint", HitGeomType::Point)
        .value("eSegment", HitGeomType::Segment)
        .value("eCurve", HitGeomType::Curve)
        .value("eArc", HitGeomType::Arc)
        .value("eSurface", HitGeomType::Surface)
        .export_values();


    //===================================================================================
    // struct SelectionPath
    py::class_< SelectionPath, RefCountedPtr<SelectionPath>, DisplayPath> c1(m, "SelectionPath");


    //===================================================================================
    // struct HitPath
    py::class_<HitPath, RefCountedPtr<HitPath>, SelectionPath> c4(m, "HitPath");

    c4.def("GetLinearParameters", [] (HitPathCR self)
           {
           DSegment3d seg;
           int vertex = 0;
           int segmentNumber = 0;
           auto retVal = self.GetLinearParameters(&seg, &vertex, &segmentNumber);
           return py::make_tuple(retVal, seg, vertex, segmentNumber);
           }, DOC(Bentley, DgnPlatform, HitPath, GetLinearParameters));

    c4.def("GetMultilineParameters", [] (HitPathCR self)
           {
           DSegment3d seg;
           int vertex = 0;
           int segmentNumber = 0;
           int lineNumber = 0;
           int capNumber = 0;
           int patIndex = 0;
           auto retVal = self.GetMultilineParameters(&seg, &vertex, &segmentNumber, &lineNumber, &capNumber, &patIndex);
           return py::make_tuple(retVal, seg, vertex, segmentNumber, lineNumber, capNumber, patIndex);
           });

    c4.def("GetBSplineParameters", [] (HitPathCR self)
           {
           double u = 0, v = 0;
           auto retVal = self.GetBSplineParameters(&u, &v);
           return py::make_tuple(retVal, u, v);
           }, DOC(Bentley, DgnPlatform, HitPath, GetBSplineParameters));

    c4.def("GetDimensionParameters", [] (HitPathCR self)
           {
           UInt32 partName, segment;
           int pointNo;
           DimensionPartType partType;
           DimensionPartSubType partSubType;
           auto retVal = self.GetDimensionParameters(&partName, &pointNo, &segment, &partType, &partSubType);
           return py::make_tuple(retVal, partName, pointNo, segment, partType, partSubType);
           }, DOC(Bentley, DgnPlatform, HitPath, GetDimensionParameters));

    }