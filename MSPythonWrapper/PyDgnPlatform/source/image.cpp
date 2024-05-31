/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\image.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/image.h>



/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_image(py::module_& m)
    {
    //===================================================================================
    // enum VideoFileFormat
    py::enum_< VideoFileFormat>(m, "VideoFileFormat", py::arithmetic())
        .value("eVIDEOFILE_FLI", VIDEOFILE_FLI)
        .value("eVIDEOFILE_FLC", VIDEOFILE_FLC)
        .value("eVIDEOFILE_AVI", VIDEOFILE_AVI)
        .value("eVIDEOFILE_WMV", VIDEOFILE_WMV)
        .export_values();

    //===================================================================================
    // enum ImageFileFormat
    py::enum_< ImageFileFormat>(m, "ImageFileFormat", py::arithmetic())
        .value("eIMAGEFILE_UNKNOWN", IMAGEFILE_UNKNOWN)
        .value("eIMAGEFILE_RGB", IMAGEFILE_RGB)
        .value("eIMAGEFILE_TARGA", IMAGEFILE_TARGA)
        .value("eIMAGEFILE_TIFF", IMAGEFILE_TIFF)
        .value("eIMAGEFILE_PICT", IMAGEFILE_PICT)
        .value("eIMAGEFILE_PCX", IMAGEFILE_PCX)
        .value("eIMAGEFILE_POSTSCRIPT", IMAGEFILE_POSTSCRIPT)
        .value("eIMAGEFILE_GIF", IMAGEFILE_GIF)
        .value("eIMAGEFILE_WPG", IMAGEFILE_WPG)
        .value("eIMAGEFILE_BMP", IMAGEFILE_BMP)
        .value("eIMAGEFILE_SUNRASTER", IMAGEFILE_SUNRASTER)
        .value("eIMAGEFILE_IMGMAPPED", IMAGEFILE_IMGMAPPED)
        .value("eIMAGEFILE_IMGRGB", IMAGEFILE_IMGRGB)
        .value("eIMAGEFILE_RLE", IMAGEFILE_RLE)
        .value("e_IMAGEFILE_FLI", _IMAGEFILE_FLI)
        .value("e_IMAGEFILE_FLC", _IMAGEFILE_FLC)
        .value("eIMAGEFILE_BUMP", IMAGEFILE_BUMP)
        .value("eIMAGEFILE_COT", IMAGEFILE_COT)
        .value("eIMAGEFILE_JPEG", IMAGEFILE_JPEG)
        .value("eIMAGEFILE_CIT", IMAGEFILE_CIT)
        .value("eIMAGEFILE_TG4", IMAGEFILE_TG4)
        .value("eIMAGEFILE_FAX", IMAGEFILE_FAX)
        .value("eIMAGEFILE_CALS", IMAGEFILE_CALS)
        .value("eIMAGEFILE_INGR", IMAGEFILE_INGR)
        .value("eIMAGEFILE_RLC", IMAGEFILE_RLC)
        .value("eIMAGEFILE_PACKBYTE", IMAGEFILE_PACKBYTE)
        .value("e_IMAGEFILE_AVI", _IMAGEFILE_AVI)
        .value("eIMAGEFILE_PROCEDURE", IMAGEFILE_PROCEDURE)
        .value("eIMAGEFILE_PNG", IMAGEFILE_PNG)
        .value("eIMAGEFILE_GEOTIFF", IMAGEFILE_GEOTIFF)
        .value("eIMAGEFILE_HMR", IMAGEFILE_HMR)
        .value("eIMAGEFILE_ITIFF", IMAGEFILE_ITIFF)
        .value("eIMAGEFILE_C29", IMAGEFILE_C29)
        .value("eIMAGEFILE_MRSID", IMAGEFILE_MRSID)
        .value("eIMAGEFILE_ERMAPPER", IMAGEFILE_ERMAPPER)
        .value("eIMAGEFILE_TIFFINTGR", IMAGEFILE_TIFFINTGR)
        .value("eIMAGEFILE_MULTICHANNEL", IMAGEFILE_MULTICHANNEL)
        .value("eIMAGEFILE_C30", IMAGEFILE_C30)
        .value("eIMAGEFILE_C31", IMAGEFILE_C31)
        .value("eIMAGEFILE_EPX", IMAGEFILE_EPX)
        .value("eIMAGEFILE_BIL", IMAGEFILE_BIL)
        .value("eIMAGEFILE_JPEG2000", IMAGEFILE_JPEG2000)
        .value("eIMAGEFILE_MPF", IMAGEFILE_MPF)
        .value("eIMAGEFILE_CRL", IMAGEFILE_CRL)
        .value("eIMAGEFILE_LRD", IMAGEFILE_LRD)
        .value("eIMAGEFILE_DOQ", IMAGEFILE_DOQ)
        .value("eIMAGEFILE_WBMP", IMAGEFILE_WBMP)
        .value("eIMAGEFILE_ERDASIMG", IMAGEFILE_ERDASIMG)
        .value("eIMAGEFILE_NITF", IMAGEFILE_NITF)
        .value("eIMAGEFILE_DTED", IMAGEFILE_DTED)
        .value("eIMAGEFILE_ITIFF64", IMAGEFILE_ITIFF64)
        .value("eIMAGEFILE_XWMS", IMAGEFILE_XWMS)
        .value("e_IMAGEFILE_WMV", _IMAGEFILE_WMV)
        .value("eIMAGEFILE_PDF", IMAGEFILE_PDF)
        .value("eIMAGEFILE_BINGMAPS", IMAGEFILE_BINGMAPS)
        .value("eIMAGEFILE_BSB", IMAGEFILE_BSB)
        .value("eIMAGEFILE_XWCS", IMAGEFILE_XWCS)
        .value("eIMAGEFILE_USGSDEM", IMAGEFILE_USGSDEM)
        .value("eIMAGEFILE_USGSSDTSDEM", IMAGEFILE_USGSSDTSDEM)
        .value("eIMAGEFILE_XORA", IMAGEFILE_XORA)
        .value("eIMAGEFILE_SPOTDIMAP", IMAGEFILE_SPOTDIMAP)
        .value("eIMAGEFILE_AIG", IMAGEFILE_AIG)
        .value("eIMAGEFILE_AAIG", IMAGEFILE_AAIG)
        .value("eIMAGEFILE_PSD", IMAGEFILE_PSD)
        .value("eIMAGEFILE_POWERVRTEXTURE", IMAGEFILE_POWERVRTEXTURE)
        .export_values();

    //===================================================================================
    // enum ImageFormat
    py::enum_< ImageFormat>(m, "ImageFormat", py::arithmetic())
        .value("eIMAGEFORMAT_BitMap", IMAGEFORMAT_BitMap)
        .value("eIMAGEFORMAT_RLEBitMap", IMAGEFORMAT_RLEBitMap)
        .value("eIMAGEFORMAT_ByteMap", IMAGEFORMAT_ByteMap)
        .value("eIMAGEFORMAT_GreyScale", IMAGEFORMAT_GreyScale)
        .value("eIMAGEFORMAT_RGBSeparate", IMAGEFORMAT_RGBSeparate)
        .value("eIMAGEFORMAT_RGB", IMAGEFORMAT_RGB)
        .value("eIMAGEFORMAT_RGBA", IMAGEFORMAT_RGBA)
        .value("eIMAGEFORMAT_PackByte", IMAGEFORMAT_PackByte)
        .value("eIMAGEFORMAT_RLEByteMap", IMAGEFORMAT_RLEByteMap)
        .value("eIMAGEFORMAT_BGRA", IMAGEFORMAT_BGRA)
        .value("eIMAGEFORMAT_RGBASeparate", IMAGEFORMAT_RGBASeparate)
        .value("eIMAGEFORMAT_BGRSeparate", IMAGEFORMAT_BGRSeparate)
        .export_values();

    //===================================================================================
    // enum CompressionRatio
    py::enum_< CompressionRatio>(m, "CompressionRatio", py::arithmetic())
        .value("eCOMPRESSIONRATIO_LOSSLESS", COMPRESSIONRATIO_LOSSLESS)
        .value("eCOMPRESSIONRATIO_MIN", COMPRESSIONRATIO_MIN)
        .value("eCOMPRESSIONRATIO_LOW", COMPRESSIONRATIO_LOW)
        .value("eCOMPRESSIONRATIO_MED", COMPRESSIONRATIO_MED)
        .value("eCOMPRESSIONRATIO_HIGH", COMPRESSIONRATIO_HIGH)
        .value("eCOMPRESSIONRATIO_DEFAULT", COMPRESSIONRATIO_DEFAULT)
        .export_values();

    //===================================================================================
    // enum CompressionType
    py::enum_< CompressionType>(m, "CompressionType", py::arithmetic())
        .value("eCOMPRESSTYPE_UNKNOWN", COMPRESSTYPE_UNKNOWN)
        .value("eCOMPRESSTYPE_NONE", COMPRESSTYPE_NONE)
        .value("eCOMPRESSTYPE_DEFAULT", COMPRESSTYPE_DEFAULT)
        .value("eCOMPRESSTYPE_CCITTRLE", COMPRESSTYPE_CCITTRLE)
        .value("eCOMPRESSTYPE_CCITTFAX3", COMPRESSTYPE_CCITTFAX3)
        .value("eCOMPRESSTYPE_CCITTFAX4", COMPRESSTYPE_CCITTFAX4)
        .value("eCOMPRESSTYPE_LZW", COMPRESSTYPE_LZW)
        .value("eCOMPRESSTYPE_OJPEG", COMPRESSTYPE_OJPEG)
        .value("eCOMPRESSTYPE_JPEG", COMPRESSTYPE_JPEG)
        .value("eCOMPRESSTYPE_BMPRLE8", COMPRESSTYPE_BMPRLE8)
        .value("eCOMPRESSTYPE_BMPRLE4", COMPRESSTYPE_BMPRLE4)
        .value("eCOMPRESSTYPE_GIFLZW", COMPRESSTYPE_GIFLZW)
        .value("eCOMPRESSTYPE_NEXT", COMPRESSTYPE_NEXT)
        .value("eCOMPRESSTYPE_CCITTRLEW", COMPRESSTYPE_CCITTRLEW)
        .value("eCOMPRESSTYPE_PACKBITS", COMPRESSTYPE_PACKBITS)
        .value("eCOMPRESSTYPE_THUNDERSCAN", COMPRESSTYPE_THUNDERSCAN)
        .value("eCOMPRESSTYPE_PIXARFILM", COMPRESSTYPE_PIXARFILM)
        .value("eCOMPRESSTYPE_DEFLATE", COMPRESSTYPE_DEFLATE)
        .value("eCOMPRESSTYPE_JBIG", COMPRESSTYPE_JBIG)
        .value("eCOMPRESSTYPE_JPEG2000", COMPRESSTYPE_JPEG2000)
        .value("eCOMPRESSTYPE_ECW", COMPRESSTYPE_ECW)
        .value("eCOMPRESSTYPE_RLE1", COMPRESSTYPE_RLE1)
        .value("eCOMPRESSTYPE_RLE8", COMPRESSTYPE_RLE8)
        .value("eCOMPRESSTYPE_ZLIB", COMPRESSTYPE_ZLIB)
        .value("eCOMPRESSTYPE_FLASHPIX", COMPRESSTYPE_FLASHPIX)
        .value("eCOMPRESSTYPE_TGARLE", COMPRESSTYPE_TGARLE)
        .value("eCOMPRESSTYPE_LRD", COMPRESSTYPE_LRD)
        .value("eCOMPRESSTYPE_FLIRLE8", COMPRESSTYPE_FLIRLE8)
        .value("eCOMPRESSTYPE_CRL8", COMPRESSTYPE_CRL8)
        .export_values();

    //===================================================================================
    // enum ImageIngrOrientation
    py::enum_< ImageIngrOrientation>(m, "ImageIngrOrientation", py::arithmetic())
        .value("eINGR_ORIENT_UpperLeftVertical", INGR_ORIENT_UpperLeftVertical)
        .value("eINGR_ORIENT_UpperRightVertical", INGR_ORIENT_UpperRightVertical)
        .value("eINGR_ORIENT_LowerLeftVertical", INGR_ORIENT_LowerLeftVertical)
        .value("eINGR_ORIENT_LowerRightVertical", INGR_ORIENT_LowerRightVertical)
        .value("eINGR_ORIENT_UpperLeftHorizontal", INGR_ORIENT_UpperLeftHorizontal)
        .value("eINGR_ORIENT_UpperRightHorizontal", INGR_ORIENT_UpperRightHorizontal)
        .value("eINGR_ORIENT_LowerLeftHorizontal", INGR_ORIENT_LowerLeftHorizontal)
        .value("eINGR_ORIENT_LowerRightHorizontal", INGR_ORIENT_LowerRightHorizontal)
        .export_values();

    //===================================================================================
    // enum ImageOriginOrientation
    py::enum_< ImageOriginOrientation>(m, "ImageOriginOrientation", py::arithmetic())
        .value("eTOP_LEFT", TOP_LEFT)
        .value("eTOP_RIGHT", TOP_RIGHT)
        .value("eLOWER_LEFT", LOWER_LEFT)
        .value("eLOWER_RIGHT", LOWER_RIGHT)
        .export_values();

    //===================================================================================
    // enum MovieFrameTransition
    py::enum_< MovieFrameTransition>(m, "MovieFrameTransition", py::arithmetic())
        .value("eMOVIE_FrameCut", MOVIE_FrameCut)
        .value("eMOVIE_HorizontalWipe", MOVIE_HorizontalWipe)
        .value("eMOVIE_VerticalWipe", MOVIE_VerticalWipe)
        .value("eMOVIE_Fade", MOVIE_Fade)
        .export_values();
    }