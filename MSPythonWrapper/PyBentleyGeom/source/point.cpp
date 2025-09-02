/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\point.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Geom/IntegerTypes/Point.h>



/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_Point(py::module_& m)
    {
    //===================================================================================
    py::class_<Point2d> c1(m, "Point2d");
    py::bind_vector<Point2dArray>(m, "Point2dArray", py::module_local(false));

    c1.def(py::init<>());
    c1.def_readwrite("x", &Point2d::x);
    c1.def_readwrite("y", &Point2d::y);

    c1.def_readwrite("X", &Point2d::x);
    c1.def_readwrite("Y", &Point2d::y);

    c1.def("__repr__", [] (Point2dCR self) { return "[{}, {}]"_s.format(self.x, self.y); });
    c1.def("__copy__", [] (const Point2d& self) { return Point2d(self); });
    
    //===================================================================================
    py::class_<Point3d> c2(m, "Point3d");
    py::bind_vector<Point3dArray>(m, "Point3dArray", py::module_local(false));

    c2.def(py::init<>());
    c2.def_readwrite("x", &Point3d::x);
    c2.def_readwrite("y", &Point3d::y);
    c2.def_readwrite("z", &Point3d::z);

    c2.def_readwrite("X", &Point3d::x);
    c2.def_readwrite("Y", &Point3d::y);
    c2.def_readwrite("Z", &Point3d::z);

    c2.def("__repr__", [] (Point3dCR self) { return "[{}, {}, {}]"_s.format(self.x, self.y, self.z); });
    c2.def("__copy__", [] (const Point3d& self) { return Point3d(self); });
    }