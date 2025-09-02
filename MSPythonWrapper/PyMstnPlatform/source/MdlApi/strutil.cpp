/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MdlApi\mscell.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn\MdlApi\msstring.fdf>
#include <Mstn\MdlApi\msparse.fdf>

struct StringUtility {};

//Expose CommandTableStatus to python in CommandTable.h
enum    CmdTableStatus
    {
    CT_Success = 0,
    CT_ResourceNotFound = 0x5000 + 1,
    CT_BadResourceType = 0x5000 + 2,
    CT_BadResource = 0x5000 + 3,
    CT_ExceedsMaximumNestLevel = 0x5000 + 4,

    CT_XmlMissingRootTable = 0x5000 + 0x20,
    CT_XmlDuplicateRootTable = 0x5000 + 0x21,
    CT_XmlMissingCommandWord = 0x5000 + 0x22,
    CT_XmlMissingSubtable = 0x5000 + 0x23,
    CT_XmlDuplicateSubtable = 0x5000 + 0x24,
    CT_XmlBadFeatureAspect = 0x5000 + 0x25,
    CT_XmlDuplicateKeyinHandlersNode = 0x5000 + 0x26,
    CT_XmlMissingKeyinNode = 0x5000 + 0x27,
    CT_XmlMissingFunctionNode = 0x5000 + 0x28,

    CT_NoCommandMatch = (-1),     // match MSERROR_NOMATCH
    CT_AmbiguousMatch = (-2),     // match MSERROR_AMBIGUOUS
    CT_ERROR = 0x8000,            //BentleyStatus::ERROR
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       12/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_msstring(py::module_& m)
    {
    py::class_<StringUtility> c1(m, "StringUtility"); 

    c1.def_static("FromUors", &mdlString_fromUors, "uor_string"_a, "uors"_a);
    c1.def_static("ToUors", [] (WString const& wstr)
        {
        double result;
        mdlString_toUors(&result, wstr.c_str());
        return result;
        });
    c1.def_static("FromDirection", &mdlString_fromDirection, "angle_str"_a, "abs_angle"_a, "format"_a, "igdsChars"_a, "addTrueNorth"_a, "angleMode"_a, "precision"_a, "leadingZero"_a, "trailingZeros"_a, "modelRef"_a);
    c1.def_static("ToDirection", [](WString const& wstr)
        {
        double result;
        mdlString_toDirection(&result, wstr.c_str());
        return result;
        });

    //===================================================================================
    // Enum CmdTableStatus
    py::enum_<CmdTableStatus>(m, "CommandTableStatus")
        .value("eCT_Success", CmdTableStatus::CT_Success)
        .value("eCT_ResourceNotFound", CmdTableStatus::CT_ResourceNotFound)
        .value("eCT_BadResourceType", CmdTableStatus::CT_BadResourceType)
        .value("eCT_BadResource", CmdTableStatus::CT_BadResource)
        .value("eCT_ExceedsMaximumNestLevel", CmdTableStatus::CT_ExceedsMaximumNestLevel)
        .value("eCT_XmlMissingRootTable", CmdTableStatus::CT_XmlMissingRootTable)
        .value("eCT_XmlDuplicateRootTable", CmdTableStatus::CT_XmlDuplicateRootTable)
        .value("eCT_XmlMissingCommandWord", CmdTableStatus::CT_XmlMissingCommandWord)
        .value("eCT_XmlMissingSubtable", CmdTableStatus::CT_XmlMissingSubtable)
        .value("eCT_XmlDuplicateSubtable", CmdTableStatus::CT_XmlDuplicateSubtable)
        .value("eCT_XmlBadFeatureAspect", CmdTableStatus::CT_XmlBadFeatureAspect)
        .value("eCT_XmlDuplicateKeyinHandlersNode", CmdTableStatus::CT_XmlDuplicateKeyinHandlersNode)
        .value("eCT_XmlMissingKeyinNode", CmdTableStatus::CT_XmlMissingKeyinNode)
        .value("eCT_XmlMissingFunctionNode", CmdTableStatus::CT_XmlMissingFunctionNode)
        .value("eCT_NoCommandMatch", CmdTableStatus::CT_NoCommandMatch)
        .value("eCT_AmbiguousMatch", CmdTableStatus::CT_AmbiguousMatch)
        .value("eCT_ERROR", CmdTableStatus::CT_ERROR)
        .export_values();

    //===================================================================================
    // struct PythonKeyinManager
    py::class_< PythonKeyinManager> c2(m, "PythonKeyinManager");

    c2.def("LoadCommandTableFromXml", [](PythonKeyinManager& self, WStringR pythonFilePath, WStringR xmlFileName) 
        {
        StatusInt status = self.LoadCommandTableFromXml(pythonFilePath, xmlFileName);
        return static_cast<CmdTableStatus>(status);
        }, "pythonFilePath"_a, "keyInXmlFileName"_a);

    c2.def_static("GetManager", &PythonKeyinManager::GetManager, py::return_value_policy::reference);
    }