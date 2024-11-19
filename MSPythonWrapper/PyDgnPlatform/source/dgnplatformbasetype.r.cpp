/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgnplatformbasetype.r.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnPlatformBaseType.r.h>



static const char * __doc_Bentley_BSIRect_IsContained =R"doc(determine whether this rectangle is completely within a " container "
rectangle.)doc";

static const char * __doc_Bentley_BSIRect_Overlap =R"doc(determine whether this rectangle overlaps another one. Optionally
return the overlapping rect)doc";

static const char * __doc_Bentley_BSIRect_PointInside =R"doc(determine whether a point is inside of this rectangle)doc";

static const char * __doc_Bentley_BSIRect_IsEqual =R"doc(are two rectangles exactly equal?)doc";

static const char * __doc_Bentley_BSIRect_Union =R"doc(form union of this rectangle with another rectangle)doc";

static const char * __doc_Bentley_BSIRect_Offset =R"doc(offset rectangle by x and y values)doc";

static const char * __doc_Bentley_BSIRect_Expand =R"doc(make rectangle larger)doc";

static const char * __doc_Bentley_BSIRect_Inset =R"doc(inset rectangle by delta x, y)doc";

static const char * __doc_Bentley_BSIRect_Limit =R"doc(limit this rectangle so it is contained in " other ")doc";

static const char * __doc_Bentley_BSIRect_Aspect =R"doc(Return Width () / Height ())doc";

static const char * __doc_Bentley_BSIRect_Area =R"doc(Return Width() * Height ())doc";

static const char * __doc_Bentley_BSIRect_Height =R"doc(Return corner.y - origin.y + 1, i.e. pixel height with start end
considered inclusive.)doc";

static const char * __doc_Bentley_BSIRect_Width =R"doc(Return corner.x - origin.x + 1, i.e. pixel width with start end
considered inclusive.)doc";

static const char * __doc_Bentley_BSIRect_Bottom =R"doc(Reuturn the corner y coordinate. (Called " Bottom " because screen
rectangles advance downward.))doc";

static const char * __doc_Bentley_BSIRect_Right =R"doc(Return the corner x coordinate.)doc";

static const char * __doc_Bentley_BSIRect_Top =R"doc(Return the origin y coordinate. (Called " Top " name because screen
rectangles start at top left and advance downward.))doc";

static const char * __doc_Bentley_BSIRect_Left =R"doc(Return the origin x coordinate.)doc";

static const char * __doc_Bentley_BSIRect_Init =R"doc(Initialize by direct copy to points. This does NOT enforce ordering.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnPlatformBaseType_r(py::module_& m)
    {
    //===================================================================================
    // struct BSIRect
    py::class_< BSIRect> c0(m, "BSIRect");

    c0.def_readwrite("origin", &BSIRect::origin);
    c0.def_readwrite("corner", &BSIRect::corner);

    c0.def(py::init<>());
    c0.def("Init", py::overload_cast<int, int, int, int>(&BSIRect::Init), "xOrg"_a, "yOrg"_a, "xHigh"_a, "xHigh"_a, DOC(Bentley, BSIRect, Init));
    c0.def("Init", py::overload_cast<Point2d const*, Point2d const*>(&BSIRect::Init), "low"_a, "high"_a, DOC(Bentley, BSIRect, Init));

    c0.def("__repr__", [](BSIRect& self)
        {
        return "(origin:{}, corner:{})"_s.format(self.origin, self.corner); 
        });

    c0.def("Left", &BSIRect::Left, DOC(Bentley, BSIRect, Left));
    c0.def("Top", &BSIRect::Top, DOC(Bentley, BSIRect, Top));
    c0.def("Right", &BSIRect::Right, DOC(Bentley, BSIRect, Right));
    c0.def("Bottom", &BSIRect::Bottom, DOC(Bentley, BSIRect, Bottom));
    c0.def("Width", &BSIRect::Width, DOC(Bentley, BSIRect, Width));
    c0.def("Height", &BSIRect::Height, DOC(Bentley, BSIRect, Height));
    c0.def("Area", &BSIRect::Area, DOC(Bentley, BSIRect, Area));
    c0.def("Aspect", &BSIRect::Aspect, DOC(Bentley, BSIRect, Aspect));

    c0.def("Limit", &BSIRect::Limit, "other"_a, DOC(Bentley, BSIRect, Limit));
    c0.def("Inset", &BSIRect::Inset, "deltaX"_a, "deltaY"_a, DOC(Bentley, BSIRect, Inset));
    c0.def("Expand", &BSIRect::Expand, "delta"_a, DOC(Bentley, BSIRect, Expand));
    c0.def("Offset", &BSIRect::Offset, "dx"_a, "dy"_a, DOC(Bentley, BSIRect, Offset));
    c0.def("Union", &BSIRect::Union, "other"_a, DOC(Bentley, BSIRect, Union));
    c0.def("IsEqual", &BSIRect::IsEqual, "other"_a, DOC(Bentley, BSIRect, IsEqual));
    c0.def("PointInside", &BSIRect::PointInside, "pt"_a, DOC(Bentley, BSIRect, PointInside));
    c0.def("Overlap", &BSIRect::Overlap, "overlap"_a, "other"_a, DOC(Bentley, BSIRect, Overlap));
    c0.def("IsContained", &BSIRect::IsContained, "IsContained"_a, DOC(Bentley, BSIRect, IsContained));

    //===================================================================================
    // struct ScanRange
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