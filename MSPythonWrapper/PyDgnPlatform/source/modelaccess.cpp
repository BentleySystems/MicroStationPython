/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\modelaccess.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ModelAccess.h>



/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ModelAccess(py::module_& m)
    {
    //===================================================================================
    // Constants for ModelRefIterator
    m.attr("MRITERATE_Root") = MRITERATE_Root;
    m.attr("MRITERATE_PrimaryChildRefs") = MRITERATE_PrimaryChildRefs;
    m.attr("MRITERATE_ExtendedChildRefs") = MRITERATE_ExtendedChildRefs;
    m.attr("MRITERATE_IncludeRedundant") = MRITERATE_IncludeRedundant;
    m.attr("MRITERATE_DisplayOrder") = MRITERATE_DisplayOrder;

    //===================================================================================
    // Constants for mdlModelRef_getChildCount
    m.attr("MRCHILD_PrimaryRefs") = MRCHILD_PrimaryRefs;
    m.attr("MRCHILD_ExtendedRefs") = MRCHILD_ExtendedRefs;

    //===================================================================================
    m.attr("MRLIST_IncludeRoot") = MRLIST_IncludeRoot;
    m.attr("MRLIST_IncludePrimaryRefs") = MRLIST_IncludePrimaryRefs;
    m.attr("MRLIST_IncludeLibraryRefs") = MRLIST_IncludeLibraryRefs;
    m.attr("MRLIST_IncludeLibraryCells") = MRLIST_IncludeLibraryCells;
    m.attr("MRLIST_AllDisplayed") = MRLIST_AllDisplayed;

    //===================================================================================
    // enum ModelFlags
    py::enum_< ModelFlags>(m, "ModelFlags", py::arithmetic())
        .value("eMODELFLAG_NOT_IN_MODEL_LIST", MODELFLAG_NOT_IN_MODEL_LIST)
        .value("eMODELFLAG_NOT_IN_CELL_LIST", MODELFLAG_NOT_IN_CELL_LIST)
        .value("eMODELFLAG_LSSCALE_COMP_ANNSCALE", MODELFLAG_LSSCALE_COMP_ANNSCALE)
        .value("eMODELFLAG_LSSCALE_IS_ANNSCALE", MODELFLAG_LSSCALE_IS_ANNSCALE)
        .value("eMODELFLAG_IS_ANNOTATION_CELL", MODELFLAG_IS_ANNOTATION_CELL)
        .value("eMODELFLAG_AUTO_UPDATE_FIELDS", MODELFLAG_AUTO_UPDATE_FIELDS)
        .value("eMODELFLAG_NON_INDEXED", MODELFLAG_NON_INDEXED)
        .value("eMODELFLAG_IS_MARKUP", MODELFLAG_IS_MARKUP)
        .value("eMODELFLAG_DRAW_MASTERMODEL_LAST", MODELFLAG_DRAW_MASTERMODEL_LAST)
        .value("eMODELFLAG_NO_PROPAGATE_ANNSCALE", MODELFLAG_NO_PROPAGATE_ANNSCALE)
        .value("eMODELFLAG_UNIT_LOCK", MODELFLAG_UNIT_LOCK)
        .value("eMODELFLAG_GRID_LOCK", MODELFLAG_GRID_LOCK)
        .value("eMODELFLAG_ISO_GRID", MODELFLAG_ISO_GRID)
        .value("eMODELFLAG_ISO_LOCK", MODELFLAG_ISO_LOCK)
        .value("eMODELFLAG_ISO_PLANE", MODELFLAG_ISO_PLANE)
        .value("eMODELFLAG_USE_ANNOTATION_SCALE", MODELFLAG_USE_ANNOTATION_SCALE)
        .value("eMODELFLAG_ACS_LOCK", MODELFLAG_ACS_LOCK)
        .export_values();        

    }