/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\ImageLib\ImageLibApi.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <ImageLib/ImageLibApi.h>

static const char* __doc_mdlImage_resize = R"doc(@description Compresses or expands the RGB buffer specified by
inputImageR and inputsize to the size specified by outputsize. The
process of resizing the image uses pixel averaging and can require
substantial processing time. The resizing algorithm produces expanded
or compressed images of significantly higher quality than those
produced using simple pixel replication or decimation techniques.

Parameter ``outputsize``:
    IN output size

Parameter ``inputImageR``:
    IN input image (RGB)

Parameter ``inputsize``:
    IN input size

Returns:
    A tuple object containing 2 elements:

tuple[0] int:
    eSUCCESS if the image is resized successfully.
    <br>eMDLERR_INSFMEMORY if there is not enough memory available to
    perform the operation.

tuple[1] bytearray:
    resized output image (RGB))doc";

static const char* __doc_mdlImage_readFileInfo = R"doc(@description Returns information about the image file specified by
fileName and fileType.

Parameter ``fileName``:
    IN file name to examine.

Parameter ``fileType``:
    IN type of the file, or -1 to use the file name
    extension to determine the disk format.

Returns:
    A tuple object containing 4 elements:

tuple[0] int:
    SUCCESS if the information is successfully extracted from the
    image file. <br>MDLERR_BADFILETYPE if filetype is not supported
    for import. <br>MDLERR_CANNOTOPENFILE if the file cannot be
    opened. 

tuple[1] Point2d:
    size of the image in X and Y pixels. If the pointer is NULL,
    this value is not returned.

tuple[2] ImageColorMode:
    color mode of the image. If the pointer is
    NULL, this value is not returned.

tuple[3] int:
    orientation of the image. If the pointer is
    NULL, this value is not returned.)doc";

static const char* __doc_mdlImage_readFileToRGB = R"doc(@description Reads the image file specified by filename and fileType
and returns an RGB image. The image file can be either mapped or
unmapped.  If NULL is specified for requestedSize, outputSize in returned tuple 
is set to the size of the file image,otherwise outputSize is set to requestedSize.

Parameter ``fileName``:
    IN image file name.

Parameter ``fileType``:
    IN type of file , or -1 to use the file name
    extension to determine the disk format.

Parameter ``requestedSize``:
    IN target size for the image, or NULL for unmodified size.

Remark:
    s The process of resizing the image uses pixel averaging and can
    substantially increase the time required to read the image. The
    resizing algorithm produces excellent results, producing expanded
    or compressed images of significantly higher quality than those
    produced using simple pixel replication or decimation.

Returns:
    A tuple object containing 3 elements:

tuple[0] int:
    SUCCESS if the file is read successfully. <br>MDLERR_BADFILETYPE:
    if filetype is not supported. <br>MDLERR_CANNOTOPENFILE: if the
    file cannot be created. <br>MDLERR_INSFMEMORY if there is not
    enough memory available to perform the operation.
    
tuple[1] bytearray:
    bytearray object to receive the RGB pixels. 
    
tuple[2] Point2d:
    size of the image in X and Y pixels. )doc";

static const char* __doc_mdlImage_extCreateFileFromRGB = R"doc(@description Creates the image file specified by fileName, fileType
and colorMode from an RGB image, allowing compression type and
transparency to be set.

Parameter ``name``:
    IN name of file.

Parameter ``type``:
    IN type of file .

Parameter ``colorMode``:
    IN color mode .

Parameter ``sizeR``:
    IN pointer to size of image in X and Y pixels.

Parameter ``imageBufferR``:
    IN address of the image buffer with red, green and blue rows
    stored separately for each scan line. The size of imageBuffer
    should be (3 * sizeR.x * sizeR.y).

Parameter ``compressType``:
    IN the type of compression to use in creating the file 

Parameter ``compressRatio``:
    IN the ratio of compression to use in creating the file 

