/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\geopoint.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Geom/GeoPoint.h>

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       9/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_GeoPoint(py::module_& m)
    {
    //===================================================================================
    // struct GeoPoint
    py::class_<GeoPoint> c0(m, "GeoPoint");
    py::bind_vector< GeoPointArray >(m, "GeoPointArray", py::module_local(false));

    c0.def_readwrite("longitude", &GeoPoint::longitude);
    c0.def_readwrite("latitude", &GeoPoint::latitude);
    c0.def_readwrite("elevation", &GeoPoint::elevation);
    c0.def(py::init<>());
    c0.def("Init", &GeoPoint::Init, "longitudeValue"_a, "latitudeValue"_a, "elevationValue"_a);
    c0.def("__copy__", [] (const GeoPoint& self) { return GeoPoint(self); });
    
    //===================================================================================
    // struct GeoPoint2d
    py::class_<GeoPoint2d> c1(m, "GeoPoint2d");
    py::bind_vector< GeoPoint2dArray >(m, "GeoPoint2dArray", py::module_local(false));

    c1.def_readwrite("longitude", &GeoPoint2d::longitude);
    c1.def_readwrite("latitude", &GeoPoint2d::latitude);
    c1.def(py::init<>());
    c1.def("Init", &GeoPoint2d::Init, "longitudeValue"_a, "latitudeValue"_a);
    c1.def("__copy__", [] (const GeoPoint2d& self) { return GeoPoint2d(self); });

    //===================================================================================
    // struct ReprojectStatus
    py::enum_<ReprojectStatus>(m, "ReprojectStatus")
        .value("eREPROJECT_Success", ReprojectStatus::REPROJECT_Success)
        .value("eREPROJECT_CSMAPERR_OutOfUsefulRange",ReprojectStatus::REPROJECT_CSMAPERR_OutOfUsefulRange)
        .value("eREPROJECT_CSMAPERR_OutOfMathematicalDomain",ReprojectStatus::REPROJECT_CSMAPERR_OutOfMathematicalDomain)
        .value("eREPROJECT_CSMAPERR_DatumConverterNotSet", ReprojectStatus::REPROJECT_CSMAPERR_DatumConverterNotSet)
        .value("eREPROJECT_CSMAPERR_VerticalDatumConversionError", ReprojectStatus::REPROJECT_CSMAPERR_VerticalDatumConversionError)
        .value("eREPROJECT_CSMAPERR_Error", ReprojectStatus::REPROJECT_CSMAPERR_Error)
        .value("eREPROJECT_BadArgument", ReprojectStatus::REPROJECT_BadArgument)
        .value("eREPROJECT_NoChange", ReprojectStatus::REPROJECT_NoChange)
        .value("eREPROJECT_StrokeError", ReprojectStatus::REPROJECT_StrokeError)
        .value("eREPROJECT_DataError", ReprojectStatus::REPROJECT_DataError)
        .value("eREPROJECT_DontValidateRange", ReprojectStatus::REPROJECT_DontValidateRange)
        .value("eREPROJECT_GeoCoordNotInitialized", ReprojectStatus::REPROJECT_GeoCoordNotInitialized)
        .value("eREPROJECT_InvalidCoordSys", ReprojectStatus::REPROJECT_InvalidCoordSys)
        .export_values();
    }
