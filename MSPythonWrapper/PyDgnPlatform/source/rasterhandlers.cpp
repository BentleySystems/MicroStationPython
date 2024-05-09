/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\rasterhandlers.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/RasterHandlers.h>
#include <DgnGeoCoord/DgnGeoCoord.h>

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_SetIsInvertBinary =R"doc(Change raster invert color state for binary raster.

Parameter ``eeh``:
    The element to modify.

Parameter ``state``:
    The new invert color state.

Returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_SetIsTransparent =R"doc(Change raster background transparency state.

Parameter ``eeh``:
    The element to modify.

Parameter ``state``:
    The new background transparency state.

Returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_SetBackgroundIndex =R"doc(Change raster background index.

Parameter ``eeh``:
    The element to modify.

Parameter ``backgroundIndex``:
    The new background index.

Returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_SetForegroundIndex =R"doc(Change raster foreground index.

Parameter ``eeh``:
    The element to modify.

Parameter ``foregroundIndex``:
    The new foreground index.

Returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_SetResolution =R"doc(Change raster resolution.

Parameter ``eeh``:
    The element to modify.

Parameter ``resolution``:
    The new raster resolution.

Returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_SetScale =R"doc(Change raster scale factor

Parameter ``eeh``:
    The element to modify.

Parameter ``scale``:
    The new raster scale factor (ratio of design file coordinates in
    the current coordinate system to pixels).

Returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_SetOrigin =R"doc(Change raster origin (in UOR)

Parameter ``eeh``:
    The element to modify.

Parameter ``origin``:
    The new raster origin in UOR (upper left corner of the raster
    element in the design file).

Returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_GetDataFormat =R"doc(Query raster data format.

Parameter ``eh``:
    The element to query.

Returns:
    one of MSRasterElemTypes data format.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_IsBinary =R"doc(Query if raster is binary.

Parameter ``eh``:
    The element to query.

Returns:
    true if raster is binary.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_IsInvertBinary =R"doc(Query if binary raster color are inverted.

Parameter ``eh``:
    The element to query.

Returns:
    true if binary raster color are inverted.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_IsTransparent =R"doc(Query if raster background is transparent.

Parameter ``eh``:
    The element to query.

Returns:
    true if raster background is transparent.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_GetBackgroundIndex =R"doc(Query raster background index

Parameter ``eh``:
    The element to query.

Returns:
    raster background index)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_GetForegroundIndex =R"doc(Query raster foreground index

Parameter ``eh``:
    The element to query.

Returns:
    raster foreground index)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_GetPixelExtent =R"doc(Query raster extent in Pixels

Parameter ``eh``:
    The element to query.

Returns:
    raster extent in Pixels)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_GetResolution =R"doc(Query raster resoltution

Parameter ``eh``:
    The element to query.

Returns:
    raster resolution)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_GetScale =R"doc(Query raster scale factor

Parameter ``eh``:
    The element to query.

Returns:
    raster scale factor (ratio of design file coordinates in the
    current coordinate system to pixels).)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_GetOrigin =R"doc(Query raster origin in UORs

Parameter ``eh``:
    The element to query.

Returns:
    raster origin in UORs (upper left corner of the raster element in
    the design file).)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_Create =R"doc(Create a new Raster Element (type 87/88) with the supplied parameters.

Parameter ``eeh``:
    The new element.

Parameter ``templateEh``:
    Initialize default properties from this template element or NULL.

Parameter ``origin``:
    Element origin.

Parameter ``scale``:
    Element scale.

Parameter ``format``:
    Element format.

Parameter ``imageBuffer``:
    Image buffer. The buffer type depend on 'format':BITMAP_RASTER:
    Expect one bit per pixel buffer with a pitch of
    BITMAP_ROWBYTES(imageSize.x). BYTE_DATA_RASTER:Expect one byte
    per pixel buffer with a pitch of imageSize.x. BINARY_RLE_RASTER:
    Same input as BITMAP_RASTER but will store the data in RLE.
    BYTE_RLE_RASTER:Same input as BYTE_DATA_RASTER but will store the
    data in BYTE RLE.

