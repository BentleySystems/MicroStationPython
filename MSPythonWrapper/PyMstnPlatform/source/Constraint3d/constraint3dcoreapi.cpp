/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\Constraint3d\constraint3dcoreapi.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Constraint3d/Constraint3dCoreApi.h>

USING_NAMESPACE_CONSTRAINT3D;

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_Constraint3dCoreAPI(py::module_& m)
    {
    //===================================================================================
    // enum class Constraint3dStorageVersion
    py::enum_< Constraint3dStorageVersion>(m, "Constraint3dStorageVersion")
        .value("eInitial", Constraint3dStorageVersion::Initial)
        .value("eLatest", Constraint3dStorageVersion::Latest)
        .export_values();

    //===================================================================================
    // enum class Constraint3dXAttributeIndex
    py::enum_< Constraint3dXAttributeIndex>(m, "Constraint3dXAttributeIndex")
        .value("eData", Constraint3dXAttributeIndex::Data)
        .value("eVariableDependency", Constraint3dXAttributeIndex::VariableDependency)
        .export_values();

    //===================================================================================
    // enum class Constraint3dType
    py::enum_< Constraint3dType>(m, "Constraint3dType")
        .value("eDCM3_DISTANCE", Constraint3dType::DCM3_DISTANCE)
        .value("eDCM3_ANGLE", Constraint3dType::DCM3_ANGLE)
        .value("eDCM3_CONCENTRIC", Constraint3dType::DCM3_CONCENTRIC)
        .value("eDCM3_RADIUS", Constraint3dType::DCM3_RADIUS)
        .value("eDCM3_PARALLEL", Constraint3dType::DCM3_PARALLEL)
        .value("eDCM3_PERPENDICULAR", Constraint3dType::DCM3_PERPENDICULAR)
        .value("eDCM3_COINCIDENT", Constraint3dType::DCM3_COINCIDENT)
        .value("eDCM3_TANGENT", Constraint3dType::DCM3_TANGENT)
        .value("eDCM3_MAJOR_RADIUS", Constraint3dType::DCM3_MAJOR_RADIUS)
        .value("eDCM3_MINOR_RADIUS", Constraint3dType::DCM3_MINOR_RADIUS)
        .value("eDCM3_EQUAL_RADIUS", Constraint3dType::DCM3_EQUAL_RADIUS)
        .value("eDCM3_MIDPOINT", Constraint3dType::DCM3_MIDPOINT)
        .value("eDCM3_DEPENDENCE", Constraint3dType::DCM3_DEPENDENCE)
        .value("eDCM3_EQUAL_PARAMETER", Constraint3dType::DCM3_EQUAL_PARAMETER)
        .value("eDCM3_EQUAL_DIRECTION", Constraint3dType::DCM3_EQUAL_DIRECTION)
        .value("eDCM3_EQUAL_CURVATURE", Constraint3dType::DCM3_EQUAL_CURVATURE)
        .value("eDCM3_EQUAL_FIRST_DERIVATIVE", Constraint3dType::DCM3_EQUAL_FIRST_DERIVATIVE)
        .value("eDCM3_EQUAL_SECOND_DERIVATIVE", Constraint3dType::DCM3_EQUAL_SECOND_DERIVATIVE)
        .value("eDCM3_CURVE_LENGTH", Constraint3dType::DCM3_CURVE_LENGTH)
        .value("eDCM3_SYMMETRIC", Constraint3dType::DCM3_SYMMETRIC)
        .value("eDCM3_HALF_ANGLE", Constraint3dType::DCM3_HALF_ANGLE)
        .value("eDCM3_COINCIDENT_AROUND_SPINE", Constraint3dType::DCM3_COINCIDENT_AROUND_SPINE)
        .value("eDCM3_COINCIDENT_WITH_SPINE", Constraint3dType::DCM3_COINCIDENT_WITH_SPINE)
        .value("eDCM3_EQUAL_HALF_ANGLE", Constraint3dType::DCM3_EQUAL_HALF_ANGLE)
        .value("eDCM3_EQUAL_CURVATURE_VECTOR", Constraint3dType::DCM3_EQUAL_CURVATURE_VECTOR)
        .value("eFixed", Constraint3dType::Fixed)
        .value("eUnspecified", Constraint3dType::Unspecified)
        .export_values();

    //===================================================================================
    // enum class SurfaceOrientation
    py::enum_< SurfaceOrientation>(m, "SurfaceOrientation")
        .value("eNotSpecified", SurfaceOrientation::NotSpecified)
        .value("eAligned", SurfaceOrientation::Aligned)
        .value("eAntiAligned", SurfaceOrientation::AntiAligned)
        .export_values();

    //===================================================================================
    // enum class Constraint3dHalfSpace
    py::enum_< Constraint3dHalfSpace>(m, "Constraint3dHalfSpace")
        .value("eNotSpecified", Constraint3dHalfSpace::NotSpecified)
        .value("ePositive", Constraint3dHalfSpace::Positive)
        .value("eNegative", Constraint3dHalfSpace::Negative)
        .export_values();

    //===================================================================================
    // struct SolverGeometry
    py::class_< SolverGeometry, SolverGeometryPtr> c1(m, "SolverGeometry");    

    //===================================================================================
    // struct GeometryId
    py::class_< GeometryId, GeometryIdPtr> c2(m, "GeometryId");
    py::bind_vector<bvector<GeometryIdPtr> >(m, "GeometryIdPtrArray", py::module_local(false));

    if (true)
        {
        //===================================================================================
        // enum class Type
        py::enum_< GeometryId::Type>(c2, "Type")
            .value("eCurve", GeometryId::Type::Curve)
            .value("eFace", GeometryId::Type::Face)
            .value("eElement", GeometryId::Type::Element)
            .value("eEdge", GeometryId::Type::Edge)
            .value("eRegionPlane", GeometryId::Type::RegionPlane)
            .value("eBRepVertex", GeometryId::Type::BRepVertex)
            .value("eCurvePoint", GeometryId::Type::CurvePoint)
            .value("eBCurve", GeometryId::Type::BCurve)
            .value("eFaceAxis", GeometryId::Type::FaceAxis)
            .value("eCurveArcAxis", GeometryId::Type::CurveArcAxis)
            .value("eEdgeArcAxis", GeometryId::Type::EdgeArcAxis)
            .value("eInvalidElement", GeometryId::Type::InvalidElement)
            .export_values();

        //===================================================================================
        // enum class Status
        py::enum_< GeometryId::Status>(c2, "Status")
            .value("eDCM3_G_UNKNOWN", GeometryId::Status::DCM3_G_UNKNOWN)
            .value("eDCM3_G_FIXED", GeometryId::Status::DCM3_G_FIXED)
            .value("eDCM3_G_OVER_DEFINED", GeometryId::Status::DCM3_G_OVER_DEFINED)
            .value("eDCM3_G_NOT_CONSISTENT", GeometryId::Status::DCM3_G_NOT_CONSISTENT)
            .value("eDCM3_G_NOT_CONSISTENT_DIMENSIONS", GeometryId::Status::DCM3_G_NOT_CONSISTENT_DIMENSIONS)
            .value("eDCM3_G_NOT_CONSISTENT_OTHER", GeometryId::Status::DCM3_G_NOT_CONSISTENT_OTHER)
            .value("eDCM3_G_NOT_CONSISTENT_UNKNOWN", GeometryId::Status::DCM3_G_NOT_CONSISTENT_UNKNOWN)
            .value("eDCM3_G_NOT_CHANGED", GeometryId::Status::DCM3_G_NOT_CHANGED)
            .value("eDCM3_G_WELL_DEFINED", GeometryId::Status::DCM3_G_WELL_DEFINED)
            .value("eDCM3_G_UNDER_DEFINED", GeometryId::Status::DCM3_G_UNDER_DEFINED)
            .value("eDCM3_G_WITHIN_BOUNDS", GeometryId::Status::DCM3_G_WITHIN_BOUNDS)
            .export_values();

        //===================================================================================
        // enum class DimensionToComponent
        py::enum_< GeometryId::DimensionToComponent>(c2, "DimensionToComponent")
            .value("eDCM3_DIMENSION_TO_NOT_SPECIFIED", GeometryId::DimensionToComponent::DCM3_DIMENSION_TO_NOT_SPECIFIED)
            .value("eDCM3_DIMENSION_TO_EXTERIOR", GeometryId::DimensionToComponent::DCM3_DIMENSION_TO_EXTERIOR)
            .value("eDCM3_DIMENSION_TO_CENTRE_POINT", GeometryId::DimensionToComponent::DCM3_DIMENSION_TO_CENTRE_POINT)
            .value("eDCM3_DIMENSION_TO_AXIS", GeometryId::DimensionToComponent::DCM3_DIMENSION_TO_AXIS)
            .value("eDCM3_DIMENSION_TO_PLANE", GeometryId::DimensionToComponent::DCM3_DIMENSION_TO_PLANE)
            .value("eDCM3_DIMENSION_TO_SPINE", GeometryId::DimensionToComponent::DCM3_DIMENSION_TO_SPINE)
            .value("eDCM3_DIMENSION_TO_APEX", GeometryId::DimensionToComponent::DCM3_DIMENSION_TO_APEX)
            .export_values();

        //===================================================================================
        // enum class FlagMasks
        py::enum_< GeometryId::FlagMasks>(c2, "FlagMasks", py::arithmetic())
            .value("eFlagMask_ParamX", GeometryId::FlagMask_ParamX)
            .value("eFlagMask_ParamY", GeometryId::FlagMask_ParamY)
            .value("eFlagMask_EntityIndex", GeometryId::FlagMask_EntityIndex)
            .export_values();
        }

    c2.def_property_readonly("Type", &GeometryId::GetType);
    c2.def("GetType", &GeometryId::GetType);

    c2.def_property("Status", &GeometryId::GetStatus, &GeometryId::SetStatus);
    c2.def("GetStatus", &GeometryId::GetStatus);
    c2.def("SetStatus", &GeometryId::SetStatus, "status"_a);

    c2.def_property("ElementRef", &GeometryId::GetElementRef, &GeometryId::SetElementRef);
    c2.def("GetElementRef", &GeometryId::GetElementRef, py::return_value_policy::reference_internal);
    c2.def("SetElementRef", &GeometryId::SetElementRef, "elemRef"_a, py::keep_alive<1, 2>());

    c2.def_property_readonly("Element", &GeometryId::GetElement);
    c2.def("GetElement", &GeometryId::GetElement, py::return_value_policy::reference_internal);

    c2.def_property("RootPep", &GeometryId::GetRootPep, &GeometryId::SetRootPep);
    c2.def("GetRootPep", &GeometryId::GetRootPep, py::return_value_policy::reference_internal);
    c2.def("SetRootPep", &GeometryId::SetRootPep, "pep"_a, py::keep_alive<1, 2>());
    
    c2.def("GetRootRange", &GeometryId::GetRootRange, "range"_a);
    c2.def("GetParameter", py::overload_cast<>(&GeometryId::GetParameter, py::const_));
    c2.def("SetParameter", py::overload_cast<double>(&GeometryId::SetParameter), "param"_a);

    c2.def("GetParameter", py::overload_cast<DPoint2dR>(&GeometryId::GetParameter, py::const_), "param"_a);
    c2.def("SetParameter", py::overload_cast<DPoint2dCR>(&GeometryId::SetParameter));

    c2.def_property("EntityIndex", &GeometryId::GetEntityIndex, &GeometryId::SetEntityIndex);
    c2.def("GetEntityIndex", &GeometryId::GetEntityIndex);
    c2.def("SetEntityIndex", &GeometryId::SetEntityIndex, "entityIndex"_a);

    c2.def(py::self < py::self);

    //===================================================================================
    // struct FaceGeometryId
    py::class_< FaceGeometryId, RefCountedPtr<FaceGeometryId>, GeometryId> c3(m, "FaceGeometryId");

    c3.def_static("Create", py::overload_cast<ElementHandleCR, ISubEntityCR>(&FaceGeometryId::Create), "eh"_a, "subEntity"_a);

    //===================================================================================
    // struct EdgeGeometryId
    py::class_< EdgeGeometryId, RefCountedPtr<EdgeGeometryId>, GeometryId> c4(m, "EdgeGeometryId");

    c4.def_static("Create", py::overload_cast<ElementHandleCR, ISubEntityCR>(&EdgeGeometryId::Create), "eh"_a, "subEntity"_a);

    //===================================================================================
    // struct EdgeArcAxisGeometryId
    py::class_< EdgeArcAxisGeometryId, RefCountedPtr<EdgeArcAxisGeometryId>, EdgeGeometryId> c5(m, "EdgeArcAxisGeometryId");

    c5.def_static("Create", py::overload_cast<ElementHandleCR, EdgeId const&>(&EdgeArcAxisGeometryId::Create), "eh"_a, "edgeId"_a);

    //===================================================================================
    // struct BRepVertexGeometryId
    py::class_< BRepVertexGeometryId, RefCountedPtr<BRepVertexGeometryId>, GeometryId> c6(m, "BRepVertexGeometryId");

    c6.def_static("Create", py::overload_cast<ElementHandleCR, ISubEntityCR>(&BRepVertexGeometryId::Create), "eh"_a, "subEntity"_a);

    //===================================================================================
    // struct CurveGeometryId
    py::class_< CurveGeometryId, RefCountedPtr<CurveGeometryId>, GeometryId> c7(m, "CurveGeometryId");

    c7.def_static("Create", py::overload_cast<ElementHandleCR, CurveLocationDetailCR>(&CurveGeometryId::Create), "eh"_a, "curveLocationDetail"_a);

    //===================================================================================
    // struct CurveArcAxisGeometryId
    py::class_< CurveArcAxisGeometryId, RefCountedPtr<CurveArcAxisGeometryId>, CurveGeometryId> c8(m, "CurveArcAxisGeometryId");

    c8.def_static("Create", py::overload_cast<ElementHandleCR, CurvePrimitiveIdCR>(&CurveArcAxisGeometryId::Create), "eh"_a, "curvePrimitiveId"_a);

    //===================================================================================
    // struct CurvePointGeometryId
    py::class_< CurvePointGeometryId, RefCountedPtr<CurvePointGeometryId>, CurveGeometryId> c9(m, "CurvePointGeometryId");

    c9.def_static("Create", py::overload_cast<ElementHandleCR, CurveLocationDetailCR>(&CurvePointGeometryId::Create), "eh"_a, "curveLocationDetail"_a);

    //===================================================================================
    // struct RegionPlaneId
    py::class_< RegionPlaneId, RefCountedPtr<RegionPlaneId>, GeometryId> c10(m, "RegionPlaneId");

    c10.def_static("Create", py::overload_cast<ElementHandleCR, PersistentElementPathCR, GeometryId::Status>(&RegionPlaneId::Create), "eh"_a, "pep"_a, "status"_a);
    c10.def_static("Create", py::overload_cast<ElementHandleCR>(&RegionPlaneId::Create), "eh"_a);

    //===================================================================================
    // struct FaceAxisGeometryId
    py::class_< FaceAxisGeometryId, RefCountedPtr<FaceAxisGeometryId>, FaceGeometryId> c11(m, "FaceAxisGeometryId");

    c11.def_static("Create", py::overload_cast<ElementHandleCR, FaceId const&>(&FaceAxisGeometryId::Create), "eh"_a, "faceId"_a);

    //===================================================================================
    // struct Constraint3dBase
    py::class_< Constraint3dBase, RefCountedPtr<Constraint3dBase> > c12(m, "Constraint3dBase");
    py::bind_vector<bvector<Constraint3dPtr> >(m, "Constraint3dPtrArray", py::module_local(false));

    if (true)
        {
        //===================================================================================
        // enum class Status
        py::enum_< Constraint3dBase::Status>(c12, "Status")
            .value("eDCM3_D_UNKNOWN", Constraint3dBase::Status::DCM3_D_UNKNOWN)
            .value("eDCM3_D_OVER_DEFINED", Constraint3dBase::Status::DCM3_D_OVER_DEFINED)
            .value("eDCM3_D_NOT_CONSISTENT", Constraint3dBase::Status::DCM3_D_NOT_CONSISTENT)
            .value("eDCM3_D_NOT_CONSISTENT_DIMENSIONS", Constraint3dBase::Status::DCM3_D_NOT_CONSISTENT_DIMENSIONS)
            .value("eDCM3_D_NOT_CONSISTENT_OTHER", Constraint3dBase::Status::DCM3_D_NOT_CONSISTENT_OTHER)
            .value("eDCM3_D_NOT_CONSISTENT_UNKNOWN", Constraint3dBase::Status::DCM3_D_NOT_CONSISTENT_UNKNOWN)
            .value("eDCM3_D_NOT_CHANGED", Constraint3dBase::Status::DCM3_D_NOT_CHANGED)
            .value("eDCM3_D_BETWEEN_SET_MEMBERS", Constraint3dBase::Status::DCM3_D_BETWEEN_SET_MEMBERS)
            .value("eDCM3_D_BETWEEN_FIXED", Constraint3dBase::Status::DCM3_D_BETWEEN_FIXED)
            .value("eDCM3_D_NOT_SOLVED", Constraint3dBase::Status::DCM3_D_NOT_SOLVED)
            .value("eDCM3_D_SOLVED", Constraint3dBase::Status::DCM3_D_SOLVED)
            .value("eRedundant", Constraint3dBase::Status::Redundant)
            .export_values();

        //===================================================================================
        // enum FlagMasks
        py::enum_< Constraint3dBase::FlagMasks>(c12, "FlagMasks")
            .value("eFlagMask_SurfaceOrientation", Constraint3dBase::FlagMask_SurfaceOrientation)
            .value("eFlagMask_GroupLock", Constraint3dBase::FlagMask_GroupLock)
            .value("eFlagMask_HalfSpace1", Constraint3dBase::FlagMask_HalfSpace1)
            .value("eFlagMask_HalfSpace2", Constraint3dBase::FlagMask_HalfSpace2)
            .export_values();
        }

    c12.def_static("Create", py::overload_cast<Constraint3dType>(&Constraint3dBase::Create), "type"_a);
    c12.def_static("Create", py::overload_cast<Constraint3dType, T_GeometryIds const&, UInt32>(&Constraint3dBase::Create), "type"_a, "geometryIds"_a, "flags"_a);

    c12.def_property_readonly("Type", &Constraint3dBase::GetType);
    c12.def("GetType", &Constraint3dBase::GetType);

    c12.def_property("Status", &Constraint3dBase::GetStatus, &Constraint3dBase::SetStatus);
    c12.def("GetStatus", &Constraint3dBase::GetStatus);
    c12.def("SetStatus", &Constraint3dBase::SetStatus, "status"_a);

    c12.def_property("Flags", &Constraint3dBase::GetFlags, &Constraint3dBase::SetFlags);
    c12.def("GetFlags", &Constraint3dBase::GetFlags);
    c12.def("SetFlags", &Constraint3dBase::SetFlags, "flags"_a);

    c12.def("SetGeometryIds", &Constraint3dBase::SetGeometryIds, "geometryIds"_a);

    c12.def_property("SurfaceOrientation", &Constraint3dBase::GetSurfaceOrientation, &Constraint3dBase::SetSurfaceOrientation);
    c12.def("GetSurfaceOrientation", &Constraint3dBase::GetSurfaceOrientation);
    c12.def("SetSurfaceOrientation", &Constraint3dBase::SetSurfaceOrientation, "orientation"_a);

    c12.def_property("HalfSpace1", &Constraint3dBase::GetHalfSpace1, &Constraint3dBase::SetHalfSpace1);
    c12.def("GetHalfSpace1", &Constraint3dBase::GetHalfSpace1);
    c12.def("SetHalfSpace1", &Constraint3dBase::SetHalfSpace1, "halfSpace"_a);

    c12.def_property("HalfSpace2", &Constraint3dBase::GetHalfSpace2, &Constraint3dBase::SetHalfSpace2);
    c12.def("GetHalfSpace2", &Constraint3dBase::GetHalfSpace2);    
    c12.def("SetHalfSpace2", &Constraint3dBase::SetHalfSpace2, "halfSpace"_a);

    c12.def_property("GroupLock", &Constraint3dBase::GetGroupLock, &Constraint3dBase::SetGroupLock);
    c12.def("GetGroupLock", &Constraint3dBase::GetGroupLock);
    c12.def("SetGroupLock", &Constraint3dBase::SetGroupLock, "groupLock"_a);

    c12.def("HasBoundVariable", &Constraint3dBase::HasBoundVariable);
    c12.def("IsRedundant", &Constraint3dBase::IsRedundant, "other"_a);
    c12.def("HasElementRef", &Constraint3dBase::HasElementRef, "elemRef"_a);
    c12.def("GetElementRefs", &Constraint3dBase::GetElementRefs, "elemRefs"_a);
    c12.def("GetRootRange", &Constraint3dBase::GetRootRange, "range"_a);

    //===================================================================================
    // struct Dimension3dBase
    py::class_< Dimension3dBase, RefCountedPtr<Dimension3dBase>, Constraint3dBase> c13(m, "Dimension3dBase");    

    //===================================================================================
    // struct DistanceDimension3d
    py::class_< DistanceDimension3d, RefCountedPtr<DistanceDimension3d>, Dimension3dBase> c14(m, "DistanceDimension3d");

    c14.def_static("Create", &DistanceDimension3d::Create, "geometryIds"_a, "flags"_a, "value"_a, "variableAccess"_a);

    //===================================================================================
    // struct Angle3dConstraint
    py::class_< Angle3dConstraint, RefCountedPtr<Angle3dConstraint>, Dimension3dBase> c15(m, "Angle3dConstraint");

    if (true)
        {
        //===================================================================================
        // enum AngleSettings
        py::enum_< Angle3dConstraint::AngleSettings>(c15, "AngleSettings", py::arithmetic())
            .value("eNO_INVERTED_AXIS", Angle3dConstraint::NO_INVERTED_AXIS)
            .value("eINVERTED_AXIS", Angle3dConstraint::INVERTED_AXIS)
            .export_values();
        }

    c15.def_static("Create", &Angle3dConstraint::Create, "geometryIds"_a, "axis"_a, "flags"_a, "value"_a, "variableAccess"_a, "settings"_a);

    //===================================================================================
    // struct Constraint3dUtil
    py::class_< Constraint3dUtil> c16(m, "Constraint3dUtil");

    c16.def_static("RemoveInvalidConstraints", [] (T_Constraints& constraints, ElementRefP changed, ElementHandleCR hostEh)
                   {
                   size_t nInvalid = 0;
                   Constraint3dUtil::RemoveInvalidConstraints(nInvalid, constraints, changed, hostEh);
                   return nInvalid;
                   }, "constraints"_a, "changed"_a, "hostEh"_a);

    c16.def_static("GetConstrainedElements", &Constraint3dUtil::GetConstrainedElements, "elements"_a, "constraints"_a, "modelRef"_a);

    c16.def_static("GetNamedGroupMembers", [] (T_StdElementRefSet& members, NamedGroupP namedGroup)
                   {
                   NamedGroupPtr namedGroup_(namedGroup);
                   return Constraint3dUtil::GetNamedGroupMembers(members, namedGroup_);
                   }, "members"_a, "namedGroup"_a);

    c16.def_static("GetNamedGroupMembers", 
                   py::overload_cast<T_StdElementRefSet&, ElementRefP, DgnModelRefP>(&Constraint3dUtil::GetNamedGroupMembers),
                   "members"_a, "elemRef"_a, "modelRef"_a);

    c16.def_static("GetFaceAxis", [] (ISubEntityCR face)
                   {
                   ICurvePrimitivePtr axis;
                   auto retVal = Constraint3dUtil::GetFaceAxis(axis, face);
                   return py::make_tuple(retVal, axis);
                   }, "face"_a);

    c16.def_static("GetEdgeArcAxis", &Constraint3dUtil::GetEdgeArcAxis, "axis"_a, "edge"_a);

    //===================================================================================
    // struct Constraint3dSolver
    py::class_< Constraint3dSolver> c17(m, "Constraint3dSolver");

    c17.def(py::init<>());

    c17.def("Initialize", [] (Constraint3dSolver& self, T_Constraints const& constraints, DgnModelRefR modelRef, py::dict const& modifiedElements, char const* debugJournal)
            {
            BentleyStatus retVal = ERROR;
            if (py::len(modifiedElements) > 0)
                {
                bmap <ElementRefP, EditElementHandleP> mes;
                for (auto& it : modifiedElements)
                    {
                    auto elemRef = it.first.cast<ElementRefP>();
                    auto eehP = it.second.cast<EditElementHandleP>();
                    mes.insert(make_bpair(elemRef, eehP));
                    }
                retVal = self.Initialize(constraints, modelRef, &mes, debugJournal);
                }
            else
                retVal = self.Initialize(constraints, modelRef, nullptr, debugJournal);

            return retVal;
            }, "constraints"_a, "modelRef"_a, "modifiedElements"_a = nullptr, "debugJournal"_a = nullptr);

    c17.def("Evaluate", [] (Constraint3dSolver& self)
            {
            py::dict outVal;
            T_ElementTransformMap tm;
            auto retVal = self.Evaluate(tm);
            if (retVal == SUCCESS && !tm.empty())
                {
                for (auto& it : tm)
                    {
                    auto key = py::cast(it.first, py::return_value_policy::reference_internal);
                    auto val = py::cast(it.second);
                    outVal[key] = val;
                    }
                }
            return py::make_tuple(retVal, outVal);
            });

    c17.def("Evaluate", [] (Constraint3dSolver& self, GeometryIdCR softReferenceId)
            {
            py::dict outVal;
            T_ElementTransformMap tm;
            auto retVal = self.Evaluate(tm, softReferenceId);
            if (retVal == SUCCESS && !tm.empty())
                {
                for (auto& it : tm)
                    {
                    auto key = py::cast(it.first, py::return_value_policy::reference_internal);
                    auto val = py::cast(it.second);
                    outVal[key] = val;
                    }
                }
            return py::make_tuple(retVal, outVal);
            }, "softReferenceId"_a);

    c17.def("Evaluate", [] (Constraint3dSolver& self, bvector<ElementRefP> const& elemRefs)
            {
            py::dict outVal;
            T_ElementTransformMap tm;
            T_StdElementRefSet refSet;

            if (!elemRefs.empty())
                refSet.insert(elemRefs.begin(), elemRefs.end());

            auto retVal = self.Evaluate(tm, refSet);
            if (retVal == SUCCESS && !tm.empty())
                {
                for (auto& it : tm)
                    {
                    auto key = py::cast(it.first, py::return_value_policy::reference_internal);
                    auto val = py::cast(it.second);
                    outVal[key] = val;
                    }
                }
            return py::make_tuple(retVal, outVal);
            }, "elemRefs"_a);

    c17.def("DynamicEvaluate", [] (Constraint3dSolver& self, bvector<ElementRefP> const& elemRefs, TransformCR transform)
            {
            py::dict outVal;
            T_ElementTransformMap tm;
            T_StdElementRefSet refSet;

            if (!elemRefs.empty())
                refSet.insert(elemRefs.begin(), elemRefs.end());

            auto retVal = self.DynamicEvaluate(tm, refSet, transform);
            if (retVal == SUCCESS && !tm.empty())
                {
                for (auto& it : tm)
                    {
                    auto key = py::cast(it.first, py::return_value_policy::reference_internal);
                    auto val = py::cast(it.second);
                    outVal[key] = val;
                    }
                }
            return py::make_tuple(retVal, outVal);
            }, "elemRefs"_a, "transform"_a);

    c17.def("DynamicEvaluate", [] (Constraint3dSolver& self, py::dict const& transformInMap)
            {
            py::dict transformOutMap;
            T_ElementTransformMap tmIn, tmOut;

            if (py::len(transformInMap) > 0)
                {
                for (auto& it : transformInMap)
                    {
                    ElementRefP key = it.first.cast<ElementRefP>();
                    Transform val = it.second.cast<Transform>();
                    tmIn.Insert(key, val);
                    }
                }

            auto retVal = self.DynamicEvaluate(tmOut, tmIn);
            if (retVal == SUCCESS && !tmOut.empty())
                {
                for (auto& it : tmOut)
                    {
                    auto key = py::cast(it.first, py::return_value_policy::reference_internal);
                    auto val = py::cast(it.second);
                    transformOutMap[key] = val;
                    }
                }

            return py::make_tuple(retVal, transformOutMap);
            }, "transformInMap"_a);

    c17.def("GetDegreesOfFreedom", [] (Constraint3dSolver& self)
            {
            int dof = 0, removedDof = 0, rigidDof = 0;
            auto retVal = self.GetDegreesOfFreedom(dof, removedDof, rigidDof);
            return py::make_tuple(retVal, dof, removedDof, rigidDof);
            });
    }