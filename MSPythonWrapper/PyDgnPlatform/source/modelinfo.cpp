/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\modelinfo.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnFileIO/ModelInfo.h>



static const char * __doc_Bentley_DgnPlatform_ModelInfo_HasSameName =R"doc(Determine whether this modelInfo has the same name as another)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_IsNameValid =R"doc(Query if the specified string may be used as a model name)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_IsNameCharValid =R"doc(Query if the specified character may be used in a model name)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_IsTreatedAs3d =R"doc(Query if this is a 3D design model. Happens when model 3d and not a
DgnModelType::Sheet)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetGridAngle =R"doc(@See SetGridParams)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetGridBase =R"doc(@See SetGridParams)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetGridRatio =R"doc(@See SetGridParams)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetGridPerReference =R"doc(@See SetGridParams)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetUorPerGrid =R"doc(@See SetGridParams)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetInsertionBase =R"doc(@See SetInsertionBase)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetSubUnit =R"doc(@See SetWorkingUnits)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetMasterUnit =R"doc(@See SetWorkingUnits)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetStorageUnit =R"doc(@See SetStorageUnit)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetUorPerMeter =R"doc(Convienence method that computes scale factor based on the model's
resolution. @See SetStorageUnit.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetTransparency =R"doc(Get the transparency setting for this model.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetRoundoffRatio =R"doc(Get the roundoff ratio for this model.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetRoundoffUnit =R"doc(Get the roundoff unit for this model.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetModelType =R"doc(Set the type for this model. This is a property. @Remarks When setting
to DgnModelType::Drawing or DgnModelType::Sheet, the background color
is changed to the default for that type. When the ModelInfo is applied
to the model via SetModelInfo, if the type has changed, we force the
ModelInfo BackgroundColor to be consistent with other model's of the
same type. This applies to Sheet and Drawing models.

Parameter ``modelType``:
    The new model type.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetModelType =R"doc(Get the type of this model.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetAnnotationScaleFactor =R"doc(Set the annotation scale factor.

Returns:
    ERROR if the input <= 0.0 @See SetIsUseAnnotationScaleOn. @See
    SetPropagateAnnotationScale. @Remarks This is a property.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetAnnotationScaleFactor =R"doc(@See SetAnnotationScaleFactor)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetDefaultRefLogical =R"doc(@Remarks This is a property.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetDefaultRefLogical =R"doc(Get the default reference logical for this model.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetIsDrawMasterModelLastOn =R"doc(@Remarks This is a property.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetIsDrawMasterModelLastOn =R"doc(@See SetIsDrawMasterModelLastOn)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetIsAutoUpdateFieldsOn =R"doc(@Remarks This is a property.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetIsAutoUpdateFieldsOn =R"doc(@See SetIsAutoUpdateFieldsOn)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetLineStyleScaleMode =R"doc(Set the linestyle scale mode. @See GetLineStyleScale. //!< @Remarks
This is a property.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetLineStyleScaleMode =R"doc(@See SetLineStyleScaleMode, @See GetLineStyleScale)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetPropagateAnnotationScale =R"doc(If true, changes to the model's annotation scale will be propagated to
annotations in the model. @See SetAnnotationScaleFactor. @Remarks This
is a property.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetPropagateAnnotationScale =R"doc(@See SetPropagateAnnotationScale)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetIsAnnotationCell =R"doc(Set the model should be considered the definition of an annotation
cell. @Remarks This is a property.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetIsAnnotationCell =R"doc(@See SetIsAnnotationCell)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetIsInCellList =R"doc(Set if the model should be hidden from a list of cells. @Remarks This
is a property.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetIsInCellList =R"doc(@See SetIsInCellList)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetIsHidden =R"doc(Set if the model is hidden (not in the model list). @Remarks This is a
property.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetIsHidden =R"doc(@See SetIsHidden)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetIs3d =R"doc(Set if the model is 2d/3d property. Cannot change existing models when
calling @See DgnModel::SetModelInfo(). @Remarks This is a property.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetIs3d =R"doc(@See SetIs3d)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetCellType =R"doc(Set the cell library type. @Return Error if the type is not
CellLibraryType::Point, CellLibraryType::Graphic, or
CellLibraryType::Menu. @Remarks This is a property.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetCellType =R"doc(@See SetCellType)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetDescription =R"doc(Set the description. Can be NULL or empty string. @Remarks This is a
property.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetDescription =R"doc(Get the description for this model.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetName =R"doc(Set the name of the model - whitespace is trimmed.

Returns:
    ERROR if length> MAX_MODEL_NAME_LENGTH or if the name is invalid.
    @See IsNameValid @Remarks This is a property.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetName =R"doc(Get the name for this model.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetDirectionBaseDir =R"doc(Change the preferred format for display of directions.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetDirectionBaseDir =R"doc(@See SetDirectionBaseDir)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetDirectionClockwise =R"doc(Change the preferred format for display of directions.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetDirectionClockwise =R"doc(@See SetDirectionClockwise)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetDirectionMode =R"doc(Change the preferred format for display of directions.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetDirectionMode =R"doc(@See SetDirectionMode)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetAngularPrecision =R"doc(Change the preferred precision for display of angles.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetAngularPrecision =R"doc(@See SetAngularPrecision)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetAngularMode =R"doc(Change the preferred format for display of angles.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetAngularMode =R"doc(@See SetAngularMode)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetLinearPrecision =R"doc(Change the preferred precision for display of distances.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetLinearPrecision =R"doc(@See SetLinearPrecision)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetLinearUnitMode =R"doc(Change the preferred format for display of distances.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetLinearUnitMode =R"doc(@See SetLinearUnitMode)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetStorageUnit =R"doc(Change the resolution settings for this model.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetWorkingUnits =R"doc(Set working-units and sub-units. Units must be valid and comparable.
Master unit must be larger than sub unit.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetRoundoffUnit =R"doc(Sets the unit roundoff parameters. Pass in valid pointer to change
value, NULL to do nothing.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetGridParams =R"doc(Sets Grid parameters. Pass in valid pointer to change value, NULL to
do nothing.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetLineStyleScale =R"doc(Sets LineStyle scale.

Returns:
    ERROR if <= 0.0.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetLineStyleScale =R"doc(Gets the line style scale. The returned value may be the model line
style scale, annotation scale, or a compound of both, as defined by
LineStyleScaleMode. @See GetLineStyleScaleMode)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetAzimuth =R"doc(Sets rotation Azimuth.

Returns:
    ERROR if<-180.0 or> 180.0.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetAzimuth =R"doc(@See SetAzimuth)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetSolidExtent =R"doc(Defines an upper bound that limits the extents of any single solid
such that it can be modeled to a fixed precision. Also called Solids
Working Area. Must be >= 0.0.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetSolidExtent =R"doc(@See SetSolidExtent)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetGlobalOrigin =R"doc(Sets an offset that is applied to all cartesian point input and
output.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetGlobalOrigin =R"doc(@See SetGlobalOrigin)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetUorPerStorage =R"doc(@See SetStorageUnit)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetIsUseAnnotationScaleOn =R"doc(When true, the active annotation scale will be applied to new
annotations (text, dimensions, etc.) that are added to the model. @See
SetAnnotationScaleFactor.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetIsUseAnnotationScaleOn =R"doc(@See SetIsUseAnnotationScaleOn;)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetIsoPlane =R"doc(Sets the axes of the isometric drawing plane for use with Isometric
Lock. @See SetIsIsoLocked.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetIsoPlane =R"doc(@See SetIsoPlane)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetIsoGrid =R"doc(When true, the grid will be aligned along lines at 30 degrees from
design plane x-axis and y-axis.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetIsoGrid =R"doc(@See SetIsoGrid)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetIsAcsLocked =R"doc(When ACS Lock is true, user supplied data points will be constrained
to lie on the xy plane of the active ACS.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetIsAcsLocked =R"doc(@See SetIsAcsLocked;)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetIsIsoLocked =R"doc(When Isometric Lock is true, user supplied data points will be
constrained to lie on the Isometric Plane. @See SetIsoPlane.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetIsIsoLocked =R"doc(@See SetIsIsoLocked)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetIsGridLocked =R"doc(When Unit Lock is true, user supplied data points will be constrained
to lie on a grid. @See SetGridParams.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetIsGridLocked =R"doc(@See SetIsGridLocked)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_SetIsUnitLocked =R"doc(When Unit Lock is true, user supplied data points will be constrained
to be at multiples of the roundoff unit. @See SetRoundoffUnit.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_GetIsUnitLocked =R"doc(@See SetIsUnitLocked)doc";

static const char * __doc_Bentley_DgnPlatform_ModelInfo_MakeCopy =R"doc(Make a copy of this ModelInfo. Use this when attempting to change a
ModelInfo associated with a model.

``
ModelInfoPtr modelInfo = dgnModel.GetModelInfo().MakeCopy();
  if (SUCCESS != modelInfo->SetValue (newValue))
   {...}   // handle error.
  if (DGNMODEL_STATUS_Success == dgnModel.SetModelInfo (*modelInfo))
    {...}    // changes are now applied to the model.
``)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ModelInfo(py::module_& m)
    {
    //===================================================================================
    // enum class NamedViewProp
    py::enum_< IsoPlaneValues>(m, "IsoPlaneValues")
        .value("eIsoPlaneTop", IsoPlaneValues::IsoPlaneTop)
        .value("eIsoPlaneLeft", IsoPlaneValues::IsoPlaneLeft)
        .value("eIsoPlaneRight", IsoPlaneValues::IsoPlaneRight)
        .value("eIsoPlaneAll", IsoPlaneValues::IsoPlaneAll)
        .export_values();

    //===================================================================================
    // struct ModelInfo
    py::class_< ModelInfo, ModelInfoPtr> c1(m, "ModelInfo");

    if (true)
        {
        //===================================================================================
        // enum LineStyleScaleMode
        py::enum_<ModelInfo::LineStyleScaleMode>(c1, "LineStyleScaleMode", py::arithmetic())
            .value("eLSSCALEMODE_LineStyleScale", ModelInfo::LSSCALEMODE_LineStyleScale)
            .value("eLSSCALEMODE_AnnotationScale", ModelInfo::LSSCALEMODE_AnnotationScale)
            .value("eLSSCALEMODE_CompoundScale", ModelInfo::LSSCALEMODE_CompoundScale)
            .export_values();
        }

    c1.def(py::init(py::overload_cast<>(&ModelInfo::Create)));
    c1.def(py::init(py::overload_cast<DgnModelType, WCharCP, bool>(&ModelInfo::Create)), "type"_a, "name"_a, "is3d"_a);
    c1.def("MakeCopy", &ModelInfo::MakeCopy, DOC(Bentley, DgnPlatform, ModelInfo, MakeCopy));

    c1.def_property("IsUnitLocked", &ModelInfo::GetIsUnitLocked, &ModelInfo::SetIsUnitLocked);
    c1.def("GetIsUnitLocked", &ModelInfo::GetIsUnitLocked, DOC(Bentley, DgnPlatform, ModelInfo, GetIsUnitLocked));
    c1.def("SetIsUnitLocked", &ModelInfo::SetIsUnitLocked, "locked"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetIsUnitLocked));
    
    c1.def_property("IsGridLocked", &ModelInfo::GetIsGridLocked, &ModelInfo::SetIsGridLocked);
    c1.def("GetIsGridLocked", &ModelInfo::GetIsGridLocked, DOC(Bentley, DgnPlatform, ModelInfo, GetIsGridLocked));
    c1.def("SetIsGridLocked", &ModelInfo::SetIsGridLocked, "locked"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetIsGridLocked));
    
    c1.def_property("IsIsoLocked", &ModelInfo::GetIsIsoLocked, &ModelInfo::SetIsIsoLocked);
    c1.def("GetIsIsoLocked", &ModelInfo::GetIsIsoLocked, DOC(Bentley, DgnPlatform, ModelInfo, GetIsIsoLocked));
    c1.def("SetIsIsoLocked", &ModelInfo::SetIsIsoLocked, "locked"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetIsIsoLocked));
    
    c1.def_property("IsAcsLocked", &ModelInfo::GetIsAcsLocked, &ModelInfo::SetIsAcsLocked);
    c1.def("GetIsAcsLocked", &ModelInfo::GetIsAcsLocked, DOC(Bentley, DgnPlatform, ModelInfo, GetIsAcsLocked));
    c1.def("SetIsAcsLocked", &ModelInfo::SetIsAcsLocked, "locked"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetIsAcsLocked));
    
    c1.def_property("IsoGrid", &ModelInfo::GetIsoGrid, &ModelInfo::SetIsoGrid);
    c1.def("GetIsoGrid", &ModelInfo::GetIsoGrid, DOC(Bentley, DgnPlatform, ModelInfo, GetIsoGrid));
    c1.def("SetIsoGrid", &ModelInfo::SetIsoGrid, "isGrid"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetIsoGrid));
    
    c1.def_property("IsoPlane", &ModelInfo::GetIsoPlane, &ModelInfo::SetIsoPlane);
    c1.def("GetIsoPlane", &ModelInfo::GetIsoPlane, DOC(Bentley, DgnPlatform, ModelInfo, GetIsoPlane));
    c1.def("SetIsoPlane", &ModelInfo::SetIsoPlane, "value"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetIsoPlane));
    
    c1.def_property("IsUseAnnotationScaleOn", &ModelInfo::GetIsUseAnnotationScaleOn, &ModelInfo::SetIsUseAnnotationScaleOn);
    c1.def("GetIsUseAnnotationScaleOn", &ModelInfo::GetIsUseAnnotationScaleOn, DOC(Bentley, DgnPlatform, ModelInfo, GetIsUseAnnotationScaleOn));
    c1.def("SetIsUseAnnotationScaleOn", &ModelInfo::SetIsUseAnnotationScaleOn, "scaleOn"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetIsUseAnnotationScaleOn));
    
    c1.def_property("UorPerStorage", py::overload_cast<>(&ModelInfo::GetUorPerStorage, py::const_), &ModelInfo::SetUorPerStorageUnit);
    c1.def("GetUorPerStorage", py::overload_cast<>(&ModelInfo::GetUorPerStorage, py::const_), DOC(Bentley, DgnPlatform, ModelInfo, GetUorPerStorage));
    c1.def("SetUorPerStorage", &ModelInfo::SetUorPerStorageUnit, "uor"_a);
    
    c1.def_property("GlobalOrigin", py::overload_cast<>(&ModelInfo::GetGlobalOrigin, py::const_), &ModelInfo::SetGlobalOrigin);
    c1.def("GetGlobalOrigin", py::overload_cast<>(&ModelInfo::GetGlobalOrigin, py::const_), py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ModelInfo, GetGlobalOrigin));
    c1.def("SetGlobalOrigin", &ModelInfo::SetGlobalOrigin, "origin"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetGlobalOrigin));
    
    c1.def_property("SolidExtent", &ModelInfo::GetSolidExtent, &ModelInfo::SetSolidExtent);
    c1.def("GetSolidExtent", &ModelInfo::GetSolidExtent, DOC(Bentley, DgnPlatform, ModelInfo, GetSolidExtent));
    c1.def("SetSolidExtent", &ModelInfo::SetSolidExtent, "extent"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetSolidExtent));
    
    c1.def_property("Azimuth", &ModelInfo::GetAzimuth, &ModelInfo::SetAzimuth);
    c1.def("GetAzimuth", &ModelInfo::GetAzimuth, DOC(Bentley, DgnPlatform, ModelInfo, GetAzimuth));
    c1.def("SetAzimuth", &ModelInfo::SetAzimuth, "azimuth"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetAzimuth));
    
    c1.def_property("LineStyleScale", &ModelInfo::GetLineStyleScale, &ModelInfo::SetLineStyleScale);
    c1.def("GetLineStyleScale", &ModelInfo::GetLineStyleScale, DOC(Bentley, DgnPlatform, ModelInfo, GetLineStyleScale));
    c1.def("SetLineStyleScale", &ModelInfo::SetLineStyleScale, "scale"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetLineStyleScale));
    
    c1.def("SetGridParams",
        [](ModelInfoR self, boost::optional<double> uorPerGrid, boost::optional<UInt32> gridPerReference, boost::optional<double> gridRatio, DPoint2dCP gridBase, boost::optional<double> gridAngle)
        {
            self.SetGridParams(uorPerGrid.get_ptr(), gridPerReference.get_ptr(), gridRatio.get_ptr(), gridBase, gridAngle.get_ptr());
        }, 
        "uorPerGrid"_a, "gridPerReference"_a, "gridRatio"_a, "gridBase"_a, "gridAngle"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetGridParams));
    c1.def("SetRoundoffUnit",
        [](ModelInfoR self, boost::optional<double> roundoffUnit, boost::optional<double> roundoffRatio)
        {
            self.SetRoundoffUnit(roundoffUnit.get_ptr(), roundoffRatio.get_ptr());
        }, "roundOffUnit"_a, "roundOffRatio"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetRoundoffUnit));
    c1.def("SetWorkingUnits", py::overload_cast<UnitDefinitionCR, UnitDefinitionCR>(&ModelInfo::SetWorkingUnits), "newMasterUnit"_a, "newSubUnit"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetWorkingUnits));
    c1.def("SetStorageUnit", &ModelInfo::SetStorageUnit, "newStorageUnit"_a, "uorPerStorage"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetStorageUnit));
    
    c1.def_property("LinearUnitMode", &ModelInfo::GetLinearUnitMode, &ModelInfo::SetLinearUnitMode);
    c1.def("GetLinearUnitMode", &ModelInfo::GetLinearUnitMode, DOC(Bentley, DgnPlatform, ModelInfo, GetLinearUnitMode));
    c1.def("SetLinearUnitMode", &ModelInfo::SetLinearUnitMode, "mode"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetLinearUnitMode));
    
    c1.def_property("LinearPrecision", &ModelInfo::GetLinearPrecision, &ModelInfo::SetLinearPrecision);
    c1.def("GetLinearPrecision", &ModelInfo::GetLinearPrecision, DOC(Bentley, DgnPlatform, ModelInfo, GetLinearPrecision));
    c1.def("SetLinearPrecision", &ModelInfo::SetLinearPrecision, "precision"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetLinearPrecision));
    
    c1.def_property("AngularMode", &ModelInfo::GetAngularMode, &ModelInfo::SetAngularMode);
    c1.def("GetAngularMode", &ModelInfo::GetAngularMode, DOC(Bentley, DgnPlatform, ModelInfo, GetAngularMode));
    c1.def("SetAngularMode", &ModelInfo::SetAngularMode, "mode"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetAngularMode));
    
    c1.def_property("AngularPrecision", &ModelInfo::GetAngularPrecision, &ModelInfo::SetAngularPrecision);
    c1.def("GetAngularPrecision", &ModelInfo::GetAngularPrecision, DOC(Bentley, DgnPlatform, ModelInfo, GetAngularPrecision));
    c1.def("SetAngularPrecision", &ModelInfo::SetAngularPrecision, "precision"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetAngularPrecision));
    
    c1.def_property("DirectionMode", &ModelInfo::GetDirectionMode, &ModelInfo::SetDirectionMode);
    c1.def("GetDirectionMode", &ModelInfo::GetDirectionMode, DOC(Bentley, DgnPlatform, ModelInfo, GetDirectionMode));
    c1.def("SetDirectionMode", &ModelInfo::SetDirectionMode, "mode"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetDirectionMode));
    
    c1.def_property("DirectionClockwise", &ModelInfo::GetDirectionClockwise, &ModelInfo::SetDirectionClockwise);
    c1.def("GetDirectionClockwise", &ModelInfo::GetDirectionClockwise, DOC(Bentley, DgnPlatform, ModelInfo, GetDirectionClockwise));
    c1.def("SetDirectionClockwise", &ModelInfo::SetDirectionClockwise, "cw"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetDirectionClockwise));
    
    c1.def_property("DirectionBaseDir", &ModelInfo::GetDirectionBaseDir, &ModelInfo::SetDirectionBaseDir);    
    c1.def("GetDirectionBaseDir", &ModelInfo::GetDirectionBaseDir, DOC(Bentley, DgnPlatform, ModelInfo, GetDirectionBaseDir));
    c1.def("SetDirectionBaseDir", &ModelInfo::SetDirectionBaseDir, "baseDir"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetDirectionBaseDir));
    
    c1.def_property("Name", &ModelInfo::GetName, &ModelInfo::SetName);
    c1.def("GetName", &ModelInfo::GetName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ModelInfo, GetName));
    c1.def("SetName", &ModelInfo::SetName, "name"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetName));
    
    c1.def_property("Description", &ModelInfo::GetDescription, &ModelInfo::SetDescription);
    c1.def("GetDescription", &ModelInfo::GetDescription, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ModelInfo, GetDescription));
    c1.def("SetDescription", &ModelInfo::SetDescription, "description"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetDescription));
    
    c1.def_property("CellType", &ModelInfo::GetCellType, &ModelInfo::SetCellType);
    c1.def("GetCellType", &ModelInfo::GetCellType, DOC(Bentley, DgnPlatform, ModelInfo, GetCellType));
    c1.def("SetCellType", &ModelInfo::SetCellType, "cellType"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetCellType));
    
    c1.def_property("Is3d", &ModelInfo::GetIs3d, &ModelInfo::SetIs3d);
    c1.def("GetIs3d", &ModelInfo::GetIs3d, DOC(Bentley, DgnPlatform, ModelInfo, GetIs3d));
    c1.def("SetIs3d", &ModelInfo::SetIs3d, "is3d"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetIs3d));
    
    c1.def_property("IsHidden", &ModelInfo::GetIsHidden, &ModelInfo::SetIsHidden);
    c1.def("GetIsHidden", &ModelInfo::GetIsHidden, DOC(Bentley, DgnPlatform, ModelInfo, GetIsHidden));
    c1.def("SetIsHidden", &ModelInfo::SetIsHidden, "isHidden"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetIsHidden));
    
    c1.def_property("IsInCellList", &ModelInfo::GetIsInCellList, &ModelInfo::SetIsInCellList);
    c1.def("GetIsInCellList", &ModelInfo::GetIsInCellList, DOC(Bentley, DgnPlatform, ModelInfo, GetIsInCellList));
    c1.def("SetIsInCellList", &ModelInfo::SetIsInCellList, "inCellList"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetIsInCellList));
    
    c1.def_property("IsAnnotationCell", &ModelInfo::GetIsAnnotationCell, &ModelInfo::SetIsAnnotationCell);
    c1.def("GetIsAnnotationCell", &ModelInfo::GetIsAnnotationCell, DOC(Bentley, DgnPlatform, ModelInfo, GetIsAnnotationCell));
    c1.def("SetIsAnnotationCell", &ModelInfo::SetIsAnnotationCell, "isAnnotationCell"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetIsAnnotationCell));
    
    c1.def_property("PropagateAnnotationScale", &ModelInfo::GetPropagateAnnotationScale, &ModelInfo::SetPropagateAnnotationScale);
    c1.def("GetPropagateAnnotationScale", &ModelInfo::GetPropagateAnnotationScale, DOC(Bentley, DgnPlatform, ModelInfo, GetPropagateAnnotationScale));
    c1.def("SetPropagateAnnotationScale", &ModelInfo::SetPropagateAnnotationScale, "scale"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetPropagateAnnotationScale));
    
    c1.def_property("LineStyleScaleMode", &ModelInfo::GetLineStyleScaleMode, &ModelInfo::SetLineStyleScaleMode);
    c1.def("GetLineStyleScaleMode", &ModelInfo::GetLineStyleScaleMode, DOC(Bentley, DgnPlatform, ModelInfo, GetLineStyleScaleMode));
    c1.def("SetLineStyleScaleMode", &ModelInfo::SetLineStyleScaleMode, "mode"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetLineStyleScaleMode));
    
    c1.def_property("IsAutoUpdateFieldsOn", &ModelInfo::GetIsAutoUpdateFieldsOn, &ModelInfo::SetIsAutoUpdateFieldsOn);
    c1.def("GetIsAutoUpdateFieldsOn", &ModelInfo::GetIsAutoUpdateFieldsOn, DOC(Bentley, DgnPlatform, ModelInfo, GetIsAutoUpdateFieldsOn));
    c1.def("SetIsAutoUpdateFieldsOn", &ModelInfo::SetIsAutoUpdateFieldsOn, "isOn"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetIsAutoUpdateFieldsOn));
    
    c1.def_property("IsDrawMasterModelLastOn", &ModelInfo::GetIsDrawMasterModelLastOn, &ModelInfo::SetIsDrawMasterModelLastOn);
    c1.def("GetIsDrawMasterModelLastOn", &ModelInfo::GetIsDrawMasterModelLastOn, DOC(Bentley, DgnPlatform, ModelInfo, GetIsDrawMasterModelLastOn));
    c1.def("SetIsDrawMasterModelLastOn", &ModelInfo::SetIsDrawMasterModelLastOn, "isOn"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetIsDrawMasterModelLastOn));
    
    c1.def_property("DefaultRefLogical", &ModelInfo::GetDefaultRefLogical, &ModelInfo::SetDefaultRefLogical);
    c1.def("GetDefaultRefLogical", &ModelInfo::GetDefaultRefLogical, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ModelInfo, GetDefaultRefLogical));
    c1.def("SetDefaultRefLogical", &ModelInfo::SetDefaultRefLogical, "logical"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetDefaultRefLogical));
    
    c1.def_property("AnnotationScaleFactor", &ModelInfo::GetAnnotationScaleFactor, &ModelInfo::SetAnnotationScaleFactor);
    c1.def("GetAnnotationScaleFactor", &ModelInfo::GetAnnotationScaleFactor, DOC(Bentley, DgnPlatform, ModelInfo, GetAnnotationScaleFactor));
    c1.def("SetAnnotationScaleFactor", &ModelInfo::SetAnnotationScaleFactor, "factor"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetAnnotationScaleFactor));
    
    c1.def_property("ModelType", &ModelInfo::GetModelType, &ModelInfo::SetModelType);
    c1.def("GetModelType", &ModelInfo::GetModelType, DOC(Bentley, DgnPlatform, ModelInfo, GetModelType));
    c1.def("SetModelType", &ModelInfo::SetModelType, "type"_a, DOC(Bentley, DgnPlatform, ModelInfo, SetModelType));

    c1.def("__eq__", [] (ModelInfoCR self, ModelInfoCR other) { return self.IsEqual(other); });
    
    c1.def_property_readonly("RoundoffUnit", &ModelInfo::GetRoundoffUnit);
    c1.def("GetRoundoffUnit", &ModelInfo::GetRoundoffUnit, DOC(Bentley, DgnPlatform, ModelInfo, GetRoundoffUnit));
    
    c1.def_property_readonly("RoundoffRatio", &ModelInfo::GetRoundoffRatio);
    c1.def("GetRoundoffRatio", &ModelInfo::GetRoundoffRatio, DOC(Bentley, DgnPlatform, ModelInfo, GetRoundoffRatio));
    
    c1.def_property_readonly("Transparency", &ModelInfo::GetTransparency);
    c1.def("GetTransparency", &ModelInfo::GetTransparency, DOC(Bentley, DgnPlatform, ModelInfo, GetTransparency));
    
    c1.def_property_readonly("UorPerMeter", py::overload_cast<>(&ModelInfo::GetUorPerMeter, py::const_));
    c1.def("GetUorPerMeter", py::overload_cast<>(&ModelInfo::GetUorPerMeter, py::const_), DOC(Bentley, DgnPlatform, ModelInfo, GetUorPerMeter));
    
    c1.def_property_readonly("StorageUnit", py::overload_cast<>(&ModelInfo::GetStorageUnit, py::const_));
    c1.def("GetStorageUnit", py::overload_cast<>(&ModelInfo::GetStorageUnit, py::const_), DOC(Bentley, DgnPlatform, ModelInfo, GetStorageUnit));
    
    c1.def_property_readonly("MasterUnit", py::overload_cast<>(&ModelInfo::GetMasterUnit, py::const_));
    c1.def("GetMasterUnit", py::overload_cast<>(&ModelInfo::GetMasterUnit, py::const_), DOC(Bentley, DgnPlatform, ModelInfo, GetMasterUnit));
    
    c1.def_property_readonly("SubUnit", py::overload_cast<>(&ModelInfo::GetSubUnit, py::const_));
    c1.def("GetSubUnit", py::overload_cast<>(&ModelInfo::GetSubUnit, py::const_), DOC(Bentley, DgnPlatform, ModelInfo, GetSubUnit));
    
    c1.def_property_readonly("InsertionBase", &ModelInfo::GetInsertionBase);
    c1.def("GetInsertionBase", &ModelInfo::GetInsertionBase, DOC(Bentley, DgnPlatform, ModelInfo, GetInsertionBase));
    
    c1.def_property_readonly("UorPerGrid", &ModelInfo::GetUorPerGrid);
    c1.def("GetUorPerGrid", &ModelInfo::GetUorPerGrid, DOC(Bentley, DgnPlatform, ModelInfo, GetUorPerGrid));
    
    c1.def_property_readonly("GridPerReference", &ModelInfo::GetGridPerReference);
    c1.def("GetGridPerReference", &ModelInfo::GetGridPerReference, DOC(Bentley, DgnPlatform, ModelInfo, GetGridPerReference));
    
    c1.def_property_readonly("GridRatio", &ModelInfo::GetGridRatio);
    c1.def("GetGridRatio", &ModelInfo::GetGridRatio, DOC(Bentley, DgnPlatform, ModelInfo, GetGridRatio));
    
    c1.def_property_readonly("GridBase", &ModelInfo::GetGridBase);
    c1.def("GetGridBase", &ModelInfo::GetGridBase, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ModelInfo, GetGridBase));
    
    c1.def_property_readonly("GridAngle", &ModelInfo::GetGridAngle);
    c1.def("GetGridAngle", &ModelInfo::GetGridAngle, DOC(Bentley, DgnPlatform, ModelInfo, GetGridAngle));
    
    c1.def_property_readonly("SheetDef", &ModelInfo::GetSheetDefP);
    c1.def("GetSheetDef", &ModelInfo::GetSheetDefP, py::return_value_policy::reference_internal);
    
    c1.def("IsTreatedAs3d", &ModelInfo::IsTreatedAs3d, DOC(Bentley, DgnPlatform, ModelInfo, IsTreatedAs3d));
    c1.def_static("IsNameCharValid", &ModelInfo::IsNameCharValid, "nameChar"_a, DOC(Bentley, DgnPlatform, ModelInfo, IsNameCharValid));
    c1.def_static("IsNameValid", &ModelInfo::IsNameValid, "name"_a, DOC(Bentley, DgnPlatform, ModelInfo, IsNameValid));
    c1.def("HasSameName", &ModelInfo::HasSameName, "modelInfo"_a, DOC(Bentley, DgnPlatform, ModelInfo, HasSameName));
    }