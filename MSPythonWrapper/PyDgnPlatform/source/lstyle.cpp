/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\lstyle.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/lstyle.h>



static const char * __doc_Bentley_DgnPlatform_LsLinePointComponent_GetLineCodeType =R"doc(LineCode or Internal)doc";

static const char * __doc_Bentley_DgnPlatform_LsStrokeData_Duplicate =R"doc(Duplicate a stroke, usually to populate the LsLineCodeComponent.

:returns:
    A smart pointer to a full copy of the stroke.)doc";

static const char * __doc_Bentley_DgnPlatform_LsStrokeData_Create =R"doc(Create a new stroke. A stroke is one piece of a line code, either a
Dash or a Gap. Each stroke in the pattern can have its own parameters
defining the behavior.

:param isDash:
    True to a Dash, false to make a Pap.

:param length:
    The lenght of the stroke.

:returns:
    A smart pointer to a new stroke)doc";

static const char * __doc_Bentley_DgnPlatform_LsStrokeData_SetStretchable =R"doc(Set whether the stroke can be stretched to fit segments to allow them
to end on a dash, or to support a fixed number of iterations.

:param stretchable:
    True to make it stretchable, false for fixed length.

See also:
    IsStretchable())doc";

static const char * __doc_Bentley_DgnPlatform_LsStrokeData_IsStretchable =R"doc(Check if the stroke can be stretched to fit segment lengths.

:returns:
    If stroke is strechable (variable length).

See also:
    SetStretchable())doc";

static const char * __doc_Bentley_DgnPlatform_LsStrokeData_SetBypassCorner =R"doc(Set whether the stroke should bypass or break at a corner of a
linestring, etc. True (bypass) means to continue the stroke after the
corner. False (break) means that the stroke should terminate at the
corner and the next stroke in the Line Code will begin the next
segment of the element.

:param bypass:
    True to make it bypass, false for break.

See also:
    BypassCorner())doc";

static const char * __doc_Bentley_DgnPlatform_LsStrokeData_BypassCorner =R"doc(Check if the stroke should bypass or break at a corner of a
linestring, etc.

:returns:
    True if the stroke should bypass the corner and continue on, False
    if it breaks at the corner and a the next stroke should begin
    after the corner.

See also:
    SetBypassCorner())doc";

static const char * __doc_Bentley_DgnPlatform_LsStrokeData_SetDash =R"doc(Set whether the stroke is a dash or a gap.

:param isDash:
    True to make it a dash, false for gap.

See also:
    IsDash())doc";

static const char * __doc_Bentley_DgnPlatform_LsStrokeData_IsDash =R"doc(Check if the stroke is a dash or gap.

:returns:
    True if it is a dash, false for a gap.

See also:
    SetDash())doc";

static const char * __doc_Bentley_DgnPlatform_LsStrokeData_SetCapMode =R"doc(Set the cap mode for the stroke. Strokes with width can show the end
of the dash differently.

:param capMode:
    The new cap mode for the stroke. remarks This is ignored for Gaps.

See also:
    GetCapMode())doc";

static const char * __doc_Bentley_DgnPlatform_LsStrokeData_GetCapMode =R"doc(Get the cap mode for the stroke. Strokes with width can show the end
of the dash differently.

:returns:
    the type of cap for this stroke. remarks This is ignored for Gaps.

See also:
    SetCapMode())doc";

static const char * __doc_Bentley_DgnPlatform_LsStrokeData_SetEndWidth =R"doc(Set the end width for the stroke. By default the end width is the same
as the start width so unless taper is desired this does not need to be
called.

:param width:
    The new end width for the stroke. remarks This only applies to
    Dashes (not Gaps).

See also:
    GetEndWidth())doc";

static const char * __doc_Bentley_DgnPlatform_LsStrokeData_GetEndWidth =R"doc(Get the end width for the stroke. By default the end width is the same
as the start width.

:returns:
    The end width for the stroke remarks This only applies to Dashes
    (not Gaps).

See also:
    SetEndWidth())doc";

static const char * __doc_Bentley_DgnPlatform_LsStrokeData_SetStartWidth =R"doc(Set the start width for the stroke. By default this will set width for
the dash unless the end width is set for a taper.

:param width:
    The new start width for the stroke. remarks This only applies to
    Dashes (not Gaps).

See also:
    GetStartWidth())doc";

