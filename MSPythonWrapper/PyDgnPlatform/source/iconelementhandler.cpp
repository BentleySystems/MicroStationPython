/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\iconelementhandler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/IconElementHandler.h>



static const char * __doc_Bentley_DgnPlatform_IconElementHandler_CreateElement =R"doc(Create a new element that stores the state of the input table object.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_IconElementHandler(py::module_& m)
    {
    //===================================================================================
    // enum class IconSource
    py::enum_< IconSource>(m, "IconSource")
        .value("eIcoFile", IconSource::IcoFile)
        .value("eResourceFile", IconSource::ResourceFile)
        .value("eDllFile", IconSource::DllFile)
        .export_values();

    //===================================================================================
    // struct IconData
    py::class_< IconData, IconDataPtr> c1(m, "IconData");

    c1.def_static("CreateFromIcoFile", &IconData::CreateFromIcoFile, "fileName"_a);
    c1.def_static("CreateFromResource", &IconData::CreateFromResource, "handle"_a, "alias"_a);
    
    c1.def_static("CreateFromData", [] (py::bytes const& data)
                  {
                  std::string strData = (std::string) data;
                  return IconData::CreateFromData((const byte*) strData.data(), strData.size());
                  }, "data"_a);
    c1.def_property_readonly("AspectRatio", &IconData::GetAspectRatio);
    c1.def("GetAspectRatio", &IconData::GetAspectRatio);

    //===================================================================================
    // struct IconGeometry
    py::class_< IconGeometry> c2(m, "IconGeometry");

    c2.def_readwrite("isDrawBoundary", &IconGeometry::m_drawBoundary);
    c2.def_readwrite("origin", &IconGeometry::m_origin);
    c2.def_readwrite("vectorX", &IconGeometry::m_vectorX);
    c2.def_readwrite("vectorY", &IconGeometry::m_vectorY);
    c2.def(py::init<bool, DPoint3dCR, DPoint3dCR, DPoint3dCR>(), "IsDrawBoundary"_a, "Origin"_a, "VectorX"_a, "VectorY"_a);

    //===================================================================================
    // struct IconElementHandler
    py::class_< IconElementHandler, ExtendedElementHandler> c3(m, "IconElementHandler");

    c3.def_static("CreateElement", &IconElementHandler::CreateElement, "eeh"_a, "templateEh"_a, "iconData"_a, "geometry"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, IconElementHandler, CreateElement));
    }