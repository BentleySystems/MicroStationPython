/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\olecellheaderhandler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/OleCellHeaderHandler.h>



static const char * __doc_Bentley_DgnPlatform_OleCellHeaderHandler_GetScale =R"doc(Query the display scale for the ole data.

Parameter ``eh``:
    IN The element to query.

Parameter ``scale``:
    OUT display scale.

Returns:
    SUCCESS if extracted data is valid.)doc";

static const char * __doc_Bentley_DgnPlatform_OleCellHeaderHandler_GetSourceSize =R"doc(Query the source data size for the ole data.

Parameter ``eh``:
    IN The element to query.

Parameter ``sourceSize``:
    OUT Source data size.

Parameter ``label``:
    OUT Unit label for source data size.

Returns:
    SUCCESS if extracted data is valid.)doc";

static const char * __doc_Bentley_DgnPlatform_OleCellHeaderHandler_GetSize =R"doc(Query extents, center, and orientation of the ole element.

Parameter ``eh``:
    IN The element to query.

Parameter ``size``:
    OUT Extents of ole element (optional).

Parameter ``center``:
    OUT Center of ole element (optional).

Parameter ``rMatrix``:
    OUT Orientation of ole element (optional).

Returns:
    SUCCESS if extracted data is valid.)doc";

static const char * __doc_Bentley_DgnPlatform_OleCellHeaderHandler_IsOleElement =R"doc(Test if the supplied element is an ole cell element.

Parameter ``eh``:
    IN The element to test.

Parameter ``info``:
    OUT ole information (optional).

