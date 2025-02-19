/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgnplatform.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnPlatform.h>

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnPlatform(py::module_& m)
    {
    //===================================================================================
    m.attr("MAX_DGN_NAMELENGTH") = (int)MAX_DGN_NAMELENGTH;
    m.attr("MAX_REFLOGICALNAME") = (int)MAX_REFLOGICALNAME;
    m.attr("MAX_ELEMENT_WORDS") = (int)MAX_ELEMENT_WORDS;
    m.attr("MAX_INTERNAL_ELEM_WORDS") = (int)MAX_INTERNAL_ELEM_WORDS;
    m.attr("MAX_ELEMENT_SIZE") = (int)MAX_ELEMENT_SIZE;
    m.attr("MAX_INTERNAL_ELEM_SIZE") = (int)MAX_INTERNAL_ELEM_SIZE;
    m.attr("MAX_ATTRIBSIZE") = (int)MAX_ATTRIBSIZE;
    m.attr("MAX_REFCLIPPNTS") = (int)MAX_REFCLIPPNTS;
    m.attr("MAX_REFFULLPATH") = (int)MAX_REFFULLPATH;
    m.attr("MAX_REFLOGICALNAMEBYTES") = (int)MAX_REFLOGICALNAMEBYTES;
    m.attr("MAX_REFDESCRIPTION") = (int)MAX_REFDESCRIPTION;
    m.attr("MAX_REFDESCRIPTIONBYTES") = (int)MAX_REFDESCRIPTIONBYTES;
    m.attr("MAX_REFBOUNDS") = (int)MAX_REFBOUNDS;
    m.attr("MAX_VIEWS") = (int)MAX_VIEWS;
    m.attr("MAX_EDFIELDS") = (int)MAX_EDFIELDS;
    m.attr("MAX_LINKAGE_STRING_LENGTH") = (int)MAX_LINKAGE_STRING_LENGTH;
    m.attr("MAX_LINKAGE_STRING_BYTES") = (int)MAX_LINKAGE_STRING_BYTES;
    m.attr("MAX_UNIT_NAME_LENGTH") = (int)MAX_UNIT_NAME_LENGTH;
    m.attr("MAX_UNIT_NAME_BYTES") = (int)MAX_UNIT_NAME_BYTES;
    m.attr("MAX_UNIT_LABEL_LENGTH") = (int)MAX_UNIT_LABEL_LENGTH;
    m.attr("MAX_UNIT_LABEL_BYTES") = (int)MAX_UNIT_LABEL_BYTES;
    m.attr("MAX_NAMEDVIEW_NAME_LENGTH") = (int)MAX_NAMEDVIEW_NAME_LENGTH;
    m.attr("MAX_NAMEDVIEW_NAME_BYTES") = (int)MAX_NAMEDVIEW_NAME_BYTES;
    m.attr("MAX_NAMEDVIEW_DESCR_LENGTH") = (int)MAX_NAMEDVIEW_DESCR_LENGTH;
    m.attr("MAX_NAMEDVIEW_DESCR_BYTES") = (int)MAX_NAMEDVIEW_DESCR_BYTES;
    m.attr("MAX_NAMEDVIEW_NAMESPACE_LENGTH") = (int)MAX_NAMEDVIEW_NAMESPACE_LENGTH;
    m.attr("MAX_NAMEDVIEW_NAMESPACE_BYTES") = (int)MAX_NAMEDVIEW_NAMESPACE_BYTES;
    m.attr("MAX_VIEWGROUP_NAME_LENGTH") = (int)MAX_VIEWGROUP_NAME_LENGTH;
    m.attr("MAX_VIEWGROUP_NAME_BYTES") = (int)MAX_VIEWGROUP_NAME_BYTES;
    m.attr("MAX_VIEWGROUP_DESCR_LENGTH") = (int)MAX_VIEWGROUP_DESCR_LENGTH;
    m.attr("MAX_VIEWGROUP_DESCR_BYTES") = (int)MAX_VIEWGROUP_DESCR_BYTES;
    m.attr("MAX_ACS_NAME_LENGTH") = (int)MAX_ACS_NAME_LENGTH;
    m.attr("MAX_ACS_NAME_BYTES") = (int)MAX_ACS_NAME_BYTES;
    m.attr("MAX_ACS_DESCR_LENGTH") = (int)MAX_ACS_DESCR_LENGTH;
    m.attr("MAX_ACS_DESCR_BYTES") = (int)MAX_ACS_DESCR_BYTES;
    m.attr("MAX_MODEL_NAME_LENGTH") = (int)MAX_MODEL_NAME_LENGTH;
    m.attr("MAX_MODEL_NAME_BYTES") = (int)MAX_MODEL_NAME_BYTES;
    m.attr("MAX_MODEL_DESCR_LENGTH") = (int)MAX_MODEL_DESCR_LENGTH;
    m.attr("MAX_MODEL_DESCR_BYTES") = (int)MAX_MODEL_DESCR_BYTES;
    m.attr("MAX_NAMEDGROUP_NAME_LENGTH") = (int)MAX_NAMEDGROUP_NAME_LENGTH;
    m.attr("MAX_NAMEDGROUP_NAME_BYTES") = (int)MAX_NAMEDGROUP_NAME_BYTES;
    m.attr("MAX_NAMEDGROUP_DESCR_LENGTH") = (int)MAX_NAMEDGROUP_DESCR_LENGTH;
    m.attr("MAX_NAMEDGROUP_DESCR_BYTES") = (int)MAX_NAMEDGROUP_DESCR_BYTES;
    m.attr("MAX_NAMEDGROUP_TYPE_LENGTH") = (int)MAX_NAMEDGROUP_TYPE_LENGTH;
    m.attr("MAX_NAMEDGROUP_TYPE_BYTES") = (int)MAX_NAMEDGROUP_TYPE_BYTES;
    m.attr("MAX_CELLNAME_LENGTH") = (int)MAX_CELLNAME_LENGTH;
    m.attr("MAX_CELLNAME_BYTES") = (int)MAX_CELLNAME_BYTES;
    m.attr("MAX_CELLDSCR_LENGTH") = (int)MAX_CELLDSCR_LENGTH;
    m.attr("MAX_CELLDSCR_BYTES") = (int)MAX_CELLDSCR_BYTES;
    m.attr("MAX_DICTIONARY_NAME_LENGTH") = (int)MAX_DICTIONARY_NAME_LENGTH;
    m.attr("MAX_DICTIONARY_DESCR_LENGTH") = (int)MAX_DICTIONARY_DESCR_LENGTH;
    m.attr("MAX_NAMEDFENCE_NAME_LENGTH") = (int)MAX_NAMEDFENCE_NAME_LENGTH;
    m.attr("MAX_NAMEDFENCE_DESCR_LENGTH") = (int)MAX_NAMEDFENCE_DESCR_LENGTH;
    m.attr("MAX_TEXTSTYLE_NAME_LENGTH") = (int)MAX_TEXTSTYLE_NAME_LENGTH;
    m.attr("MAX_TEXTSTYLE_NAME_BYTES") = (int)MAX_TEXTSTYLE_NAME_BYTES;
    m.attr("MAX_DIMSTYLE_NAME_LENGTH") = (int)MAX_DIMSTYLE_NAME_LENGTH;
    m.attr("MAX_DIMSTYLE_NAME_BYTES") = (int)MAX_DIMSTYLE_NAME_BYTES;
    m.attr("MAX_DIMSTYLE_DESCRIPTION_LENGTH") = (int)MAX_DIMSTYLE_DESCRIPTION_LENGTH;
    m.attr("MAX_DIMSTYLE_DESCRIPTION_BYTES") = (int)MAX_DIMSTYLE_DESCRIPTION_BYTES;
    m.attr("MAX_LEVEL_NAME_LENGTH") = (int)MAX_LEVEL_NAME_LENGTH;
    m.attr("MAX_LEVEL_NAME_BYTES") = (int)MAX_LEVEL_NAME_BYTES;
    m.attr("MAX_LEVEL_DESCRIPTION_LENGTH") = (int)MAX_LEVEL_DESCRIPTION_LENGTH;
    m.attr("MAX_LEVEL_DESCRIPTION_BYTES") = (int)MAX_LEVEL_DESCRIPTION_BYTES;
    m.attr("MAX_LEVEL_LIBRARY_NAME_LENGTH") = (int)MAX_LEVEL_LIBRARY_NAME_LENGTH;
    m.attr("MAX_LEVEL_LIBRARY_NAME_BYTES") = (int)MAX_LEVEL_LIBRARY_NAME_BYTES;
    m.attr("MAX_MODEL_DISPLAY_LENGTH") = (int)MAX_MODEL_DISPLAY_LENGTH;
    m.attr("MAX_MODEL_DISPLAY_BYTES") = (int)MAX_MODEL_DISPLAY_BYTES;
    m.attr("MAX_COLORBOOK_NAME") = (int)MAX_COLORBOOK_NAME;
    m.attr("MAX_COLORBOOK_ENTRY") = (int)MAX_COLORBOOK_ENTRY;
    m.attr("MAX_BOOKANDNAME_LEN") = (int)MAX_BOOKANDNAME_LEN;
    m.attr("MAX_VERTICES") = (int)MAX_VERTICES;
    m.attr("MIN_LINECODE") = (int)MIN_LINECODE;
    m.attr("MAX_LINECODE") = (int)MAX_LINECODE;
    m.attr("DEFAULTMODEL") = (int)DEFAULTMODEL;
    m.attr("MINIMUM_WINDOW_DEPTH") = (int)MINIMUM_WINDOW_DEPTH;
    m.attr("MAXIMUM_WINDOW_DEPTH") = (int)MAXIMUM_WINDOW_DEPTH;
    m.attr("MAX_PATH_ENTRIES") = (int)MAX_PATH_ENTRIES;
    m.attr("INVALID_LEVEL") = (int)INVALID_LEVEL;
    m.attr("INVALID_COLOR") = (int)INVALID_COLOR;
    m.attr("INVALID_STYLE") = (int)INVALID_STYLE;
    m.attr("INVALID_WEIGHT") = (int)INVALID_WEIGHT;
    m.attr("INVALID_CLASS ") = (int)INVALID_CLASS;
    m.attr("MAX_MATRIX_DATA_DOUBLE") = (int)MAX_MATRIX_DATA_DOUBLE;
    m.attr("MAX_MATRIX_DATA_INT") = (int)MAX_MATRIX_DATA_INT;

    //===================================================================================
    // enum LinkageKeyValues
    py::enum_< LinkageKeyValues>(m, "LinkageKeyValues")
        .value("eSTRING_LINKAGE_KEY_Generic", LinkageKeyValues::STRING_LINKAGE_KEY_Generic)
        .value("eSTRING_LINKAGE_KEY_Name", LinkageKeyValues::STRING_LINKAGE_KEY_Name)
        .value("eSTRING_LINKAGE_KEY_Description", LinkageKeyValues::STRING_LINKAGE_KEY_Description)
        .value("eSTRING_LINKAGE_KEY_FileName", LinkageKeyValues::STRING_LINKAGE_KEY_FileName)
        .value("eSTRING_LINKAGE_KEY_LogicalName", LinkageKeyValues::STRING_LINKAGE_KEY_LogicalName)
        .value("eSTRING_LINKAGE_KEY_PatternCell", LinkageKeyValues::STRING_LINKAGE_KEY_PatternCell)
        .value("eSTRING_LINKAGE_KEY_DimensionStyle", LinkageKeyValues::STRING_LINKAGE_KEY_DimensionStyle)
        .value("eSTRING_LINKAGE_KEY_DimStyleDescr", LinkageKeyValues::STRING_LINKAGE_KEY_DimStyleDescr)
        .value("eSTRING_LINKAGE_KEY_Library", LinkageKeyValues::STRING_LINKAGE_KEY_Library)
        .value("eSTRING_LINKAGE_KEY_ProfileName", LinkageKeyValues::STRING_LINKAGE_KEY_ProfileName)
        .value("eSTRING_LINKAGE_KEY_LevelNameExpr", LinkageKeyValues::STRING_LINKAGE_KEY_LevelNameExpr)
        .value("eSTRING_LINKAGE_KEY_LevelDescriptionExpr", LinkageKeyValues::STRING_LINKAGE_KEY_LevelDescriptionExpr)
        .value("eSTRING_LINKAGE_KEY_LevelColorExpr", LinkageKeyValues::STRING_LINKAGE_KEY_LevelColorExpr)
        .value("eSTRING_LINKAGE_KEY_LevelStyleExpr", LinkageKeyValues::STRING_LINKAGE_KEY_LevelStyleExpr)
        .value("eSTRING_LINKAGE_KEY_LevelWeightExpr", LinkageKeyValues::STRING_LINKAGE_KEY_LevelWeightExpr)
        .value("eSTRING_LINKAGE_KEY_ElementColorExpr", LinkageKeyValues::STRING_LINKAGE_KEY_ElementColorExpr)
        .value("eSTRING_LINKAGE_KEY_ElementStyleExpr", LinkageKeyValues::STRING_LINKAGE_KEY_ElementStyleExpr)
        .value("eSTRING_LINKAGE_KEY_ElementWeightExpr", LinkageKeyValues::STRING_LINKAGE_KEY_ElementWeightExpr)
        .value("eSTRING_LINKAGE_KEY_FileExpr", LinkageKeyValues::STRING_LINKAGE_KEY_FileExpr)
        .value("eSTRING_LINKAGE_KEY_MastUnitLabel", LinkageKeyValues::STRING_LINKAGE_KEY_MastUnitLabel)
        .value("eSTRING_LINKAGE_KEY_SubUnitLabel", LinkageKeyValues::STRING_LINKAGE_KEY_SubUnitLabel)
        .value("eSTRING_LINKAGE_KEY_ModelName", LinkageKeyValues::STRING_LINKAGE_KEY_ModelName)
        .value("eSTRING_LINKAGE_KEY_SecondaryMastUnitLabel", LinkageKeyValues::STRING_LINKAGE_KEY_SecondaryMastUnitLabel)
        .value("eSTRING_LINKAGE_KEY_SecondarySubUnitLabel", LinkageKeyValues::STRING_LINKAGE_KEY_SecondarySubUnitLabel)
        .value("eSTRING_LINKAGE_KEY_DimArrowCellName", LinkageKeyValues::STRING_LINKAGE_KEY_DimArrowCellName)
        .value("eSTRING_LINKAGE_KEY_DimStrokeCellName", LinkageKeyValues::STRING_LINKAGE_KEY_DimStrokeCellName)
        .value("eSTRING_LINKAGE_KEY_DimDotCellName", LinkageKeyValues::STRING_LINKAGE_KEY_DimDotCellName)
        .value("eSTRING_LINKAGE_KEY_DimOriginCellName", LinkageKeyValues::STRING_LINKAGE_KEY_DimOriginCellName)
        .value("eSTRING_LINKAGE_KEY_DimPrefixCellName", LinkageKeyValues::STRING_LINKAGE_KEY_DimPrefixCellName)
        .value("eSTRING_LINKAGE_KEY_DimSuffixCellName", LinkageKeyValues::STRING_LINKAGE_KEY_DimSuffixCellName)
        .value("eSTRING_LINKAGE_KEY_NameSpace", LinkageKeyValues::STRING_LINKAGE_KEY_NameSpace)
        .value("eSTRING_LINKAGE_KEY_FullReferencePath", LinkageKeyValues::STRING_LINKAGE_KEY_FullReferencePath)
        .value("eSTRING_LINKAGE_KEY_FilterMember", LinkageKeyValues::STRING_LINKAGE_KEY_FilterMember)
        .value("eSTRING_LINKAGE_KEY_XData", LinkageKeyValues::STRING_LINKAGE_KEY_XData)
        .value("eSTRING_LINKAGE_KEY_ReportName", LinkageKeyValues::STRING_LINKAGE_KEY_ReportName)
        .value("eSTRING_LINKAGE_KEY_RefAlternateFile", LinkageKeyValues::STRING_LINKAGE_KEY_RefAlternateFile)
        .value("eSTRING_LINKAGE_KEY_RefAlternateModel", LinkageKeyValues::STRING_LINKAGE_KEY_RefAlternateModel)
        .value("eSTRING_LINKAGE_KEY_RefAlternateFullPath", LinkageKeyValues::STRING_LINKAGE_KEY_RefAlternateFullPath)
        .value("eSTRING_LINKAGE_KEY_DWGPatternName", LinkageKeyValues::STRING_LINKAGE_KEY_DWGPatternName)
        .value("eSTRING_LINKAGE_KEY_DWGMTextFile", LinkageKeyValues::STRING_LINKAGE_KEY_DWGMTextFile)
        .value("eSTRING_LINKAGE_KEY_DWGDieselTextFile", LinkageKeyValues::STRING_LINKAGE_KEY_DWGDieselTextFile)
        .value("eSTRING_LINKAGE_KEY_AlternateFontName", LinkageKeyValues::STRING_LINKAGE_KEY_AlternateFontName)
        .value("eSTRING_LINKAGE_KEY_DwgBlockName", LinkageKeyValues::STRING_LINKAGE_KEY_DwgBlockName)
        .value("eSTRING_LINKAGE_KEY_NamedGroupName", LinkageKeyValues::STRING_LINKAGE_KEY_NamedGroupName)
        .value("eSTRING_LINKAGE_KEY_NamedGroupDescription", LinkageKeyValues::STRING_LINKAGE_KEY_NamedGroupDescription)
        .value("eSTRING_LINKAGE_KEY_NamedGroupType", LinkageKeyValues::STRING_LINKAGE_KEY_NamedGroupType)
        .value("eSTRING_LINKAGE_KEY_ReferenceNamedGroup", LinkageKeyValues::STRING_LINKAGE_KEY_ReferenceNamedGroup)
        .value("eSTRING_LINKAGE_KEY_DefaultRefLogical", LinkageKeyValues::STRING_LINKAGE_KEY_DefaultRefLogical)
        .value("eSTRING_LINKAGE_KEY_ReferenceRevision", LinkageKeyValues::STRING_LINKAGE_KEY_ReferenceRevision)
        .value("eSTRING_LINKAGE_KEY_DimNoteCellName", LinkageKeyValues::STRING_LINKAGE_KEY_DimNoteCellName)
        .value("eSTRING_LINKAGE_KEY_ClipName", LinkageKeyValues::STRING_LINKAGE_KEY_ClipName)
        .value("eSTRING_LINKAGE_KEY_GeoFeature", LinkageKeyValues::STRING_LINKAGE_KEY_GeoFeature)
        .value("eSTRING_LINKAGE_KEY_GeoPbaName", LinkageKeyValues::STRING_LINKAGE_KEY_GeoPbaName)
        .value("eSTRING_LINKAGE_KEY_SheetFormName", LinkageKeyValues::STRING_LINKAGE_KEY_SheetFormName)
        .value("eSTRING_LINKAGE_KEY_PaperFormName", LinkageKeyValues::STRING_LINKAGE_KEY_PaperFormName)
        .value("eSTRING_LINKAGE_KEY_WindowsPrinterName", LinkageKeyValues::STRING_LINKAGE_KEY_WindowsPrinterName)
        .value("eSTRING_LINKAGE_KEY_PltFileName", LinkageKeyValues::STRING_LINKAGE_KEY_PltFileName)
        .value("eSTRING_LINKAGE_KEY_ColorBook", LinkageKeyValues::STRING_LINKAGE_KEY_ColorBook)
        .value("eSTRING_LINKAGE_KEY_AnimationParameter", LinkageKeyValues::STRING_LINKAGE_KEY_AnimationParameter)
        .value("eSTRING_LINKAGE_KEY_AnimationActionType", LinkageKeyValues::STRING_LINKAGE_KEY_AnimationActionType)
        .value("eSTRING_LINKAGE_KEY_AnimationOriginalActorName", LinkageKeyValues::STRING_LINKAGE_KEY_AnimationOriginalActorName)
        .value("eSTRING_LINKAGE_KEY_SchemaName", LinkageKeyValues::STRING_LINKAGE_KEY_SchemaName)
        .value("eSTRING_LINKAGE_KEY_EndField", LinkageKeyValues::STRING_LINKAGE_KEY_EndField)
        .value("eSTRING_LINKAGE_KEY_PstFileName", LinkageKeyValues::STRING_LINKAGE_KEY_PstFileName)
        .value("eSTRING_LINKAGE_KEY_ReferenceProviderID", LinkageKeyValues::STRING_LINKAGE_KEY_ReferenceProviderID)
        .value("eSTRING_LINKAGE_KEY_IlluminatedMesh", LinkageKeyValues::STRING_LINKAGE_KEY_IlluminatedMesh)
        .value("eSTRING_LINKAGE_KEY_LevelColor", LinkageKeyValues::STRING_LINKAGE_KEY_LevelColor)
        .value("eSTRING_LINKAGE_KEY_LevelElementColor", LinkageKeyValues::STRING_LINKAGE_KEY_LevelElementColor)
        .value("eSTRING_LINKAGE_KEY_LevelStyle", LinkageKeyValues::STRING_LINKAGE_KEY_LevelStyle)
        .value("eSTRING_LINKAGE_KEY_LevelElementStyle", LinkageKeyValues::STRING_LINKAGE_KEY_LevelElementStyle)
        .value("eSTRING_LINKAGE_KEY_LevelMaterial", LinkageKeyValues::STRING_LINKAGE_KEY_LevelMaterial)
        .value("eSTRING_LINKAGE_KEY_LevelElementMaterial", LinkageKeyValues::STRING_LINKAGE_KEY_LevelElementMaterial)
        .value("eSTRING_LINKAGE_KEY_SheetName", LinkageKeyValues::STRING_LINKAGE_KEY_SheetName)
        .value("eSTRING_LINKAGE_KEY_Sheet_UNUSED_74", LinkageKeyValues::STRING_LINKAGE_KEY_Sheet_UNUSED_74)
        .value("eSTRING_LINKAGE_KEY_EcInstance", LinkageKeyValues::STRING_LINKAGE_KEY_EcInstance)
        .value("eSTRING_LINKAGE_KEY_ECOMConnectionLinkage", LinkageKeyValues::STRING_LINKAGE_KEY_ECOMConnectionLinkage)
        .value("eSTRING_LINKAGE_KEY_ComponentSetExpressionSummary", LinkageKeyValues::STRING_LINKAGE_KEY_ComponentSetExpressionSummary)
        .value("eSTRING_LINKAGE_KEY_ECOMConnectionNamedGroupLinkage", LinkageKeyValues::STRING_LINKAGE_KEY_ECOMConnectionNamedGroupLinkage)
        .value("eSTRING_LINKAGE_KEY_ComponentSetExpression", LinkageKeyValues::STRING_LINKAGE_KEY_ComponentSetExpression)
        .value("eSTRING_LINKAGE_KEY_SchemaVersion", LinkageKeyValues::STRING_LINKAGE_KEY_SchemaVersion)
        .value("eSTRING_LINKAGE_KEY_CommonGeometryType", LinkageKeyValues::STRING_LINKAGE_KEY_CommonGeometryType)
        .value("eSTRING_LINKAGE_KEY_CommonGeometryOperation", LinkageKeyValues::STRING_LINKAGE_KEY_CommonGeometryOperation)
        .value("eSTRING_LINKAGE_KEY_PrintStyleName", LinkageKeyValues::STRING_LINKAGE_KEY_PrintStyleName)
        .value("eSTRING_LINKAGE_KEY_SchemaProviderName", LinkageKeyValues::STRING_LINKAGE_KEY_SchemaProviderName)
        .value("eSTRING_LINKAGE_KEY_DwgEntityPropertyList", LinkageKeyValues::STRING_LINKAGE_KEY_DwgEntityPropertyList)
        .value("eSTRING_LINKAGE_KEY_EmbeddedReference", LinkageKeyValues::STRING_LINKAGE_KEY_EmbeddedReference)
        .value("eSTRING_LINKAGE_KEY_ReferenceSymbologyTemplate", LinkageKeyValues::STRING_LINKAGE_KEY_ReferenceSymbologyTemplate)
        .value("eSTRING_LINKAGE_KEY_SheetIndexDefaultProperties", LinkageKeyValues::STRING_LINKAGE_KEY_SheetIndexDefaultProperties)
        .value("eSTRING_LINKAGE_KEY_BackgroundMapJson", LinkageKeyValues::STRING_LINKAGE_KEY_BackgroundMapJson)
        .value("eSTRING_LINKAGE_KEY_NamedPresentationCondition", LinkageKeyValues::STRING_LINKAGE_KEY_NamedPresentationCondition)
        .value("eSTRING_LINKAGE_KEY_TPFFileName", LinkageKeyValues::STRING_LINKAGE_KEY_TPFFileName)
        .value("eSTRING_LINKAGE_KEY_ItemType", LinkageKeyValues::STRING_LINKAGE_KEY_ItemType)
        .value("eDOUBLEARRAY_LINKAGE_KEY_Generic", LinkageKeyValues::DOUBLEARRAY_LINKAGE_KEY_Generic)
        .value("eDOUBLEARRAY_LINKAGE_KEY_Fence", LinkageKeyValues::DOUBLEARRAY_LINKAGE_KEY_Fence)
        .value("eDOUBLEARRAY_LINKAGE_KEY_ClippingRct", LinkageKeyValues::DOUBLEARRAY_LINKAGE_KEY_ClippingRct)
        .value("eDOUBLEARRAY_LINKAGE_KEY_ClippingMsk", LinkageKeyValues::DOUBLEARRAY_LINKAGE_KEY_ClippingMsk)
        .value("eDOUBLEARRAY_LINKAGE_KEY_ClippingRotation", LinkageKeyValues::DOUBLEARRAY_LINKAGE_KEY_ClippingRotation)
        .value("eDOUBLEARRAY_LINKAGE_KEY_WorldToViewXForm", LinkageKeyValues::DOUBLEARRAY_LINKAGE_KEY_WorldToViewXForm)
        .value("eDOUBLEARRAY_LINKAGE_KEY_ViewToWorldXForm", LinkageKeyValues::DOUBLEARRAY_LINKAGE_KEY_ViewToWorldXForm)
        .value("eDOUBLEARRAY_LINKAGE_KEY_FlattenTransform", LinkageKeyValues::DOUBLEARRAY_LINKAGE_KEY_FlattenTransform)
        .value("eDOUBLEARRAY_LINKAGE_KEY_DwgTransform", LinkageKeyValues::DOUBLEARRAY_LINKAGE_KEY_DwgTransform)
        .value("eDOUBLEARRAY_LINKAGE_KEY_RefColorAdjustment", LinkageKeyValues::DOUBLEARRAY_LINKAGE_KEY_RefColorAdjustment)
        .value("eDOUBLEARRAY_LINKAGE_KEY_HLinePathInfo", LinkageKeyValues::DOUBLEARRAY_LINKAGE_KEY_HLinePathInfo)
        .value("eDOUBLEARRAY_LINKAGE_KEY_RefColorAdvancedAdjustment", LinkageKeyValues::DOUBLEARRAY_LINKAGE_KEY_RefColorAdvancedAdjustment)
        .value("eDOUBLEARRAY_LINKAGE_KEY_RegionTextMarginFactor", LinkageKeyValues::DOUBLEARRAY_LINKAGE_KEY_RegionTextMarginFactor)
        .value("eDOUBLEARRAY_LINKAGE_KEY_AuxCoordScale", LinkageKeyValues::DOUBLEARRAY_LINKAGE_KEY_AuxCoordScale)
        .value("eDOUBLEARRAY_LINKAGE_KEY_RefTransparency", LinkageKeyValues::DOUBLEARRAY_LINKAGE_KEY_RefTransparency)
        .value("eDOUBLEARRAY_LINKAGE_KEY_Transform", LinkageKeyValues::DOUBLEARRAY_LINKAGE_KEY_Transform)
        .value("eDOUBLEARRAY_LINKAGE_KEY_PlacemarkMonument", LinkageKeyValues::DOUBLEARRAY_LINKAGE_KEY_PlacemarkMonument)
        .value("eDOUBLEARRAY_LINKAGE_KEY_AnnotationScale", LinkageKeyValues::DOUBLEARRAY_LINKAGE_KEY_AnnotationScale)
        .value("eDOUBLEARRAY_LINKAGE_KEY_ClippingDepth", LinkageKeyValues::DOUBLEARRAY_LINKAGE_KEY_ClippingDepth)
        .value("eDOUBLEARRAY_LINKAGE_KEY_RefAdditionalFlags", LinkageKeyValues::DOUBLEARRAY_LINKAGE_KEY_RefAdditionalFlags)
        .value("eDOUBLEARRAY_LINKAGE_KEY_OriginRelativeOffset", LinkageKeyValues::DOUBLEARRAY_LINKAGE_KEY_OriginRelativeOffset)
        .value("eBYTEARRAY_LINKAGE_KEY_FontNameCP", LinkageKeyValues::BYTEARRAY_LINKAGE_KEY_FontNameCP)
        .value("eBYTEARRAY_LINKAGE_KEY_AlternateFontNameCP", LinkageKeyValues::BYTEARRAY_LINKAGE_KEY_AlternateFontNameCP)
        .value("eBYTEARRAY_LINKAGE_KEY_HLineTiling", LinkageKeyValues::BYTEARRAY_LINKAGE_KEY_HLineTiling)
        .value("eBYTEARRAY_LINKAGE_KEY_SectionEdgeId", LinkageKeyValues::BYTEARRAY_LINKAGE_KEY_SectionEdgeId)
        .value("eBYTEARRAY_LINKAGE_KEY_VectorIconModel", LinkageKeyValues::BYTEARRAY_LINKAGE_KEY_VectorIconModel)
        .value("eBYTEARRAY_LINKAGE_KEY_AuxCoordGrid", LinkageKeyValues::BYTEARRAY_LINKAGE_KEY_AuxCoordGrid)
        .value("eBITMASK_LINKAGE_KEY_Generic", LinkageKeyValues::BITMASK_LINKAGE_KEY_Generic)
        .value("eBITMASK_LINKAGE_KEY__________Unused", LinkageKeyValues::BITMASK_LINKAGE_KEY__________Unused)
        .value("eBITMASK_LINKAGE_KEY_Level", LinkageKeyValues::BITMASK_LINKAGE_KEY_Level)
        .value("eBITMASK_LINKAGE_KEY_HiddenLineFlags", LinkageKeyValues::BITMASK_LINKAGE_KEY_HiddenLineFlags)
        .value("eBITMASK_LINKAGE_KEY_LibraryRefs", LinkageKeyValues::BITMASK_LINKAGE_KEY_LibraryRefs)
        .value("eBITMASK_LINKAGE_KEY_TextWhiteSpace", LinkageKeyValues::BITMASK_LINKAGE_KEY_TextWhiteSpace)
        .value("eBITMASK_LINKAGE_KEY_RasterOverrideFlags", LinkageKeyValues::BITMASK_LINKAGE_KEY_RasterOverrideFlags)
        .value("eBITMASK_LINKAGE_KEY_MlineOverrideFlags", LinkageKeyValues::BITMASK_LINKAGE_KEY_MlineOverrideFlags)
        .value("eBITMASK_LINKAGE_KEY_LevelAttributes", LinkageKeyValues::BITMASK_LINKAGE_KEY_LevelAttributes)
        .value("eBITMASK_LINKAGE_KEY_DimShieldsBase", LinkageKeyValues::BITMASK_LINKAGE_KEY_DimShieldsBase)
        .value("eBITMASK_LINKAGE_KEY_DimBallAndChainShields", LinkageKeyValues::BITMASK_LINKAGE_KEY_DimBallAndChainShields)
        .value("eBITMASK_LINKAGE_KEY_DimExtensionLineShields", LinkageKeyValues::BITMASK_LINKAGE_KEY_DimExtensionLineShields)
        .value("eBITMASK_LINKAGE_KEY_DimGeneralShields", LinkageKeyValues::BITMASK_LINKAGE_KEY_DimGeneralShields)
        .value("eBITMASK_LINKAGE_KEY_DimMuliLineShields", LinkageKeyValues::BITMASK_LINKAGE_KEY_DimMuliLineShields)
        .value("eBITMASK_LINKAGE_KEY_DimPlacementShields", LinkageKeyValues::BITMASK_LINKAGE_KEY_DimPlacementShields)
        .value("eBITMASK_LINKAGE_KEY_DimSymbolShields", LinkageKeyValues::BITMASK_LINKAGE_KEY_DimSymbolShields)
        .value("eBITMASK_LINKAGE_KEY_DimTerminatorShields", LinkageKeyValues::BITMASK_LINKAGE_KEY_DimTerminatorShields)
        .value("eBITMASK_LINKAGE_KEY_DimTextShields", LinkageKeyValues::BITMASK_LINKAGE_KEY_DimTextShields)
        .value("eBITMASK_LINKAGE_KEY_DimToleranceShields", LinkageKeyValues::BITMASK_LINKAGE_KEY_DimToleranceShields)
        .value("eBITMASK_LINKAGE_KEY_DimValueShields", LinkageKeyValues::BITMASK_LINKAGE_KEY_DimValueShields)
        .value("eBITMASK_LINKAGE_KEY_DimTemplate0Shields", LinkageKeyValues::BITMASK_LINKAGE_KEY_DimTemplate0Shields)
        .value("eBITMASK_LINKAGE_KEY_DimTemplate1Shields", LinkageKeyValues::BITMASK_LINKAGE_KEY_DimTemplate1Shields)
        .value("eBITMASK_LINKAGE_KEY_DimTemplate2Shields", LinkageKeyValues::BITMASK_LINKAGE_KEY_DimTemplate2Shields)
        .value("eBITMASK_LINKAGE_KEY_DimTemplate3Shields", LinkageKeyValues::BITMASK_LINKAGE_KEY_DimTemplate3Shields)
        .value("eBITMASK_LINKAGE_KEY_DimTemplate4Shields", LinkageKeyValues::BITMASK_LINKAGE_KEY_DimTemplate4Shields)
        .value("eBITMASK_LINKAGE_KEY_DimTemplate5Shields", LinkageKeyValues::BITMASK_LINKAGE_KEY_DimTemplate5Shields)
        .value("eBITMASK_LINKAGE_KEY_DimTemplate6Shields", LinkageKeyValues::BITMASK_LINKAGE_KEY_DimTemplate6Shields)
        .value("eBITMASK_LINKAGE_KEY_DimTemplate7Shields", LinkageKeyValues::BITMASK_LINKAGE_KEY_DimTemplate7Shields)
        .value("eBITMASK_LINKAGE_KEY_DimTemplate8Shields", LinkageKeyValues::BITMASK_LINKAGE_KEY_DimTemplate8Shields)
        .value("eBITMASK_LINKAGE_KEY_DimTemplate9Shields", LinkageKeyValues::BITMASK_LINKAGE_KEY_DimTemplate9Shields)
        .value("eBITMASK_LINKAGE_KEY_DimTemplate10Shields",LinkageKeyValues::BITMASK_LINKAGE_KEY_DimTemplate10Shields)
        .value("eBITMASK_LINKAGE_KEY_DimTemplate11Shields",LinkageKeyValues::BITMASK_LINKAGE_KEY_DimTemplate11Shields)
        .value("eBITMASK_LINKAGE_KEY_DimTemplate12Shields",LinkageKeyValues::BITMASK_LINKAGE_KEY_DimTemplate12Shields)
        .value("eBITMASK_LINKAGE_KEY_DimTemplate13Shields",LinkageKeyValues::BITMASK_LINKAGE_KEY_DimTemplate13Shields)
        .value("eBITMASK_LINKAGE_KEY_DimTemplate14Shields",LinkageKeyValues::BITMASK_LINKAGE_KEY_DimTemplate14Shields)
        .value("eBITMASK_LINKAGE_KEY_DimTemplate15Shields",LinkageKeyValues::BITMASK_LINKAGE_KEY_DimTemplate15Shields)
        .value("eBITMASK_LINKAGE_KEY_DimTemplate16Shields",LinkageKeyValues::BITMASK_LINKAGE_KEY_DimTemplate16Shields)
        .value("eBITMASK_LINKAGE_KEY_DimTemplate17Shields",LinkageKeyValues::BITMASK_LINKAGE_KEY_DimTemplate17Shields)
        .value("eBITMASK_LINKAGE_KEY_DimTemplate18Shields",LinkageKeyValues::BITMASK_LINKAGE_KEY_DimTemplate18Shields)
        .value("eBITMASK_LINKAGE_KEY_DimTemplate19Shields",LinkageKeyValues::BITMASK_LINKAGE_KEY_DimTemplate19Shields)
        .value("eBITMASK_LINKAGE_KEY_DimTemplate20Shields",LinkageKeyValues::BITMASK_LINKAGE_KEY_DimTemplate20Shields)
        .value("eBITMASK_LINKAGE_KEY_DimTemplate21Shields",LinkageKeyValues::BITMASK_LINKAGE_KEY_DimTemplate21Shields)
        .value("eBITMASK_LINKAGE_KEY_DimTemplate22Shields",LinkageKeyValues::BITMASK_LINKAGE_KEY_DimTemplate22Shields)
        .value("eBITMASK_LINKAGE_KEY_DimTemplate23Shields",LinkageKeyValues::BITMASK_LINKAGE_KEY_DimTemplate23Shields)
        .value("eMULTISTATEMASK_LINKAGE_KEY_NamedLevelMask", LinkageKeyValues::MULTISTATEMASK_LINKAGE_KEY_NamedLevelMask)
        .value("eSYMBOLOGY_LINKAGE_KEY_RefBound", LinkageKeyValues::SYMBOLOGY_LINKAGE_KEY_RefBound)
        .value("eSYMBOLOGY_LINKAGE_KEY_HLineVisible", LinkageKeyValues::SYMBOLOGY_LINKAGE_KEY_HLineVisible)
        .value("eSYMBOLOGY_LINKAGE_KEY_HLineHidden", LinkageKeyValues::SYMBOLOGY_LINKAGE_KEY_HLineHidden)
        .value("eSYMBOLOGY_LINKAGE_KEY_HLineSmooth", LinkageKeyValues::SYMBOLOGY_LINKAGE_KEY_HLineSmooth)
        .value("eELEMENTID_LINKAGE_KEY_Generic", LinkageKeyValues::ELEMENTID_LINKAGE_KEY_Generic)
        .value("eELEMENTID_LINKAGE_KEY_NestedAttachmentLevelTable", LinkageKeyValues::ELEMENTID_LINKAGE_KEY_NestedAttachmentLevelTable)
        .value("eELEMENTID_LINKAGE_KEY_glyphId", LinkageKeyValues::ELEMENTID_LINKAGE_KEY_glyphId)
        .value("eELEMENTID_LINKAGE_KEY_LevelMaskAttachmentId", LinkageKeyValues::ELEMENTID_LINKAGE_KEY_LevelMaskAttachmentId)
        .value("eMODELID_LINKAGE_KEY_ReferenceAttachment", LinkageKeyValues::MODELID_LINKAGE_KEY_ReferenceAttachment)
        .export_values();

    //===================================================================================
    // enum class ElementChangeType
    py::enum_< DgnHistory::ElementChangeType>(m, "ElementChangeType")
        .value("eMissing", DgnHistory::ElementChangeType::Missing)
        .value("eAdded", DgnHistory::ElementChangeType::Added)
        .value("eDeleted", DgnHistory::ElementChangeType::Deleted)
        .value("eReplaced", DgnHistory::ElementChangeType::Replaced)
        .export_values();

    //===================================================================================
    // enum class EvaluationReason
    py::enum_< EvaluationReason>(m, "EvaluationReason")
        .value("eNil", EvaluationReason::None)
        .value("eEditor", EvaluationReason::Editor)
        .value("eUpdate", EvaluationReason::Update)
        .value("ePlot", EvaluationReason::Plot)
        .value("eModelLoad", EvaluationReason::ModelLoad)
        .value("eModelSave", EvaluationReason::ModelSave)
        .value("eDesignHistory_", EvaluationReason::DesignHistory)
        .value("eUnconditional", EvaluationReason::Unconditional)
        .export_values();

    //===================================================================================
    // enum class ConfigurationVariableLevel
    py::enum_< ConfigurationVariableLevel>(m, "ConfigurationVariableLevel")
        .value("ePredefined", ConfigurationVariableLevel::Predefined)
        .value("eSysEnv", ConfigurationVariableLevel::SysEnv)
        .value("eSystem", ConfigurationVariableLevel::System)
        .value("eApplication", ConfigurationVariableLevel::Application)
        .value("eOrganization", ConfigurationVariableLevel::Organization)
        .value("eWorkSpace", ConfigurationVariableLevel::WorkSpace)
        .value("eWorkSet", ConfigurationVariableLevel::WorkSet)
        .value("eRole", ConfigurationVariableLevel::Role)
        .value("eUser", ConfigurationVariableLevel::User)
        .export_values();

    //===================================================================================
    // enum class ChangeTrackAction
    py::enum_< ChangeTrackAction>(m, "ChangeTrackAction")
        .value("eDelete", ChangeTrackAction::Delete)
        .value("eAdd", ChangeTrackAction::Add)
        .value("eModify", ChangeTrackAction::Modify)
        .value("eAddComplete", ChangeTrackAction::AddComplete)
        .value("eModifyFence", ChangeTrackAction::ModifyFence)
        .value("eMark", ChangeTrackAction::Mark)
        .value("eModelAdd", ChangeTrackAction::ModelAdd)
        .value("eModelDelete", ChangeTrackAction::ModelDelete)
        .value("eXAttributeAdd", ChangeTrackAction::XAttributeAdd)
        .value("eXAttributeDelete", ChangeTrackAction::XAttributeDelete)
        .value("eXAttributeModify", ChangeTrackAction::XAttributeModify)
        .value("eXAttributeReplace", ChangeTrackAction::XAttributeReplace)
        .value("eModelPropModify", ChangeTrackAction::ModelPropModify)
        .value("eCustomEntry", ChangeTrackAction::CustomEntry)
        .value("eModifyComplete", ChangeTrackAction::ModifyComplete)
        .export_values();

    //===================================================================================
    // enum class ChangeTrackSource
    py::enum_< ChangeTrackSource>(m, "ChangeTrackSource")
        .value("eUndoRedo", ChangeTrackSource::UndoRedo)
        .value("eHistoryRestore", ChangeTrackSource::HistoryRestore)
        .value("eHistoryMerge", ChangeTrackSource::HistoryMerge)
        .export_values();

    //===================================================================================
    // enum class DependencyStatus
    py::enum_< DependencyStatus>(m, "DependencyStatus")
        .value("eSuccess", DependencyStatus::Success)
        .value("eCallbackError", DependencyStatus::CallbackError)
        .value("eMaxIterationsError", DependencyStatus::MaxIterationsError)
        .value("eMissingCallBackError", DependencyStatus::MissingCallBackError)
        .value("eRefToTentativeError", DependencyStatus::RefToTentativeError)
        .value("eDisabledError", DependencyStatus::DisabledError)
        .value("eSuspendedError", DependencyStatus::SuspendedError)
        .value("eRecursiveError", DependencyStatus::RecursiveError)
        .export_values();

    //===================================================================================
    // enum class DependencyGraphEvaluationStatus
    py::enum_< DependencyGraphEvaluationStatus>(m, "DependencyGraphEvaluationStatus")
        .value("eSuccess", DependencyGraphEvaluationStatus::Success)
        .value("eRedundantFailure", DependencyGraphEvaluationStatus::RedundantFailure)
        .value("eBadConstraintFailure", DependencyGraphEvaluationStatus::BadConstraintFailure)
        .value("eWeakConstraintsRejectedSuccess", DependencyGraphEvaluationStatus::WeakConstraintsRejectedSuccess)
        .export_values();

    //===================================================================================
    // enum class DgnCoordSystem
    py::enum_< DgnCoordSystem>(m, "DgnCoordSystem")
        .value("eScreen", DgnCoordSystem::Screen)
        .value("eView", DgnCoordSystem::View)
        .value("eNpc", DgnCoordSystem::Npc)
        .value("eRoot", DgnCoordSystem::Root)
        .value("eActive", DgnCoordSystem::Active)
        .value("eFrustum", DgnCoordSystem::Frustum)
        .export_values();

    //===================================================================================
    // enum class GradientFlags
    py::enum_< GradientFlags>(m, "GradientFlags")
        .value("eInvert", GradientFlags::Invert)
        .value("eOutline", GradientFlags::Outline)
        .value("eAlwaysFilled", GradientFlags::AlwaysFilled)
        .export_values();

    //===================================================================================
    // enum class ClipMask
    py::enum_< ClipMask>(m, "ClipMask")
        .value("eNil", ClipMask::None)
        .value("eXLow", ClipMask::XLow)
        .value("eXHigh", ClipMask::XHigh)
        .value("eYLow", ClipMask::YLow)
        .value("eYHigh", ClipMask::YHigh)
        .value("eZLow", ClipMask::ZLow)
        .value("eZHigh", ClipMask::ZHigh)
        .value("eXAndY", ClipMask::XAndY)
        .value("eAll", ClipMask::All)
        .export_values();

    //===================================================================================
    // enum class BackgroundMapType
    py::enum_< BackgroundMapType>(m, "BackgroundMapType")
        .value("eNil", BackgroundMapType::None)
        .value("eRoad", BackgroundMapType::Road)
        .value("eAerial", BackgroundMapType::Aerial)
        .value("eHybrid", BackgroundMapType::Hybrid)
        .export_values();

    //===================================================================================
    m.attr("COLOR_BYLEVEL") = (int)COLOR_BYLEVEL;
    m.attr("COLOR_BYCELL") = (int)COLOR_BYCELL;
    m.attr("STYLE_BYLEVEL") = (int)STYLE_BYLEVEL;
    m.attr("STYLE_BYCELL") = (int)STYLE_BYCELL;
    m.attr("WEIGHT_BYLEVEL") = (int)WEIGHT_BYLEVEL;
    m.attr("WEIGHT_BYCELL") = (int)WEIGHT_BYCELL;
    m.attr("LEVEL_BYCELL") = (int)LEVEL_BYCELL;

    //===================================================================================
    // enum ViewLevelDisplayType
    py::enum_< ViewLevelDisplayType>(m, "ViewLevelDisplayType")
        .value("eNormal", ViewLevelDisplayType::Normal)
        .value("eEffective", ViewLevelDisplayType::Effective)
        .export_values();

    //===================================================================================
    // enum SnapStatus
    py::enum_< SnapStatus>(m, "SnapStatus")
        .value("eSuccess", SnapStatus::Success)
        .value("eAborted", SnapStatus::Aborted)
        .value("eNoElements", SnapStatus::NoElements)
        .value("eDisabled", SnapStatus::Disabled)
        .value("eNoSnapPossible", SnapStatus::NoSnapPossible)
        .value("eNotSnappable", SnapStatus::NotSnappable)
        .value("eRefNotSnappable", SnapStatus::RefNotSnappable)
        .value("eFilteredByLevel", SnapStatus::FilteredByLevel)
        .value("eFilteredByUser", SnapStatus::FilteredByUser)
        .value("eFilteredByApp", SnapStatus::FilteredByApp)
        .value("eFilteredByAppQuietly", SnapStatus::FilteredByAppQuietly)
        .export_values();

    //===================================================================================
    // enum OutputMessagePriority
    py::enum_< OutputMessagePriority>(m, "OutputMessagePriority")
        .value("eNil", OutputMessagePriority::None)
        .value("eError", OutputMessagePriority::Error)
        .value("eWarning", OutputMessagePriority::Warning)
        .value("eInfo", OutputMessagePriority::Info)
        .value("eDebug", OutputMessagePriority::Debug)
        .value("eOldStyle", OutputMessagePriority::OldStyle)
        .value("eTempRight", OutputMessagePriority::TempRight)
        .value("eTempLeft", OutputMessagePriority::TempLeft)
        .value("eFatal", OutputMessagePriority::Fatal)
        .export_values();

    //===================================================================================
    // enum OutputMessageAlert
    py::enum_< OutputMessageAlert>(m, "OutputMessageAlert")
        .value("eNil", OutputMessageAlert::None)
        .value("eDialog", OutputMessageAlert::Dialog)
        .value("eBalloon", OutputMessageAlert::Balloon)
        .export_values();

    //===================================================================================
    // enum FileOpenConstants
    py::enum_< FileOpenConstants>(m, "FileOpenConstants", py::arithmetic())
        .value("eOPEN_FOR_WRITE", FileOpenConstants::OPEN_FOR_WRITE)
        .value("eOPEN_FOR_READ", FileOpenConstants::OPEN_FOR_READ)
        .value("eUF_WTR_SUCCESS", FileOpenConstants::UF_WTR_SUCCESS)
        .value("eUF_OPEN_READ", FileOpenConstants::UF_OPEN_READ)
        .value("eUF_OPEN_WRITE", FileOpenConstants::UF_OPEN_WRITE)
        .value("eUF_OPEN_CREATE", FileOpenConstants::UF_OPEN_CREATE)
        .value("eUF_TRY_WRITE_THEN_READ", FileOpenConstants::UF_TRY_WRITE_THEN_READ)
        .value("eUF_CUR_DIR_SWAP", FileOpenConstants::UF_CUR_DIR_SWAP)
        .value("eUF_NO_CUR_DIR", FileOpenConstants::UF_NO_CUR_DIR)
        .value("eUF_JUST_BUILD", FileOpenConstants::UF_JUST_BUILD)
        .value("eUF_FIND_FOLDER", FileOpenConstants::UF_FIND_FOLDER)
        .export_values();

    //===================================================================================
    // enum TransformOptionValues
    py::enum_< TransformOptionValues>(m, "TransformOptionValues", py::arithmetic())
        .value("eTRANSFORM_OPTIONS_ModelFromElmdscr", TransformOptionValues::TRANSFORM_OPTIONS_ModelFromElmdscr)
        .value("eTRANSFORM_OPTIONS_DimValueMatchSource", TransformOptionValues::TRANSFORM_OPTIONS_DimValueMatchSource)
        .value("eTRANSFORM_OPTIONS_DimSizeMatchSource", TransformOptionValues::TRANSFORM_OPTIONS_DimSizeMatchSource)
        .value("eTRANSFORM_OPTIONS_MlineScaleOffsets", TransformOptionValues::TRANSFORM_OPTIONS_MlineScaleOffsets)
        .value("eTRANSFORM_OPTIONS_MlineMirrorOffsets", TransformOptionValues::TRANSFORM_OPTIONS_MlineMirrorOffsets)
        .value("eTRANSFORM_OPTIONS_DisableMirrorCharacters", TransformOptionValues::TRANSFORM_OPTIONS_DisableMirrorCharacters)
        .value("eTRANSFORM_OPTIONS_AnnotationSizeMatchSource", TransformOptionValues::TRANSFORM_OPTIONS_AnnotationSizeMatchSource)
        .value("eTRANSFORM_OPTIONS_RotateDimView", TransformOptionValues::TRANSFORM_OPTIONS_RotateDimView)
        .value("eTRANSFORM_OPTIONS_ApplyAnnotationScale", TransformOptionValues::TRANSFORM_OPTIONS_ApplyAnnotationScale)
        .value("eTRANSFORM_OPTIONS_FromClone", TransformOptionValues::TRANSFORM_OPTIONS_FromClone)
        .value("eTRANSFORM_OPTIONS_NoteScaleSize", TransformOptionValues::TRANSFORM_OPTIONS_NoteScaleSize)
        .value("eTRANSFORM_OPTIONS_DisableRotateCharacters", TransformOptionValues::TRANSFORM_OPTIONS_DisableRotateCharacters)
        .export_values();

    //===================================================================================
    // enum GridOrientationType
    py::enum_< GridOrientationType>(m, "GridOrientationType")
        .value("eView", GridOrientationType::View)
        .value("eWorldXY", GridOrientationType::WorldXY)
        .value("eWorldYZ", GridOrientationType::WorldYZ)
        .value("eWorldXZ", GridOrientationType::WorldXZ)
        .value("eACS", GridOrientationType::ACS)
        .export_values();

    //===================================================================================
    m.attr("ANGLE_PRECISION_Active") = (int)ANGLE_PRECISION_Active;
    m.attr("ANGLE_MODE_Active") = (int)ANGLE_MODE_Active;
    m.attr("ANGLE_MODE_Standard") = (int)ANGLE_MODE_Standard;
    m.attr("ANGLE_MODE_Azimuth") = (int)ANGLE_MODE_Azimuth;
    m.attr("ANGLE_MODE_Bearing") = (int)ANGLE_MODE_Bearing;

    //===================================================================================
    // enum DisplayPathType
    py::enum_< DisplayPathType>(m, "DisplayPathType")
        .value("eDisplay", DisplayPathType::Display)
        .value("eSelection", DisplayPathType::Selection)
        .value("eHit", DisplayPathType::Hit)
        .value("eSnap", DisplayPathType::Snap)
        .value("eIntersection", DisplayPathType::Intersection)
        .export_values();

    //===================================================================================
    // enum DitherModes
    py::enum_< DitherModes>(m, "DitherModes", py::arithmetic())
        .value("eDITHERMODE_Pattern", DitherModes::DITHERMODE_Pattern)
        .value("eDITHERMODE_ErrorDiffusion", DitherModes::DITHERMODE_ErrorDiffusion)
        .export_values();

    //===================================================================================
    // enum DgnAttachmentAttachedReason
    py::enum_< DgnAttachmentAttachedReason>(m, "DgnAttachmentAttachedReason")
        .value("eNewAttachment", DgnAttachmentAttachedReason::NewAttachment)
        .value("eReattached", DgnAttachmentAttachedReason::Reattached)
        .value("eUndoneDetach", DgnAttachmentAttachedReason::UndoneDetach)
        .value("eRedoneAttach", DgnAttachmentAttachedReason::RedoneAttach)
        .value("eReloaded", DgnAttachmentAttachedReason::Reloaded)
        .value("eReattachUndoRedo", DgnAttachmentAttachedReason::ReattachUndoRedo)
        .value("eChildrenReloaded", DgnAttachmentAttachedReason::ChildrenReloaded)
        .value("eNewNonActiveModel", DgnAttachmentAttachedReason::NewNonActiveModel)
        .export_values();

    //===================================================================================
    // enum DgnAttachmentDetachedReason
    py::enum_< DgnAttachmentDetachedReason>(m, "DgnAttachmentDetachedReason")
        .value("eDetached", DgnAttachmentDetachedReason::Detached)
        .value("eUndoneAttach", DgnAttachmentDetachedReason::UndoneAttach)
        .value("eRedoneDetach", DgnAttachmentDetachedReason::RedoneDetach)
        .value("eReattached", DgnAttachmentDetachedReason::Reattached)
        .value("eModelDeleted", DgnAttachmentDetachedReason::ModelDeleted)
        .value("eReloaded", DgnAttachmentDetachedReason::Reloaded)
        .value("eMergedIntoMaster", DgnAttachmentDetachedReason::MergedIntoMaster)
        .export_values();

    //===================================================================================
    // enum AnnotationScaleAction
    py::enum_< AnnotationScaleAction>(m, "AnnotationScaleAction")
        .value("eUpdate", AnnotationScaleAction::Update)
        .value("eAdd", AnnotationScaleAction::Add)
        .value("eRemove", AnnotationScaleAction::Remove)
        .export_values();

    //===================================================================================
    // enum FenceStretchFlags
    py::enum_< FenceStretchFlags>(m, "FenceStretchFlags")
        .value("eNil", FenceStretchFlags::None)
        .value("eCells", FenceStretchFlags::Cells)
        .export_values();

    //===================================================================================
    // enum FenceClipFlags
    py::enum_< FenceClipFlags>(m, "FenceClipFlags")
        .value("eNil", FenceClipFlags::None)
        .value("eOptimized", FenceClipFlags::Optimized)
        .export_values();

    //===================================================================================
    // enum ClipVolumePass
    py::enum_< ClipVolumePass>(m, "ClipVolumePass")
        .value("eNil", ClipVolumePass::None)
        .value("eInsideForward", ClipVolumePass::InsideForward)
        .value("eInsideBackward", ClipVolumePass::InsideBackward)
        .value("eOutside", ClipVolumePass::Outside)
        .value("eInside", ClipVolumePass::Inside)
        .value("eCut", ClipVolumePass::Cut)
        .export_values();        

    //===================================================================================
    // enum AgendaEvent
    py::enum_< AgendaEvent>(m, "AgendaEvent")
        .value("eModifyEntries", AgendaEvent::ModifyEntries)
        .value("ePreModify", AgendaEvent::PreModify)
        .value("ePostModify", AgendaEvent::PostModify)
        .value("eAddClipboardFormats", AgendaEvent::AddClipboardFormats)
        .value("eRedraw", AgendaEvent::Redraw)
        .value("ePreCopy", AgendaEvent::PreCopy)
        .export_values();

    //===================================================================================
    // enum AgendaModify
    py::enum_< AgendaModify>(m, "AgendaModify")
        .value("eOriginal", AgendaModify::Original)
        .value("eCopy", AgendaModify::Copy)
        .value("eClipOriginal", AgendaModify::ClipOriginal)
        .value("eClipCopy", AgendaModify::ClipCopy)
        .export_values();

    //===================================================================================
    // enum AgendaOperation
    py::enum_< AgendaOperation>(m, "AgendaOperation")
        .value("eNotSpecified", AgendaOperation::NotSpecified)
        .value("eTranslate", AgendaOperation::Translate)
        .value("eScale", AgendaOperation::Scale)
        .value("eRotate", AgendaOperation::Rotate)
        .value("eMirror", AgendaOperation::Mirror)
        .value("eArray", AgendaOperation::Array)
        .value("eStretch", AgendaOperation::Stretch)
        .value("eDelete", AgendaOperation::Delete)
        .value("eClipboard", AgendaOperation::Clipboard)
        .value("eDragDrop", AgendaOperation::DragDrop)
        .value("eChangeAttrib", AgendaOperation::ChangeAttrib)
        .value("eFileFence", AgendaOperation::FileFence)
        .value("eDrop", AgendaOperation::Drop)
        .export_values();
        
    //===================================================================================
    // struct RgbColorShort
    py::class_< RgbColorShort>(m, "RgbColorShort")
        .def_readwrite("red", &RgbColorShort::red)
        .def_readwrite("green", &RgbColorShort::green)
        .def_readwrite("blue", &RgbColorShort::blue);

    //===================================================================================
    // struct HsvColorDef
    py::class_< HsvColorDef>(m, "HsvColorDef")
        .def_readwrite("hue", &HsvColorDef::hue)
        .def_readwrite("saturation", &HsvColorDef::saturation)
        .def_readwrite("value", &HsvColorDef::value);

    //===================================================================================
    // struct FColor3
    py::class_< FColor3>(m, "FColor3")
        .def_readwrite("r", &FColor3::r)
        .def_readwrite("g", &FColor3::g)
        .def_readwrite("b", &FColor3::b);

    //===================================================================================
    // struct FColor4
    py::class_< FColor4>(m, "FColor4")
        .def_readwrite("r", &FColor4::r)
        .def_readwrite("g", &FColor4::g)
        .def_readwrite("b", &FColor4::b)
        .def_readwrite("a", &FColor4::a);

    //===================================================================================
    // struct FTexture2
    py::class_< FTexture2>(m, "FTexture2")
        .def_readwrite("u", &FTexture2::u)
        .def_readwrite("v", &FTexture2::v);

    //===================================================================================
    // struct FTexture3
    py::class_< FTexture3>(m, "FTexture3")
        .def_readwrite("u", &FTexture3::u)
        .def_readwrite("v", &FTexture3::v)
        .def_readwrite("w", &FTexture3::w);

    //===================================================================================
    // enum DgnDrawMode
    py::enum_< DgnDrawMode>(m, "DgnDrawMode", py::arithmetic())
        .value("eDRAW_MODE_Normal", DgnDrawMode::DRAW_MODE_Normal)
        .value("eDRAW_MODE_Erase", DgnDrawMode::DRAW_MODE_Erase)
        .value("eDRAW_MODE_Hilite", DgnDrawMode::DRAW_MODE_Hilite)
        .value("eDRAW_MODE_TempDraw", DgnDrawMode::DRAW_MODE_TempDraw)
        .value("eDRAW_MODE_Flash", DgnDrawMode::DRAW_MODE_Flash)
        .export_values();

    //===================================================================================
    // enum DrawPurpose
    py::enum_< DrawPurpose>(m, "DrawPurpose")
        .value("eNotSpecified", DrawPurpose::NotSpecified)
        .value("eUpdate", DrawPurpose::Update)
        .value("eUpdateDynamic", DrawPurpose::UpdateDynamic)
        .value("eUpdateHealing", DrawPurpose::UpdateHealing)
        .value("eHilite", DrawPurpose::Hilite)
        .value("eUnhilite", DrawPurpose::Unhilite)
        .value("eChangedPre", DrawPurpose::ChangedPre)
        .value("eChangedPost", DrawPurpose::ChangedPost)
        .value("eRestoredPre", DrawPurpose::RestoredPre)
        .value("eRestoredPost", DrawPurpose::RestoredPost)
        .value("eDynamics", DrawPurpose::Dynamics)
        .value("eRangeCalculation", DrawPurpose::RangeCalculation)
        .value("ePlot", DrawPurpose::Plot)
        .value("ePick", DrawPurpose::Pick)
        .value("eFlash", DrawPurpose::Flash)
        .value("eTransientChanged", DrawPurpose::TransientChanged)
        .value("eCaptureGeometry", DrawPurpose::CaptureGeometry)
        .value("eGenerateThumbnail", DrawPurpose::GenerateThumbnail)
        .value("eForceRedraw", DrawPurpose::ForceRedraw)
        .value("eFenceAccept", DrawPurpose::FenceAccept)
        .value("eRegionFlood", DrawPurpose::RegionFlood)
        .value("eFitView", DrawPurpose::FitView)
        .value("eXGraphicsCreate", DrawPurpose::XGraphicsCreate)
        .value("eCaptureShadowList", DrawPurpose::CaptureShadowList)
        .value("eExportVisibleEdges", DrawPurpose::ExportVisibleEdges)
        .value("eInterferenceDetection", DrawPurpose::InterferenceDetection)
        .value("eCutXGraphicsCreate", DrawPurpose::CutXGraphicsCreate)
        .value("eModelFacet", DrawPurpose::ModelFacet)
        .value("eMeasure", DrawPurpose::Measure)
        .value("eVisibilityCalculation", DrawPurpose::VisibilityCalculation)
        .value("eProxyHashExtraction", DrawPurpose::ProxyHashExtraction)
        .value("eComputeModelRefRange", DrawPurpose::ComputeModelRefRange)
        .value("eDgnDbConvert", DrawPurpose::DgnDbConvert)
        .value("eVueRender", DrawPurpose::VueRender)
        .export_values();

    //===================================================================================
    // enum MemberTraverseType
    py::enum_< MemberTraverseType>(m, "MemberTraverseType")
        .value("eSimple", MemberTraverseType::Simple)
        .value("eManipulate", MemberTraverseType::Manipulate)
        .value("eCopy", MemberTraverseType::Copy)
        .value("eEnumerate", MemberTraverseType::Enumerate)
        .value("eDirectMembers", MemberTraverseType::DirectMembers)
        .export_values();

    //===================================================================================
    // enum FileCompareMask
    py::enum_< FileCompareMask>(m, "FileCompareMask")
        .value("eNil", FileCompareMask::None)
        .value("eBaseNameAndExtension", FileCompareMask::BaseNameAndExtension)
        .value("eFileStat", FileCompareMask::FileStat)
        .value("eAll", FileCompareMask::All)
        .export_values();

    //===================================================================================        
    // struct CameraInfo
    py::class_< CameraInfo>(m, "CameraInfo")
        .def_readwrite("angle", &CameraInfo::m_angle)
        .def_readwrite("focalLength", &CameraInfo::m_focalLength)
        .def_readwrite("position", &CameraInfo::m_position)
        .def("Invalidate", &CameraInfo::Invalidate);

    //===================================================================================
    // enum MlineModifyPoint
    py::enum_< MlineModifyPoint>(m, "MlineModifyPoint")
        .value("eNil", MlineModifyPoint::None)
        .value("eShiftBreaks", MlineModifyPoint::ShiftBreaks)
        .value("eRemoveAssociations", MlineModifyPoint::RemoveAssociations)
        .export_values();

    //===================================================================================
    // enum StyleIteratorMode
    py::enum_< StyleIteratorMode>(m, "StyleIteratorMode")
        .value("eInvalid", StyleIteratorMode::Invalid)
        .value("eActiveFileOnly", StyleIteratorMode::ActiveFileOnly)
        .value("eLibrariesOnly", StyleIteratorMode::LibrariesOnly)
        .value("eActiveFileAndLibraries", StyleIteratorMode::ActiveFileAndLibraries)
        .export_values();

    //===================================================================================
    // enum StyleEventType
    py::enum_< StyleEventType>(m, "StyleEventType")
        .value("eInvalid", StyleEventType::Invalid)
        .value("eAdd", StyleEventType::Add)
        .value("eDelete", StyleEventType::Delete)
        .value("eChange", StyleEventType::Change)
        .value("eSetActive", StyleEventType::SetActive)
        .value("eModifyActive", StyleEventType::ModifyActive)
        .value("eBeforeSetActive", StyleEventType::BeforeSetActive)
        .export_values();

    //===================================================================================
    // enum StyleEventSource
    py::enum_< StyleEventSource>(m, "StyleEventSource")
        .value("eInvalid", StyleEventSource::Invalid)
        .value("eAction", StyleEventSource::Action)
        .value("eUndo", StyleEventSource::Undo)
        .value("eRedo", StyleEventSource::Redo)
        .export_values();

    //===================================================================================
    // enum LevelMaskReferenceState
    py::enum_< LevelMaskReferenceState>(m, "LevelMaskReferenceState")
        .value("eUnknown", LevelMaskReferenceState::Unknown)
        .value("eOff", LevelMaskReferenceState::Off)
        .value("eOn", LevelMaskReferenceState::On)
        .export_values();

    //===================================================================================
    // enum LimitRefLoading
    py::enum_< LimitRefLoading>(m, "LimitRefLoading")
        .value("eNil", LimitRefLoading::None)
        .value("eDoNotFillCaches", LimitRefLoading::DoNotFillCaches)
        .value("eIgnoreAttachments", LimitRefLoading::IgnoreAttachments)
        .export_values();

    //===================================================================================
    // enum ScanTestResult
    py::enum_< ScanTestResult>(m, "ScanTestResult")
        .value("ePass", ScanTestResult::Pass)
        .value("eFail", ScanTestResult::Fail)
        .export_values();    

    //===================================================================================
    //Struct AssocPoint
    py::class_< AssocPoint> c0(m, "AssocPoint");
    c0.def(py::init<>());
    c0.def("__getitem__", [](const AssocPoint& self, int index)
        {
        if (index < 0 || index >= 20)
            {
            PyErr_SetString (PyExc_IndexError, "Index out of range, the range is 0~19");
            throw py::error_already_set();
            }

        return self.buf[index];
        });

    c0.def("__setitem__", [](AssocPoint& self, int index, unsigned short value)
        {
        if (index < 0 || index >= 20)
            {
                PyErr_SetString(PyExc_IndexError, "Index out of range, the range is 0~19");
                throw py::error_already_set();
            }

        self.buf[index] = value;
        });

    c0.def("__len__", [](const AssocPoint& self)
        {
        return 20;  //const length in C++ side
        });

    //===================================================================================
    //Struct LevelClassMask
    py::class_< LevelClassMask> c1(m, "LevelClassMask");
    c1.def(py::init<>());
    c1.def_property("levelBitMask", 
        [](LevelClassMask const& self) { return self.levelBitMaskP; },
        [](LevelClassMask& self, BitMaskCP val) { self.levelBitMaskP = val; }, py::keep_alive<1, 2>() );
    c1.def_readwrite("classMask", &LevelClassMask::classMask);
    }