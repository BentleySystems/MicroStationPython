/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\iviewdraw.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/IViewDraw.h>



static const char * __doc_Bentley_DgnPlatform_IDrawGeom_DrawBox =R"doc(Creates box ISolidPrimitive from inputs and calls DrawSolidPrimitive.)doc";

static const char * __doc_Bentley_DgnPlatform_IDrawGeom_DrawSphere =R"doc(Creates sphere ISolidPrimitive from inputs and calls
DrawSolidPrimitive.)doc";

static const char * __doc_Bentley_DgnPlatform_IDrawGeom_DrawCone =R"doc(Creates cone ISolidPrimitive from inputs and calls DrawSolidPrimitive.)doc";

static const char * __doc_Bentley_DgnPlatform_IDrawGeom_DrawTorus =R"doc(Creates torus ISolidPrimitive from inputs and calls
DrawSolidPrimitive.)doc";

static const char * __doc_Bentley_DgnPlatform_IDrawGeom_DrawPolyface =R"doc(@note Caller is expected to define texture id for illuminated meshed,
SetTextureId.

Remark:
    s Wireframe fill display supported for non-illuminated meshes.)doc";

static const char * __doc_Bentley_DgnPlatform_IPointCloudDrawParams_GetOrigin =R"doc(returns false if no origin)doc";

static const char * __doc_Bentley_DgnPlatform_IPointCloudDrawParams_GetRange =R"doc(returns false if it does not have range)doc";

static const char * __doc_Bentley_DgnPlatform_IPointCloudDrawParams_GetVersion =R"doc(Get version number.)doc";

static const char * __doc_Bentley_DgnPlatform_IPointCloudDrawParams_IsThreadBound =R"doc(If true, always executed in calling thread instead of QV thread)doc";

static const char * __doc_Bentley_DgnPlatform_OvrMatSymb_SetLineStyle =R"doc(Set line style and MATSYMB_OVERRIDE_Style by style number.)doc";

static const char * __doc_Bentley_DgnPlatform_OvrMatSymb_SetPatternParams =R"doc(Set hatch/pattern display override.)doc";

static const char * __doc_Bentley_DgnPlatform_OvrMatSymb_SetMaterial =R"doc(Set material override and MATSYMB_OVERRIDE_RenderMaterial.)doc";

static const char * __doc_Bentley_DgnPlatform_OvrMatSymb_SetIndexedRasterPattern =R"doc(Set raster pattern by line code index (0-7), on/off mask, and
MATSYMB_OVERRIDE_Style.)doc";

static const char * __doc_Bentley_DgnPlatform_OvrMatSymb_SetTransparentFillColor =R"doc(Set fill color transparency (0-255) and
MATSYMB_OVERRIDE_FillColorTransparency.)doc";

static const char * __doc_Bentley_DgnPlatform_OvrMatSymb_SetTransparentLineColor =R"doc(Set element color transparency (0-255) and
MATSYMB_OVERRIDE_ColorTransparency.)doc";

static const char * __doc_Bentley_DgnPlatform_OvrMatSymb_SetIndexedFillColorTBGR =R"doc(Set fill color by color map index, TBGR, and MATSYMB_OVERRIDE_Color.
MATSYMB_OVERRIDE_ColorTransparency is not set.)doc";

static const char * __doc_Bentley_DgnPlatform_OvrMatSymb_SetIndexedLineColorTBGR =R"doc(Set element color by color map index, TBGR, and
MATSYMB_OVERRIDE_Color. MATSYMB_OVERRIDE_ColorTransparency is not set.)doc";

static const char * __doc_Bentley_DgnPlatform_OvrMatSymb_Clear =R"doc(Set OvrMatSymbFlags to MATSYMB_OVERRIDE_None and reset to default
values.)doc";

static const char * __doc_Bentley_DgnPlatform_OvrMatSymb_GetPatternParams =R"doc(Get hatch/area pattern override.)doc";

static const char * __doc_Bentley_DgnPlatform_OvrMatSymb_SetMaterialUVDetail =R"doc(Set material uv override.)doc";

static const char * __doc_Bentley_DgnPlatform_OvrMatSymb_GetMaterial =R"doc(Get material override. Valid when MATSYMB_OVERRIDE_RenderMaterial is
set.)doc";

static const char * __doc_Bentley_DgnPlatform_OvrMatSymb_GetRasterPatternIndex =R"doc(Get raster pattern line code index. Valid when MATSYMB_OVERRIDE_Style
is set.)doc";

static const char * __doc_Bentley_DgnPlatform_OvrMatSymb_SetRasterPattern =R"doc(Set raster pattern on/off mask and MATSYMB_OVERRIDE_Style.)doc";

static const char * __doc_Bentley_DgnPlatform_OvrMatSymb_GetRasterPattern =R"doc(Get raster pattern on/off mask. Valid when MATSYMB_OVERRIDE_Style is
set.)doc";

static const char * __doc_Bentley_DgnPlatform_OvrMatSymb_SetWidth =R"doc(Set raster width (pixels) and MATSYMB_OVERRIDE_RastWidth.)doc";

static const char * __doc_Bentley_DgnPlatform_OvrMatSymb_GetWidth =R"doc(Get raster width in pixels. Valid when MATSYMB_OVERRIDE_RastWidth is
set.)doc";

static const char * __doc_Bentley_DgnPlatform_OvrMatSymb_GetFillColorIndex =R"doc(Get fill override color map index. Valid when
MATSYMB_OVERRIDE_FillColor is set.)doc";

static const char * __doc_Bentley_DgnPlatform_OvrMatSymb_GetLineColorIndex =R"doc(Get element override color map index. Valid when
MATSYMB_OVERRIDE_Color is set.)doc";

static const char * __doc_Bentley_DgnPlatform_OvrMatSymb_SetFillColorTBGR =R"doc(Set fill color by TBGR and MATSYMB_OVERRIDE_FillColor.
MATSYMB_OVERRIDE_FillColorTransparency is not set.)doc";

static const char * __doc_Bentley_DgnPlatform_OvrMatSymb_GetFillColorTBGR =R"doc(Get fill override color in form TBGR. Check
MATSYMB_OVERRIDE_FillColorTransparency/MATSYMB_OVERRIDE_FillColor to
determine if T and/or BGR value is valid.)doc";

static const char * __doc_Bentley_DgnPlatform_OvrMatSymb_SetLineColorTBGR =R"doc(Set element color by TBGR and MATSYMB_OVERRIDE_Color.
MATSYMB_OVERRIDE_ColorTransparency is not set.)doc";

static const char * __doc_Bentley_DgnPlatform_OvrMatSymb_GetLineColorTBGR =R"doc(Get element override color in form TBGR. Check
MATSYMB_OVERRIDE_ColorTransparency/MATSYMB_OVERRIDE_Color to determine
if T and/or BGR value is valid.)doc";

static const char * __doc_Bentley_DgnPlatform_OvrMatSymb_SetFlags =R"doc(Set OvrMatSymbFlags mask. Only necessary to clear flags, individual
set methods handle enabling the appropriate flags.)doc";

static const char * __doc_Bentley_DgnPlatform_OvrMatSymb_GetFlags =R"doc(Return mask of OvrMatSymbFlags.)doc";

static const char * __doc_Bentley_DgnPlatform_ElemMatSymb_SetPatternParams =R"doc(Set area patterning parameters.)doc";

static const char * __doc_Bentley_DgnPlatform_ElemMatSymb_SetMaterial =R"doc(Set the render material. NOTE:You must supply a seed context to
support geometry maps!)doc";

static const char * __doc_Bentley_DgnPlatform_ElemMatSymb_GetPatternParams =R"doc(Get the area pattern params.)doc";

static const char * __doc_Bentley_DgnPlatform_ElemMatSymb_SetMaterialUVDetail =R"doc(Set the material uv detail for elements which use spherical,
cylindrical, cubic and directional drape material mapping modes)doc";

static const char * __doc_Bentley_DgnPlatform_ElemMatSymb_GetMaterial =R"doc(Get the render material.)doc";

static const char * __doc_Bentley_DgnPlatform_ElemMatSymb_GetGradientSymb =R"doc(Get the GradientSymb from this ElemMatSymb.)doc";

