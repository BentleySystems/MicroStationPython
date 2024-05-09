/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\isettings.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ISettings.h>



static const char * __doc_Bentley_DgnPlatform_IDgnSettings_GetCurrentSettings =R"doc(Static method to find an object which can answer IDgnSettings queries.

Returns:
    Returns a reference to an object that can execute Get methods to
    find various ApplicationSettings objects. Bentley Systems +-------
    -------+--------------+---------------+----------------+----------
    ---)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnSettings_DoesModelSettingsElmExist =R"doc(Tests for existence of the ApplicationSettings element for a model.

Parameter ``cache``:
    pointer to the cache of the model of interest

Returns:
    true if an application settings element exists for the model
    Bentley Systems +--------------+--------------+---------------+---
    -------------+-------------)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnSettings_GetModelApplicationSettings =R"doc(Get the ApplicationSettings element for a model.

Parameter ``cache``:
    pointer to the cache of the model of interest

Returns:
    ApplicationSettings Bentley Systems +--------------+--------------
    +---------------+----------------+-------------)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnSettings_GetFileApplicationSettings =R"doc(Get the ApplicationSettings element for a DgnFile.

Parameter ``file``:
    file of interest

Returns:
    ApplicationSettings Bentley Systems +--------------+--------------
    +---------------+----------------+-------------)doc";

static const char * __doc_Bentley_DgnPlatform_ApplicationSettings_SaveSetting =R"doc(Save an application defined setting on the setting element. This
method should be used rather than directly adding XAttributes to the
setting element since it writes non-undoably (so your settings won't
be part of a transaction and therefore reversed by the Undo command.)

Parameter ``handlerId``:
    the id of the DgnPlatform::XAttributeHandler for this setting.
    While the Id is mandatory, it is not necessary to actually
    implement an DgnPlatform::XAttributeHandler just to save settings
    data. However, implementing an DgnPlatform::XAttributeHandler
    allows applications to participate in change merging of their
    settings data.

Parameter ``settingId``:
    an id for this settting (this should be non-zero).

Parameter ``settingData``:
    the setting data

Parameter ``size``:
    the number of bytes in settingData Bentley Systems +--------------
    +--------------+---------------+----------------+-------------)doc";

static const char * __doc_Bentley_DgnPlatform_ApplicationSettings_GetElementRef =R"doc(Get the ElementRefP of the element holding the settings data. This is
used for accessing the settings XAttributes by creating an
DgnPlatform::XAttributeHandle. Bentley Systems +--------------+-------
-------+---------------+----------------+-------------)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ISettings(py::module_& m)
    {
    //===================================================================================
    // struct ApplicationSettings
    py::class_< ApplicationSettings> c1(m, "ApplicationSettings");

    c1.def_property_readonly("ElementRef", &ApplicationSettings::GetElementRef);
    c1.def("GetElementRef", &ApplicationSettings::GetElementRef, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ApplicationSettings, GetElementRef));

    c1.def("SaveSetting", [] (ApplicationSettings& self, XAttributeHandlerId handlerId, UInt32 settingId, py::bytes const& data)
           {
           std::string strData = (std::string) data;
           self.SaveSetting(handlerId, settingId, (void const*) strData.data(), (UInt32) strData.size());
           }, "handlerId"_a, "settingId"_a, "data"_a, DOC(Bentley, DgnPlatform, ApplicationSettings, SaveSetting));
    
    //===================================================================================
    // struct IDgnSettings
    py::class_< IDgnSettings, std::unique_ptr< IDgnSettings, py::nodelete> > c2(m, "IDgnSettings");

    c2.def("GetFileApplicationSettings", py::overload_cast<DgnFileR>(&IDgnSettings::GetFileApplicationSettings), "file"_a, DOC(Bentley, DgnPlatform, IDgnSettings, GetFileApplicationSettings));
    c2.def("GetFileApplicationSettings", py::overload_cast<DgnModelRefR>(&IDgnSettings::GetFileApplicationSettings), "modelRef"_a, DOC(Bentley, DgnPlatform, IDgnSettings, GetFileApplicationSettings));
    c2.def("GetModelApplicationSettings", py::overload_cast<DgnModelR>(&IDgnSettings::GetModelApplicationSettings), "model"_a, DOC(Bentley, DgnPlatform, IDgnSettings, GetModelApplicationSettings));
    c2.def("GetModelApplicationSettings", py::overload_cast<DgnModelRefR>(&IDgnSettings::GetModelApplicationSettings), "modelRef"_a, DOC(Bentley, DgnPlatform, IDgnSettings, GetModelApplicationSettings));

    c2.def("DoesModelSettingsElmExist", &IDgnSettings::DoesModelSettingsElmExist, "model"_a, DOC(Bentley, DgnPlatform, IDgnSettings, DoesModelSettingsElmExist));
    c2.def_static("GetCurrentSettings", &IDgnSettings::GetCurrentSettings, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, IDgnSettings, GetCurrentSettings));
    }