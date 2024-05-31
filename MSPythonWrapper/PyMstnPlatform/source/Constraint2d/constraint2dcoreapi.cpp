/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\Constraint2d\constraint2dcoreapi.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Constraint2d/Constraint2dCoreAPI.h>



static const char * __doc_Bentley_DgnPlatform_Constraint2dSolverData_IsCurvePlaneConstrained =R"doc(A curve plane is constrained if is by a plane distance dimension.)doc";

static const char * __doc_Bentley_DgnPlatform_Constraint2dSolverData_IsCurvePlaneFixed =R"doc(A curve plane is considered to be fixed if any portion of the curve is
fixed.)doc";

static const char * __doc_Bentley_DgnPlatform_Constraint2dSolverData_Reverse =R"doc(@description Update constraint data assuming the curve's direction was
reversed.

Parameter ``[in]``:
    elementRef A element to specify what curve's direction was
    reversed

Parameter ``[in]``:
    curveVector An optional update-to-date curve vector to set
    specific to *elementRef*

Returns:
    True if any change was made, or false if not)doc";

static const char * __doc_Bentley_DgnPlatform_Constraint2dSolverData_RemoveInvalidConstraints =R"doc(@description Remove all invalid constraint data which are correlated
to the the given element.

Parameter ``[out]``:
    invalidCount An integer to receive the number of invalid
    constraints

Parameter ``[in]``:
    elementRef Specify an element ref whose constraints will be
    removed)doc";

static const char * __doc_Bentley_DgnPlatform_Constraint2dSolverData_RemoveUnresolvedElementRefs =R"doc(@description Remove all constraint data whose target elements are not
resolved.)doc";

static const char * __doc_Bentley_DgnPlatform_Constraint2dSolverData_RemoveElementRef =R"doc(@description Remove all constraint data which are correlated to the
the given element.

Parameter ``[in]``:
    elementRef Specify an element ref whose constraints will be
    removed

Returns:
    True if any removal occurred; otherwise false.)doc";

static const char * __doc_Bentley_DgnPlatform_Constraint2dSolverData_CollateByElement =R"doc(@description Check and divide this constraint model into child per
links among elements.

Parameter ``[out]``:
    childGroups Separate child constraint model whose member elements
    have links with each other.

Returns:
    The number of child constraint models.)doc";

static const char * __doc_Bentley_DgnPlatform_Constraint2dSolverData_Merge =R"doc(@description Merge another constraint model into this one. Identital
data items will be excluded while merging.

Parameter ``[in]``:
    rhs A data instance to merge into.

Returns:
    True if there are some items being merged into; otherwise False if
    nothing being merged.)doc";

static const char * __doc_Bentley_DgnPlatform_Constraint2dSolverData_GetElementRefs =R"doc(@description Query all member elements.

Parameter ``[out]``:
    elementRefs A set receiving member elements.

Returns:
    The number of member elements.)doc";

static const char * __doc_Bentley_DgnPlatform_Constraint2dSolverData_IsComplete =R"doc(@description Determine if it is complete, i.e., its actual topology is
identical to the datum description used.

Returns:
    True if it is complete; otherwise False.)doc";

static const char * __doc_Bentley_DgnPlatform_Constraint2dSolverData_IsResolved =R"doc(@description Determine if it is resolved, i.e., all member elements
are available

Returns:
    True if it is resolved; otherwise False.)doc";

static const char * __doc_Bentley_DgnPlatform_Constraint2dSolverData_IsEmpty =R"doc(@description Determine if it is empty.

Returns:
    True if it is empty; otherwise False.)doc";

static const char * __doc_Bentley_DgnPlatform_Constraint2dSolverData_Clear =R"doc(@description Clear all data and set to empty)doc";

static const char * __doc_Bentley_DgnPlatform_Constraint2dSolver_GetResultCurveVector =R"doc(@description Get results for the given element

Parameter ``[out]``:
    resultCurve A curve vector reference to receive the result

Parameter ``[in]``:
    elementRef A reference to element to specify what element is to
    query)doc";

static const char * __doc_Bentley_DgnPlatform_Constraint2dSolver_Evaluate =R"doc(@description Perform a evaluation

Parameter ``[in]``:
    dragInfos An array of dragging information representing direct
    changes.

Parameter ``[in]``:
    isDynamic A boolean indicating whether for " dynamic " purpose.