static const char * __doc_Bentley_DgnPlatform_ElemMatSymb_GetLineStyleSymb =R"doc(Get the LineStyleSymb from this ElemMatSymb.)doc";

static const char * __doc_Bentley_DgnPlatform_ElemMatSymb_SetIsBlankingRegion =R"doc(Set that fill is always behind other geometry.)doc";

static const char * __doc_Bentley_DgnPlatform_ElemMatSymb_IsBlankingRegion =R"doc(Determine whether the fill represents blanking region.)doc";

static const char * __doc_Bentley_DgnPlatform_ElemMatSymb_IsFilled =R"doc(Determine whether the fill flag is on for this ElemMatSymb.)doc";

static const char * __doc_Bentley_DgnPlatform_ElemMatSymb_GetRasterPatternIndex =R"doc(Get the style index from this ElemMatSymb (INVALID_STYLE returned for
raster patterns not derived from line codes))doc";

static const char * __doc_Bentley_DgnPlatform_ElemMatSymb_GetRasterPattern =R"doc(Get the raster pattern from this ElemMatSymb. The raster pattern is a
32 bit mask that is repeated along geometry. For each bit that is on
in the pattern, a pixel is set to the line color.)doc";

static const char * __doc_Bentley_DgnPlatform_ElemMatSymb_HasTrueWidth =R"doc(Determine whether TrueWidth is on for this ElemMatSymb)doc";

static const char * __doc_Bentley_DgnPlatform_ElemMatSymb_GetWidth =R"doc(Get the width in pixels from this ElemMatSymb.)doc";

static const char * __doc_Bentley_DgnPlatform_ElemMatSymb_GetFillColorIndex =R"doc(Get the fill color index from this ElemMatSymb
(DgnColorMap::INDEX_Invalid returned for TBGR color))doc";

static const char * __doc_Bentley_DgnPlatform_ElemMatSymb_GetFillColorTBGR =R"doc(Get the TBGR fill color from this ElemMatSymb.)doc";

static const char * __doc_Bentley_DgnPlatform_ElemMatSymb_GetLineColorIndex =R"doc(Get the line color index from this ElemMatSymb
(DgnColorMap::INDEX_Invalid returned for TBGR color))doc";

static const char * __doc_Bentley_DgnPlatform_ElemMatSymb_GetLineColorTBGR =R"doc(Get the TBGR line color from this ElemMatSymb)doc";

static const char * __doc_Bentley_DgnPlatform_LineStyleSymb_SetPlaneAsMatrixRows =R"doc(Set line style orientation for a line style in 3d. Pass NULL to clear
plane modifier and use identity rotation.)doc";

static const char * __doc_Bentley_DgnPlatform_LineStyleSymb_SetEndWidth =R"doc(Set end width. Pass 0.0 to clear end width modifier.)doc";

static const char * __doc_Bentley_DgnPlatform_LineStyleSymb_GetEndWidth =R"doc(Return end width if modifier is set (otherwise same as start width).)doc";

static const char * __doc_Bentley_DgnPlatform_LineStyleSymb_SetOriginWidth =R"doc(Set start width. Pass 0.0 to clear start width modifier.)doc";

static const char * __doc_Bentley_DgnPlatform_LineStyleSymb_GetOriginWidth =R"doc(Return start width if modifier is set (otherwise same as end width).)doc";

static const char * __doc_Bentley_DgnPlatform_LineStyleSymb_SetGapScale =R"doc(Set gap scale. Pass 1.0 to clear gap scale modifier.)doc";

static const char * __doc_Bentley_DgnPlatform_LineStyleSymb_GetGapScale =R"doc(Return the gap scale, returns 1.0 if gap scale modifier is not set.)doc";

static const char * __doc_Bentley_DgnPlatform_LineStyleSymb_SetDashScale =R"doc(Set dash scale. Pass 1.0 to clear dash scale modifier.)doc";

static const char * __doc_Bentley_DgnPlatform_LineStyleSymb_GetDashScale =R"doc(Return the dash scale, returns 1.0 if dash scale modifier is not set.)doc";

static const char * __doc_Bentley_DgnPlatform_LineStyleSymb_SetScale =R"doc(Set line style scale. Pass 1.0 to clear line style scale modifier.)doc";

static const char * __doc_Bentley_DgnPlatform_LineStyleSymb_GetScale =R"doc(Return the line style scale, returns 1.0 if scale modifier is not set.)doc";

static const char * __doc_Bentley_DgnPlatform_LineStyleSymb_GetPlaneAsMatrixRows =R"doc(Get line style orientation for a line style in 3d. Returns identity if
no plane has been set.)doc";

static const char * __doc_Bentley_DgnPlatform_LineStyleSymb_GetName =R"doc(Get line style name, returns NULL if no linestyle is active.)doc";

static const char * __doc_Bentley_DgnPlatform_ElemDisplayParams_GetThickness =R"doc(Get element extrude thickness.)doc";

static const char * __doc_Bentley_DgnPlatform_ElemDisplayParams_GetElementDisplayPriority =R"doc(Get element display priority (2d only).)doc";

static const char * __doc_Bentley_DgnPlatform_ElemDisplayParams_GetMaterial =R"doc(Get render material.)doc";

static const char * __doc_Bentley_DgnPlatform_ElemDisplayParams_GetTransparency =R"doc(Get element transparency.)doc";

static const char * __doc_Bentley_DgnPlatform_ElemDisplayParams_GetElementClass =R"doc(Get element class.)doc";

static const char * __doc_Bentley_DgnPlatform_ElemDisplayParams_GetLevel =R"doc(Get element level.)doc";

static const char * __doc_Bentley_DgnPlatform_ElemDisplayParams_GetWeight =R"doc(Get element weight.)doc";

static const char * __doc_Bentley_DgnPlatform_ElemDisplayParams_GetLineStyleParams =R"doc(Get element linestyle modifiers.)doc";

static const char * __doc_Bentley_DgnPlatform_ElemDisplayParams_GetLineStyleModelRef =R"doc(Get element linestyle model. NOTE:Expected to be NULL if style model
is the same as element's model, i.e. normal case.)doc";

static const char * __doc_Bentley_DgnPlatform_ElemDisplayParams_GetLineStyle =R"doc(Get element linestyle.)doc";

static const char * __doc_Bentley_DgnPlatform_ElemDisplayParams_GetGradient =R"doc(Get gradient fill information. Valid when NULL != GetGradient () &&
FillDisplay::Never != GetFillDisplay ().)doc";

static const char * __doc_Bentley_DgnPlatform_ElemDisplayParams_GetFillDisplay =R"doc(Get fill display setting.)doc";

static const char * __doc_Bentley_DgnPlatform_ElemDisplayParams_IsFillColorTBGR =R"doc(Helper method, checks INVALID_COLOR == GetFillColor () &&
FillDisplay::Never != GetFillDisplay () && NULL == GetGradient ().)doc";

static const char * __doc_Bentley_DgnPlatform_ElemDisplayParams_GetFillColorTBGR =R"doc(Get element fill color that has been defined by TBGR value. Valid when
INVALID_COLOR == GetFillColor () && FillDisplay::Never !=
GetFillDisplay () && NULL == GetGradient ().)doc";

static const char * __doc_Bentley_DgnPlatform_ElemDisplayParams_GetFillColor =R"doc(Get element fill color id. Valid when INVALID_COLOR != GetFillColor ()
&& FillDisplay::Never != GetFillDisplay () && NULL == GetGradient ().)doc";

static const char * __doc_Bentley_DgnPlatform_ElemDisplayParams_IsLineColorTBGR =R"doc(Helper method, checks INVALID_COLOR == GetLineColor ().)doc";

static const char * __doc_Bentley_DgnPlatform_ElemDisplayParams_GetLineColorTBGR =R"doc(Get element color that has been defined by TBGR value. Valid when
INVALID_COLOR == GetLineColor ().)doc";