Returns:
    true if eh is a valid ole element.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_OleCellHeaderHandler(py::module_& m)
    {
    //===================================================================================
    // enum DgnOleStorageType
    py::enum_< DgnOleStorageType>(m, "DgnOleStorageType", py::arithmetic())
        .value("eDGNOLE_STORAGE_Linked", DGNOLE_STORAGE_Linked)
        .value("eDGNOLE_STORAGE_Embedded", DGNOLE_STORAGE_Embedded)
        .value("eDGNOLE_STORAGE_Static", DGNOLE_STORAGE_Static)
        .export_values();

    //===================================================================================
    // enum DgnOlePasteMethod
    py::enum_< DgnOlePasteMethod>(m, "DgnOlePasteMethod", py::arithmetic())
        .value("eDGNOLE_PASTEMETHOD_ByCornerPoints", DGNOLE_PASTEMETHOD_ByCornerPoints)
        .value("eDGNOLE_PASTEMETHOD_ByObjectSize", DGNOLE_PASTEMETHOD_ByObjectSize)
        .value("eDGNOLE_PASTEMETHOD_ByObjectMinTextSize", DGNOLE_PASTEMETHOD_ByObjectMinTextSize)
        .export_values();

    //===================================================================================
    // enum DgnOleViewRotationMode
    py::enum_< DgnOleViewRotationMode>(m, "DgnOleViewRotationMode", py::arithmetic())
        .value("eDGNOLE_ViewRotation_ViewIndependent", DGNOLE_ViewRotation_ViewIndependent)
        .value("eDGNOLE_ViewRotation_ViewDependent", DGNOLE_ViewRotation_ViewDependent)
        .value("eDGNOLE_ViewRotation_AutoCAD", DGNOLE_ViewRotation_AutoCAD)
        .export_values();

    //===================================================================================
    // struct HiMetricSizeShort
    py::class_< HiMetricSizeShort> c1(m, "HiMetricSizeShort");
    c1.def_readwrite("x", &HiMetricSizeShort::x);
    c1.def_readwrite("y", &HiMetricSizeShort::y);

    //===================================================================================
    // struct HiMetricSizeLong
    py::class_< HiMetricSizeLong> c2(m, "HiMetricSizeLong");
    c2.def_readwrite("x", &HiMetricSizeLong::x);
    c2.def_readwrite("y", &HiMetricSizeLong::y);

    //===================================================================================
    // struct DgnOleFlags
    py::class_< DgnOleFlags> c3(m, "DgnOleFlags");

    c3.def_property("Transparent",
                    [] (DgnOleFlags const& self) { return self.transparent == 1 ? true : false; },
                    [] (DgnOleFlags& self, bool value) { self.transparent = value ? 1 : 0; });

    c3.def_property("Selectable",
                    [] (DgnOleFlags const& self) { return self.selectable == 1 ? true : false; },
                    [] (DgnOleFlags& self, bool value) { self.selectable = value ? 1 : 0; });

    c3.def_property("Activateable",
                    [] (DgnOleFlags const& self) { return self.activateable == 1 ? true : false; },
                    [] (DgnOleFlags& self, bool value) { self.activateable = value ? 1 : 0; });

    c3.def_property("InsertedObj",
                    [] (DgnOleFlags const& self) { return self.insertedObj == 1 ? true : false; },
                    [] (DgnOleFlags& self, bool value) { self.insertedObj = value ? 1 : 0; });

    c3.def_property("DoNotDisplayOleObj",
                    [] (DgnOleFlags const& self) { return self.doNotDisplayOleObj == 1 ? true : false; },
                    [] (DgnOleFlags& self, bool value) { self.doNotDisplayOleObj = value ? 1 : 0; });

    c3.def_property("ViewRotationMode",
                    [] (DgnOleFlags const& self) { return (DgnOleViewRotationMode)self.viewRotationMode; },
                    [] (DgnOleFlags& self, DgnOleViewRotationMode mode) { self.viewRotationMode = (UInt32)mode; });        

    //===================================================================================
    // struct DgnOleInfo
    py::class_< DgnOleInfo> c4(m, "DgnOleInfo");

    c4.def_readwrite("version", &DgnOleInfo::m_version);
    c4.def_readwrite("oleAspect", &DgnOleInfo::m_oleAspect);
    c4.def_readwrite("defaultSize", &DgnOleInfo::m_defaultSize);
    c4.def_readwrite("storageType", &DgnOleInfo::m_storageType);
    c4.def_readwrite("flags", &DgnOleInfo::m_flags);

    //===================================================================================
    // enum DgnOleStatus
    py::enum_< DgnOleStatus>(m, "DgnOleStatus", py::arithmetic())
        .value("eDGNOLE_SUCCESS", DGNOLE_SUCCESS)
        .value("eDGNOLE_ERROR_BadElement", DGNOLE_ERROR_BadElement)
        .value("eDGNOLE_ERROR_AlreadyActive", DGNOLE_ERROR_AlreadyActive)
        .value("eDGNOLE_ERROR_NotOleElement", DGNOLE_ERROR_NotOleElement)
        .value("eDGNOLE_ERROR_LockBytesError", DGNOLE_ERROR_LockBytesError)
        .value("eDGNOLE_ERROR_BadOleObject", DGNOLE_ERROR_BadOleObject)
        .value("eDGNOLE_ERROR_CantActivate", DGNOLE_ERROR_CantActivate)
        .value("eDGNOLE_ERROR_StaticOleElement", DGNOLE_ERROR_StaticOleElement)
        .value("eDGNOLE_ERROR_ElementInReference", DGNOLE_ERROR_ElementInReference)
        .value("eDGNOLE_ERROR_CantResolveLink", DGNOLE_ERROR_CantResolveLink)
        .value("eDGNOLE_ERROR_CantConnectToLink", DGNOLE_ERROR_CantConnectToLink)
        .value("eDGNOLE_ERROR_ClassDifferent", DGNOLE_ERROR_ClassDifferent)
        .value("eDGNOLE_ERROR_NoObjectInLink", DGNOLE_ERROR_NoObjectInLink)
        .export_values();

    //===================================================================================
    //struct OleCellHeaderHandler
    py::class_< OleCellHeaderHandler
        , std::unique_ptr< OleCellHeaderHandler, py::nodelete>
        , Type2Handler
    > c5(m, "OleCellHeaderHandler");

    c5.def_static("IsOleElement", &OleCellHeaderHandler::IsOleElement, "eh"_a, "info"_a, DOC(Bentley, DgnPlatform, OleCellHeaderHandler, IsOleElement));
    c5.def("GetSize", &OleCellHeaderHandler::GetSize, "eh"_a, "size"_a, "center"_a, "rMatrix"_a, DOC(Bentley, DgnPlatform, OleCellHeaderHandler, GetSize));
    c5.def("GetSourceSize", &OleCellHeaderHandler::GetSourceSize, "eh"_a, "sourceSize"_a, "label"_a, DOC(Bentley, DgnPlatform, OleCellHeaderHandler, GetSourceSize));
    c5.def("GetScale", &OleCellHeaderHandler::GetScale, "eh"_a, "scale"_a, DOC(Bentley, DgnPlatform, OleCellHeaderHandler, GetScale));
    
    c5.def("ExtractOleData", [] (OleCellHeaderHandler& self, ElementHandleCR eh, py::bytearray& data)
           {
           void* dataP = nullptr;
           UInt32 dataSize = 0;
           auto retVal = self.ExtractOleData(eh, &dataP, &dataSize);
           if (retVal == SUCCESS && nullptr != dataP && dataSize > 0)
               {
               data = py::bytearray((const char*) dataP, dataSize);
               self.FreeExtractedOleData(dataP);
               }
           return retVal;
           }, "eh"_a, "data"_a);

    c5.def_static("CreateOleElement", [] (EditElementHandleR eeh, DgnOleInfo const* info, WCharCP name, WCharCP description, DPoint3dArray const& shape, py::bytes const& oleData, bool is3d, DgnModelRefR modelRef)
                  {
                  std::string strData = oleData.cast<std::string>();
                  return OleCellHeaderHandler::CreateOleElement(eeh, info, name, description, shape.data(), (void const*) strData.data(), strData.size(), is3d, modelRef);
                  }, "eeh"_a, "info"_a, "name"_a, "description"_a, "shape"_a, "oldData"_a, "is3d"_a, "modelRef"_a);

    c5.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr< OleCellHeaderHandler, py::nodelete>(&OleCellHeaderHandler::GetInstance()); });
    c5.def_static("GetInstance", &OleCellHeaderHandler::GetInstance, py::return_value_policy::reference);
    }