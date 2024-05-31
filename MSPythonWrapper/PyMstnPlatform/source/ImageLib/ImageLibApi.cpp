/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\ImageLib\ImageLibApi.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <ImageLib/ImageLibApi.h>

BEGIN_BENTLEY_MSTNPLATFORM_MSPYTHON_NAMESPACE
struct MstnImage {};
END_BENTLEY_MSTNPLATFORM_MSPYTHON_NAMESPACE

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       1/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ImageLibAPI(py::module_& m)
    {
    py::class_<MstnImage> c1(m, "MstnImage");

    c1.def_static("resize", [](Point2dR outputsize, py::bytearray& inputImageR, Point2dR inputsize)
        {
        byte* imageMapP;

        int retVal = mdlImage_resize (&imageMapP, &outputsize, (byte*)inputImageR.data(), &inputsize);

        py::bytearray imageMap;

        if (SUCCESS == retVal)
            imageMap = py::bytearray((const char*)imageMapP, outputsize.x * outputsize.y * 3);

        return py::make_tuple(retVal, imageMap);
        }, "outputsize"_a, "inputImageR"_a, "inputsize"_a, py::call_guard<py::gil_scoped_release>());

    c1.def_static("readFileInfo", [](WCharCP fileName, DgnPlatform::ImageFileFormat fileType)
        {
        Point2d imageSize;
        DgnPlatform::ImageColorMode  colorMode;
        int  orientation;

        int retVal = mdlImage_readFileInfo(&imageSize, &colorMode, &orientation, fileName, fileType);

        return py::make_tuple(retVal, imageSize, colorMode, orientation);
        }, "fileName"_a, "fileType"_a);

    c1.def_static("readFileToRGB", [](WCharCP fileName, DgnPlatform::ImageFileFormat fileType, boost::optional<Point2d> requestedSize)
        {
        byte *imageBufferP = nullptr;
        Point2d outputSize;

        int retVal = mdlImage_readFileToRGB(&imageBufferP, &outputSize, fileName, fileType, requestedSize.get_ptr ());

        py::bytearray imageMap;

        if (SUCCESS == retVal)
            {
            imageMap = py::bytearray((const char*)imageBufferP, outputSize.x * outputSize.y * 3);
            mdlImage_freeImage(imageBufferP, &outputSize, IMAGEFORMAT_RGB);
            }

        return py::make_tuple(retVal, imageMap, outputSize);
        }, "fileName"_a, "fileType"_a, "requestedSize"_a, py::call_guard<py::gil_scoped_release>());

    c1.def_static("extCreateFileFromRGB", [](WCharCP name, DgnPlatform::ImageFileFormat type, DgnPlatform::ImageColorMode colorMode, Point2dR sizeR,
                                             py::bytearray& imageBufferR, DgnPlatform::CompressionType compressType, 
                                             DgnPlatform::CompressionRatio compressRatio, py::bytearray& transparencyR)
        {
        return mdlImage_extCreateFileFromRGB (name, type, colorMode, &sizeR, (byte*)imageBufferR.data(), compressType, compressRatio, transparencyR.size () == 0 ? nullptr : (byte*)transparencyR.data());
        }, "name"_a, "type"_a, "colorMode"_a, "sizeR"_a, "imageBufferR"_a, "compressType"_a, "compressRatio"_a, "transparencyR"_a);


    c1.def_static("getExtension", [](DgnPlatform::ImageFileFormat type)
        {
        WChar ext[MAXEXTENSIONLENGTH];

        int retVal = mdlImage_getExtension (ext, type);

        return py::make_tuple(retVal, ext);
        },"type"_a);

    
    c1.def_static("getExportSupport", [](DgnPlatform::ImageFileFormat type)
        {
        DgnPlatform::ImageColorMode defaultMode;
        bool rgbSupport, palette256Support, palette16Support, greyScaleSupport, monochromeSupport;

        int retVal = mdlImage_getExportSupport (&defaultMode, &rgbSupport, &palette256Support, &palette16Support, &greyScaleSupport, &monochromeSupport, type);

        return py::make_tuple(retVal, defaultMode, rgbSupport, palette256Support, palette16Support, greyScaleSupport, monochromeSupport);
        },"type"_a);

    c1.def_static("getImportFormatString", [](DgnPlatform::ImageFileFormat formatId)
        {
        WChar formatName[512];

        int retVal = mdlImage_getImportFormatString(formatName, 512, formatId);

        return py::make_tuple(retVal, formatName);
        }, "formatId"_a);

    c1.def_static("getExportFormatString", [](DgnPlatform::ImageFileFormat formatId)
        {
        WChar formatName[512];

        int retVal = mdlImage_getExportFormatString (formatName, 512, formatId);

        return py::make_tuple(retVal, formatName);
        },"formatId"_a);


    c1.def_static("typeFromExtension", &mdlImage_typeFromExtension, "fileName"_a);

    c1.def_static("applyGamma", [](py::bytearray& rgb, Point2dR sizeR, double gamma)
        {
        mdlImage_applyGamma((byte*)rgb.data(), (byte*)rgb.data(), &sizeR, gamma);
        }, "rgb"_a, "sizeR"_a, "gamma"_a, py::call_guard<py::gil_scoped_release>());

    c1.def_static("negate", [](py::bytearray& rgb, Point2dR sizeR)
        {
        mdlImage_negate((byte*)rgb.data(), (byte*)rgb.data(), &sizeR);
        }, "rgb"_a, "sizeR"_a, py::call_guard<py::gil_scoped_release>());



    c1.def_static("extractSubImage", [] (Point2dR outSizeR, py::bytearray& inR, Point2dR inSizeR, BSIRectR rectR, int imageFormat)
        {
        int             bufsize = mdlImage_memorySize (&outSizeR, imageFormat);
        py::bytearray   out = py::bytearray(nullptr, bufsize);

        int retVal = mdlImage_extractSubImage((byte*)out.data(), &outSizeR, (byte*)inR.data(), &inSizeR, &rectR, imageFormat);

        return py::make_tuple(retVal, out);
        }, "outSizeR"_a, "inR"_a, "inSizeR"_a, "rectR"_a, "imageFormat"_a);

    c1.def_static("tintImage", [](py::bytearray& imageR, Point2dR imageSizeR, RgbColorDef* tintRGBP)
        {
        mdlImage_tintImage((byte*)imageR.data(), &imageSizeR, tintRGBP);
        }, "imageR"_a, "imageSizeR"_a, "tintRGBP"_a);

    c1.def_static("rotate", [](py::bytearray& inpBufferR, Point2dR imageSizeR, int imageFormat, int rotation)
        {
        byte        *outBufferP = nullptr;
        Point2d     outSize;

        int retVal = mdlImage_rotate(&outBufferP, &outSize, (byte*)inpBufferR.data(), &imageSizeR, imageFormat, rotation);

        py::bytearray outImage;

        if (SUCCESS == retVal)
            {
            int bufsize = mdlImage_memorySize (&outSize, imageFormat);
            outImage = py::bytearray((const char*)outBufferP, bufsize);
            mdlImage_freeImage((byte*)outBufferP, &outSize, imageFormat);
            }

        return py::make_tuple(retVal, outImage, outSize);
        }, "inpBufferR"_a, "imageSizeR"_a, "imageFormat"_a, "rotation"_a);

    c1.def_static("mirror", [](py::bytearray& rgb, Point2dR imageSizeR, int imageFormat, bool vertical)
        {
        return mdlImage_mirror((byte*)rgb.data(), &imageSizeR, imageFormat, vertical);

        }, "rgb"_a, "imageSizeR"_a, "imageFormat"_a, "vertical"_a);

    c1.def_static("memorySize", &mdlImage_memorySize, "sizeP"_a, "imageFormat"_a);
    c1.def_static("typeFromFile", &mdlImage_typeFromFile, "fileNameP"_a);


    c1.def_static("fileType", &mdlImage_fileType, "fileType"_a, "fileNameP"_a);

    c1.def_static("RGBToRGBSeparate", [](py::bytearray& rgbInterlacedR, Point2dR imageSizeR, DgnPlatform::ImageColorMode colorMode)
        {
        int             imgFmt = (colorMode == DgnPlatform::ImageColorMode::RGB ? IMAGEFORMAT_RGB : IMAGEFORMAT_RGBA);
        int             bufsize = mdlImage_memorySize (&imageSizeR, imgFmt);
        py::bytearray   imageMap = py::bytearray(nullptr, bufsize);

        int retVal =  mdlImage_RGBToRGBSeparate((byte*)imageMap.data (), (byte*)rgbInterlacedR.data(), &imageSizeR, colorMode);

        return py::make_tuple(retVal, imageMap); 
        }, "rgbInterlacedR"_a, "imageSizeR"_a, "colorMode"_a);

    c1.def_static("RGBToRGBSeparateInPlace", [](py::bytearray& rgb, Point2dR imageSizeR, DgnPlatform::ImageColorMode colorMode)
        {
        return mdlImage_RGBToRGBSeparate((byte*)rgb.data(), (byte*)rgb.data(), &imageSizeR, colorMode);
        }, "rgb"_a, "imageSizeR"_a, "colorMode"_a);


    c1.def_static("RGBSeparateToRGBInPlace", [](py::bytearray& rgb, Point2dR imageSizeR, DgnPlatform::ImageColorMode colorMode)
        {
        return mdlImage_RGBSeparateToRGB((byte*)rgb.data(), (byte*)rgb.data(), &imageSizeR, colorMode);
        }, "rgb"_a, "imageSizeR"_a, "colorMode"_a);



    c1.def_static("RGBSeparateToBGR", []( py::bytearray& rgb, Point2dR imageSizeR, DgnPlatform::ImageColorMode colorMode)
        {
        int             imgFmt = (colorMode == DgnPlatform::ImageColorMode::RGB ? IMAGEFORMAT_RGB : IMAGEFORMAT_RGBA);
        int             bufsize = mdlImage_memorySize (&imageSizeR, imgFmt);
        py::bytearray   imageMap = py::bytearray(nullptr, bufsize);

        int retVal = mdlImage_RGBSeparateToBGR((byte*)imageMap.data(), (byte*)rgb.data(), &imageSizeR, colorMode);

        return py::make_tuple(retVal, imageMap);
        }, "rgb"_a, "imageSizeR"_a, "colorMode"_a);

    c1.def_static("saveView", [](WCharCP fileNameP, Point2dR imageSizeR, int renderMode, DgnPlatform::ImageFileFormat imageFormat, bool stereo, bool antialias, int view)
        {
        return mdlImage_saveView(fileNameP, &imageSizeR, renderMode, imageFormat, stereo, antialias, view);

        }, "fileNameP"_a, "imageSizeR"_a, "renderMode"_a, "imageFormat"_a, "stereo"_a, "antialias"_a, "view"_a);


    c1.def_static("saveViewToRGB", [](Point2dR imageSizeR, int renderMode, bool stereo, bool antialias, int view)
        {
        byte* imageMapP = nullptr;    

        int retVal = mdlImage_saveViewToRGB(&imageMapP, &imageSizeR, renderMode, stereo, antialias, view);

        py::bytearray imageMap;

        if (SUCCESS == retVal)
            {
            imageMap = py::bytearray((const char*)imageMapP, imageSizeR.x * imageSizeR.y* 3);
            dlmSystem_mdlFree (imageMapP);
            }
        return py::make_tuple(retVal, imageMap);
        }, "imageSizeR"_a, "renderMode"_a, "stereo"_a, "antialias"_a, "view"_a);
    
    c1.def_static("saveViewToRGBA", [](Point2dR imageSizeR, int renderMode, bool stereo, bool antialias, int view)
        {
        byte* imageMapP = nullptr;    

        int retVal = mdlImage_saveViewToRGBA(&imageMapP, &imageSizeR, renderMode, stereo, antialias, view);

        py::bytearray imageMap;

        if (SUCCESS == retVal)
            {
            imageMap = py::bytearray((const char*)imageMapP, imageSizeR.x * imageSizeR.y* 4);
            dlmSystem_mdlFree (imageMapP);
            }
        return py::make_tuple(retVal, imageMap);
        }, "imageSizeR"_a, "renderMode"_a, "stereo"_a, "antialias"_a, "view"_a);

    }