static const char * __doc_Bentley_DgnPlatform_LsStrokeData_GetStartWidth =R"doc(Get the start width for the stroke. By default if there is no end
width this is the width of the entire dash.

:returns:
    The start width or width for the stroke remarks This only applies
    to Dashes (not Gaps).

See also:
    SetStartWidth())doc";

static const char * __doc_Bentley_DgnPlatform_LsStrokeData_SetLength =R"doc(Set the lenght of the stroke.

:param length:
    The new length for the stroke. remarks This only applies to Dashes
    (not Gaps).

See also:
    GetLength())doc";

static const char * __doc_Bentley_DgnPlatform_LsStrokeData_GetLength =R"doc(Get the length of the stroke.

:returns:
    The length of the stroke

See also:
    SetLength())doc";

static const char * __doc_Bentley_DgnPlatform_LineStyleHandle_IsPhysical =R"doc(Line styles are physical and should be scaled as such. This only
applies to styles in dgnlibs, not resources. Default is false.)doc";

static const char * __doc_Bentley_DgnPlatform_LineStyleHandle_IsSharedCellScaleIndependent =R"doc(Make the line scale independent of scale of shared cells. This is for
DWG. Default is false.)doc";

static const char * __doc_Bentley_DgnPlatform_LineStyleHandle_IsUsedForRange =R"doc(Normally styles are used for element range, but certain styles
(usually from DWG) should not be. Default is true.)doc";

static const char * __doc_Bentley_DgnPlatform_LineStyleHandle_IsSnappable =R"doc(If true, snap to various points on the linestyle; if false only snap
to the center line. Default is false.)doc";

static const char * __doc_Bentley_DgnPlatform_LineStyleHandle_GetOverrideId =R"doc(Used to set a specific positive ID when a style is coming from a
resource file. This is only for support of some very specific products
from 20 years ago; it is never a good idea to use it on new styles.
You should only reference linestyles by name.)doc";

static const char * __doc_Bentley_DgnPlatform_LineStyleHandle_GetStyleScale =R"doc(Defines a scaling factor to be applied to the components. This was for
resources; set to 1.0 (default) for DGNLIBs.)doc";

static const char * __doc_Bentley_DgnPlatform_LineStyleHandle_GetUnitsType =R"doc(Whether the units of the style are in UORs, Master, or Pixels. If it
is stored in a DGNLIB, do not use Master.)doc";