Parameter ``transparencyR``:
    IN the index of the transparency value, or the RGB tripple to use
    for the transparency value.

Returns:
    SUCCESS if the file is created successfully.
    <br>eMDLERR_BADFILETYPE: if filetype is not supported.
    <br>eMDLERR_CANNOTOPENFILE: if the file cannot be created.
    <br>eMDLERR_INSFMEMORY if there is not enough memory available to
    perform the operation. )doc";

static const char* __doc_mdlImage_getExtension = R"doc(@description Returns the default three character file extension for
the specified image format.

Parameter ``type``:
    IN image type .  

Returns:
    A tuple object containing 2 elements:

tuple[0] int:
   eSUCCESS if the file type is
   found; eMDLERR_BADARG if it is not.

tuple[1] str:
   default file extension (MAXEXTENSIONLENGTH characters).)doc";

static const char* __doc_mdlImage_getExportSupport = R"doc(@description For a specified image format, returns the default color
mode, and whether each of the various color modes is supported for
export.

Parameter ``imageType``:
    IN image type . 

Returns:
    A tuple object containing 7 elements:

tuple[0] int:
    eSUCCESS if the file type is
    supported; eMDLERR_BADARG if it is not.

tuple[1] ImageColorMode::
    default color mode.

tuple[2] bool:
    support for 24 bit RGB.

tuple[3] bool:
    support for 256 color palette.

tuple[4] bool:
    support for 16 color palette.

tuple[5] bool:
    support for grey scale.

tuple[6] bool:
    support for monochrome. )doc";

static const char* __doc_mdlImage_getImportFormatString = R"doc(@description Get the corresponding string for a given ImageFileFormat

Parameter ``formatId``:
    IN ImageFileFormat to acquire the name. @Return BSISUCCESS if the
    string is found. 

Returns:
    A tuple object containing 2 elements:

tuple[0] int:
    eSUCCESS if the string is found. .

tuple[1] str:
    Name of Import format.)doc";

static const char* __doc_mdlImage_getExportFormatString = R"doc(@description Get the corresponding string for a given ImageFileFormat

Parameter ``formatId``:
    IN ImageFileFormat to acquire the name. 

Returns:
    A tuple object containing 2 elements:

tuple[0] int:
    eSUCCESS if the string is found. .

tuple[1] str:
    Name of Export format.)doc"; 

static const char* __doc_mdlImage_typeFromExtension = R"doc(@description Returns the file type of the specified image file.

Parameter ``fileName``:
    IN image file name

Returns:
    the image file type from the filename extension . If the extension does not have a match,
    eIMAGEFILE_UNKNOWN is returned. )doc";

static const char* __doc_mdlImage_applyGamma = R"doc(@description Applies gamma correction to the input RGB buffer and
places the result in the output RGB buffer.

Parameter ``rgb``:
    IN Out image buffer (may be the same as rgbInP).

Parameter ``sizeR``:
    IN image size in X and Y pixels.

Parameter ``gamma``:
    IN gamma value to be applied to image (1.0 means no correction).)doc";

static const char* __doc_mdlImage_negate = R"doc(@description Returns an RGB image that is the negated version of the
input RGB image.

Parameter ``rgb``:
    IN Out image buffer.

Parameter ``sizeR``:
    IN image size in X and Y pixels. )doc";

static const char* __doc_mdlImage_extractSubImage = R"doc(@description Extracts a subimage from a larger image and stretches or
decimates it to fit a user-defined output image size.

Parameter ``outSizeR``:
    IN output image size in X and Y pixels.

Parameter ``inR``:
    IN source image buffer.

Parameter ``inSizeR``:
    IN size of the source image in X and Y pixels.

Parameter ``rectR``:
    IN rectangular subimage in X and Y pixels. The rectangle defined
    by rectR should be a subset of the rectangle with origin at (0,0)
    and corner at (inSizeR.x - 1, inSizeR.y - 1). If rectR is None,
    the subimage rectangle is the entire image.