Returns:
    SUCCESS if implemented successfully; otherwise ERROR if failed.)doc";

static const char * __doc_Bentley_DgnPlatform_Constraint2dSolver_GetData =R"doc(@description Initialize model

Parameter ``[in]``:
    data The 2d constraint model to evaluate.

Remark:
    s The curvevector in *data* must have CurvePrimitiveIds; scale is
    equal to the solid's scale, i.e., DCube(parasolid)=>Uor. It should
    more than 1.0)doc";

static const char * __doc_Bentley_DgnPlatform_Constraint2dSolver_SetData =R"doc(@description Initialize model

Parameter ``[in]``:
    data The 2d constraint model to evaluate.

Parameter ``[in]``:
    uorPerMaster A float-point value to specify the UOR unit in master
    unit

Remark:
    s The curvevector must have CurvePrimitiveIds; scale is equal to
    the solid's scale, i.e., DCube(parasolid)=>Uor. It should more
    than 1.0)doc";

static const char * __doc_Bentley_DgnPlatform_Drag2dInfo_SetRadius =R"doc(@description Set radius

Parameter ``radius``:
    Radius)doc";

static const char * __doc_Bentley_DgnPlatform_Drag2dInfo_GetRadius =R"doc(@description Get radius

Returns:
    Radius value)doc";

static const char * __doc_Bentley_DgnPlatform_Drag2dInfo_SetMoveValue =R"doc(@description Set moving value

Parameter ``value``:
    Moving value)doc";

static const char * __doc_Bentley_DgnPlatform_Drag2dInfo_GetMoveValue =R"doc(@description Get moving value

Returns:
    A vector representing the moving value.)doc";

static const char * __doc_Bentley_DgnPlatform_Drag2dInfo_SetDraggingTransform =R"doc(@description Set dragging transform type

Parameter ``transformType``:
    Dragging transform type)doc";

static const char * __doc_Bentley_DgnPlatform_Drag2dInfo_GetDraggingTransform =R"doc(@description Get dragging transform type

Returns:
    Dragging transform type)doc";

static const char * __doc_Bentley_DgnPlatform_Drag2dInfo_SetCurveEntityIdentifier =R"doc(@description Set curve identifier

Parameter ``identifer``:
    Curve identifier)doc";

static const char * __doc_Bentley_DgnPlatform_Drag2dInfo_GetCurveEntityIdentifier =R"doc(@description Get curve identifier

Returns:
    Curve identifier)doc";

static const char * __doc_Bentley_DgnPlatform_Dimension2dData_GetVariableName =R"doc(@description Get variable name

Returns:
    A WString reference to the variable name)doc";

static const char * __doc_Bentley_DgnPlatform_Dimension2dData_SetVariableName =R"doc(@description Set variable name

Parameter ``name``:
    Variable name)doc";

static const char * __doc_Bentley_DgnPlatform_Dimension2dData_GetDimensionValue =R"doc(@description Get dimension value

Returns:
    Dimension value)doc";

static const char * __doc_Bentley_DgnPlatform_Dimension2dData_SetDimensionValue =R"doc(@description Set a new dimension value

Parameter ``value``:
    A new dimension value to set)doc";

static const char * __doc_Bentley_DgnPlatform_Constraint2dData_AddCurveIdentifier =R"doc(@description Add curve identifier

Parameter ``id``:
    The id to be added)doc";

static const char * __doc_Bentley_DgnPlatform_Constraint2dData_GetConstraintStatus =R"doc(@description Get the constraint status

Returns:
    The constraint status)doc";

static const char * __doc_Bentley_DgnPlatform_Constraint2dData_SetConstraintStatus =R"doc(@description Set the constraint status

Parameter ``status``:
    A new constraint status to set)doc";

static const char * __doc_Bentley_DgnPlatform_Constraint2dData_GetConstraintType =R"doc(@description Get the constraint type

Returns:
    The constraint type)doc";

static const char * __doc_Bentley_DgnPlatform_Constraint2dData_SetConstraintType =R"doc(@description Set the constraint type

Parameter ``type``:
    The constraint type)doc";

static const char * __doc_Bentley_DgnPlatform_CurveEntityIdentifier_GetPointIndex =R"doc(@description Get the point index

Returns:
    The point index)doc";

static const char * __doc_Bentley_DgnPlatform_CurveEntityIdentifier_SetPointIndex =R"doc(@description Set the point index in linestring

