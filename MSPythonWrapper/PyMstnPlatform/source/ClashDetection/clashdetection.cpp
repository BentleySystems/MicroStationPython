/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\ClashDetection\clashdetection.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <ClashDetection/ClashDetection.h>

USING_NAMESPACE_BENTLEY_CLASHDETECTION;

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ClashDetection(py::module_& m)
    {
    //===================================================================================
    // enum ClashStatus
    py::enum_< ClashStatus>(m, "ClashStatus", py::arithmetic())
        .value("eCLASHSTATUS_NotInRange", CLASHSTATUS_NotInRange)
        .value("eCLASHSTATUS_Collision", CLASHSTATUS_Collision)
        .value("eCLASHSTATUS_Clearance", CLASHSTATUS_Clearance)
        .value("eCLASHSTATUS_Error", CLASHSTATUS_Error)
        .export_values();

    //===================================================================================
    // enum ClashCollectStatus
    py::enum_< ClashCollectStatus>(m, "ClashCollectStatus", py::arithmetic())
        .value("eCLASHCOLLECT_Success", CLASHCOLLECT_Success)
        .value("eCLASHCOLLECT_Error", CLASHCOLLECT_Error)
        .value("eCLASHCOLLECT_NoGeometry", CLASHCOLLECT_NoGeometry)
        .export_values();

    //===================================================================================
    // struct IClashData
    py::class_< IClashData, std::unique_ptr<IClashData, py::nodelete> > c2(m, "IClashData");

    //===================================================================================
    // struct ClashDetector
    py::class_< ClashDetector, ClashDetectorPtr> c3(m, "ClashDetector");

    c3.def_static("NoClearance", &ClashDetector::NoClearance);

    c3.def("CollectGeometry", [] (ClashDetector& self, DisplayPathCR displayPath, double offset)
           {
           ClashCollectStatus status;
           auto retVal = self.CollectGeometry(displayPath, &status, offset);
           return py::make_tuple(retVal, py::cast(retVal, py::return_value_policy::reference_internal));
           }, "displayPath"_a, "offset"_a = 0);

    c3.def("CollectGeometry", [] (ClashDetector& self, ElementHandleCR eh, double offset)
           {
           ClashCollectStatus status;
           auto retVal = self.CollectGeometry(eh, &status, offset);
           return py::make_tuple(retVal, py::cast(retVal, py::return_value_policy::reference_internal));
           }, "eh"_a, "offset"_a = 0);

    c3.def("Clear", &ClashDetector::Clear);

    c3.def("ComputeClosestApproach", [] (ClashDetector& self, IClashDataCP object1, IClashDataCP object2, double maxClearance)
           {
           double outClearance = 0;
           auto retVal = self.ComputeClosestApproach(outClearance, object1, object2, maxClearance);
           return py::make_tuple(retVal, outClearance);
           }, "object1"_a, "object2"_a, "maxClearance"_a);

    c3.def("ComputeClosestApproachToPosition", [] (ClashDetector& self, IClashDataCP object1, DPoint3dCR positionUOR, double maxClearance)
           {
           double outClearance = 0;
           auto retVal = self.ComputeClosestApproachToPosition(outClearance, object1, positionUOR, maxClearance);
           return py::make_tuple(retVal, outClearance);
           }, "object1"_a, "positionUOR"_a, "maxClearance"_a);

    c3.def_static("CreateClashDetector", &ClashDetector::CreateClashDetector, "viewport"_a);

    }