Parameter ``imageFormat``:
    IN IMAGEFORMAT type .

Returns:
    A tuple object containing 2 elements:

tuple[0] int:
    eSUCCESS if the operation is completed successfully.

tuple[1] bytearray:
    bytearray object to receive the subimage)doc";

static const char* __doc_mdlImage_tintImage = R"doc(@description Tints an RGB image in format eIMAGEFORMAT_RGBSeparate by
adjusting values as defined below.

Parameter ``imageR``:
    OUT an image buffer in format IMAGEFORMAT_RGBSeparate.

Parameter ``imageSizeR``:
    IN size of the image in X and Y pixels.

Parameter ``tintRGBP``:
    IN RGB value that will be used to tint the image.

Remark:
    s The image pixels are adjusted as follows:

```
imageP = (tintRGBP->red   * (UInt)*imageP) / 255u;
imageP += imageSizeP->x;
imageP = (tintRGBP->green * (UInt)*imageP) / 255u;
imageP += imageSizeP->x;
imageP = (tintRGBP->blue  * (UInt)*imageP) / 255u;
```
)doc";

static const char* __doc_mdlImage_rotate = R"doc(@description Rotates the image about the origin in a counter clockwise
direction by a specified number of degrees.

Parameter ``inpBufferR``:
    IN input image buffer.

Parameter ``imageSizeR``:
    IN size of the input image buffer in X and Y pixels.

Parameter ``imageFormat``:
    IN one the IMAGEFORMAT types.

Parameter ``rotation``:
    IN 90, 180 or 270 degrees.

Remark:
    s Currently, only 90, 180 and 270 degree rotations are supported.

Returns:
    A tuple object containing 3 elements:

tuple[0] int:
    eSUCCESS if the operation is completed successfully.
    <br>eMDLERR_INSFMEMORY if there is not enough memory available to
    perform the operation. <br>eMDLERR_BADARG if an invalid image
    format is detected.

tuple[1] bytearray:
    bytearray object to receive the image.

tuple[2] Point2d:
    Size of the output image in X and Y pixels.)doc";


static const char* __doc_mdlImage_mirror = R"doc(@description Mirrors an image by reversing the pixels, either
horizontally or vertically.

Parameter ``rgb``:
    IN OUT the image buffer. The original buffer is
    overwritten during the mirror operation.

Parameter ``imageSizeR``:
    IN size of the image buffer in X and Y pixels.

Parameter ``imageFormat``:
    IN one of the IMAGEFORMAT types.

Parameter ``vertical``:
    IN if true, the image is mirrored vertically; if false, the image
    is mirrored horizontally.

Returns:
    eSUCCESS if the operation is completed successfully.
    <br>eMDLERR_INSFMEMORY if there is not enough memory available to
    perform the operation. )doc";

static const char* __doc_mdlImage_memorySize = R"doc(@description Returns the amount of memory initially required to hold
the image in the specified image format. If the image is uncompressed,
this is the total size. If it is compressed, this is the amount
necessary to hold an array of pointers to each image row. Memory for
each row will be allocated in subsequent operations once the size of
the compressed row is determined.

Parameter ``sizeP``:
    IN the size of the image in X and Y pixels.

Parameter ``imageFormat``:
    IN any of the IMAGEFORMAT types.

Returns:
    if successful, the positive number of bytes required to hold the
    input image. <br>eMDLERR_BADARG if an invalid image format is
    detected.)doc";

static const char* __doc_mdlImage_typeFromFile = R"doc(@description Attempts to determine the type of file from header
information within the file itself. If it can successfully validate
the file type, it returns one of the supported IMAGEFILE formats.

Remark:
    s Currently, this function recognizes the following types of
    files: FLI, GIF, PNG, JPEG, IMG, IMG (24-bit), all Intergraph
    files and TIFF files. These files have magic number and special
    check bytes that easily identify the type of image file.

