/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MicroStation.r.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/MicroStation.r.h>


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                      9/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_MicroStation_r(py::module_& m)
{
    py::enum_<DockPosition>(m, "DockPosition")
        .value("eDOCK_NOTDOCKED", DockPosition::DOCK_NOTDOCKED)
        .value("eDOCK_LEFT"     , DockPosition::DOCK_LEFT)
        .value("eDOCK_RIGHT"    , DockPosition::DOCK_RIGHT)
        .value("eDOCK_TOP"      , DockPosition::DOCK_TOP)
        .value("eDOCK_BOTTOM"   , DockPosition::DOCK_BOTTOM)
        .value("eDOCK_NOTSHOWN" , DockPosition::DOCK_NOTSHOWN)
        .value("eDOCK_CENTER"   , DockPosition::DOCK_CENTER)
        .value("eDOCK_FILL"     , DockPosition::DOCK_FILL)
        .export_values();

    py::enum_<DockPriority>(m, "DockPriority")
        .value("eDOCKPRIORITY_CMDWINDOW"      , DockPriority::DOCKPRIORITY_CMDWINDOW)
        .value("eDOCKPRIORITY_STATUS"         , DockPriority::DOCKPRIORITY_STATUS)
        .value("eDOCKPRIORITY_BASELEFT"       , DockPriority::DOCKPRIORITY_BASELEFT)
        .value("eDOCKPRIORITY_BASERIGHT"      , DockPriority::DOCKPRIORITY_BASERIGHT)
        .value("eDOCKPRIORITY_BASETOP"        , DockPriority::DOCKPRIORITY_BASETOP)
        .value("eDOCKPRIORITY_BASEBOTTOM"     , DockPriority::DOCKPRIORITY_BASEBOTTOM)
        .value("eDOCKEXTENT_DONTCARE"         , DockPriority::DOCKEXTENT_DONTCARE)
        .value("eDOCKEXTENT_FULLWIDTHORHEIGHT", DockPriority::DOCKEXTENT_FULLWIDTHORHEIGHT)
        .value("eDOCKEXTENT_SPECIFIED"        , DockPriority::DOCKEXTENT_SPECIFIED)
        .value("eDOCKEXTENT_INVALIDREGION"    , DockPriority::DOCKEXTENT_INVALIDREGION)
        .export_values();
}
