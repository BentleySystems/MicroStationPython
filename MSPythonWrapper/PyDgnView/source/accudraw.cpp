/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnView\source\accudraw.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnView/AccuDraw.h>
#include <DgnView/IViewManager.h>
#include <optional>



static const char * __doc_Bentley_DgnPlatform_AccuDraw_GetInstance =R"doc(Get the current AccuDraw instance.)doc";

static const char * __doc_Bentley_DgnPlatform_AccuDraw_SetContext =R"doc(Allows tools to provide hints to accudraw for setting compass
location, orientation, mode, etc.)doc";

static const char * __doc_Bentley_DgnPlatform_AccuDraw_GetRotationMode =R"doc(Current compass rotation type)doc";

static const char * __doc_Bentley_DgnPlatform_AccuDraw_GetCompassMode =R"doc(Current compass mode)doc";

static const char * __doc_Bentley_DgnPlatform_AccuDraw_GetFloatingOrigin =R"doc(Current compass floating origin setting)doc";

static const char * __doc_Bentley_DgnPlatform_AccuDraw_GetLocked =R"doc(Current compass locks bitmask)doc";

static const char * __doc_Bentley_DgnPlatform_AccuDraw_GetAngle =R"doc(Current compass polar angle)doc";

static const char * __doc_Bentley_DgnPlatform_AccuDraw_GetDistance =R"doc(Current compass polar distance)doc";

static const char * __doc_Bentley_DgnPlatform_AccuDraw_GetDelta =R"doc(Current compass xyz delta)doc";

static const char * __doc_Bentley_DgnPlatform_AccuDraw_GetOrigin =R"doc(Current compass origin)doc";

static const char * __doc_Bentley_DgnPlatform_AccuDraw_GetRotation =R"doc(Current compass orientation)doc";

static const char * __doc_Bentley_DgnPlatform_AccuDraw_GetCompassViewport =R"doc(Current compass viewport)doc";

static const char * __doc_Bentley_DgnPlatform_AccuDraw_Deactivate =R"doc(For tools that don't support AccuDraw or don't want it automatically
enabled.)doc";

static const char * __doc_Bentley_DgnPlatform_AccuDraw_Activate =R"doc(For tools to explicitly enable AccuDraw before dynamics start.)doc";

