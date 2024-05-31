/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\tagelementdata.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/TagElementData.h>



/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_TagElementData(py::module_& m)
    {
    //===================================================================================
    // struct DgnTagSetSpec
    py::class_< DgnTagSetSpec> c1(m, "DgnTagSetSpec");

    c1.def_property("TagSetName",
                    [] (DgnTagSetSpec const& self) { return self.setName; },
                    [] (DgnTagSetSpec& self, WCharCP szName) { wcsncpy(self.setName, szName, TAG_SET_NAME_MAX); });

    c1.def_property("ReportName",
                    [] (DgnTagSetSpec const& self) { return self.reportName; },
                    [] (DgnTagSetSpec& self, WCharCP szName) { wcsncpy(self.reportName, szName, TAG_SET_NAME_MAX); });

    c1.def_property("ModelRef",
                    [] (DgnTagSetSpec const& self) { return self.modelRef; },
                    [] (DgnTagSetSpec& self, DgnModelRefP modelRef) { self.modelRef = modelRef; }, py::keep_alive<1, 2>());

    c1.def_readwrite("ownerId", &DgnTagSetSpec::ownerID);

    //===================================================================================
    // struct DgnTagSpec
    py::class_< DgnTagSpec> c2(m, "DgnTagSpec");

    c2.def_property("TagSetSpec",
                    [] (DgnTagSpec const& self) { return self.set; },
                    [] (DgnTagSpec& self, DgnTagSetSpec const& newVal) { memcpy((void*) &self.set, (const void*) &newVal, sizeof(DgnTagSetSpec)); });

    c2.def_property("TagName",
                    [] (DgnTagSpec const& self) { return self.tagName; },
                    [] (DgnTagSpec& self, WCharCP szName) { wcsncpy(self.tagName, szName, TAG_SET_NAME_MAX); });
    }