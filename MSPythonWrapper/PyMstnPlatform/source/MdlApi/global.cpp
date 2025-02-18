/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MdlApi\global.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn\MdlApi\global.h>


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       09/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_global(py::module_& m)
{
    py::class_<MSDisplayDescr> c1(m, "MSDisplayDescr");
    c1.def(py::init<>());
    c1.def_readwrite("id", &MSDisplayDescr::id);
    c1.def_readwrite("xResolution", &MSDisplayDescr::xResolution);
    c1.def_readwrite("yResolution", &MSDisplayDescr::yResolution);
    c1.def_readwrite("screenWidth", &MSDisplayDescr::screenWidth);
    c1.def_readwrite("screenHeight", &MSDisplayDescr::screenHeight);
    c1.def_readwrite("aspect", &MSDisplayDescr::aspect);
    c1.def_readwrite("charHeight", &MSDisplayDescr::charHeight);
    c1.def_readwrite("charWidth", &MSDisplayDescr::charWidth);
    c1.def_readwrite("cursorWidth", &MSDisplayDescr::cursorWidth);
    c1.def_readwrite("cursorHeight", &MSDisplayDescr::cursorHeight);
    c1.def_property_readonly("gammaTable",
        [](MSDisplayDescr const& self) {return py::bytearray((const char*)self.gammaTable, sizeof(self.gammaTable)); });
    c1.def_readwrite("gammaCorrection", &MSDisplayDescr::gammaCorrection);
    c1.def_readwrite("screenRect", &MSDisplayDescr::screenRect);
}