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

:param eeh:
    The element to modify.

:param state:
    The new invert color state.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_SetIsTransparent =R"doc(Change raster background transparency state.

:param eeh:
    The element to modify.

:param state:
    The new background transparency state.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_SetBackgroundIndex =R"doc(Change raster background index.

:param eeh:
    The element to modify.

:param backgroundIndex:
    The new background index.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_SetForegroundIndex =R"doc(Change raster foreground index.

:param eeh:
    The element to modify.

:param foregroundIndex:
    The new foreground index.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_SetResolution =R"doc(Change raster resolution.

:param eeh:
    The element to modify.

:param resolution:
    The new raster resolution.

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_SetScale =R"doc(Change raster scale factor

:param eeh:
    The element to modify.

:param scale:
    The new raster scale factor (ratio of design file coordinates in
    the current coordinate system to pixels).

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_SetOrigin =R"doc(Change raster origin (in UOR)

:param eeh:
    The element to modify.

:param origin:
    The new raster origin in UOR (upper left corner of the raster
    element in the design file).

:returns:
    true if element was updated.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_GetDataFormat =R"doc(Query raster data format.

:param eh:
    The element to query.

:returns:
    one of MSRasterElemTypes data format.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_IsBinary =R"doc(Query if raster is binary.

:param eh:
    The element to query.

:returns:
    true if raster is binary.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_IsInvertBinary =R"doc(Query if binary raster color are inverted.

:param eh:
    The element to query.

:returns:
    true if binary raster color are inverted.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_IsTransparent =R"doc(Query if raster background is transparent.

:param eh:
    The element to query.

:returns:
    true if raster background is transparent.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_GetBackgroundIndex =R"doc(Query raster background index

:param eh:
    The element to query.

:returns:
    raster background index)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_GetForegroundIndex =R"doc(Query raster foreground index

:param eh:
    The element to query.

:returns:
    raster foreground index)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_GetPixelExtent =R"doc(Query raster extent in Pixels

:param eh:
    The element to query.

:returns:
    raster extent in Pixels)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_GetResolution =R"doc(Query raster resoltution

:param eh:
    The element to query.

:returns:
    raster resolution)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_GetScale =R"doc(Query raster scale factor

:param eh:
    The element to query.

:returns:
    raster scale factor (ratio of design file coordinates in the
    current coordinate system to pixels).)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_GetOrigin =R"doc(Query raster origin in UORs

:param eh:
    The element to query.

:returns:
    raster origin in UORs (upper left corner of the raster element in
    the design file).)doc";

static const char * __doc_Bentley_DgnPlatform_RasterHdrHandler_Create =R"doc(Create a new Raster Element (type 87/88) with the supplied parameters.

:param eeh:
    The new element.

:param templateEh:
    Initialize default properties from this template element or NULL.

:param origin:
    Element origin.

:param scale:
    Element scale.

:param format:
    Element format.

:param imageBuffer:
    Image buffer. The buffer type depend on 'format':BITMAP_RASTER:
    Expect one bit per pixel buffer with a pitch of
    BITMAP_ROWBYTES(imageSize.x). BYTE_DATA_RASTER:Expect one byte
    per pixel buffer with a pitch of imageSize.x. BINARY_RLE_RASTER:
    Same input as BITMAP_RASTER but will store the data in RLE.
    BYTE_RLE_RASTER:Same input as BYTE_DATA_RASTER but will store the
    data in BYTE RLE.

:param imageSize:
    Image size (in pixels).

:param foreground:
    Foreground index.

:param background:
    Background index.

:param modelRef:
    Model to associate this element with. Required to compute range.

:returns:
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
                                py::bytes const& imageData, Point2dCR imageSize, Byte foreground, Byte background, DgnModelRefR modelRef)
                  {
                  std::string strData = imageData.cast<std::string>();
                  return RasterHdrHandler::Create(eeh, templateEh, origin, scale, format, (const Byte*) strData.data(), imageSize, foreground, background, modelRef);
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
               Byte* imageBuffer = (Byte*) _alloca(inputBufferSize);
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
               Byte* imageBuffer = (Byte*) _alloca(inputBufferSize);
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

