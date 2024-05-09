/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\xattributechange.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/XAttributeChange.h>



static const char * __doc_Bentley_DgnPlatform_XAttributeChange_GetChangeType =R"doc(Get the type of change scheduled to the XAttribute.)doc";

static const char * __doc_Bentley_DgnPlatform_XAttributeChange_GetId =R"doc(Get the ID of the XAttribute within the element.)doc";

static const char * __doc_Bentley_DgnPlatform_XAttributeChange_GetHandlerId =R"doc(Get the ID of the XAttribute's IXAttributeHandler.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_XAttributeChange(py::module_& m)
    {
    //===================================================================================
    // struct XAttributeChange
    py::class_< XAttributeChange> c1(m, "XAttributeChange");

    if (true)
        {
        //===================================================================================
        // enum ChangeType
        py::enum_< XAttributeChange::ChangeType>(c1, "ChangeType", py::arithmetic())
            .value("eCHANGETYPE_Unknown", XAttributeChange::CHANGETYPE_Unknown)
            .value("eCHANGETYPE_Write", XAttributeChange::CHANGETYPE_Write)
            .value("eCHANGETYPE_Delete", XAttributeChange::CHANGETYPE_Delete)
            .value("eCHANGETYPE_HistoricalVersion", XAttributeChange::CHANGETYPE_HistoricalVersion)
            .value("eCHANGETYPE_HistoricalVersionDidNotExist", XAttributeChange::CHANGETYPE_HistoricalVersionDidNotExist)
            .export_values();
        }

    c1.def(py::init<>());
    c1.def_property_readonly("HandlerId", &XAttributeChange::GetHandlerId);
    c1.def("GetHandlerId", &XAttributeChange::GetHandlerId, DOC(Bentley, DgnPlatform, XAttributeChange, GetHandlerId));
    
    c1.def_property_readonly("Id", &XAttributeChange::GetId);
    c1.def("GetId", &XAttributeChange::GetId, DOC(Bentley, DgnPlatform, XAttributeChange, GetId));
    
    c1.def_property_readonly("Data", [] (XAttributeChangeCR self) { return py::bytes((const char*) self.PeekData(), self.GetSize()); });
    c1.def("GetData", [] (XAttributeChangeCR self) { return py::bytes((const char*) self.PeekData(), self.GetSize()); });
    
    c1.def_property_readonly("ChangeType", &XAttributeChange::GetChangeType);
    c1.def("GetChangeType", &XAttributeChange::GetChangeType, DOC(Bentley, DgnPlatform, XAttributeChange, GetChangeType));
    }