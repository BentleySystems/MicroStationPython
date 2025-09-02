/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgnelements.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnFileIO/DgnElements.h>
#include <Pybind11/numpy.h>



/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnElements(py::module_& m)
    {
    PYBIND11_NUMPY_DTYPE(DPoint3d, x, y, z);
    PYBIND11_NUMPY_DTYPE(DPoint2d, x, y);
    //struct Elm_hdr
    py::class_<Elm_hdr> c000(m, "Elm_hdr");
    c000.def_readwrite("type", &Elm_hdr::type);

    c000.def_property("reserved",
        [](Elm_hdr const& self) {return self.reserved; },
        [](Elm_hdr& self, UInt16 value) {self.reserved = value; });

    c000.def_property("archive",
        [](Elm_hdr const& self) {return self.archive; },
        [](Elm_hdr& self, UInt16 value) {self.archive = value; });

    c000.def_property("obsolete__",
        [](Elm_hdr const& self) {return self.obsolete__; },
        [](Elm_hdr& self, UInt16 value) {self.obsolete__ = value; });

    c000.def_property("obsolete_2",
        [](Elm_hdr const& self) {return self.obsolete_2; },
        [](Elm_hdr& self, UInt16 value) {self.obsolete_2 = value; });

    c000.def_property("nonModel",
        [](Elm_hdr const& self) {return self.nonModel; },
        [](Elm_hdr& self, UInt16 value) {self.nonModel = value; });

    c000.def_property("locked",
        [](Elm_hdr const& self) {return self.locked; },
        [](Elm_hdr& self, UInt16 value) {self.locked = value; });

    c000.def_property("isGraphics",
        [](Elm_hdr const& self) {return self.isGraphics; },
        [](Elm_hdr& self, UInt16 value) {self.isGraphics = value; });

    c000.def_property("isComplexHeader",
        [](Elm_hdr const& self) {return self.isComplexHeader; },
        [](Elm_hdr& self, UInt16 value) {self.isComplexHeader = value; });

    c000.def_property("complex",
        [](Elm_hdr const& self) {return self.complex; },
        [](Elm_hdr& self, UInt16 value) {self.complex = value; });

    c000.def_property("deleted",
        [](Elm_hdr const& self) {return self.deleted; },
        [](Elm_hdr& self, UInt16 value) {self.deleted = value; });

    c000.def_readwrite("elementSize", &Elm_hdr::elementSize);
    c000.def_readwrite("attrOffset", &Elm_hdr::attrOffset);
    c000.def_readwrite("level", &Elm_hdr::level);
    c000.def_readwrite("uniqueId", &Elm_hdr::uniqueId);
    c000.def_readwrite("lastModified", &Elm_hdr::lastModified);

    //struct DispHdrProperties
    py::class_<DispHdrProperties> c0011(m, "DispHdrProperties");

    c0011.def_property("elementClass",
        [](DispHdrProperties const& self) {return self.elementClass; },
        [](DispHdrProperties& self, UInt16 value) {self.elementClass = value; });

    c0011.def_property("reserved",
        [](DispHdrProperties const& self) {return self.reserved; },
        [](DispHdrProperties& self, UInt16 value) {self.reserved = value; });

    c0011.def_property("unused2",
        [](DispHdrProperties const& self) {return self.unused2; },
        [](DispHdrProperties& self, UInt16 value) {self.unused2 = value; });

    c0011.def_property("unused3",
        [](DispHdrProperties const& self) {return self.unused3; },
        [](DispHdrProperties& self, UInt16 value) {self.unused3 = value; });

    c0011.def_property("invisible",
        [](DispHdrProperties const& self) {return self.invisible; },
        [](DispHdrProperties& self, UInt16 value) {self.invisible = value; });

    c0011.def_property("dynamicRange",
        [](DispHdrProperties const& self) {return self.dynamicRange; },
        [](DispHdrProperties& self, UInt16 value) {self.dynamicRange = value; });

    c0011.def_property("n",
        [](DispHdrProperties const& self) {return self.n; },
        [](DispHdrProperties& self, UInt16 value) {self.n = value; });

    c0011.def_property("m",
        [](DispHdrProperties const& self) {return self.m; },
        [](DispHdrProperties& self, UInt16 value) {self.m = value; });

    c0011.def_property("is3d",
        [](DispHdrProperties const& self) {return self.is3d; },
        [](DispHdrProperties& self, UInt16 value) {self.is3d = value; });

    c0011.def_property("r",
        [](DispHdrProperties const& self) {return self.r; },
        [](DispHdrProperties& self, UInt16 value) {self.r = value; });

    c0011.def_property("p",
        [](DispHdrProperties const& self) {return self.p; },
        [](DispHdrProperties& self, UInt16 value) {self.p = value; });

    c0011.def_property("s",
        [](DispHdrProperties const& self) {return self.s; },
        [](DispHdrProperties& self, UInt16 value) {self.s = value; });

    c0011.def_property("h",
        [](DispHdrProperties const& self) {return self.h; },
        [](DispHdrProperties& self, UInt16 value) {self.h = value; });

    //struct Disp_hdr
    py::class_<Disp_hdr> c001(m, "Disp_hdr");

    c001.def_readwrite("grphgrp", &Disp_hdr::grphgrp);
    c001.def_readwrite("priority", &Disp_hdr::priority);

    //struct Disp_hdr::props
    union Disp_hdr_props
        {
        Int16       s;
        DispHdrProperties  b;
        };

    py::class_<Disp_hdr_props> c0010(c001, "Disp_hdr_props");
    c0010.def(py::init<>());
    c0010.def_property("s",
        [](Disp_hdr_props const& self) {return self.s; },
        [](Disp_hdr_props& self, Int16 value) {self.s = value; });

    c0010.def_property("b",
        [](Disp_hdr_props const& self) {return &self.b; },
        [](Disp_hdr_props& self, DispHdrProperties const& value) {self.b = value; });

    c001.def_property("props",
        [](Disp_hdr& self) {return reinterpret_cast<Disp_hdr_props*>(&self.props); },
        [](Disp_hdr& self, Disp_hdr_props const& value) { memcpy(&self.props, &value, sizeof(Disp_hdr_props)); });

    c001.def_readwrite("reserved", &Disp_hdr::reserved);
    c001.def_readwrite("symb", &Disp_hdr::symb);
    c001.def_readwrite("range", &Disp_hdr::range);

    //struct Header
    py::class_<Header> c002(m, "Header");
    c002.def_readwrite("ehdr", &Header::ehdr);
    c002.def_readwrite("dhdr", &Header::dhdr);

    //struct line_string_2d
    py::class_<Line_String_2d> c003(m, "Line_String_2d");
    c003.def_readwrite("ehdr", &Line_String_2d::ehdr);
    c003.def_readwrite("dhdr", &Line_String_2d::dhdr);
    c003.def_readwrite("numverts", &Line_String_2d::numverts);
    c003.def_readwrite("reserved", &Line_String_2d::reserved);
    c003.def_property("vertice",
        [](Line_String_2d& self)
        {
        py::list ptArray;//Here returns a list instead of DPoint3dArray to enable the vertice[i] value modification support with assignment 'ptList[i] = pt' on python side
        for (size_t i = 0; i < self.numverts; i++)
            ptArray.append(py::cast(self.vertice[i], py::return_value_policy::reference));
        return ptArray;
        },
        [](Line_String_2d& self, DPoint2dArray const& ptArray)
        {
        size_t validNumber = ptArray.size();
        validNumber = validNumber > self.numverts ? self.numverts : validNumber;

        for (size_t i = 0; i < validNumber; i++)
            self.vertice[i] = ptArray[i];
        });
    c003.def_property("verticeArray",
        [](Line_String_2d& self)
        {
        return py::array_t<DPoint2d>{ self.numverts, self.vertice, py::cast(self)};
        },
        [](Line_String_2d& self, py::array_t<DPoint2d> const& arr)
        {
        py::buffer_info buf = arr.request();
        auto* ptr = static_cast<DPoint2d*>(buf.ptr);

        if (self.numverts != arr.size())
            return;

        memcpy(self.vertice, ptr, self.numverts * sizeof(DPoint2d));
        });

    //struct Line_String_3d
    py::class_<Line_String_3d> c004(m, "Line_String_3d");
    c004.def_readwrite("ehdr", &Line_String_3d::ehdr);
    c004.def_readwrite("dhdr", &Line_String_3d::dhdr);
    c004.def_readwrite("numverts", &Line_String_3d::numverts);
    c004.def_readwrite("reserved", &Line_String_3d::reserved);
    c004.def_property("vertice",
        [](Line_String_3d& self)
        {
        py::list ptArray;  //Here returns a list instead of DPoint3dArray to enable the vertice[i] value modification support with assignment 'ptList[i] = pt' on python side
        for (UInt32 i = 0; i < self.numverts; i++)
            ptArray.append(py::cast(self.vertice[i], py::return_value_policy::reference));
        return ptArray;
        },
        [](Line_String_3d& self, DPoint3dArray const& ptArray)
        {
            size_t validNumber = ptArray.size();
            validNumber = validNumber > self.numverts ? self.numverts : validNumber;

            for (size_t i = 0; i < validNumber; i++)
                self.vertice[i] = ptArray[i];
        });
    c004.def_property("verticeArray",
        [](Line_String_3d& self)
        {
        return py::array_t<DPoint3d>{ self.numverts, self.vertice, py::cast(self)};
        },
        [](Line_String_3d& self, py::array_t<DPoint3d> const& arr)
        {
        py::buffer_info buf = arr.request();
        auto* ptr = static_cast<DPoint3d*>(buf.ptr);

        if (self.numverts != arr.size())
            return;

        memcpy(self.vertice, ptr, self.numverts * sizeof(DPoint3d));
        });

    //struct cell_2d
    py::class_<Cell_2d> c005(m, "Cell_2d");
    c005.def_readwrite("ehdr", &Cell_2d::ehdr);
    c005.def_readwrite("dhdr", &Cell_2d::dhdr);
    c005.def_readwrite("componentCount", &Cell_2d::componentCount);
    c005.def_readwrite("classMap", &Cell_2d::classMap);

    //struct cell_2d_flags
    struct cell_2d_flags
        {
        UInt16      isAnnotation : 1;                 // is annotation cell 
        UInt16      matchSourceAnnotationSize : 1;    // true = when scaling, do not scale its annotations 
        UInt16      matchSourceDimValue : 1;          // true = when scaling, do not scale its dimension values 
        UInt16      matchSourceMultilineOffset : 1;   // true = when scaling, do not scale its multiline offsets 
        UInt16      reserved : 12;                    // reserved 
        };

    py::class_<cell_2d_flags> c0050(c005, "cell_2d_flags");
    c0050.def_property("isAnnotation",
        [](cell_2d_flags const& self) {return self.isAnnotation; },
        [](cell_2d_flags& self, Int16 value) {self.isAnnotation = value; });

    c0050.def_property("matchSourceAnnotationSize",
        [](cell_2d_flags const& self) {return self.matchSourceAnnotationSize; },
        [](cell_2d_flags& self, Int16 value) {self.matchSourceAnnotationSize = value; });

    c0050.def_property("matchSourceDimValue",
        [](cell_2d_flags const& self) {return self.matchSourceDimValue; },
        [](cell_2d_flags& self, Int16 value) {self.matchSourceDimValue = value; });

    c0050.def_property("matchSourceMultilineOffset",
        [](cell_2d_flags const& self) {return self.matchSourceMultilineOffset; },
        [](cell_2d_flags& self, Int16 value) {self.matchSourceMultilineOffset = value; });

    c0050.def_property("reserved",
        [](cell_2d_flags const& self) {return self.reserved; },
        [](cell_2d_flags& self, Int16 value) {self.reserved = value; });

    c005.def_property("flags",
        [](Cell_2d& self) {return reinterpret_cast<cell_2d_flags*>(&self.flags); },
        [](Cell_2d& self, cell_2d_flags const& value) { memcpy(&self.flags, &value, sizeof(cell_2d_flags)); } );

    c005.def_readwrite("rnglow", &Cell_2d::rnglow);
    c005.def_readwrite("rnghigh", &Cell_2d::rnghigh);

    c005.def_property("transform",
        [](Cell_2d& self) {return py::array_t<T_Adouble>{{2,2}, self.transform[0], py::cast(self)};},
        [](Cell_2d& self, py::array_t<T_Adouble> const& arr) 
        {
        py::buffer_info buf = arr.request();
        auto* ptr = static_cast<T_Adouble*>(buf.ptr);

        if (4 != arr.size())
            return;

        memcpy(self.transform[0], ptr, 4 * sizeof(T_Adouble));
        });

    c005.def_readwrite("origin", &Cell_2d::origin);

    //struct cell_3d
    py::class_<Cell_3d> c006(m, "Cell_3d");
    c006.def_readwrite("ehdr", &Cell_3d::ehdr);
    c006.def_readwrite("dhdr", &Cell_3d::dhdr);
    c006.def_readwrite("componentCount", &Cell_3d::componentCount);
    c006.def_readwrite("classMap", &Cell_3d::classMap);

    //struct cell_3d_flags
    struct cell_3d_flags
        {
        UInt16      isAnnotation : 1;                 
        UInt16      matchSourceAnnotationSize : 1;    
        UInt16      matchSourceDimValue : 1;          
        UInt16      matchSourceMultilineOffset : 1;    
        UInt16      reserved : 12;                    
        };

    py::class_<cell_3d_flags> c0060(c006, "cell_3d_flags");
    c0060.def_property("isAnnotation",
        [](cell_3d_flags const& self) {return self.isAnnotation; },
        [](cell_3d_flags& self, Int16 value) {self.isAnnotation = value; });

    c0060.def_property("matchSourceAnnotationSize",
        [](cell_3d_flags const& self) {return self.matchSourceAnnotationSize; },
        [](cell_3d_flags& self, Int16 value) {self.matchSourceAnnotationSize = value; });

    c0060.def_property("matchSourceDimValue",
        [](cell_3d_flags const& self) {return self.matchSourceDimValue; },
        [](cell_3d_flags& self, Int16 value) {self.matchSourceDimValue = value; });

    c0060.def_property("matchSourceMultilineOffset",
        [](cell_3d_flags const& self) {return self.matchSourceMultilineOffset; },
        [](cell_3d_flags& self, Int16 value) {self.matchSourceMultilineOffset = value; });

    c0060.def_property("reserved",
        [](cell_3d_flags const& self) {return self.reserved; },
        [](cell_3d_flags& self, Int16 value) {self.reserved = value; });

    c006.def_property("flags",
        [](Cell_3d& self) {return reinterpret_cast<cell_3d_flags*>(&self.flags); },
        [](Cell_3d& self, cell_3d_flags const& value) {memcpy (&self.flags, &value, sizeof(cell_3d_flags));});

    c006.def_readwrite("rnglow", &Cell_3d::rnglow);
    c006.def_readwrite("rnghigh", &Cell_3d::rnghigh);

    c006.def_property("transform",
        [](Cell_3d& self) {return py::array_t<T_Adouble>{ {3, 3}, self.transform[0], py::cast(self)}; },
        [](Cell_3d& self, py::array_t<T_Adouble> const& arr)
        {
        py::buffer_info buf = arr.request();
        auto* ptr = static_cast<T_Adouble*>(buf.ptr);

        if (9 != arr.size())
            return;

        memcpy (self.transform[0], ptr, 9 * sizeof(T_Adouble));
        });

    c006.def_readwrite("origin", &cell_3d::origin);

    //struct Line_2d
    py::class_<Line_2d> c007(m, "Line_2d");
    c007.def_readwrite("ehdr", &Line_2d::ehdr);
    c007.def_readwrite("dhdr", &Line_2d::dhdr);
    c007.def_readwrite("start", &Line_2d::start);
    c007.def_readwrite("end", &Line_2d::end);

    //struct Line_3d
    py::class_<Line_3d> c008(m, "Line_3d");
    c008.def_readwrite("ehdr", &Line_3d::ehdr);
    c008.def_readwrite("dhdr", &Line_3d::dhdr);
    c008.def_readwrite("start", &Line_3d::start);
    c008.def_readwrite("end", &Line_3d::end);

    //struct Text_node_2d
    py::class_<Text_node_2d> c009(m, "Text_node_2d");
    c009.def_readwrite("ehdr", &Text_node_2d::ehdr);
    c009.def_readwrite("dhdr", &Text_node_2d::dhdr);
    c009.def_readwrite("componentCount", &Text_node_2d::componentCount);
    c009.def_readwrite("nodenumber", &Text_node_2d::nodenumber);
    c009.def_readwrite("font", &Text_node_2d::font);
    c009.def_readwrite("maxlngth", &Text_node_2d::maxlngth);
    c009.def_readwrite("just", &Text_node_2d::just);
    c009.def_readwrite("linespc", &Text_node_2d::linespc);
    c009.def_readwrite("lngthmult", &Text_node_2d::lngthmult);
    c009.def_readwrite("hghtmult", &Text_node_2d::hghtmult);
    c009.def_readwrite("rotationAngle", &Text_node_2d::rotationAngle);
    c009.def_readwrite("origin", &Text_node_2d::origin);

    //struct Text_node_3d
    py::class_<Text_node_3d> c010(m, "Text_node_3d");
    c010.def_readwrite("ehdr", &Text_node_3d::ehdr);
    c010.def_readwrite("dhdr", &Text_node_3d::dhdr);
    c010.def_readwrite("componentCount", &Text_node_3d::componentCount);
    c010.def_readwrite("nodenumber", &Text_node_3d::nodenumber);
    c010.def_readwrite("font", &Text_node_3d::font);
    c010.def_readwrite("maxlngth", &Text_node_3d::maxlngth);
    c010.def_readwrite("just", &Text_node_3d::just);
    c010.def_readwrite("linespc", &Text_node_3d::linespc);
    c010.def_readwrite("lngthmult", &Text_node_3d::lngthmult);
    c010.def_readwrite("hghtmult", &Text_node_3d::hghtmult);
    c010.def_property("quat",
        [](Text_node_3d& self) {return py::array_t<T_Adouble>{ 4, self.quat, py::cast(self)}; },
        [](Text_node_3d& self, py::array_t<T_Adouble> const& arr) 
        {
        py::buffer_info buf = arr.request();
        auto* ptr = static_cast<T_Adouble*>(buf.ptr);

        if (4 != arr.size())
            return;

        memcpy (self.quat, ptr, 4*sizeof(T_Adouble));
        });

    c010.def_readwrite("origin", &Text_node_3d::origin);

    //struct Complex_string
    py::class_<Complex_string> c011(m, "Complex_string");
    c011.def(py::init<>());
    c011.def_readwrite("ehdr", &Complex_string::ehdr);
    c011.def_readwrite("dhdr", &Complex_string::dhdr);
    c011.def_readwrite("componentCount", &Complex_string::componentCount);
    c011.def_readwrite("reserved", &Complex_string::reserved);

    //struct Ellipse_2d
    py::class_<Ellipse_2d> c012(m, "Ellipse_2d");
    c012.def_readwrite("ehdr", &Ellipse_2d::ehdr);
    c012.def_readwrite("dhdr", &Ellipse_2d::dhdr);
    c012.def_readwrite("primary", &Ellipse_2d::primary);
    c012.def_readwrite("secondary", &Ellipse_2d::secondary);
    c012.def_readwrite("rotationAngle", &Ellipse_2d::rotationAngle);
    c012.def_readwrite("origin", &Ellipse_2d::origin);

    //struct Ellipse_3d
    py::class_<Ellipse_3d> c013(m, "Ellipse_3d");
    c013.def_readwrite("ehdr", &Ellipse_3d::ehdr);
    c013.def_readwrite("dhdr", &Ellipse_3d::dhdr);
    c013.def_readwrite("primary", &Ellipse_3d::primary);
    c013.def_readwrite("secondary", &Ellipse_3d::secondary);
    c013.def_property("quat",
        [](Ellipse_3d& self) {return py::array_t<T_Adouble>{ 4, self.quat, py::cast(self)}; },
        [](Ellipse_3d& self, py::array_t<T_Adouble> const& arr)
        {
        py::buffer_info buf = arr.request();
        auto* ptr = static_cast<T_Adouble*>(buf.ptr);

        if (4 != arr.size())
            return;

        memcpy(self.quat, ptr, 4 * sizeof(T_Adouble));
        });

    c013.def_readwrite("origin", &Ellipse_3d::origin);

    //struct Arc_2d
    py::class_<Arc_2d> c014(m, "Arc_2d");
    c014.def_readwrite("ehdr", &Arc_2d::ehdr);
    c014.def_readwrite("dhdr", &Arc_2d::dhdr);
    c014.def_readwrite("startAngle", &Arc_2d::startAngle);
    c014.def_readwrite("sweepAngle", &Arc_2d::sweepAngle);
    c014.def_readwrite("primary", &Arc_2d::primary);
    c014.def_readwrite("secondary", &Arc_2d::secondary);
    c014.def_readwrite("rotationAngle", &Arc_2d::rotationAngle);
    c014.def_readwrite("origin", &Arc_2d::origin);

    //struct Arc_3d
    py::class_<Arc_3d> c015(m, "Arc_3d");
    c015.def_readwrite("ehdr", &Arc_3d::ehdr);
    c015.def_readwrite("dhdr", &Arc_3d::dhdr);
    c015.def_readwrite("startAngle", &Arc_3d::startAngle);
    c015.def_readwrite("sweepAngle", &Arc_3d::sweepAngle);
    c015.def_readwrite("primary", &Arc_3d::primary);
    c015.def_readwrite("secondary", &Arc_3d::secondary);
    c015.def_readwrite("origin", &Arc_3d::origin);
    c015.def_property("quat",
        [](Arc_3d& self) {return py::array_t<T_Adouble>{ 4, self.quat, py::cast(self)}; },
        [](Arc_3d& self, py::array_t<T_Adouble> const& arr)
        {
        py::buffer_info buf = arr.request();
        auto* ptr = static_cast<T_Adouble*>(buf.ptr);

        if (4 != arr.size())
            return;

        memcpy(self.quat, ptr, 4 * sizeof(T_Adouble));
        });

    //struct Text_2d
    py::class_<Text_2d> c016(m, "Text_2d");
    c016.def_readwrite("ehdr", &Text_2d::ehdr);
    c016.def_readwrite("dhdr", &Text_2d::dhdr);
    c016.def_readwrite("font", &Text_2d::font);
    c016.def_readwrite("just", &Text_2d::just);
    c016.def_readwrite("numchars", &Text_2d::numchars);
    c016.def_readwrite("lngthmult", &Text_2d::lngthmult);
    c016.def_readwrite("hghtmult", &Text_2d::hghtmult);
    c016.def_readwrite("length", &Text_2d::length);
    c016.def_readwrite("height", &Text_2d::height);
    c016.def_readwrite("rotationAngle", &Text_2d::rotationAngle);
    c016.def_readwrite("origin", &Text_2d::origin);
    c016.def_readwrite("edflds", &Text_2d::edflds);
    c016.def_property("string",
        [](Text_2d& self) {return py::array_t<VariChar>{ self.numchars, self.string, py::cast(self)}; },
        [](Text_2d& self, py::array_t<VariChar> const& arr)
        {
        py::buffer_info buf = arr.request();
        auto* ptr = static_cast<VariChar*>(buf.ptr);

        if (self.numchars != arr.size())
            return;

        memcpy(self.string, ptr, self.numchars * sizeof(VariChar));
        });

    //struct Text_3d
    py::class_<Text_3d> c017(m, "Text_3d");
    c017.def_readwrite("ehdr", &Text_3d::ehdr);
    c017.def_readwrite("dhdr", &Text_3d::dhdr);
    c017.def_readwrite("font", &Text_3d::font);
    c017.def_readwrite("just", &Text_3d::just);
    c017.def_readwrite("numchars", &Text_3d::numchars);
    c017.def_readwrite("lngthmult", &Text_3d::lngthmult);
    c017.def_readwrite("hghtmult", &Text_3d::hghtmult);
    c017.def_readwrite("length", &Text_3d::length);
    c017.def_readwrite("height", &Text_3d::height);

    c017.def_property("quat",
        [](Text_3d& self) {return py::array_t<T_Adouble>{ 4, self.quat, py::cast(self)}; },
        [](Text_3d& self, py::array_t<T_Adouble> const& arr)
        {
        py::buffer_info buf = arr.request();
        auto* ptr = static_cast<T_Adouble*>(buf.ptr);

        if (4 != arr.size())
            return;

        memcpy(self.quat, ptr, 4 * sizeof(T_Adouble));
        });

    c017.def_readwrite("origin", &Text_3d::origin);
    c017.def_readwrite("edflds", &Text_3d::edflds);
    c017.def_property("string",
        [](Text_3d& self) {return py::array_t<VariChar>{ self.numchars, self.string, py::cast(self)}; },
        [](Text_3d& self, py::array_t<VariChar> const& arr)
        {
        py::buffer_info buf = arr.request();
        auto* ptr = static_cast<VariChar*>(buf.ptr);

        if (self.numchars != arr.size())
            return;

        memcpy(self.string, ptr, self.numchars * sizeof(VariChar));
        });

    //struct Point_string_2d
    py::class_<Point_string_2d> c018(m, "Point_string_2d");
    c018.def_readwrite("ehdr", &Point_string_2d::ehdr);
    c018.def_readwrite("dhdr", &Point_string_2d::dhdr);
    c018.def_readwrite("numpts", &Point_string_2d::numpts);
    c018.def_readwrite("reserved", &Point_string_2d::reserved);

    c018.def_property("point",
        [](Point_string_2d& self)
        {
        py::list ptArray;
        for (UInt32 i = 0; i < self.numpts; i++)
            ptArray.append(py::cast(self.point[i], py::return_value_policy::reference));
        return ptArray;
        },
        [](Point_string_2d& self, DPoint2dArray const& ptArray)
        {
            size_t validNumber = ptArray.size();
            validNumber = validNumber > self.numpts ? self.numpts : validNumber;

            for (size_t i = 0; i < validNumber; i++)
                self.point[i] = ptArray[i];
        });
    c018.def_property("pointArray",
        [](Point_string_2d& self)
        {
        return py::array_t<DPoint2d>{ self.numpts, self.point, py::cast(self)};
        },
        [](Point_string_2d& self, py::array_t<DPoint2d> const& arr)
        {
        py::buffer_info buf = arr.request();
        auto* ptr = static_cast<DPoint2d*>(buf.ptr);

        if (self.numpts != arr.size())
            return;

        memcpy(self.point, ptr, self.numpts * sizeof(DPoint2d));
        });

    //struct Point_string_3d
    py::class_<Point_string_3d> c019(m, "Point_string_3d");
    c019.def_readwrite("ehdr", &Point_string_3d::ehdr);
    c019.def_readwrite("dhdr", &Point_string_3d::dhdr);
    c019.def_readwrite("numpts", &Point_string_3d::numpts);
    c019.def_readwrite("reserved", &Point_string_3d::reserved);
    c019.def_property("point",
        [](Point_string_3d& self)
        {
        py::list ptArray;
        for (UInt32 i = 0; i < self.numpts; i++)
            ptArray.append(py::cast(self.point[i], py::return_value_policy::reference));
        return ptArray;
        },
        [](Point_string_3d& self, DPoint3dArray const& ptArray)
        {
            size_t validNumber = ptArray.size();
            validNumber = validNumber > self.numpts ? self.numpts : validNumber;

            for (size_t i = 0; i < validNumber; i++)
                self.point[i] = ptArray[i];
        });
    c019.def_property("pointArray",
        [](Point_string_3d& self)
        {
        return py::array_t<DPoint3d>{ self.numpts, self.point, py::cast(self)};
        },
        [](Point_string_3d& self, py::array_t<DPoint3d> const& arr)
        {
        py::buffer_info buf = arr.request();
        auto* ptr = static_cast<DPoint3d*>(buf.ptr);

        if (self.numpts != arr.size())
            return;

        memcpy(self.point, ptr, self.numpts * sizeof(DPoint3d));
        });

    //struct Cone_3d
    py::class_<Cone_3d> c020(m, "Cone_3d");
    c020.def_readwrite("ehdr", &Cone_3d::ehdr);
    c020.def_readwrite("dhdr", &Cone_3d::dhdr);

    //struct Cone_3d_b
    struct Cone_3d_b
        {
        UInt16      type : 3;             // cone type 
        UInt16      rsrv : 12;            // reserved 
        UInt16      surf : 1;             // 0 = solid, 1 = surface 
        };

    py::class_<Cone_3d_b> c0200(c020, "Cone_3d_b");
    c0200.def_property("type", 
        [](Cone_3d_b const& self) {return self.type; },
        [](Cone_3d_b& self, UInt16 value) {self.type = value;});

    c0200.def_property("rsrv",
        [](Cone_3d_b const& self) {return self.rsrv; },
        [](Cone_3d_b& self, UInt16 value) {self.rsrv = value;});

    c0200.def_property("surf",
        [](Cone_3d_b const& self) {return self.surf; },
        [](Cone_3d_b& self, UInt16 value) {self.surf = value;});

    c020.def_property("b",
        [](Cone_3d& self) {return reinterpret_cast<Cone_3d_b*>(&self.b); },
        [](Cone_3d& self, Cone_3d_b const& value) {memcpy (&self.b, &value, sizeof(Cone_3d_b));});

    c020.def_property("quat",
        [](Cone_3d& self) {return py::array_t<T_Adouble>{ 4, self.quat, py::cast(self)}; },
        [](Cone_3d& self, py::array_t<T_Adouble> const& arr)
        {
        py::buffer_info buf = arr.request();
        auto* ptr = static_cast<T_Adouble*>(buf.ptr);

        if (4 != arr.size())
            return;

        memcpy(self.quat, ptr, 4 * sizeof(T_Adouble));
        });

    c020.def_readwrite("center_1", &Cone_3d::center_1);
    c020.def_readwrite("radius_1", &Cone_3d::radius_1);
    c020.def_readwrite("center_2", &Cone_3d::center_2);
    c020.def_readwrite("radius_2", &Cone_3d::radius_2);

    //struct Surface
    py::class_<Surface> c021(m, "Surface");
    c021.def_readwrite("ehdr", &Surface::ehdr);
    c021.def_readwrite("dhdr", &Surface::dhdr);
    c021.def_readwrite("componentCount", &Surface::componentCount);
    c021.def_readwrite("boundelms", &Surface::boundelms);
    c021.def_readwrite("surftype", &Surface::surftype);

    //struct Bspline_pole_2d
    py::class_<Bspline_pole_2d> c022(m, "Bspline_pole_2d");
    c022.def_readwrite("ehdr", &Bspline_pole_2d::ehdr);
    c022.def_readwrite("dhdr", &Bspline_pole_2d::dhdr);
    c022.def_readwrite("numpoles", &Bspline_pole_2d::numpoles);
    c022.def_property("poles",
        [](Bspline_pole_2d& self)
        {
        py::list ptArray;
        for (UInt32 i = 0; i < self.numpoles; i++)
            ptArray.append(py::cast(self.poles[i], py::return_value_policy::reference));
        return ptArray;
        },
        [](Bspline_pole_2d& self, DPoint2dArray const& ptArray)
        {
            size_t validNumber = ptArray.size();
            validNumber = validNumber > self.numpoles ? self.numpoles : validNumber;

            for (size_t i = 0; i < validNumber; i++)
                self.poles[i] = ptArray[i];
        });
    c022.def_property("poleArray",
        [](Bspline_pole_2d& self)
        {
        return py::array_t<DPoint2d>{ self.numpoles, self.poles, py::cast(self)};
        },
        [](Bspline_pole_2d& self, py::array_t<DPoint2d> const& arr)
        {
        py::buffer_info buf = arr.request();
        auto* ptr = static_cast<DPoint2d*>(buf.ptr);

        if (self.numpoles != arr.size())
            return;

        memcpy(self.poles, ptr, self.numpoles * sizeof(DPoint2d));
        });

    //struct bspline_pole_3d
    py::class_<Bspline_pole_3d> c023(m, "Bspline_pole_3d");
    c023.def_readwrite("ehdr", &Bspline_pole_3d::ehdr);
    c023.def_readwrite("dhdr", &Bspline_pole_3d::dhdr);
    c023.def_readwrite("numpoles", &Bspline_pole_3d::numpoles);
    c023.def_readwrite("reserved", &Bspline_pole_3d::reserved);
    c023.def_property("poles",
        [](Bspline_pole_3d& self)
        {
        py::list ptArray;
        for (UInt32 i = 0; i < self.numpoles; i++)
            ptArray.append(py::cast(self.poles[i], py::return_value_policy::reference));
        return ptArray;
        },
        [](Bspline_pole_3d& self, DPoint3dArray const& ptArray)
        {
            size_t validNumber = ptArray.size();
            validNumber = validNumber > self.numpoles ? self.numpoles : validNumber;

            for (size_t i = 0; i < validNumber; i++)
                self.poles[i] = ptArray[i];
        });
    c023.def_property("poleArray",
        [](Bspline_pole_3d& self)
        {
        return py::array_t<DPoint3d>{ self.numpoles, self.poles, py::cast(self)};
        },
        [](Bspline_pole_2d& self, py::array_t<DPoint3d> const& arr)
        {
        py::buffer_info buf = arr.request();
        auto* ptr = static_cast<DPoint3d*>(buf.ptr);

        if (self.numpoles != arr.size())
            return;

        memcpy(self.poles, ptr, self.numpoles * sizeof(DPoint3d));
        });

    //struct Bspline_flags
    py::class_<Bspline_flags> c0240(m, "Bspline_flags");
    c0240.def_property("order",
        [](Bspline_flags const& self) {return self.order; },
        [](Bspline_flags& self, UInt32 value) {self.order = value; });

    c0240.def_property("curve_display",
        [](Bspline_flags const& self) {return self.curve_display; },
        [](Bspline_flags& self, UInt32 value) {self.curve_display = value; });

    c0240.def_property("poly_display",
        [](Bspline_flags const& self) {return self.poly_display; },
        [](Bspline_flags& self, UInt32 value) {self.poly_display = value; });

    c0240.def_property("rational",
        [](Bspline_flags const& self) {return self.rational; },
        [](Bspline_flags& self, UInt32 value) {self.rational = value; });

    c0240.def_property("closed",
        [](Bspline_flags const& self) {return self.closed; },
        [](Bspline_flags& self, UInt32 value) {self.closed = value; });

    c0240.def_property("curve_type",
        [](Bspline_flags const& self) {return self.curve_type; },
        [](Bspline_flags& self, UInt32 value) {self.curve_type = value; });

    c0240.def_property("construct_type",
        [](Bspline_flags const& self) {return self.construct_type; },
        [](Bspline_flags& self, UInt32 value) {self.construct_type = value; });

    c0240.def_property("isNaturalTangents",
        [](Bspline_flags const& self) {return self.isNaturalTangents; },
        [](Bspline_flags& self, UInt32 value) {self.isNaturalTangents = value; });

    c0240.def_property("isChordLenTangents",
        [](Bspline_flags const& self) {return self.isChordLenTangents; },
        [](Bspline_flags& self, UInt32 value) {self.isChordLenTangents = value; });

    c0240.def_property("isColinearTangents",
        [](Bspline_flags const& self) {return self.isColinearTangents; },
        [](Bspline_flags& self, UInt32 value) {self.isColinearTangents = value; });

    c0240.def_property("isChordLenKnots",
        [](Bspline_flags const& self) {return self.isChordLenKnots; },
        [](Bspline_flags& self, UInt32 value) {self.isChordLenKnots = value; });

    c0240.def_property("isZeroStartTangent",
        [](Bspline_flags const& self) {return self.isZeroStartTangent; },
        [](Bspline_flags& self, UInt32 value) {self.isZeroStartTangent = value; });

    c0240.def_property("isZeroEndTangent",
        [](Bspline_flags const& self) {return self.isZeroEndTangent; },
        [](Bspline_flags& self, UInt32 value) {self.isZeroEndTangent = value; });

    c0240.def_property("storeFullKnots",
        [](Bspline_flags const& self) {return self.storeFullKnots; },
        [](Bspline_flags& self, UInt32 value) {self.storeFullKnots = value; });

    c0240.def_property("reserved",
        [](Bspline_flags const& self) {return self.reserved; },
        [](Bspline_flags& self, UInt32 value) {self.reserved = value; });

    //struct Bspline_curve
    py::class_<Bspline_curve> c024(m, "Bspline_curve");
    c024.def_readwrite("ehdr", &Bspline_curve::ehdr);
    c024.def_readwrite("dhdr", &Bspline_curve::dhdr);
    c024.def_readwrite("componentCount", &Bspline_curve::componentCount);
    c024.def_readwrite("flags", &Bspline_curve::flags);
    c024.def_readwrite("num_poles", &Bspline_curve::num_poles);
    c024.def_readwrite("num_knots", &Bspline_curve::num_knots);

    //struct Bsurf_flags
    py::class_<Bsurf_flags> c0250(m, "Bsurf_flags");
    c0250.def_property("v_order",
        [](Bsurf_flags const& self) {return self.v_order; },
        [](Bsurf_flags& self, UInt32 value) {self.v_order = value; });

    c0250.def_property("arcSpacing",
        [](Bsurf_flags const& self) {return self.arcSpacing; },
        [](Bsurf_flags& self, UInt32 value) {self.arcSpacing = value; });

    c0250.def_property("v_closed",
        [](Bsurf_flags const& self) {return self.v_closed; },
        [](Bsurf_flags& self, UInt32 value) {self.v_closed = value; });

    c0250.def_property("storeFullKnots",
        [](Bsurf_flags const& self) {return self.storeFullKnots; },
        [](Bsurf_flags& self, UInt32 value) {self.storeFullKnots = value; });

    c0250.def_property("reserved",
        [](Bsurf_flags const& self) {return self.reserved; },
        [](Bsurf_flags& self, UInt32 value) {self.reserved = value; });

    //struct Bspline_surface
    py::class_<Bspline_surface> c025(m, "Bspline_surface");
    c025.def_readwrite("ehdr", &Bspline_surface::ehdr);
    c025.def_readwrite("dhdr", &Bspline_surface::dhdr);
    c025.def_readwrite("componentCount", &Bspline_surface::componentCount);
    c025.def_readwrite("flags", &Bspline_surface::flags);
    c025.def_readwrite("num_poles_u", &Bspline_surface::num_poles_u);
    c025.def_readwrite("num_knots_u", &Bspline_surface::num_knots_u);
    c025.def_readwrite("rule_lines_u", &Bspline_surface::rule_lines_u);
    c025.def_readwrite("bsurf_flags", &Bspline_surface::bsurf_flags);
    c025.def_readwrite("num_poles_v", &Bspline_surface::num_poles_v);
    c025.def_readwrite("num_knots_v", &Bspline_surface::num_knots_v);
    c025.def_readwrite("rule_lines_v", &Bspline_surface::rule_lines_v);
    c025.def_readwrite("num_bounds", &Bspline_surface::num_bounds);

    //struct Bspline_weight
    py::class_<Bspline_weight> c026(m, "Bspline_weight");
    c026.def_readwrite("ehdr", &Bspline_weight::ehdr);
    c026.def_property_readonly("weights",
            [](Bspline_weight& self) {return self.weights;});

    //struct Bspline_knot
    py::class_<Bspline_knot> c027(m, "Bspline_knot");
    c027.def_readwrite("ehdr", &Bspline_knot::ehdr);
    c027.def_property_readonly("knots",
        [](Bspline_knot& self) {return self.knots;});

    //struct Bsurf_boundary
    py::class_<Bsurf_boundary> c028(m, "Bsurf_boundary");
    c028.def_readwrite("ehdr", &Bsurf_boundary::ehdr);
    c028.def_readwrite("number", &Bsurf_boundary::number);
    c028.def_readwrite("numverts", &Bsurf_boundary::numverts);
    c028.def_property("vertices",
        [](Bsurf_boundary& self)
        {
        py::list ptArray;
        for (UInt32 i = 0; i < self.numverts; i++)
            ptArray.append(py::cast(self.vertices[i], py::return_value_policy::reference));
        return ptArray;
        }, 
        [](Bsurf_boundary& self, DPoint2dArray const& ptArray)
        {
            size_t validNumber = ptArray.size();
            validNumber = validNumber > self.numverts ? self.numverts : validNumber;

            for (size_t i = 0; i < validNumber; i++)
                self.vertices[i] = ptArray[i];
        });
    c028.def_property("verticeArray",
        [](Bsurf_boundary& self)
        {
        return py::array_t<DPoint2d>{ self.numverts, self.vertices, py::cast(self)};
        },
        [](Bsurf_boundary& self, py::array_t<DPoint2d> const& arr)
        {
        py::buffer_info buf = arr.request();
        auto* ptr = static_cast<DPoint2d*>(buf.ptr);

        if (self.numverts != arr.size())
            return;

        memcpy(self.vertices, ptr, self.numverts * sizeof(DPoint2d));
        });

    //struct Raster_flags_b
    struct Raster_flags_b
        {
        unsigned    right : 1;
        unsigned    lower : 1;
        unsigned    horizontal : 1;
        unsigned    format : 5;
        unsigned    color : 1;
        unsigned    transparent : 1;
        unsigned    positive : 1;
        unsigned    unused : 5;
        };

    //struct Raster_flags
    py::class_<Raster_flags> c029(m, "Raster_flags");

    py::class_<Raster_flags_b> c0290(c029, "Raster_flags_b");
    c0290.def_property("right",
        [](Raster_flags_b const& self) {return self.right; },
        [](Raster_flags_b& self, unsigned value) {self.right = value; });

    c0290.def_property("lower",
        [](Raster_flags_b const& self) {return self.lower; },
        [](Raster_flags_b& self, unsigned value) {self.lower = value; });

    c0290.def_property("horizontal",
        [](Raster_flags_b const& self) {return self.horizontal; },
        [](Raster_flags_b& self, unsigned value) {self.horizontal = value; });

    c0290.def_property("format",
        [](Raster_flags_b const& self) {return self.format; },
        [](Raster_flags_b& self, unsigned value) {self.format = value; });

    c0290.def_property("color",
        [](Raster_flags_b const& self) {return self.color; },
        [](Raster_flags_b& self, unsigned value) {self.color = value; });

    c0290.def_property("transparent",
        [](Raster_flags_b const& self) {return self.transparent; },
        [](Raster_flags_b& self, unsigned value) {self.transparent = value; });

    c0290.def_property("positive",
        [](Raster_flags_b const& self) {return self.positive; },
        [](Raster_flags_b& self, unsigned value) {self.positive = value; });

    c029.def_property("b",
        [](Raster_flags& self) {return reinterpret_cast<Raster_flags_b*>(&self.b); },
        [](Raster_flags& self, Raster_flags_b const& value) {memcpy(&self.b, &value, sizeof(Raster_flags_b));});

    c029.def_property("s",
        [](Raster_flags& self) {return self.s; },
        [](Raster_flags& self, Int16 value) { self.s = value;});

    //struct Raster_hdr
    py::class_<Raster_hdr> c030(m, "Raster_hdr");
    c030.def_readwrite("ehdr", &Raster_hdr::ehdr);
    c030.def_readwrite("dhdr", &Raster_hdr::dhdr);
    c030.def_readwrite("componentCount", &Raster_hdr::componentCount);
    c030.def_readwrite("flags", &Raster_hdr::flags);
    c030.def_readwrite("background", &Raster_hdr::background);
    c030.def_readwrite("foreground", &Raster_hdr::foreground);
    c030.def_readwrite("xextent", &Raster_hdr::xextent);
    c030.def_readwrite("yextent", &Raster_hdr::yextent);
    c030.def_readwrite("reserved", &Raster_hdr::reserved);
    c030.def_readwrite("resolution", &Raster_hdr::resolution);
    c030.def_readwrite("scale", &Raster_hdr::scale);
    c030.def_readwrite("origin", &Raster_hdr::origin);
    c030.def_readwrite("numverts", &Raster_hdr::numverts);
    c030.def_readwrite("reserved2", &Raster_hdr::reserved2);
    c030.def_property("vertex",
        [](Raster_hdr& self)
        {
        py::list ptArray;
        for (UInt32 i = 0; i < self.numverts; i++)
            {
            if (self.dhdr.props.b.is3d)
                ptArray.append(py::cast(self.u.vert3d[i], py::return_value_policy::reference));
            else
                ptArray.append(py::cast(self.u.vert2d[i], py::return_value_policy::reference));
            }
        return ptArray;
        },
        [](Raster_hdr& self, const py::list& ptArray)
            {
            size_t validNumber = ptArray.size();
            validNumber = validNumber > self.numverts ? self.numverts : validNumber;

            for (size_t i = 0; i < validNumber; i++)
                {
                try
                    {
                    if (self.dhdr.props.b.is3d)
                        self.u.vert3d[i] = ptArray[i].cast<DPoint3d>();
                    else
                        self.u.vert2d[i] = ptArray[i].cast<DPoint2d>();
                    }
                catch (...) //once call to cast<>() fails, an exception throwed
                    {
                    return;
                    }
                }
             });

    //struct Raster_comp
    py::class_<Raster_comp> c031(m, "Raster_comp");
    c031.def_readwrite("ehdr", &Raster_comp::ehdr);
    c031.def_readwrite("dhdr", &Raster_comp::dhdr);
    c031.def_readwrite("flags", &Raster_comp::flags);
    c031.def_readwrite("background", &Raster_comp::background);
    c031.def_readwrite("foreground", &Raster_comp::foreground);
    c031.def_readwrite("xoffset", &Raster_comp::xoffset);
    c031.def_readwrite("yoffset", &Raster_comp::yoffset);
    c031.def_readwrite("numpixels", &Raster_comp::numpixels);
    c031.def_property("pixel",
        [](Raster_comp& self) {return py::array_t<Byte>{ 4, self.pixel, py::cast(self)}; },
        [](Raster_comp& self, py::array_t<Byte> const& arr) 
        {
        py::buffer_info buf = arr.request();
        auto* ptr = static_cast<Byte*>(buf.ptr);

        if (4 != arr.size())
            return;

        memcpy(self.pixel, ptr, 4 * sizeof(Byte));
        });

    //struct applicationElm
    py::class_<ApplicationElm> c032(m, "ApplicationElm");
    c032.def_readwrite("ehdr", &ApplicationElm::ehdr);
    c032.def_readwrite("signatureWord", &ApplicationElm::signatureWord);
    c032.def_property_readonly("appData",
        [](ApplicationElm& self) {return self.appData;});

    //struct ColorTable
    py::class_<ColorTable> c033(m, "ColorTable");
    c033.def_readwrite("ehdr", &ColorTable::ehdr);
    c033.def_readwrite("signatureWord", &ColorTable::screen_flag);
    c033.def_property_readonly("color_info",
        [](ColorTable& self) {return self.color_info;});

    //struct ViewFlags
    py::class_<ViewFlags> c035(m, "ViewFlags");
    c035.def_property("deprecated1",
        [](ViewFlags const& self) {return self.deprecated1; },
        [](ViewFlags& self, UInt32 value) {self.deprecated1 = value; });
    c035.def_property("fast_text",
        [](ViewFlags const& self) {return self.fast_text; },
        [](ViewFlags& self, UInt32 value) {self.fast_text = value; });
    c035.def_property("deprecated2",
        [](ViewFlags const& self) {return self.deprecated2; },
        [](ViewFlags& self, UInt32 value) {self.deprecated2 = value; });
    c035.def_property("line_wghts",
        [](ViewFlags const& self) {return self.line_wghts; },
        [](ViewFlags& self, UInt32 value) {self.line_wghts = value; });
    c035.def_property("patterns",
        [](ViewFlags const& self) {return self.patterns; },
        [](ViewFlags& self, UInt32 value) {self.patterns = value; });
    c035.def_property("text_nodes",
        [](ViewFlags const& self) {return self.text_nodes; },
        [](ViewFlags& self, UInt32 value) {self.text_nodes = value; });
    c035.def_property("ed_fields",
        [](ViewFlags const& self) {return self.ed_fields; },
        [](ViewFlags& self, UInt32 value) {self.ed_fields = value; });
    c035.def_property("on_off",
        [](ViewFlags const& self) {return self.on_off; },
        [](ViewFlags& self, UInt32 value) {self.on_off = value; });
    c035.def_property("deprecated3",
        [](ViewFlags const& self) {return self.deprecated3; },
        [](ViewFlags& self, UInt32 value) {self.deprecated3 = value; });
    c035.def_property("grid",
        [](ViewFlags const& self) {return self.grid; },
        [](ViewFlags& self, UInt32 value) {self.grid = value; });
    c035.def_property("lev_symb",
        [](ViewFlags const& self) {return self.lev_symb; },
        [](ViewFlags& self, UInt32 value) {self.lev_symb = value; });
    c035.def_property("deprecated4",
        [](ViewFlags const& self) {return self.deprecated4; },
        [](ViewFlags& self, UInt32 value) {self.deprecated4 = value; });
    c035.def_property("constructs",
        [](ViewFlags const& self) {return self.constructs; },
        [](ViewFlags& self, UInt32 value) {self.constructs = value; });
    c035.def_property("dimens",
        [](ViewFlags const& self) {return self.dimens; },
        [](ViewFlags& self, UInt32 value) {self.dimens = value; });
    c035.def_property("fast_cell",
        [](ViewFlags const& self) {return self.fast_cell; },
        [](ViewFlags& self, UInt32 value) {self.fast_cell = value; });
    c035.def_property("def",
        [](ViewFlags const& self) {return self.def; },
        [](ViewFlags& self, UInt32 value) {self.def = value; });
    c035.def_property("fill",
        [](ViewFlags const& self) {return self.fill; },
        [](ViewFlags& self, UInt32 value) {self.fill = value; });
    c035.def_property("deprecated5",
        [](ViewFlags const& self) {return self.deprecated5; },
        [](ViewFlags& self, UInt32 value) {self.deprecated5 = value; });
    c035.def_property("auxDisplay",
        [](ViewFlags const& self) {return self.auxDisplay; },
        [](ViewFlags& self, UInt32 value) {self.auxDisplay = value; });
    c035.def_property("deprecated6",
        [](ViewFlags const& self) {return self.deprecated6; },
        [](ViewFlags& self, UInt32 value) {self.deprecated6 = value; });
    c035.def_property("deprecated7",
        [](ViewFlags const& self) {return self.deprecated7; },
        [](ViewFlags& self, UInt32 value) {self.deprecated7 = value; });
    c035.def_property("hideNamedPresentation",
        [](ViewFlags const& self) {return self.hideNamedPresentation; },
        [](ViewFlags& self, UInt32 value) {self.hideNamedPresentation = value; });
    c035.def_property("camera",
        [](ViewFlags const& self) {return self.camera; },
        [](ViewFlags& self, UInt32 value) {self.camera = value; });
    c035.def_property("renderMode",
        [](ViewFlags const& self) {return self.renderMode; },
        [](ViewFlags& self, UInt32 value) {self.renderMode = value; });
    c035.def_property("background",
        [](ViewFlags const& self) {return self.background; },
        [](ViewFlags& self, UInt32 value) {self.background = value; });
    c035.def_property("refBoundaryDisplay",
        [](ViewFlags const& self) {return self.refBoundaryDisplay; },
        [](ViewFlags& self, UInt32 value) {self.refBoundaryDisplay = value; });
    c035.def_property("deprecated8",
        [](ViewFlags const& self) {return self.deprecated8; },
        [](ViewFlags& self, UInt32 value) {self.deprecated8 = value; });
    c035.def_property("deprecated9",
        [](ViewFlags const& self) {return self.deprecated9; },
        [](ViewFlags& self, UInt32 value) {self.deprecated9 = value; });
    c035.def_property("deprecated10",
        [](ViewFlags const& self) {return self.deprecated10; },
        [](ViewFlags& self, UInt32 value) {self.deprecated10 = value; });
    c035.def_property("deprecated11",
        [](ViewFlags const& self) {return self.deprecated11; },
        [](ViewFlags& self, UInt32 value) {self.deprecated11 = value; });
    c035.def_property("deprecated12",
        [](ViewFlags const& self) {return self.deprecated12; },
        [](ViewFlags& self, UInt32 value) {self.deprecated12 = value; });
    c035.def_property("textureMaps",
        [](ViewFlags const& self) {return self.textureMaps; },
        [](ViewFlags& self, UInt32 value) {self.textureMaps = value; });
    c035.def_property("deprecated13",
        [](ViewFlags const& self) {return self.deprecated13; },
        [](ViewFlags& self, UInt32 value) {self.deprecated13 = value; });
    c035.def_property("transparency",
        [](ViewFlags const& self) {return self.transparency; },
        [](ViewFlags& self, UInt32 value) {self.transparency = value; });
    c035.def_property("deprecated14",
        [](ViewFlags const& self) {return self.deprecated14; },
        [](ViewFlags& self, UInt32 value) {self.deprecated14 = value; });
    c035.def_property("inhibitLineStyles",
        [](ViewFlags const& self) {return self.inhibitLineStyles; },
        [](ViewFlags& self, UInt32 value) {self.inhibitLineStyles = value; });
    c035.def_property("deprecated15",
        [](ViewFlags const& self) {return self.deprecated15; },
        [](ViewFlags& self, UInt32 value) {self.deprecated15 = value; });
    c035.def_property("patternDynamics",
        [](ViewFlags const& self) {return self.patternDynamics; },
        [](ViewFlags& self, UInt32 value) {self.patternDynamics = value; });
    c035.def_property("deprecated16",
        [](ViewFlags const& self) {return self.deprecated16; },
        [](ViewFlags& self, UInt32 value) {self.deprecated16 = value; });
    c035.def_property("tagsOff",
        [](ViewFlags const& self) {return self.tagsOff; },
        [](ViewFlags& self, UInt32 value) {self.tagsOff = value; });
    c035.def_property("renderDisplayEdges",
        [](ViewFlags const& self) {return self.renderDisplayEdges; },
        [](ViewFlags& self, UInt32 value) {self.renderDisplayEdges = value; });
    c035.def_property("renderDisplayHidden",
        [](ViewFlags const& self) {return self.renderDisplayHidden; },
        [](ViewFlags& self, UInt32 value) {self.renderDisplayHidden = value; });
    c035.def_property("isNamed_deprecated",
        [](ViewFlags const& self) {return self.isNamed_deprecated; },
        [](ViewFlags& self, UInt32 value) {self.isNamed_deprecated = value; });
    c035.def_property("deprecated17",
        [](ViewFlags const& self) {return self.deprecated17; },
        [](ViewFlags& self, UInt32 value) {self.deprecated17 = value; });
    c035.def_property("overrideBackground",
        [](ViewFlags const& self) {return self.overrideBackground; },
        [](ViewFlags& self, UInt32 value) {self.overrideBackground = value; });
    c035.def_property("noFrontClip",
        [](ViewFlags const& self) {return self.noFrontClip; },
        [](ViewFlags& self, UInt32 value) {self.noFrontClip = value; });
    c035.def_property("noBackClip",
        [](ViewFlags const& self) {return self.noBackClip; },
        [](ViewFlags& self, UInt32 value) {self.noBackClip = value; });
    c035.def_property("noClipVolume",
        [](ViewFlags const& self) {return self.noClipVolume; },
        [](ViewFlags& self, UInt32 value) {self.noClipVolume = value; });
    c035.def_property("useDisplaySet",
        [](ViewFlags const& self) {return self.useDisplaySet; },
        [](ViewFlags& self, UInt32 value) {self.useDisplaySet = value; });
    c035.def_property("associativeClip",
        [](ViewFlags const& self) {return self.associativeClip; },
        [](ViewFlags& self, UInt32 value) {self.associativeClip = value; });
    c035.def_property("minimized",
        [](ViewFlags const& self) {return self.minimized; },
        [](ViewFlags& self, UInt32 value) {self.minimized = value; });
    c035.def_property("maximized",
        [](ViewFlags const& self) {return self.maximized; },
        [](ViewFlags& self, UInt32 value) {self.maximized = value; });
    c035.def_property("renderDisplayShadows",
        [](ViewFlags const& self) {return self.renderDisplayShadows; },
        [](ViewFlags& self, UInt32 value) {self.renderDisplayShadows = value; });
    c035.def_property("disableHeightMaps",
        [](ViewFlags const& self) {return self.disableHeightMaps; },
        [](ViewFlags& self, UInt32 value) {self.disableHeightMaps = value; });
    c035.def_property("hiddenLineStyle",
        [](ViewFlags const& self) {return self.hiddenLineStyle; },
        [](ViewFlags& self, UInt32 value) {self.hiddenLineStyle = value; });
    c035.def_property("inhibitRenderMaterials",
        [](ViewFlags const& self) {return self.inhibitRenderMaterials; },
        [](ViewFlags& self, UInt32 value) {self.inhibitRenderMaterials = value; });
    c035.def_property("ignoreSceneLights",
        [](ViewFlags const& self) {return self.ignoreSceneLights; },
        [](ViewFlags& self, UInt32 value) {self.ignoreSceneLights = value; });
    c035.def_property("displayPlacementPoint",
        [](ViewFlags const& self) {return self.displayPlacementPoint; },
        [](ViewFlags& self, UInt32 value) {self.displayPlacementPoint = value; });
    c035.def_property("itemtypetext",
        [](ViewFlags const& self) {return self.itemtypetext; },
        [](ViewFlags& self, UInt32 value) {self.itemtypetext = value; });
    c035.def_property("hideTextFieldBkgrnd",
        [](ViewFlags const& self) {return self.hideTextFieldBkgrnd; },
        [](ViewFlags& self, UInt32 value) {self.hideTextFieldBkgrnd = value; });
    c035.def_property("reserved3",
        [](ViewFlags const& self) {return self.reserved3; },
        [](ViewFlags& self, UInt32 value) {self.reserved3 = value; });

#if defined (__cplusplus)
    c035.def("SetRenderMode", &ViewFlags::SetRenderMode, "value"_a);
    c035.def("GetRenderMode", &ViewFlags::GetRenderMode);
#endif

    //struct Fb_opts
    py::class_<Fb_opts> c036(m, "Fb_opts");
    c036.def_property("one_one_map",
        [](Fb_opts const& self) {return self.one_one_map; },
        [](Fb_opts& self, UInt32 value) {self.one_one_map = value; });
    c036.def_property("db_diff_mf",
        [](Fb_opts const& self) {return self.db_diff_mf; },
        [](Fb_opts& self, UInt32 value) {self.db_diff_mf = value; });
    c036.def_property("snap_lock",
        [](Fb_opts const& self) {return self.snap_lock; },
        [](Fb_opts& self, UInt32 value) {self.snap_lock = value; });
    c036.def_property("locate_lock",
        [](Fb_opts const& self) {return self.locate_lock; },
        [](Fb_opts& self, UInt32 value) {self.locate_lock = value; });
    c036.def_property("hLineAttachment",
        [](Fb_opts const& self) {return self.hLineAttachment; },
        [](Fb_opts& self, UInt32 value) {self.hLineAttachment = value; });
    c036.def_property("completePathStoredInV7",
        [](Fb_opts const& self) {return self.completePathStoredInV7; },
        [](Fb_opts& self, UInt32 value) {self.completePathStoredInV7 = value; });
    c036.def_property("anonymous",
        [](Fb_opts const& self) {return self.anonymous; },
        [](Fb_opts& self, UInt32 value) {self.anonymous = value; });
    c036.def_property("inactive",
        [](Fb_opts const& self) {return self.inactive; },
        [](Fb_opts& self, UInt32 value) {self.inactive = value; });
    c036.def_property("synchPresentationWithNamedView",
        [](Fb_opts const& self) {return self.synchPresentationWithNamedView; },
        [](Fb_opts& self, UInt32 value) {self.synchPresentationWithNamedView = value; });
    c036.def_property("missing_file",
        [](Fb_opts const& self) {return self.missing_file; },
        [](Fb_opts& self, UInt32 value) {self.missing_file = value; });
    c036.def_property("levelOverride",
        [](Fb_opts const& self) {return self.levelOverride; },
        [](Fb_opts& self, UInt32 value) {self.levelOverride = value; });
    c036.def_property("dontDetachOnAll",
        [](Fb_opts const& self) {return self.dontDetachOnAll; },
        [](Fb_opts& self, UInt32 value) {self.dontDetachOnAll = value; });
    c036.def_property("metadataOnly",
        [](Fb_opts const& self) {return self.metadataOnly; },
        [](Fb_opts& self, UInt32 value) {self.metadataOnly = value; });
    c036.def_property("attachmentFromDWG",
        [](Fb_opts const& self) {return self.attachmentFromDWG; },
        [](Fb_opts& self, UInt32 value) {self.attachmentFromDWG = value; });
    c036.def_property("treatAsElement",
        [](Fb_opts const& self) {return self.treatAsElement; },
        [](Fb_opts& self, UInt32 value) {self.treatAsElement = value; });
    c036.def_property("deprecated",
        [](Fb_opts const& self) {return self.deprecated; },
        [](Fb_opts& self, UInt32 value) {self.deprecated = value; });
    c036.def_property("attachMethod",
        [](Fb_opts const& self) {return self.attachMethod; },
        [](Fb_opts& self, UInt32 value) {self.attachMethod = value; });
    c036.def_property("useViewFlagsInAttachment",
        [](Fb_opts const& self) {return self.useViewFlagsInAttachment; },
        [](Fb_opts& self, UInt32 value) {self.useViewFlagsInAttachment = value; });
    c036.def_property("synchWithNamedView",
        [](Fb_opts const& self) {return self.synchWithNamedView; },
        [](Fb_opts& self, UInt32 value) {self.synchWithNamedView = value; });
    c036.def_property("levelControlsDisplay",
        [](Fb_opts const& self) {return self.levelControlsDisplay; },
        [](Fb_opts& self, UInt32 value) {self.levelControlsDisplay = value; });
    c036.def_property("useAnnotationScale",
        [](Fb_opts const& self) {return self.useAnnotationScale; },
        [](Fb_opts& self, UInt32 value) {self.useAnnotationScale = value; });
    c036.def_property("isAnnotationAttachment",
        [](Fb_opts const& self) {return self.isAnnotationAttachment; },
        [](Fb_opts& self, UInt32 value) {self.isAnnotationAttachment = value; });
    c036.def_property("userSpecifiedZForGeoReprojected",
        [](Fb_opts const& self) {return self.userSpecifiedZForGeoReprojected; },
        [](Fb_opts& self, UInt32 value) {self.userSpecifiedZForGeoReprojected = value; });
    c036.def_property("applicationLocked",
        [](Fb_opts const& self) {return self.applicationLocked; },
        [](Fb_opts& self, UInt32 value) {self.applicationLocked = value; });
    c036.def_property("synchVolumeWithNamedView",
        [](Fb_opts const& self) {return self.synchVolumeWithNamedView; },
        [](Fb_opts& self, UInt32 value) {self.synchVolumeWithNamedView = value; });

    //struct Fd_opts
    py::class_<Fd_opts> c037(m, "Fd_opts");
    c037.def_property("view_ovr",
        [](Fd_opts const& self) {return self.view_ovr; },
        [](Fd_opts& self, UInt32 value) {self.view_ovr = value; });
    c037.def_property("display",
        [](Fd_opts const& self) {return self.display; },
        [](Fd_opts& self, UInt32 value) {self.display = value; });
    c037.def_property("line_width",
        [](Fd_opts const& self) {return self.line_width; },
        [](Fd_opts& self, UInt32 value) {self.line_width = value; });
    c037.def_property("lstyleScale",
        [](Fd_opts const& self) {return self.lstyleScale; },
        [](Fd_opts& self, UInt32 value) {self.lstyleScale = value; });
    c037.def_property("hiddenLine",
        [](Fd_opts const& self) {return self.hiddenLine; },
        [](Fd_opts& self, UInt32 value) {self.hiddenLine = value; });
    c037.def_property("displayHidden",
        [](Fd_opts const& self) {return self.displayHidden; },
        [](Fd_opts& self, UInt32 value) {self.displayHidden = value; });
    c037.def_property("surrogateHLine",
        [](Fd_opts const& self) {return self.surrogateHLine; },
        [](Fd_opts& self, UInt32 value) {self.surrogateHLine = value; });
    c037.def_property("rotateClipping",
        [](Fd_opts const& self) {return self.rotateClipping; },
        [](Fd_opts& self, UInt32 value) {self.rotateClipping = value; });
    c037.def_property("smoothEdges",
        [](Fd_opts const& self) {return self.smoothEdges; },
        [](Fd_opts& self, UInt32 value) {self.smoothEdges = value; });
    c037.def_property("extendedRef",
        [](Fd_opts const& self) {return self.extendedRef; },
        [](Fd_opts& self, UInt32 value) {self.extendedRef = value; });
    c037.def_property("clipBack",
        [](Fd_opts const& self) {return self.clipBack; },
        [](Fd_opts& self, UInt32 value) {self.clipBack = value; });
    c037.def_property("clipFront",
        [](Fd_opts const& self) {return self.clipFront; },
        [](Fd_opts& self, UInt32 value) {self.clipFront = value; });
    c037.def_property("cameraOn",
        [](Fd_opts const& self) {return self.cameraOn; },
        [](Fd_opts& self, UInt32 value) {self.cameraOn = value; });
    c037.def_property("scaleByUnits",
        [](Fd_opts const& self) {return self.scaleByUnits; },
        [](Fd_opts& self, UInt32 value) {self.scaleByUnits = value; });
    c037.def_property("displayBoundary",
        [](Fd_opts const& self) {return self.displayBoundary; },
        [](Fd_opts& self, UInt32 value) {self.displayBoundary = value; });
    c037.def_property("libraryRef",
        [](Fd_opts const& self) {return self.libraryRef; },
        [](Fd_opts& self, UInt32 value) {self.libraryRef = value; });
    c037.def_property("displayRasterRefs",
        [](Fd_opts const& self) {return self.displayRasterRefs; },
        [](Fd_opts& self, UInt32 value) {self.displayRasterRefs = value; });
    c037.def_property("useAlternateFile",
        [](Fd_opts const& self) {return self.useAlternateFile; },
        [](Fd_opts& self, UInt32 value) {self.useAlternateFile = value; });
    c037.def_property("useLights",
        [](Fd_opts const& self) {return self.useLights; },
        [](Fd_opts& self, UInt32 value) {self.useLights = value; });
    c037.def_property("doNotDisplayAsNested",
        [](Fd_opts const& self) {return self.doNotDisplayAsNested; },
        [](Fd_opts& self, UInt32 value) {self.doNotDisplayAsNested = value; });
    c037.def_property("colorTableUsage",
        [](Fd_opts const& self) {return self.colorTableUsage; },
        [](Fd_opts& self, UInt32 value) {self.colorTableUsage = value; });
    c037.def_property("viewport",
        [](Fd_opts const& self) {return self.viewport; },
        [](Fd_opts& self, UInt32 value) {self.viewport = value; });
    c037.def_property("scaleByStorageUnits",
        [](Fd_opts const& self) {return self.scaleByStorageUnits; },
        [](Fd_opts& self, UInt32 value) {self.scaleByStorageUnits = value; });
    c037.def_property("printColorAdjustment",
        [](Fd_opts const& self) {return self.printColorAdjustment; },
        [](Fd_opts& self, UInt32 value) {self.printColorAdjustment = value; });
    c037.def_property("newLevelDisplay",
        [](Fd_opts const& self) {return self.newLevelDisplay; },
        [](Fd_opts& self, UInt32 value) {self.newLevelDisplay = value; });
    c037.def_property("plot3D",
        [](Fd_opts const& self) {return self.plot3D; },
        [](Fd_opts& self, UInt32 value) {self.plot3D = value; });
    c037.def_property("nestOverrides",
        [](Fd_opts const& self) {return self.nestOverrides; },
        [](Fd_opts& self, UInt32 value) {self.nestOverrides = value; });
    c037.def_property("globalLineStyleScales",
        [](Fd_opts const& self) {return self.globalLineStyleScales; },
        [](Fd_opts& self, UInt32 value) {self.globalLineStyleScales = value; });

    //struct  referenceFileElm
    py::class_<ReferenceFileElm> c034(m, "ReferenceFileElm");
    c034.def_readwrite("ehdr", &ReferenceFileElm::ehdr);
    c034.def_readwrite("componentCount", &ReferenceFileElm::componentCount);
    c034.def_readwrite("version", &ReferenceFileElm::version);
    c034.def_readwrite("groupId", &ReferenceFileElm::groupId);
    c034.def_readwrite("fileNumber", &ReferenceFileElm::fileNumber);
    c034.def_readwrite("parentAttachmentId", &ReferenceFileElm::parentAttachmentId);
    c034.def_readwrite("fb_opts", &ReferenceFileElm::fb_opts);
    c034.def_readwrite("fd_opts", &ReferenceFileElm::fd_opts);
    c034.def_readwrite("priority", &ReferenceFileElm::priority);
    c034.def_property("displayFlags",
        [](ReferenceFileElm& self) {return py::array_t<ViewFlags>{ 8, self.displayFlags, py::cast(self)}; },
        [](ReferenceFileElm& self, py::array_t<ViewFlags> const& arr)
        {
        py::buffer_info buf = arr.request();
        auto* ptr = static_cast<ViewFlags*>(buf.ptr);

        if (8 != arr.size())
            return;

        memcpy(self.displayFlags, ptr, 8 * sizeof(ViewFlags));
        });

    c034.def_readwrite("baseNestDepth", &ReferenceFileElm::baseNestDepth);
    c034.def_readwrite("reserved", &ReferenceFileElm::reserved);
    c034.def_readwrite("refOrigin", &ReferenceFileElm::refOrigin);
    c034.def_readwrite("masterOrigin", &ReferenceFileElm::masterOrigin);
    c034.def_readwrite("transform", &ReferenceFileElm::transform);
    c034.def_readwrite("scale", &ReferenceFileElm::scale);
    c034.def_readwrite("zFront", &ReferenceFileElm::zFront);
    c034.def_readwrite("zBack", &ReferenceFileElm::zBack);
    c034.def_readwrite("cameraPosition", &ReferenceFileElm::cameraPosition);
    c034.def_readwrite("nestDepth", &ReferenceFileElm::nestDepth);
    c034.def_readwrite("reserved1", &ReferenceFileElm::reserved1);
    c034.def_readwrite("foreignUnitMode", &ReferenceFileElm::foreignUnitMode);
    c034.def_readwrite("nClipPoints", &ReferenceFileElm::nClipPoints);
    c034.def_property("clipPoints",
        [](ReferenceFileElm& self)
        {
        py::list ptArray;
        for (UInt32 i = 0; i < self.nClipPoints; i++)
              ptArray.append(py::cast(self.clipPoints[i], py::return_value_policy::reference));
        return ptArray;
        },
        [](ReferenceFileElm& self, DPoint2dArray const& ptArray)
        {
            size_t validNumber = ptArray.size();
            validNumber = validNumber > self.nClipPoints ? self.nClipPoints : validNumber;

            for (size_t i = 0; i < validNumber; i++)
                self.clipPoints[i] = ptArray[i];
        });
    c034.def_property("clipPointArray",
        [](ReferenceFileElm& self)
        {
        return py::array_t<DPoint2d>{ self.nClipPoints, self.clipPoints, py::cast(self)};
        },
        [](ReferenceFileElm& self, py::array_t<DPoint2d> const& arr)
        {
        py::buffer_info buf = arr.request();
        auto* ptr = static_cast<DPoint2d*>(buf.ptr);

        if (self.nClipPoints != arr.size())
            return;

        memcpy(self.clipPoints, ptr, self.nClipPoints * sizeof(DPoint2d));
        });

    //union MSElement
    py::class_<MSElement> c1(m, "MSElement");
    c1.def_property_readonly("ehdr",
        [](MSElement& self) {return &self.ehdr; });

    c1.def_property_readonly("hdr",
        [](MSElement& self) {return &self.hdr; });

    c1.def_property_readonly("cell_2d",
        [](MSElement& self) {return &self.cell_2d; });

    c1.def_property_readonly("cell_3d",
        [](MSElement& self) {return &self.cell_3d; });

    c1.def_property_readonly("line_2d",
        [](MSElement& self) {return &self.line_2d; });

    c1.def_property_readonly("line_3d",
        [](MSElement& self) {return &self.line_3d; });

    c1.def_property_readonly("line_string_2d",
        [](MSElement& self) {return &self.line_string_2d; });

    c1.def_property_readonly("line_string_3d",
        [](MSElement& self) {return &self.line_string_3d; });

    c1.def_property_readonly("text_node_2d",
        [](MSElement& self) {return &self.text_node_2d; });

    c1.def_property_readonly("text_node_3d",
        [](MSElement& self) {return &self.text_node_3d; });

    c1.def_property_readonly("complex_string",
        [](MSElement& self) {return &self.complex_string; });

    c1.def_property_readonly("ellipse_2d",
        [](MSElement& self) {return &self.ellipse_2d; });

    c1.def_property_readonly("ellipse_3d",
        [](MSElement& self) {return &self.ellipse_3d; });

    c1.def_property_readonly("arc_2d",
        [](MSElement& self) {return &self.arc_2d; });

    c1.def_property_readonly("arc_3d",
        [](MSElement& self) {return &self.arc_3d; });

    c1.def_property_readonly("text_2d",
        [](MSElement& self) {return &self.text_2d; });

    c1.def_property_readonly("text_3d",
        [](MSElement& self) {return &self.text_3d; });

    c1.def_property_readonly("point_string_2d",
        [](MSElement& self) {return &self.point_string_2d; });

    c1.def_property_readonly("point_string_3d",
        [](MSElement& self) {return &self.point_string_3d; });

    c1.def_property_readonly("cone_3d",
        [](MSElement& self) {return &self.cone_3d; });

    c1.def_property_readonly("surf",
        [](MSElement& self) {return &self.surf; });

    c1.def_property_readonly("bspline_pole_2d",
        [](MSElement& self) {return &self.bspline_pole_2d; });

    c1.def_property_readonly("bspline_pole_3d",
        [](MSElement& self) {return &self.bspline_pole_3d; });

    c1.def_property_readonly("bspline_curve",
        [](MSElement& self) {return &self.bspline_curve; });

    c1.def_property_readonly("bspline_surface",
        [](MSElement& self) {return &self.bspline_surface; });

    c1.def_property_readonly("bspline_weight",
        [](MSElement& self) {return &self.bspline_weight; });

    c1.def_property_readonly("bspline_knot",
        [](MSElement& self) {return &self.bspline_knot; });

    c1.def_property_readonly("bsurf_boundary",
        [](MSElement& self) {return &self.bsurf_boundary; });

    c1.def_property_readonly("raster_hdr",
        [](MSElement& self) {return &self.raster_hdr; });

    c1.def_property_readonly("raster_comp",
        [](MSElement& self) {return &self.raster_comp; });

    c1.def_property_readonly("applicationElm",
        [](MSElement& self) {return &self.applicationElm; });

    c1.def_property_readonly("colorTable",
        [](MSElement& self) {return &self.colorTable; });

    c1.def_property_readonly("referenceFileElm",
        [](MSElement& self) {return &self.referenceFileElm; });

    c1.def(py::init([] () { return new MSElement(); }));
    c1.def("Size", &MSElement::Size);
    c1.def("CopyTo", &MSElement::CopyTo, "rhs"_a);
    c1.def("GetID", &MSElement::GetID);
    c1.def("IsComplexHeader", &MSElement::IsComplexHeader);

    c1.def_property_readonly("ComplexComponentCount", &MSElement::GetComplexComponentCount);
    c1.def("GetComplexComponentCount", &MSElement::GetComplexComponentCount);
    }