static const char * __doc_Bentley_DgnPlatform_ElemDisplayParams_GetLineColor =R"doc(Get element color id. NOTE:Will be INVALID_COLOR when color has been
defined by TBGR value.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialUVDetail_SetElementHandle =R"doc(Set the element which requires UV mapping)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialUVDetail_GetElementHandle =R"doc(Get the element which requires UV mapping)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialUVDetail_SetQVAliasMaterialId =R"doc(Set the QV Material Id for the UV mapping to use. This Id is ref
counted and its lifecycle will need to exist past the draw of the
temporary element. Then when the referece count is 0 the destructor of
this object will remove the material definition from QuickVision. Only
required for mapping non persistent elements)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialUVDetail_GetQVAliasMaterialId =R"doc(Get the QV Material Id for the UV mapping to use. Only required for
mapping non persistent elements)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialUVDetail_SetProjectionVariant =R"doc(Set the capped value of the UV mapping. Only required for mapping non
persistent elements)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialUVDetail_GetProjectionVariant =R"doc(Get the capped value of the UV mapping. Only required for mapping non
persistent elements)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialUVDetail_SetMapMode =R"doc(Set the map mode of the UV mapping. Only required for mapping non
persistent elements)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialUVDetail_GetMapMode =R"doc(Get the map mode of the UV mapping. Only required for mapping non
persistent elements)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialUVDetail_SetSize =R"doc(Set the size of the UV mapping. Only required for mapping non
persistent elements)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialUVDetail_GetSize =R"doc(Get the size of the UV mapping. Only required for mapping non
persistent elements)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialUVDetail_SetRMatrix =R"doc(Set the orientation of the UV mapping. Only required for mapping non
persistent elements)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialUVDetail_GetRMatrix =R"doc(Get the orientation of the UV mapping. Only required for mapping non
persistent elements)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialUVDetail_SetOrigin =R"doc(Set the origin on the UV mapping. Only required for mapping non
persistent elements)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialUVDetail_GetOrigin =R"doc(Get the origin of the UV mapping. Only required for mapping non
persistent elements)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialUVDetail_Copy =R"doc(Copy the contents of the argument object into this object

Parameter ``rhs``:
    Object to copy)doc";

static const char * __doc_Bentley_DgnPlatform_QVAliasMaterialId_GetId =R"doc(Get the id for the generated Qv Material)doc";

static const char * __doc_Bentley_DgnPlatform_GradientSymb_SetKeys =R"doc(Set gradient colors and color start fractions. If nKeys is 1, tint is
used to define 2nd color.)doc";

static const char * __doc_Bentley_DgnPlatform_GradientSymb_GetKey =R"doc(Return color and color start fraction (0.0 to 1.0) by index.)doc";

static const char * __doc_Bentley_DgnPlatform_GradientSymb_SetAngle =R"doc(Set gradient angle. (radians))doc";

static const char * __doc_Bentley_DgnPlatform_GradientSymb_GetAngle =R"doc(Return gradient angle. (radians))doc";

static const char * __doc_Bentley_DgnPlatform_GradientSymb_SetTint =R"doc(Set gradient tint. (0.0 to 1.0))doc";

static const char * __doc_Bentley_DgnPlatform_GradientSymb_GetTint =R"doc(Return gradient tint. (0.0 to 1.0))doc";

static const char * __doc_Bentley_DgnPlatform_GradientSymb_SetShift =R"doc(Set gradient shift. (0.0 to 1.0))doc";

static const char * __doc_Bentley_DgnPlatform_GradientSymb_GetShift =R"doc(Return gradient shift. (0.0 to 1.0))doc";

static const char * __doc_Bentley_DgnPlatform_GradientSymb_SetFlags =R"doc(Set GradientFlags.)doc";

static const char * __doc_Bentley_DgnPlatform_GradientSymb_GetFlags =R"doc(Return GradientFlags.)doc";

static const char * __doc_Bentley_DgnPlatform_GradientSymb_SetMode =R"doc(Set GradientMode.)doc";

static const char * __doc_Bentley_DgnPlatform_GradientSymb_GetMode =R"doc(Return GradientMode.)doc";

static const char * __doc_Bentley_DgnPlatform_GradientSymb_GetNKeys =R"doc(Return the number of colors in gradient.)doc";

