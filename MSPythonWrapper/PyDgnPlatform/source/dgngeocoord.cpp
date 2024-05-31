/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgngeocoord.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnGeoCoord/DgnGeoCoord.h>
#include "PyDgnPlatform.h"

using namespace GeoCoordinates;

//=======================================================================================
// Trampoline class for IGeoCoordinateEventHandler.
// @bsiclass                                                                   09/23
//=======================================================================================
struct PyIGeoCoordinateEventHandler : IGeoCoordinateEventHandler
    {
    public:
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       9/2023
        +---------------+---------------+---------------+---------------+---------------+------*/    
        virtual StatusInt   BeforeCoordinateSystemChanged(DgnGCSP oldGCS, DgnGCSP newGCS, DgnModelRefP modelRef, bool primaryCoordSys, bool writingToFile, bool reprojectData) override
            { PYBIND11_OVERRIDE_PURE_EXR(StatusInt, IGeoCoordinateEventHandler, BeforeCoordinateSystemChanged, SUCCESS, oldGCS, newGCS, modelRef, primaryCoordSys, writingToFile, reprojectData); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       9/2023
        +---------------+---------------+---------------+---------------+---------------+------*/    
        virtual void        AfterCoordinateSystemChanged(DgnGCSP oldGCS, DgnGCSP newGCS, DgnModelRefP modelRef, bool primaryCoordSys, bool writtenToFile, bool reprojectData) override
            { PYBIND11_OVERRIDE_PURE_EX(void, IGeoCoordinateEventHandler, AfterCoordinateSystemChanged, oldGCS, newGCS, modelRef, primaryCoordSys, writtenToFile, reprojectData); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       9/2023
        +---------------+---------------+---------------+---------------+---------------+------*/    
        virtual StatusInt   BeforeCoordinateSystemDeleted(DgnGCSP currentGCS, DgnModelRefP modelRef, bool primaryCoordSys) override
            { PYBIND11_OVERRIDE_PURE_EXR(StatusInt, IGeoCoordinateEventHandler, BeforeCoordinateSystemDeleted, SUCCESS, currentGCS, modelRef, primaryCoordSys); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       9/2023
        +---------------+---------------+---------------+---------------+---------------+------*/    
        virtual void        AfterCoordinateSystemDeleted(DgnGCSP currentGCS, DgnModelRefP modelRef, bool primaryCoordSys) override
            { PYBIND11_OVERRIDE_PURE_EX(void, IGeoCoordinateEventHandler, AfterCoordinateSystemDeleted, currentGCS, modelRef, primaryCoordSys); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       9/2023
        +---------------+---------------+---------------+---------------+---------------+------*/    
        virtual void        BeforeReferenceGeoCoordinationChanged(DgnModelRefP modelRef, GeoCoordinationState oldState, GeoCoordinationState newState) override
            { PYBIND11_OVERRIDE_PURE_EX(void, IGeoCoordinateEventHandler, BeforeReferenceGeoCoordinationChanged, modelRef, oldState, newState); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       9/2023
        +---------------+---------------+---------------+---------------+---------------+------*/    
        virtual void        AfterReferenceGeoCoordinationChanged(DgnModelRefP modelRef, GeoCoordinationState oldState, GeoCoordinationState newState) override
            { PYBIND11_OVERRIDE_PURE_EX(void, IGeoCoordinateEventHandler, AfterReferenceGeoCoordinationChanged, modelRef, oldState, newState); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       9/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnGCS(py::module_& m)
    {
    //===================================================================================
    // Enum GeoCoordinationState
    py::enum_<GeoCoordinationState>(m, "GeoCoordinationState")
        .value("eNoGeoCoordination", GeoCoordinationState::NoGeoCoordination)
        .value("eReprojected", GeoCoordinationState::Reprojected)
        .value("eAECTransform", GeoCoordinationState::AECTransform)
        .export_values();

    //===================================================================================
    // Enum GeoCoordInterpretation
    py::enum_<GeoCoordInterpretation>(m, "GeoCoordInterpretation")
        .value("eCartesian", GeoCoordInterpretation::Cartesian)
        .value("eXYZ", GeoCoordInterpretation::XYZ)
        .export_values();

    //===================================================================================
    // interface IGeoCoordinateEventHandler
    py::class_< IGeoCoordinateEventHandler, PyIGeoCoordinateEventHandler> c0(m, "IGeoCoordinateEventHandler");
    py::bind_vector< T_GeoCoordEventHandlers>(m, "GeoCoordEventHandlersVector", py::module_local(false));

    c0.def(py::init<>());
    c0.def("BeforeCoordinateSystemChanged", &IGeoCoordinateEventHandler::BeforeCoordinateSystemChanged, "oldGCS"_a, "newGCS"_a, "modelRef"_a, "primaryCoordSys"_a, "writingToFile"_a, "reprojectData"_a);
    c0.def("AfterCoordinateSystemChanged",  &IGeoCoordinateEventHandler::AfterCoordinateSystemChanged,  "oldGCS"_a, "newGCS"_a, "modelRef"_a, "primaryCoordSys"_a, "writingToFile"_a, "reprojectData"_a);
    c0.def("BeforeCoordinateSystemDeleted", &IGeoCoordinateEventHandler::BeforeCoordinateSystemDeleted, "currentGCS"_a, "modelRef"_a, "primaryCoordSys"_a);
    c0.def("AfterCoordinateSystemDeleted",  &IGeoCoordinateEventHandler::AfterCoordinateSystemDeleted, "currentGCS"_a, "modelRef"_a, "primaryCoordSys"_a);
    c0.def("BeforeReferenceGeoCoordinationChanged", &IGeoCoordinateEventHandler::BeforeReferenceGeoCoordinationChanged, "modelRef"_a, "oldState"_a, "newState"_a);
    c0.def("AfterReferenceGeoCoordinationChanged", &IGeoCoordinateEventHandler::AfterReferenceGeoCoordinationChanged, "modelRef"_a, "oldState"_a, "newState"_a);

    //===================================================================================
    // struct DgnGCS
    py::class_< DgnGCS, BaseGCS, DgnGCSPtr, DgnModelAppData> c1(m, "DgnGCS");

    c1.def_static("CreateGCS", py::overload_cast<WCharCP, DgnModelRefP>(&DgnGCS::CreateGCS), "coordinateSystemName"_a, "modelRef"_a);
    c1.def_static("CreateGCS", py::overload_cast<DgnModelRefP>(&DgnGCS::CreateGCS), "modelRef"_a);
    c1.def_static("CreateGCS", py::overload_cast<BaseGCSCP, DgnModelRefP>(&DgnGCS::CreateGCS), "baseGCS"_a, "modelRef"_a);
    c1.def_static("CreateGCS", py::overload_cast<DgnGCSCR>(&DgnGCS::CreateGCS), "dgnGcs"_a);

    c1.def("CartesianFromUors", &DgnGCS::CartesianFromUors, "outCartesian"_a, "inUors"_a);
    c1.def("CartesianFromUors2D", &DgnGCS::CartesianFromUors2D, "outCartesian"_a, "inUors"_a);
    c1.def("UorsFromCartesian", &DgnGCS::UorsFromCartesian, "outUors"_a, "inCartesian"_a);
    c1.def("UorsFromCartesian2D", &DgnGCS::UorsFromCartesian2D, "outUors"_a, "inCartesian"_a);
    c1.def("UorsFromLatLong", &DgnGCS::UorsFromLatLong, "outUors"_a, "inLatLong"_a);
    c1.def("LatLongFromUors", &DgnGCS::LatLongFromUors, "outLatLong"_a, "inUors"_a);
    c1.def("LatLongFromUorsXYZ", &DgnGCS::LatLongFromUorsXYZ, "outLatLong"_a, "inUors"_a);

    c1.def("ReprojectUors", [](DgnGCS const& self, DPoint3dCP inUors, int numPoints, DgnGCSCR destMstnGCS)
        {
        ReprojectStatus status;
        DPoint3d outUorsDest; 
        GeoPoint outLatLongDest, outLatLongSrc;

        status = self.ReprojectUors(&outUorsDest, &outLatLongDest, &outLatLongSrc, inUors, numPoints, destMstnGCS);
        return py::make_tuple(status, outUorsDest, outLatLongDest, outLatLongSrc);
        }, "inUors"_a, "numPoints"_a, "destMstnGCS"_a);

    c1.def("ReprojectUors", [](DgnGCS const & self, DPoint3dCP inUors, int numPoints, GeoCoordInterpretation interpretation, DgnGCSCR destMstnGCS)
        {
        ReprojectStatus status;
        DPoint3d outUorsDest; 
        GeoPoint outLatLongDest, outLatLongSrc;

        status = self.ReprojectUors(&outUorsDest, &outLatLongDest, &outLatLongSrc, inUors, numPoints, interpretation, destMstnGCS);
        return py::make_tuple(status, outUorsDest, outLatLongDest, outLatLongSrc);
        }, "inUors"_a, "numPoints"_a, "interpretation"_a, "destMstnGCS"_a);

    c1.def("UorsFromLatLong2D", &DgnGCS::UorsFromLatLong2D, "outUors"_a, "inLatLong"_a);
    c1.def("LatLongFromUors2D", &DgnGCS::LatLongFromUors2D, "outLatLong"_a, "inUors"_a);

    c1.def("ReprojectUors2D", [](DgnGCS& self, DPoint2dCP inUors, int numPoints, DgnGCSCR destMstnGCS)
        {
        ReprojectStatus status;
        DPoint2d outUorsDest; 
        GeoPoint2d outLatLongDest, outLatLongSrc;

        status = self.ReprojectUors2D(&outUorsDest, &outLatLongDest, &outLatLongSrc, inUors, numPoints, destMstnGCS);
        return py::make_tuple(status, outUorsDest, outLatLongDest, outLatLongSrc);
        }, "inUors"_a, "numPoints"_a, "destMstnGCS"_a);

    c1.def("GetLinearTransformToBaseGCS", [](DgnGCS& self, DRange3dCR extent, BaseGCSCR destBaseGCS)
        {
        ReprojectStatus status;
        Transform  outTransform;
        double maxError, meanError;

        status = self.GetLinearTransformToBaseGCS(&outTransform, extent, destBaseGCS, &maxError, &meanError);
        return py::make_tuple(status, outTransform, maxError, meanError);
        }, "extent"_a, "destBaseGCS"_a);

    c1.def("GetLocalTransform", py::overload_cast<TransformP, DPoint3dCR, DPoint3dCP, bool, bool, DgnGCSCR>(&DgnGCS::GetLocalTransform, py::const_),
                                "outTransform"_a, "elementOrigin"_a, "extent"_a, "doRotate"_a, "doScale"_a, "destMstnGCS"_a);

    c1.def("GetLocalTransform", py::overload_cast<TransformP, DPoint3dCR, DPoint3dCP, bool, bool, GeoCoordInterpretation, DgnGCSCR>(&DgnGCS::GetLocalTransform, py::const_),
        "outTransform"_a, "elementOrigin"_a, "extent"_a, "doRotate"_a, "doScale"_a, "interpretation"_a, "destMstnGCS"_a);

    c1.def("GetProjectionName", &DgnGCS::GetProjectionName, "outputBuffer"_a);
    c1.def("GetDisplayName", &DgnGCS::GetDisplayName, "outputBuffer"_a);

    c1.def("ToModel", &DgnGCS::ToModel, "modelRef"_a, "primaryCoordSys"_a, "writeToFile"_a, "reprojectData"_a, "reportProblems"_a);

    c1.def_static("FromModel", &DgnGCS::FromModel, "modelRef"_a, "primaryCoordSys"_a);
    c1.def_static("DeleteFromModel", &DgnGCS::DeleteFromModel, "modelRef"_a, "primaryCoordSys"_a);
    c1.def_static("FromCache", &DgnGCS::FromCache, "cache"_a, "primaryCoordSys"_a);
    c1.def_static("ReloadGeoReferences", &DgnGCS::ReloadGeoReferences, "modelRef"_a);

    c1.def_static("SetEventHandler", &DgnGCS::SetEventHandler, "handler"_a);
    c1.def_static("RemoveEventHandler", &DgnGCS::RemoveEventHandler, "handler"_a);

    c1.def("GetPaperScale", &DgnGCS::GetPaperScale);
    c1.def("SetPaperScale", &DgnGCS::SetPaperScale, "paperScale"_a, "modelRef"_a);
    }
