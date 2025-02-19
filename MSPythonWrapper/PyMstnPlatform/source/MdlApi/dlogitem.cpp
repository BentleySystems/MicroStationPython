/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MdlApi\dlogitem.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/MdlApi/dlogitem.h>


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                      10/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_dlogitem(py::module_& m)
{
    py::enum_<HideReasonCode>(m, "HideReasonCode")
        .value("eHideWindow" , HideReasonCode::HideWindow)
        .value("eExiting"    , HideReasonCode::Exiting)
        .value("eWindowClose", HideReasonCode::WindowClose)
        .value("eNoDgnFile"  , HideReasonCode::NoDgnFile)
        .value("eUserClose"  , HideReasonCode::UserClose)
        .value("eMdlUnload"  , HideReasonCode::MdlUnload)
        .export_values();
}
