/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dimensionstyleprops.r.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DimensionStyleProps.r.h>

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DimensionStyleProps_r(py::module_& m)
    {
    //===================================================================================
    // Accuracy constants
    m.attr("DIMACC_INVALID") = DIMACC_INVALID;
    m.attr("DIMACC_0") = DIMACC_0;
    m.attr("DIMACC_1") = DIMACC_1;
    m.attr("DIMACC_2") = DIMACC_2;
    m.attr("DIMACC_3") = DIMACC_3;
    m.attr("DIMACC_4") = DIMACC_4;
    m.attr("DIMACC_5") = DIMACC_5;
    m.attr("DIMACC_6") = DIMACC_6;
    m.attr("DIMACC_7") = DIMACC_7;
    m.attr("DIMACC_8") = DIMACC_8;
    m.attr("DIMACC_HALF") = DIMACC_HALF;
    m.attr("DIMACC_4th") = DIMACC_4th;
    m.attr("DIMACC_8th") = DIMACC_8th;
    m.attr("DIMACC_16th") = DIMACC_16th;
    m.attr("DIMACC_32nd") = DIMACC_32nd;
    m.attr("DIMACC_64th") = DIMACC_64th;
    m.attr("DIMACC_Alt") = DIMACC_Alt;

    m.attr("DIMACC_SCI_1") = DIMACC_SCI_1;
    m.attr("DIMACC_SCI_2") = DIMACC_SCI_2;
    m.attr("DIMACC_SCI_3") = DIMACC_SCI_3;
    m.attr("DIMACC_SCI_4") = DIMACC_SCI_4;
    m.attr("DIMACC_SCI_5") = DIMACC_SCI_5;
    m.attr("DIMACC_SCI_6") = DIMACC_SCI_6;
    m.attr("DIMACC_SCI_7") = DIMACC_SCI_7;
    m.attr("DIMACC_SCI_8") = DIMACC_SCI_8;

    //===================================================================================
    // enum DimStyleProp_BallAndChain_Mode
    py::enum_< DimStyleProp_BallAndChain_Mode>(m, "DimStyleProp_BallAndChain_Mode", py::arithmetic())
        .value("eDIMSTYLE_VALUE_BallAndChain_Mode_None", DIMSTYLE_VALUE_BallAndChain_Mode_None)
        .value("eDIMSTYLE_VALUE_BallAndChain_Mode_On", DIMSTYLE_VALUE_BallAndChain_Mode_On)
        .value("eDIMSTYLE_VALUE_BallAndChain_Mode_Auto", DIMSTYLE_VALUE_BallAndChain_Mode_Auto)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_BallAndChain_Alignment
    py::enum_< DimStyleProp_BallAndChain_Alignment>(m, "DimStyleProp_BallAndChain_Alignment", py::arithmetic())
        .value("eDIMSTYLE_VALUE_BallAndChain_Alignment_Auto", DIMSTYLE_VALUE_BallAndChain_Alignment_Auto)
        .value("eDIMSTYLE_VALUE_BallAndChain_Alignment_Left", DIMSTYLE_VALUE_BallAndChain_Alignment_Left)
        .value("eDIMSTYLE_VALUE_BallAndChain_Alignment_Right", DIMSTYLE_VALUE_BallAndChain_Alignment_Right)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_Terminator_Type
    py::enum_< DimStyleProp_Terminator_Type>(m, "DimStyleProp_Terminator_Type", py::arithmetic())
        .value("eDIMSTYLE_VALUE_Terminator_Type_None", DIMSTYLE_VALUE_Terminator_Type_None)
        .value("eDIMSTYLE_VALUE_Terminator_Type_Arrow", DIMSTYLE_VALUE_Terminator_Type_Arrow)
        .value("eDIMSTYLE_VALUE_Terminator_Type_Stroke", DIMSTYLE_VALUE_Terminator_Type_Stroke)
        .value("eDIMSTYLE_VALUE_Terminator_Type_Origin", DIMSTYLE_VALUE_Terminator_Type_Origin)
        .value("eDIMSTYLE_VALUE_Terminator_Type_Dot", DIMSTYLE_VALUE_Terminator_Type_Dot)
        .value("eDIMSTYLE_VALUE_Terminator_Type_Note", DIMSTYLE_VALUE_Terminator_Type_Note)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_BallAndChain_ChainType
    py::enum_< DimStyleProp_BallAndChain_ChainType>(m, "DimStyleProp_BallAndChain_ChainType", py::arithmetic())
        .value("eDIMSTYLE_VALUE_BallAndChain_ChainType_None", DIMSTYLE_VALUE_BallAndChain_ChainType_None)
        .value("eDIMSTYLE_VALUE_BallAndChain_ChainType_Line", DIMSTYLE_VALUE_BallAndChain_ChainType_Line)
        .value("eDIMSTYLE_VALUE_BallAndChain_ChainType_Arc", DIMSTYLE_VALUE_BallAndChain_ChainType_Arc)
        .value("eDIMSTYLE_VALUE_BallAndChain_ChainType_BSpline", DIMSTYLE_VALUE_BallAndChain_ChainType_BSpline)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_General_Alignment
    py::enum_< DimStyleProp_General_Alignment>(m, "DimStyleProp_General_Alignment", py::arithmetic())
        .value("eDIMSTYLE_VALUE_General_Alignment_View", DIMSTYLE_VALUE_General_Alignment_View)
        .value("eDIMSTYLE_VALUE_General_Alignment_Drawing", DIMSTYLE_VALUE_General_Alignment_Drawing)
        .value("eDIMSTYLE_VALUE_General_Alignment_True", DIMSTYLE_VALUE_General_Alignment_True)
        .value("eDIMSTYLE_VALUE_General_Alignment_Arbitrary", DIMSTYLE_VALUE_General_Alignment_Arbitrary)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_General_RadialMode
    py::enum_< DimStyleProp_General_RadialMode>(m, "DimStyleProp_General_RadialMode", py::arithmetic())
        .value("eDIMSTYLE_VALUE_General_RadialMode_CenterMark", DIMSTYLE_VALUE_General_RadialMode_CenterMark)
        .value("eDIMSTYLE_VALUE_General_RadialMode_Radius", DIMSTYLE_VALUE_General_RadialMode_Radius)
        .value("eDIMSTYLE_VALUE_General_RadialMode_RadiusExtended", DIMSTYLE_VALUE_General_RadialMode_RadiusExtended)
        .value("eDIMSTYLE_VALUE_General_RadialMode_Diameter", DIMSTYLE_VALUE_General_RadialMode_Diameter)
        .value("eDIMSTYLE_VALUE_General_RadialMode_DiameterExtended", DIMSTYLE_VALUE_General_RadialMode_DiameterExtended)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_MLNote_FrameType
    py::enum_< DimStyleProp_MLNote_FrameType>(m, "DimStyleProp_MLNote_FrameType", py::arithmetic())
        .value("eDIMSTYLE_VALUE_MLNote_FrameType_None", DIMSTYLE_VALUE_MLNote_FrameType_None)
        .value("eDIMSTYLE_VALUE_MLNote_FrameType_Line", DIMSTYLE_VALUE_MLNote_FrameType_Line)
        .value("eDIMSTYLE_VALUE_MLNote_FrameType_Box", DIMSTYLE_VALUE_MLNote_FrameType_Box)
        .value("eDIMSTYLE_VALUE_MLNote_FrameType_RotatedBox", DIMSTYLE_VALUE_MLNote_FrameType_RotatedBox)
        .value("eDIMSTYLE_VALUE_MLNote_FrameType_Circle", DIMSTYLE_VALUE_MLNote_FrameType_Circle)
        .value("eDIMSTYLE_VALUE_MLNote_FrameType_Capsule", DIMSTYLE_VALUE_MLNote_FrameType_Capsule)
        .value("eDIMSTYLE_VALUE_MLNote_FrameType_Hexagon", DIMSTYLE_VALUE_MLNote_FrameType_Hexagon)
        .value("eDIMSTYLE_VALUE_MLNote_FrameType_RotatedHexagon", DIMSTYLE_VALUE_MLNote_FrameType_RotatedHexagon)
        .value("eDIMSTYLE_VALUE_MLNote_FrameType_Triangle", DIMSTYLE_VALUE_MLNote_FrameType_Triangle)
        .value("eDIMSTYLE_VALUE_MLNote_FrameType_Pentagon", DIMSTYLE_VALUE_MLNote_FrameType_Pentagon)
        .value("eDIMSTYLE_VALUE_MLNote_FrameType_Octagon", DIMSTYLE_VALUE_MLNote_FrameType_Octagon)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_MLNote_Justification
    py::enum_< DimStyleProp_MLNote_Justification>(m, "DimStyleProp_MLNote_Justification", py::arithmetic())
        .value("eDIMSTYLE_VALUE_MLNote_Justification_Left", DIMSTYLE_VALUE_MLNote_Justification_Left)
        .value("eDIMSTYLE_VALUE_MLNote_Justification_Right", DIMSTYLE_VALUE_MLNote_Justification_Right)
        .value("eDIMSTYLE_VALUE_MLNote_Justification_Dynamic", DIMSTYLE_VALUE_MLNote_Justification_Dynamic)
        .value("eDIMSTYLE_VALUE_MLNote_Justification_Center", DIMSTYLE_VALUE_MLNote_Justification_Center)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_MLNote_VerticalJustification
    py::enum_< DimStyleProp_MLNote_VerticalJustification>(m, "DimStyleProp_MLNote_VerticalJustification", py::arithmetic())
        .value("eDIMSTYLE_VALUE_MLNote_VerticalJustification_Top", DIMSTYLE_VALUE_MLNote_VerticalJustification_Top)
        .value("eDIMSTYLE_VALUE_MLNote_VerticalJustification_Center", DIMSTYLE_VALUE_MLNote_VerticalJustification_Center)
        .value("eDIMSTYLE_VALUE_MLNote_VerticalJustification_Bottom", DIMSTYLE_VALUE_MLNote_VerticalJustification_Bottom)
        .value("eDIMSTYLE_VALUE_MLNote_VerticalJustification_Dynamic", DIMSTYLE_VALUE_MLNote_VerticalJustification_Dynamic)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_MLNote_TextRotation
    py::enum_< DimStyleProp_MLNote_TextRotation>(m, "DimStyleProp_MLNote_TextRotation", py::arithmetic())
        .value("eDIMSTYLE_VALUE_MLNote_TextRotation_Horizontal", DIMSTYLE_VALUE_MLNote_TextRotation_Horizontal)
        .value("eDIMSTYLE_VALUE_MLNote_TextRotation_Vertical", DIMSTYLE_VALUE_MLNote_TextRotation_Vertical)
        .value("eDIMSTYLE_VALUE_MLNote_TextRotation_Inline", DIMSTYLE_VALUE_MLNote_TextRotation_Inline)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_MLNote_HorAttachment
    py::enum_< DimStyleProp_MLNote_HorAttachment>(m, "DimStyleProp_MLNote_HorAttachment", py::arithmetic())
        .value("eDIMSTYLE_VALUE_MLNote_HorAttachment_Auto", DIMSTYLE_VALUE_MLNote_HorAttachment_Auto)
        .value("eDIMSTYLE_VALUE_MLNote_HorAttachment_Left", DIMSTYLE_VALUE_MLNote_HorAttachment_Left)
        .value("eDIMSTYLE_VALUE_MLNote_HorAttachment_Right", DIMSTYLE_VALUE_MLNote_HorAttachment_Right)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_MLNote_VerAttachment
    py::enum_< DimStyleProp_MLNote_VerAttachment>(m, "DimStyleProp_MLNote_VerAttachment", py::arithmetic())
        .value("eDIMSTYLE_VALUE_MLNote_VerAttachment_Top", DIMSTYLE_VALUE_MLNote_VerAttachment_Top)
        .value("eDIMSTYLE_VALUE_MLNote_VerAttachment_TopLine", DIMSTYLE_VALUE_MLNote_VerAttachment_TopLine)
        .value("eDIMSTYLE_VALUE_MLNote_VerAttachment_Middle", DIMSTYLE_VALUE_MLNote_VerAttachment_Middle)
        .value("eDIMSTYLE_VALUE_MLNote_VerAttachment_BottomLine", DIMSTYLE_VALUE_MLNote_VerAttachment_BottomLine)
        .value("eDIMSTYLE_VALUE_MLNote_VerAttachment_Bottom", DIMSTYLE_VALUE_MLNote_VerAttachment_Bottom)
        .value("eDIMSTYLE_VALUE_MLNote_VerAttachment_DynamicLine", DIMSTYLE_VALUE_MLNote_VerAttachment_DynamicLine)
        .value("eDIMSTYLE_VALUE_MLNote_VerAttachment_DynamicCorner", DIMSTYLE_VALUE_MLNote_VerAttachment_DynamicCorner)
        .value("eDIMSTYLE_VALUE_MLNote_VerAttachment_Underline", DIMSTYLE_VALUE_MLNote_VerAttachment_Underline)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_Symbol_Standard
    py::enum_< DimStyleProp_Symbol_Standard>(m, "DimStyleProp_Symbol_Standard", py::arithmetic())
        .value("eDIMSTYLE_VALUE_Symbol_Standard_None", DIMSTYLE_VALUE_Symbol_Standard_None)
        .value("eDIMSTYLE_VALUE_Symbol_Standard_Diameter", DIMSTYLE_VALUE_Symbol_Standard_Diameter)
        .value("eDIMSTYLE_VALUE_Symbol_Standard_Radius", DIMSTYLE_VALUE_Symbol_Standard_Radius)
        .value("eDIMSTYLE_VALUE_Symbol_Standard_Area", DIMSTYLE_VALUE_Symbol_Standard_Area)
        .value("eDIMSTYLE_VALUE_Symbol_Standard_SphericalRadius", DIMSTYLE_VALUE_Symbol_Standard_SphericalRadius)
        .value("eDIMSTYLE_VALUE_Symbol_Standard_SphericalDiameter", DIMSTYLE_VALUE_Symbol_Standard_SphericalDiameter)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_Symbol_CustomType
    py::enum_< DimStyleProp_Symbol_CustomType>(m, "DimStyleProp_Symbol_CustomType", py::arithmetic())
        .value("eDIMSTYLE_VALUE_Symbol_CustomType_Default", DIMSTYLE_VALUE_Symbol_CustomType_Default)
        .value("eDIMSTYLE_VALUE_Symbol_CustomType_Character", DIMSTYLE_VALUE_Symbol_CustomType_Character)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_Symbol_PreSufType
    py::enum_< DimStyleProp_Symbol_PreSufType>(m, "DimStyleProp_Symbol_PreSufType", py::arithmetic())
        .value("eDIMSTYLE_VALUE_Symbol_PreSufType_None", DIMSTYLE_VALUE_Symbol_PreSufType_None)
        .value("eDIMSTYLE_VALUE_Symbol_PreSufType_Character", DIMSTYLE_VALUE_Symbol_PreSufType_Character)
        .value("eDIMSTYLE_VALUE_Symbol_PreSufType_Cell", DIMSTYLE_VALUE_Symbol_PreSufType_Cell)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_Symbol_TermType
    py::enum_< DimStyleProp_Symbol_TermType>(m, "DimStyleProp_Symbol_TermType", py::arithmetic())
        .value("eDIMSTYLE_VALUE_Symbol_TermType_Default", DIMSTYLE_VALUE_Symbol_TermType_Default)
        .value("eDIMSTYLE_VALUE_Symbol_TermType_Character", DIMSTYLE_VALUE_Symbol_TermType_Character)
        .value("eDIMSTYLE_VALUE_Symbol_TermType_Cell", DIMSTYLE_VALUE_Symbol_TermType_Cell)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_Terminator_Mode
    py::enum_< DimStyleProp_Terminator_Mode>(m, "DimStyleProp_Terminator_Mode", py::arithmetic())
        .value("eDIMSTYLE_VALUE_Terminator_Mode_Auto", DIMSTYLE_VALUE_Terminator_Mode_Auto)
        .value("eDIMSTYLE_VALUE_Terminator_Mode_Reversed", DIMSTYLE_VALUE_Terminator_Mode_Reversed)
        .value("eDIMSTYLE_VALUE_Terminator_Mode_Inside", DIMSTYLE_VALUE_Terminator_Mode_Inside)
        .value("eDIMSTYLE_VALUE_Terminator_Mode_Outside", DIMSTYLE_VALUE_Terminator_Mode_Outside)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_Terminator_Arrowhead
    py::enum_< DimStyleProp_Terminator_Arrowhead>(m, "DimStyleProp_Terminator_Arrowhead", py::arithmetic())
        .value("eDIMSTYLE_VALUE_Terminator_Arrowhead_Open", DIMSTYLE_VALUE_Terminator_Arrowhead_Open)
        .value("eDIMSTYLE_VALUE_Terminator_Arrowhead_Closed", DIMSTYLE_VALUE_Terminator_Arrowhead_Closed)
        .value("eDIMSTYLE_VALUE_Terminator_Arrowhead_Filled", DIMSTYLE_VALUE_Terminator_Arrowhead_Filled)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_Text_Justification
    py::enum_< DimStyleProp_Text_Justification>(m, "DimStyleProp_Text_Justification", py::arithmetic())
        .value("eDIMSTYLE_VALUE_Text_Justification_Offset", DIMSTYLE_VALUE_Text_Justification_Offset)
        .value("eDIMSTYLE_VALUE_Text_Justification_Left", DIMSTYLE_VALUE_Text_Justification_Left)
        .value("eDIMSTYLE_VALUE_Text_Justification_CenterLeft", DIMSTYLE_VALUE_Text_Justification_CenterLeft)
        .value("eDIMSTYLE_VALUE_Text_Justification_Right", DIMSTYLE_VALUE_Text_Justification_Right)
        .value("eDIMSTYLE_VALUE_Text_Justification_CenterRight", DIMSTYLE_VALUE_Text_Justification_CenterRight)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_Value_AngleFormat
    py::enum_< DimStyleProp_Value_AngleFormat>(m, "DimStyleProp_Value_AngleFormat", py::arithmetic())
        .value("eDIMSTYLE_VALUE_Value_AngleFormat_Degrees", DIMSTYLE_VALUE_Value_AngleFormat_Degrees)
        .value("eDIMSTYLE_VALUE_Value_AngleFormat_DegMinSec", DIMSTYLE_VALUE_Value_AngleFormat_DegMinSec)
        .value("eDIMSTYLE_VALUE_Value_AngleFormat_Centesimal", DIMSTYLE_VALUE_Value_AngleFormat_Centesimal)
        .value("eDIMSTYLE_VALUE_Value_AngleFormat_Radians", DIMSTYLE_VALUE_Value_AngleFormat_Radians)
        .value("eDIMSTYLE_VALUE_Value_AngleFormat_DegMin", DIMSTYLE_VALUE_Value_AngleFormat_DegMin)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_Value_AnglePrecision
    py::enum_< DimStyleProp_Value_AnglePrecision>(m, "DimStyleProp_Value_AnglePrecision", py::arithmetic())
        .value("eDIMSTYLE_VALUE_Value_AnglePrecision_Whole", DIMSTYLE_VALUE_Value_AnglePrecision_Whole)
        .value("eDIMSTYLE_VALUE_Value_AnglePrecision_1_Place", DIMSTYLE_VALUE_Value_AnglePrecision_1_Place)
        .value("eDIMSTYLE_VALUE_Value_AnglePrecision_2_Place", DIMSTYLE_VALUE_Value_AnglePrecision_2_Place)
        .value("eDIMSTYLE_VALUE_Value_AnglePrecision_3_Place", DIMSTYLE_VALUE_Value_AnglePrecision_3_Place)
        .value("eDIMSTYLE_VALUE_Value_AnglePrecision_4_Place", DIMSTYLE_VALUE_Value_AnglePrecision_4_Place)
        .value("eDIMSTYLE_VALUE_Value_AnglePrecision_5_Place", DIMSTYLE_VALUE_Value_AnglePrecision_5_Place)
        .value("eDIMSTYLE_VALUE_Value_AnglePrecision_6_Place", DIMSTYLE_VALUE_Value_AnglePrecision_6_Place)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_Value_DMSPrecisionMode
    py::enum_< DimStyleProp_Value_DMSPrecisionMode>(m, "DimStyleProp_Value_DMSPrecisionMode", py::arithmetic())
        .value("eDIMSTYLE_VALUE_Value_DMSPrecisionMode_Fixed", DIMSTYLE_VALUE_Value_DMSPrecisionMode_Fixed)
        .value("eDIMSTYLE_VALUE_Value_DMSPrecisionMode_Floating", DIMSTYLE_VALUE_Value_DMSPrecisionMode_Floating)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_Text_StackedFractionAlignment
    py::enum_< DimStyleProp_Text_StackedFractionAlignment>(m, "DimStyleProp_Text_StackedFractionAlignment", py::arithmetic())
        .value("eDIMSTYLE_VALUE_Text_StackedFractionAlignment_Top", DIMSTYLE_VALUE_Text_StackedFractionAlignment_Top)
        .value("eDIMSTYLE_VALUE_Text_StackedFractionAlignment_Center", DIMSTYLE_VALUE_Text_StackedFractionAlignment_Center)
        .value("eDIMSTYLE_VALUE_Text_StackedFractionAlignment_Bottom", DIMSTYLE_VALUE_Text_StackedFractionAlignment_Bottom)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_Text_StackedFractionType
    py::enum_< DimStyleProp_Text_StackedFractionType>(m, "DimStyleProp_Text_StackedFractionType", py::arithmetic())
        .value("eDIMSTYLE_VALUE_Text_StackedFractionType_FromFont", DIMSTYLE_VALUE_Text_StackedFractionType_FromFont)
        .value("eDIMSTYLE_VALUE_Text_StackedFractionType_Horizontal", DIMSTYLE_VALUE_Text_StackedFractionType_Horizontal)
        .value("eDIMSTYLE_VALUE_Text_StackedFractionType_Diagonal", DIMSTYLE_VALUE_Text_StackedFractionType_Diagonal)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_Placement_TextPosition
    py::enum_< DimStyleProp_Placement_TextPosition>(m, "DimStyleProp_Placement_TextPosition", py::arithmetic())
        .value("eDIMSTYLE_VALUE_Placement_TextPosition_Manual", DIMSTYLE_VALUE_Placement_TextPosition_Manual)
        .value("eDIMSTYLE_VALUE_Placement_TextPosition_SemiAuto", DIMSTYLE_VALUE_Placement_TextPosition_SemiAuto)
        .value("eDIMSTYLE_VALUE_Placement_TextPosition_Auto", DIMSTYLE_VALUE_Placement_TextPosition_Auto)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_Text_Location
    py::enum_< DimStyleProp_Text_Location>(m, "DimStyleProp_Text_Location", py::arithmetic())
        .value("eDIMSTYLE_VALUE_Text_Location_Inline", DIMSTYLE_VALUE_Text_Location_Inline)
        .value("eDIMSTYLE_VALUE_Text_Location_Above", DIMSTYLE_VALUE_Text_Location_Above)
        .value("eDIMSTYLE_VALUE_Text_Location_Outside", DIMSTYLE_VALUE_Text_Location_Outside)
        .value("eDIMSTYLE_VALUE_Text_Location_TopLeft", DIMSTYLE_VALUE_Text_Location_TopLeft)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_Text_SuperscriptMode
    py::enum_< DimStyleProp_Text_SuperscriptMode>(m, "DimStyleProp_Text_SuperscriptMode", py::arithmetic())
        .value("eDIMSTYLE_VALUE_Text_SuperscriptMode_FromFont", DIMSTYLE_VALUE_Text_SuperscriptMode_FromFont)
        .value("eDIMSTYLE_VALUE_Text_SuperscriptMode_Generated", DIMSTYLE_VALUE_Text_SuperscriptMode_Generated)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_Value_Format
    py::enum_< DimStyleProp_Value_Format>(m, "DimStyleProp_Value_Format", py::arithmetic())
        .value("eDIMSTYLE_VALUE_Value_Format_MU", DIMSTYLE_VALUE_Value_Format_MU)
        .value("eDIMSTYLE_VALUE_Value_Format_MU_Label", DIMSTYLE_VALUE_Value_Format_MU_Label)
        .value("eDIMSTYLE_VALUE_Value_Format_SU", DIMSTYLE_VALUE_Value_Format_SU)
        .value("eDIMSTYLE_VALUE_Value_Format_SU_Label", DIMSTYLE_VALUE_Value_Format_SU_Label)
        .value("eDIMSTYLE_VALUE_Value_Format_MU_dash_SU", DIMSTYLE_VALUE_Value_Format_MU_dash_SU)
        .value("eDIMSTYLE_VALUE_Value_Format_MU_Label_SU_Label", DIMSTYLE_VALUE_Value_Format_MU_Label_SU_Label)
        .value("eDIMSTYLE_VALUE_Value_Format_MU_Label_dash_SU_Label", DIMSTYLE_VALUE_Value_Format_MU_Label_dash_SU_Label)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_Value_Comparison
    py::enum_< DimStyleProp_Value_Comparison>(m, "DimStyleProp_Value_Comparison", py::arithmetic())
        .value("eDIMSTYLE_VALUE_Value_Compare_Less", DIMSTYLE_VALUE_Value_Compare_Less)
        .value("eDIMSTYLE_VALUE_Value_Compare_Greater", DIMSTYLE_VALUE_Value_Compare_Greater)
        .value("eDIMSTYLE_VALUE_Value_Compare_LessOrEqual", DIMSTYLE_VALUE_Value_Compare_LessOrEqual)
        .value("eDIMSTYLE_VALUE_Value_Compare_GreaterOrEqual", DIMSTYLE_VALUE_Value_Compare_GreaterOrEqual)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_Text_Vertical
    py::enum_< DimStyleProp_Text_Vertical>(m, "DimStyleProp_Text_Vertical", py::arithmetic())
        .value("eDIMSTYLE_VALUE_Text_Vertical_Never", DIMSTYLE_VALUE_Text_Vertical_Never)
        .value("eDIMSTYLE_VALUE_Text_Vertical_Always", DIMSTYLE_VALUE_Text_Vertical_Always)
        .value("eDIMSTYLE_VALUE_Text_Vertical_NoFit", DIMSTYLE_VALUE_Text_Vertical_NoFit)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_Value_ThousandsOpts
    py::enum_< DimStyleProp_Value_ThousandsOpts>(m, "DimStyleProp_Value_ThousandsOpts", py::arithmetic())
        .value("eDIMSTYLE_VALUE_Value_ThousandsSep_None", DIMSTYLE_VALUE_Value_ThousandsSep_None)
        .value("eDIMSTYLE_VALUE_Value_ThousandsSep_Space", DIMSTYLE_VALUE_Value_ThousandsSep_Space)
        .value("eDIMSTYLE_VALUE_Value_ThousandsSep_Comma", DIMSTYLE_VALUE_Value_ThousandsSep_Comma)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_Text_FrameType
    py::enum_< DimStyleProp_Text_FrameType>(m, "DimStyleProp_Text_FrameType", py::arithmetic())
        .value("eDIMSTYLE_VALUE_Text_FrameType_None", DIMSTYLE_VALUE_Text_FrameType_None)
        .value("eDIMSTYLE_VALUE_Text_FrameType_Box", DIMSTYLE_VALUE_Text_FrameType_Box)
        .value("eDIMSTYLE_VALUE_Text_FrameType_Capsule", DIMSTYLE_VALUE_Text_FrameType_Capsule)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_Value_LabelLineFormat
    py::enum_< DimStyleProp_Value_LabelLineFormat>(m, "DimStyleProp_Value_LabelLineFormat", py::arithmetic())
        .value("eDIMSTYLE_VALUE_Value_LabelLineFormat_Standard", DIMSTYLE_VALUE_Value_LabelLineFormat_Standard)
        .value("eDIMSTYLE_VALUE_Value_LabelLineFormat_AngleOverLength", DIMSTYLE_VALUE_Value_LabelLineFormat_AngleOverLength)
        .value("eDIMSTYLE_VALUE_Value_LabelLineFormat_LengthAbove", DIMSTYLE_VALUE_Value_LabelLineFormat_LengthAbove)
        .value("eDIMSTYLE_VALUE_Value_LabelLineFormat_AngleAbove", DIMSTYLE_VALUE_Value_LabelLineFormat_AngleAbove)
        .value("eDIMSTYLE_VALUE_Value_LabelLineFormat_LengthBelow", DIMSTYLE_VALUE_Value_LabelLineFormat_LengthBelow)
        .value("eDIMSTYLE_VALUE_Value_LabelLineFormat_AngleBelow", DIMSTYLE_VALUE_Value_LabelLineFormat_AngleBelow)
        .value("eDIMSTYLE_VALUE_Value_LabelLineFormat_LengthAngleAbove", DIMSTYLE_VALUE_Value_LabelLineFormat_LengthAngleAbove)
        .value("eDIMSTYLE_VALUE_Value_LabelLineFormat_LengthAngleBelow", DIMSTYLE_VALUE_Value_LabelLineFormat_LengthAngleBelow)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_Value_Accuracy
    py::enum_< DimStyleProp_Value_Accuracy>(m, "DimStyleProp_Value_Accuracy", py::arithmetic())
        .value("eDIMSTYLE_VALUE_Value_Accuracy_Whole", DIMSTYLE_VALUE_Value_Accuracy_Whole)
        .value("eDIMSTYLE_VALUE_Value_Accuracy_1_Decimal", DIMSTYLE_VALUE_Value_Accuracy_1_Decimal)
        .value("eDIMSTYLE_VALUE_Value_Accuracy_2_Decimal", DIMSTYLE_VALUE_Value_Accuracy_2_Decimal)
        .value("eDIMSTYLE_VALUE_Value_Accuracy_3_Decimal", DIMSTYLE_VALUE_Value_Accuracy_3_Decimal)
        .value("eDIMSTYLE_VALUE_Value_Accuracy_4_Decimal", DIMSTYLE_VALUE_Value_Accuracy_4_Decimal)
        .value("eDIMSTYLE_VALUE_Value_Accuracy_5_Decimal", DIMSTYLE_VALUE_Value_Accuracy_5_Decimal)
        .value("eDIMSTYLE_VALUE_Value_Accuracy_6_Decimal", DIMSTYLE_VALUE_Value_Accuracy_6_Decimal)
        .value("eDIMSTYLE_VALUE_Value_Accuracy_7_Decimal", DIMSTYLE_VALUE_Value_Accuracy_7_Decimal)
        .value("eDIMSTYLE_VALUE_Value_Accuracy_8_Decimal", DIMSTYLE_VALUE_Value_Accuracy_8_Decimal)
        .value("eDIMSTYLE_VALUE_Value_Accuracy_Half", DIMSTYLE_VALUE_Value_Accuracy_Half)
        .value("eDIMSTYLE_VALUE_Value_Accuracy_Quarter", DIMSTYLE_VALUE_Value_Accuracy_Quarter)
        .value("eDIMSTYLE_VALUE_Value_Accuracy_Eighth", DIMSTYLE_VALUE_Value_Accuracy_Eighth)
        .value("eDIMSTYLE_VALUE_Value_Accuracy_Sixteenth", DIMSTYLE_VALUE_Value_Accuracy_Sixteenth)
        .value("eDIMSTYLE_VALUE_Value_Accuracy_ThirtySecond", DIMSTYLE_VALUE_Value_Accuracy_ThirtySecond)
        .value("eDIMSTYLE_VALUE_Value_Accuracy_SixtyFourth", DIMSTYLE_VALUE_Value_Accuracy_SixtyFourth)
        .value("eDIMSTYLE_VALUE_Value_Accuracy_Scientific_1_Decimal", DIMSTYLE_VALUE_Value_Accuracy_Scientific_1_Decimal)
        .value("eDIMSTYLE_VALUE_Value_Accuracy_Scientific_2_Decimal", DIMSTYLE_VALUE_Value_Accuracy_Scientific_2_Decimal)
        .value("eDIMSTYLE_VALUE_Value_Accuracy_Scientific_3_Decimal", DIMSTYLE_VALUE_Value_Accuracy_Scientific_3_Decimal)
        .value("eDIMSTYLE_VALUE_Value_Accuracy_Scientific_4_Decimal", DIMSTYLE_VALUE_Value_Accuracy_Scientific_4_Decimal)
        .value("eDIMSTYLE_VALUE_Value_Accuracy_Scientific_5_Decimal", DIMSTYLE_VALUE_Value_Accuracy_Scientific_5_Decimal)
        .value("eDIMSTYLE_VALUE_Value_Accuracy_Scientific_6_Decimal", DIMSTYLE_VALUE_Value_Accuracy_Scientific_6_Decimal)
        .value("eDIMSTYLE_VALUE_Value_Accuracy_Scientific_7_Decimal", DIMSTYLE_VALUE_Value_Accuracy_Scientific_7_Decimal)
        .value("eDIMSTYLE_VALUE_Value_Accuracy_Scientific_8_Decimal", DIMSTYLE_VALUE_Value_Accuracy_Scientific_8_Decimal)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_FitOptions
    py::enum_< DimStyleProp_FitOptions>(m, "DimStyleProp_FitOptions", py::arithmetic())
        .value("eDIMSTYLE_VALUE_FitOption_MoveTermsFirst", DIMSTYLE_VALUE_FitOption_MoveTermsFirst)
        .value("eDIMSTYLE_VALUE_FitOption_ReverseTerms", DIMSTYLE_VALUE_FitOption_ReverseTerms)
        .value("eDIMSTYLE_VALUE_FitOption_KeepTermsInside", DIMSTYLE_VALUE_FitOption_KeepTermsInside)
        .value("eDIMSTYLE_VALUE_FitOption_KeepTermsOutside", DIMSTYLE_VALUE_FitOption_KeepTermsOutside)
        .value("eDIMSTYLE_VALUE_FitOption_KeepTextInside", DIMSTYLE_VALUE_FitOption_KeepTextInside)
        .value("eDIMSTYLE_VALUE_FitOption_MoveTextFirst", DIMSTYLE_VALUE_FitOption_MoveTextFirst)
        .value("eDIMSTYLE_VALUE_FitOption_MoveBoth", DIMSTYLE_VALUE_FitOption_MoveBoth)
        .value("eDIMSTYLE_VALUE_FitOption_MoveEither", DIMSTYLE_VALUE_FitOption_MoveEither)
        .export_values();

    //===================================================================================
    // enum DimStyleProp
    py::enum_< DimStyleProp>(m, "DimStyleProp", py::arithmetic())
        .value("eDIMSTYLE_PROP_Invalid", DIMSTYLE_PROP_Invalid)
        .value("eDIMSTYLE_PROP_BallAndChain_Alignment_INTEGER", DIMSTYLE_PROP_BallAndChain_Alignment_INTEGER)
        .value("eDIMSTYLE_PROP_BallAndChain_ChainTerminator_INTEGER", DIMSTYLE_PROP_BallAndChain_ChainTerminator_INTEGER)
        .value("eDIMSTYLE_PROP_BallAndChain_ChainType_INTEGER", DIMSTYLE_PROP_BallAndChain_ChainType_INTEGER)
        .value("eDIMSTYLE_PROP_BallAndChain_IsActive_BOOLINT", DIMSTYLE_PROP_BallAndChain_IsActive_BOOLINT)
        .value("eDIMSTYLE_PROP_BallAndChain_ShowTextLeader_BOOLINT", DIMSTYLE_PROP_BallAndChain_ShowTextLeader_BOOLINT)
        .value("eDIMSTYLE_PROP_BallAndChain_NoDockOnDimLine_BOOLINT", DIMSTYLE_PROP_BallAndChain_NoDockOnDimLine_BOOLINT)
        .value("eDIMSTYLE_PROP_BallAndChain_ElbowLength_DOUBLE", DIMSTYLE_PROP_BallAndChain_ElbowLength_DOUBLE)
        .value("eDIMSTYLE_PROP_MLNote_ElbowLength_DOUBLE", DIMSTYLE_PROP_MLNote_ElbowLength_DOUBLE)
        .value("eDIMSTYLE_PROP_BallAndChain_UseElbowLength_BOOLINT", DIMSTYLE_PROP_BallAndChain_UseElbowLength_BOOLINT)
        .value("eDIMSTYLE_PROP_BallAndChain_Mode_INTEGER", DIMSTYLE_PROP_BallAndChain_Mode_INTEGER)
        .value("eDIMSTYLE_PROP_ExtensionLine_Color_COLOR", DIMSTYLE_PROP_ExtensionLine_Color_COLOR)
        .value("eDIMSTYLE_PROP_ExtensionLine_Extend_DOUBLE", DIMSTYLE_PROP_ExtensionLine_Extend_DOUBLE)
        .value("eDIMSTYLE_PROP_ExtensionLine_Join_BOOLINT", DIMSTYLE_PROP_ExtensionLine_Join_BOOLINT)
        .value("eDIMSTYLE_PROP_ExtensionLine_Left_TEMPLATEFLAG", DIMSTYLE_PROP_ExtensionLine_Left_TEMPLATEFLAG)
        .value("eDIMSTYLE_PROP_ExtensionLine_LineStyle_LINESTYLE", DIMSTYLE_PROP_ExtensionLine_LineStyle_LINESTYLE)
        .value("eDIMSTYLE_PROP_ExtensionLine_Offset_DOUBLE", DIMSTYLE_PROP_ExtensionLine_Offset_DOUBLE)
        .value("eDIMSTYLE_PROP_ExtensionLine_OverrideColor_BOOLINT", DIMSTYLE_PROP_ExtensionLine_OverrideColor_BOOLINT)
        .value("eDIMSTYLE_PROP_ExtensionLine_OverrideLineStyle_BOOLINT", DIMSTYLE_PROP_ExtensionLine_OverrideLineStyle_BOOLINT)
        .value("eDIMSTYLE_PROP_ExtensionLine_OverrideWeight_BOOLINT", DIMSTYLE_PROP_ExtensionLine_OverrideWeight_BOOLINT)
        .value("eDIMSTYLE_PROP_ExtensionLine_Right_TEMPLATEFLAG", DIMSTYLE_PROP_ExtensionLine_Right_TEMPLATEFLAG)
        .value("eDIMSTYLE_PROP_ExtensionLine_ShowAny_BOOLINT", DIMSTYLE_PROP_ExtensionLine_ShowAny_BOOLINT)
        .value("eDIMSTYLE_PROP_ExtensionLine_Weight_WEIGHT", DIMSTYLE_PROP_ExtensionLine_Weight_WEIGHT)
        .value("eDIMSTYLE_PROP_ExtensionLine_AngleChordAlign_TEMPLATEFLAG", DIMSTYLE_PROP_ExtensionLine_AngleChordAlign_TEMPLATEFLAG)
        .value("eDIMSTYLE_PROP_General_Alignment_INTEGER", DIMSTYLE_PROP_General_Alignment_INTEGER)
        .value("eDIMSTYLE_PROP_General_CenterMarkSize_DISTANCE", DIMSTYLE_PROP_General_CenterMarkSize_DISTANCE)
        .value("eDIMSTYLE_PROP_General_Color_COLOR", DIMSTYLE_PROP_General_Color_COLOR)
        .value("eDIMSTYLE_PROP_General_DimensionScale_DOUBLE", DIMSTYLE_PROP_General_DimensionScale_DOUBLE)
        .value("eDIMSTYLE_PROP_General_DimStyleDescription_MSWCHAR", DIMSTYLE_PROP_General_DimStyleDescription_MSWCHAR)
        .value("eDIMSTYLE_PROP_General_DimStyleName_MSWCHAR", DIMSTYLE_PROP_General_DimStyleName_MSWCHAR)
        .value("eDIMSTYLE_PROP_General_Font_FONT", DIMSTYLE_PROP_General_Font_FONT)
        .value("eDIMSTYLE_PROP_General_IgnoreLevelSymbology_BOOLINT", DIMSTYLE_PROP_General_IgnoreLevelSymbology_BOOLINT)
        .value("eDIMSTYLE_PROP_General_LineStyle_LINESTYLE", DIMSTYLE_PROP_General_LineStyle_LINESTYLE)
        .value("eDIMSTYLE_PROP_General_OverrideColor_BOOLINT", DIMSTYLE_PROP_General_OverrideColor_BOOLINT)
        .value("eDIMSTYLE_PROP_General_OverrideLineStyle_BOOLINT", DIMSTYLE_PROP_General_OverrideLineStyle_BOOLINT)
        .value("eDIMSTYLE_PROP_General_OverrideWeight_BOOLINT", DIMSTYLE_PROP_General_OverrideWeight_BOOLINT)
        .value("eDIMSTYLE_PROP_General_RadialMode_INTEGER", DIMSTYLE_PROP_General_RadialMode_INTEGER)
        .value("eDIMSTYLE_PROP_General_RelativeDimLine_BOOLINT", DIMSTYLE_PROP_General_RelativeDimLine_BOOLINT)
        .value("eDIMSTYLE_PROP_General_ShowCenterMark_TEMPLATEFLAG", DIMSTYLE_PROP_General_ShowCenterMark_TEMPLATEFLAG)
        .value("eDIMSTYLE_PROP_General_Stacked_TEMPLATEFLAG", DIMSTYLE_PROP_General_Stacked_TEMPLATEFLAG)
        .value("eDIMSTYLE_PROP_General_StackOffset_DISTANCE", DIMSTYLE_PROP_General_StackOffset_DISTANCE)
        .value("eDIMSTYLE_PROP_General_Weight_WEIGHT", DIMSTYLE_PROP_General_Weight_WEIGHT)
        .value("eDIMSTYLE_PROP_General_FitOption_INTEGER", DIMSTYLE_PROP_General_FitOption_INTEGER)
        .value("eDIMSTYLE_PROP_General_SuppressUnfitTerminators_BOOLINT", DIMSTYLE_PROP_General_SuppressUnfitTerminators_BOOLINT)
        .value("eDIMSTYLE_PROP_General_PushTextRight_BOOLINT", DIMSTYLE_PROP_General_PushTextRight_BOOLINT)
        .value("eDIMSTYLE_PROP_General_TightFitTextAbove_BOOLINT", DIMSTYLE_PROP_General_TightFitTextAbove_BOOLINT)
        .value("eDIMSTYLE_PROP_General_UseMinLeader_BOOLINT", DIMSTYLE_PROP_General_UseMinLeader_BOOLINT)
        .value("eDIMSTYLE_PROP_General_FitInclinedTextBox_BOOLINT", DIMSTYLE_PROP_General_FitInclinedTextBox_BOOLINT)
        .value("eDIMSTYLE_PROP_General_FrozenInSharedCell_BOOLINT", DIMSTYLE_PROP_General_FrozenInSharedCell_BOOLINT)
        .value("eDIMSTYLE_PROP_General_ExtendDimLineUnderText_BOOLINT", DIMSTYLE_PROP_General_ExtendDimLineUnderText_BOOLINT)
        .value("eDIMSTYLE_PROP_MLNote_FrameType_INTEGER", DIMSTYLE_PROP_MLNote_FrameType_INTEGER)
        .value("eDIMSTYLE_PROP_MLNote_Justification_INTEGER", DIMSTYLE_PROP_MLNote_Justification_INTEGER)
        .value("eDIMSTYLE_PROP_MLNote_ShowLeader_BOOLINT", DIMSTYLE_PROP_MLNote_ShowLeader_BOOLINT)
        .value("eDIMSTYLE_PROP_MLNote_VerticalJustification_INTEGER", DIMSTYLE_PROP_MLNote_VerticalJustification_INTEGER)
        .value("eDIMSTYLE_PROP_MLNote_LeaderType_BOOLINT", DIMSTYLE_PROP_MLNote_LeaderType_BOOLINT)
        .value("eDIMSTYLE_PROP_MLNote_TextRotation_INTEGER", DIMSTYLE_PROP_MLNote_TextRotation_INTEGER)
        .value("eDIMSTYLE_PROP_MLNote_HorAttachment_INTEGER", DIMSTYLE_PROP_MLNote_HorAttachment_INTEGER)
        .value("eDIMSTYLE_PROP_MLNote_VerLeftAttachment_INTEGER", DIMSTYLE_PROP_MLNote_VerLeftAttachment_INTEGER)
        .value("eDIMSTYLE_PROP_MLNote_VerRightAttachment_INTEGER", DIMSTYLE_PROP_MLNote_VerRightAttachment_INTEGER)
        .value("eDIMSTYLE_PROP_MLNote_LeftMargin_DOUBLE", DIMSTYLE_PROP_MLNote_LeftMargin_DOUBLE)
        .value("eDIMSTYLE_PROP_MLNote_LowerMargin_DOUBLE", DIMSTYLE_PROP_MLNote_LowerMargin_DOUBLE)
        .value("eDIMSTYLE_PROP_MLNote_ScaleFrame_BOOLINT", DIMSTYLE_PROP_MLNote_ScaleFrame_BOOLINT)
        .value("eDIMSTYLE_PROP_MLNote_FrameScale_DOUBLE", DIMSTYLE_PROP_MLNote_FrameScale_DOUBLE)
        .value("eDIMSTYLE_PROP_Placement_CompatibleV3_BOOLINT", DIMSTYLE_PROP_Placement_CompatibleV3_BOOLINT)
        .value("eDIMSTYLE_PROP_Placement_Level_LEVEL", DIMSTYLE_PROP_Placement_Level_LEVEL)
        .value("eDIMSTYLE_PROP_Placement_OverrideLevel_BOOLINT", DIMSTYLE_PROP_Placement_OverrideLevel_BOOLINT)
        .value("eDIMSTYLE_PROP_Placement_TextPosition_INTEGER", DIMSTYLE_PROP_Placement_TextPosition_INTEGER)
        .value("eDIMSTYLE_PROP_Placement_UseReferenceScale_BOOLINT", DIMSTYLE_PROP_Placement_UseReferenceScale_BOOLINT)
        .value("eDIMSTYLE_PROP_Placement_UseStyleAnnotationScale_BOOLINT", DIMSTYLE_PROP_Placement_UseStyleAnnotationScale_BOOLINT)
        .value("eDIMSTYLE_PROP_Placement_AnnotationScale_DOUBLE", DIMSTYLE_PROP_Placement_AnnotationScale_DOUBLE)
        .value("eDIMSTYLE_PROP_Symbol_DiameterChar_CHAR", DIMSTYLE_PROP_Symbol_DiameterChar_CHAR)
        .value("eDIMSTYLE_PROP_Symbol_DiameterFont_FONT", DIMSTYLE_PROP_Symbol_DiameterFont_FONT)
        .value("eDIMSTYLE_PROP_Symbol_DiameterType_INTEGER", DIMSTYLE_PROP_Symbol_DiameterType_INTEGER)
        .value("eDIMSTYLE_PROP_Symbol_LowerPrefixChar_CHAR", DIMSTYLE_PROP_Symbol_LowerPrefixChar_CHAR)
        .value("eDIMSTYLE_PROP_Symbol_LowerSuffixChar_CHAR", DIMSTYLE_PROP_Symbol_LowerSuffixChar_CHAR)
        .value("eDIMSTYLE_PROP_Symbol_MainPrefixChar_CHAR", DIMSTYLE_PROP_Symbol_MainPrefixChar_CHAR)
        .value("eDIMSTYLE_PROP_Symbol_MainSuffixChar_CHAR", DIMSTYLE_PROP_Symbol_MainSuffixChar_CHAR)
        .value("eDIMSTYLE_PROP_Symbol_PlusMinusChar_CHAR", DIMSTYLE_PROP_Symbol_PlusMinusChar_CHAR)
        .value("eDIMSTYLE_PROP_Symbol_PlusMinusType_INTEGER", DIMSTYLE_PROP_Symbol_PlusMinusType_INTEGER)
        .value("eDIMSTYLE_PROP_Symbol_Prefix_TEMPLATEFLAG", DIMSTYLE_PROP_Symbol_Prefix_TEMPLATEFLAG)
        .value("eDIMSTYLE_PROP_Symbol_PrefixCellName_MSWCHAR", DIMSTYLE_PROP_Symbol_PrefixCellName_MSWCHAR)
        .value("eDIMSTYLE_PROP_Symbol_PrefixChar_CHAR", DIMSTYLE_PROP_Symbol_PrefixChar_CHAR)
        .value("eDIMSTYLE_PROP_Symbol_PrefixFont_FONT", DIMSTYLE_PROP_Symbol_PrefixFont_FONT)
        .value("eDIMSTYLE_PROP_Symbol_PrefixType_INTEGER", DIMSTYLE_PROP_Symbol_PrefixType_INTEGER)
        .value("eDIMSTYLE_PROP_Symbol_Suffix_TEMPLATEFLAG", DIMSTYLE_PROP_Symbol_Suffix_TEMPLATEFLAG)
        .value("eDIMSTYLE_PROP_Symbol_SuffixCellName_MSWCHAR", DIMSTYLE_PROP_Symbol_SuffixCellName_MSWCHAR)
        .value("eDIMSTYLE_PROP_Symbol_SuffixChar_CHAR", DIMSTYLE_PROP_Symbol_SuffixChar_CHAR)
        .value("eDIMSTYLE_PROP_Symbol_SuffixFont_FONT", DIMSTYLE_PROP_Symbol_SuffixFont_FONT)
        .value("eDIMSTYLE_PROP_Symbol_SuffixType_INTEGER", DIMSTYLE_PROP_Symbol_SuffixType_INTEGER)
        .value("eDIMSTYLE_PROP_Symbol_TolPrefixChar_CHAR", DIMSTYLE_PROP_Symbol_TolPrefixChar_CHAR)
        .value("eDIMSTYLE_PROP_Symbol_TolSuffixChar_CHAR", DIMSTYLE_PROP_Symbol_TolSuffixChar_CHAR)
        .value("eDIMSTYLE_PROP_Symbol_UpperPrefixChar_CHAR", DIMSTYLE_PROP_Symbol_UpperPrefixChar_CHAR)
        .value("eDIMSTYLE_PROP_Symbol_UpperSuffixChar_CHAR", DIMSTYLE_PROP_Symbol_UpperSuffixChar_CHAR)
        .value("eDIMSTYLE_PROP_Terminator_ArrowCellName_MSWCHAR", DIMSTYLE_PROP_Terminator_ArrowCellName_MSWCHAR)
        .value("eDIMSTYLE_PROP_Terminator_ArrowChar_CHAR", DIMSTYLE_PROP_Terminator_ArrowChar_CHAR)
        .value("eDIMSTYLE_PROP_Terminator_ArrowFont_FONT", DIMSTYLE_PROP_Terminator_ArrowFont_FONT)
        .value("eDIMSTYLE_PROP_Terminator_ArrowType_INTEGER", DIMSTYLE_PROP_Terminator_ArrowType_INTEGER)
        .value("eDIMSTYLE_PROP_Terminator_Color_COLOR", DIMSTYLE_PROP_Terminator_Color_COLOR)
        .value("eDIMSTYLE_PROP_Terminator_DotCellName_MSWCHAR", DIMSTYLE_PROP_Terminator_DotCellName_MSWCHAR)
        .value("eDIMSTYLE_PROP_Terminator_DotChar_CHAR", DIMSTYLE_PROP_Terminator_DotChar_CHAR)
        .value("eDIMSTYLE_PROP_Terminator_DotFont_FONT", DIMSTYLE_PROP_Terminator_DotFont_FONT)
        .value("eDIMSTYLE_PROP_Terminator_DotType_INTEGER", DIMSTYLE_PROP_Terminator_DotType_INTEGER)
        .value("eDIMSTYLE_PROP_Terminator_First_TEMPLATEFLAG", DIMSTYLE_PROP_Terminator_First_TEMPLATEFLAG)
        .value("eDIMSTYLE_PROP_Terminator_Height_DOUBLE", DIMSTYLE_PROP_Terminator_Height_DOUBLE)
        .value("eDIMSTYLE_PROP_Terminator_Joint_TEMPLATEFLAG", DIMSTYLE_PROP_Terminator_Joint_TEMPLATEFLAG)
        .value("eDIMSTYLE_PROP_Terminator_Left_TEMPLATEFLAG", DIMSTYLE_PROP_Terminator_Left_TEMPLATEFLAG)
        .value("eDIMSTYLE_PROP_Terminator_LineStyle_LINESTYLE", DIMSTYLE_PROP_Terminator_LineStyle_LINESTYLE)
        .value("eDIMSTYLE_PROP_Terminator_MinLeader_DOUBLE", DIMSTYLE_PROP_Terminator_MinLeader_DOUBLE)
        .value("eDIMSTYLE_PROP_Terminator_Mode_INTEGER", DIMSTYLE_PROP_Terminator_Mode_INTEGER)
        .value("eDIMSTYLE_PROP_Terminator_NoLineThruArrow_BOOLINT", DIMSTYLE_PROP_Terminator_NoLineThruArrow_BOOLINT)
        .value("eDIMSTYLE_PROP_Terminator_NoLineThruDot_BOOLINT", DIMSTYLE_PROP_Terminator_NoLineThruDot_BOOLINT)
        .value("eDIMSTYLE_PROP_Terminator_NoLineThruOrigin_BOOLINT", DIMSTYLE_PROP_Terminator_NoLineThruOrigin_BOOLINT)
        .value("eDIMSTYLE_PROP_Terminator_NoLineThruStroke_BOOLINT", DIMSTYLE_PROP_Terminator_NoLineThruStroke_BOOLINT)
        .value("eDIMSTYLE_PROP_Terminator_OriginCellName_MSWCHAR", DIMSTYLE_PROP_Terminator_OriginCellName_MSWCHAR)
        .value("eDIMSTYLE_PROP_Terminator_OriginChar_CHAR", DIMSTYLE_PROP_Terminator_OriginChar_CHAR)
        .value("eDIMSTYLE_PROP_Terminator_OriginFont_FONT", DIMSTYLE_PROP_Terminator_OriginFont_FONT)
        .value("eDIMSTYLE_PROP_Terminator_OriginType_INTEGER", DIMSTYLE_PROP_Terminator_OriginType_INTEGER)
        .value("eDIMSTYLE_PROP_Terminator_OverrideColor_BOOLINT", DIMSTYLE_PROP_Terminator_OverrideColor_BOOLINT)
        .value("eDIMSTYLE_PROP_Terminator_OverrideLineStyle_BOOLINT", DIMSTYLE_PROP_Terminator_OverrideLineStyle_BOOLINT)
        .value("eDIMSTYLE_PROP_Terminator_OverrideWeight_BOOLINT", DIMSTYLE_PROP_Terminator_OverrideWeight_BOOLINT)
        .value("eDIMSTYLE_PROP_Terminator_Right_TEMPLATEFLAG", DIMSTYLE_PROP_Terminator_Right_TEMPLATEFLAG)
        .value("eDIMSTYLE_PROP_Terminator_Arrowhead_INTEGER", DIMSTYLE_PROP_Terminator_Arrowhead_INTEGER)
        .value("eDIMSTYLE_PROP_Terminator_StrokeCellName_MSWCHAR", DIMSTYLE_PROP_Terminator_StrokeCellName_MSWCHAR)
        .value("eDIMSTYLE_PROP_Terminator_StrokeChar_CHAR", DIMSTYLE_PROP_Terminator_StrokeChar_CHAR)
        .value("eDIMSTYLE_PROP_Terminator_StrokeFont_FONT", DIMSTYLE_PROP_Terminator_StrokeFont_FONT)
        .value("eDIMSTYLE_PROP_Terminator_StrokeType_INTEGER", DIMSTYLE_PROP_Terminator_StrokeType_INTEGER)
        .value("eDIMSTYLE_PROP_Terminator_Weight_WEIGHT", DIMSTYLE_PROP_Terminator_Weight_WEIGHT)
        .value("eDIMSTYLE_PROP_Terminator_Width_DOUBLE", DIMSTYLE_PROP_Terminator_Width_DOUBLE)
        .value("eDIMSTYLE_PROP_Terminator_Note_INTEGER", DIMSTYLE_PROP_Terminator_Note_INTEGER)
        .value("eDIMSTYLE_PROP_Terminator_NoteType_INTEGER", DIMSTYLE_PROP_Terminator_NoteType_INTEGER)
        .value("eDIMSTYLE_PROP_Terminator_NoteCellName_MSWCHAR", DIMSTYLE_PROP_Terminator_NoteCellName_MSWCHAR)
        .value("eDIMSTYLE_PROP_Terminator_NoteChar_CHAR", DIMSTYLE_PROP_Terminator_NoteChar_CHAR)
        .value("eDIMSTYLE_PROP_Terminator_NoteFont_FONT", DIMSTYLE_PROP_Terminator_NoteFont_FONT)
        .value("eDIMSTYLE_PROP_Terminator_UniformCellScale_BOOLINT", DIMSTYLE_PROP_Terminator_UniformCellScale_BOOLINT)
        .value("eDIMSTYLE_PROP_Terminator_DimLineThruArrow_BOOLINT", DIMSTYLE_PROP_Terminator_DimLineThruArrow_BOOLINT)
        .value("eDIMSTYLE_PROP_Terminator_DimLineThruDot_BOOLINT", DIMSTYLE_PROP_Terminator_DimLineThruDot_BOOLINT)
        .value("eDIMSTYLE_PROP_Terminator_DimLineThruOrigin_BOOLINT", DIMSTYLE_PROP_Terminator_DimLineThruOrigin_BOOLINT)
        .value("eDIMSTYLE_PROP_Terminator_DimLineThruStroke_BOOLINT", DIMSTYLE_PROP_Terminator_DimLineThruStroke_BOOLINT)
        .value("eDIMSTYLE_PROP_Terminator_SuppressLargeTerminator_BOOLINT", DIMSTYLE_PROP_Terminator_SuppressLargeTerminator_BOOLINT)
        .value("eDIMSTYLE_PROP_Text_ArcLengthSymbol_TEMPLATEFLAG", DIMSTYLE_PROP_Text_ArcLengthSymbol_TEMPLATEFLAG)
        .value("eDIMSTYLE_PROP_Text_AutoLift_BOOLINT", DIMSTYLE_PROP_Text_AutoLift_BOOLINT)
        .value("eDIMSTYLE_PROP_Text_Box_BOOLINT", DIMSTYLE_PROP_Text_Box_BOOLINT)
        .value("eDIMSTYLE_PROP_Text_Capsule_BOOLINT", DIMSTYLE_PROP_Text_Capsule_BOOLINT)
        .value("eDIMSTYLE_PROP_Text_Color_COLOR", DIMSTYLE_PROP_Text_Color_COLOR)
        .value("eDIMSTYLE_PROP_Text_DecimalComma_BOOLINT", DIMSTYLE_PROP_Text_DecimalComma_BOOLINT)
        .value("eDIMSTYLE_PROP_Text_Embed_BOOLINT", DIMSTYLE_PROP_Text_Embed_BOOLINT)
        .value("eDIMSTYLE_PROP_Text_Font_BOOLINT", DIMSTYLE_PROP_Text_Font_BOOLINT)
        .value("eDIMSTYLE_PROP_Text_Height_DISTANCE", DIMSTYLE_PROP_Text_Height_DISTANCE)
        .value("eDIMSTYLE_PROP_Text_Horizontal_BOOLINT", DIMSTYLE_PROP_Text_Horizontal_BOOLINT)
        .value("eDIMSTYLE_PROP_Text_HorizontalMargin_DOUBLE", DIMSTYLE_PROP_Text_HorizontalMargin_DOUBLE)
        .value("eDIMSTYLE_PROP_Text_Justification_INTEGER", DIMSTYLE_PROP_Text_Justification_INTEGER)
        .value("eDIMSTYLE_PROP_Text_LeadingZero_BOOLINT", DIMSTYLE_PROP_Text_LeadingZero_BOOLINT)
        .value("eDIMSTYLE_PROP_Text_NoFitVertical_TEMPLATEFLAG", DIMSTYLE_PROP_Text_NoFitVertical_TEMPLATEFLAG)
        .value("eDIMSTYLE_PROP_Text_OmitLeadingDelimiter_BOOLINT", DIMSTYLE_PROP_Text_OmitLeadingDelimiter_BOOLINT)
        .value("eDIMSTYLE_PROP_Text_OverrideColor_BOOLINT", DIMSTYLE_PROP_Text_OverrideColor_BOOLINT)
        .value("eDIMSTYLE_PROP_Text_OverrideHeight_BOOLINT", DIMSTYLE_PROP_Text_OverrideHeight_BOOLINT)
        .value("eDIMSTYLE_PROP_Text_OverrideWeight_BOOLINT", DIMSTYLE_PROP_Text_OverrideWeight_BOOLINT)
        .value("eDIMSTYLE_PROP_Text_OverrideWidth_BOOLINT", DIMSTYLE_PROP_Text_OverrideWidth_BOOLINT)
        .value("eDIMSTYLE_PROP_Text_SecLeadingZero_BOOLINT", DIMSTYLE_PROP_Text_SecLeadingZero_BOOLINT)
        .value("eDIMSTYLE_PROP_Text_ShowSecondary_BOOLINT", DIMSTYLE_PROP_Text_ShowSecondary_BOOLINT)
        .value("eDIMSTYLE_PROP_Text_Underline_BOOLINT", DIMSTYLE_PROP_Text_Underline_BOOLINT)
        .value("eDIMSTYLE_PROP_Text_Vertical_TEMPLATEFLAG", DIMSTYLE_PROP_Text_Vertical_TEMPLATEFLAG)
        .value("eDIMSTYLE_PROP_Text_VerticalMargin_DOUBLE", DIMSTYLE_PROP_Text_VerticalMargin_DOUBLE)
        .value("eDIMSTYLE_PROP_Text_Weight_WEIGHT", DIMSTYLE_PROP_Text_Weight_WEIGHT)
        .value("eDIMSTYLE_PROP_Text_Width_DISTANCE", DIMSTYLE_PROP_Text_Width_DISTANCE)
        .value("eDIMSTYLE_PROP_Text_TextStyle_TEXTSTYLE", DIMSTYLE_PROP_Text_TextStyle_TEXTSTYLE)
        .value("eDIMSTYLE_PROP_Text_TextStyleID_INTEGER", DIMSTYLE_PROP_Text_TextStyleID_INTEGER)
        .value("eDIMSTYLE_PROP_Text_StackedFractionAlignment_INTEGER", DIMSTYLE_PROP_Text_StackedFractionAlignment_INTEGER)
        .value("eDIMSTYLE_PROP_Text_StackedFractions_BOOLINT", DIMSTYLE_PROP_Text_StackedFractions_BOOLINT)
        .value("eDIMSTYLE_PROP_Text_StackedFractionType_INTEGER", DIMSTYLE_PROP_Text_StackedFractionType_INTEGER)
        .value("eDIMSTYLE_PROP_Text_StackedFractionScale_DOUBLE", DIMSTYLE_PROP_Text_StackedFractionScale_DOUBLE)
        .value("eDIMSTYLE_PROP_Text_OverrideStackedFractions_BOOLINT", DIMSTYLE_PROP_Text_OverrideStackedFractions_BOOLINT)
        .value("eDIMSTYLE_PROP_Text_OverrideUnderline_BOOLINT", DIMSTYLE_PROP_Text_OverrideUnderline_BOOLINT)
        .value("eDIMSTYLE_PROP_Text_Location_INTEGER", DIMSTYLE_PROP_Text_Location_INTEGER)
        .value("eDIMSTYLE_PROP_Text_VerticalOpts_TEMPLATEFLAG", DIMSTYLE_PROP_Text_VerticalOpts_TEMPLATEFLAG)
        .value("eDIMSTYLE_PROP_Text_FrameType_INTEGER", DIMSTYLE_PROP_Text_FrameType_INTEGER)
        .value("eDIMSTYLE_PROP_Text_InlineTextLift_DOUBLE", DIMSTYLE_PROP_Text_InlineTextLift_DOUBLE)
        .value("eDIMSTYLE_PROP_Text_SuperscriptMode_INTEGER", DIMSTYLE_PROP_Text_SuperscriptMode_INTEGER)
        .value("eDIMSTYLE_PROP_Tolerance_LowerValue_DISTANCE", DIMSTYLE_PROP_Tolerance_LowerValue_DISTANCE)
        .value("eDIMSTYLE_PROP_Tolerance_Mode_BOOLINT", DIMSTYLE_PROP_Tolerance_Mode_BOOLINT)
        .value("eDIMSTYLE_PROP_Tolerance_Show_BOOLINT", DIMSTYLE_PROP_Tolerance_Show_BOOLINT)
        .value("eDIMSTYLE_PROP_Tolerance_StackEqual_BOOLINT", DIMSTYLE_PROP_Tolerance_StackEqual_BOOLINT)
        .value("eDIMSTYLE_PROP_Tolerance_TextHorizontalMargin_DOUBLE", DIMSTYLE_PROP_Tolerance_TextHorizontalMargin_DOUBLE)
        .value("eDIMSTYLE_PROP_Tolerance_TextScale_DOUBLE", DIMSTYLE_PROP_Tolerance_TextScale_DOUBLE)
        .value("eDIMSTYLE_PROP_Tolerance_TextVerticalMargin_DOUBLE", DIMSTYLE_PROP_Tolerance_TextVerticalMargin_DOUBLE)
        .value("eDIMSTYLE_PROP_Tolerance_TextVerticalSeparation_DOUBLE", DIMSTYLE_PROP_Tolerance_TextVerticalSeparation_DOUBLE)
        .value("eDIMSTYLE_PROP_Tolerance_UpperValue_DISTANCE", DIMSTYLE_PROP_Tolerance_UpperValue_DISTANCE)
        .value("eDIMSTYLE_PROP_Tolerance_Accuracy_ACCURACY", DIMSTYLE_PROP_Tolerance_Accuracy_ACCURACY)
        .value("eDIMSTYLE_PROP_Tolerance_SecAccuracy_ACCURACY", DIMSTYLE_PROP_Tolerance_SecAccuracy_ACCURACY)
        .value("eDIMSTYLE_PROP_Tolerance_ShowSignForZero_BOOLINT", DIMSTYLE_PROP_Tolerance_ShowSignForZero_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_Accuracy_ACCURACY", DIMSTYLE_PROP_Value_Accuracy_ACCURACY)
        .value("eDIMSTYLE_PROP_Value_AltAccuracy_ACCURACY", DIMSTYLE_PROP_Value_AltAccuracy_ACCURACY)
        .value("eDIMSTYLE_PROP_Value_AltIsActive_BOOLINT", DIMSTYLE_PROP_Value_AltIsActive_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_AltSecAccuracy_ACCURACY", DIMSTYLE_PROP_Value_AltSecAccuracy_ACCURACY)
        .value("eDIMSTYLE_PROP_Value_AltSecIsActive_BOOLINT", DIMSTYLE_PROP_Value_AltSecIsActive_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_AltSecShowDelimiter_BOOLINT", DIMSTYLE_PROP_Value_AltSecShowDelimiter_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_AltSecShowMasterUnit_BOOLINT", DIMSTYLE_PROP_Value_AltSecShowMasterUnit_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_AltSecShowSubUnit_BOOLINT", DIMSTYLE_PROP_Value_AltSecShowSubUnit_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_AltSecShowUnitLabel_BOOLINT", DIMSTYLE_PROP_Value_AltSecShowUnitLabel_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_AltSecShowWhenThresholdEqual_BOOLINT", DIMSTYLE_PROP_Value_AltSecShowWhenThresholdEqual_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_AltSecShowWhenThresholdLess_BOOLINT", DIMSTYLE_PROP_Value_AltSecShowWhenThresholdLess_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_AltSecShowZeroMasterUnit_BOOLINT", DIMSTYLE_PROP_Value_AltSecShowZeroMasterUnit_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_AltSecThreshold_DISTANCE", DIMSTYLE_PROP_Value_AltSecThreshold_DISTANCE)
        .value("eDIMSTYLE_PROP_Value_AltShowDelimiter_BOOLINT", DIMSTYLE_PROP_Value_AltShowDelimiter_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_AltShowMasterUnit_BOOLINT", DIMSTYLE_PROP_Value_AltShowMasterUnit_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_AltShowSubUnit_BOOLINT", DIMSTYLE_PROP_Value_AltShowSubUnit_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_AltShowUnitLabel_BOOLINT", DIMSTYLE_PROP_Value_AltShowUnitLabel_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_AltShowWhenThresholdEqual_BOOLINT", DIMSTYLE_PROP_Value_AltShowWhenThresholdEqual_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_AltShowWhenThresholdLess_BOOLINT", DIMSTYLE_PROP_Value_AltShowWhenThresholdLess_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_AltShowZeroMasterUnit_BOOLINT", DIMSTYLE_PROP_Value_AltShowZeroMasterUnit_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_AltThreshold_DISTANCE", DIMSTYLE_PROP_Value_AltThreshold_DISTANCE)
        .value("eDIMSTYLE_PROP_Value_AngleFormat_INTEGER", DIMSTYLE_PROP_Value_AngleFormat_INTEGER)
        .value("eDIMSTYLE_PROP_Value_AngleLeadingZero_BOOLINT", DIMSTYLE_PROP_Value_AngleLeadingZero_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_AngleMeasure_BOOLINT", DIMSTYLE_PROP_Value_AngleMeasure_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_AnglePrecision_INTEGER", DIMSTYLE_PROP_Value_AnglePrecision_INTEGER)
        .value("eDIMSTYLE_PROP_Value_AngleTrailingZeros_BOOLINT", DIMSTYLE_PROP_Value_AngleTrailingZeros_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_RoundLSD_BOOLINT", DIMSTYLE_PROP_Value_RoundLSD_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_SecAccuracy_ACCURACY", DIMSTYLE_PROP_Value_SecAccuracy_ACCURACY)
        .value("eDIMSTYLE_PROP_Value_SecShowDelimiter_BOOLINT", DIMSTYLE_PROP_Value_SecShowDelimiter_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_SecShowMasterUnit_BOOLINT", DIMSTYLE_PROP_Value_SecShowMasterUnit_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_SecShowSubUnit_BOOLINT", DIMSTYLE_PROP_Value_SecShowSubUnit_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_SecShowTrailingZeros_BOOLINT", DIMSTYLE_PROP_Value_SecShowTrailingZeros_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_SecShowUnitLabel_BOOLINT", DIMSTYLE_PROP_Value_SecShowUnitLabel_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_SecShowZeroMasterUnit_BOOLINT", DIMSTYLE_PROP_Value_SecShowZeroMasterUnit_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_ShowDelimiter_BOOLINT", DIMSTYLE_PROP_Value_ShowDelimiter_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_ShowMasterUnit_BOOLINT", DIMSTYLE_PROP_Value_ShowMasterUnit_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_ShowSubUnit_BOOLINT", DIMSTYLE_PROP_Value_ShowSubUnit_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_ShowTrailingZeros_BOOLINT", DIMSTYLE_PROP_Value_ShowTrailingZeros_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_ShowUnitLabel_BOOLINT", DIMSTYLE_PROP_Value_ShowUnitLabel_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_ShowZeroMasterUnit_BOOLINT", DIMSTYLE_PROP_Value_ShowZeroMasterUnit_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_NoReduceFraction_BOOLINT", DIMSTYLE_PROP_Value_NoReduceFraction_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_NoReduceAltFraction_BOOLINT", DIMSTYLE_PROP_Value_NoReduceAltFraction_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_NoReduceTolFraction_BOOLINT", DIMSTYLE_PROP_Value_NoReduceTolFraction_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_SuperscriptLSD_BOOLINT", DIMSTYLE_PROP_Value_SuperscriptLSD_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_ThousandsSeparator_BOOLINT", DIMSTYLE_PROP_Value_ThousandsSeparator_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_ThousandsSpace_BOOLINT", DIMSTYLE_PROP_Value_ThousandsSpace_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_Unit_UNITS", DIMSTYLE_PROP_Value_Unit_UNITS)
        .value("eDIMSTYLE_PROP_Value_UnitLabelMaster_MSWCHAR", DIMSTYLE_PROP_Value_UnitLabelMaster_MSWCHAR)
        .value("eDIMSTYLE_PROP_Value_UnitLabelSecMaster_MSWCHAR", DIMSTYLE_PROP_Value_UnitLabelSecMaster_MSWCHAR)
        .value("eDIMSTYLE_PROP_Value_UnitLabelSecSub_MSWCHAR", DIMSTYLE_PROP_Value_UnitLabelSecSub_MSWCHAR)
        .value("eDIMSTYLE_PROP_Value_UnitLabelSub_MSWCHAR", DIMSTYLE_PROP_Value_UnitLabelSub_MSWCHAR)
        .value("eDIMSTYLE_PROP_Value_UnitSec_UNITS", DIMSTYLE_PROP_Value_UnitSec_UNITS)
        .value("eDIMSTYLE_PROP_Value_UseWorkingUnits_BOOLINT", DIMSTYLE_PROP_Value_UseWorkingUnits_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_OrdDecrementReverse_BOOLINT", DIMSTYLE_PROP_Value_OrdDecrementReverse_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_OrdUseDatumValue_BOOLINT", DIMSTYLE_PROP_Value_OrdUseDatumValue_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_OrdDatumValue_DISTANCE", DIMSTYLE_PROP_Value_OrdDatumValue_DISTANCE)
        .value("eDIMSTYLE_PROP_Value_LabelLineSuppressAngle_BOOLINT", DIMSTYLE_PROP_Value_LabelLineSuppressAngle_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_LabelLineSuppressLength_BOOLINT", DIMSTYLE_PROP_Value_LabelLineSuppressLength_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_LabelLineInvertLabels_BOOLINT", DIMSTYLE_PROP_Value_LabelLineInvertLabels_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_NoReduceSecFraction_BOOLINT", DIMSTYLE_PROP_Value_NoReduceSecFraction_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_NoReduceAltSecFraction_BOOLINT", DIMSTYLE_PROP_Value_NoReduceAltSecFraction_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_NoReduceTolSecFraction_BOOLINT", DIMSTYLE_PROP_Value_NoReduceTolSecFraction_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_LabelLineAdjacentLabels_BOOLINT", DIMSTYLE_PROP_Value_LabelLineAdjacentLabels_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_OrdFreeLocation_BOOLINT", DIMSTYLE_PROP_Value_OrdFreeLocation_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_Format_INTEGER", DIMSTYLE_PROP_Value_Format_INTEGER)
        .value("eDIMSTYLE_PROP_Value_AltFormat_INTEGER", DIMSTYLE_PROP_Value_AltFormat_INTEGER)
        .value("eDIMSTYLE_PROP_Value_SecFormat_INTEGER", DIMSTYLE_PROP_Value_SecFormat_INTEGER)
        .value("eDIMSTYLE_PROP_Value_AltSecFormat_INTEGER", DIMSTYLE_PROP_Value_AltSecFormat_INTEGER)
        .value("eDIMSTYLE_PROP_Value_AltThresholdComparison_INTEGER", DIMSTYLE_PROP_Value_AltThresholdComparison_INTEGER)
        .value("eDIMSTYLE_PROP_Value_AltSecThresholdComparison_INTEGER", DIMSTYLE_PROP_Value_AltSecThresholdComparison_INTEGER)
        .value("eDIMSTYLE_PROP_Value_ThousandsOpts_INTEGER", DIMSTYLE_PROP_Value_ThousandsOpts_INTEGER)
        .value("eDIMSTYLE_PROP_Value_UnitMaster_ONEUNIT", DIMSTYLE_PROP_Value_UnitMaster_ONEUNIT)
        .value("eDIMSTYLE_PROP_Value_UnitSub_ONEUNIT", DIMSTYLE_PROP_Value_UnitSub_ONEUNIT)
        .value("eDIMSTYLE_PROP_Value_SecUnitMaster_ONEUNIT", DIMSTYLE_PROP_Value_SecUnitMaster_ONEUNIT)
        .value("eDIMSTYLE_PROP_Value_SecUnitSub_ONEUNIT", DIMSTYLE_PROP_Value_SecUnitSub_ONEUNIT)
        .value("eDIMSTYLE_PROP_Value_LabelLineFormat_INTEGER", DIMSTYLE_PROP_Value_LabelLineFormat_INTEGER)
        .value("eDIMSTYLE_PROP_Value_ShowZeroSubUnit_BOOLINT", DIMSTYLE_PROP_Value_ShowZeroSubUnit_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_AltShowZeroSubUnit_BOOLINT", DIMSTYLE_PROP_Value_AltShowZeroSubUnit_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_SecShowZeroSubUnit_BOOLINT", DIMSTYLE_PROP_Value_SecShowZeroSubUnit_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_AltSecShowZeroSubUnit_BOOLINT", DIMSTYLE_PROP_Value_AltSecShowZeroSubUnit_BOOLINT)
        .value("eDIMSTYLE_PROP_Value_DMSPrecisionMode_INTEGER", DIMSTYLE_PROP_Value_DMSPrecisionMode_INTEGER)
        .value("eDIMSTYLE_PROP_Value_RoundOff_DOUBLE", DIMSTYLE_PROP_Value_RoundOff_DOUBLE)
        .value("eDIMSTYLE_PROP_Value_SecRoundOff_DOUBLE", DIMSTYLE_PROP_Value_SecRoundOff_DOUBLE)
        .value("eDIMSTYLE_PROP_Value_SpaceAfterNonStackedFraction_BOOLINT", DIMSTYLE_PROP_Value_SpaceAfterNonStackedFraction_BOOLINT)
        .export_values();

    //===================================================================================
    // enum DimStyleProp_Type
    py::enum_< DimStyleProp_Type>(m, "DimStyleProp_Type", py::arithmetic())
        .value("ePROPTYPE_None", PROPTYPE_None)
        .value("ePROPTYPE_Accuracy", PROPTYPE_Accuracy)
        .value("ePROPTYPE_BoolInt", PROPTYPE_BoolInt)
        .value("ePROPTYPE_Char", PROPTYPE_Char)
        .value("ePROPTYPE_Color", PROPTYPE_Color)
        .value("ePROPTYPE_Distance", PROPTYPE_Distance)
        .value("ePROPTYPE_Double", PROPTYPE_Double)
        .value("ePROPTYPE_Integer", PROPTYPE_Integer)
        .value("ePROPTYPE_Font", PROPTYPE_Font)
        .value("ePROPTYPE_Level", PROPTYPE_Level)
        .value("ePROPTYPE_LineStyle", PROPTYPE_LineStyle)
        .value("ePROPTYPE_MSWChar", PROPTYPE_MSWChar)
        .value("ePROPTYPE_OneUnit", PROPTYPE_OneUnit)
        .value("ePROPTYPE_TemplateFlag", PROPTYPE_TemplateFlag)
        .value("ePROPTYPE_Units", PROPTYPE_Units)
        .value("ePROPTYPE_Weight", PROPTYPE_Weight)
        .export_values();

    //===================================================================================
    // enum DimensionPartType
    py::enum_< DimensionPartType>(m, "DimensionPartType", py::arithmetic())
        .value("eADTYPE_INHERIT", ADTYPE_INHERIT)
        .value("eADTYPE_EXT_LEFT", ADTYPE_EXT_LEFT)
        .value("eADTYPE_EXT_RIGHT", ADTYPE_EXT_RIGHT)
        .value("eADTYPE_TEXT_UPPER", ADTYPE_TEXT_UPPER)
        .value("eADTYPE_TEXT_LOWER", ADTYPE_TEXT_LOWER)
        .value("eADTYPE_TEXT_SINGLE", ADTYPE_TEXT_SINGLE)
        .value("eADTYPE_TERM_LEFT", ADTYPE_TERM_LEFT)
        .value("eADTYPE_TERM_RIGHT", ADTYPE_TERM_RIGHT)
        .value("eADTYPE_DIMLINE", ADTYPE_DIMLINE)
        .value("eADTYPE_CENTER", ADTYPE_CENTER)
        .value("eADTYPE_TEXT_SYMBOLS", ADTYPE_TEXT_SYMBOLS)
        .value("eADTYPE_CHAIN", ADTYPE_CHAIN)
        .export_values();

    //===================================================================================
    // enum DimensionPartSubType
    py::enum_< DimensionPartSubType>(m, "DimensionPartSubType", py::arithmetic())
        .value("eADSUB_NONE", ADSUB_NONE)
        .value("eADSUB_TOL_UPPER", ADSUB_TOL_UPPER)
        .value("eADSUB_TOL_LOWER", ADSUB_TOL_LOWER)
        .value("eADSUB_TOL_SINGLE", ADSUB_TOL_SINGLE)
        .value("eADSUB_LIM_UPPER", ADSUB_LIM_UPPER)
        .value("eADSUB_LIM_LOWER", ADSUB_LIM_LOWER)
        .value("eADSUB_LIM_SINGLE", ADSUB_LIM_SINGLE)
        .value("eADSUB_PREFIX", ADSUB_PREFIX)
        .value("eADSUB_SUFFIX", ADSUB_SUFFIX)
        .value("eADSUB_TERMSYMBOL", ADSUB_TERMSYMBOL)
        .value("eADSUB_LEADER", ADSUB_LEADER)
        .export_values();

    //===================================================================================
    // enum DimensionTextPartType
    py::enum_< DimensionTextPartType>(m, "DimensionTextPartType", py::arithmetic())
        .value("eDIMTEXTPART_Primary", DIMTEXTPART_Primary)
        .value("eDIMTEXTPART_Secondary", DIMTEXTPART_Secondary)
        .export_values();

    //===================================================================================
    // enum DimensionTextPartSubType
    py::enum_< DimensionTextPartSubType>(m, "DimensionTextPartSubType", py::arithmetic())
        .value("eDIMTEXTSUBPART_Main", DIMTEXTSUBPART_Main)
        .value("eDIMTEXTSUBPART_Tolerance_Plus", DIMTEXTSUBPART_Tolerance_Plus)
        .value("eDIMTEXTSUBPART_Tolerance_Minus", DIMTEXTSUBPART_Tolerance_Minus)
        .value("eDIMTEXTSUBPART_Limit_Upper", DIMTEXTSUBPART_Limit_Upper)
        .value("eDIMTEXTSUBPART_Limit_Lower", DIMTEXTSUBPART_Limit_Lower)
        .export_values();

    }