Parameter ``imageSize``:
    Image size (in pixels).

Parameter ``foreground``:
    Foreground index.

Parameter ``background``:
    Background index.

Parameter ``modelRef``:
    Model to associate this element with. Required to compute range.

Returns:
    SUCCESS if a valid element is created and range was successfully
    calculated.)doc";

using namespace GeoCoordinates;

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_RasterHandlers(py::module_& m)
    {
    //===================================================================================
    // struct  RasterFrameElementCollection
    py::class_< RasterFrameElementCollection> c3(m, "RasterFrameElementCollection");

    c3.def(py::init<DgnModelR>(), "model"_a);
    c3.def(py::init<DgnModelRefR>(), "modelRef"_a);
    c3.def("__bool__", [] (RasterFrameElementCollection& self) { return !self.empty(); });
    c3.def("__iter__", [] (RasterFrameElementCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

    // struct RasterFrameHandler 94
    py::class_<RasterFrameHandler, DisplayHandler, ITransactionHandler, IRasterAttachmentEdit,
        std::unique_ptr<RasterFrameHandler, py::nodelete>> c5(m, "RasterFrameHandler");

    c5.def_static("GetInstance", &RasterFrameHandler::GetInstance);

    // enum MissingHandlerPermissions
    py::enum_< MSRasterElemTypes>(m, "MSRasterElemTypes", py::arithmetic())
        .value("eBITMAP_RASTER", BITMAP_RASTER)
        .value("eBYTE_DATA_RASTER", BYTE_DATA_RASTER)
        .value("eBINARY_RLE_RASTER", BINARY_RLE_RASTER)
        .value("eBYTE_RLE_RASTER", BYTE_RLE_RASTER)
        .export_values();

    //===================================================================================
    // struct RasterHdrHandler 87
    py::class_< RasterHdrHandler, std::unique_ptr< RasterHdrHandler, py::nodelete>, DisplayHandler> c4(m, "RasterHdrHandler");

    c4.def_static("Create", [] (EditElementHandleR eeh, ElementHandleCP templateEh, DPoint3dCR origin, double scale, MSRasterElemTypes format,
                                py::bytes const& imageData, Point2dCR imageSize, byte foreground, byte background, DgnModelRefR modelRef)
                  {
                  std::string strData = imageData.cast<std::string>();
                  return RasterHdrHandler::Create(eeh, templateEh, origin, scale, format, (const byte*) strData.data(), imageSize, foreground, background, modelRef);
                  }, "eeh"_a, "templateEh"_a, "origin"_a, "scale"_a, "format"_a, "imageData"_a, "imageSize"_a, "foreground"_a, "background"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, RasterHdrHandler, Create));

    c4.def("GetOrigin", &RasterHdrHandler::GetOrigin, "eh"_a, DOC(Bentley, DgnPlatform, RasterHdrHandler, GetOrigin));
    c4.def("GetScale", &RasterHdrHandler::GetScale, "eh"_a, DOC(Bentley, DgnPlatform, RasterHdrHandler, GetScale));
    c4.def("GetResolution", &RasterHdrHandler::GetResolution, "eh"_a, DOC(Bentley, DgnPlatform, RasterHdrHandler, GetResolution));
    c4.def("GetPixelExtent", &RasterHdrHandler::GetPixelExtent, "eh"_a, DOC(Bentley, DgnPlatform, RasterHdrHandler, GetPixelExtent));
    c4.def("GetForegroundIndex", &RasterHdrHandler::GetForegroundIndex, "eh"_a, DOC(Bentley, DgnPlatform, RasterHdrHandler, GetForegroundIndex));
    c4.def("GetBackgroundIndex", &RasterHdrHandler::GetBackgroundIndex, "eh"_a, DOC(Bentley, DgnPlatform, RasterHdrHandler, GetBackgroundIndex));
    c4.def("IsTransparent", &RasterHdrHandler::IsTransparent, "eh"_a, DOC(Bentley, DgnPlatform, RasterHdrHandler, IsTransparent));
    c4.def("IsInvertBinary", &RasterHdrHandler::IsInvertBinary, "eh"_a, DOC(Bentley, DgnPlatform, RasterHdrHandler, IsInvertBinary));
    c4.def("IsBinary", &RasterHdrHandler::IsBinary, "eh"_a, DOC(Bentley, DgnPlatform, RasterHdrHandler, IsBinary));
    c4.def("GetDataFormat", &RasterHdrHandler::GetDataFormat, "eh"_a, DOC(Bentley, DgnPlatform, RasterHdrHandler, GetDataFormat));

    c4.def("GetBitMap", [] (RasterHdrHandler const& self, ElementHandleCR eh, py::bytearray& imageData)
           {
           BentleyStatus retVal = ERROR;
           size_t inputBufferSize = py::len(imageData);
           if (inputBufferSize > 0)
               {
               byte* imageBuffer = (byte*) _alloca(inputBufferSize);
               retVal = self.GetBitMap(eh, imageBuffer, inputBufferSize);
               if (retVal == SUCCESS)
                   imageData = py::bytearray((const char*) imageBuffer, inputBufferSize);
               }
           return retVal;
           }, "eh"_a, "imageData"_a);

    c4.def("GetByteMap", [] (RasterHdrHandler const& self, ElementHandleCR eh, int inputBufferSize, bvector<UInt32> const& lookupTableP)
           {
           BentleyStatus retVal = ERROR;
           py::bytearray imageData;

           if (inputBufferSize <= 0)
               return py::make_tuple (retVal, imageData);

           if (inputBufferSize > 0)
               {
               byte* imageBuffer = (byte*) _alloca(inputBufferSize);
               if (lookupTableP.size () > 0)
                    retVal = self.GetByteMap(eh, imageBuffer, (size_t)inputBufferSize, (UInt32 const*)(&lookupTableP.front ()));
               else
                   retVal = self.GetByteMap(eh, imageBuffer, (size_t)inputBufferSize, (UInt32 const*)NULL);

               if (retVal == SUCCESS)
                   imageData = py::bytearray((const char*) imageBuffer, inputBufferSize);
               }
           return py::make_tuple(retVal, imageData);
           }, "eh"_a, "inputBufferSize"_a, "lookupTableP"_a);

    c4.def("SetOrigin", &RasterHdrHandler::SetOrigin, "eeh"_a, "origin"_a, DOC(Bentley, DgnPlatform, RasterHdrHandler, SetOrigin));
    c4.def("SetScale", &RasterHdrHandler::SetScale, "eeh"_a, "scale"_a, DOC(Bentley, DgnPlatform, RasterHdrHandler, SetScale));
    c4.def("SetResolution", &RasterHdrHandler::SetResolution, "eeh"_a, "resolution"_a, DOC(Bentley, DgnPlatform, RasterHdrHandler, SetResolution));
    c4.def("SetForegroundIndex", &RasterHdrHandler::SetForegroundIndex, "eeh"_a, "foregroundIndex"_a, DOC(Bentley, DgnPlatform, RasterHdrHandler, SetForegroundIndex));
    c4.def("SetBackgroundIndex", &RasterHdrHandler::SetBackgroundIndex, "eeh"_a, "backgroundIndex"_a, DOC(Bentley, DgnPlatform, RasterHdrHandler, SetBackgroundIndex));
    c4.def("SetIsTransparent", &RasterHdrHandler::SetIsTransparent, "eeh"_a, "state"_a, DOC(Bentley, DgnPlatform, RasterHdrHandler, SetIsTransparent));
    c4.def("SetIsInvertBinary", &RasterHdrHandler::SetIsInvertBinary, "eeh"_a, "state"_a, DOC(Bentley, DgnPlatform, RasterHdrHandler, SetIsInvertBinary));

    }