static const char * __doc_Bentley_DgnPlatform_LineStyleParams_Init =R"doc(Initialize LineStyleParamsResource members.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_IViewDraw(py::module_& m)
    {
    m.attr ("STYLEMOD_SCALE") = STYLEMOD_SCALE;
    m.attr ("STYLEMOD_DSCALE") = STYLEMOD_DSCALE;
    m.attr ("STYLEMOD_GSCALE") = STYLEMOD_GSCALE;
    m.attr ("STYLEMOD_SWIDTH") = STYLEMOD_SWIDTH;
    m.attr("STYLEMOD_EWIDTH") = STYLEMOD_EWIDTH;
    m.attr("STYLEMOD_DISTPHASE") = STYLEMOD_DISTPHASE;
    m.attr("STYLEMOD_FRACTPHASE") = STYLEMOD_FRACTPHASE;
    m.attr("STYLEMOD_CENTERPHASE") = STYLEMOD_CENTERPHASE;

    //===================================================================================
    //===================================================================================
    // struct LineStyleParamsResource
    py::class_< LineStyleParamsResource> c0(m, "LineStyleParamsResource");
    c0.def_readwrite("modifiers", &LineStyleParamsResource::modifiers);
    c0.def_readwrite("reserved", &LineStyleParamsResource::reserved);
    c0.def_readwrite("scale", &LineStyleParamsResource::scale);
    c0.def_readwrite("dashScale", &LineStyleParamsResource::dashScale);
    c0.def_readwrite("gapScale", &LineStyleParamsResource::gapScale);
    c0.def_readwrite("startWidth", &LineStyleParamsResource::startWidth);
    c0.def_readwrite("endWidth", &LineStyleParamsResource::endWidth);
    c0.def_readwrite("distPhase", &LineStyleParamsResource::distPhase);
    c0.def_readwrite("fractPhase", &LineStyleParamsResource::fractPhase);
    c0.def_readwrite("lineMask", &LineStyleParamsResource::lineMask);
    c0.def_readwrite("mlineFlags", &LineStyleParamsResource::mlineFlags);
    c0.def_readwrite("normal", &LineStyleParamsResource::normal);
    c0.def_readwrite("rMatrix", &LineStyleParamsResource::rMatrix);

    // struct LineStyleParams
    py::class_< LineStyleParams, LineStyleParamsResource> c1(m, "LineStyleParams");
    c1.def(py::init<>());
    c1.def("Init", &LineStyleParams::Init, DOC(Bentley, DgnPlatform, LineStyleParams, Init));    

    //===================================================================================
    // enum class DrawExpense
    py::enum_< DgnPlatform::DrawExpense>(m, "DrawExpense")
        .value("eMedium", DgnPlatform::DrawExpense::Medium)
        .value("eHigh", DgnPlatform::DrawExpense::High)
        .export_values();

    //===================================================================================
    // enum class FillDisplay
    py::enum_< DgnPlatform::FillDisplay>(m, "FillDisplay")
        .value("eNever", DgnPlatform::FillDisplay::Never)
        .value("eByView", DgnPlatform::FillDisplay::ByView)
        .value("eAlways", DgnPlatform::FillDisplay::Always)
        .value("eBlanking", DgnPlatform::FillDisplay::Blanking)
        .export_values();

    //===================================================================================
    // enum class LineJoin
    py::enum_< DgnPlatform::LineJoin>(m, "LineJoin")
        .value("eNone", DgnPlatform::LineJoin::None)
        .value("eBevel", DgnPlatform::LineJoin::Bevel)
        .value("eMiter", DgnPlatform::LineJoin::Miter)
        .value("eRound", DgnPlatform::LineJoin::Round)
        .export_values();

    //===================================================================================
    // enum class LineCap
    py::enum_< DgnPlatform::LineCap>(m, "LineCap")
        .value("eNone", DgnPlatform::LineCap::None)
        .value("eFlat", DgnPlatform::LineCap::Flat)
        .value("eSquare", DgnPlatform::LineCap::Square)
        .value("eRound", DgnPlatform::LineCap::Round)
        .value("eTriangle", DgnPlatform::LineCap::Triangle)
        .export_values();

    //===================================================================================
    // enum class RangeResult
    py::enum_< DgnPlatform::RangeResult>(m, "RangeResult")
        .value("eOutside", DgnPlatform::RangeResult::Outside)
        .value("eOverlap", DgnPlatform::RangeResult::Overlap)
        .value("eInside", DgnPlatform::RangeResult::Inside)
        .export_values();

    //===================================================================================
    // enum class RasterFormat
    py::enum_< DgnPlatform::RasterFormat>(m, "RasterFormat")
        .value("eRGBA", DgnPlatform::RasterFormat::RGBA)
        .value("eBGRA", DgnPlatform::RasterFormat::BGRA)
        .value("eRGB", DgnPlatform::RasterFormat::RGB)
        .value("eBGR", DgnPlatform::RasterFormat::BGR)
        .value("eGray", DgnPlatform::RasterFormat::Gray)
        .value("eAlpha", DgnPlatform::RasterFormat::Alpha)
        .value("eRGBS", DgnPlatform::RasterFormat::RGBS)
        .value("eBGRS", DgnPlatform::RasterFormat::BGRS)
        .export_values();

    //===================================================================================
    // struct GradientSymb
    py::class_< GradientSymb, GradientSymbPtr> c2(m, "GradientSymb");

    c2.def(py::init(&GradientSymb::Create));
    c2.def("GetNKeys", &GradientSymb::GetNKeys, DOC(Bentley, DgnPlatform, GradientSymb, GetNKeys));

    c2.def_property("Mode", &GradientSymb::GetMode, &GradientSymb::SetMode);
    c2.def("GetMode", &GradientSymb::GetMode, DOC(Bentley, DgnPlatform, GradientSymb, GetMode));
    c2.def("SetMode", &GradientSymb::SetMode, "mode"_a, DOC(Bentley, DgnPlatform, GradientSymb, SetMode));
    
    c2.def_property("Flags", &GradientSymb::GetFlags, &GradientSymb::SetFlags);
    c2.def("GetFlags", &GradientSymb::GetFlags, DOC(Bentley, DgnPlatform, GradientSymb, GetFlags));
    c2.def("SetFlags", &GradientSymb::SetFlags, "flags"_a, DOC(Bentley, DgnPlatform, GradientSymb, SetFlags));
    
    c2.def_property("Shift", &GradientSymb::GetShift, &GradientSymb::SetShift);
    c2.def("GetShift", &GradientSymb::GetShift, DOC(Bentley, DgnPlatform, GradientSymb, GetShift));
    c2.def("SetShift", &GradientSymb::SetShift, "shift"_a, DOC(Bentley, DgnPlatform, GradientSymb, SetShift));
    
    c2.def_property("Tint", &GradientSymb::GetTint, &GradientSymb::SetTint);
    c2.def("GetTint", &GradientSymb::GetTint, DOC(Bentley, DgnPlatform, GradientSymb, GetTint));
    c2.def("SetTint", &GradientSymb::SetTint, "tint"_a, DOC(Bentley, DgnPlatform, GradientSymb, SetTint));
    
    c2.def_property("Angle", &GradientSymb::GetAngle, &GradientSymb::SetAngle);
    c2.def("GetAngle", &GradientSymb::GetAngle, DOC(Bentley, DgnPlatform, GradientSymb, GetAngle));
    c2.def("SetAngle", &GradientSymb::SetAngle, "angle"_a, DOC(Bentley, DgnPlatform, GradientSymb, SetAngle));
    
    c2.def("GetKey", [] (GradientSymb const& self, int index)
           {
           RgbColorDef color;
           double value = 0;
           self.GetKey(color, value, index);
           return py::make_tuple(color, value);
           }, "index"_a, DOC(Bentley, DgnPlatform, GradientSymb, GetKey));

    c2.def("SetKeys", [] (GradientSymb& self, bvector< RgbColorDef> const& colors, DoubleArray const& values)
           {
           size_t nItem = __min(colors.size(), values.size());
           self.SetKeys((UInt16) nItem, colors.data(), values.data());
           }, "colors"_a, "values"_a, DOC(Bentley, DgnPlatform, GradientSymb, SetKeys));

    //===================================================================================
    // struct QVAliasMaterialId
    py::class_< QVAliasMaterialId, QVAliasMaterialIdPtr> c3(m, "QVAliasMaterialId");

    c3.def(py::init(&QVAliasMaterialId::Create), "qvAliasMaterialId"_a);
    c3.def("GetId", &QVAliasMaterialId::GetId, DOC(Bentley, DgnPlatform, QVAliasMaterialId, GetId));

    //===================================================================================
    // struct MaterialUVDetail
    py::class_< MaterialUVDetail, MaterialUVDetailPtr> c4(m, "MaterialUVDetail");

    c4.def("Copy", &MaterialUVDetail::Copy, "rhs"_a, DOC(Bentley, DgnPlatform, MaterialUVDetail, Copy));
    c4.def("__eq__", [] (MaterialUVDetailR self, MaterialUVDetailCR other) { return self.Equals(other); });

    c4.def_property("Origin", &MaterialUVDetail::GetOrigin, &MaterialUVDetail::SetOrigin);
    c4.def("GetOrigin", &MaterialUVDetail::GetOrigin, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialUVDetail, GetOrigin));
    c4.def("SetOrigin", &MaterialUVDetail::SetOrigin, "pt"_a, DOC(Bentley, DgnPlatform, MaterialUVDetail, SetOrigin));
    
    c4.def_property("RMatrix", &MaterialUVDetail::GetRMatrix, &MaterialUVDetail::SetRMatrix);
    c4.def("GetRMatrix", &MaterialUVDetail::GetRMatrix, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialUVDetail, GetRMatrix));
    c4.def("SetRMatrix", &MaterialUVDetail::SetRMatrix, "matrix"_a, DOC(Bentley, DgnPlatform, MaterialUVDetail, SetRMatrix));
    
    c4.def_property("Size", &MaterialUVDetail::GetSize, &MaterialUVDetail::SetSize);
    c4.def("GetSize", &MaterialUVDetail::GetSize, DOC(Bentley, DgnPlatform, MaterialUVDetail, GetSize));
    c4.def("SetSize", &MaterialUVDetail::SetSize, "size"_a, DOC(Bentley, DgnPlatform, MaterialUVDetail, SetSize));
    
    c4.def_property("MapMode", &MaterialUVDetail::GetMapMode, &MaterialUVDetail::SetMapMode);
    c4.def("GetMapMode", &MaterialUVDetail::GetMapMode, DOC(Bentley, DgnPlatform, MaterialUVDetail, GetMapMode));
    c4.def("SetMapMode", &MaterialUVDetail::SetMapMode, "mapMode"_a, DOC(Bentley, DgnPlatform, MaterialUVDetail, SetMapMode));
    
    c4.def_property("ProjectionVariant", &MaterialUVDetail::GetProjectionVariant, &MaterialUVDetail::SetProjectionVariant);
    c4.def("GetProjectionVariant", &MaterialUVDetail::GetProjectionVariant, DOC(Bentley, DgnPlatform, MaterialUVDetail, GetProjectionVariant));
    c4.def("SetProjectionVariant", &MaterialUVDetail::SetProjectionVariant, "variant"_a, DOC(Bentley, DgnPlatform, MaterialUVDetail, SetProjectionVariant));
    
    c4.def_property("QVAliasMaterialId",
                    py::cpp_function(&MaterialUVDetail::GetQVAliasMaterialId),
                    py::cpp_function(&MaterialUVDetail::SetQVAliasMaterialId, py::keep_alive<1, 2>()));
    c4.def("GetQVAliasMaterialId", &MaterialUVDetail::GetQVAliasMaterialId, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialUVDetail, GetQVAliasMaterialId));
    c4.def("SetQVAliasMaterialId", &MaterialUVDetail::SetQVAliasMaterialId, "qvId"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, MaterialUVDetail, SetQVAliasMaterialId));

    c4.def_property("ElementHandle", &MaterialUVDetail::GetElementHandle, &MaterialUVDetail::SetElementHandle);
    c4.def("GetElementHandle", &MaterialUVDetail::GetElementHandle, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialUVDetail, GetElementHandle));
    c4.def("SetElementHandle", &MaterialUVDetail::SetElementHandle, "eh"_a, DOC(Bentley, DgnPlatform, MaterialUVDetail, SetElementHandle));
    
    c4.def(py::init(&MaterialUVDetail::Create));


    //===================================================================================
    // struct ElemDisplayParams
    py::class_< ElemDisplayParams> c6(m, "ElemDisplayParams");

    c6.def_property_readonly("LineColor", &ElemDisplayParams::GetLineColor);
    c6.def("GetLineColor", &ElemDisplayParams::GetLineColor, DOC(Bentley, DgnPlatform, ElemDisplayParams, GetLineColor));
    
    c6.def_property_readonly("LineColorTBGR", &ElemDisplayParams::GetLineColorTBGR);
    c6.def("GetLineColorTBGR", &ElemDisplayParams::GetLineColorTBGR, DOC(Bentley, DgnPlatform, ElemDisplayParams, GetLineColorTBGR));
    
    c6.def("IsLineColorTBGR", &ElemDisplayParams::IsLineColorTBGR, DOC(Bentley, DgnPlatform, ElemDisplayParams, IsLineColorTBGR));
    
    c6.def_property_readonly("FillColor", &ElemDisplayParams::GetFillColor);
    c6.def("GetFillColor", &ElemDisplayParams::GetFillColor, DOC(Bentley, DgnPlatform, ElemDisplayParams, GetFillColor));
    
    c6.def("GetFillColorTBGR", &ElemDisplayParams::GetFillColorTBGR, DOC(Bentley, DgnPlatform, ElemDisplayParams, GetFillColorTBGR));
    
    c6.def("IsFillColorTBGR", &ElemDisplayParams::IsFillColorTBGR, DOC(Bentley, DgnPlatform, ElemDisplayParams, IsFillColorTBGR));
    
    c6.def_property_readonly("FillDisplay", &ElemDisplayParams::GetFillDisplay);
    c6.def("GetFillDisplay", &ElemDisplayParams::GetFillDisplay, DOC(Bentley, DgnPlatform, ElemDisplayParams, GetFillDisplay));
    
    c6.def_property_readonly("Gradient", &ElemDisplayParams::GetGradient);
    c6.def("GetGradient", &ElemDisplayParams::GetGradient, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ElemDisplayParams, GetGradient));
    
    c6.def_property_readonly("LineStyle", &ElemDisplayParams::GetLineStyle);
    c6.def("GetLineStyle", &ElemDisplayParams::GetLineStyle, DOC(Bentley, DgnPlatform, ElemDisplayParams, GetLineStyle));
    
    c6.def_property_readonly("LineStyleModelRef", &ElemDisplayParams::GetLineStyleModelRef);
    c6.def("GetLineStyleModelRef", &ElemDisplayParams::GetLineStyleModelRef, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ElemDisplayParams, GetLineStyleModelRef));
    
    c6.def_property_readonly("LineStyleParams", &ElemDisplayParams::GetLineStyleParams);
    c6.def("GetLineStyleParams", &ElemDisplayParams::GetLineStyleParams, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ElemDisplayParams, GetLineStyleParams));
    
    c6.def_property_readonly("Weight", &ElemDisplayParams::GetWeight);
    c6.def("GetWeight", &ElemDisplayParams::GetWeight, DOC(Bentley, DgnPlatform, ElemDisplayParams, GetWeight));
    
    c6.def_property_readonly("Level", &ElemDisplayParams::GetLevel);
    c6.def("GetLevel", &ElemDisplayParams::GetLevel, DOC(Bentley, DgnPlatform, ElemDisplayParams, GetLevel));
    
    c6.def_property_readonly("ElementClass", &ElemDisplayParams::GetElementClass);
    c6.def("GetElementClass", &ElemDisplayParams::GetElementClass, DOC(Bentley, DgnPlatform, ElemDisplayParams, GetElementClass));
    
    c6.def_property_readonly("Transparency", &ElemDisplayParams::GetTransparency);
    c6.def("GetTransparency", &ElemDisplayParams::GetTransparency, DOC(Bentley, DgnPlatform, ElemDisplayParams, GetTransparency));
    
    c6.def_property_readonly("Material", &ElemDisplayParams::GetMaterial);
    c6.def("GetMaterial", &ElemDisplayParams::GetMaterial, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ElemDisplayParams, GetMaterial));
    
    c6.def_property_readonly("ElementDisplayPriority", &ElemDisplayParams::GetElementDisplayPriority);
    c6.def("GetElementDisplayPriority", &ElemDisplayParams::GetElementDisplayPriority, DOC(Bentley, DgnPlatform, ElemDisplayParams, GetElementDisplayPriority));
    
    c6.def("GetThickness", [] (ElemDisplayParamsCR self)
           {
           bool isCapped = false;
           DVec3d direction = *self.GetThickness(isCapped);
           return py::make_tuple(direction, isCapped);
           }, DOC(Bentley, DgnPlatform, ElemDisplayParams, GetThickness));   

    //===================================================================================
    // struct LineStyleSymb
    py::class_< LineStyleSymb> c9(m, "LineStyleSymb");

    c9.def_property_readonly("Name", &LineStyleSymb::GetName);
    c9.def("GetName", &LineStyleSymb::GetName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, LineStyleSymb, GetName));

    c9.def("GetPlaneAsMatrixRows", &LineStyleSymb::GetPlaneAsMatrixRows, "rMatrix"_a, DOC(Bentley, DgnPlatform, LineStyleSymb, GetPlaneAsMatrixRows));
    
    c9.def_property("Scale", &LineStyleSymb::GetScale, &LineStyleSymb::SetScale);
    c9.def("GetScale", &LineStyleSymb::GetScale, DOC(Bentley, DgnPlatform, LineStyleSymb, GetScale));
    c9.def("SetScale", &LineStyleSymb::SetScale, "scale"_a, DOC(Bentley, DgnPlatform, LineStyleSymb, SetScale));
    
    c9.def_property("DashScale", &LineStyleSymb::GetDashScale, &LineStyleSymb::SetDashScale);
    c9.def("GetDashScale", &LineStyleSymb::GetDashScale, DOC(Bentley, DgnPlatform, LineStyleSymb, GetDashScale));
    c9.def("SetDashScale", &LineStyleSymb::SetDashScale, "scale"_a, DOC(Bentley, DgnPlatform, LineStyleSymb, SetDashScale));
    
    c9.def_property("GapScale", &LineStyleSymb::GetGapScale, &LineStyleSymb::SetGapScale);
    c9.def("GetGapScale", &LineStyleSymb::GetGapScale, DOC(Bentley, DgnPlatform, LineStyleSymb, GetGapScale));
    c9.def("SetGapScale", &LineStyleSymb::SetGapScale, "scale"_a, DOC(Bentley, DgnPlatform, LineStyleSymb, SetGapScale));
    
    c9.def_property("OriginWidth", &LineStyleSymb::GetOriginWidth, &LineStyleSymb::SetOriginWidth);
    c9.def("GetOriginWidth", &LineStyleSymb::GetOriginWidth, DOC(Bentley, DgnPlatform, LineStyleSymb, GetOriginWidth));
    c9.def("SetOriginWidth", &LineStyleSymb::SetOriginWidth, "width"_a, DOC(Bentley, DgnPlatform, LineStyleSymb, SetOriginWidth));
    
    c9.def_property("EndWidth", &LineStyleSymb::GetEndWidth, &LineStyleSymb::SetEndWidth);
    c9.def("GetEndWidth", &LineStyleSymb::GetEndWidth, DOC(Bentley, DgnPlatform, LineStyleSymb, GetEndWidth));
    c9.def("SetEndWidth", &LineStyleSymb::SetEndWidth, "width"_a, DOC(Bentley, DgnPlatform, LineStyleSymb, SetEndWidth));
    
    c9.def("SetPlaneAsMatrixRows", &LineStyleSymb::SetPlaneAsMatrixRows, "rMatrix"_a, DOC(Bentley, DgnPlatform, LineStyleSymb, SetPlaneAsMatrixRows));

    //===================================================================================
    // struct ElemMatSymb
    py::class_< ElemMatSymb> c10(m, "ElemMatSymb");

    c10.def_property("LineColorTBGR", &ElemMatSymb::GetLineColorTBGR, &ElemMatSymb::SetLineColorTBGR);
    c10.def("GetLineColorTBGR", &ElemMatSymb::GetLineColorTBGR, DOC(Bentley, DgnPlatform, ElemMatSymb, GetLineColorTBGR));
    c10.def("SetLineColorTBGR", &ElemMatSymb::SetLineColorTBGR, "color"_a);
    
    c10.def_property_readonly("LineColorIndex", &ElemMatSymb::GetLineColorIndex);
    c10.def("GetLineColorIndex", &ElemMatSymb::GetLineColorIndex, DOC(Bentley, DgnPlatform, ElemMatSymb, GetLineColorIndex));
    
    c10.def_property("FillColorTBGR", &ElemMatSymb::GetFillColorTBGR, &ElemMatSymb::SetFillColorTBGR);
    c10.def("GetFillColorTBGR", &ElemMatSymb::GetFillColorTBGR, DOC(Bentley, DgnPlatform, ElemMatSymb, GetFillColorTBGR));
    c10.def("SetFillColorTBGR", &ElemMatSymb::SetFillColorTBGR, "color"_a);
    
    c10.def_property_readonly("FillColorIndex", &ElemMatSymb::GetFillColorIndex);
    c10.def("GetFillColorIndex", &ElemMatSymb::GetFillColorIndex, DOC(Bentley, DgnPlatform, ElemMatSymb, GetFillColorIndex));
    
    c10.def_property("Width", &ElemMatSymb::GetWidth, &ElemMatSymb::SetWidth);
    c10.def("GetWidth", &ElemMatSymb::GetWidth, DOC(Bentley, DgnPlatform, ElemMatSymb, GetWidth));
    c10.def("SetWidth", &ElemMatSymb::SetWidth, "width"_a);
    
    c10.def("HasTrueWidth", &ElemMatSymb::HasTrueWidth, DOC(Bentley, DgnPlatform, ElemMatSymb, HasTrueWidth));
    
    c10.def_property("RasterPattern", &ElemMatSymb::GetRasterPattern, &ElemMatSymb::SetRasterPattern);
    c10.def("GetRasterPattern", &ElemMatSymb::GetRasterPattern, DOC(Bentley, DgnPlatform, ElemMatSymb, GetRasterPattern));
    c10.def("SetRasterPattern", &ElemMatSymb::SetRasterPattern, "pattern"_a);
    
    c10.def_property_readonly("RasterPatternIndex", &ElemMatSymb::GetRasterPatternIndex);
    c10.def("GetRasterPatternIndex", &ElemMatSymb::GetRasterPatternIndex, DOC(Bentley, DgnPlatform, ElemMatSymb, GetRasterPatternIndex));
    
    c10.def_property("Filled", &ElemMatSymb::IsFilled, &ElemMatSymb::SetIsFilled);
    c10.def("IsFilled", &ElemMatSymb::IsFilled, DOC(Bentley, DgnPlatform, ElemMatSymb, IsFilled));
    c10.def("SetIsFilled", &ElemMatSymb::SetIsFilled, "filled"_a);
    
    c10.def_property("BlankingRegion", &ElemMatSymb::IsBlankingRegion, &ElemMatSymb::SetIsBlankingRegion);
    c10.def("IsBlankingRegion", &ElemMatSymb::IsBlankingRegion, DOC(Bentley, DgnPlatform, ElemMatSymb, IsBlankingRegion));
    c10.def("SetIsBlankingRegion", &ElemMatSymb::SetIsBlankingRegion, "blanking"_a, DOC(Bentley, DgnPlatform, ElemMatSymb, SetIsBlankingRegion));
    
    c10.def_property_readonly("LineStyleSymb", &ElemMatSymb::GetLineStyleSymbR);
    c10.def("GetLineStyleSymb", &ElemMatSymb::GetLineStyleSymbR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ElemMatSymb, GetLineStyleSymb));
    
    c10.def_property_readonly("GradientSymb", &ElemMatSymb::GetGradientSymb);
    c10.def("GetGradientSymb", &ElemMatSymb::GetGradientSymb, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ElemMatSymb, GetGradientSymb));
    
    c10.def_property_readonly("Material", &ElemMatSymb::GetMaterial);
    c10.def("GetMaterial", &ElemMatSymb::GetMaterial, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ElemMatSymb, GetMaterial));

    c10.def_property("MaterialUVDetail", [] (ElemMatSymbCR self)
                     {
                     return MaterialUVDetailPtr(const_cast<MaterialUVDetailP>(self.GetMaterialUVDetail()));
                     },
                     & ElemMatSymb::SetMaterialUVDetail);
    c10.def("GetMaterialUVDetail", [] (ElemMatSymbCR self) { return MaterialUVDetailPtr(const_cast<MaterialUVDetailP>(self.GetMaterialUVDetail())); });
    c10.def("SetMaterialUVDetail", &ElemMatSymb::SetMaterialUVDetail, "detail"_a, DOC(Bentley, DgnPlatform, ElemMatSymb, SetMaterialUVDetail));
    
    c10.def_property_readonly("PatternParams", &ElemMatSymb::GetPatternParams);
    c10.def("GetPatternParams", &ElemMatSymb::GetPatternParams, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ElemMatSymb, GetPatternParams));
    
    c10.def("SetIndexedLineColorTBGR", &ElemMatSymb::SetIndexedLineColorTBGR, "index"_a, "lineColor"_a);
    c10.def("SetIndexedFillColorTBGR", &ElemMatSymb::SetIndexedFillColorTBGR, "index"_a, "fillColor"_a);
    c10.def("SetIndexedRasterPattern", &ElemMatSymb::SetIndexedRasterPattern, "index"_a, "rasterPat"_a);
    c10.def("SetMaterial", &ElemMatSymb::SetMaterial, "material"_a, "seedContext"_a = nullptr, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, ElemMatSymb, SetMaterial));
    c10.def("SetPatternParams", [] (ElemMatSymb& self, PatternParamsP patternParams)
            {
            PatternParamsPtr paramPtr(patternParams);
            self.SetPatternParams(paramPtr);
            }, "patternParams"_a, DOC(Bentley, DgnPlatform, ElemMatSymb, SetPatternParams));

    //===================================================================================
    // enum OvrMatSymbFlags
    py::enum_< OvrMatSymbFlags>(m, "OvrMatSymbFlags", py::arithmetic())
        .value("eMATSYMB_OVERRIDE_None", MATSYMB_OVERRIDE_None)
        .value("eMATSYMB_OVERRIDE_Color", MATSYMB_OVERRIDE_Color)
        .value("eMATSYMB_OVERRIDE_ColorTransparency", MATSYMB_OVERRIDE_ColorTransparency)
        .value("eMATSYMB_OVERRIDE_FillColor", MATSYMB_OVERRIDE_FillColor)
        .value("eMATSYMB_OVERRIDE_FillColorTransparency", MATSYMB_OVERRIDE_FillColorTransparency)
        .value("eMATSYMB_OVERRIDE_RastWidth", MATSYMB_OVERRIDE_RastWidth)
        .value("eMATSYMB_OVERRIDE_Style", MATSYMB_OVERRIDE_Style)
        .value("eMATSYMB_OVERRIDE_TrueWidth", MATSYMB_OVERRIDE_TrueWidth)
        .value("eMATSYMB_OVERRIDE_ExtSymb", MATSYMB_OVERRIDE_ExtSymb)
        .value("eMATSYMB_OVERRIDE_RenderMaterial", MATSYMB_OVERRIDE_RenderMaterial)
        .value("eMATSYMB_OVERRIDE_FallbackRenderMaterial", MATSYMB_OVERRIDE_FallbackRenderMaterial)
        .export_values();

    //===================================================================================
    // struct OvrMatSymb
    py::class_< OvrMatSymb> c11(m, "OvrMatSymb");

    
    c11.def_property("Flags", &OvrMatSymb::GetFlags, &OvrMatSymb::SetFlags);
    c11.def("GetFlags", &OvrMatSymb::GetFlags, DOC(Bentley, DgnPlatform, OvrMatSymb, GetFlags));
    c11.def("SetFlags", &OvrMatSymb::SetFlags, "flags"_a, DOC(Bentley, DgnPlatform, OvrMatSymb, SetFlags));
    
    c11.def_property("LineColorTBGR", &OvrMatSymb::GetLineColorTBGR, &OvrMatSymb::SetLineColorTBGR);
    c11.def("GetLineColorTBGR", &OvrMatSymb::GetLineColorTBGR, DOC(Bentley, DgnPlatform, OvrMatSymb, GetLineColorTBGR));
    c11.def("SetLineColorTBGR", &OvrMatSymb::SetLineColorTBGR, "color"_a, DOC(Bentley, DgnPlatform, OvrMatSymb, SetLineColorTBGR));
    
    c11.def_property("FillColorTBGR", &OvrMatSymb::GetFillColorTBGR, &OvrMatSymb::SetFillColorTBGR);
    c11.def("GetFillColorTBGR", &OvrMatSymb::GetFillColorTBGR, DOC(Bentley, DgnPlatform, OvrMatSymb, GetFillColorTBGR));
    c11.def("SetFillColorTBGR", &OvrMatSymb::SetFillColorTBGR, "color"_a, DOC(Bentley, DgnPlatform, OvrMatSymb, SetFillColorTBGR));
    
    c11.def_property_readonly("LineColorIndex", &OvrMatSymb::GetLineColorIndex);
    c11.def("GetLineColorIndex", &OvrMatSymb::GetLineColorIndex, DOC(Bentley, DgnPlatform, OvrMatSymb, GetLineColorIndex));
    
    c11.def_property_readonly("FillColorIndex", &OvrMatSymb::GetFillColorIndex);
    c11.def("GetFillColorIndex", &OvrMatSymb::GetFillColorIndex, DOC(Bentley, DgnPlatform, OvrMatSymb, GetFillColorIndex));
    
    c11.def_property("Width", &OvrMatSymb::GetWidth, &OvrMatSymb::SetWidth);
    c11.def("GetWidth", &OvrMatSymb::GetWidth, DOC(Bentley, DgnPlatform, OvrMatSymb, GetWidth));
    c11.def("SetWidth", &OvrMatSymb::SetWidth, "width"_a, DOC(Bentley, DgnPlatform, OvrMatSymb, SetWidth));
    
    c11.def_property("RasterPattern", &OvrMatSymb::GetRasterPattern, &OvrMatSymb::SetRasterPattern);
    c11.def("GetRasterPattern", &OvrMatSymb::GetRasterPattern, DOC(Bentley, DgnPlatform, OvrMatSymb, GetRasterPattern));
    c11.def("SetRasterPattern", &OvrMatSymb::SetRasterPattern, "pattern"_a, DOC(Bentley, DgnPlatform, OvrMatSymb, SetRasterPattern));
    
    c11.def_property_readonly("RasterPatternIndex", &OvrMatSymb::GetRasterPatternIndex);
    c11.def("GetRasterPatternIndex", &OvrMatSymb::GetRasterPatternIndex, DOC(Bentley, DgnPlatform, OvrMatSymb, GetRasterPatternIndex));
    
    c11.def_property_readonly("Material", &OvrMatSymb::GetMaterial);
    c11.def("GetMaterial", &OvrMatSymb::GetMaterial, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, OvrMatSymb, GetMaterial));
    
    c11.def_property("MaterialUVDetail", [] (OvrMatSymbCR self) { return MaterialUVDetailPtr(const_cast<MaterialUVDetailP>(self.GetMaterialUVDetail())); }, &OvrMatSymb::SetMaterialUVDetail);
    c11.def("GetMaterialUVDetail", [] (OvrMatSymbCR self) { return MaterialUVDetailPtr(const_cast<MaterialUVDetailP>(self.GetMaterialUVDetail())); });
    c11.def("SetMaterialUVDetail", &OvrMatSymb::SetMaterialUVDetail, "detail"_a, DOC(Bentley, DgnPlatform, OvrMatSymb, SetMaterialUVDetail));
    
    c11.def_property_readonly("PatternParams", &OvrMatSymb::GetPatternParams);
    c11.def("GetPatternParams", &OvrMatSymb::GetPatternParams, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, OvrMatSymb, GetPatternParams));
    
    c11.def("Clear", &OvrMatSymb::Clear, DOC(Bentley, DgnPlatform, OvrMatSymb, Clear));
    c11.def("SetIndexedLineColorTBGR", &OvrMatSymb::SetIndexedLineColorTBGR, "index"_a, "lineColor"_a, DOC(Bentley, DgnPlatform, OvrMatSymb, SetIndexedLineColorTBGR));
    c11.def("SetIndexedFillColorTBGR", &OvrMatSymb::SetIndexedFillColorTBGR, "index"_a, "fillColor"_a, DOC(Bentley, DgnPlatform, OvrMatSymb, SetIndexedFillColorTBGR));
    c11.def("SetTransparentLineColor", &OvrMatSymb::SetTransparentLineColor, "transparency"_a, DOC(Bentley, DgnPlatform, OvrMatSymb, SetTransparentLineColor));
    c11.def("SetTransparentFillColor", &OvrMatSymb::SetTransparentFillColor, "transparency"_a, DOC(Bentley, DgnPlatform, OvrMatSymb, SetTransparentFillColor));
    c11.def("SetIndexedRasterPattern", &OvrMatSymb::SetIndexedRasterPattern, "index"_a, "rasterPat"_a, DOC(Bentley, DgnPlatform, OvrMatSymb, SetIndexedRasterPattern));
    c11.def("SetMaterial", &OvrMatSymb::SetMaterial, "material"_a, "context"_a = nullptr, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, OvrMatSymb, SetMaterial));
    
    c11.def("SetPatternParams", [] (OvrMatSymb& self, PatternParamsP patternParams)
            {
            PatternParamsPtr paramPtr(patternParams);
            self.SetPatternParams(paramPtr);
            }, "patternParams"_a, DOC(Bentley, DgnPlatform, OvrMatSymb, SetPatternParams));

    c11.def("SetLineStyle", &OvrMatSymb::SetLineStyle, "styleNo"_a, "modelRef"_a, "styleModelRef"_a, "lStyleParams"_a, "context"_a, "startTangent"_a, "endTangent"_a, DOC(Bentley, DgnPlatform, OvrMatSymb, SetLineStyle));

    //===================================================================================
    // struct IPointCloudDrawParams
    py::class_< IPointCloudDrawParams, std::unique_ptr< IPointCloudDrawParams, py::nodelete> > c12(m, "IPointCloudDrawParams");

    if (true)
        {
        //===================================================================================
        // enum VersionNumber
        py::enum_< IPointCloudDrawParams::VersionNumber>(c12, "VersionNumber", py::arithmetic())
            .value("eIPointCloudDrawParams_InitialVersion", IPointCloudDrawParams::IPointCloudDrawParams_InitialVersion)
            .export_values();
        }

    c12.def("IsThreadBound", &IPointCloudDrawParams::IsThreadBound, DOC(Bentley, DgnPlatform, IPointCloudDrawParams, IsThreadBound));
    c12.def("GetVersion", &IPointCloudDrawParams::GetVersion, DOC(Bentley, DgnPlatform, IPointCloudDrawParams, GetVersion));
    c12.def("GetRange", &IPointCloudDrawParams::GetRange, "range"_a, DOC(Bentley, DgnPlatform, IPointCloudDrawParams, GetRange));
    c12.def("GetOrigin", &IPointCloudDrawParams::GetOrigin, "origin"_a, DOC(Bentley, DgnPlatform, IPointCloudDrawParams, GetOrigin));
    
    c12.def("GetRgbColors", [] (IPointCloudDrawParams& self)
            {
            py::list outVal;
            UInt32 nItem = self.GetNumPoints();
            RgbColorDef const* colors = self.GetRgbColors();
            if (nItem > 0 && nullptr != colors)
                {
                for (UInt32 i = 0; i < nItem; i++)
                    outVal.append(py::cast(colors[i]));
                }
            return outVal;
            });

    c12.def("GetDPoints", [] (IPointCloudDrawParams& self)
            {
            py::list outVal;
            UInt32 nItem = self.GetNumPoints();
            DPoint3dCP pnts = self.GetDPoints();
            if (nItem > 0 && nullptr != pnts)
                {
                for (UInt32 i = 0; i < nItem; i++)
                    outVal.append(py::cast(pnts[i]));
                }
            return outVal;
            });

    c12.def("GetFPoints", [] (IPointCloudDrawParams& self)
            {
            py::list outVal;
            UInt32 nItem = self.GetNumPoints();
            FPoint3dCP pnts = self.GetFPoints();
            if (nItem > 0 && nullptr != pnts)
                {
                for (UInt32 i = 0; i < nItem; i++)
                    outVal.append(py::cast(pnts[i]));
                }
            return outVal;
            });    


    //===================================================================================
    // struct IDrawGeom
    py::class_< IDrawGeom
        , std::unique_ptr<IDrawGeom, py::nodelete>
    > c14(m, "IDrawGeom");

    c14.def_property("DrawViewFlags", 
                     py::cpp_function(&IDrawGeom::GetDrawViewFlags, py::return_value_policy::reference_internal), 
                     py::cpp_function(&IDrawGeom::SetDrawViewFlags, py::keep_alive<1, 2>()));

    c14.def("GetDrawViewFlags", &IDrawGeom::GetDrawViewFlags, py::return_value_policy::reference_internal);
    c14.def("SetDrawViewFlags", &IDrawGeom::SetDrawViewFlags, "flags"_a, py::keep_alive<1, 2>());

    c14.def("ActivateMatSymb", &IDrawGeom::ActivateMatSymb, "matSymb"_a);
    c14.def("ActivateOverrideMatSymb", &IDrawGeom::ActivateOverrideMatSymb, "ovrMatSymb"_a);
    
    c14.def("DrawLineString3d", [] (IDrawGeom& self, DPoint3dArray const& points, DPoint3dCP range)
            {
            self.DrawLineString3d((int)points.size(), points.data(), range);
            }, "points"_a, "range"_a);

    c14.def("DrawLineString2d", [] (IDrawGeom& self, DPoint2dArray const& points, double zDepth, DPoint2dCP range)
            {
            self.DrawLineString2d((int)points.size(), points.data(), zDepth, range);
            }, "points"_a, "zDepth"_a, "range"_a);

    c14.def("DrawPointString3d", [] (IDrawGeom& self, DPoint3dArray const& points, DPoint3dCP range)
            {
            self.DrawPointString3d((int)points.size(), points.data(), range);
            }, "points"_a, "range"_a);

    c14.def("DrawPointString2d", [] (IDrawGeom& self, DPoint2dArray const& points, double zDepth, DPoint2dCP range)
            {
            self.DrawPointString2d((int) points.size(), points.data(), zDepth, range);
            }, "points"_a, "zDepth"_a, "range"_a);

    c14.def("DrawShape3d", [] (IDrawGeom& self, DPoint3dArray const& points, bool filled, DPoint3dCP range)
            {
            self.DrawShape3d((int) points.size(), points.data(), filled, range);
            }, "points"_a, "filled"_a, "range"_a);

    c14.def("DrawShape2d", [] (IDrawGeom& self, DPoint2dArray const& points, bool filled, double zDepth, DPoint2dCP range)
            {
            self.DrawShape2d((int) points.size(), points.data(), filled, zDepth, range);
            }, "points"_a, "filled"_a, "zDepth"_a, "range"_a);

    c14.def("DrawArc3d", &IDrawGeom::DrawArc3d, "ellipse"_a, "isEllipse"_a, "filled"_a, "range"_a);
    c14.def("DrawArc2d", &IDrawGeom::DrawArc2d, "ellipse"_a, "isEllipse"_a, "filled"_a, "zDepth"_a, "range"_a);
    c14.def("DrawBSplineCurve", &IDrawGeom::DrawBSplineCurve, "curve"_a, "filled"_a);
    c14.def("DrawBSplineCurve2d", &IDrawGeom::DrawBSplineCurve2d, "curve"_a, "filled"_a, "zDepth"_a);
    c14.def("DrawCurveVector", &IDrawGeom::DrawCurveVector, "curves"_a, "filled"_a);
    c14.def("DrawCurveVector2d", &IDrawGeom::DrawCurveVector2d, "curves"_a, "filled"_a, "zDepth"_a);
    c14.def("DrawSolidPrimitive", &IDrawGeom::DrawSolidPrimitive, "primitive"_a);
    c14.def("DrawBSplineSurface", &IDrawGeom::DrawBSplineSurface, "surface"_a);
    c14.def("DrawPolyface", &IDrawGeom::DrawPolyface, "meshData"_a, "filled"_a = false, DOC(Bentley, DgnPlatform, IDrawGeom, DrawPolyface));
    c14.def("DrawBody", &IDrawGeom::DrawBody, "entity"_a, "attachments"_a = nullptr, "pixelSize"_a = 0.0);
    c14.def("DrawTextString", [] (IDrawGeom& self, TextStringCR text, boost::optional<double> zDepth)
            {
            self.DrawTextString(text, zDepth.get_ptr());
            }, "text"_a, "zDepth"_a = nullptr);


    c14.def("DrawTorus", &IDrawGeom::DrawTorus, "center"_a, "vectorX"_a, "vectorY"_a, "majorRadius"_a, "minorRadius"_a, "sweepAngle"_a, "capped"_a, DOC(Bentley, DgnPlatform, IDrawGeom, DrawTorus));
    c14.def("DrawCone", &IDrawGeom::DrawCone, "centerA"_a, "centerB"_a, "radiusA"_a, "radiusB"_a, "capped"_a, DOC(Bentley, DgnPlatform, IDrawGeom, DrawCone));
    c14.def("DrawSphere", &IDrawGeom::DrawSphere, "center"_a, "axes"_a, "radius"_a, DOC(Bentley, DgnPlatform, IDrawGeom, DrawSphere));
    c14.def("DrawBox", &IDrawGeom::DrawBox, "primary"_a, "secondary"_a, "basePoint"_a, "topPoint"_a, "baseWidth"_a, "baseLength"_a, "topWidth"_a, "topLength"_a, "capped"_a, DOC(Bentley, DgnPlatform, IDrawGeom, DrawBox));
    //===================================================================================
    // struct IViewDraw
    py::class_< IViewDraw
        , std::unique_ptr< IViewDraw, py::nodelete>
        , IDrawGeom> c15(m, "IViewDraw");

    c15.def("SetToViewCoords", &IViewDraw::SetToViewCoords, "yesNo"_a);
    c15.def("SetSymbology", &IViewDraw::SetSymbology, "lineColorTBGR"_a, "fillColorTBGR"_a, "lineWidth"_a, "linePattern"_a);
    c15.def("DrawGrid", &IViewDraw::DrawGrid, "doIsoGrid"_a, "drawDots"_a, "gridOrigin"_a, "xVector"_a, "yVector"_a, "gridsPerRef"_a, "repetitions"_a);
    c15.def("DrawSprite", &IViewDraw::DrawSprite, "sprite"_a, "location"_a, "xVec"_a, "transparency"_a);
    //c15.def("DrawTiledRaster", &IViewDraw::DrawTiledRaster, "tiledRaster"_a);

    c15.def("DrawRaster2d", [] (IViewDraw& self, std::array<DPoint2d, 4> const& points, int pitch, int numTexelsX, int numTexelsY, int enableAlpha, int format, py::bytes const& texels, double zDepth, DPoint2dCP range)
            {
            std::string strData = (std::string) texels;
            self.DrawRaster2d(points.data(), pitch, numTexelsX, numTexelsY, enableAlpha, format, (byte const*) strData.data(), zDepth, range);
            }, "points"_a, "pitch"_a, "numTexelsX"_a, "numTexelsY"_a, "enableAlpha"_a, "format"_a, "texels"_a, "zDepth"_a, "range"_a);

    c15.def("DrawRaster", [] (IViewDraw& self, std::array<DPoint3d, 4> const& points, int pitch, int numTexelsX, int numTexelsY, int enableAlpha, int format, py::bytes const& texels, DPoint3dCP range)
            {
            std::string strData = (std::string) texels;
            self.DrawRaster(points.data(), pitch, numTexelsX, numTexelsY, enableAlpha, format, (byte const*) strData.data(), range);
            }, "points"_a, "pitch"_a, "numTexelsX"_a, "numTexelsY"_a, "enableAlpha"_a, "format"_a, "texels"_a, "range"_a);

    c15.def("DrawPointCloud", &IViewDraw::DrawPointCloud, "drawParams"_a);
    c15.def("PopRenderOverrides", &IViewDraw::PopRenderOverrides);
    }