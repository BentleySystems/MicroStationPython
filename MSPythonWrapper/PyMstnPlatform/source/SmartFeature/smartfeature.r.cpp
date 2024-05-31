/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\SmartFeature\smartfeature.r.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <PSolid/PSolidCoreAPI.h>
#include <Mstn/SmartFeature/SmartFeatureAPI.h>
#include <Mstn/SmartFeature/SmartFeatureBaseDefs.h>
#include <Mstn/SmartFeature/SmartFeature.r.h>

USING_NAMESPACE_SMARTFEATURE;

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_SmartFeature_r(py::module_& m)
    {
    //===================================================================================
    // struct ChamferEdgeSettings
    py::class_< ChamferEdgeSettings> c4(m, "ChamferEdgeSettings");

    c4.def(py::init<>());
    c4.def(py::init<DgnModelR>(), "dgnModel"_a);

    c4.def_readwrite("length", &ChamferEdgeSettings::m_length);
    c4.def_readwrite("distance", &ChamferEdgeSettings::m_distance);
    c4.def_readwrite("distance2", &ChamferEdgeSettings::m_distance2);
    c4.def_readwrite("angle", &ChamferEdgeSettings::m_angle);
    c4.def_readwrite("maxChamferDistance", &ChamferEdgeSettings::m_maxChamferDistance);

    c4.def_property("method",
                    [] (ChamferEdgeSettings const& self) { return self.m_method; },
                    [] (ChamferEdgeSettings& self, UInt32 mode) { self.m_method = mode; });

    c4.def_property("propogateToSmoothEdges",
                    [] (ChamferEdgeSettings const& self) { return (bool) self.m_propogateToSmoothEdges; },
                    [] (ChamferEdgeSettings& self, bool mode) { self.m_propogateToSmoothEdges = (UInt32) mode; });

    c4.def_property("reversed",
                    [] (ChamferEdgeSettings const& self) { return (bool) self.m_reversed; },
                    [] (ChamferEdgeSettings& self, bool mode) { self.m_reversed = (UInt32) mode; });


    //===================================================================================
    // struct ExtrudeSettings
    py::class_< ExtrudeSettings> c21(m, "ExtrudeSettings");

    c21.def_property("doSkew",
                     [] (ExtrudeSettings const& self) { return (bool) self.m_doSkew; },
                     [] (ExtrudeSettings& self, bool mode) { self.m_doSkew = (UInt32) mode; });

    c21.def_property("doScale",
                     [] (ExtrudeSettings const& self) { return (bool) self.m_doScale; },
                     [] (ExtrudeSettings& self, bool mode) { self.m_doScale = (UInt32) mode; });

    c21.def_property("doSpin",
                     [] (ExtrudeSettings const& self) { return (bool) self.m_doSpin; },
                     [] (ExtrudeSettings& self, bool mode) { self.m_doSpin = (UInt32) mode; });

    c21.def_property("bothWays",
                     [] (ExtrudeSettings const& self) { return (bool) self.m_bothWays; },
                     [] (ExtrudeSettings& self, bool mode) { self.m_bothWays = (UInt32) mode; });

    c21.def_property("createSheet",
                     [] (ExtrudeSettings const& self) { return (bool) self.m_createSheet; },
                     [] (ExtrudeSettings& self, bool mode) { self.m_createSheet = (UInt32) mode; });

    c21.def_property("basePresent",
                     [] (ExtrudeSettings const& self) { return (bool) self.m_basePresent; },
                     [] (ExtrudeSettings& self, bool mode) { self.m_basePresent = (UInt32) mode; });

    c21.def_property("isNormalized",
                     [] (ExtrudeSettings const& self) { return (bool) self.m_isNormalized; },
                     [] (ExtrudeSettings& self, bool mode) { self.m_isNormalized = (UInt32) mode; });

    c21.def_property("thicknessMode",
                     [] (ExtrudeSettings const& self) { return self.m_thicknessMode; },
                     [] (ExtrudeSettings& self, UInt32 mode) { self.m_thicknessMode = mode; });

    c21.def_readwrite("distance", &ExtrudeSettings::m_distance);
    c21.def_readwrite("normal", &ExtrudeSettings::m_normal);
    c21.def_readwrite("basePoint", &ExtrudeSettings::m_basePoint);
    c21.def_readwrite("xScale", &ExtrudeSettings::m_xScale);
    c21.def_readwrite("yScale", &ExtrudeSettings::m_yScale);
    c21.def_readwrite("spinAngle", &ExtrudeSettings::m_spinAngle);
    c21.def_readwrite("thickness", &ExtrudeSettings::m_thickness);

    c21.def(py::init<>());

    c21.def(py::init(
        [](DPoint3dCR hitPoint, bool createSheet, bool skewed, boost::optional<double> distance, double xScale, double yScale,
           double spinAngle, bool bothWays, UInt32 thicknessMode, double thickness, DgnButtonEventCR ev, CurveVectorCR curveVector)
        {
            return new ExtrudeSettings(hitPoint, createSheet, skewed, distance.get_ptr(), xScale, yScale,
                                       spinAngle, bothWays, thicknessMode, thickness, ev, curveVector);
        }),
        "hitPoint"_a, "createSheet"_a, "skewed"_a, "distance"_a, "xScale"_a, "yScale"_a, "spinAngle"_a, "bothWays"_a, "thicknessMode"_a, "thickness"_a, "ev"_a, "curveVector"_a);

    c21.def(py::init(
        [](DPoint3dCR hitPoint, bool createSheet, bool skewed, boost::optional<double> distance, double xScale, double yScale,
           double spinAngle, bool bothWays, UInt32 thicknessMode, double thickness, DPoint3dCP origin, ViewportP vp, CurveVectorCR curveVector)
        {
            return new ExtrudeSettings(hitPoint, createSheet, skewed, distance.get_ptr(), xScale, yScale,
                spinAngle, bothWays, thicknessMode, thickness, origin, vp, curveVector);
        }),
        "hitPoint"_a, "createSheet"_a, "skewed"_a, "distance"_a, "xScale"_a, "yScale"_a, "spinAngle"_a, "bothWays"_a, "thicknessMode"_a, "thickness"_a, "origin"_a, "vp"_a, "curveVector"_a);

    c21.def("Validate", &ExtrudeSettings::Validate);
    c21.def("SetDistance", &ExtrudeSettings::SetDistance, "distance"_a);
    c21.def("SetXScale", &ExtrudeSettings::SetXScale, "scale"_a);
    c21.def("SetYScale", &ExtrudeSettings::SetYScale, "scale"_a);
    c21.def("SetSpinAngle", &ExtrudeSettings::SetSpinAngle, "spinAngle"_a);
    c21.def("SetThickness", &ExtrudeSettings::SetThickness, "thickness"_a);

    //===================================================================================
    // struct RevolveSettings
    py::class_< RevolveSettings> c22(m, "RevolveSettings");

    c22.def_property("createSheet",
                     [] (RevolveSettings const& self) { return (bool)self.m_createSheet; },
                     [] (RevolveSettings& self, bool mode) { self.m_createSheet = (UInt32)mode; });

    c22.def_property("thicknessMode",
                     [] (RevolveSettings const& self) { return self.m_thicknessMode; },
                     [] (RevolveSettings& self, UInt32 mode) { self.m_thicknessMode = mode; });

    c22.def_property("numRules",
                     [] (RevolveSettings const& self) { return self.m_numRules; },
                     [] (RevolveSettings& self, UInt32 mode) { self.m_numRules = mode; });

    c22.def_property("numRules",
                     [] (RevolveSettings const& self) { return self.m_numRules; },
                     [] (RevolveSettings& self, UInt32 mode) { self.m_numRules = mode; });

    c22.def_readwrite("axis", &RevolveSettings::m_axis);
    c22.def_readwrite("angle", &RevolveSettings::m_angle);
    c22.def_readwrite("thickness", &RevolveSettings::m_thickness);

    c22.def(py::init<>());

    c22.def(py::init<DPoint3dCR, bool, double, int, DgnButtonEventCR, DgnButtonEventCP, CurveVectorCR, UInt32, double>(),
            "hitPoint"_a, "createSheet"_a, "angle"_a, "axisMode"_a, "ev"_a, "axisPoint"_a, "curveVector"_a, "thicknessMode"_a, "thickness"_a);

    c22.def(py::init<DPoint3dCR, bool, double, int, DPoint3dCP, DPoint3dCP, CurveVectorCR, UInt32, double, ViewportP>(),
            "hitPoint"_a, "createSheet"_a, "angle"_a, "axisMode"_a, "origin"_a, "axisPoint"_a, "curveVector"_a, "thicknessMode"_a, "thickness"_a, "vp"_a);

    c22.def("Validate", &RevolveSettings::Validate);
    c22.def("SetAngle", &RevolveSettings::SetAngle, "angle"_a);
    c22.def("SetAxis", &RevolveSettings::SetAxis, "axis"_a);
    c22.def("SetAxisOrigin", &RevolveSettings::SetAxisOrigin, "axisOrigin"_a);
    c22.def("SetAxisDirection", &RevolveSettings::SetAxisDirection, "axisDirection"_a);
    c22.def("SetThickness", &RevolveSettings::SetThickness, "thickness"_a);

    //===================================================================================
    // struct AssociativeExtractSettings
    py::class_< AssociativeExtractSettings> c23(m, "AssociativeExtractSettings");

    c23.def(py::init<>());
    c23.def(py::init<DgnModelR>(), "dgnModel"_a);

    c23.def_readwrite("type", &AssociativeExtractSettings::m_type);

    c23.def_property("moveElement",
                     [] (AssociativeExtractSettings const& self) { return (bool) self.m_moveElement; },
                     [] (AssociativeExtractSettings& self, bool mode) { self.m_moveElement = (UInt32) mode; });

    c23.def_property("keepAssociative",
                     [] (AssociativeExtractSettings const& self) { return (bool) self.m_keepAssociative; },
                     [] (AssociativeExtractSettings& self, bool mode) { self.m_keepAssociative = (UInt32) mode; });

    c23.def_property("deleteWithParent",
                     [] (AssociativeExtractSettings const& self) { return (bool) self.m_deleteWithParent; },
                     [] (AssociativeExtractSettings& self, bool mode) { self.m_deleteWithParent = (UInt32) mode; });

    c23.def_readwrite("offset", &AssociativeExtractSettings::m_offset);

    //===================================================================================
    // struct AssociativeExtractSymbologySettings
    py::class_< AssociativeExtractSymbologySettings> c24(m, "AssociativeExtractSymbologySettings");

    c24.def(py::init<>());
    c24.def(py::init<DgnModelR>(), "dgnModel"_a);

    c24.def_property("colorOverride",
                     [] (AssociativeExtractSymbologySettings const& self) { return (bool) self.m_colorOverride; },
                     [] (AssociativeExtractSymbologySettings& self, bool mode) { self.m_colorOverride = (UInt32) mode; });

    c24.def_property("weightOverride",
                     [] (AssociativeExtractSymbologySettings const& self) { return (bool) self.m_weightOverride; },
                     [] (AssociativeExtractSymbologySettings& self, bool mode) { self.m_weightOverride = (UInt32) mode; });

    c24.def_property("styleOverride",
                     [] (AssociativeExtractSymbologySettings const& self) { return (bool) self.m_styleOverride; },
                     [] (AssociativeExtractSymbologySettings& self, bool mode) { self.m_styleOverride = (UInt32) mode; });

    c24.def_property("levelOverride",
                     [] (AssociativeExtractSymbologySettings const& self) { return (bool) self.m_levelOverride; },
                     [] (AssociativeExtractSymbologySettings& self, bool mode) { self.m_levelOverride = (UInt32) mode; });

    c24.def_property("classOverride",
                     [] (AssociativeExtractSymbologySettings const& self) { return (bool) self.m_classOverride; },
                     [] (AssociativeExtractSymbologySettings& self, bool mode) { self.m_classOverride = (UInt32) mode; });

    c24.def_property("elementclass",
                     [] (AssociativeExtractSymbologySettings const& self) { return (bool) self.m_elementclass; },
                     [] (AssociativeExtractSymbologySettings& self, bool mode) { self.m_elementclass = (UInt32) mode; });

    c24.def_readwrite("color", &AssociativeExtractSymbologySettings::m_color);
    c24.def_readwrite("weight", &AssociativeExtractSymbologySettings::m_weight);
    c24.def_readwrite("style", &AssociativeExtractSymbologySettings::m_style);
    c24.def_readwrite("level", &AssociativeExtractSymbologySettings::m_level);

    //===================================================================================
    // struct ExtrudeAlongProfileSetting
    py::class_< ExtrudeAlongProfileSetting> c25(m, "ExtrudeAlongProfileSetting");

    c25.def(py::init<>());
    c25.def(py::init<DgnModelR>(), "dgnModel"_a);

    c24.def_property("circularProfile",
                     [] (ExtrudeAlongProfileSetting const& self) { return (bool) self.m_circularProfile; },
                     [] (ExtrudeAlongProfileSetting& self, bool mode) { self.m_circularProfile = (UInt32) mode; });

    c24.def_property("doInsideDiameter",
                     [] (ExtrudeAlongProfileSetting const& self) { return (bool) self.m_doInsideDiameter; },
                     [] (ExtrudeAlongProfileSetting& self, bool mode) { self.m_doInsideDiameter = (UInt32) mode; });

    c24.def_property("doOutsideDiameter",
                     [] (ExtrudeAlongProfileSetting const& self) { return (bool) self.m_doOutsideDiameter; },
                     [] (ExtrudeAlongProfileSetting& self, bool mode) { self.m_doOutsideDiameter = (UInt32) mode; });

    c24.def_property("doEditmode",
                     [] (ExtrudeAlongProfileSetting const& self) { return (bool) self.m_doEditmode; },
                     [] (ExtrudeAlongProfileSetting& self, bool mode) { self.m_doEditmode = (UInt32) mode; });    
    }