Parameter ``pointIndex``:
    the point index)doc";

static const char * __doc_Bentley_DgnPlatform_CurveEntityIdentifier_ElementToCurveVector =R"doc(@cond DONTINCLUDEINDOC @endcond @description Get an editable curve
vector of a given element

Parameter ``[out]``:
    curveVector The resultant curve vector

Parameter ``[in]``:
    eh An ElementHandle to specify a curve element)doc";

static const char * __doc_Bentley_DgnPlatform_CurveEntityIdentifier_GetVertexType =R"doc(@description Get the vertex type

Returns:
    The vertex type)doc";

static const char * __doc_Bentley_DgnPlatform_CurveEntityIdentifier_SetVertexType =R"doc(@description Set new vertex type

Parameter ``vertexType``:
    A new vertex type to set)doc";

static const char * __doc_Bentley_DgnPlatform_CurveEntityIdentifier_GetSubEdgeIndex =R"doc(@description Get the sub edge index

Returns:
    The sub edge index)doc";

static const char * __doc_Bentley_DgnPlatform_CurveEntityIdentifier_SetSubEdgeIndex =R"doc(@description Set the sub edge index

Parameter ``subEdgeIndex``:
    the sub edge index)doc";

static const char * __doc_Bentley_DgnPlatform_CurveEntityIdentifier_GetEdgeId =R"doc(@description Get the edge id @retval NULL if failing to get)doc";

static const char * __doc_Bentley_DgnPlatform_CurveEntityIdentifier_SetEdgeId =R"doc(@description Set the edge id

Parameter ``edgeId``:
    the edge id @note edgeId cannot be NULL)doc";

static const char * __doc_Bentley_DgnPlatform_CurveEntityIdentifier_IsValid =R"doc(@description Test the CurveEntityIdentifier is valid or not

Returns:
    True if it is valid, or False if not)doc";