static const char * __doc_Bentley_DgnPlatform_AccuDraw_IsActive =R"doc(Compass is active/displayed.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_AccuDraw(py::module_& m)
    {
    //===================================================================================
    // enum AccuDrawFlags
    py::enum_< AccuDrawFlags>(m, "AccuDrawFlags", py::arithmetic())
        .value("eACCUDRAW_SetModePolar", ACCUDRAW_SetModePolar)
        .value("eACCUDRAW_SetModeRect", ACCUDRAW_SetModeRect)
        .value("eACCUDRAW_SetOrigin", ACCUDRAW_SetOrigin)
        .value("eACCUDRAW_FixedOrigin", ACCUDRAW_FixedOrigin)
        .value("eACCUDRAW_SetRMatrix", ACCUDRAW_SetRMatrix)
        .value("eACCUDRAW_SetXAxis", ACCUDRAW_SetXAxis)
        .value("eACCUDRAW_SetNormal", ACCUDRAW_SetNormal)
        .value("eACCUDRAW_SetDistance", ACCUDRAW_SetDistance)
        .value("eACCUDRAW_LockDistance", ACCUDRAW_LockDistance)
        .value("eACCUDRAW_Lock_X", ACCUDRAW_Lock_X)
        .value("eACCUDRAW_Lock_Y", ACCUDRAW_Lock_Y)
        .value("eACCUDRAW_Lock_Z", ACCUDRAW_Lock_Z)
        .value("eACCUDRAW_Disable", ACCUDRAW_Disable)
        .value("eACCUDRAW_Set3dMatrix", ACCUDRAW_Set3dMatrix)
        .value("eACCUDRAW_OrientDefault", ACCUDRAW_OrientDefault)
        .value("eACCUDRAW_SetFocus", ACCUDRAW_SetFocus)
        .value("eACCUDRAW_Delay", ACCUDRAW_Delay)
        .value("eACCUDRAW_OrientACS", ACCUDRAW_OrientACS)
        .value("eACCUDRAW_SetXAxis2", ACCUDRAW_SetXAxis2)
        .value("eACCUDRAW_LockAngle", ACCUDRAW_LockAngle)
        .value("eACCUDRAW_AllowStartInLocate", ACCUDRAW_AllowStartInLocate)
        .value("eACCUDRAW_AlwaysSetOrigin", ACCUDRAW_AlwaysSetOrigin)
        .value("eACCUDRAW_RedrawCompass", ACCUDRAW_RedrawCompass)
        .value("eACCUDRAW_UpdateRotation", ACCUDRAW_UpdateRotation)
        .export_values();

    //===================================================================================
    // struct AccuDraw
    py::class_< AccuDraw> c1(m, "AccuDraw");

    if (true)
        {
        //===================================================================================
        // enum CompassMode
        py::enum_<AccuDraw::CompassMode>(c1, "CompassMode", py::arithmetic())
            .value("eMODE_Polar", AccuDraw::MODE_Polar)
            .value("eMODE_Rectangular", AccuDraw::MODE_Rectangular)
            .export_values();

        //===================================================================================
        // enum RotationMode
        py::enum_<AccuDraw::RotationMode>(c1, "RotationMode", py::arithmetic())
            .value("eROTATION_Top", AccuDraw::ROTATION_Top)
            .value("eROTATION_Front", AccuDraw::ROTATION_Front)
            .value("eROTATION_Side", AccuDraw::ROTATION_Side)
            .value("eROTATION_View", AccuDraw::ROTATION_View)
            .value("eROTATION_ACS", AccuDraw::ROTATION_ACS)
            .value("eROTATION_Context", AccuDraw::ROTATION_Context)
            .value("eROTATION_Restore", AccuDraw::ROTATION_Restore)
            .export_values();

        //===================================================================================
        // enum LockedStates
        py::enum_<AccuDraw::LockedStates>(c1, "LockedStates", py::arithmetic())
            .value("eNONE_LOCKED", AccuDraw::NONE_LOCKED)
            .value("eX_BM", AccuDraw::X_BM)
            .value("eY_BM", AccuDraw::Y_BM)
            .value("eVEC_BM", AccuDraw::VEC_BM)
            .value("eDIST_BM", AccuDraw::DIST_BM)
            .value("eXY_BM", AccuDraw::XY_BM)
            .value("eANGLE_BM", AccuDraw::ANGLE_BM)
            .export_values();
        }

    c1.def("IsActive", &AccuDraw::IsActive, DOC(Bentley, DgnPlatform, AccuDraw, IsActive));
    c1.def("Activate", &AccuDraw::Activate, DOC(Bentley, DgnPlatform, AccuDraw, Activate));
    c1.def("Deactivate", &AccuDraw::Deactivate, DOC(Bentley, DgnPlatform, AccuDraw, Deactivate));
    c1.def_property_readonly("CompassViewport", &AccuDraw::GetCompassViewport);
    c1.def("GetCompassViewport", &AccuDraw::GetCompassViewport, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, AccuDraw, GetCompassViewport));
    
    c1.def_property_readonly("Rotation", [] (AccuDraw& self)
                             {
                             RotMatrix mat;
                             self.GetRotation(mat);
                             return mat;
                             });
    c1.def("GetRotation", &AccuDraw::GetRotation, "rMatrix"_a, DOC(Bentley, DgnPlatform, AccuDraw, GetRotation));

    c1.def_property_readonly("Origin", [] (AccuDraw& self)
                             {
                             DPoint3d origin;
                             self.GetOrigin(origin);
                             return origin;
                             });
    c1.def("GetOrigin", &AccuDraw::GetOrigin, "origin"_a, DOC(Bentley, DgnPlatform, AccuDraw, GetOrigin));

    c1.def_property_readonly("Delta", [] (AccuDraw& self)
                             {
                             DVec3d delta;
                             self.GetDelta(delta);
                             return delta;
                             });
    c1.def("GetDelta", &AccuDraw::GetDelta, "delta"_a, DOC(Bentley, DgnPlatform, AccuDraw, GetDelta));

    c1.def_property_readonly("Distance", &AccuDraw::GetDistance);
    c1.def("GetDistance", &AccuDraw::GetDistance, DOC(Bentley, DgnPlatform, AccuDraw, GetDistance));
    
    c1.def_property_readonly("Angle", &AccuDraw::GetAngle);
    c1.def("GetAngle", &AccuDraw::GetAngle, DOC(Bentley, DgnPlatform, AccuDraw, GetAngle));
    
    c1.def_property_readonly("Locked", &AccuDraw::GetLocked);    
    c1.def("GetLocked", &AccuDraw::GetLocked, DOC(Bentley, DgnPlatform, AccuDraw, GetLocked));    
    
    c1.def_property_readonly("FloatingOrigin", &AccuDraw::GetFloatingOrigin);
    c1.def("GetFloatingOrigin", &AccuDraw::GetFloatingOrigin, DOC(Bentley, DgnPlatform, AccuDraw, GetFloatingOrigin));
    
    c1.def_property_readonly("CompassMode", &AccuDraw::GetCompassMode);
    c1.def("GetCompassMode", &AccuDraw::GetCompassMode, DOC(Bentley, DgnPlatform, AccuDraw, GetCompassMode));
    
    c1.def_property_readonly("RotationMode", &AccuDraw::GetRotationMode);
    c1.def("GetRotationMode", &AccuDraw::GetRotationMode, DOC(Bentley, DgnPlatform, AccuDraw, GetRotationMode));

    c1.def("SetContext",
           [] (AccuDraw& self, AccuDrawFlags flags, DPoint3dCP origin, DVec3dCP orientation, DVec3dCP delta,
               boost::optional<double> distance, boost::optional<double> angle, TransformCP trans)
           {
           return self.SetContext(flags, origin, orientation, delta, distance.get_ptr(), angle.get_ptr(), trans);
           },
           "flags"_a, "origin"_a = nullptr, "orientation"_a = nullptr, "delta"_a = nullptr,
           "distance"_a = nullptr, "angle"_a = nullptr, "trans"_a = nullptr, DOC(Bentley, DgnPlatform, AccuDraw, SetContext));


    c1.def_static("GetInstance", &AccuDraw::GetInstance, py::return_value_policy::reference, DOC(Bentley, DgnPlatform, AccuDraw, GetInstance));

    }