/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\iglobalposition.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/IGlobalPosition.h>



//=======================================================================================
// Trampoline class for IGlobalPositionSource
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyGlobalPositionSource : IGlobalPositionSource
    {
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/        
    virtual bool GPSAvailable() override
        { PYBIND11_OVERRIDE_PURE_EXR(bool, IGlobalPositionSource, GPSAvailable, false, ); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt GetLatestPositionData(GlobalPositionData* data) override
        { PYBIND11_OVERRIDE_PURE(StatusInt, IGlobalPositionSource, GetLatestPositionData, ERROR, data); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_IGlobalPosition(py::module_& m)
    {
    //===================================================================================
    // struct GlobalPositionData
    py::class_<GlobalPositionData> c1(m, "GlobalPositionData");

    c1.def(py::init<>());
    c1.def_readwrite("longitude", &GlobalPositionData::longitude);
    c1.def_readwrite("latitude", &GlobalPositionData::latitude);
    c1.def_readwrite("elevation", &GlobalPositionData::elevation);
    c1.def_readwrite("UTCTicks", &GlobalPositionData::UTCTicks);
    c1.def_readwrite("fixDimension", &GlobalPositionData::fixDimension);
    c1.def_readwrite("PDOP", &GlobalPositionData::PDOP);
    c1.def_readwrite("HDOP", &GlobalPositionData::HDOP);
    c1.def_readwrite("VDOP", &GlobalPositionData::VDOP);
    c1.def_readwrite("heading", &GlobalPositionData::heading);
    c1.def_readwrite("velocity", &GlobalPositionData::velocity);

    //===================================================================================
    // struct IGlobalPositionSource
    py::class_< IGlobalPositionSource, std::unique_ptr<IGlobalPositionSource, py::nodelete>, IPyGlobalPositionSource> c2(m, "IGlobalPositionSource");

    c2.def(py::init<>());
    c2.def("GPSAvailable", &IGlobalPositionSource::GPSAvailable);
    c2.def("GetLatestPositionData", &IGlobalPositionSource::GetLatestPositionData, "data"_a);
    c2.def_static("GetGlobalPositionSource", [] () { return std::unique_ptr< IGlobalPositionSource, py::nodelete>(mdlSystem_getGlobalPositionSource()); });
 
    }