Remark:
    s The MstnImage.typeFromFile function is the preferred way to
    determine the format of a source (import) image file. It should be
    checked before calling MstnImage.typeFromExtension, since image
    types returned by this function are more likely to be correct.

Parameter ``fileNameP``:
    IN full path name of the image file.

Returns:
    an IMAGEFILE type. <br>IMAGEFILE_UNKNOWN if no
    valid image format can be determined. )doc";

static const char* __doc_mdlImage_fileType = R"doc(@description Determines the format of the specified image file. @Param
fileType IN set to eIMAGEFILE_UNKNOWN to find the type of the file, or
set to a specific file type to verify that the file is of that type.

Parameter ``fileNameP``:
    IN the name of the file to verify or determine type

Returns:
    eIMAGEFILE_UNKNOWN if the file is not found or is invalid,
    otherwise file type of file )doc";

static const char* __doc_mdlImage_RGBToRGBSeparate = R"doc(@description Converts the specified image from RBG interlaced to RGB
separated format. 

Parameter ``rgbInterlacedR``:
    IN image in RGBRGBRGB or RGBARGBARGBA format

Parameter ``imageSizeR``:
    IN size of the image.

Parameter ``colorMode``:
    IN either ImageColorMode::RGB or ImageColorMode::RGBA.

Returns:
    A tuple object containing 2 elements:

tuple[0] int:
    eSUCCESS if the operation is completed successfully.
    <br>eMDLERR_INSFMEMORY if there is not enough memory available to
    perform the operation. @Remarks If the input image is RGBA, the
    alph channel is discarded.

tuple[1] bytearray:
    bytearray object to receive the RRRGGGBBB format image data)doc";


static const char* __doc_mdlImage_RGBToRGBSeparateInPlace = R"doc(@description Converts the specified image from RBG interlaced to RGB
separated format. 

Parameter ``rgb``:
    IN OUT image in RGBRGBRGB or RGBARGBARGBA format

Parameter ``imageSizeR``:
    IN size of the image.

Parameter ``colorMode``:
    IN either ImageColorMode::RGB or ImageColorMode::RGBA.

Returns:
    eSUCCESS if the operation is completed successfully.
    <br>eMDLERR_INSFMEMORY if there is not enough memory available to
    perform the operation. @Remarks If the input image is RGBA, the
    alph channel is discarded..)doc";

static const char* __doc_mdlImage_RGBSeparateToRGBInPlace = R"doc(@description Converts the specified image from RBG separate to RGB
interlaced format. 

Parameter ``rgb``:
    IN OUT the buffer to receive the image in RGBRGBRGB or RGBARGBARGBA format.

Parameter ``imageSizeR``:
    IN the RRRGGGBBB format image data. 

Parameter ``colorMode``:
    IN either ImageColorMode::RGB or ImageColorMode::RGBA.

Returns:
    eSUCCESS if the operation is completed successfully.
    <br>eMDLERR_INSFMEMORY if there is not enough memory available to
    perform the operation.)doc";


static const char* __doc_mdlImage_RGBSeparateToBGR = R"doc(@description Converts the specified image from RBG separate to BGR
interlaced format. 

Parameter ``rgbSeparate``:
    IN the RRRGGGBBB format image data.

Parameter ``imageSizeR``:
    IN the size of the image. 

Parameter ``colorMode``:
    IN either ImageColorMode::RGB or ImageColorMode::RGBA.

Returns:
    A tuple object containing 2 elements:

tuple[0] int:
    eSUCCESS if the operation is completed successfully.
    <br>eMDLERR_INSFMEMORY if there is not enough memory available to
    perform the operation.

tuple[1] bytearray:
    bytearray object to receive the image in BGRBGRBGR or BGRABGRABGRA format)doc";

static const char* __doc_mdlImage_saveView = R"doc(@Description Renders an RGB image of a view to disk. 

Parameter ``fileNameP``:
    IN name of image file to create. 

Parameter ``imageSizeR``:
    IN size of image to render (in X and Y pixels). 

