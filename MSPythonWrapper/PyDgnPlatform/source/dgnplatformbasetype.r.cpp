/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgnplatformbasetype.r.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnPlatformBaseType.r.h>

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnPlatformBaseType_r(py::module_& m)
    {
    //===================================================================================
    // struct BSIRect
    py::class_< BSIRect>(m, "BSIRect")
        .def(py::init<>())
        .def_readwrite("origin", &BSIRect::origin)
        .def_readwrite("corner", &BSIRect::corner)
        .def("__repr__", [] (BSIRect& self)
             {
             return "(origin:{}, corner:{})"_s.format(self.origin, self.corner); 
             });

    //===================================================================================
    // struct BSIRect
    py::class_< ScanRange>(m, "ScanRange")
        .def(py::init<>())
        .def_readwrite("xlowlim", &ScanRange::xlowlim)
        .def_readwrite("ylowlim", &ScanRange::ylowlim)
        .def_readwrite("zlowlim", &ScanRange::zlowlim)
        .def_readwrite("xhighlim", &ScanRange::xhighlim)
        .def_readwrite("yhighlim", &ScanRange::yhighlim)
        .def_readwrite("zhighlim", &ScanRange::zhighlim)
        .def("__repr__", [] (ScanRange& self)
             {
             return "(lowlim:[{}, {}, {}], highlim:[{}, {}, {}])"_s.format(self.xlowlim, self.ylowlim, self.zlowlim, self.xhighlim, self.yhighlim, self.zhighlim);
             });
    }