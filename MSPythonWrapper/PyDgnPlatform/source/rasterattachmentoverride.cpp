/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\rasterattachmentoverride.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/RasterAttachmentOverride.h>



static const char * __doc_Bentley_DgnPlatform_RasterOverridesCollection_Write =R"doc(Write RasterOverrides collection.

Parameter ``ref``:
    The DgnAttachment.

Returns:
    non-zero error status if the write operation failed.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterOverridesCollection_ClearAll =R"doc(Clear all RasterOverrides.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterOverridesCollection_HasOverride =R"doc(Query if RasterOverrides exists.)doc";

static const char * __doc_Bentley_DgnPlatform_RasterOverridesCollection_GetCP =R"doc(Query RasterOverrides collection for the input DgnAttachment.

Parameter ``ref``:
    The DgnAttachment.

Returns:
    a const pointer to the RasterOverrides collection or NULL if no
    overrides exist.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_RasterAttachmentOverride(py::module_& m)
    {
    //===================================================================================
    // struct RasterOverrides
    py::class_< RasterOverrides> c1(m, "RasterOverrides");

    c1.def_readwrite("ovrFlags", &RasterOverrides::m_ovrFlags);
    c1.def_readwrite("toggleValues", &RasterOverrides::m_toggleValues);

    if (true)
        {
        //===================================================================================
        // enum RasterOvrFlags
        py::enum_< RasterOverrides::RasterOvrFlags>(c1, "RasterOvrFlags", py::arithmetic())
            .value("eRASTER_OVR_Invert", RasterOverrides::RASTER_OVR_Invert)
            .value("eRASTER_OVR_Transparency", RasterOverrides::RASTER_OVR_Transparency)
            .value("eRASTER_OVR_Clip", RasterOverrides::RASTER_OVR_Clip)
            .value("eRASTER_OVR_View1", RasterOverrides::RASTER_OVR_View1)
            .value("eRASTER_OVR_View2", RasterOverrides::RASTER_OVR_View2)
            .value("eRASTER_OVR_View3", RasterOverrides::RASTER_OVR_View3)
            .value("eRASTER_OVR_View4", RasterOverrides::RASTER_OVR_View4)
            .value("eRASTER_OVR_View5", RasterOverrides::RASTER_OVR_View5)
            .value("eRASTER_OVR_View6", RasterOverrides::RASTER_OVR_View6)
            .value("eRASTER_OVR_View7", RasterOverrides::RASTER_OVR_View7)
            .value("eRASTER_OVR_View8", RasterOverrides::RASTER_OVR_View8)
            .value("eRASTER_OVR_Print", RasterOverrides::RASTER_OVR_Print)
            .value("eRASTER_OVR_BinaryPrintInvert", RasterOverrides::RASTER_OVR_BinaryPrintInvert)
            .value("eRASTER_OVR_Drape", RasterOverrides::RASTER_OVR_Drape)
            .export_values();
        }

    c1.def(py::init<>());
    c1.def("IsOverridden", &RasterOverrides::IsOverridden, "ovrFlags"_a);
    c1.def("ClearAll", &RasterOverrides::ClearAll);
    c1.def("HasOverride", &RasterOverrides::HasOverride);
    c1.def("GetValue", &RasterOverrides::GetValue, "ovrFlags"_a);
    c1.def("SetValue", &RasterOverrides::SetValue, "ovrFlags"_a, "newValue"_a);        

    //===================================================================================
    // struct RasterOverridesCollection
    py::class_< RasterOverridesCollection, DgnAttachmentAppData, std::unique_ptr<RasterOverridesCollection, py::nodelete> > c2(m, "RasterOverridesCollection");

    c2.def("GetRasterOverrides", &RasterOverridesCollection::GetRasterOverridesR, "elRef"_a, py::return_value_policy::reference_internal);

    c2.def_static("GetFrom", [] (DgnAttachmentR refAtt) //replacement method of GetCP, GetR
                  {
                  return std::unique_ptr<RasterOverridesCollection, py::nodelete>(&RasterOverridesCollection::GetR(refAtt));
                  }, "refAtt"_a);

    c2.def("HasOverride", &RasterOverridesCollection::HasOverride, DOC(Bentley, DgnPlatform, RasterOverridesCollection, HasOverride));
    c2.def("ClearAll", &RasterOverridesCollection::ClearAll, DOC(Bentley, DgnPlatform, RasterOverridesCollection, ClearAll));
    c2.def("Write", &RasterOverridesCollection::Write, "refAtt"_a, DOC(Bentley, DgnPlatform, RasterOverridesCollection, Write));
    }