Parameter ``renderMode``:
    IN the rendering mode (SMOOTH, MSRenderMode::Phong, CONSTANT, etc.). 

Parameter ``imageFormat``:
    IN image format of output file.

Parameter ``stereo``:
    IN if non-zero, the view is rendered in stereo mode. 

Parameter ``antiAlias``:
    IN if non-zero, the view is antialiased.

Parameter ``view``:
    IN number of view to save. 

Returns:
    eSUCCESS: if the view is rendered successfully. <br>eMDLERR_BADVIEWNUMBER: 
    if the view number is invalid. <br>eMDLERR_INSFMEMORY: if a memory error occurs.
    <br>eMDLERR_CANNOTOPENFILE: if the file cannot be created)doc";

static const char* __doc_mdlImage_saveViewToRGB = R"doc(@Description Renders the specified view and stores the image in the
RGB buffer. 

Parameter ``imageSizeR``:
    IN size of image to render (in X and Y pixels). 

Parameter ``renderMode``:
    IN the rendering mode (SMOOTH, MSRenderMode::Phong, CONSTANT, etc.). 

Parameter ``stereo``:
    IN if non-zero, the view is rendered in stereo mode. 

Parameter ``antiAlias``:
    IN if non-zero, the view is antialiased.

Parameter ``view``:
    IN number of view to save. 

Returns:
    A tuple object containing 2 elements:

tuple[0] int:
    eSUCCESS: if the view is rendered successfully. <br>eMDLERR_BADVIEWNUMBER: 
    if the view number is invalid. <br>eMDLERR_INSFMEMORY: if a memory error occurs.
    <br>eMDLERR_CANNOTOPENFILE: if the file cannot be created.

tuple[1] bytearray:
    bytearray object to receive the RGB image data)doc";


static const char* __doc_mdlImage_saveViewToRGBA = R"doc(@Description Renders the specified view and stores the image in the
RGB buffer. 

Parameter ``imageSizeR``:
    IN size of image to render (in X and Y pixels). 

Parameter ``renderMode``:
    IN the rendering mode (SMOOTH, MSRenderMode::Phong, CONSTANT, etc.). 

Parameter ``stereo``:
    IN if non-zero, the view is rendered in stereo mode. 

Parameter ``antiAlias``:
    IN if non-zero, the view is antialiased.

Parameter ``view``:
    IN number of view to save. 

Returns:
    A tuple object containing 2 elements:

tuple[0] int:
    eSUCCESS: if the view is rendered successfully. <br>eMDLERR_BADVIEWNUMBER: 
    if the view number is invalid. <br>eMDLERR_INSFMEMORY: if a memory error occurs.
    <br>eMDLERR_CANNOTOPENFILE: if the file cannot be created.

