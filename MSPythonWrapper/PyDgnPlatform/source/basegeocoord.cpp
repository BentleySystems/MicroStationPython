/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\basegeocoord.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnGeoCoord/DgnGeoCoord.h>

using namespace GeoCoordinates;

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       9/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_BaseGCS(py::module_& m)
    {
    //===================================================================================
    // Enum GeoCoordParseStatus
    py::enum_<GeoCoordParseStatus>(m, "GeoCoordParseStatus")
        .value("eGeoCoordParse_GeoCoordNotInitialized", GeoCoordParseStatus::GeoCoordParse_GeoCoordNotInitialized)
        .value("eGeoCoordParse_Success", GeoCoordParseStatus::GeoCoordParse_Success)
        .value("eGeoCoordParse_Error", GeoCoordParseStatus::GeoCoordParse_Error)
        .value("eGeoCoordParse_ParseError", GeoCoordParseStatus::GeoCoordParse_ParseError)
        .value("eGeoCoordParse_NoGCS", GeoCoordParseStatus::GeoCoordParse_NoGCS)
        .value("eGeoCoordParse_NoDatum", GeoCoordParseStatus::GeoCoordParse_NoDatum)
        .value("eGeoCoordParse_NoEllipsoid", GeoCoordParseStatus::GeoCoordParse_NoEllipsoid)
        .value("eGeoCoordParse_NoTransform", GeoCoordParseStatus::GeoCoordParse_NoTransform)
        .value("eGeoCoordParse_NoRoot", GeoCoordParseStatus::GeoCoordParse_NoRoot)
        .value("eGeoCoordParse_BadAlias", GeoCoordParseStatus::GeoCoordParse_BadAlias)
        .value("eGeoCoordParse_NodeNotFound", GeoCoordParseStatus::GeoCoordParse_NodeNotFound)
        .value("eGeoCoordParse_NoContent", GeoCoordParseStatus::GeoCoordParse_NoContent)
        .value("eGeoCoordParse_BadProjectionMethod", GeoCoordParseStatus::GeoCoordParse_BadProjectionMethod)
        .value("eGeoCoordParse_UnknownProjectionMethod", GeoCoordParseStatus::GeoCoordParse_UnknownProjectionMethod)
        .value("eGeoCoordParse_BadProjectionParamsSection", GeoCoordParseStatus::GeoCoordParse_BadProjectionParamsSection)
        .value("eGeoCoordParse_BadProjectionParam", GeoCoordParseStatus::GeoCoordParse_BadProjectionParam)
        .value("eGeoCoordParse_BadProjection", GeoCoordParseStatus::GeoCoordParse_BadProjection)
        .value("eGeoCoordParse_UnknownProjectionParam", GeoCoordParseStatus::GeoCoordParse_UnknownProjectionParam)
        .value("eGeoCoordParse_InvalidParamForMethod", GeoCoordParseStatus::GeoCoordParse_InvalidParamForMethod)
        .value("eGeoCoordParse_BadQuadrant", GeoCoordParseStatus::GeoCoordParse_BadQuadrant)
        .value("eGeoCoordParse_BadDomain", GeoCoordParseStatus::GeoCoordParse_BadDomain)
        .value("eGeoCoordParse_BadEllipsoid", GeoCoordParseStatus::GeoCoordParse_BadEllipsoid)
        .value("eGeoCoordParse_BadEllipsoidRadius", GeoCoordParseStatus::GeoCoordParse_BadEllipsoidRadius)
        .value("eGeoCoordParse_BadTransformParam", GeoCoordParseStatus::GeoCoordParse_BadTransformParam)
        .value("eGeoCoordParse_BadTransform", GeoCoordParseStatus::GeoCoordParse_BadTransform)
        .value("eGeoCoordParse_BadTransformPath", GeoCoordParseStatus::GeoCoordParse_BadTransformPath)
        .value("eGeoCoordParse_BadTransformParamSection", GeoCoordParseStatus::GeoCoordParse_BadTransformParamSection)
        .value("eGeoCoordParse_BadGridFileDef", GeoCoordParseStatus::GeoCoordParse_BadGridFileDef)
        .value("eGeoCoordParse_UnknownGridFileFormat", GeoCoordParseStatus::GeoCoordParse_UnknownGridFileFormat)
        .value("eGeoCoordParse_MREGNotSupported", GeoCoordParseStatus::GeoCoordParse_MREGNotSupported)
        .value("eGeoCoordParse_MissingPropertyOrParameter", GeoCoordParseStatus::GeoCoordParse_MissingPropertyOrParameter)
        .value("eGeoCoordParse_BadDatum", GeoCoordParseStatus::GeoCoordParse_BadDatum)
        .value("eGeoCoordParse_BadGCS", GeoCoordParseStatus::GeoCoordParse_BadGCS)
        .value("eGeoCoordParse_UnknownEllipsoid", GeoCoordParseStatus::GeoCoordParse_UnknownEllipsoid)
        .value("eGeoCoordParse_UnknownDatum", GeoCoordParseStatus::GeoCoordParse_UnknownDatum)
        .value("eGeoCoordParse_InvalidDefinition", GeoCoordParseStatus::GeoCoordParse_InvalidDefinition)
        .value("eGeoCoordParse_UnknownTransformMethod", GeoCoordParseStatus::GeoCoordParse_UnknownTransformMethod)
        .value("eGeoCoordParse_BadExtension", GeoCoordParseStatus::GeoCoordParse_BadExtension)
        .value("eGeoCoordParse_BadPrimeMeridian", GeoCoordParseStatus::GeoCoordParse_BadPrimeMeridian)
        .value("eGeoCoordParse_BadAxis", GeoCoordParseStatus::GeoCoordParse_BadAxis)
        .value("eGeoCoordParse_BadVertical", GeoCoordParseStatus::GeoCoordParse_BadVertical)
        .value("eGeoCoordParse_UnsupportedProjectionParam", GeoCoordParseStatus::GeoCoordParse_UnsupportedProjectionParam)
        .value("eGeoCoordParse_UnknownUnit", GeoCoordParseStatus::GeoCoordParse_UnknownUnit)
        .value("eGeoCoordParse_UnsupportedMeridian", GeoCoordParseStatus::GeoCoordParse_UnsupportedMeridian)
        .value("eGeoCoordParse_BadUnit", GeoCoordParseStatus::GeoCoordParse_BadUnit)
        .export_values();

    //===================================================================================
    // Enum VertDatumCode
    py::enum_<VertDatumCode>(m, "VertDatumCode")
        .value("evdcFromDatum", VertDatumCode::vdcFromDatum)
        .value("evdcNGVD29", VertDatumCode::vdcNGVD29)
        .value("evdcNAVD88", VertDatumCode::vdcNAVD88)
        .value("evdcGeoid", VertDatumCode::vdcGeoid)
        .value("evdcEllipsoid", VertDatumCode::vdcEllipsoid)
        .value("evdcLocalEllipsoid", VertDatumCode::vdcLocalEllipsoid)
        .export_values();

    //===================================================================================
    // Enum WGS84ConvertCode
    py::enum_<WGS84ConvertCode>(m, "WGS84ConvertCode")
    .value("eConvertType_NONE",WGS84ConvertCode::ConvertType_NONE)
    .value("eConvertType_MOLO",WGS84ConvertCode::ConvertType_MOLO)
    .value("eConvertType_MREG",WGS84ConvertCode::ConvertType_MREG)
    .value("eConvertType_BURS",WGS84ConvertCode::ConvertType_BURS)
    .value("eConvertType_NAD27",WGS84ConvertCode::ConvertType_NAD27)
    .value("eConvertType_NAD83",WGS84ConvertCode::ConvertType_NAD83)
    .value("eConvertType_WGS84",WGS84ConvertCode::ConvertType_WGS84)
    .value("eConvertType_WGS72",WGS84ConvertCode::ConvertType_WGS72)
    .value("eConvertType_HPGN",WGS84ConvertCode::ConvertType_HPGN)
    .value("eConvertType_7PARM",WGS84ConvertCode::ConvertType_7PARM)
    .value("eConvertType_AGD66",WGS84ConvertCode::ConvertType_AGD66)
    .value("eConvertType_3PARM",WGS84ConvertCode::ConvertType_3PARM)
    .value("eConvertType_6PARM",WGS84ConvertCode::ConvertType_6PARM)
    .value("eConvertType_4PARM",WGS84ConvertCode::ConvertType_4PARM)
    .value("eConvertType_AGD84",WGS84ConvertCode::ConvertType_AGD84)
    .value("eConvertType_NZGD4",WGS84ConvertCode::ConvertType_NZGD4)
    .value("eConvertType_ATS77",WGS84ConvertCode::ConvertType_ATS77)
    .value("eConvertType_GDA94",WGS84ConvertCode::ConvertType_GDA94)
    .value("eConvertType_NZGD2K",WGS84ConvertCode::ConvertType_NZGD2K)
    .value("eConvertType_CSRS",WGS84ConvertCode::ConvertType_CSRS)
    .value("eConvertType_TOKYO",WGS84ConvertCode::ConvertType_TOKYO)
    .value("eConvertType_RGF93",WGS84ConvertCode::ConvertType_RGF93)
    .value("eConvertType_ED50",WGS84ConvertCode::ConvertType_ED50)
    .value("eConvertType_DHDN",WGS84ConvertCode::ConvertType_DHDN)
    .value("eConvertType_ETRF89",WGS84ConvertCode::ConvertType_ETRF89)
    .value("eConvertType_GEOCTR",WGS84ConvertCode::ConvertType_GEOCTR)
    .value("eConvertType_CHENYX",WGS84ConvertCode::ConvertType_CHENYX)
    .value("eConvertType_GENGRID",WGS84ConvertCode::ConvertType_GENGRID)
    .value("eConvertType_MAXVALUE",WGS84ConvertCode::ConvertType_MAXVALUE)
    .export_values();

    //===================================================================================
    //Struct GenConvertCode
    py::enum_<GenConvertCode>(m, "GenConvertCode")
        .value("eGenConvertType_NONE", GenConvertCode::GenConvertType_NONE)
        .value("eGenConvertType_WGS72", GenConvertCode::GenConvertType_WGS72)
        .value("eGenConvertType_3PARM", GenConvertCode::GenConvertType_3PARM)
        .value("eGenConvertType_MOLO", GenConvertCode::GenConvertType_MOLO)
        .value("eGenConvertType_GEOCTR", GenConvertCode::GenConvertType_GEOCTR)
        .value("eGenConvertType_4PARM", GenConvertCode::GenConvertType_4PARM)
        .value("eGenConvertType_6PARM", GenConvertCode::GenConvertType_6PARM)
        .value("eGenConvertType_BURS", GenConvertCode::GenConvertType_BURS)
        .value("eGenConvertType_7PARM", GenConvertCode::GenConvertType_7PARM)
        .value("eGenConvertType_BDKAS", GenConvertCode::GenConvertType_BDKAS)
        .value("eGenConvertType_GFILE", GenConvertCode::GenConvertType_GFILE)
        .value("eGenConvertType_MREG", GenConvertCode::GenConvertType_MREG)
        .export_values();

    //===================================================================================
    //Struct BaseGCS
    py::class_< BaseGCS, RefCountedPtr<BaseGCS>> c0(m, "BaseGCS");
    py::bind_vector< bvector<GeoPoint> >(m, "GeoPointVector", py::module_local(false));
    py::bind_vector< bvector<GeoPoint2d> >(m, "GeoPoint2dVector", py::module_local(false));

    c0.def(py::init(py::overload_cast<>(&BaseGCS::CreateGCS)));
    c0.def(py::init(py::overload_cast<WCharCP>(&BaseGCS::CreateGCS)), "coordinateSystemKeyName"_a);
    c0.def(py::init(py::overload_cast<BaseGCSCR>(&BaseGCS::CreateGCS)), "baseGcs"_a);

    c0.def_static("CreateGCS", py::overload_cast<>(&BaseGCS::CreateGCS));
    c0.def_static("CreateGCS", py::overload_cast<WCharCP>(&BaseGCS::CreateGCS), "coordinateSystemKeyName"_a);
    c0.def_static("CreateGCS", py::overload_cast<BaseGCSCR>(&BaseGCS::CreateGCS), "baseGcs"_a);

    c0.def("AllocateClean", &BaseGCS::AllocateClean);
    c0.def("ClearConverterCache", &BaseGCS::ClearConverterCache);

    c0.def("InitAzimuthalEqualArea", [](BaseGCS& self, WCharCP datumName, WCharCP unitName, double originLongitude, double originLatitude, double azimuthAngle, double scale, double falseEasting, double falseNorthing, int quadrant)
        {
        WString errorMsg;
        StatusInt status = self.InitAzimuthalEqualArea (&errorMsg, datumName, unitName, originLongitude, originLatitude, azimuthAngle, scale, falseEasting, falseNorthing, quadrant);
        return py::make_tuple (errorMsg, status);
        }, "datumName"_a, "unitName"_a, "originLongitude"_a, "originLatitude"_a, "azimuthAngle"_a, "scale"_a, "falseEasting"_a, "falseNorthing"_a, "quadrant"_a);

    c0.def("InitTransverseMercator", [](BaseGCS& self, WCharCP datumName, WCharCP unitName, double originLongitude, double originLatitude, double scale, double falseEasting, double falseNorthing, int quadrant)
        {
        WString errorMsg;
        StatusInt status = self.InitTransverseMercator(&errorMsg, datumName, unitName, originLongitude, originLatitude, scale, falseEasting, falseNorthing, quadrant);
        return py::make_tuple(status, errorMsg);
        }, "datumName"_a, "unitName"_a, "originLongitude"_a, "originLatitude"_a, "scale"_a, "falseEasting"_a, "falseNorthing"_a, "quadrant"_a);

    c0.def("InitLatLong", &BaseGCS::InitLatLong, "errorMsg"_a, "datumName"_a, "ellipsoidName"_a, "unitName"_a, "originLongitude"_a, "originLatitude"_a);

    c0.def("InitLatLong", [](BaseGCS& self, WCharCP datumName, WCharCP ellipsoidName, WCharCP unitName, double  originLongitude, double  originLatitude)
        {
        WString errorMsg;
        StatusInt status = self.InitLatLong (&errorMsg, datumName, ellipsoidName, unitName, originLongitude, originLatitude);
        return py::make_tuple(status, errorMsg);
        }, "datumName"_a, "ellipsoidName"_a, "unitName"_a, "originLongitude"_a, "originLatitude"_a);

    //===================================================================================
    // Enum WktFlavor
    py::enum_<BaseGCS::WktFlavor>(c0, "WktFlavor")
        .value("ewktFlavorOGC", BaseGCS::wktFlavorOGC)
        .value("ewktFlavorGeoTiff", BaseGCS::wktFlavorGeoTiff)
        .value("ewktFlavorESRI", BaseGCS::wktFlavorESRI)
        .value("ewktFlavorOracle", BaseGCS::wktFlavorOracle)
        .value("ewktFlavorGeoTools", BaseGCS::wktFlavorGeoTools)
        .value("ewktFlavorEPSG", BaseGCS::wktFlavorEPSG)
        .value("ewktFlavorOracle9", BaseGCS::wktFlavorOracle9)
        .value("ewktFlavorAutodesk", BaseGCS::wktFlavorAutodesk)
        .value("ewktFlavorUnknown", BaseGCS::wktFlavorUnknown)
        .value("ewktFlavorAppAlt", BaseGCS::wktFlavorAppAlt)
        .value("ewktFlavorLclAlt", BaseGCS::wktFlavorLclAlt)
        .export_values();

    //===================================================================================
    // Enum RangeTestResult
    py::enum_<BaseGCS::RangeTestResult>(c0, "RangeTestResult")
        .value("eRangeTestOk", BaseGCS::RangeTestOk)
        .value("eRangeTestOutsideRange", BaseGCS::RangeTestOutsideRange)
        .value("eRangeTestOutsideMathDomain", BaseGCS::RangeTestOutsideMathDomain)
        .export_values();

    c0.def("InitFromWellKnownText", [](BaseGCS& self, BaseGCS::WktFlavor wktFlavor, WCharCP wellKnownText)
        {
        StatusInt warning;
        WString   warningErrorMsg;
        StatusInt status = self.InitFromWellKnownText (&warning, &warningErrorMsg, wktFlavor, wellKnownText);
        return py::make_tuple(warning, warningErrorMsg, status);
        }, "wktFlavor"_a, "wellKnownText"_a);

   c0.def("InitFromOSGEOXML", &BaseGCS::InitFromOSGEOXML, "osgeoXML"_a);

   c0.def("InitFromWellKnownText", [](BaseGCS& self, WCharCP wellKnownText)
        {
        StatusInt warning;
        WString   warningErrorMsg;
        StatusInt status = self.InitFromWellKnownText (&warning, &warningErrorMsg, wellKnownText);
        return py::make_tuple(warning, warningErrorMsg, status);
        }, "wellKnownText"_a);

    c0.def("InitFromEPSGCode", [](BaseGCS& self, int epsgCode)
        {
        StatusInt warning;
        WString   warningErrorMsg;
        StatusInt status = self.InitFromEPSGCode(&warning, &warningErrorMsg, epsgCode);
        return py::make_tuple(warning, warningErrorMsg, status);
        }, "epsgCode"_a);

    c0.def("GetWellKnownText", [](BaseGCSCR self, BaseGCS::WktFlavor wktFlavor, bool originalIfPresent, bool doNotInsertTOWGS84, bool posVectorRotationSignConvention)
        {
        WString   wellKnownText;
        StatusInt status = self.GetWellKnownText(wellKnownText, wktFlavor, originalIfPresent, doNotInsertTOWGS84, posVectorRotationSignConvention);
        return py::make_tuple(wellKnownText, status);
        }, "wktFlavor"_a, "originalIfPresent"_a = false, "doNotInsertTOWGS84"_a = false, "posVectorRotationSignConvention"_a = false);

    c0.def("GetCompoundCSWellKnownText", [](BaseGCSCR self, BaseGCS::WktFlavor wktFlavor, bool originalIfPresent, bool doNotInsertTOWGS84, bool posVectorRotationSignConvention)
        {
        WString   wellKnownText;
        StatusInt status = self.GetCompoundCSWellKnownText(wellKnownText, wktFlavor, originalIfPresent, doNotInsertTOWGS84, posVectorRotationSignConvention);
        return py::make_tuple(wellKnownText, status);
        }, "wktFlavor"_a, "originalIfPresent"_a = false, "doNotInsertTOWGS84"_a = false, "posVectorRotationSignConvention"_a = false);

    //Note : geoTiffKeys is __BENTLEY_INTERNAL_ONLY__, this method is not possible to be called successfully in python before IGeoTiffKeysList published.
    //c0.def("InitFromGeoTiffKeys", [](BaseGCS& self, ::IGeoTiffKeysList* geoTiffKeys, bool allowUnitsOverride)
    //    {
    //    StatusInt warning;
    //    WString   warningErrorMsg;
    //    StatusInt status = self.InitFromGeoTiffKeys(&warning, &warningErrorMsg, geoTiffKeys, allowUnitsOverride);
    //    return py::make_tuple(warning, warningErrorMsg, status);
    //    }, "geoTiffKeys"_a, "allowUnitsOverride"_a = false);

    c0.def("GetLinearTransform", [](BaseGCSCR self, DRange3dCR extent, BaseGCSCR targetGCS)
        {
        Transform outTransform;
        double maxError, meanError;
        WString   wellKnownText;
        StatusInt status = self.GetLinearTransform(&outTransform, extent, targetGCS, &maxError, &meanError);
        return py::make_tuple(outTransform, maxError, meanError, status);
        }, "extent"_a, "targetGCS"_a);

    c0.def("GetLinearTransformECEF", [](BaseGCSCR self, DRange3dCR extentECEF, BaseGCSCR targetGCS)
        {
        Transform outTransform;
        double maxError, meanError;
        WString   wellKnownText;
        StatusInt status = self.GetLinearTransformECEF(&outTransform, extentECEF, targetGCS, &maxError, &meanError);
        return py::make_tuple(outTransform, maxError, meanError, status);
        }, "extentECEF"_a, "targetGCS"_a);

    c0.def("GetLinearTransformToECEF", [](BaseGCSCR self, DRange3dCR extent)
        {
        Transform outTransform;
        double maxError, meanError;
        WString   wellKnownText;
        StatusInt status = self.GetLinearTransformToECEF (&outTransform, extent, &maxError, &meanError);
        return py::make_tuple(outTransform, maxError, meanError, status);
        }, "extent"_a);

    c0.def("CartesianFromCartesian", [](BaseGCSCR self, DPoint3dCR inCartesian, BaseGCSCR targetGCS)
        {
        DPoint3d outCartesian;
        ReprojectStatus status = self.CartesianFromCartesian(outCartesian, inCartesian, targetGCS);
        return py::make_tuple(outCartesian, status);
        }, "inCartesian"_a, "targetGCS"_a);

    c0.def("CartesianFromCartesian2D", [](BaseGCSCR self, DPoint2dCR inCartesian, BaseGCSCR targetGCS)
        {
        DPoint2d outCartesian;
        ReprojectStatus status = self.CartesianFromCartesian2D(outCartesian, inCartesian, targetGCS);
        return py::make_tuple(outCartesian, status);
        }, "inCartesian"_a, "targetGCS"_a);

    c0.def("CartesianFromECEF", [](BaseGCSCR self, DPoint3dCR inECEF, BaseGCSCR targetGCS)
        {
        DPoint3d outCartesian;
        ReprojectStatus status = self.CartesianFromECEF(outCartesian, inECEF, targetGCS);
        return py::make_tuple(outCartesian, status);
        }, "inECEF"_a, "targetGCS"_a);

    c0.def("ECEFFromCartesian", [](BaseGCSCR self, DPoint3dCR inCartesian)
        {
        DPoint3d outECEF;
        ReprojectStatus status = self.ECEFFromCartesian(outECEF, inCartesian);
        return py::make_tuple(outECEF, status);
        }, "inCartesian"_a);

    //Note : geoTiffKeys is __BENTLEY_INTERNAL_ONLY__, Below methods are not possible to be called successfully in python before IGeoTiffKeysList published.
    //c0.def ("SetGeoTiffKeys", &BaseGCS::SetGeoTiffKeys, "geoTiffKeys"_a);
    //c0.def ("GetGeoTiffKeys", &BaseGCS::GetGeoTiffKeys, "geoTiffKeys"_a, "originalsIfPresent"_a);

    c0.def("CanSaveToGeoTiffKeys", &BaseGCS::CanSaveToGeoTiffKeys);
    c0.def("IsValid", &BaseGCS::IsValid);
    c0.def("GetError", &BaseGCS::GetError);

    c0.def("GetErrorMessage", [](BaseGCSCR self, WStringR errorMsg) {return self.GetErrorMessage(errorMsg);}, "errorMsg"_a);
    c0.def_static("GetErrorMessageS", py::overload_cast<WStringR, StatusInt>(&BaseGCS::GetErrorMessage), "errorMsg"_a, "errorCode"_a);

    c0.def("Validate", &BaseGCS::Validate, "errorList"_a);
    c0.def("IsStandard", &BaseGCS::IsStandard);

    c0.def_property("Name", &BaseGCS::GetName, &BaseGCS::SetName);
    c0.def("GetName", &BaseGCS::GetName);
    c0.def("SetName", &BaseGCS::SetName, "name"_a);

    c0.def_property("Description", &BaseGCS::GetDescription, &BaseGCS::SetDescription);
    c0.def("GetDescription", &BaseGCS::GetDescription);
    c0.def("SetDescription", &BaseGCS::SetDescription, "description"_a);

    c0.def_property_readonly("Projection", &BaseGCS::GetProjection);
    c0.def("GetProjection", &BaseGCS::GetProjection);

    //===================================================================================
    // Enum ProjectionCodeValue
    py::enum_<BaseGCS::ProjectionCodeValue>(c0, "ProjectionCodeValue")
        .value("epcvInvalid", BaseGCS::pcvInvalid)
        .value("epcvUnity", BaseGCS::pcvUnity)
        .value("epcvTransverseMercator", BaseGCS::pcvTransverseMercator)
        .value("epcvAlbersEqualArea", BaseGCS::pcvAlbersEqualArea)
        .value("epcvHotineObliqueMercator", BaseGCS::pcvHotineObliqueMercator)
        .value("epcvMercator", BaseGCS::pcvMercator)
        .value("epcvLambertEquidistantAzimuthal", BaseGCS::pcvLambertEquidistantAzimuthal)
        .value("epcvLambertTangential", BaseGCS::pcvLambertTangential)
        .value("epcvAmericanPolyconic", BaseGCS::pcvAmericanPolyconic)
        .value("epcvModifiedPolyconic", BaseGCS::pcvModifiedPolyconic)
        .value("epcvLambertEqualAreaAzimuthal", BaseGCS::pcvLambertEqualAreaAzimuthal)
        .value("epcvEquidistantConic", BaseGCS::pcvEquidistantConic)
        .value("epcvMillerCylindrical", BaseGCS::pcvMillerCylindrical)
        .value("epcvModifiedStereographic", BaseGCS::pcvModifiedStereographic)
        .value("epcvNewZealandNationalGrid", BaseGCS::pcvNewZealandNationalGrid)
        .value("epcvSinusoidal", BaseGCS::pcvSinusoidal)
        .value("epcvOrthographic", BaseGCS::pcvOrthographic)
        .value("epcvGnomonic", BaseGCS::pcvGnomonic)
        .value("epcvEquidistantCylindrical", BaseGCS::pcvEquidistantCylindrical)
        .value("epcvVanderGrinten", BaseGCS::pcvVanderGrinten)
        .value("epcvCassini", BaseGCS::pcvCassini)
        .value("epcvRobinsonCylindrical", BaseGCS::pcvRobinsonCylindrical)
        .value("epcvBonne", BaseGCS::pcvBonne)
        .value("epcvEckertIV", BaseGCS::pcvEckertIV)
        .value("epcvEckertVI", BaseGCS::pcvEckertVI)
        .value("epcvMollweide", BaseGCS::pcvMollweide)
        .value("epcvGoodeHomolosine", BaseGCS::pcvGoodeHomolosine)
        .value("epcvEqualAreaAuthalicNormal", BaseGCS::pcvEqualAreaAuthalicNormal)
        .value("epcvEqualAreaAuthalicTransverse", BaseGCS::pcvEqualAreaAuthalicTransverse)
        .value("epcvBipolarObliqueConformalConic", BaseGCS::pcvBipolarObliqueConformalConic)
        .value("epcvObliqueCylindricalSwiss", BaseGCS::pcvObliqueCylindricalSwiss)
        .value("epcvPolarStereographic", BaseGCS::pcvPolarStereographic)
        .value("epcvObliqueStereographic", BaseGCS::pcvObliqueStereographic)
        .value("epcvSnyderObliqueStereographic", BaseGCS::pcvSnyderObliqueStereographic)
        .value("epcvLambertConformalConicOneParallel", BaseGCS::pcvLambertConformalConicOneParallel)
        .value("epcvLambertConformalConicTwoParallel", BaseGCS::pcvLambertConformalConicTwoParallel)
        .value("epcvLambertConformalConicBelgian", BaseGCS::pcvLambertConformalConicBelgian)
        .value("epcvLambertConformalConicWisconsin", BaseGCS::pcvLambertConformalConicWisconsin)
        .value("epcvTransverseMercatorWisconsin", BaseGCS::pcvTransverseMercatorWisconsin)
        .value("epcvLambertConformalConicMinnesota", BaseGCS::pcvLambertConformalConicMinnesota)
        .value("epcvTransverseMercatorMinnesota", BaseGCS::pcvTransverseMercatorMinnesota)
        .value("epcvSouthOrientedTransverseMercator", BaseGCS::pcvSouthOrientedTransverseMercator)
        .value("epcvUniversalTransverseMercator", BaseGCS::pcvUniversalTransverseMercator)
        .value("epcvSnyderTransverseMercator", BaseGCS::pcvSnyderTransverseMercator)
        .value("epcvGaussKrugerTranverseMercator", BaseGCS::pcvGaussKrugerTranverseMercator)
        .value("epcvCzechKrovak", BaseGCS::pcvCzechKrovak)
        .value("epcvCzechKrovakObsolete", BaseGCS::pcvCzechKrovakObsolete)
        .value("epcvMercatorScaleReduction", BaseGCS::pcvMercatorScaleReduction)
        .value("epcvObliqueConformalConic", BaseGCS::pcvObliqueConformalConic)
        .value("epcvCzechKrovak95", BaseGCS::pcvCzechKrovak95)
        .value("epcvCzechKrovak95Obsolete", BaseGCS::pcvCzechKrovak95Obsolete)
        .value("epcvPolarStereographicStandardLatitude", BaseGCS::pcvPolarStereographicStandardLatitude)
        .value("epcvTransverseMercatorAffinePostProcess", BaseGCS::pcvTransverseMercatorAffinePostProcess)
        .value("epcvNonEarth", BaseGCS::pcvNonEarth)
        .value("epcvObliqueCylindricalHungary", BaseGCS::pcvObliqueCylindricalHungary)
        .value("epcvTransverseMercatorDenmarkSys34", BaseGCS::pcvTransverseMercatorDenmarkSys34)
        .value("epcvTransverseMercatorOstn97", BaseGCS::pcvTransverseMercatorOstn97)
        .value("epcvAzimuthalEquidistantElevatedEllipsoid", BaseGCS::pcvAzimuthalEquidistantElevatedEllipsoid)
        .value("epcvTransverseMercatorOstn02", BaseGCS::pcvTransverseMercatorOstn02)
        .value("epcvTransverseMercatorDenmarkSys3499", BaseGCS::pcvTransverseMercatorDenmarkSys3499)
        .value("epcvTransverseMercatorKruger", BaseGCS::pcvTransverseMercatorKruger)
        .value("epcvWinkelTripel", BaseGCS::pcvWinkelTripel)
        .value("epcvNonEarthScaleRotation", BaseGCS::pcvNonEarthScaleRotation)
        .value("epcvLambertConformalConicAffinePostProcess", BaseGCS::pcvLambertConformalConicAffinePostProcess)
        .value("epcvTransverseMercatorDenmarkSys3401", BaseGCS::pcvTransverseMercatorDenmarkSys3401)
        .value("epcvEquidistantCylindricalEllipsoid", BaseGCS::pcvEquidistantCylindricalEllipsoid)
        .value("epcvPlateCarree", BaseGCS::pcvPlateCarree)
        .value("epcvPopularVisualizationPseudoMercator", BaseGCS::pcvPopularVisualizationPseudoMercator)
        .value("epcvLambertMichigan", BaseGCS::pcvLambertMichigan)
        .value("epcvCzechKrovakModified", BaseGCS::pcvCzechKrovakModified)
        .value("epcvHotineObliqueMercator1UV", BaseGCS::pcvHotineObliqueMercator1UV)
        .value("epcvHotineObliqueMercator1XY", BaseGCS::pcvHotineObliqueMercator1XY)
        .value("epcvHotineObliqueMercator2UV", BaseGCS::pcvHotineObliqueMercator2UV)
        .value("epcvHotineObliqueMercator2XY", BaseGCS::pcvHotineObliqueMercator2XY)
        .value("epcvRectifiedSkewOrthomorphic", BaseGCS::pcvRectifiedSkewOrthomorphic)
        .value("epcvRectifiedSkewOrthomorphicCentered", BaseGCS::pcvRectifiedSkewOrthomorphicCentered)
        .value("epcvRectifiedSkewOrthomorphicOrigin", BaseGCS::pcvRectifiedSkewOrthomorphicOrigin)
        .value("epcvTotalUniversalTransverseMercator", BaseGCS::pcvTotalUniversalTransverseMercator)
        .value("epcvTotalTransverseMercatorBF", BaseGCS::pcvTotalTransverseMercatorBF)
        .value("epcvObliqueMercatorMinnesota", BaseGCS::pcvObliqueMercatorMinnesota)
        .value("epcvTransverseMercatorOstn15", BaseGCS::pcvTransverseMercatorOstn15)
        .export_values();

    c0.def_property("ProjectionCode", &BaseGCS::GetProjectionCode, &BaseGCS::SetProjectionCode);
    c0.def("GetProjectionCode", &BaseGCS::GetProjectionCode);
    c0.def("SetProjectionCode", &BaseGCS::SetProjectionCode, "projectionCode"_a);

    c0.def("GetGroup", &BaseGCS::GetGroup, "group"_a);
    c0.def("SetGroup", &BaseGCS::SetGroup, "source"_a);

    c0.def("GetLocation", &BaseGCS::GetLocation, "location"_a);
    c0.def("GetSource", &BaseGCS::GetSource, "source"_a);
    c0.def("SetSource", &BaseGCS::SetSource, "source"_a);

    c0.def("GetUnits", &BaseGCS::GetUnits, "units"_a);

    c0.def_property("UnitCode", &BaseGCS::GetUnitCode, &BaseGCS::SetUnitCode);
    c0.def("GetUnitCode", &BaseGCS::GetUnitCode);
    c0.def("SetUnitCode", &BaseGCS::SetUnitCode, "code"_a);

    c0.def_property_readonly("EPSGUnitCode", &BaseGCS::GetEPSGUnitCode);
    c0.def("GetEPSGUnitCode", &BaseGCS::GetEPSGUnitCode);

    c0.def("SetUnitByKeyname", &BaseGCS::SetUnitByKeyname, "unitKeyname"_a);
    c0.def("GetDatumName", &BaseGCS::GetDatumName);

    c0.def_property("DatumCode", &BaseGCS::GetDatumCode, &BaseGCS::SetDatumCode);
    c0.def("GetDatumCode", &BaseGCS::GetDatumCode);
    c0.def("SetDatumCode", &BaseGCS::SetDatumCode, "datumCode"_a);

    c0.def_property("Datum", &BaseGCS::GetDatum, &BaseGCS::SetDatum);
    c0.def("GetDatum", &BaseGCS::GetDatum);
    c0.def("SetDatum", &BaseGCS::SetDatum, "datum"_a);

    c0.def("HasCustomDatum", &BaseGCS::HasCustomDatum);

    c0.def_property_readonly("DatumDescription", &BaseGCS::GetDatumDescription);
    c0.def("GetDatumDescription", &BaseGCS::GetDatumDescription);

    c0.def("GetDatumSource", &BaseGCS::GetDatumSource, "datumSource"_a);

    c0.def_property_readonly("DatumConvertMethod", &BaseGCS::GetDatumConvertMethod);
    c0.def("GetDatumConvertMethod", &BaseGCS::GetDatumConvertMethod);

    c0.def("GetDatumDelta", &BaseGCS::GetDatumDelta, "delta"_a);
    c0.def("GetDatumRotation", &BaseGCS::GetDatumRotation, "rotation"_a);

    c0.def_property_readonly("DatumScale", &BaseGCS::GetDatumScale);
    c0.def("GetDatumScale", &BaseGCS::GetDatumScale);

    //Need GridFileDefinition published for usage
    //c0.def("GetDatumGridFile", &BaseGCS::GetDatumGridFile, "gridFileDef"_a);

    c0.def("DatumParametersValid", &BaseGCS::DatumParametersValid, "deltaValid"_a, "rotationValid"_a, "scaleValid"_a);
    c0.def("DatumExtendedParametersValid", &BaseGCS::DatumExtendedParametersValid, "deltaValid"_a, "rotationValid"_a, "scaleValid"_a, "gridValid"_a);

    c0.def_property_readonly("VerticalDatumName", &BaseGCS::GetVerticalDatumName);
    c0.def("GetVerticalDatumName", &BaseGCS::GetVerticalDatumName);

    c0.def_property_readonly("VerticalDatumCode", &BaseGCS::GetVerticalDatumCode);
    c0.def("GetVerticalDatumCode", &BaseGCS::GetVerticalDatumCode);

    c0.def_property("VerticalDatumCode", &BaseGCS::GetNetVerticalDatumCode, &BaseGCS::SetVerticalDatumCode);
    c0.def("GetNetVerticalDatumCode", &BaseGCS::GetNetVerticalDatumCode);
    c0.def("SetVerticalDatumCode", &BaseGCS::SetVerticalDatumCode, "VertDatumCode"_a);

    c0.def("SetVerticalDatumByKey", &BaseGCS::SetVerticalDatumByKey, "verticalDatumKey"_a);

    c0.def_property_readonly("EllipsoidName", &BaseGCS::GetEllipsoidName);
    c0.def("GetEllipsoidName", &BaseGCS::GetEllipsoidName);

    c0.def_property("EllipsoidCode", &BaseGCS::GetEllipsoidCode, &BaseGCS::SetEllipsoidCode);
    c0.def("GetEllipsoidCode", &BaseGCS::GetEllipsoidCode);
    c0.def("SetEllipsoidCode", &BaseGCS::SetEllipsoidCode, "ellipsoidCode"_a);

    c0.def_property_readonly("EllipsoidDescription", &BaseGCS::GetEllipsoidDescription);
    c0.def("GetEllipsoidDescription", &BaseGCS::GetEllipsoidDescription);

    c0.def("GetEllipsoidSource", &BaseGCS::GetEllipsoidSource, "ellipsoidSource"_a);
 
    c0.def_property("OriginLatitude", &BaseGCS::GetOriginLatitude, &BaseGCS::SetOriginLatitude);
    c0.def("GetOriginLatitude", &BaseGCS::GetOriginLatitude);
    c0.def("SetOriginLatitude", &BaseGCS::SetOriginLatitude, "value"_a);

    c0.def_property("FalseEasting", &BaseGCS::GetFalseEasting, &BaseGCS::SetFalseEasting);
    c0.def("GetFalseEasting", &BaseGCS::GetFalseEasting);
    c0.def("SetFalseEasting", &BaseGCS::SetFalseEasting, "value"_a);

    c0.def_property("FalseNorthing", &BaseGCS::GetFalseNorthing, &BaseGCS::SetFalseNorthing);
    c0.def("GetFalseNorthing", &BaseGCS::GetFalseNorthing);
    c0.def("SetFalseNorthing", &BaseGCS::SetFalseNorthing, "value"_a);

    c0.def_property("ScaleReduction", &BaseGCS::GetScaleReduction, &BaseGCS::SetScaleReduction);
    c0.def("GetScaleReduction", &BaseGCS::GetScaleReduction);
    c0.def("SetScaleReduction", &BaseGCS::SetScaleReduction, "value"_a);

    c0.def_property_readonly("EllipsoidPolarRadius", &BaseGCS::GetEllipsoidPolarRadius);
    c0.def("GetEllipsoidPolarRadius", &BaseGCS::GetEllipsoidPolarRadius);

    c0.def_property_readonly("EllipsoidEquatorialRadius", &BaseGCS::GetEllipsoidEquatorialRadius);
    c0.def("GetEllipsoidEquatorialRadius", &BaseGCS::GetEllipsoidEquatorialRadius);

    c0.def_property_readonly("EllipsoidEccentricity", &BaseGCS::GetEllipsoidEccentricity);
    c0.def("GetEllipsoidEccentricity", &BaseGCS::GetEllipsoidEccentricity);

    c0.def_property("MinimumLongitude", &BaseGCS::GetMinimumLongitude, &BaseGCS::SetMinimumLongitude);
    c0.def("GetMinimumLongitude", &BaseGCS::GetMinimumLongitude);
    c0.def("SetMinimumLongitude", &BaseGCS::SetMinimumLongitude, "value"_a);

    c0.def_property("MaximumLongitude", &BaseGCS::GetMaximumLongitude, &BaseGCS::SetMaximumLongitude);
    c0.def("GetMaximumLongitude", &BaseGCS::GetMaximumLongitude);
    c0.def("SetMaximumLongitude", &BaseGCS::SetMaximumLongitude, "value"_a);

    c0.def_property("MinimumLatitude", &BaseGCS::GetMinimumLatitude, &BaseGCS::SetMinimumLatitude);
    c0.def("GetMinimumLatitude", &BaseGCS::GetMinimumLatitude);
    c0.def("SetMinimumLatitude", &BaseGCS::SetMinimumLatitude, "value"_a);

    c0.def_property("MaximumLatitude", &BaseGCS::GetMaximumLatitude, &BaseGCS::SetMaximumLatitude);
    c0.def("GetMaximumLatitude", &BaseGCS::GetMaximumLatitude);
    c0.def("SetMaximumLatitude", &BaseGCS::SetMaximumLatitude, "value"_a);

    c0.def_property_readonly("MinimumUsefulLongitude", &BaseGCS::GetMinimumUsefulLongitude);
    c0.def("GetMinimumUsefulLongitude", &BaseGCS::GetMinimumUsefulLongitude);

    c0.def_property_readonly("MaximumUsefulLongitude", &BaseGCS::GetMaximumUsefulLongitude);
    c0.def("GetMaximumUsefulLongitude", &BaseGCS::GetMaximumUsefulLongitude);

    c0.def_property_readonly("MinimumUsefulLatitude", &BaseGCS::GetMinimumUsefulLatitude);
    c0.def("GetMinimumUsefulLatitude", &BaseGCS::GetMinimumUsefulLatitude);

    c0.def_property_readonly("MaximumUsefulLatitude", &BaseGCS::GetMaximumUsefulLatitude);
    c0.def("GetMaximumUsefulLatitude", &BaseGCS::GetMaximumUsefulLatitude);

    c0.def_property("StandardParallel1", &BaseGCS::GetStandardParallel1, &BaseGCS::SetStandardParallel1);
    c0.def("GetStandardParallel1", &BaseGCS::GetStandardParallel1);
    c0.def("SetStandardParallel1", &BaseGCS::SetStandardParallel1, "value"_a);

    c0.def_property("StandardParallel2", &BaseGCS::GetStandardParallel2, &BaseGCS::SetStandardParallel2);
    c0.def("GetStandardParallel2", &BaseGCS::GetStandardParallel2);
    c0.def("SetStandardParallel2", &BaseGCS::SetStandardParallel2, "value"_a);

    c0.def_property("Azimuth", &BaseGCS::GetAzimuth, &BaseGCS::SetAzimuth);
    c0.def("GetAzimuth", &BaseGCS::GetAzimuth);
    c0.def("SetAzimuth", &BaseGCS::SetAzimuth, "value"_a);

    c0.def_property("CentralMeridian", &BaseGCS::GetCentralMeridian, &BaseGCS::SetCentralMeridian);
    c0.def("GetCentralMeridian", &BaseGCS::GetCentralMeridian);
    c0.def("SetCentralMeridian", &BaseGCS::SetCentralMeridian, "value"_a);

    c0.def_property("EasternMeridian", &BaseGCS::GetEasternMeridian, &BaseGCS::SetEasternMeridian);
    c0.def("GetEasternMeridian", &BaseGCS::GetEasternMeridian);
    c0.def("SetEasternMeridian", &BaseGCS::SetEasternMeridian, "value"_a);

    c0.def_property("CentralPointLongitude", &BaseGCS::GetCentralPointLongitude, &BaseGCS::SetCentralPointLongitude);
    c0.def("GetCentralPointLongitude", &BaseGCS::GetCentralPointLongitude);
    c0.def("SetCentralPointLongitude", &BaseGCS::SetCentralPointLongitude, "value"_a);

    c0.def_property("CentralPointLatitude", &BaseGCS::GetCentralPointLatitude, &BaseGCS::SetCentralPointLatitude);
    c0.def("GetCentralPointLatitude", &BaseGCS::GetCentralPointLatitude);
    c0.def("SetCentralPointLatitude", &BaseGCS::SetCentralPointLatitude, "value"_a);

    c0.def_property("Point1Longitude", &BaseGCS::GetPoint1Longitude, &BaseGCS::SetPoint1Longitude);
    c0.def("GetPoint1Longitude", &BaseGCS::GetPoint1Longitude);
    c0.def("SetPoint1Longitude", &BaseGCS::SetPoint1Longitude, "value"_a);

    c0.def_property("Point1Latitude", &BaseGCS::GetPoint1Latitude, &BaseGCS::SetPoint1Latitude);
    c0.def("GetPoint1Latitude", &BaseGCS::GetPoint1Latitude);
    c0.def("SetPoint1Latitude", &BaseGCS::SetPoint1Latitude, "value"_a);

    c0.def_property("Point2Longitude", &BaseGCS::GetPoint2Longitude, &BaseGCS::SetPoint2Longitude);
    c0.def("GetPoint2Longitude", &BaseGCS::GetPoint2Longitude);
    c0.def("SetPoint2Longitude", &BaseGCS::SetPoint2Longitude, "value"_a);

    c0.def_property("Point2Latitude", &BaseGCS::GetPoint2Latitude, &BaseGCS::SetPoint2Latitude);
    c0.def("GetPoint2Latitude", &BaseGCS::GetPoint2Latitude);
    c0.def("SetPoint2Latitude", &BaseGCS::SetPoint2Latitude, "value"_a);

    c0.def_property("GeoidSeparation", &BaseGCS::GetGeoidSeparation, &BaseGCS::SetGeoidSeparation);
    c0.def("GetGeoidSeparation", &BaseGCS::GetGeoidSeparation);
    c0.def("SetGeoidSeparation", &BaseGCS::SetGeoidSeparation, "value"_a);

    c0.def_property("ElevationAboveGeoid", &BaseGCS::GetElevationAboveGeoid, &BaseGCS::SetElevationAboveGeoid);
    c0.def("GetElevationAboveGeoid", &BaseGCS::GetElevationAboveGeoid);
    c0.def("SetElevationAboveGeoid", &BaseGCS::SetElevationAboveGeoid, "value"_a);

    c0.def_property("EllipsoidScaleFactor", &BaseGCS::GetEllipsoidScaleFactor, &BaseGCS::SetEllipsoidScaleFactor);
    c0.def("GetEllipsoidScaleFactor", &BaseGCS::GetEllipsoidScaleFactor);
    c0.def("SetEllipsoidScaleFactor", &BaseGCS::SetEllipsoidScaleFactor, "value"_a);

    c0.def_property("UTMZone", &BaseGCS::GetUTMZone, &BaseGCS::SetUTMZone);
    c0.def("GetUTMZone", &BaseGCS::GetUTMZone);
    c0.def("SetUTMZone", &BaseGCS::SetUTMZone, "value"_a);

    c0.def_property("Hemisphere", &BaseGCS::GetHemisphere, &BaseGCS::SetHemisphere);
    c0.def("GetHemisphere", &BaseGCS::GetHemisphere);
    c0.def("SetHemisphere", &BaseGCS::SetHemisphere, "value"_a);

    c0.def_property("Quadrant", &BaseGCS::GetQuadrant, &BaseGCS::SetQuadrant);
    c0.def("GetQuadrant", &BaseGCS::GetQuadrant);
    c0.def("SetQuadrant", &BaseGCS::SetQuadrant, "value"_a);

    c0.def_property("DanishSys34Region", &BaseGCS::GetDanishSys34Region, &BaseGCS::SetDanishSys34Region);
    c0.def("GetDanishSys34Region", &BaseGCS::GetDanishSys34Region);
    c0.def("SetDanishSys34Region", &BaseGCS::SetDanishSys34Region, "value"_a);

    c0.def_property("AffineA0", &BaseGCS::GetAffineA0, &BaseGCS::SetAffineA0);
    c0.def("GetAffineA0", &BaseGCS::GetAffineA0);
    c0.def("SetAffineA0", &BaseGCS::SetAffineA0, "value"_a);

    c0.def_property("AffineA1", &BaseGCS::GetAffineA1, &BaseGCS::SetAffineA1);
    c0.def("GetAffineA1", &BaseGCS::GetAffineA1);
    c0.def("SetAffineA1", &BaseGCS::SetAffineA1, "value"_a);

    c0.def_property("AffineA2", &BaseGCS::GetAffineA2, &BaseGCS::SetAffineA2);
    c0.def("GetAffineA2", &BaseGCS::GetAffineA2);
    c0.def("SetAffineA2", &BaseGCS::SetAffineA2, "value"_a);

    c0.def_property("AffineB0", &BaseGCS::GetAffineB0, &BaseGCS::SetAffineB0);
    c0.def("GetAffineB0", &BaseGCS::GetAffineB0);
    c0.def("SetAffineB0", &BaseGCS::SetAffineB0, "value"_a);

    c0.def_property("AffineB1", &BaseGCS::GetAffineB1, &BaseGCS::SetAffineB1);
    c0.def("GetAffineB1", &BaseGCS::GetAffineB1);
    c0.def("SetAffineB1", &BaseGCS::SetAffineB1, "value"_a);

    c0.def_property("AffineB2", &BaseGCS::GetAffineB2, &BaseGCS::SetAffineB2);
    c0.def("GetAffineB2", &BaseGCS::GetAffineB2);
    c0.def("SetAffineB2", &BaseGCS::SetAffineB2, "value"_a);

    c0.def("GetAffineParameters", [](BaseGCSCR self) 
        {
        double A0, A1, A2, B0, B1, B2;
        self.GetAffineParameters(&A0, &A1, &A2, &B0, &B1, &B2);
        return py::make_tuple(A0, A1, A2, B0, B1, B2);
        });
    c0.def("SetAffineParameters", &BaseGCS::SetAffineParameters, "A0"_a, "A1"_a, "A2"_a, "B0"_a, "B1"_a, "B2"_a);

    c0.def("DefinitionComplete", &BaseGCS::DefinitionComplete);
    c0.def_static("GetLinearUnitNames", &BaseGCS::GetLinearUnitNames);
    c0.def_static("GetUnitNames", &BaseGCS::GetUnitNames);
    c0.def_static("GetDatumNames", &BaseGCS::GetDatumNames);
    c0.def_static("GetEllipsoidNames", &BaseGCS::GetEllipsoidNames);
    c0.def("GetScaleAlongMeridian", &BaseGCS::GetScaleAlongMeridian, "point"_a);
    c0.def("GetScaleAlongParallel", &BaseGCS::GetScaleAlongParallel, "point"_a);
    c0.def("GetGridScale", &BaseGCS::GetGridScale, "point"_a);
    c0.def("GetConvergenceAngle", &BaseGCS::GetConvergenceAngle, "point"_a);

    c0.def("GetDistance", [](BaseGCSCR self, GeoPointCR  startPoint, GeoPointCR  endPoint)
        {
        double distance, azimuth;
        StatusInt status = self.GetDistance (&distance, &azimuth, startPoint, endPoint);
        return py::make_tuple (status, distance, azimuth);
        }, "startPoint"_a, "endPoint"_a);

    c0.def("GetDistanceInMeters", [](BaseGCSCR self, GeoPointCR  startPoint, GeoPointCR  endPoint)
        {
        double distance, azimuth;
        StatusInt status = self.GetDistanceInMeters (&distance, &azimuth, startPoint, endPoint);
        return py::make_tuple (status, distance, azimuth);
        }, "startPoint"_a, "endPoint"_a);

    c0.def("GetCenterPoint", &BaseGCS::GetCenterPoint, "centerPoint"_a);
    c0.def("IsEquivalent", &BaseGCS::IsEquivalent, "compareTo"_a);
    c0.def("IsEqual", &BaseGCS::IsEqual, "compareTo"_a);
    c0.def("CorrectVerticalDatumToPreserveLegacyElevation", &BaseGCS::CorrectVerticalDatumToPreserveLegacyElevation, "extent"_a, "targetGCS"_a);

    c0.def("Compare", [](BaseGCSCR self, BaseGCSCR compareTo, bool stopFirstDifference)
        {
        bool datumDifferent, csDifferent, verticalDatumDifferent, localTransformDifferent;
        bool status = self.Compare(compareTo, datumDifferent, csDifferent, verticalDatumDifferent, localTransformDifferent, stopFirstDifference);
        return py::make_tuple (status, datumDifferent, csDifferent, verticalDatumDifferent, localTransformDifferent);
        }, "compareTo"_a, "stopFirstDifference"_a);

    c0.def("GetMathematicalDomain", &BaseGCS::GetMathematicalDomain, "shape"_a);

    c0.def("GetMathematicalDomainExtent", [](BaseGCSCR self)
        {
        double minLongitude, maxLongitude, minLatitude, maxLatitude;
        StatusInt status = self.GetMathematicalDomainExtent (minLongitude, maxLongitude, minLatitude, maxLatitude);
        return py::make_tuple (status, minLongitude, maxLongitude, minLatitude, maxLatitude);
        });

#ifdef DICTIONARY_MANAGEMENT_ONLY
    c0.def("OutputAsASC", &BaseGCS::OutputAsASC, "GCSAsASC"_a);
#endif

    c0.def("HasEquivalentDatum", &BaseGCS::HasEquivalentDatum, "compareTo"_a);
    c0.def("GetEPSGCode", py::overload_cast<bool>(&BaseGCS::GetEPSGCode, py::const_), "noSearch"_a=false);
    c0.def("GetEPSGDatumCode", &BaseGCS::GetEPSGDatumCode, "noSearch"_a = false);
    c0.def("GetEPSGEllipsoidCode", &BaseGCS::GetEPSGEllipsoidCode, "noSearch"_a = false);

    c0.def_property("StoredEPSGCode", &BaseGCS::GetStoredEPSGCode, &BaseGCS::SetStoredEPSGCode);
    c0.def("GetStoredEPSGCode", &BaseGCS::GetStoredEPSGCode);
    c0.def("SetStoredEPSGCode", &BaseGCS::SetStoredEPSGCode, "value"_a);

    c0.def("CartesianFromLatLong", &BaseGCS::CartesianFromLatLong, "outCartesian"_a, "inLatLong"_a);
    c0.def("CartesianFromLatLong2D", &BaseGCS::CartesianFromLatLong2D, "outCartesian"_a, "inLatLong"_a);
    c0.def("LatLongFromCartesian", &BaseGCS::LatLongFromCartesian, "outLatLong"_a, "inCartesian"_a);
    c0.def("LatLongFromCartesian2D", &BaseGCS::LatLongFromCartesian2D, "outLatLong"_a, "inCartesian"_a);
    c0.def("UnitsFromMeters", &BaseGCS::UnitsFromMeters);
    c0.def("CheckGeoPointRange", &BaseGCS::CheckGeoPointRange, "points"_a, "numPoints"_a);
    c0.def("CheckCartesianRange", &BaseGCS::CheckCartesianRange, "points"_a, "numPoints"_a);

    c0.def_property("ReprojectElevation", &BaseGCS::GetReprojectElevation, &BaseGCS::SetReprojectElevation);
    c0.def("GetReprojectElevation", &BaseGCS::GetReprojectElevation);
    c0.def("SetReprojectElevation", &BaseGCS::SetReprojectElevation, "value"_a);

    c0.def("LatLongFromLatLong", &BaseGCS::LatLongFromLatLong, "outLatLong"_a, "inLatLong"_a, "targetGCS"_a);
    c0.def("LatLongFromLatLong2D", &BaseGCS::LatLongFromLatLong2D, "outLatLong"_a, "inLatLong"_a, "targetGCS"_a);

    c0.def_static("RadiansFromDegrees", &BaseGCS::RadiansFromDegrees, "inDegrees"_a);
    c0.def_static("DegreesFromRadians", &BaseGCS::DegreesFromRadians, "inRadians"_a);
    c0.def("LatLongFromXYZ", &BaseGCS::LatLongFromXYZ, "outLatLong"_a, "inXYZ"_a);
    c0.def("XYZFromLatLong", &BaseGCS::XYZFromLatLong, "outXYZ"_a, "inLatLong"_a);

    //===================================================================================
    // Enum LocalTransformType
    py::enum_<LocalTransformType>(m, "LocalTransformType")
        .value("eTRANSFORM_None", LocalTransformType::TRANSFORM_None)
        .value("eTRANSFORM_Helmert", LocalTransformType::TRANSFORM_Helmert)
        .value("eTRANSFORM_SecondOrderConformal", LocalTransformType::TRANSFORM_SecondOrderConformal)
        .export_values();

    //===================================================================================
    // Struct Group
    py::class_<Group, std::unique_ptr<Group, py::nodelete>> c1(m, "GeoCoordGroup");

    c1.def_property_readonly("Name", &Group::GetName);
    c1.def("GetName", &Group::GetName);

    c1.def_property_readonly("Description", &Group::GetDescription);
    c1.def("GetDescription", &Group::GetDescription);

    c1.def("GetMemberEnumerator", &Group::GetMemberEnumerator);
    c1.def("GetGroupEnumerator", &Group::GetGroupEnumerator);
    c1.def("Destroy", &Group::Destroy);

    //===================================================================================
    // Struct GroupEnumerator
    py::class_<GroupEnumerator, std::unique_ptr<GroupEnumerator, py::nodelete>> c2(m, "GroupEnumerator");

    c2.def("MoveNext", &GroupEnumerator::MoveNext);
    c2.def("GetCurrent", &GroupEnumerator::GetCurrent);
    c2.def("Destroy", &GroupEnumerator::Destroy);

    //===================================================================================
    // Struct MemberEnumerator
    py::class_<MemberEnumerator, std::unique_ptr<MemberEnumerator, py::nodelete>> c3(m, "MemberEnumerator");

    c3.def("MoveNext", &MemberEnumerator::MoveNext);
    c3.def("GetCurrentGCSName", &MemberEnumerator::GetCurrentGCSName);
    c3.def("GetCurrentGCSDescription", &MemberEnumerator::GetCurrentGCSDescription);
    c3.def("Destroy", &MemberEnumerator::Destroy);

    //===================================================================================
    // Enum GeoUnitBase
    py::enum_<GeoUnitBase>(m, "GeoUnitBase")
        .value("eNone", GeoUnitBase::None)
        .value("eMeter", GeoUnitBase::Meter)
        .value("eDegree", GeoUnitBase::Degree)
        .export_values();

    //===================================================================================
    // Enum GeoUnitSystem
    py::enum_<GeoUnitSystem>(m, "GeoUnitSystem")
        .value("eNone", GeoUnitSystem::None)
        .value("eEnglish", GeoUnitSystem::English)
        .value("eMetric", GeoUnitSystem::Metric)
        .value("eUSSurvey", GeoUnitSystem::USSurvey)
        .export_values();

    //===================================================================================
    // struct Unit
    typedef GeoCoordinates::Unit GeoCoordUnit;

    py::class_< GeoCoordUnit, std::unique_ptr<GeoCoordUnit, py::nodelete>> c4(m, "Unit");

    c4.def_static("FindUnit", &GeoCoordUnit::FindUnit, "unitName"_a);

    c4.def("GetName", &GeoCoordUnit::GetName);
    c4.def("GetPluralName", &GeoCoordUnit::GetPluralName);
    c4.def("GetAbbreviation", &GeoCoordUnit::GetAbbreviation);
    c4.def("GetSystem", &GeoCoordUnit::GetSystem);
    c4.def("GetBase", &GeoCoordUnit::GetBase);
    c4.def("GetEPSGCode", &GeoCoordUnit::GetEPSGCode);
    c4.def("GetConversionFactor", &GeoCoordUnit::GetConversionFactor);
    c4.def("Destroy", &GeoCoordUnit::Destroy);

    //===================================================================================
    // struct UnitEnumerator
    py::class_< UnitEnumerator> c5(m, "UnitEnumerator");
    c5.def(py::init<>());
    c5.def("MoveNext", &UnitEnumerator::MoveNext);
    c5.def("GetCurrent", &UnitEnumerator::GetCurrent);
    c5.def("Destroy", &UnitEnumerator::Destroy);

    //===================================================================================
    // struct Ellipsoid
    py::class_< Ellipsoid, std::unique_ptr<Ellipsoid, py::nodelete>> c6(m, "Ellipsoid");
    c6.def_static ("CreateEllipsoid", py::overload_cast<WCharCP>(&Ellipsoid::CreateEllipsoid), "keyName"_a);
    c6.def("IsValid", &Ellipsoid::IsValid);
    c6.def("GetError", &Ellipsoid::GetError);
    c6.def("GetErrorMessage", &Ellipsoid::GetErrorMessage, "errorMsg"_a);

    c6.def_property("Name", &Ellipsoid::GetName, &Ellipsoid::SetName);
    c6.def("GetName", &Ellipsoid::GetName);
    c6.def("SetName", &Ellipsoid::SetName, "value"_a);

    c6.def_property_readonly("Description", &Ellipsoid::GetDescription);
    c6.def("GetDescription", &Ellipsoid::GetDescription);

    c6.def("GetSource", &Ellipsoid::GetSource, "source"_a);

    c6.def_property_readonly("PolarRadius", &Ellipsoid::GetPolarRadius);
    c6.def("GetPolarRadius", &Ellipsoid::GetPolarRadius);

    c6.def_property_readonly("EquatorialRadius", &Ellipsoid::GetEquatorialRadius);
    c6.def("GetEquatorialRadius", &Ellipsoid::GetEquatorialRadius);

    c6.def_property_readonly("Eccentricity", &Ellipsoid::GetEccentricity);
    c6.def("GetEccentricity", &Ellipsoid::GetEccentricity);

    c6.def_property("EPSGCode", &Ellipsoid::GetEPSGCode, &Ellipsoid::SetEPSGCode);
    c6.def("GetEPSGCode", &Ellipsoid::GetEPSGCode);
    c6.def("SetEPSGCode", &Ellipsoid::SetEPSGCode, "value"_a);

    c6.def("Destroy", &Ellipsoid::Destroy);

#ifdef DICTIONARY_MANAGEMENT_ONLY
    c6.def("OutputAsASC", &Ellipsoid::OutputAsASC);
#endif

    c6.def_static("CreateEnumerator", &Ellipsoid::CreateEnumerator);

    //===================================================================================
    // struct Ellipsoid
    py::class_< EllipsoidEnumerator, std::unique_ptr<EllipsoidEnumerator, py::nodelete>> c7(m, "EllipsoidEnumerator");

    c7.def("MoveNext", &EllipsoidEnumerator::MoveNext);
    c7.def("GetCurrent", &EllipsoidEnumerator::GetCurrent);
    c7.def("Destroy", &EllipsoidEnumerator::Destroy);

    //===================================================================================
    // struct Datum
    py::class_< Datum, std::unique_ptr<Datum, py::nodelete>> c8(m, "Datum");

    c8.attr("NO_DATUM_CODE") = Datum::NO_DATUM_CODE;
    c8.attr("CUSTOM_DATUM_CODE") = Datum::CUSTOM_DATUM_CODE;
    c8.attr("USER_DATUM_CODE_OFFSET") = Datum::USER_DATUM_CODE_OFFSET;
    c8.attr("DATUM_CODE_SEPARATOR") = Datum::DATUM_CODE_SEPARATOR;

    c8.def_static("CreateDatum", py::overload_cast<WCharCP>(&Datum::CreateDatum), "keyName"_a);

    c8.def("IsValid", &Datum::IsValid);
    c8.def("GetError", &Datum::GetError);
    c8.def("GetErrorMessage", &Datum::GetErrorMessage, "errorMsg"_a);

    c8.def_property("Name", &Datum::GetName, &Datum::SetName);
    c8.def("GetName", &Datum::GetName);
    c8.def("SetName", &Datum::SetName, "value"_a);

    c8.def_property("Description", &Datum::GetDescription, &Datum::SetDescription);
    c8.def("GetDescription", &Datum::GetDescription);
    c8.def("SetDescription", &Datum::SetDescription, "value"_a);

    c8.def_property("Source", &Datum::GetSource, &Datum::SetSource);
    c8.def("GetSource", &Datum::GetSource);
    c8.def("SetSource", &Datum::SetSource, "value"_a);

    c8.def_property("Source", &Datum::GetConvertToWGS84MethodCode, &Datum::SetConvertToWGS84MethodCode);
    c8.def("GetConvertToWGS84MethodCode", &Datum::GetConvertToWGS84MethodCode);
    c8.def("SetConvertToWGS84MethodCode", &Datum::SetConvertToWGS84MethodCode, "value"_a);

    c8.def("UsesAGeocentricMethod", &Datum::UsesAGeocentricMethod);
    c8.def("GetDelta", &Datum::GetDelta, "delta"_a);
    c8.def("SetDelta", &Datum::SetDelta, "delta"_a);

    c8.def("GetRotation", &Datum::GetRotation, "rotation"_a);
    c8.def("SetRotation", &Datum::SetRotation, "rotation"_a);

    c8.def_property("Scale", &Datum::GetScale, &Datum::SetScale);
    c8.def("GetScale", &Datum::GetScale);
    c8.def("SetScale", &Datum::SetScale, "scalePPM"_a);

    //Need GridFileDefinition published for usage
    //c8.def("SetGridFile", &Datum::SetGridFile, "gridFileDef"_a);
    //c8.def("GetGridFile", &Datum::GetGridFile, "gridFileDef"_a, "strict"_a = true);

    c8.def_property("EPSGCode", &Datum::GetEPSGCode, &Datum::SetEPSGCode);
    c8.def("GetEPSGCode", &Datum::GetEPSGCode);
    c8.def("SetEPSGCode", &Datum::SetEPSGCode, "value"_a);

    c8.def_property_readonly("EllipsoidName", &Datum::GetEllipsoidName);
    c8.def("GetEllipsoidName", &Datum::GetEllipsoidName);

    c8.def_property("EllipsoidCode", &Datum::GetEllipsoidCode, &Datum::SetEllipsoidCode);
    c8.def("GetEllipsoidCode", &Datum::GetEllipsoidCode);
    c8.def("SetEllipsoidCode", &Datum::SetEllipsoidCode, "ellipsoidCode"_a);

    c8.def_property("EllipsoidDescription", &Datum::GetEllipsoidDescription, &Datum::GetEllipsoidSource);
    c8.def("GetEllipsoidDescription", &Datum::GetEllipsoidDescription);
    c8.def("GetEllipsoidSource", &Datum::GetEllipsoidSource, "ellipsoidSource"_a);

    c8.def_property_readonly("EllipsoidPolarRadius", &Datum::GetEllipsoidPolarRadius);
    c8.def("GetEllipsoidPolarRadius", &Datum::GetEllipsoidPolarRadius);

    c8.def_property_readonly("EllipsoidEquatorialRadius", &Datum::GetEllipsoidEquatorialRadius);
    c8.def("GetEllipsoidEquatorialRadius", &Datum::GetEllipsoidEquatorialRadius);

    c8.def_property_readonly("EllipsoidEccentricity", &Datum::GetEllipsoidEccentricity);
    c8.def("GetEllipsoidEccentricity", &Datum::GetEllipsoidEccentricity);

    c8.def_property("Ellipsoid", &Datum::GetEllipsoid, &Datum::SetEllipsoid);
    c8.def("GetEllipsoid", &Datum::GetEllipsoid);
    c8.def("SetEllipsoid", &Datum::SetEllipsoid, "newEllipsoid"_a);

    c8.def("ParametersValid", [](Datum const& self)
        {
        bool deltaValid, rotationValid, scaleValid;
        self.ParametersValid(deltaValid, rotationValid, scaleValid);
        return py::make_tuple (deltaValid, rotationValid, scaleValid);
        });

    c8.def("ExtendedParametersValid", [](Datum const& self)
        {
        bool deltaValid, rotationValid, scaleValid, gridValid;
        self.ExtendedParametersValid(deltaValid, rotationValid, scaleValid, gridValid);
        return py::make_tuple (deltaValid, rotationValid, scaleValid, gridValid);
        });

    c8.def("Destroy", &Datum::Destroy);

#ifdef DICTIONARY_MANAGEMENT_ONLY
    c8.def("OutputAsASC", &Datum::OutputAsASC, "DatumAsASC"_a);
#endif

    c8.def_static ("CreateEnumerator", &Datum::CreateEnumerator);

    //===================================================================================
    // struct DatumEnumerator
    py::class_< DatumEnumerator, std::unique_ptr<DatumEnumerator, py::nodelete>> c9(m, "DatumEnumerator");

    c9.def("MoveNext", &DatumEnumerator::MoveNext);
    c9.def("GetCurrent", &DatumEnumerator::GetCurrent);
    c9.def("Destroy", &DatumEnumerator::Destroy);
    }