static const char * __doc_Bentley_DgnPlatform_LineStyleHandle_GetId =R"doc(The linestyle ID used by elements in the current file.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_lstyle(py::module_& m)
    {

    //===================================================================================
    // enum LineStyleDwgExportReason
    py::enum_< LineStyleDwgExportReason>(m, "LineStyleDwgExportReason", py::arithmetic())
        .value("eLS_DWG_Ok", LS_DWG_Ok)
        .value("eLS_DWG_NoComponents", LS_DWG_NoComponents)
        .value("eLS_DWG_ShxOnlyCompatSet", LS_DWG_ShxOnlyCompatSet)
        .value("eLS_DWG_CompoundHasOffsets", LS_DWG_CompoundHasOffsets)
        .value("eLS_DWG_TooManySegments", LS_DWG_TooManySegments)
        .value("eLS_DWG_SymbolAtStartOrEnd", LS_DWG_SymbolAtStartOrEnd)
        .value("eLS_DWG_PartialWidthDash", LS_DWG_PartialWidthDash)
        .value("eLS_DWG_OpenDashCap", LS_DWG_OpenDashCap)
        .value("eLS_DWG_WidthsChange", LS_DWG_WidthsChange)
        .value("eLS_DWG_WidthTapers", LS_DWG_WidthTapers)
        .value("eLS_DWG_IterationLimit", LS_DWG_IterationLimit)
        .export_values();

    //===================================================================================
    // struct LineStyleHandle
    py::class_< LineStyleHandle, LineStyleHandlePtr> c1(m, "LineStyleHandle");

    c1.def_property("Id", &LineStyleHandle::GetId, &LineStyleHandle::SetId);
    c1.def("GetId", &LineStyleHandle::GetId, DOC(Bentley, DgnPlatform, LineStyleHandle, GetId));
    c1.def("SetId", &LineStyleHandle::SetId, "Id"_a);
    
    c1.def_property("Name", &LineStyleHandle::GetName, &LineStyleHandle::SetName);
    c1.def("GetName", &LineStyleHandle::GetName, py::return_value_policy::reference_internal);
    c1.def("SetName", &LineStyleHandle::SetName, "name"_a);

    c1.def_property("Component", &LineStyleHandle::GetComponent, &LineStyleHandle::SetComponent);
    c1.def("GetComponent", &LineStyleHandle::GetComponent);
    c1.def("SetComponent", &LineStyleHandle::SetComponent, "newComp"_a);
    
    c1.def_property("UnitsType", &LineStyleHandle::GetUnitsType, &LineStyleHandle::SetUnitsType);
    c1.def("GetUnitsType", &LineStyleHandle::GetUnitsType, DOC(Bentley, DgnPlatform, LineStyleHandle, GetUnitsType));
    c1.def("SetUnitsType", &LineStyleHandle::SetUnitsType, "unitType"_a);
    
    c1.def_property("StyleScale", &LineStyleHandle::GetStyleScale, &LineStyleHandle::SetStyleScale);
    c1.def("GetStyleScale", &LineStyleHandle::GetStyleScale, DOC(Bentley, DgnPlatform, LineStyleHandle, GetStyleScale));
    c1.def("SetStyleScale", &LineStyleHandle::SetStyleScale, "scale"_a);
    
    c1.def_property("OverrideId", &LineStyleHandle::GetOverrideId, &LineStyleHandle::SetOverrideId);
    c1.def("GetOverrideId", &LineStyleHandle::GetOverrideId, DOC(Bentley, DgnPlatform, LineStyleHandle, GetOverrideId));
    c1.def("SetOverrideId", &LineStyleHandle::SetOverrideId, "id"_a);
    
    c1.def_property("Snappable", &LineStyleHandle::IsSnappable, &LineStyleHandle::SetSnappable);
    c1.def("IsSnappable", &LineStyleHandle::IsSnappable, DOC(Bentley, DgnPlatform, LineStyleHandle, IsSnappable));
    c1.def("SetSnappable", &LineStyleHandle::SetSnappable, "snappable"_a);
    
    c1.def_property("UsedForRange", &LineStyleHandle::IsUsedForRange, &LineStyleHandle::SetUsedForRange);
    c1.def("IsUsedForRange", &LineStyleHandle::IsUsedForRange, DOC(Bentley, DgnPlatform, LineStyleHandle, IsUsedForRange));
    c1.def("SetUsedForRange", &LineStyleHandle::SetUsedForRange, "used"_a);
    
    c1.def_property("SharedCellScaleIndependent", &LineStyleHandle::IsSharedCellScaleIndependent, &LineStyleHandle::SetSharedCellScaleIndependent);
    c1.def("IsSharedCellScaleIndependent", &LineStyleHandle::IsSharedCellScaleIndependent, DOC(Bentley, DgnPlatform, LineStyleHandle, IsSharedCellScaleIndependent));
    c1.def("SetSharedCellScaleIndependent", &LineStyleHandle::SetSharedCellScaleIndependent, "newVal"_a);
    
    c1.def_property("Physical", &LineStyleHandle::IsPhysical, &LineStyleHandle::SetPhysical);
    c1.def("IsPhysical", &LineStyleHandle::IsPhysical, DOC(Bentley, DgnPlatform, LineStyleHandle, IsPhysical));
    c1.def("SetPhysical", &LineStyleHandle::SetPhysical, "newVal"_a);
    
    c1.def("AddToDgn", &LineStyleHandle::AddToDgn, "dgnFile"_a);
    c1.def("AddAllToDgn", &LineStyleHandle::AddAllToDgn, "dgnFile"_a);
    c1.def("AddToRsc", &LineStyleHandle::AddToRsc, "resourceFile"_a);
    c1.def("AddAllToRsc", &LineStyleHandle::AddAllToRsc, "resourceFile"_a);
    c1.def("Replace", &LineStyleHandle::Replace, "oldName"_a);
    c1.def("ReplaceAll", &LineStyleHandle::ReplaceAll);
    c1.def_static("Create", py::overload_cast<WCharCP>(&LineStyleHandle::Create), "name"_a);
    c1.def_static("GetStyleHandle", py::overload_cast<WCharCP, DgnFileR>(&LineStyleHandle::GetStyleHandle), "name"_a, "dgnFile"_a);
    c1.def_static("GetStyleHandle", py::overload_cast<WCharCP, RscFileHandle>(&LineStyleHandle::GetStyleHandle), "name"_a, "rscFile"_a);

    //===================================================================================
    // struct LsComponent
    py::class_< LsComponent, LsComponentPtr> c2(m, "LsComponent");

    c2.def_property_readonly("Type", &LsComponent::GetType);
    c2.def("GetType", &LsComponent::GetType);
    
    c2.def_property_readonly("Name", &LsComponent::GetName);
    c2.def("GetName", &LsComponent::GetName, py::return_value_policy::reference_internal);

    c2.def("Duplicate", &LsComponent::Duplicate);
    c2.def("AddToDgn", &LsComponent::AddToDgn, "dgnFile"_a);
    c2.def("AddToRsc", &LsComponent::AddToRsc, "rscFile"_a);
    c2.def("Replace", &LsComponent::Replace, "oldName"_a);
    c2.def_static("CreateCompoundComponent", &LsComponent::CreateCompoundComponent, "name"_a);
    c2.def_static("CreateLineCodeComponent", &LsComponent::CreateLineCodeComponent, "name"_a);
    c2.def_static("CreateInternalComponent", &LsComponent::CreateInternalComponent, "lineCode"_a);
    c2.def_static("CreatePointSymbolComponent", &LsComponent::CreatePointSymbolComponent, "name"_a);
    c2.def_static("CreateLinePointComponent", &LsComponent::CreateLinePointComponent, "name"_a);
    c2.def_static("GetAllComponents", py::overload_cast<LsComponentVector&, DgnFileR>(&LsComponent::GetAllComponents), "components"_a, "dgnFile"_a);
    c2.def_static("GetAllComponents", py::overload_cast<LsComponentVector&, RscFileHandle>(&LsComponent::GetAllComponents), "components"_a, "rscFile"_a);
    c2.def_static("GetComponent", py::overload_cast<LsElementType, WCharCP, DgnFileR>(&LsComponent::GetComponent), "type"_a, "name"_a, "dgnFile"_a);
    c2.def_static("GetComponent", py::overload_cast<LsElementType, WCharCP, RscFileHandle>(&LsComponent::GetComponent), "type"_a, "name"_a, "rscFile"_a);
    
    c2.def_property_readonly("ComponentId", &LsComponent::GetComponentId);
    c2.def("GetComponentId", &LsComponent::GetComponentId);

    //===================================================================================
    // struct LsCompoundComponent
    py::class_< LsCompoundComponent, LsCompoundComponentPtr, LsComponent> c4(m, "LsCompoundComponent");

    c4.def_property_readonly("NumComponents", &LsCompoundComponent::GetNumComponents);
    c4.def("GetNumComponents", &LsCompoundComponent::GetNumComponents);

    c4.def("GetComponent", &LsCompoundComponent::GetComponent, "iComp"_a);
    c4.def("GetComponentOffset", &LsCompoundComponent::GetComponentOffset, "iComp"_a);
    c4.def("SetComponentOffset", &LsCompoundComponent::SetComponentOffset, "iComp"_a, "offset"_a);
    c4.def("AppendComponent", &LsCompoundComponent::AppendComponent, "component"_a, "offset"_a);
    c4.def("DeleteComponent", &LsCompoundComponent::DeleteComponent, "iComp"_a);

    //===================================================================================
    // enum LsPhaseMode
    py::enum_< LsPhaseMode>(m, "LsPhaseMode", py::arithmetic())
        .value("eLsPhaseMode_None", LsPhaseMode_None)
        .value("eLsPhaseMode_Fixed", LsPhaseMode_Fixed)
        .value("eLsPhaseMode_Fraction", LsPhaseMode_Fraction)
        .value("eLsPhaseMode_Center", LsPhaseMode_Center)
        .export_values();

    //===================================================================================
    // struct  LsStrokeData
    py::class_< LsStrokeData, LsStrokeDataPtr> c5(m, "LsStrokeData");

    c5.def_property("Length", &LsStrokeData::GetLength, &LsStrokeData::SetLength);
    c5.def("GetLength", &LsStrokeData::GetLength, DOC(Bentley, DgnPlatform, LsStrokeData, GetLength));
    c5.def("SetLength", &LsStrokeData::SetLength, "length"_a, DOC(Bentley, DgnPlatform, LsStrokeData, SetLength));
    
    c5.def_property("StartWidth", &LsStrokeData::GetStartWidth, &LsStrokeData::SetStartWidth);
    c5.def("GetStartWidth", &LsStrokeData::GetStartWidth, DOC(Bentley, DgnPlatform, LsStrokeData, GetStartWidth));
    c5.def("SetStartWidth", &LsStrokeData::SetStartWidth, "width"_a, DOC(Bentley, DgnPlatform, LsStrokeData, SetStartWidth));
    
    c5.def_property("EndWidth", &LsStrokeData::GetEndWidth, &LsStrokeData::SetEndWidth);
    c5.def("GetEndWidth", &LsStrokeData::GetEndWidth, DOC(Bentley, DgnPlatform, LsStrokeData, GetEndWidth));
    c5.def("SetEndWidth", &LsStrokeData::SetEndWidth, "width"_a, DOC(Bentley, DgnPlatform, LsStrokeData, SetEndWidth));
    
    c5.def_property("CapMode", &LsStrokeData::GetCapMode, &LsStrokeData::SetCapMode);
    c5.def("GetCapMode", &LsStrokeData::GetCapMode, DOC(Bentley, DgnPlatform, LsStrokeData, GetCapMode));
    c5.def("SetCapMode", &LsStrokeData::SetCapMode, "mode"_a, DOC(Bentley, DgnPlatform, LsStrokeData, SetCapMode));
    
    c5.def_property("Dash", &LsStrokeData::IsDash, &LsStrokeData::SetDash);
    c5.def("IsDash", &LsStrokeData::IsDash, DOC(Bentley, DgnPlatform, LsStrokeData, IsDash));
    c5.def("SetDash", &LsStrokeData::SetDash, "dash"_a, DOC(Bentley, DgnPlatform, LsStrokeData, SetDash));
    
    c5.def_property("IsBypassCorner", &LsStrokeData::BypassCorner, &LsStrokeData::SetBypassCorner);
    c5.def("BypassCorner", &LsStrokeData::BypassCorner, DOC(Bentley, DgnPlatform, LsStrokeData, BypassCorner));
    c5.def("SetBypassCorner", &LsStrokeData::SetBypassCorner, "bypass"_a, DOC(Bentley, DgnPlatform, LsStrokeData, SetBypassCorner));
    
    c5.def_property("Stretchable", &LsStrokeData::IsStretchable, &LsStrokeData::SetStretchable);
    c5.def("IsStretchable", &LsStrokeData::IsStretchable, DOC(Bentley, DgnPlatform, LsStrokeData, IsStretchable));
    c5.def("SetStretchable", &LsStrokeData::SetStretchable, "stretchable"_a, DOC(Bentley, DgnPlatform, LsStrokeData, SetStretchable));
    
    c5.def_property("IsInvertStart", &LsStrokeData::InvertStart, &LsStrokeData::SetInvertStart);
    c5.def("InvertStart", &LsStrokeData::InvertStart);
    c5.def("SetInvertStart", &LsStrokeData::SetInvertStart, "newVal"_a);
    
    c5.def_property("IsInvertEnd", &LsStrokeData::InvertEnd, &LsStrokeData::SetInvertEnd);
    c5.def("InvertEnd", &LsStrokeData::InvertEnd);
    c5.def("SetInvertEnd", &LsStrokeData::SetInvertEnd, "newVal"_a);
    
    c5.def("HasFullWidth", &LsStrokeData::HasFullWidth);
    c5.def("SetFullWidth", &LsStrokeData::SetFullWidth, "width"_a);
    
    c5.def("HasLeftWidth", &LsStrokeData::HasLeftWidth);
    c5.def("SetLeftWidth", &LsStrokeData::SetLeftWidth, "width"_a);
    
    c5.def("HasRightWidth", &LsStrokeData::HasRightWidth);
    c5.def("SetRightWidth", &LsStrokeData::SetRightWidth, "width"_a);
    
    c5.def("IsConstantWidth", &LsStrokeData::IsConstantWidth);
    c5.def("IsHalfWidth", &LsStrokeData::IsHalfWidth);
    c5.def("HasUniformFullWidth", &LsStrokeData::HasUniformFullWidth);
    c5.def("HasWidth", &LsStrokeData::HasWidth);
    c5.def("Copy", &LsStrokeData::Copy, "other"_a);
    c5.def_static("Create", &LsStrokeData::Create, "isDash"_a, "length"_a, DOC(Bentley, DgnPlatform, LsStrokeData, Create));
    c5.def("Duplicate", &LsStrokeData::Duplicate, DOC(Bentley, DgnPlatform, LsStrokeData, Duplicate));

    //===================================================================================
    // struct LsLineCodeComponent
    py::class_< LsLineCodeComponent, LsLineCodeComponentPtr, LsComponent> c6(m, "LsLineCodeComponent");

    c6.def("HasIterationLimit", &LsLineCodeComponent::HasIterationLimit);
    c6.def("SetHasIterationLimit", &LsLineCodeComponent::SetHasIterationLimit, "limit"_a);
    
    c6.def_property("NumIterations", &LsLineCodeComponent::GetNumIterations, &LsLineCodeComponent::SetNumIterations);
    c6.def("GetNumIterations", &LsLineCodeComponent::GetNumIterations);
    c6.def("SetNumIterations", &LsLineCodeComponent::SetNumIterations, "numIter"_a);
    
    c6.def_property("SingleSegmentMode", &LsLineCodeComponent::IsSingleSegmentMode, &LsLineCodeComponent::SetSingleSegmentMode);
    c6.def("IsSingleSegmentMode", &LsLineCodeComponent::IsSingleSegmentMode);
    c6.def("SetSingleSegmentMode", &LsLineCodeComponent::SetSingleSegmentMode, "mode"_a);
    
    c6.def_property("PhaseMode", &LsLineCodeComponent::GetPhaseMode, &LsLineCodeComponent::SetPhaseMode);
    c6.def("GetPhaseMode", &LsLineCodeComponent::GetPhaseMode);
    c6.def("SetPhaseMode", &LsLineCodeComponent::SetPhaseMode, "mode"_a);
    
    c6.def_property("PhaseValue", &LsLineCodeComponent::GetPhaseValue, &LsLineCodeComponent::SetPhaseValue);
    c6.def("GetPhaseValue", &LsLineCodeComponent::GetPhaseValue);
    c6.def("SetPhaseValue", &LsLineCodeComponent::SetPhaseValue, "value"_a);
    
    c6.def("HasUniformFullWidth", [] (LsLineCodeComponent const& self)
           {
           double width = 0;
           auto retVal = self.HasUniformFullWidth(&width);
           return py::make_tuple(retVal, width);
           });

    c6.def("HasWidth", &LsLineCodeComponent::HasWidth);
    
    c6.def_property_readonly("NumStrokes", &LsLineCodeComponent::GetNumStrokes);
    c6.def("GetNumStrokes", &LsLineCodeComponent::GetNumStrokes);

    c6.def("GetStroke", &LsLineCodeComponent::GetStroke, "iStroke"_a);
    c6.def("ReplaceStroke", &LsLineCodeComponent::ReplaceStroke, "iStroke"_a, "newStroke"_a);
    c6.def("DeleteStroke", &LsLineCodeComponent::DeleteStroke, "iStroke"_a);
    c6.def("AppendStroke", &LsLineCodeComponent::AppendStroke, "newStroke"_a);

    //===================================================================================
    // struct LsInternalComponent
    py::class_< LsInternalComponent, LsInternalComponentPtr, LsLineCodeComponent> c7(m, "LsInternalComponent");

    c7.def("IsHardwareStyle", &LsInternalComponent::IsHardwareStyle);
    
    c7.def_property("HardwareStyle", &LsInternalComponent::GetHardwareStyle, &LsInternalComponent::SetHardwareStyle);
    c7.def("GetHardwareStyle", &LsInternalComponent::GetHardwareStyle);
    c7.def("SetHardwareStyle", &LsInternalComponent::SetHardwareStyle, "lineCode"_a);
    
    c7.def("IsInternalDefault", &LsInternalComponent::IsInternalDefault);
    c7.def("SetInternalDefault", &LsInternalComponent::SetInternalDefault);

    //===================================================================================
    // enum SymbolLocation
    py::enum_< SymbolLocation>(m, "SymbolLocation", py::arithmetic())
        .value("eSymbolStroke", SymbolStroke)
        .value("eSymbolLineOrigin", SymbolLineOrigin)
        .value("eSymbolLineEnd", SymbolLineEnd)
        .value("eSymbolLineVertex", SymbolLineVertex)
        .value("eSymbolUnknown", SymbolUnknown)
        .export_values();

    //===================================================================================
    // enum SymbolStrokeLocation
    py::enum_< SymbolStrokeLocation>(m, "SymbolStrokeLocation", py::arithmetic())
        .value("eSymbolStrokeOrigin", SymbolStrokeOrigin)
        .value("eSymbolStrokeEnd", SymbolStrokeEnd)
        .value("eSymbolStrokeCenter", SymbolStrokeCenter)
        .export_values();

    //===================================================================================
    // enum PartialTreatment
    py::enum_< PartialTreatment>(m, "PartialTreatment", py::arithmetic())
        .value("eSymbolPartialOrigin", SymbolPartialOrigin)
        .value("eSymbolPartialProject", SymbolPartialProject)
        .value("eSymbolPartialNone", SymbolPartialNone)
        .export_values();

    //===================================================================================
    // enum SymbolRotation
    py::enum_< SymbolRotation>(m, "SymbolRotation", py::arithmetic())
        .value("eSymbolRotationRelative", SymbolRotationRelative)
        .value("eSymbolRotationAbsolute", SymbolRotationAbsolute)
        .value("eSymbolRotationAdjusted", SymbolRotationAdjusted)
        .export_values();

    //===================================================================================
    // struct LsPointSymbolInfo
    py::class_< LsPointSymbolInfo, LsPointSymbolInfoPtr> c8(m, "LsPointSymbolInfo");

    c8.def(py::init(&LsPointSymbolInfo::Create));
    
    c8.def_property("Symbol", &LsPointSymbolInfo::GetSymbol, &LsPointSymbolInfo::SetSymbol);
    c8.def("GetSymbol", &LsPointSymbolInfo::GetSymbol);
    c8.def("SetSymbol", &LsPointSymbolInfo::SetSymbol, "symb"_a);
    
    c8.def_property("StrokeNumber", &LsPointSymbolInfo::GetStrokeNumber, &LsPointSymbolInfo::SetStrokeNumber);
    c8.def("GetStrokeNumber", &LsPointSymbolInfo::GetStrokeNumber);
    c8.def("SetStrokeNumber", &LsPointSymbolInfo::SetStrokeNumber, "number"_a);
    
    c8.def_property("SymbolLocation", &LsPointSymbolInfo::GetSymbolLocation, &LsPointSymbolInfo::SetSymbolLocation);
    c8.def("GetSymbolLocation", &LsPointSymbolInfo::GetSymbolLocation);
    c8.def("SetSymbolLocation", &LsPointSymbolInfo::SetSymbolLocation, "location"_a);
    
    c8.def_property("SymbolStrokeLocation", &LsPointSymbolInfo::GetSymbolStrokeLocation, &LsPointSymbolInfo::SetSymbolStrokeLocation);
    c8.def("GetSymbolStrokeLocation", &LsPointSymbolInfo::GetSymbolStrokeLocation);
    c8.def("SetSymbolStrokeLocation", &LsPointSymbolInfo::SetSymbolStrokeLocation, "location"_a);
    
    c8.def("IsOnStroke", &LsPointSymbolInfo::IsOnStroke);
    
    c8.def_property("RotationType", &LsPointSymbolInfo::GetRotationType, &LsPointSymbolInfo::SetRotationType);
    c8.def("GetRotationType", &LsPointSymbolInfo::GetRotationType);
    c8.def("SetRotationType", &LsPointSymbolInfo::SetRotationType, "rotType"_a);
    
    c8.def_property("Stretchable", &LsPointSymbolInfo::IsStretchable, &LsPointSymbolInfo::SetStretchable);
    c8.def("IsStretchable", &LsPointSymbolInfo::IsStretchable);
    c8.def("SetStretchable", &LsPointSymbolInfo::SetStretchable, "newVal"_a);
    
    c8.def_property("Clipped", &LsPointSymbolInfo::IsClipped, &LsPointSymbolInfo::SetClipped);
    c8.def("IsClipped", &LsPointSymbolInfo::IsClipped);
    c8.def("SetClipped", &LsPointSymbolInfo::SetClipped, "clipped"_a);
    
    c8.def_property("PartialTreatment", &LsPointSymbolInfo::GetPartialTreatment, &LsPointSymbolInfo::SetPartialTreatment);
    c8.def("GetPartialTreatment", &LsPointSymbolInfo::GetPartialTreatment);
    c8.def("SetPartialTreatment", &LsPointSymbolInfo::SetPartialTreatment, "newVal"_a);
    
    c8.def_property("ColorFromSymbol", &LsPointSymbolInfo::ColorFromSymbol, &LsPointSymbolInfo::SetColorFromSymbol);
    c8.def("GetColorFromSymbol", &LsPointSymbolInfo::ColorFromSymbol);
    c8.def("SetColorFromSymbol", &LsPointSymbolInfo::SetColorFromSymbol, "newVal"_a);
    
    c8.def_property("IsWeightFromSymbol", &LsPointSymbolInfo::WeightFromSymbol, &LsPointSymbolInfo::SetWeightFromSymbol);
    c8.def("WeightFromSymbol", &LsPointSymbolInfo::WeightFromSymbol);
    c8.def("SetWeightFromSymbol", &LsPointSymbolInfo::SetWeightFromSymbol, "newVal"_a);
    
    c8.def_property("XOffset", &LsPointSymbolInfo::GetXOffset, &LsPointSymbolInfo::SetXOffset);
    c8.def("GetXOffset", &LsPointSymbolInfo::GetXOffset);
    c8.def("SetXOffset", &LsPointSymbolInfo::SetXOffset, "offset"_a);
    
    c8.def_property("YOffset", &LsPointSymbolInfo::GetYOffset, &LsPointSymbolInfo::SetYOffset);
    c8.def("GetYOffset", &LsPointSymbolInfo::GetYOffset);
    c8.def("SetYOffset", &LsPointSymbolInfo::SetYOffset, "offset"_a);
    
    c8.def_property("Angle", &LsPointSymbolInfo::GetAngle, &LsPointSymbolInfo::SetAngle);
    c8.def("GetAngle", &LsPointSymbolInfo::GetAngle);
    c8.def("SetAngle", &LsPointSymbolInfo::SetAngle, "angle"_a);

    //===================================================================================
    // struct LsLinePointComponent
    py::class_< LsLinePointComponent, LsLinePointComponentPtr, LsComponent> c9(m, "LsLinePointComponent");

    c9.def_property_readonly("LineCodeId", &LsLinePointComponent::GetLineCodeId);
    c9.def("GetLineCodeId", &LsLinePointComponent::GetLineCodeId);

    c9.def_property_readonly("LineCodeType", &LsLinePointComponent::GetLineCodeType);
    c9.def("GetLineCodeType", &LsLinePointComponent::GetLineCodeType, DOC(Bentley, DgnPlatform, LsLinePointComponent, GetLineCodeType));

    c9.def_property("LineCode", &LsLinePointComponent::GetLineCode, &LsLinePointComponent::SetLineCode);
    c9.def("GetLineCode", &LsLinePointComponent::GetLineCode);
    c9.def("SetLineCode", &LsLinePointComponent::SetLineCode, "lineCode"_a);

    c9.def_property_readonly("NumSymbols", &LsLinePointComponent::GetNumSymbols);
    c9.def("GetNumSymbols", &LsLinePointComponent::GetNumSymbols);
    c9.def("GetSymbolInfo", &LsLinePointComponent::GetSymbolInfo, "iSymbol"_a);
    c9.def("AddSymbolInfo", &LsLinePointComponent::AddSymbolInfo, "symInfo"_a);
    c9.def("RemoveSymbolInfo", &LsLinePointComponent::RemoveSymbolInfo, "symInfo"_a);

    //===================================================================================
    // struct LsPointSymbolComponent
    py::class_< LsPointSymbolComponent, LsPointSymbolComponentPtr, LsComponent> c10(m, "LsPointSymbolComponent");

    c10.def_property("UnitScale", &LsPointSymbolComponent::GetUnitScale, &LsPointSymbolComponent::SetUnitScale);
    c10.def("GetUnitScale", &LsPointSymbolComponent::GetUnitScale);
    c10.def("SetUnitScale", &LsPointSymbolComponent::SetUnitScale, "scale"_a);

    c10.def_property("IsSuppressScale", &LsPointSymbolComponent::SuppressScale, &LsPointSymbolComponent::SetSuppressScale);
    c10.def("SuppressScale", &LsPointSymbolComponent::SuppressScale);
    c10.def("SetSuppressScale", &LsPointSymbolComponent::SetSuppressScale, "suppress"_a);

    c10.def("Is3d", &LsPointSymbolComponent::Is3d);
    }