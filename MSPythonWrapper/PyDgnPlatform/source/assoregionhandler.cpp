/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\assocregionhandler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/AssocRegionHandler.h>

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_AssocRegionHandler(py::module_& m)
    {
    //===================================================================================
    // enum class RegionLoops
    py::enum_<RegionLoops>(m, "RegionLoops")
        .value("eIgnore", RegionLoops::Ignore)
        .value("eOuter", RegionLoops::Outer)
        .value("eAlternating", RegionLoops::Alternating)
        .export_values();

    //===================================================================================
    // enum class RegionType
    py::enum_< RegionType>(m, "RegionType")
        .value("eFlood", RegionType::Flood)
        .value("eUnion", RegionType::Union)
        .value("eIntersection", RegionType::Intersection)
        .value("eDifference", RegionType::Difference)
        .value("eExclusiveOr", RegionType::ExclusiveOr)
        .export_values();

    //===================================================================================
    // enum RegionConstants
    py::enum_< RegionConstants>(m, "RegionConstants")
        .value("eMAX_FloodSeedPoints", MAX_FloodSeedPoints);

    //===================================================================================
    // struct RegionParams
    py::class_< RegionParams> c1(m, "RegionParams");

    c1.def(py::init<>());

    c1.def_property("Type", &RegionParams::GetType, &RegionParams::SetType);
    c1.def("GetType", &RegionParams::GetType);
    c1.def("SetType", &RegionParams::SetType, "type"_a);

    c1.def_property("Associative", &RegionParams::GetAssociative, &RegionParams::SetAssociative);
    c1.def("GetAssociative", &RegionParams::GetAssociative);
    c1.def("SetAssociative", &RegionParams::SetAssociative, "yesNo"_a);

    c1.def_property("InvisibleBoundary", &RegionParams::GetInvisibleBoundary, &RegionParams::SetInvisibleBoundary);
    c1.def("GetInvisibleBoundary", &RegionParams::GetInvisibleBoundary);
    c1.def("SetInvisibleBoundary", &RegionParams::SetInvisibleBoundary, "yesNo"_a);

    c1.def("GetFlattenBoundary", &RegionParams::GetFlattenBoundary, "flatten"_a);
    c1.def("SetFlattenBoundary", &RegionParams::SetFlattenBoundary, "yesNo"_a, "flatten"_a);

    c1.def_property("Dirty", &RegionParams::GetDirty, &RegionParams::SetDirty);
    c1.def("GetDirty", &RegionParams::GetDirty);
    c1.def("SetDirty", &RegionParams::SetDirty, "yesNo"_a);

    c1.def("SetFloodParams", &RegionParams::SetFloodParams, "regionLoops"_a, "gapTolerance"_a);
    c1.def("SetInteriorText", &RegionParams::SetInteriorText, "interiorText"_a, "textMarginFactor"_a);
    
    c1.def("GetFloodParams", [] (RegionParams const& self)
           {
           double gapTolerance = 0;
           auto retVal = self.GetFloodParams(&gapTolerance);
           return py::make_tuple(retVal, gapTolerance);
           });

    c1.def("GetInteriorText", [] (RegionParams const& self)
           {
           double textMarginFactor = 0;
           auto retVal = self.GetInteriorText(&textMarginFactor);
           return py::make_tuple(retVal, textMarginFactor);
           });    

    //===================================================================================
    // struct IAssocRegionQuery
    py::class_<IAssocRegionQuery, std::unique_ptr<IAssocRegionQuery, py::nodelete>
    > c2(m, "IAssocRegionQuery");
    if (true)
        {
        py::class_<IAssocRegionQuery::LoopData> c2_1(c2, "LoopData");
        py::bind_vector< bvector<IAssocRegionQuery::LoopData> >(m, "LoopDataArray", py::module_local(false));

        c2_1.def(py::init<>());
        c2_1.def_readwrite("loopCode", &IAssocRegionQuery::LoopData::m_loopCode);
        c2_1.def_readwrite("loopRoots", &IAssocRegionQuery::LoopData::m_loopRoots);
        }
    
    c2.def("GetParams", &IAssocRegionQuery::GetParams, "eh"_a, "params"_a);
    c2.def("GetSeedPoints", &IAssocRegionQuery::GetSeedPoints, "eh"_a, "points"_a);
    c2.def("GetRoots", &IAssocRegionQuery::GetRoots, "eh"_a, "roots"_a);
    c2.def("GetLoopData", &IAssocRegionQuery::GetLoopData, "eh"_a, "loopData"_a);            
        
    //===================================================================================
    // struct AssocRegionCellHeaderHandler
    py::class_< AssocRegionCellHeaderHandler
        , Type2Handler
        , ICurvePathEdit
        , IAssocRegionQuery
        , IAreaFillPropertiesEdit
    > c3(m, "AssocRegionCellHeaderHandler");

    c3.def_static("IsValidRegionBoundaryType", &AssocRegionCellHeaderHandler::IsValidRegionBoundaryType, "eh"_a);
    c3.def_static("SetLoopRoots", &AssocRegionCellHeaderHandler::SetLoopRoots, "eeh"_a, "boundaryRoots"_a, "numBoundaryRoots"_a);
    c3.def_static("SetLoopOedCode", &AssocRegionCellHeaderHandler::SetLoopOedCode, "eeh"_a, "loopCode"_a);

    c3.def_static("CreateAssocRegionElement", &AssocRegionCellHeaderHandler::CreateAssocRegionElement,
                  "eeh"_a, "boundary"_a, "boundaryRoots"_a, "numBoundaryRoots"_a, "seedPoints"_a, "numSeedPoints"_a, "params"_a, "cellName"_a);

    c3.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr<AssocRegionCellHeaderHandler, py::nodelete>(&AssocRegionCellHeaderHandler::GetInstance()); });
    c3.def_static("GetInstance", &AssocRegionCellHeaderHandler::GetInstance, py::return_value_policy::reference);
    }