tuple[1] bytearray:
    bytearray object to receive the RGBA image data.)doc";

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
		Byte* imageMapP;
		int retVal = mdlImage_resize (&imageMapP, &outputsize, (Byte*)inputImageR.data(), &inputsize);

        py::bytearray imageMap;

        if (SUCCESS == retVal)
            imageMap = py::bytearray((const char*)imageMapP, outputsize.x * outputsize.y * 3);

        return py::make_tuple(retVal, imageMap);
        }, "outputsize"_a, "inputImageR"_a, "inputsize"_a, DOC(mdlImage_resize));

    c1.def_static("readFileInfo", [](WCharCP fileName, DgnPlatform::ImageFileFormat fileType)
        {
        Point2d imageSize;
        DgnPlatform::ImageColorMode  colorMode;
        int  orientation;

        int retVal = mdlImage_readFileInfo(&imageSize, &colorMode, &orientation, fileName, fileType);

        return py::make_tuple(retVal, imageSize, colorMode, orientation);
        }, "fileName"_a, "fileType"_a, py::call_guard<py::gil_scoped_release>(), DOC(mdlImage_readFileInfo));

    c1.def_static("readFileToRGB", [](WCharCP fileName, DgnPlatform::ImageFileFormat fileType, boost::optional<Point2d> requestedSize)
        {
		Byte *imageBufferP = nullptr;
        Point2d outputSize;

        int retVal = mdlImage_readFileToRGB(&imageBufferP, &outputSize, fileName, fileType, requestedSize.get_ptr ());
        py::bytearray imageMap;

        if (SUCCESS == retVal)
            {
            imageMap = py::bytearray((const char*)imageBufferP, outputSize.x * outputSize.y * 3);
            mdlImage_freeImage(imageBufferP, &outputSize, IMAGEFORMAT_RGB);
            }

        return py::make_tuple(retVal, imageMap, outputSize);
        }, "fileName"_a, "fileType"_a, "requestedSize"_a, DOC(mdlImage_readFileToRGB));

    c1.def_static("extCreateFileFromRGB", [](WCharCP name, DgnPlatform::ImageFileFormat type, DgnPlatform::ImageColorMode colorMode, Point2dR sizeR,
                                             py::bytearray& imageBufferR, DgnPlatform::CompressionType compressType, 
                                             DgnPlatform::CompressionRatio compressRatio, boost::optional<py::bytearray> transparency)
        {
        Byte* transP = nullptr;
        if (transparency.get_ptr())
            transP = (Byte*)(transparency.get_ptr()->data());
                      
        return mdlImage_extCreateFileFromRGB (name, type, colorMode, &sizeR, (Byte*)imageBufferR.data(), compressType, compressRatio, transP);
        }, "name"_a, "type"_a, "colorMode"_a, "sizeR"_a, "imageBufferR"_a, "compressType"_a, "compressRatio"_a, "transparency"_a, DOC(mdlImage_extCreateFileFromRGB));

    c1.def_static("getExtension", [](DgnPlatform::ImageFileFormat type)
        {
        WChar ext[MAXEXTENSIONLENGTH];

        int retVal = mdlImage_getExtension (ext, type);

        return py::make_tuple(retVal, ext);
        },"type"_a, DOC(mdlImage_getExtension));

    c1.def_static("getExportSupport", [](DgnPlatform::ImageFileFormat imageType)
        {
        DgnPlatform::ImageColorMode defaultMode;
        bool rgbSupport, palette256Support, palette16Support, greyScaleSupport, monochromeSupport;

        int retVal = mdlImage_getExportSupport (&defaultMode, &rgbSupport, &palette256Support, &palette16Support, &greyScaleSupport, &monochromeSupport, imageType);

        return py::make_tuple(retVal, defaultMode, rgbSupport, palette256Support, palette16Support, greyScaleSupport, monochromeSupport);
        },"type"_a, DOC(mdlImage_getExportSupport));

    c1.def_static("getImportFormatString", [](DgnPlatform::ImageFileFormat formatId)
        {
        WChar formatName[512];

        int retVal = mdlImage_getImportFormatString(formatName, 512, formatId);

        return py::make_tuple(retVal, formatName);
        }, "formatId"_a, DOC(mdlImage_getImportFormatString));

    c1.def_static("getExportFormatString", [](DgnPlatform::ImageFileFormat formatId)
        {
        WChar formatName[512];

        int retVal = mdlImage_getExportFormatString (formatName, 512, formatId);

        return py::make_tuple(retVal, formatName);
        },"formatId"_a, DOC(mdlImage_getExportFormatString));

    c1.def_static("typeFromExtension", &mdlImage_typeFromExtension, "fileName"_a, DOC(mdlImage_typeFromExtension));
    c1.def_static("applyGamma", [](py::bytearray& rgb, Point2dR sizeR, double gamma)
        {
        mdlImage_applyGamma((Byte*)rgb.data(), (Byte*)rgb.data(), &sizeR, gamma);
        }, "rgb"_a, "sizeR"_a, "gamma"_a, DOC(mdlImage_applyGamma));

    c1.def_static("negate", [](py::bytearray& rgb, Point2dR sizeR)
        {
        mdlImage_negate((Byte*)rgb.data(), (Byte*)rgb.data(), &sizeR);
        }, "rgb"_a, "sizeR"_a, DOC(mdlImage_negate));


    c1.def_static("extractSubImage", [] (Point2dR outSizeR, py::bytearray& inR, Point2dR inSizeR, BSIRectR rectR, int imageFormat)
        {
        int             bufsize = mdlImage_memorySize (&outSizeR, imageFormat);
        py::bytearray   out = py::bytearray(nullptr, bufsize);

        int retVal = mdlImage_extractSubImage((Byte*)out.data(), &outSizeR, (Byte*)inR.data(), &inSizeR, &rectR, imageFormat);

        return py::make_tuple(retVal, out);
        }, "outSizeR"_a, "inR"_a, "inSizeR"_a, "rectR"_a, "imageFormat"_a, DOC(mdlImage_extractSubImage));

    c1.def_static("tintImage", [](py::bytearray& imageR, Point2dR imageSizeR, RgbColorDef* tintRGBP)
        {
        mdlImage_tintImage((Byte*)imageR.data(), &imageSizeR, tintRGBP);
        }, "imageR"_a, "imageSizeR"_a, "tintRGBP"_a, DOC(mdlImage_tintImage));

    c1.def_static("rotate", [](py::bytearray& inpBufferR, Point2dR imageSizeR, int imageFormat, int rotation)
        {
        Byte        *outBufferP = nullptr;
        Point2d     outSize;

        int retVal = mdlImage_rotate(&outBufferP, &outSize, (Byte*)inpBufferR.data(), &imageSizeR, imageFormat, rotation);

        py::bytearray outImage;

        if (SUCCESS == retVal)
            {
            int bufsize = mdlImage_memorySize (&outSize, imageFormat);
            outImage = py::bytearray((const char*)outBufferP, bufsize);
            mdlImage_freeImage((Byte*)outBufferP, &outSize, imageFormat);
            }

        return py::make_tuple(retVal, outImage, outSize);
        }, "inpBufferR"_a, "imageSizeR"_a, "imageFormat"_a, "rotation"_a, DOC(mdlImage_rotate));

    c1.def_static("mirror", [](py::bytearray& rgb, Point2dR imageSizeR, int imageFormat, bool vertical)
        {
        return mdlImage_mirror((Byte*)rgb.data(), &imageSizeR, imageFormat, vertical);

        }, "rgb"_a, "imageSizeR"_a, "imageFormat"_a, "vertical"_a, DOC(mdlImage_mirror));

    c1.def_static("memorySize", &mdlImage_memorySize, "sizeP"_a, "imageFormat"_a, DOC(mdlImage_memorySize));
    c1.def_static("typeFromFile", &mdlImage_typeFromFile, "fileNameP"_a, DOC(mdlImage_typeFromFile));
    c1.def_static("fileType", &mdlImage_fileType, "fileType"_a, "fileNameP"_a, DOC(mdlImage_fileType));

    c1.def_static("RGBToRGBSeparate", [](py::bytearray& rgbInterlacedR, Point2dR imageSizeR, DgnPlatform::ImageColorMode colorMode)
        {
        int             imgFmt = (colorMode == DgnPlatform::ImageColorMode::RGB ? IMAGEFORMAT_RGB : IMAGEFORMAT_RGBA);
        int             bufsize = mdlImage_memorySize (&imageSizeR, imgFmt);
        py::bytearray   imageMap = py::bytearray(nullptr, bufsize);

        int retVal =  mdlImage_RGBToRGBSeparate((Byte*)imageMap.data (), (Byte*)rgbInterlacedR.data(), &imageSizeR, colorMode);

        return py::make_tuple(retVal, imageMap); 
        }, "rgbInterlacedR"_a, "imageSizeR"_a, "colorMode"_a, DOC(mdlImage_RGBToRGBSeparate));

    c1.def_static("RGBToRGBSeparateInPlace", [](py::bytearray& rgb, Point2dR imageSizeR, DgnPlatform::ImageColorMode colorMode)
        {
        return mdlImage_RGBToRGBSeparate((Byte*)rgb.data(), (Byte*)rgb.data(), &imageSizeR, colorMode);
        }, "rgb"_a, "imageSizeR"_a, "colorMode"_a, DOC(mdlImage_RGBToRGBSeparateInPlace));

    c1.def_static("RGBSeparateToRGBInPlace", [](py::bytearray& rgb, Point2dR imageSizeR, DgnPlatform::ImageColorMode colorMode)
        {
        return mdlImage_RGBSeparateToRGB((Byte*)rgb.data(), (Byte*)rgb.data(), &imageSizeR, colorMode);
        }, "rgb"_a, "imageSizeR"_a, "colorMode"_a, DOC(mdlImage_RGBSeparateToRGBInPlace));

    c1.def_static("RGBSeparateToBGR", []( py::bytearray& rgbSeparate, Point2dR imageSizeR, DgnPlatform::ImageColorMode colorMode)
        {
        int             imgFmt = (colorMode == DgnPlatform::ImageColorMode::RGB ? IMAGEFORMAT_RGB : IMAGEFORMAT_RGBA);
        int             bufsize = mdlImage_memorySize (&imageSizeR, imgFmt);
        py::bytearray   imageMap = py::bytearray(nullptr, bufsize);

        int retVal = mdlImage_RGBSeparateToBGR((Byte*)imageMap.data(), (Byte*)rgbSeparate.data(), &imageSizeR, colorMode);

        return py::make_tuple(retVal, imageMap);
        }, "rgbSeparate"_a, "imageSizeR"_a, "colorMode"_a, DOC(mdlImage_RGBSeparateToBGR));

    c1.def_static("saveView", [](WCharCP fileNameP, Point2dR imageSizeR, int renderMode, DgnPlatform::ImageFileFormat imageFormat, bool stereo, bool antialias, int view)
        {
        return mdlImage_saveView(fileNameP, &imageSizeR, renderMode, imageFormat, stereo, antialias, view);

        }, "fileNameP"_a, "imageSizeR"_a, "renderMode"_a, "imageFormat"_a, "stereo"_a, "antialias"_a, "view"_a, DOC(mdlImage_saveView));

    c1.def_static("saveViewToRGB", [](Point2dR imageSizeR, int renderMode, bool stereo, bool antialias, int view)
        {
        Byte* imageMapP = nullptr;    

        int retVal = mdlImage_saveViewToRGB(&imageMapP, &imageSizeR, renderMode, stereo, antialias, view);

        py::bytearray imageMap;

        if (SUCCESS == retVal)
            {
            imageMap = py::bytearray((const char*)imageMapP, imageSizeR.x * imageSizeR.y* 3);
            dlmSystem_mdlFree (imageMapP);
            }
        return py::make_tuple(retVal, imageMap);
        }, "imageSizeR"_a, "renderMode"_a, "stereo"_a, "antialias"_a, "view"_a, DOC(mdlImage_saveViewToRGB));
    
    c1.def_static("saveViewToRGBA", [](Point2dR imageSizeR, int renderMode, bool stereo, bool antialias, int view)
        {
        Byte* imageMapP = nullptr;    

        int retVal = mdlImage_saveViewToRGBA(&imageMapP, &imageSizeR, renderMode, stereo, antialias, view);

        py::bytearray imageMap;

        if (SUCCESS == retVal)
            {
            imageMap = py::bytearray((const char*)imageMapP, imageSizeR.x * imageSizeR.y* 4);
            dlmSystem_mdlFree (imageMapP);
            }
        return py::make_tuple(retVal, imageMap);
        }, "imageSizeR"_a, "renderMode"_a, "stereo"_a, "antialias"_a, "view"_a, DOC(mdlImage_saveViewToRGBA));
    }
