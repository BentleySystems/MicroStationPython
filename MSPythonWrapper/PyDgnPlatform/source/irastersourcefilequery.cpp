/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\irastersourcefilequery.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/IRasterSourceFileQuery.h>



static const char * __doc_Bentley_DgnPlatform_IRasterSourceFileQuery_ReadToRGBAUsingTopLeftPixelAsAlpha =R"doc(Fill a buffer with RGBA data read from a raster file. If the file is
not RGBA, original data read will be converted to RGBA the first pixel
will be used as the background colour for the production of an alpha
mask

:param RgbaBuffer:
    The buffer to be filled. Caller must allocate the buffer before
    calling the method.

:param maxBufferLength:
    The size of the input buffer.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterSourceFileQuery_ReadToRGBA =R"doc(Fill a buffer with RGBA data read from a raster file. If the file is
not RGBA, original data read will be converted to RGBA

:param RgbaBuffer:
    The buffer to be filled. Caller must allocate the buffer before
    calling the method.

:param maxBufferLength:
    The size of the input buffer.

:param useBgIfNoAlpha:
    If True and there is no alpha channel present in file, will create
    alpha based on background color. Use first pixel as background
    color if no background defined in file.

:returns:
    BSISUCCESS or BSIERROR.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterSourceFileQuery_GetBitmapWidth =R"doc(Query bitmap width in pixels.

:returns:
    bitmap width in pixels.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterSourceFileQuery_GetBitmapHeight =R"doc(Query bitmap height in pixels.

:returns:
    bitmap height in pixels.)doc";

static const char * __doc_Bentley_DgnPlatform_IRasterSourceFileQuery_InitFrom =R"doc(Initialize the source file query object.

:param eh:
    A pointer to corresponding raster attachment elementHandle.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_IRasterSourceFileQuery(py::module_& m)
    {
    //===================================================================================
    // struct IRasterSourceFileQuery
    py::class_< IRasterSourceFileQuery, IRasterSourceFileQueryPtr> c1(m, "IRasterSourceFileQuery");

    c1.def("InitFrom", py::overload_cast<ElementHandleCR>(&IRasterSourceFileQuery::InitFrom), "eh"_a, DOC(Bentley, DgnPlatform, IRasterSourceFileQuery, InitFrom));
    c1.def("InitFrom", py::overload_cast<DgnDocumentMonikerR, UInt32>(&IRasterSourceFileQuery::InitFrom), "moniker"_a, "pageNumber"_a, DOC(Bentley, DgnPlatform, IRasterSourceFileQuery, InitFrom));
    
    c1.def_property_readonly("BitmapHeight", &IRasterSourceFileQuery::GetBitmapHeight);
    c1.def("GetBitmapHeight", &IRasterSourceFileQuery::GetBitmapHeight, DOC(Bentley, DgnPlatform, IRasterSourceFileQuery, GetBitmapHeight));
    
    c1.def_property_readonly("BitmapWidth", &IRasterSourceFileQuery::GetBitmapWidth);
    c1.def("GetBitmapWidth", &IRasterSourceFileQuery::GetBitmapWidth, DOC(Bentley, DgnPlatform, IRasterSourceFileQuery, GetBitmapWidth));
    
    c1.def("HasAlpha", &IRasterSourceFileQuery::HasAlpha);

    c1.def("ReadToRGBA", [] (IRasterSourceFileQueryCR self, py::bytearray& buffer, bool useBgIfNoAlpha)
           {
           size_t maxBufferLength = py::len(buffer);
           UInt8Array data(maxBufferLength);
           auto retVal = self.ReadToRGBA(data.data(), maxBufferLength, useBgIfNoAlpha);
           if (retVal == SUCCESS)
               buffer = py::bytearray((const char*) data.data(), data.size());
           return retVal;
           }, "buffer"_a, "useBgIfNoAlpha"_a, DOC(Bentley, DgnPlatform, IRasterSourceFileQuery, ReadToRGBA));

    c1.def("ReadToRGBAUsingTopLeftPixelAsAlpha", [] (IRasterSourceFileQueryCR self, py::bytearray& buffer)
           {
           size_t maxBufferLength = py::len(buffer);
           UInt8Array data(maxBufferLength);
           auto retVal = self.ReadToRGBAUsingTopLeftPixelAsAlpha(data.data(), maxBufferLength);
           if (retVal == SUCCESS)
               buffer = py::bytearray((const char*) data.data(), data.size());
           return retVal;
           }, "buffer"_a, DOC(Bentley, DgnPlatform, IRasterSourceFileQuery, ReadToRGBAUsingTopLeftPixelAsAlpha));
    }