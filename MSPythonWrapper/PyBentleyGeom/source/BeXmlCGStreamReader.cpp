#include "MSPythonPCH.h"
#include <GeomSerialization\BeXmlCommonGeometry.h>

void def_XmlCGStreamReader(py::module_& m)
    {
    //===================================================================================
    // struct BeExtendedDataEntry
    py::class_<BeExtendedDataEntry> c1(m, "BeExtendedDataEntry");
    c1.def (py::init<>());
    c1.def_readwrite ("Key", &BeExtendedDataEntry::Key);
    c1.def_readwrite ("Type", &BeExtendedDataEntry::Type);
    c1.def_readwrite ("Value", &BeExtendedDataEntry::Value);

    py::bind_vector<BeExtendedData>(m, "BeExtendedData", py::module_local(false));
    py::bind_vector<bvector<IGeometryPtr>>(m, "IGeometryPtrArray", py::module_local(false));
    py::bind_map<BeExtendedDataGeometryMap>(m, "BeExtendedDataGeometryMap", py::module_local(false));

    //===================================================================================
    // struct BeXmlCGStreamReader
    py::class_<BeXmlCGStreamReader> c2(m, "BeXmlCGStreamReader");
    c2.def_static("TryParse", py::overload_cast<Utf8CP, bvector<IGeometryPtr>&, BeExtendedDataGeometryMap&, size_t>(&BeXmlCGStreamReader::TryParse), "beXmlCGString"_a, "geometry"_a, "extendedData"_a, "maxDepth"_a = INT_MAX);
    c2.def_static("TryParse", ([](bvector<Byte>& buffer, bvector<IGeometryPtr>& geometry, BeExtendedDataGeometryMap& extendedData, size_t maxDepth = INT_MAX)
        {
        return BeXmlCGStreamReader::TryParse(buffer.data(), (int)buffer.size(), geometry, extendedData, maxDepth);
        }), "buffer"_a, "geometry"_a, "extendedData"_a, "maxDepth"_a = INT_MAX);

    //===================================================================================
    // struct BeXmlCGWriter
    py::class_<BeXmlCGWriter> c3(m, "BeXmlCGWriter");
    c3.def_static("Write", ([](IGeometryCR data, BeExtendedDataGeometryMap* extendedData = NULL, bool preferCGSweeps = false)
        {
        Utf8String xml;
        BeXmlCGWriter::Write(xml, data, extendedData, preferCGSweeps);
        return xml;
        }), "data"_a, "extendedData"_a = NULL, "preferCGSweeps"_a = false);
    c3.def_static("WriteBytes", &BeXmlCGWriter::WriteBytes, "byte"_a, "data"_a, "extendedData"_a = NULL, "preferCGSweeps"_a = false);



    }