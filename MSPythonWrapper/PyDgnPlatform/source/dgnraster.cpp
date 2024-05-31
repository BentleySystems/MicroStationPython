/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgnraster.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <RasterCore/RasterFile.h>
#include <RasterCore/RasterSource.h>
#include <RasterCore/DgnRaster.h>
#include <DgnGeoCoord/DgnGeoCoord.h>

USING_NAMESPACE_RASTER

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       9/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnRaster(py::module_& m)
    {
    if (!PyNameSpaceManager::IsNameSpaceUsing(PyNameSpaceManager::Bentley_DgnPlatform_Raster))
        return;

    // Enum RasterFileStatus
    py::enum_<RasterFileStatus>(m, "RasterFileStatus")
        .value("eRASTERFILE_STATUS_Opened", RasterFileStatus::RASTERFILE_STATUS_Opened)
        .value("eRASTERFILE_STATUS_UnknownError", RasterFileStatus::RASTERFILE_STATUS_UnknownError)
        .value("eRASTERFILE_STATUS_Invalid", RasterFileStatus::RASTERFILE_STATUS_Invalid)
        .value("eRASTERFILE_STATUS_Missing", RasterFileStatus::RASTERFILE_STATUS_Missing)
        .value("eRASTERFILE_STATUS_ConnectionError", RasterFileStatus::RASTERFILE_STATUS_ConnectionError)
        .value("eRASTERFILE_STATUS_Closed", RasterFileStatus::RASTERFILE_STATUS_Closed)
        .value("eRASTERFILE_STATUS_InvalidPassword", RasterFileStatus::RASTERFILE_STATUS_InvalidPassword)
        .value("eRASTERFILE_STATUS_InvalidAccessMode", RasterFileStatus::RASTERFILE_STATUS_InvalidAccessMode)
        .export_values();

    //Struct RasterFile
    py::class_< RasterFile, RefCountedPtr<RasterFile>> c4(m, "RasterFile");

    c4.def_property_readonly("NumberOfPages", &RasterFile::GetNumberOfPages);
    c4.def("GetNumberOfPages", &RasterFile::GetNumberOfPages);

    c4.def_property_readonly("ReadOnly", &RasterFile::IsReadOnly);
    c4.def("IsReadOnly", &RasterFile::IsReadOnly);

    c4.def_property_readonly("Status", &RasterFile::GetStatus);
    c4.def("GetStatus", &RasterFile::GetStatus);

    c4.def_property_readonly("FileFormat", &RasterFile::GetFileFormat);
    c4.def("GetFileFormat", &RasterFile::GetFileFormat);

    c4.def_property_readonly("Document", &RasterFile::GetDocumentCP);
    c4.def("GetDocument", &RasterFile::GetDocumentCP);

    //Struct RasterFileManager
    py::class_< RasterFileManager, std::unique_ptr<RasterFileManager, py::nodelete>>(m, "RasterFileManager");

    //Struct RasterSource
    py::class_< RasterSource, RefCountedPtr<RasterSource>> c2(m, "RasterSource");

    c2.def("IsValidSource", &RasterSource::IsValidSource);

    c2.def_property_readonly("RasterFile", &RasterSource::GetRasterFile);
    c2.def("GetRasterFile", &RasterSource::GetRasterFile);

    c2.def_property_readonly("PageNumber", &RasterSource::GetPageNumber);
    c2.def("GetPageNumber", &RasterSource::GetPageNumber);

    c2.def_property_readonly("BitmapHeight", &RasterSource::GetBitmapHeight);
    c2.def("GetBitmapHeight", &RasterSource::GetBitmapHeight);

    c2.def_property_readonly("BitmapWidth", &RasterSource::GetBitmapWidth);
    c2.def("GetBitmapWidth", &RasterSource::GetBitmapWidth);

    c2.def_property_readonly("ColorMode", &RasterSource::GetColorMode);
    c2.def("GetColorMode", &RasterSource::GetColorMode);

    // Struct DgnRasterOpenParams
    py::class_< DgnRasterOpenParams, RefCountedPtr<DgnRasterOpenParams>> c1(m, "DgnRasterOpenParams");

    c1.def_static("Create", &DgnRasterOpenParams::Create, "moniker"_a, "readonly"_a);

    c1.def("Clone", &DgnRasterOpenParams::Clone);

    c1.def_property_readonly ("FileName", &DgnRasterOpenParams::GetFilename);
    c1.def("GetFilename", &DgnRasterOpenParams::GetFilename);

    c1.def_property_readonly("Filespec", &DgnRasterOpenParams::GetFilespec);
    c1.def("GetFilespec", &DgnRasterOpenParams::GetFilespec);

    c1.def_property("AttachMoniker", &DgnRasterOpenParams::GetAttachMoniker, &DgnRasterOpenParams::SetAttachMoniker);
    c1.def("GetAttachMoniker", &DgnRasterOpenParams::GetAttachMoniker);
    c1.def("SetAttachMoniker", &DgnRasterOpenParams::SetAttachMoniker);

    c1.def_property("OpenReadOnly", &DgnRasterOpenParams::IsOpenReadOnly, &DgnRasterOpenParams::SetOpenReadOnly);
    c1.def("IsOpenReadOnly", &DgnRasterOpenParams::IsOpenReadOnly);
    c1.def("SetOpenReadOnly", &DgnRasterOpenParams::SetOpenReadOnly);

    // Struct DgnRaster
    py::class_< DgnRaster, RefCountedPtr<DgnRaster>> c0(m, "DgnRaster");

    c0.def_static("Create", [](DgnRasterOpenParamsR openParams, DgnModelRefR modelRef) {
        DgnRasterStatus status;
        DgnRasterPtr dgnRasterPtr = DgnRaster::Create(status, openParams, modelRef);
        return py::make_tuple(dgnRasterPtr, status);
        }, "openParams"_a, "modelRef"_a);

    c0.def_property_readonly("OpenParams", &DgnRaster::GetOpenParams);
    c0.def("GetOpenParams", &DgnRaster::GetOpenParams);

    c0.def("AddToModel", &DgnRaster::AddToModel);
    c0.def("DeleteFromModel", &DgnRaster::DeleteFromModel);
    c0.def("ReplaceInModel", &DgnRaster::ReplaceInModel);

    c0.def_property_readonly("ElementRef", &DgnRaster::GetElementRef);
    c0.def("GetElementRef", &DgnRaster::GetElementRef);

    c0.def_property_readonly("ModelRef", &DgnRaster::GetModelRefP);
    c0.def("GetModelRef", &DgnRaster::GetModelRefP);

    c0.def_property("Level", &DgnRaster::GetLevel, &DgnRaster::SetLevel);
    c0.def("GetLevel", &DgnRaster::GetLevel);
    c0.def("SetLevel", &DgnRaster::SetLevel, "level"_a);

    c0.def_property("Description", &DgnRaster::GetDescription, &DgnRaster::SetDescription);
    c0.def("GetDescription", &DgnRaster::GetDescription);
    c0.def("SetDescription", &DgnRaster::SetDescription, "description"_a);

    c0.def_property("LogicalName", &DgnRaster::GetLogicalName, &DgnRaster::SetLogicalName);
    c0.def("GetLogicalName", &DgnRaster::GetLogicalName);
    c0.def("SetLogicalName", &DgnRaster::SetLogicalName, "logicalName"_a);

    c0.def_static("IsLogicalNameUnique", &DgnRaster::IsLogicalNameUnique, "logicalName"_a, "dgnModel"_a);

    c0.def_property("SnappableState", &DgnRaster::GetSnappableState, &DgnRaster::SetSnappableState);
    c0.def("GetSnappableState", &DgnRaster::GetSnappableState);
    c0.def("SetSnappableState", &DgnRaster::SetSnappableState, "state"_a);

    c0.def_property("LockedState", &DgnRaster::GetLockedState, &DgnRaster::SetLockedState);
    c0.def("GetLockedState", &DgnRaster::GetLockedState);
    c0.def("SetLockedState", &DgnRaster::SetLockedState, "state"_a);

    c0.def_property("ViewIndependentState", &DgnRaster::GetViewIndependentState, &DgnRaster::SetViewIndependentState);
    c0.def("GetViewIndependentState", &DgnRaster::GetViewIndependentState);
    c0.def("SetViewIndependentState", &DgnRaster::SetViewIndependentState, "state"_a);

    c0.def_property("GCSInheritedFromModelState", &DgnRaster::GetGCSInheritedFromModelState, &DgnRaster::SetGCSInheritedFromModelState);
    c0.def("GetGCSInheritedFromModelState", &DgnRaster::GetGCSInheritedFromModelState);
    c0.def("SetGCSInheritedFromModelState", &DgnRaster::SetGCSInheritedFromModelState, "state"_a);

    c0.def_property("Transform", &DgnRaster::GetTransform, &DgnRaster::SetTransform);
    c0.def("GetTransform", &DgnRaster::GetTransform);
    c0.def("SetTransform", &DgnRaster::SetTransform, "georef"_a);

    c0.def_property("ScanningResolution", &DgnRaster::GetScanningResolution, &DgnRaster::SetScanningResolution);
    c0.def("GetScanningResolution", &DgnRaster::GetScanningResolution);
    c0.def("SetScanningResolution", &DgnRaster::SetScanningResolution, "scanningResolutionDPI"_a);

    c0.def("GetViewState", &DgnRaster::GetViewState, "viewNumber"_a);
    c0.def("SetViewState", &DgnRaster::SetViewState, "viewNumber"_a, "state"_a);

    c0.def_property("InvertState", &DgnRaster::GetInvertState, &DgnRaster::SetInvertState);
    c0.def("GetInvertState", &DgnRaster::GetInvertState);
    c0.def("SetInvertState", &DgnRaster::SetInvertState, "state"_a);

    c0.def_property("PrintState", &DgnRaster::GetPrintState, &DgnRaster::SetPrintState);
    c0.def("GetPrintState", &DgnRaster::GetPrintState);
    c0.def("SetPrintState", &DgnRaster::SetPrintState, "state"_a);

    c0.def_property("ClipState", &DgnRaster::GetClipState, &DgnRaster::SetClipState);
    c0.def("GetClipState", &DgnRaster::GetClipState);
    c0.def("SetClipState", &DgnRaster::SetClipState, "state"_a);

    c0.def_property("TransparencyState", &DgnRaster::GetTransparencyState, &DgnRaster::SetTransparencyState);
    c0.def("GetTransparencyState", &DgnRaster::GetTransparencyState);
    c0.def("SetTransparencyState", &DgnRaster::SetTransparencyState, "state"_a);

    c0.def_property("BinaryPrintInvertState", &DgnRaster::GetBinaryPrintInvertState, &DgnRaster::SetBinaryPrintInvertState);
    c0.def("GetBinaryPrintInvertState", &DgnRaster::GetBinaryPrintInvertState);
    c0.def("SetBinaryPrintInvertState", &DgnRaster::SetBinaryPrintInvertState, "state"_a);

    c0.def_property("DisplayPriorityPlane", &DgnRaster::GetDisplayPriorityPlane, &DgnRaster::SetDisplayPriorityPlane);
    c0.def("GetDisplayPriorityPlane", &DgnRaster::GetDisplayPriorityPlane);
    c0.def("SetDisplayPriorityPlane", &DgnRaster::SetDisplayPriorityPlane, "plane"_a);

    c0.def_property("ViewGamma", &DgnRaster::GetViewGamma, &DgnRaster::SetViewGamma);
    c0.def("GetViewGamma", &DgnRaster::GetViewGamma);
    c0.def("SetViewGamma", &DgnRaster::SetViewGamma, "gamma"_a);

    c0.def_property("PrintGamma", &DgnRaster::GetPrintGamma, &DgnRaster::SetPrintGamma);
    c0.def("GetPrintGamma", &DgnRaster::GetPrintGamma);
    c0.def("SetPrintGamma", &DgnRaster::SetPrintGamma, "gamma"_a);

    c0.def_property("TintColor", &DgnRaster::GetTintColor, &DgnRaster::SetTintColor);
    c0.def("GetTintColor", &DgnRaster::GetTintColor);
    c0.def("SetTintColor", &DgnRaster::SetTintColor, "rawColorIndex"_a);

    c0.def_property("ForegroundColor", &DgnRaster::GetForegroundColor, &DgnRaster::SetForegroundColor);
    c0.def("GetForegroundColor", &DgnRaster::GetForegroundColor);
    c0.def("SetForegroundColor", &DgnRaster::SetForegroundColor, "rawColorIndex"_a);

    c0.def_property("BackgroundColor", &DgnRaster::GetBackgroundColor, &DgnRaster::SetBackgroundColor);
    c0.def("GetBackgroundColor", &DgnRaster::GetBackgroundColor);
    c0.def("SetBackgroundColor", &DgnRaster::SetBackgroundColor, "rawColorIndex"_a);

    c0.def_property("Contrast", &DgnRaster::GetContrast, &DgnRaster::SetContrast);
    c0.def("GetContrast", &DgnRaster::GetContrast);
    c0.def("SetContrast", &DgnRaster::SetContrast, "contrast"_a);

    c0.def_property("Brightness", &DgnRaster::GetBrightness, &DgnRaster::SetBrightness);
    c0.def("GetBrightness", &DgnRaster::GetBrightness);
    c0.def("SetBrightness", &DgnRaster::SetBrightness, "brightness"_a);

    c0.def_property("ImageTransparencyLevel", &DgnRaster::GetImageTransparencyLevel, &DgnRaster::SetImageTransparencyLevel);
    c0.def("GetImageTransparencyLevel", &DgnRaster::GetImageTransparencyLevel);
    c0.def("SetImageTransparencyLevel", &DgnRaster::SetImageTransparencyLevel, "transparency"_a);

    c0.def_property("BackgroundTransparencyLevel", &DgnRaster::GetBackgroundTransparencyLevel, &DgnRaster::SetBackgroundTransparencyLevel);
    c0.def("GetBackgroundTransparencyLevel", &DgnRaster::GetBackgroundTransparencyLevel);
    c0.def("SetBackgroundTransparencyLevel", &DgnRaster::SetBackgroundTransparencyLevel, "transparency"_a);

    c0.def_property("ForegroundTransparencyLevel", &DgnRaster::GetForegroundTransparencyLevel, &DgnRaster::SetForegroundTransparencyLevel);
    c0.def("GetForegroundTransparencyLevel", &DgnRaster::GetForegroundTransparencyLevel);
    c0.def("SetForegroundTransparencyLevel", &DgnRaster::SetForegroundTransparencyLevel, "transparency"_a);

    c0.def("GetTransparentColors", &DgnRaster::GetTransparentColors, "transparentColors"_a);
    c0.def("SetTransparentColors", &DgnRaster::SetTransparentColors, "transparentColors"_a);

    c0.def_property("DgnGCS", &DgnRaster::GetDgnGCSCP, &DgnRaster::SetDgnGCS);
    c0.def("GetDgnGCS", &DgnRaster::GetDgnGCSCP);
    c0.def("SetDgnGCS", &DgnRaster::SetDgnGCS, "RasterDgnGCS"_a);

    c0.def_property("ClipProperties", &DgnRaster::GetClipProperties, &DgnRaster::SetClipProperties);
    c0.def("GetClipProperties", &DgnRaster::GetClipProperties);
    c0.def("SetClipProperties", &DgnRaster::SetClipProperties, "clipProp"_a);

    c0.def_property_readonly("ReadOnly", &DgnRaster::IsReadOnly);
    c0.def("IsReadOnly", &DgnRaster::IsReadOnly);

    c0.def_property_readonly("RasterSource", &DgnRaster::GetRasterSourceCP);
    c0.def("GetRasterSource", &DgnRaster::GetRasterSourceCP);
    }
