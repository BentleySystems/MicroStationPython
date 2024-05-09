/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\iviewoutput.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/IViewOutput.h>



static const char * __doc_Bentley_DgnPlatform_IViewOutput_CheckNeedsHeal =R"doc(Check if output is currently in need of healing and optionally return
the dirty rectangle.)doc";

static const char * __doc_Bentley_DgnPlatform_IViewOutput_EnableZWriting =R"doc(Call to set immediate mode z-buffer writes to full or partial range.
If full range is disabled, z's will be written near the back of the
frustum. @note Write Z off is only supported for display of transient
geometry.)doc";

static const char * __doc_Bentley_DgnPlatform_IViewOutput_EnableZTesting =R"doc(Call to enable/disable z-buffer comparisons in immediate mode. The
values written to the z-buffer depend on the states of test Z and
write Z as follows. If write Z on, test Z on - full z-buffer range is
enabled and written. If write Z on, test Z off - z values written near
the front of frustum. If write Z off - z values written near the back
of frustum.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_IViewOutput(py::module_& m)
    {
    //===================================================================================
    // struct CameraParams
    py::class_< CameraParams> c1(m, "CameraParams");

    c1.def_readwrite("position", &CameraParams::position);
    c1.def_readwrite("focalLength", &CameraParams::focalLength);
    c1.def_readwrite("limit", &CameraParams::limit);

    //===================================================================================
    // enum class DgnDrawBuffer
    py::enum_< DgnDrawBuffer>(m, "DgnDrawBuffer")
        .value("eNone", DgnDrawBuffer::None)
        .value("eScreen", DgnDrawBuffer::Screen)
        .value("eDynamic", DgnDrawBuffer::Dynamic)
        .value("eBackingStore", DgnDrawBuffer::BackingStore)
        .value("eDrawing", DgnDrawBuffer::Drawing)
        .export_values();

    //===================================================================================
    // enum NpcCorners
    py::enum_< NpcCorners>(m, "NpcCorners", py::arithmetic())
        .value("eNPC_000", NPC_000)
        .value("eNPC_100", NPC_100)
        .value("eNPC_010", NPC_010)
        .value("eNPC_110", NPC_110)
        .value("eNPC_001", NPC_001)
        .value("eNPC_101", NPC_101)
        .value("eNPC_011", NPC_011)
        .value("eNPC_111", NPC_111)
        .export_values();

    //===================================================================================
    // enum class ViewportStatus
    py::enum_< ViewportStatus>(m, "ViewportStatus")
        .value("eSuccess", ViewportStatus::Success)
        .value("eViewNotInitialized", ViewportStatus::ViewNotInitialized)
        .value("eAlreadyAttached", ViewportStatus::AlreadyAttached)
        .value("eNotAttached", ViewportStatus::NotAttached)
        .value("eDrawFailure", ViewportStatus::DrawFailure)
        .value("eNotResized", ViewportStatus::NotResized)
        .value("eModelNotFound", ViewportStatus::ModelNotFound)
        .value("eViewInfoNotOpen", ViewportStatus::ViewInfoNotOpen)
        .export_values();

    //===================================================================================
    // enum class AntiAliasPref
    py::enum_< AntiAliasPref>(m, "AntiAliasPref")
        .value("eDetect", AntiAliasPref::Detect)
        .value("eOn", AntiAliasPref::On)
        .value("eOff", AntiAliasPref::Off)
        .export_values();

    //===================================================================================
    // enum class DrawExportFlags
    py::enum_< DrawExportFlags>(m, "DrawExportFlags")
        .value("eUseDefault", DrawExportFlags::UseDefault)
        .value("eClipToFrustum", DrawExportFlags::ClipToFrustum)
        .value("eLinesAsPolys", DrawExportFlags::LinesAsPolys)
        .value("eDeferTransparent", DrawExportFlags::DeferTransparent)
        .export_values();

    //===================================================================================
    // struct IViewOutput
    py::class_ < IViewOutput, std::unique_ptr < IViewOutput, py::nodelete > , IViewDraw > c4(m, "IViewOutput");

    c4.def("PushTransClip", &IViewOutput::PushTransClip, "transform"_a, "clipPlaneSet"_a = nullptr);
    c4.def("PopTransClip", &IViewOutput::PopTransClip);
    c4.def("EnableZTesting", &IViewOutput::EnableZTesting, "yesNo"_a, DOC(Bentley, DgnPlatform, IViewOutput, EnableZTesting));
    c4.def("EnableZWriting", &IViewOutput::EnableZWriting, "yesNo"_a, DOC(Bentley, DgnPlatform, IViewOutput, EnableZWriting));
    c4.def("CheckNeedsHeal", &IViewOutput::CheckNeedsHeal, "rect"_a, DOC(Bentley, DgnPlatform, IViewOutput, CheckNeedsHeal));
    }