USING_NAMESPACE_CONSTRAINT2D;

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_Constraint2dCoreAPI(py::module_& m)
    {
    //===================================================================================
    // enum class VertexType
    py::enum_< VertexType>(m, "VertexType")
        .value("eEdge", VertexType::Edge)
        .value("eStart", VertexType::Start)
        .value("eEnd", VertexType::End)
        .value("eCenter", VertexType::Center)
        .value("eParameter", VertexType::Parameter)
        .value("ePointIndex", VertexType::PointIndex)
        .value("eEllipseMajor1", VertexType::EllipseMajor1)
        .value("eEllipseMajor2", VertexType::EllipseMajor2)
        .value("eEllipseMinor1", VertexType::EllipseMinor1)
        .value("eEllipseMinor2", VertexType::EllipseMinor2)
        .value("eArcPoint", VertexType::ArcPoint)
        .value("eEllipseMajorEdge", VertexType::EllipseMajorEdge)
        .value("eEllipseMinorEdge", VertexType::EllipseMinorEdge)
        .value("ePlanarFace", VertexType::PlanarFace)
        .export_values();

    //===================================================================================
    // enum class SectorAngleType
    py::enum_< Constraint2d::SectorAngleType>(m, "SectorAngleType")
        .value("eParallel_AntiClockwise", Constraint2d::SectorAngleType::AntiParallel_AntiClockwise)
        .value("eParallel_Clockwise", Constraint2d::SectorAngleType::Parallel_Clockwise)
        .value("eAntiParallel_AntiClockwise", Constraint2d::SectorAngleType::AntiParallel_AntiClockwise)
        .value("eAntiParallel_Clockwise", Constraint2d::SectorAngleType::AntiParallel_Clockwise)
        .export_values();

    //===================================================================================
    // enum class SectorAngleType
    py::enum_<Constraint2dType>(m, "Constraint2dType")
        .value("eDistance", Constraint2dType::Distance)
        .value("eAngle", Constraint2dType::Angle)
        .value("eConcentric", Constraint2dType::Concentric)
        .value("eRadius", Constraint2dType::Radius)
        .value("eParallel", Constraint2dType::Parallel)
        .value("ePerpendicular", Constraint2dType::Perpendicular)
        .value("eCoincident", Constraint2dType::Coincident)
        .value("eTangent", Constraint2dType::Tangent)
        .value("eIdentical", Constraint2dType::Identical)
        .value("eSymmetric", Constraint2dType::Symmetric)
        .value("eMajor_Radius", Constraint2dType::Major_Radius)
        .value("eMinor_Radius", Constraint2dType::Minor_Radius)
        .value("eEqual_Radius", Constraint2dType::Equal_Radius)
        .value("eEqual_Distance", Constraint2dType::Equal_Distance)
        .value("eMidpoint", Constraint2dType::Midpoint)
        .value("eDependence", Constraint2dType::Dependence)
        .value("ePatterned", Constraint2dType::Patterned)
        .value("eEqual_Parameter", Constraint2dType::Equal_Parameter)
        .value("eNormal", Constraint2dType::Normal)
        .value("eEqual_Direction", Constraint2dType::Equal_Direction)
        .value("eEqual_Curvature", Constraint2dType::Equal_Curvature)
        .value("eEqual_First_Derivative", Constraint2dType::Equal_First_Derivative)
        .value("eEqual_Second_Derivative", Constraint2dType::Equal_Second_Derivative)
        .value("eOffset", Constraint2dType::Offset)
        .value("eSimple_Dependence", Constraint2dType::Simple_Dependence)
        .value("eCurve_Length", Constraint2dType::Curve_Length)
        .value("ePatterned_2d", Constraint2dType::Patterned_2d)
        .value("ePattern_Value", Constraint2dType::Pattern_Value)
        .value("ePattern_2d_value_1", Constraint2dType::Pattern_2d_value_1)
        .value("ePattern_2d_value_2", Constraint2dType::Pattern_2d_value_2)
        .value("eEqual_Relative_Transform", Constraint2dType::Equal_Relative_Transform)
        .value("eArc_length", Constraint2dType::Arc_length)
        .value("eOffset_Dimension", Constraint2dType::Offset_Dimension)
        .value("eArea", Constraint2dType::Area)
        .value("ePerimeter", Constraint2dType::Perimeter)
        .value("eFix", Constraint2dType::Fix)
        .value("eHorizontal", Constraint2dType::Horizontal)
        .value("eVertical", Constraint2dType::Vertical)
        .value("eEqual", Constraint2dType::Equal)
        .value("ePlanar_Distance", Constraint2dType::Planar_Distance)
        .value("eDistanceLL", Constraint2dType::DistanceLL)
        .value("eDistancePL", Constraint2dType::DistancePL)
        .value("eDistancePP", Constraint2dType::DistancePP)
        .value("eDistanceCL", Constraint2dType::DistanceCL)
        .value("eDistanceCP", Constraint2dType::DistanceCP)
        .value("eDistanceCC", Constraint2dType::DistanceCC)
        .value("eDummy", Constraint2dType::Dummy)
        .export_values();

    //===================================================================================
    // enum class Constraint2dStatus
    py::enum_<Constraint2dStatus>(m, "Constraint2dStatus")
        .value("eUnknown", Constraint2dStatus::Unknown)
        .value("eBetween_Fixed", Constraint2dStatus::Between_Fixed)
        .value("eBetween_Set_Members", Constraint2dStatus::Between_Set_Members)
        .value("eOver_Defined", Constraint2dStatus::Over_Defined)
        .value("eNon_Algebraic", Constraint2dStatus::Non_Algebraic)
        .value("eNot_Consistent", Constraint2dStatus::Not_Consistent)
        .value("eNot_Consistent_Dimensions", Constraint2dStatus::Not_Consistent_Dimensions)
        .value("eNot_Consistent_Other", Constraint2dStatus::Not_Consistent_Other)
        .value("eNot_Consistent_Unknown", Constraint2dStatus::Not_Consistent_Unknown)
        .value("eNot_Solved", Constraint2dStatus::Not_Solved)
        .value("eNot_Changed", Constraint2dStatus::Not_Changed)
        .value("eSolved", Constraint2dStatus::Solved)
        .export_values();

    //===================================================================================
    // enum class DragTransformType
    py::enum_<DragTransformType>(m, "DragTransformType")
        .value("eGeneral", DragTransformType::General)
        .value("eTranslation", DragTransformType::Translation)
        .value("eRadius", DragTransformType::Radius)
        .value("eMajor_Radius", DragTransformType::Major_Radius)
        .value("eMinor_Radius", DragTransformType::Minor_Radius)
        .value("eOffset_Distance", DragTransformType::Offset_Distance)
        .export_values();

    //===================================================================================
    // enum class DimensionHalfSpace
    py::enum_< DimensionHalfSpace>(m, "DimensionHalfSpace")
        .value("eUnspecified", DimensionHalfSpace::Unspecified)
        .value("eLeft", DimensionHalfSpace::Left)
        .value("eRight", DimensionHalfSpace::Right)
        .export_values();

    //===================================================================================
    // enum class DimensionAlignmentType
    py::enum_< DimensionAlignmentType>(m, "DimensionAlignmentType")
        .value("eDimAlign_Unknown", DimensionAlignmentType::DimAlign_Unknown)
        .value("eDimAlign_Drawing_X", DimensionAlignmentType::DimAlign_Drawing_X)
        .value("eDimAlign_Drawing_X_Reversed", DimensionAlignmentType::DimAlign_Drawing_X_Reversed)
        .value("eDimAlign_Drawing_Y", DimensionAlignmentType::DimAlign_Drawing_Y)
        .value("eDimAlign_Drawing_Y_Reversed", DimensionAlignmentType::DimAlign_Drawing_Y_Reversed)
        .export_values();

    //===================================================================================
    // struct CurveEntityIdentifier
    py::class_< CurveEntityIdentifier> c1(m, "CurveEntityIdentifier");
    py::bind_vector<bvector<CurveEntityIdentifier> >(m, "CurveEntityIdentifierArray", py::module_local(false));

    c1.def(py::init<>());
    c1.def(py::init<CurveVectorR, CurvePrimitiveIdCP, size_t, VertexType, ElementRefP>(), "curve"_a, "edgeId"_a, "subIndex"_a, "vertexType"_a, "elemRef"_a);
    c1.def(py::init<CurveVectorR, CurveLocationDetailCR, VertexType, ElementRefP>(), "curve"_a, "location"_a, "vertexType"_a, "elemRef"_a);
    c1.def(py::self == py::self);
    c1.def(py::self < py::self);
    c1.def("__bool__", &CurveEntityIdentifier::IsValid);
    c1.def("IsValid", &CurveEntityIdentifier::IsValid, DOC(Bentley, DgnPlatform, CurveEntityIdentifier, IsValid));
    
    c1.def_property("EdgeId", &CurveEntityIdentifier::GetEdgeId, &CurveEntityIdentifier::SetEdgeId);
    c1.def("SetEdgeId", &CurveEntityIdentifier::SetEdgeId, "edgeId"_a, DOC(Bentley, DgnPlatform, CurveEntityIdentifier, SetEdgeId));
    c1.def("GetEdgeId", &CurveEntityIdentifier::GetEdgeId, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, CurveEntityIdentifier, GetEdgeId));
    
    c1.def_property("SubEdgeIndex", &CurveEntityIdentifier::GetSubEdgeIndex, &CurveEntityIdentifier::SetSubEdgeIndex);
    c1.def("SetSubEdgeIndex", &CurveEntityIdentifier::SetSubEdgeIndex, "subEdgeIndex"_a, DOC(Bentley, DgnPlatform, CurveEntityIdentifier, SetSubEdgeIndex));
    c1.def("GetSubEdgeIndex", &CurveEntityIdentifier::GetSubEdgeIndex, DOC(Bentley, DgnPlatform, CurveEntityIdentifier, GetSubEdgeIndex));
    
    c1.def_property("VertexType", &CurveEntityIdentifier::GetVertexType, &CurveEntityIdentifier::SetVertexType);
    c1.def("SetVertexType", &CurveEntityIdentifier::SetVertexType, "vertexType"_a, DOC(Bentley, DgnPlatform, CurveEntityIdentifier, SetVertexType));
    c1.def("GetVertexType", &CurveEntityIdentifier::GetVertexType, DOC(Bentley, DgnPlatform, CurveEntityIdentifier, GetVertexType));

    c1.def_static("ElementToCurveVector", [] (ElementHandleCR eh)
                  {
                  CurveVectorPtr cv;
                  auto retVal = CurveEntityIdentifier::ElementToCurveVector(cv, eh);
                  return py::make_tuple(retVal, cv);
                  }, "eh"_a, DOC(Bentley, DgnPlatform, CurveEntityIdentifier, ElementToCurveVector));

    c1.def_property("PointIndex", &CurveEntityIdentifier::GetPointIndex, &CurveEntityIdentifier::SetPointIndex);
    c1.def("SetPointIndex", &CurveEntityIdentifier::SetPointIndex, "pointIndex"_a, DOC(Bentley, DgnPlatform, CurveEntityIdentifier, SetPointIndex));
    c1.def("GetPointIndex", &CurveEntityIdentifier::GetPointIndex, DOC(Bentley, DgnPlatform, CurveEntityIdentifier, GetPointIndex));

    //===================================================================================
    // struct Constraint2dData
    py::class_< Constraint2dData> c2(m, "Constraint2dData");
    py::bind_vector<bvector<Constraint2dData> >(m, "Constraint2dDataArray", py::module_local(false));

    c2.def(py::init<>());
    c2.def(py::init<Constraint2dType>(), "constraintType"_a);

    c2.def_property("ConstraintType", &Constraint2dData::GetConstraintType, &Constraint2dData::SetConstraintType);
    c2.def("SetConstraintType", &Constraint2dData::SetConstraintType, "type"_a, DOC(Bentley, DgnPlatform, Constraint2dData, SetConstraintType));
    c2.def("GetConstraintType", &Constraint2dData::GetConstraintType, DOC(Bentley, DgnPlatform, Constraint2dData, GetConstraintType));

    c2.def_property("ConstraintStatus", &Constraint2dData::GetConstraintStatus, &Constraint2dData::SetConstraintStatus);
    c2.def("SetConstraintStatus", &Constraint2dData::SetConstraintStatus, "status"_a, DOC(Bentley, DgnPlatform, Constraint2dData, SetConstraintStatus));
    c2.def("GetConstraintStatus", &Constraint2dData::GetConstraintStatus, DOC(Bentley, DgnPlatform, Constraint2dData, GetConstraintStatus));
    c2.def("AddCurveIdentifier", &Constraint2dData::AddCurveIdentifier, "id"_a, DOC(Bentley, DgnPlatform, Constraint2dData, AddCurveIdentifier));

    //===================================================================================
    // struct Dimension2dData
    py::class_< Dimension2dData, Constraint2dData> c3(m, "Dimension2dData");

    c3.def(py::init<>());
    c3.def(py::init<Constraint2dType>(), "constraintType"_a);

    c3.def_property("DimensionValue", &Dimension2dData::GetDimensionValue, &Dimension2dData::SetDimensionValue);
    c3.def("SetDimensionValue", &Dimension2dData::SetDimensionValue, "value"_a, DOC(Bentley, DgnPlatform, Dimension2dData, SetDimensionValue));
    c3.def("GetDimensionValue", &Dimension2dData::GetDimensionValue, DOC(Bentley, DgnPlatform, Dimension2dData, GetDimensionValue));
    
    c3.def_property("VariableName", &Dimension2dData::GetVariableName, &Dimension2dData::SetVariableName);
    c3.def("SetVariableName", &Dimension2dData::SetVariableName, "name"_a, DOC(Bentley, DgnPlatform, Dimension2dData, SetVariableName));
    c3.def("GetVariableName", &Dimension2dData::GetVariableName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, Dimension2dData, GetVariableName));
    
    c3.def_property("SectorAngleType", &Dimension2dData::GetSectorAngleType, &Dimension2dData::SetSectorAngleType);
    c3.def("SetSectorAngleType", &Dimension2dData::SetSectorAngleType, "type"_a);
    c3.def("GetSectorAngleType", &Dimension2dData::GetSectorAngleType);
    
    c3.def_property("DimensionHeight", &Dimension2dData::GetDimensionHeight, &Dimension2dData::SetDimensionHeight);
    c3.def("SetDimensionHeight", &Dimension2dData::SetDimensionHeight, "value"_a);
    c3.def("GetDimensionHeight", &Dimension2dData::GetDimensionHeight);
    
    c3.def_property("DimensionFraction", &Dimension2dData::GetDimensionFraction, &Dimension2dData::SetDimensionFraction);
    c3.def("SetDimensionFraction", &Dimension2dData::SetDimensionFraction, "value"_a);
    c3.def("GetDimensionFraction", &Dimension2dData::GetDimensionFraction);
    
    c3.def_property("AngleSectorIndex", &Dimension2dData::GetAngleSectorIndex, &Dimension2dData::SetAngleSectorIndex);
    c3.def("SetAngleSectorIndex", &Dimension2dData::SetAngleSectorIndex, "sectorIndex"_a);
    c3.def("GetAngleSectorIndex", &Dimension2dData::GetAngleSectorIndex);
    
    c3.def_property("HalfSpace1", &Dimension2dData::GetHalfSpace1, &Dimension2dData::SetHalfSpace1);
    c3.def("SetHalfSpace1", &Dimension2dData::SetHalfSpace1, "halfSpace"_a);
    c3.def("GetHalfSpace1", &Dimension2dData::GetHalfSpace1);
    
    c3.def_property("HalfSpace2", &Dimension2dData::GetHalfSpace2, &Dimension2dData::SetHalfSpace2);
    c3.def("SetHalfSpace2", &Dimension2dData::SetHalfSpace2, "halfSpace"_a);
    c3.def("GetHalfSpace2", &Dimension2dData::GetHalfSpace2);
    
    c3.def_property("DimensionAlignmentType", &Dimension2dData::GetDimensionAlignmentType, &Dimension2dData::SetDimensionAlignmentType);
    c3.def("SetDimensionAlignmentType", &Dimension2dData::SetDimensionAlignmentType, "type"_a);
    c3.def("GetDimensionAlignmentType", &Dimension2dData::GetDimensionAlignmentType);
    
    c3.def(py::self == py::self);
    
    c3.def_property("DimensionXOffset", &Dimension2dData::GetDimensionXOffset, &Dimension2dData::SetDimensionXOffset);
    c3.def("SetDimensionXOffset", &Dimension2dData::SetDimensionXOffset, "value"_a);
    c3.def("GetDimensionXOffset", &Dimension2dData::GetDimensionXOffset);
    
    c3.def_property("DiaType", &Dimension2dData::GetDiaType, &Dimension2dData::SetDiaType);
    c3.def("SetDiaType", &Dimension2dData::SetDiaType, "value"_a);    
    c3.def("GetDiaType", &Dimension2dData::GetDiaType);
    //===================================================================================
    // struct Drag2dInfo
    py::class_< Drag2dInfo> c4(m, "Drag2dInfo");

    c4.def(py::init<>());
    c4.def(py::init<CurveEntityIdentifierCR, DragTransformType>(), "identifier"_a, "transformType"_a = DragTransformType::Translation);

    c4.def_property("CurveEntityIdentifier", &Drag2dInfo::GetCurveEntityIdentifier, &Drag2dInfo::SetCurveEntityIdentifier);
    c4.def("GetCurveEntityIdentifier", &Drag2dInfo::GetCurveEntityIdentifier, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, Drag2dInfo, GetCurveEntityIdentifier));
    c4.def("SetCurveEntityIdentifier", &Drag2dInfo::SetCurveEntityIdentifier, "identifier"_a, DOC(Bentley, DgnPlatform, Drag2dInfo, SetCurveEntityIdentifier));
    
    c4.def_property("DraggingTransform", &Drag2dInfo::GetDraggingTransform, &Drag2dInfo::SetDraggingTransform);
    c4.def("GetDraggingTransform", &Drag2dInfo::GetDraggingTransform, DOC(Bentley, DgnPlatform, Drag2dInfo, GetDraggingTransform));
    c4.def("SetDraggingTransform", &Drag2dInfo::SetDraggingTransform, "transformType"_a, DOC(Bentley, DgnPlatform, Drag2dInfo, SetDraggingTransform));
    
    c4.def_property("MoveValue", &Drag2dInfo::GetMoveValue, &Drag2dInfo::SetMoveValue);
    c4.def("GetMoveValue", &Drag2dInfo::GetMoveValue, DOC(Bentley, DgnPlatform, Drag2dInfo, GetMoveValue));
    c4.def("SetMoveValue", &Drag2dInfo::SetMoveValue, "value"_a, DOC(Bentley, DgnPlatform, Drag2dInfo, SetMoveValue));
    
    c4.def_property("Radius", &Drag2dInfo::GetRadius, &Drag2dInfo::SetRadius);
    c4.def("GetRadius", &Drag2dInfo::GetRadius, DOC(Bentley, DgnPlatform, Drag2dInfo, GetRadius));
    c4.def("SetRadius", &Drag2dInfo::SetRadius, "radius"_a, DOC(Bentley, DgnPlatform, Drag2dInfo, SetRadius));
    
    c4.def("Clear", &Drag2dInfo::Clear);


    //===================================================================================
    // struct Constraint2dSolver
    py::class_< Constraint2dSolver> c6(m, "Constraint2dSolver");

    c6.def(py::init<double, bool>(), "localToWorldScale"_a, "isAutoConstraining"_a = false);

    c6.def("SetData", &Constraint2dSolver::SetData, "data"_a, "uorPerMaster"_a = 1.0, DOC(Bentley, DgnPlatform, Constraint2dSolver, SetData));
    c6.def("GetData", &Constraint2dSolver::GetData, "data"_a, DOC(Bentley, DgnPlatform, Constraint2dSolver, GetData));
    c6.def("Evaluate", &Constraint2dSolver::Evaluate, "dragInfos"_a, "isDynamic"_a, DOC(Bentley, DgnPlatform, Constraint2dSolver, Evaluate));
    
    c6.def("GetResultCurveVector", [] (Constraint2dSolver& self, ElementRefP elemRef)
           {
           CurveVectorPtr cv;
           auto retVal = self.GetResultCurveVector(cv, elemRef);
           return py::make_tuple(retVal, cv);
           }, "elemRef"_a, DOC(Bentley, DgnPlatform, Constraint2dSolver, GetResultCurveVector));    
    
    //===================================================================================
    // struct Constraint2dSolverData
    py::class_< Constraint2dSolverData> c9(m, "Constraint2dSolverData");
    py::bind_vector<bvector<Constraint2dSolverData> >(m, "Constraint2dSolverDataArray", py::module_local(false));

    c9.def(py::init<>());
    c9.def("Clear", &Constraint2dSolverData::Clear, DOC(Bentley, DgnPlatform, Constraint2dSolverData, Clear));
    c9.def("IsEmpty", &Constraint2dSolverData::IsEmpty, DOC(Bentley, DgnPlatform, Constraint2dSolverData, IsEmpty));
    c9.def("__bool__", [] (Constraint2dSolverData& self) { return !self.IsEmpty(); });
    c9.def("IsResolved", &Constraint2dSolverData::IsResolved, DOC(Bentley, DgnPlatform, Constraint2dSolverData, IsResolved));
    c9.def("IsComplete", &Constraint2dSolverData::IsComplete, DOC(Bentley, DgnPlatform, Constraint2dSolverData, IsComplete));
    c9.def("GetElementRefs", &Constraint2dSolverData::GetElementRefs, "elemRefs"_a, DOC(Bentley, DgnPlatform, Constraint2dSolverData, GetElementRefs));
    c9.def("Merge", &Constraint2dSolverData::Merge, "rhs"_a, DOC(Bentley, DgnPlatform, Constraint2dSolverData, Merge));
    c9.def("CollateByElement", &Constraint2dSolverData::CollateByElement, "childGroups"_a, DOC(Bentley, DgnPlatform, Constraint2dSolverData, CollateByElement));
    c9.def("RemoveElementRef", &Constraint2dSolverData::RemoveElementRef, "elemRef"_a, DOC(Bentley, DgnPlatform, Constraint2dSolverData, RemoveElementRef));
    c9.def("RemoveUnresolvedElementRefs", &Constraint2dSolverData::RemoveUnresolvedElementRefs, DOC(Bentley, DgnPlatform, Constraint2dSolverData, RemoveUnresolvedElementRefs));
    
    c9.def("RemoveInvalidConstraints", [] (Constraint2dSolverData& self, ElementRefP elemRef)
           {
           size_t invalidCount = 0;
           self.RemoveInvalidConstraints(invalidCount, elemRef);
           return invalidCount;
           }, "elemRef"_a, DOC(Bentley, DgnPlatform, Constraint2dSolverData, RemoveInvalidConstraints));

    c9.def("Reverse", &Constraint2dSolverData::Reverse, "elemRef"_a, "curveVector"_a = nullptr, DOC(Bentley, DgnPlatform, Constraint2dSolverData, Reverse));
    c9.def("Replace", &Constraint2dSolverData::Replace, "oldElemRef"_a, "newElemRef"_a);
    c9.def("IsCurvePlaneFixed", &Constraint2dSolverData::IsCurvePlaneFixed, "curveId"_a, DOC(Bentley, DgnPlatform, Constraint2dSolverData, IsCurvePlaneFixed));
    c9.def("IsCurvePlaneConstrained", &Constraint2dSolverData::IsCurvePlaneConstrained, "curveId"_a, DOC(Bentley, DgnPlatform, Constraint2dSolverData, IsCurvePlaneConstrained));
    }