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
    // struct PythonKeyinManager
    py::class_< PythonKeyinManager> c2(m, "PythonKeyinManager");

    c2.def("LoadCommandTableFromXml", &PythonKeyinManager::LoadCommandTableFromXml, "pythonFilePath"_a, "keyInXmlFileName"_a );

    c2.def_static("GetManager", &PythonKeyinManager::GetManager, py::return_value_policy::reference);

    }