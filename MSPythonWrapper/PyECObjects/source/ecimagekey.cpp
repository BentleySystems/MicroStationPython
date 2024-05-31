/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyECObjects\source\ecimagekey.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <ECPresentation/ecimagekey.h>

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ecimagekey(py::module_& m)
    {
    //===================================================================================
    // struct ECImageKey
    py::class_< ECImageKey> c1(m, "ECImageKey");

    if (true)
        {
        //===================================================================================
        // enum ImageType
        py::enum_< ECImageKey::ImageType>(c1, "ImageType", py::arithmetic())
            .value("eIcon", ECImageKey::Icon)
            .value("eBitmap", ECImageKey::Bitmap)
            .value("eCursor", ECImageKey::Cursor)
            .value("eRscIcon", ECImageKey::RscIcon)
            .export_values();
        }

    c1.def(py::init<WStringCR, ECImageKey::ImageType>(), "name"_a, "type"_a);
    //c1.def(py::init<long, uint32_t, MdlDesc*>(), "name"_a, "type"_a);

    c1.def_property("ImageType", &ECImageKey::GetImageType, &ECImageKey::SetImageType);
    c1.def("GetImageType", &ECImageKey::GetImageType);
    c1.def("SetImageType", &ECImageKey::SetImageType, "type"_a);
    
    c1.def_property("ImageName", &ECImageKey::GetImageName, &ECImageKey::SetImageName);
    c1.def("GetImageName", &ECImageKey::GetImageName, py::return_value_policy::reference_internal);
    c1.def("SetImageName", &ECImageKey::SetImageName, "name"_a);
    
    c1.def_property("IconId", &ECImageKey::GetIconId, &ECImageKey::SetIconId);
    c1.def("GetIconId", &ECImageKey::GetIconId);
    c1.def("SetIconId", &ECImageKey::SetIconId, "rscId"_a);
    
    c1.def_property("IconType", &ECImageKey::GetIconType, &ECImageKey::SetIconType);
    c1.def("GetIconType", &ECImageKey::GetIconType);
    c1.def("SetIconType", &ECImageKey::SetIconType, "iconType"_a);
    }