/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\areapattern.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/AreaPattern.h>



static const char * __doc_Bentley_DgnPlatform_PatternParams_SetAnnotationScale =R"doc(Set annotation scale. Sets modifier bit for
PatternParamsModifierFlags::AnnotationScale. @note This is optional.
Setting it makes the pattern an 'annotative' element, which typically
synchronizes its scale with model's annotation scale.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_GetAnnotationScale =R"doc(Get annotation scale. Used if
PatternParamsModifierFlags::AnnotationScale is set. @note If
PatternParamsModifierFlags::AnnotationScale is set, this pattern is an
'annotative' element, which typically synchronizes its scale with
model's annotation scale.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_SetOrigin =R"doc(Set pattern origin. Sets modifier bit for
PatternParamsModifierFlags::Origin. @note Not supported, define
pattern origin relative to element origin using SetOffset instead.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_GetOrigin =R"doc(Get pattern origin. Used if PatternParamsModifierFlags::Origin is set.
@note Not supported, pattern origin stored as offset from element
origin.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_SetDwgHatchDef =R"doc(Set pattern dwg hatch definition. Sets modifier bit for
PatternParamsModifierFlags::DwgHatchDef.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_GetDwgHatchDef =R"doc(Get pattern dwg hatch definition. Used if
PatternParamsModifierFlags::DwgHatchDef is set.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_SetHoleStyle =R"doc(Set pattern dwg hole style. Sets modifier bit for
PatternParamsModifierFlags::HoleStyle.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_GetHoleStyle =R"doc(Get pattern dwg hole style. Used if
PatternParamsModifierFlags::HoleStyle is set.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_SetStyle =R"doc(Set pattern line style. Sets modifier bit for
PatternParamsModifierFlags::Style. @note Use to set a pattern line
style that is different than element line style. Ignored for area
pattern using a graphic cell not a point cell. @note Only line styles
0-7 are supported.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_GetStyle =R"doc(Get pattern line style. Used if PatternParamsModifierFlags::Style is
set. @note Uses element line style if not set. Ignored for area
pattern using a graphic cell not a point cell. @note Only line styles
0-7 are supported.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_SetColor =R"doc(Set pattern color. Sets modifier bit for
PatternParamsModifierFlags::Color. @note Use to set a pattern color
that is different than element color. Ignored for area pattern using a
graphic cell not a point cell.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_GetColor =R"doc(Get pattern color. Used if PatternParamsModifierFlags::Color is set.
@note Uses element color if not set. Ignored for area pattern using a
graphic cell not a point cell.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_SetMaxLine =R"doc(Set pattern max multiline boundary index. Sets modifier bit for
PatternParamsModifierFlags::Multiline. Valid only for multiline
elements.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_GetMaxLine =R"doc(Get pattern max multiline boundary index. Used if
PatternParamsModifierFlags::Multiline is set.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_SetMinLine =R"doc(Set pattern min multiline boundary index. Sets modifier bit for
PatternParamsModifierFlags::Multiline. Valid only for multiline
elements.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_GetMinLine =R"doc(Get pattern min multiline boundary index. Used if
PatternParamsModifierFlags::Multiline is set.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_SetCellId =R"doc(Set pattern cell by supplying the element id of an existing shared
cell definition. Sets modifier bit for
PatternParamsModifierFlags::Cell.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_GetCellId =R"doc(Get pattern cell element id. Used if PatternParamsModifierFlags::Cell
is set.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_SetCellName =R"doc(Set pattern cell by supplying the cell name. Sets modifier bit for
PatternParamsModifierFlags::Cell. @note Used by
mdlPattern_addAssociative. Will search attached cell library and
attempt to create a new shared cell definition if one with this name
does not already exist. When using IAreaFillPropertiesEdit::AddPattern
you can not specify the pattern cell by name and must instead call
SetCellId with the element id of an existing shared cell definittion.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_GetCellName =R"doc(Get pattern cell name. Used if PatternParamsModifierFlags::Cell is
set. @note Not stored, set to name of cell referenced by GetCellId.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_SetTolerance =R"doc(Set pattern choord tolerance. Sets modifier bit for
PatternParamsModifierFlags::Tolerance.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_GetTolerance =R"doc(Get pattern choord tolerance. Used if
PatternParamsModifierFlags::Tolerance is set.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_GetScale =R"doc(Get pattern scale. Used if PatternParamsModifierFlags::Scale is set.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_SetSecondaryAngle =R"doc(Set pattern cross hatch angle. Sets modifier bit for
PatternParamsModifierFlags::Angle2.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_GetSecondaryAngle =R"doc(Get pattern cross hatch angle. Used if
PatternParamsModifierFlags::Angle2 is set.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_SetSecondarySpacing =R"doc(Set pattern cross hatch spacing or area pattern column spacing. Sets
modifier bit for PatternParamsModifierFlags::Space2.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_GetSecondarySpacing =R"doc(Get pattern cross hatch spacing or area pattern column spacing. Used
if PatternParamsModifierFlags::Space2 is set.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_GetPrimaryAngle =R"doc(Get pattern hatch angle or area pattern angle. Used if
PatternParamsModifierFlags::Angle1 is set.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_SetPrimarySpacing =R"doc(Set pattern hatch spacing or area pattern row spacing. Sets modifier
bit for PatternParamsModifierFlags::Space1.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_GetPrimarySpacing =R"doc(Get pattern hatch spacing or area pattern row spacing. Used if
PatternParamsModifierFlags::Space1 is set.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_SetOffset =R"doc(Set pattern offset from element origin. Sets modifier bit for
PatternParamsModifierFlags::Offset.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_GetOffset =R"doc(Get pattern offset from element origin. Used if
PatternParamsModifierFlags::Offset is set.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_SetOrientation =R"doc(Set pattern orientation. Sets modifier bit for
PatternParamsModifierFlags::RotMatrix.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_GetOrientation =R"doc(Get pattern orientation. Used if PatternParamsModifierFlags::RotMatrix
is set.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_SetModifiers =R"doc(Set the pattern modifiers bit field.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_GetModifiers =R"doc(Get the pattern modifiers bit field.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_IsEqual =R"doc(Compare two PatternParams.)doc";

static const char * __doc_Bentley_DgnPlatform_PatternParams_Copy =R"doc(Copy values from an existing PatternParams.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_AreaPattern(py::module_& m)
    {
    //===================================================================================
    // struct DwgHatchDefLine
    py::class_< DwgHatchDefLine> c1(m, "DwgHatchDefLine");
    py::bind_vector<bvector< DwgHatchDefLine>>(m, "DwgHatchDefLineArray", py::module_local(false));

    c1.def(py::init<>());
    c1.def_readwrite("angle", &DwgHatchDefLine::angle);
    c1.def_readwrite("through", &DwgHatchDefLine::through);
    c1.def_readwrite("offset", &DwgHatchDefLine::offset);
    c1.def_readwrite("nDashes", &DwgHatchDefLine::nDashes);

    //===================================================================================
    // struct DwgHatchDef
    py::class_<DwgHatchDef> c2(m, "DwgHatchDef");

    c2.def(py::init<>());
    c2.def_readwrite("nDefLines", &DwgHatchDef::nDefLines);
    c2.def_readwrite("pixelSize", &DwgHatchDef::pixelSize);
    c2.def_readwrite("islandStyle", &DwgHatchDef::islandStyle);

    //===================================================================================
    // enum PatternParamsCompareFlags
    py::enum_< PatternParamsCompareFlags>(m, "PatternParamsCompareFlags", py::arithmetic())
        .value("ePATTERNPARAMSCOMPAREFLAGS_RMatrix", PATTERNPARAMSCOMPAREFLAGS_RMatrix)
        .value("ePATTERNPARAMSCOMPAREFLAGS_Offset", PATTERNPARAMSCOMPAREFLAGS_Offset)
        .value("ePATTERNPARAMSCOMPAREFLAGS_Default", PATTERNPARAMSCOMPAREFLAGS_Default)
        .value("ePATTERNPARAMSCOMPAREFLAGS_Origin", PATTERNPARAMSCOMPAREFLAGS_Origin)
        .value("ePATTERNPARAMSCOMPAREFLAGS_Symbology", PATTERNPARAMSCOMPAREFLAGS_Symbology)
        .value("ePATTERNPARAMSCOMPAREFLAGS_Mline", PATTERNPARAMSCOMPAREFLAGS_Mline)
        .value("ePATTERNPARAMSCOMPAREFLAGS_Tolerance", PATTERNPARAMSCOMPAREFLAGS_Tolerance)
        .value("ePATTERNPARAMSCOMPAREFLAGS_HoleStyle", PATTERNPARAMSCOMPAREFLAGS_HoleStyle)
        .value("ePATTERNPARAMSCOMPAREFLAGS_DwgHatch", PATTERNPARAMSCOMPAREFLAGS_DwgHatch)
        .value("ePATTERNPARAMSCOMPAREFLAGS_AnnotationScale", PATTERNPARAMSCOMPAREFLAGS_AnnotationScale)
        .value("ePATTERNPARAMSCOMPAREFLAGS_All", PATTERNPARAMSCOMPAREFLAGS_All)
        .export_values();        

    //===================================================================================
    // enum class PatternParamsHoleStyleType
    py::enum_< PatternParamsHoleStyleType>(m, "PatternParamsHoleStyleType")
        .value("eNormal", PatternParamsHoleStyleType::Normal)
        .value("eParity", PatternParamsHoleStyleType::Parity)
        .export_values();        

    //===================================================================================
    // enum class PatternParamsModifierFlags
    py::enum_< PatternParamsModifierFlags>(m, "PatternParamsModifierFlags")
        .value("eNone", PatternParamsModifierFlags::None)
        .value("eSpace1", PatternParamsModifierFlags::Space1)
        .value("eAngle1", PatternParamsModifierFlags::Angle1)
        .value("eSpace2", PatternParamsModifierFlags::Space2)
        .value("eAngle2", PatternParamsModifierFlags::Angle2)
        .value("eScale", PatternParamsModifierFlags::Scale)
        .value("eCell", PatternParamsModifierFlags::Cell)
        .value("eTolerance", PatternParamsModifierFlags::Tolerance)
        .value("eStyle", PatternParamsModifierFlags::Style)
        .value("eWeight", PatternParamsModifierFlags::Weight)
        .value("eColor", PatternParamsModifierFlags::Color)
        .value("eSnap", PatternParamsModifierFlags::Snap)
        .value("eRotMatrix_", PatternParamsModifierFlags::RotMatrix)
        .value("eOffset", PatternParamsModifierFlags::Offset)
        .value("eHoleStyle", PatternParamsModifierFlags::HoleStyle)
        .value("eDwgHatchDef", PatternParamsModifierFlags::DwgHatchDef)
        .value("eMultiline", PatternParamsModifierFlags::Multiline)
        .value("eOrigin", PatternParamsModifierFlags::Origin)
        .value("ePixelSize", PatternParamsModifierFlags::PixelSize)
        .value("eIslandStyle", PatternParamsModifierFlags::IslandStyle)
        .value("eTrueScale", PatternParamsModifierFlags::TrueScale)
        .value("eRawDwgLoops", PatternParamsModifierFlags::RawDwgLoops)
        .value("eDwgHatchOrigin", PatternParamsModifierFlags::DwgHatchOrigin)
        .value("eAnnotationScale", PatternParamsModifierFlags::AnnotationScale)
        .export_values();

    //===================================================================================
    // enum PatternPlacementTypes
    py::enum_< PatternPlacementTypes>(m, "PatternPlacementTypes", py::arithmetic())
        .value("ePATTERN_HATCH", PATTERN_HATCH)
        .value("ePATTERN_CROSSHATCH", PATTERN_CROSSHATCH)
        .value("ePATTERN_AREA", PATTERN_AREA)
        .export_values();

    //===================================================================================
    // struct PatternParams : RefCountedBase
    py::class_< PatternParams, PatternParamsPtr> c3(m, "PatternParams");

    c3.def(py::init(&PatternParams::Create));
    c3.def(py::init(&PatternParams::CreateFromExisting), "existing"_a);

    c3.def("Copy", &PatternParams::Copy, "existing"_a, DOC(Bentley, DgnPlatform, PatternParams, Copy));
    c3.def("IsEqual", &PatternParams::IsEqual, "params"_a, "compareFlags"_a = PATTERNPARAMSCOMPAREFLAGS_Default, DOC(Bentley, DgnPlatform, PatternParams, IsEqual));

    c3.def_property("Modifiers", &PatternParams::GetModifiers, &PatternParams::SetModifiers);
    c3.def("GetModifiers", &PatternParams::GetModifiers, DOC(Bentley, DgnPlatform, PatternParams, GetModifiers));
    c3.def("SetModifiers", &PatternParams::SetModifiers, "flags"_a, DOC(Bentley, DgnPlatform, PatternParams, SetModifiers));
    
    c3.def_property("Orientation", &PatternParams::GetOrientation, &PatternParams::SetOrientation);
    c3.def("GetOrientation", &PatternParams::GetOrientation, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, PatternParams, GetOrientation));
    c3.def("SetOrientation", &PatternParams::SetOrientation, "rotMatrix"_a, DOC(Bentley, DgnPlatform, PatternParams, SetOrientation));
    
    c3.def_property("Offset", &PatternParams::GetOffset, &PatternParams::SetOffset);
    c3.def("GetOffset", &PatternParams::GetOffset, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, PatternParams, GetOffset));
    c3.def("SetOffset", &PatternParams::SetOffset, "offset"_a, DOC(Bentley, DgnPlatform, PatternParams, SetOffset));
    
    c3.def_property("PrimarySpacing", &PatternParams::GetPrimarySpacing, &PatternParams::SetPrimarySpacing);
    c3.def("GetPrimarySpacing", &PatternParams::GetPrimarySpacing, DOC(Bentley, DgnPlatform, PatternParams, GetPrimarySpacing));
    c3.def("SetPrimarySpacing", &PatternParams::SetPrimarySpacing, "spacing"_a, DOC(Bentley, DgnPlatform, PatternParams, SetPrimarySpacing));
    
    c3.def_property_readonly("PrimaryAngle", &PatternParams::GetPrimaryAngle);
    c3.def("GetPrimaryAngle", &PatternParams::GetPrimaryAngle, DOC(Bentley, DgnPlatform, PatternParams, GetPrimaryAngle));
    
    c3.def_property("SecondarySpacing", &PatternParams::GetSecondarySpacing, &PatternParams::SetSecondarySpacing);
    c3.def("GetSecondarySpacing", &PatternParams::GetSecondarySpacing, DOC(Bentley, DgnPlatform, PatternParams, GetSecondarySpacing));
    c3.def("SetSecondarySpacing", &PatternParams::SetSecondarySpacing, "spacing"_a, DOC(Bentley, DgnPlatform, PatternParams, SetSecondarySpacing));
    
    c3.def_property("SecondaryAngle", &PatternParams::GetSecondaryAngle, &PatternParams::SetSecondaryAngle);
    c3.def("GetSecondaryAngle", &PatternParams::GetSecondaryAngle, DOC(Bentley, DgnPlatform, PatternParams, GetSecondaryAngle));
    c3.def("SetSecondaryAngle", &PatternParams::SetSecondaryAngle, "angle"_a, DOC(Bentley, DgnPlatform, PatternParams, SetSecondaryAngle));
    
    c3.def_property_readonly("Scale", &PatternParams::GetScale);
    c3.def("GetScale", &PatternParams::GetScale, DOC(Bentley, DgnPlatform, PatternParams, GetScale));
    
    c3.def_property("Tolerance", &PatternParams::GetTolerance, &PatternParams::SetTolerance);
    c3.def("GetTolerance", &PatternParams::GetTolerance, DOC(Bentley, DgnPlatform, PatternParams, GetTolerance));
    c3.def("SetTolerance", &PatternParams::SetTolerance, "tolerance"_a, DOC(Bentley, DgnPlatform, PatternParams, SetTolerance));
    
    c3.def_property("CellName", &PatternParams::GetCellName, &PatternParams::SetCellName);
    c3.def("GetCellName", &PatternParams::GetCellName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, PatternParams, GetCellName));
    c3.def("SetCellName", &PatternParams::SetCellName, "cellName"_a, DOC(Bentley, DgnPlatform, PatternParams, SetCellName));
    
    c3.def_property("CellId", &PatternParams::GetCellId, &PatternParams::SetCellId);
    c3.def("GetCellId", &PatternParams::GetCellId, DOC(Bentley, DgnPlatform, PatternParams, GetCellId));
    c3.def("SetCellId", &PatternParams::SetCellId, "cellElementId"_a, DOC(Bentley, DgnPlatform, PatternParams, SetCellId));
    
    c3.def_property("MinLine", &PatternParams::GetMinLine, &PatternParams::SetMinLine);
    c3.def("GetMinLine", &PatternParams::GetMinLine, DOC(Bentley, DgnPlatform, PatternParams, GetMinLine));
    c3.def("SetMinLine", &PatternParams::SetMinLine, "minLine"_a, DOC(Bentley, DgnPlatform, PatternParams, SetMinLine));
    
    c3.def_property("MaxLine", &PatternParams::GetMaxLine, &PatternParams::SetMaxLine);
    c3.def("GetMaxLine", &PatternParams::GetMaxLine, DOC(Bentley, DgnPlatform, PatternParams, GetMaxLine));
    c3.def("SetMaxLine", &PatternParams::SetMaxLine, "maxLine"_a, DOC(Bentley, DgnPlatform, PatternParams, SetMaxLine));
    
    c3.def_property("Color", &PatternParams::GetColor, &PatternParams::SetColor);
    c3.def("GetColor", &PatternParams::GetColor, DOC(Bentley, DgnPlatform, PatternParams, GetColor));
    c3.def("SetColor", &PatternParams::SetColor, "color"_a, DOC(Bentley, DgnPlatform, PatternParams, SetColor));
    
    c3.def_property("Style", &PatternParams::GetStyle, &PatternParams::SetStyle);
    c3.def("GetStyle", &PatternParams::GetStyle, DOC(Bentley, DgnPlatform, PatternParams, GetStyle));
    c3.def("SetStyle", &PatternParams::SetStyle, "style"_a, DOC(Bentley, DgnPlatform, PatternParams, SetStyle));
    
    c3.def_property("HoleStyle", &PatternParams::GetHoleStyle, &PatternParams::SetHoleStyle);
    c3.def("GetHoleStyle", &PatternParams::GetHoleStyle, DOC(Bentley, DgnPlatform, PatternParams, GetHoleStyle));
    c3.def("SetHoleStyle", &PatternParams::SetHoleStyle, "holeStyleType"_a, DOC(Bentley, DgnPlatform, PatternParams, SetHoleStyle));    
    
    c3.def_property("DwgHatchDef", &PatternParams::GetDwgHatchDef, &PatternParams::SetDwgHatchDef);
    c3.def("GetDwgHatchDef", &PatternParams::GetDwgHatchDef, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, PatternParams, GetDwgHatchDef));
    c3.def("SetDwgHatchDef", &PatternParams::SetDwgHatchDef, "hatchDef"_a, DOC(Bentley, DgnPlatform, PatternParams, SetDwgHatchDef));
    
    c3.def_property("Origin", &PatternParams::GetOrigin, &PatternParams::SetOrigin);
    c3.def("GetOrigin", &PatternParams::GetOrigin, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, PatternParams, GetOrigin));
    c3.def("SetOrigin", &PatternParams::SetOrigin, "point"_a, DOC(Bentley, DgnPlatform, PatternParams, SetOrigin));
    
    c3.def_property("AnnotationScale", &PatternParams::GetAnnotationScale, &PatternParams::SetAnnotationScale);
    c3.def("GetAnnotationScale", &PatternParams::GetAnnotationScale, DOC(Bentley, DgnPlatform, PatternParams, GetAnnotationScale));
    c3.def("SetAnnotationScale", &PatternParams::SetAnnotationScale, "scale"_a, DOC(Bentley, DgnPlatform, PatternParams, SetAnnotationScale));
    }