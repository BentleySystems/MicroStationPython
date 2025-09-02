/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\basegeocoord.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnGeoCoord/DgnGeoCoord.h>

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_DatumEnumerator_Destroy =R"doc(Free this DatumEnumerator.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_DatumEnumerator_GetCurrent =R"doc(Gets the current Datum.

:returns:
    the current Datum. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_DatumEnumerator_MoveNext =R"doc(Moves to the next Datum

:returns:
    true if successful in moving to the next Datum, false if there are
    no more. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_OutputAsASC =R"doc(Creates a string that contains the CSMAP ASC format text definition of
the datum. This format is only useful for dictionary management
purposes.

:param DatumAsASC:
    (output) Reference to string that receives the text ASC desctiption of
    GCS.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_Destroy =R"doc(Free this Datum. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_ExtendedParametersValid =R"doc(Returns whether the delta, rotation, and scale parameters are valid
for this Datum.

:param deltaValid:
    (output) Returns true if the datum is valid and its WGS84ConvertCode
    indicates that the delta parameters are used.

:param rotationValid:
    (output) Returns true if the datum is valid and its WGS84ConvertCode
    indicates that the rotation parameters are used.

:param scaleValid:
    (output) Returns true if the datum is valid and its WGS84ConvertCode
    indicates that the scale parameter is used.

:param gridValid:
    (output) Returns true if the datum is valid and its WGS84ConvertCode
    indicates that grid file is used.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_ParametersValid =R"doc(Returns whether the delta, rotation, and scale parameters are valid
for this Datum.

:param deltaValid:
    (output) Returns true if the datum is valid and its WGS84ConvertCode
    indicates that the delta parameters are used.

:param rotationValid:
    (output) Returns true if the datum is valid and its WGS84ConvertCode
    indicates that the rotation parameters are used.

:param scaleValid:
    (output) Returns true if the datum is valid and its WGS84ConvertCode
    indicates that the scale parameter is used.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_SetEllipsoid =R"doc(Sets the ellipsoid for the datum. The ellipsoid is captured and must
not be destroyed by the caller.

:param newEllipsoid:
    (input) The new Ellipsoid for the Datum.

:returns:
    SUCCESS if ellipsoid was correctly set.  .)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_GetEllipsoid =R"doc(Returns the pointer to the internal ellipsoid used by this Datum

:returns:
    The Ellipsoid of the Datum. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_GetEllipsoidEccentricity =R"doc(Gets the eccentricity value for the Ellipsoid.

:returns:
    The eccentricity value for the Ellipsoid.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_GetEllipsoidEquatorialRadius =R"doc(Gets the equatorial radius of the Ellipsoid.

:returns:
    The equatorial radius of the Ellipsoid.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_GetEllipsoidPolarRadius =R"doc(Gets the polar radius of the Coordinate System.

:returns:
    The polar radius of the Ellipsoid.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_GetEllipsoidSource =R"doc(Gets the source of the Ellipsoid used in this Datum

:returns:
    The source of the Ellipsoid of the Datum.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_GetEllipsoidDescription =R"doc(Gets the description of the Ellipsoid used in this Datum

:returns:
    The description of the Ellipsoid of the Datum.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_SetEllipsoidCode =R"doc(Sets the internal index of the Ellipsoid used in this Datum

:returns:
    Index of the Coordinate System Ellipsoid.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_GetEllipsoidCode =R"doc(Gets the internal index of the Ellipsoid used in this Datum

:returns:
    Index of the Coordinate System Ellipsoid. If not set then
    Ellipsoid::NO_ELLIPSOID_CODE is returned. If the ellipsoid is
    custom (for self-defined datums) then
    Ellipsoid::CUSTOM_ELLIPSOID_CODE is returned.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_GetEllipsoidName =R"doc(Gets the key name of the Ellipsoid used in this Datum

:returns:
    The key name Ellipsoid of the Datum.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_SetEPSGCode =R"doc(Sets the EPSG code in the datum definition.

:param value:
    (input) The new EPSG code. Can be 0 to 32767. Value 0 indicates there
    is no EPSG code for this definition.

:returns:
    SUCCESS is successful.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_GetEPSGCode =R"doc(Gets the EPSG code for this Datum, if known.

:returns:
    The EPSG code. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_GetGridFile =R"doc(Utilitarian method. Although the grid file definitions are part of the
transform path set using SetStoredGeodticTransformPath() method, some
common workflow require a single transform using a single grid file.
The present method will return the grid file definition if the datum
is currently based on a stored geodetic transform path containing a
single transform that must use the Grid File method to WGS84 and
contain a single grid file definition. If any of those conditions are
not met ERROR is returned, otherwise the grid file definition is
returned with a SUCCESS status.

:param gridFileDef:
    (output) Reference to the grid file that will receive the current datum
    grid file definition.

:param strict:
    (input) OPTIONAL default true. If false is provided then the method
    will return the grid file definition of the first transform even
    if additional transform exists. If true then there must not exist
    any additional transform.

:returns:
    SUCCESS is successful or ERROR if any prerequisite condition
    indicated above is not met.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_SetGridFile =R"doc(Utilitarian method. Although the grid file definitions are part of the
transform path set using SetStoredGeodticTransformPath() method, some
common workflow require a single transform using a single grid file.
The present method is functionally equivalent to clearing caches,
setting the convert method to GENGRID, removing the stored transform
path if any then creating a new stored transform path containing a
single transform to WGS84 based on grid file using a single grid file.

:param gridFileDef:
    (input) The new grid file definition for the datum transform.

:returns:
    SUCCESS is successful or ERROR in case of any error.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_SetScale =R"doc(Sets the datum transformation scaling in parts per million if known.

:param scalePPM:
    (input) The scale in parts per million.

:returns:
    GEOCOORDERR_ParameterNotUsed if the datum ConvertToWGS84Method
    does not use the scale setting. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_GetScale =R"doc(Gets the datum transformation scaling in parts per million if known.

:returns:
    The datum transformation scale in ppm.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_SetRotation =R"doc(Sets the angles from the WGS84 x, y, and z axes to those of this Datum

:param rotation:
    (input) The rotation angles.

:returns:
    GEOCOORDERR_ParameterNotUsed if the datum ConvertToWGS84Method
    does not use the rotation settings.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_GetRotation =R"doc(Gets the angles from the WGS84 x, y, and z axes to those of this Datum

:param rotation:
    (output) The rotation angles.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_SetDelta =R"doc(Sets the vector from the geocenter of the WGS84 Datum to the geocenter
of this Datum.

:param delta:
    (input) The vector from the geocenter of the WGS84 Datum to the
    geocenter of this Datum.

:returns:
    GEOCOORDERR_ParameterNotUsed if the datum ConvertToWGS84Method
    does not use the delta settings.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_GetDelta =R"doc(Gets the vector from the geocenter of the WGS84 Datum to the geocenter
of this Datum.

:param delta:
    (output) The vector from the geocenter of the WGS84 Datum to the
    geocenter of this Datum. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_UsesAGeocentricMethod =R"doc(Inidcates if the datum transformation uses one of the geocentric
methods (3, 4, 6, 7, molodenski, bursa wolf,...)

:returns:
    true if the datum transformation uses a geocentric method.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_SetConvertToWGS84MethodCode =R"doc(Sets the method used to convert longitude/latitude from this Datum to
the WGS84 datum.

:returns:
    BSISUCCESS or an error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_GetConvertToWGS84MethodCode =R"doc(Gets the method used to convert longitude/latitude from this Datum to
the WGS84 datum.

:returns:
    The convert method.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_SetSource =R"doc(Sets the source of the Datum

:returns:
    BSISUCCESS or an error code. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_GetSource =R"doc(Gets the source of the Datum

:returns:
    The source of the Datum.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_SetDescription =R"doc(Sets the description of the Datum.

:returns:
    BSISUCCESS or an error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_GetDescription =R"doc(Gets the description of the Datum.

:returns:
    The description of the Datum.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_SetName =R"doc(Sets the key name of the Datum.

:returns:
    BSISUCCESS or an error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_GetName =R"doc(Gets the name of the Datum

:returns:
    The name of the Datum.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_GetErrorMessage =R"doc(Gets the error message associated with constructor failure if IsValid
is false.

:returns:
    The CSMap error message.

See also:
    #GetError)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_GetError =R"doc(Gets the error code associated with constructor failure if IsValid is
false.

:returns:
    The CSMap error code.

See also:
    #GetErrorMessage )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_IsValid =R"doc(Returns whether the Datum is valid or not.

:returns:
    True if the Datum is valid, False otherwise.

See also:
    #GetError

Remark:
    s If the datum does not correspond to a datum in the datum
    library, IsValid is false, and GetError and GetErrorMessage can be
    used to obtain more details.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Datum_CreateDatum =R"doc(Initializes a new instance of the Datum class

:returns:
    Initialized Datum.

Remark:
    s If keyName is in the Datum library and valid, the return Datum's
    IsValid() returns true. Otherwise, the GetError() or
    GetErrorMessage() methods return the error.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_EllipsoidEnumerator_Destroy =R"doc(Free this EllipsoidEnumerator.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_EllipsoidEnumerator_GetCurrent =R"doc(Gets the current Ellipsoid.

:returns:
    the current Ellipsoid.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_EllipsoidEnumerator_MoveNext =R"doc(Moves to the next Ellipsoid

:returns:
    true if successful in moving to the next Ellipsoid, false if there
    are no more.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Ellipsoid_CreateEnumerator =R"doc(Factory method to create an EllipsoidEnumerator

:returns:
    An initialized EllipsoidEnumerator )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Ellipsoid_OutputAsASC =R"doc(Creates a string that contains the CSMAP ASC format text definition of
the Ellipsoid. This format is only useful for dictionary management
purposes.

:param EllipsoidAsASC:
    (output) Reference to string that receives the text ASC desctiption of
    GCS )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Ellipsoid_Destroy =R"doc(Free this Group. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Ellipsoid_SetEPSGCode =R"doc(Sets the EPSG code in the ellipsoid definition.

:param value:
    (input) The new EPSG code. Can be 0 to 32767 where 0 indicates there
    are no EPSG code for this definition

:returns:
    SUCCESS is successful.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Ellipsoid_GetEPSGCode =R"doc(Gets the EPSG code for this Ellipsoid, if known.

:returns:
    The EPSG code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Ellipsoid_GetEccentricity =R"doc(Gets the eccentricity value for the Ellipsoid.

:returns:
    The eccentricity value for the Ellipsoid.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Ellipsoid_GetEquatorialRadius =R"doc(Gets the equatorial radius of the Ellipsoid in meters.

:returns:
    The equatorial radius of the Ellipsoid in meters.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Ellipsoid_GetPolarRadius =R"doc(Gets the polar radius of the Ellipsoid in meters.

:returns:
    The polar radius of the Ellipsoid in meters.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Ellipsoid_GetSource =R"doc(Sets the source of the Ellipsoid

:returns:
    The source of the Ellipsoid. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Ellipsoid_GetDescription =R"doc(Gets the description of the Ellipsoid.

:returns:
    The description of the Ellipsoid. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Ellipsoid_SetName =R"doc(Sets the key name of the Ellipsoid.

:returns:
    BSISUCCESS or an error code. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Ellipsoid_GetName =R"doc(Gets the name of the Ellipsoid

:returns:
    The name of the Ellipsoid. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Ellipsoid_GetErrorMessage =R"doc(Gets the error message associated with constructor failure if IsValid
is false.

:returns:
    The CSMap error message.

See also:
    #GetError)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Ellipsoid_GetError =R"doc(Gets the error code associated with constructor failure if IsValid is
false.

:returns:
    The CSMap error code.

See also:
    #GetErrorMessage )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Ellipsoid_IsValid =R"doc(Returns whether the Ellipsoid is valid or not.

:returns:
    True if the Ellipsoid is valid, False otherwise.

See also:
    #GetError

Remark:
    s If the Ellipsoid does not correspond to a Ellipsoid in the
    Ellipsoid library, IsValid is false, and GetError and
    GetErrorMessage can be used to obtain more details.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_UnitEnumerator_Destroy =R"doc( )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_UnitEnumerator_GetCurrent =R"doc(Gets the current Unit.

:returns:
    the current Unit.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_UnitEnumerator_MoveNext =R"doc(Moves to the next unit

:returns:
    true if successful in moving to the next Unit, false if there are
    no more.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_MemberEnumerator_Destroy =R"doc(Free this MemberEnumerator. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_MemberEnumerator_GetCurrentGCSDescription =R"doc(Gets the current GCS Description.

:returns:
    the current member GCS description.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_MemberEnumerator_GetCurrentGCSName =R"doc(Gets the current GCS Name.

:returns:
    the current member GCS name )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_MemberEnumerator_MoveNext =R"doc(Moves to the GCS group member

:returns:
    true if successful in moving to the next GCS, false if there are
    no more.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_GroupEnumerator_Destroy =R"doc(Free this GroupEnumerator. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_GroupEnumerator_GetCurrent =R"doc(Gets the current Group.

:returns:
    the current GCS Group.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_GroupEnumerator_MoveNext =R"doc(Moves to the next group

:returns:
    true if successful in moving to the next Group, false if there are
    no more. -)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Group_Destroy =R"doc(Free this Group.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Group_GetGroupEnumerator =R"doc(Gets enumerator for Groups in the library

:returns:
    The enumerator. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Group_GetMemberEnumerator =R"doc(Gets enumerator for members of this group

:returns:
    The enumerator.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Group_GetDescription =R"doc(Gets the description of the GCS Group

:returns:
    The description of the Coordinate System.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_Group_GetName =R"doc(Gets the name of the GCS Group

:returns:
    The name of the GCS Group.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_XYZFromLatLong =R"doc(Calculates the XYZ (ECEF) coordinates from the longitude, latitude and
elevation. The ECEF coordinates are comuted according to GCS current
datum. This does not compute necessarily the ECEF relative to WGS84.
This method will not work for all GCS. In order to be able to compute
the ECEF coordinates relative to the GCS Datum and ellipsoid the
elevation must be expressed using a vertical datum that can be
converted to the Local Ellipsoid vertical datum. For example for all
GCS based on the NAD27 datum, the XYZ coordinate cannot be computed
due to the inability to convert to the Clarke66 ellipsoid local
elevation. Datum conversions to WGS84 rely on grid files which are
neutral vertical wise and the Clarke66 Ellipsoid does not have a shape
similar to the WGS84 ellipsoid. For the other GCS that are not
vertically coincident with WGS84 the elevation must already be based
on the local ellipsoid (vdcLocalEllipsoid). The present method will
not perform vertical change resulting from vertical datum upon the
WGS84 ellipsoid (vdcEllipsoid or vdcFromDatum) that may also require
application of geoid separation. Note however that GCS that make use
of a Geoid vertical datum and that have datums considered vertically
coincident to WGS84 then geoid separation value will be applied prior
to XYZ computations. Example:All based on grid files to WGS84 but
that do not have an ellipsoid of same shape will result in an error.
EPSG:3857 and EPSG:900913 will not work because the ellipsoid used in
the calculation is spherical even though the transformation to WGS84
is vertically neutral. BritishNatGrid with vertical datum set to
vdcLocalEllipsoid WILL WORK. Because coordinates already expressed
relative to the OSGB datum based on the Airy30 ellipsoid.

:param outXYZ:
    (output) The calculated XYZ (ECEF) coordinates.

:param inLatLong:
    (input) The latitude, longitude and elevation to convert.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_LatLongFromXYZ =R"doc(Calculates the longitude and latitude from ECEF coordinate according
to GCS current datum. This does not compute necessarily the ECEF
relative to WGS84. This method will not work for all GCS. In order to
be able to compute the ECEF coordinates relative to the GCS Datum and
ellipsoid the elevation must be expressed using a vertical datum that
can be converted to the Local Ellipsoid vertical datum. For example
for all GCS based on the NAD27 datum, the XYZ coordinate cannot be
computed due to the inability to convert to the Clarke66 ellipsoid
local elevation. Datum conversions to WGS84 rely on grid files which
are neutral vertical wise and the Clarke66 Ellipsoid does not have a
shape similar to the WGS84 ellipsoid. For the other GCS that are not
vertically coincident with WGS84 the elevation must already be based
on the local ellipsoid (vdcLocalEllipsoid). The present method will
not perform vertical change resulting from vertical datum upon the
WGS84 ellipsoid (vdcEllipsoid or vdcFromDatum) that may also require
application of geoid separation. Note however that GCS that make use
of a Geoid vertical datum and that have datums considered vertically
coincident to WGS84 then geoid separation value will be applied prior
to XYZ computations. Example:All based on grid files to WGS84 but
that do not have an ellipsoid of same shape will result in an error.
EPSG:3857 and EPSG:900913 will not work because the ellipsoid used in
the calculation is spherical even though the transformation to WGS84
is vertically neutral. BritishNatGrid with vertical datum set to
vdcLocalEllipsoid WILL WORK. Because coordinates already expressed
relative to the OSGB datum based on the Airy30 ellipsoid.

:param outLatLong:
    (output) The calculated longitude,latitude,elevation.

:param inXYZ:
    (input) The XYZ (ECEF) coordinates of this GCS. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_DegreesFromRadians =R"doc(Converts from Radians to Degrees

:param inRadians:
    (input) Angular value in radians.

:returns:
    Angular value in degrees )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_RadiansFromDegrees =R"doc(Converts from Degrees to Radians

:param inDegrees:
    (input) Angular value in degrees.

:returns:
    Angular value in radians   )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_LatLongFromLatLong2D =R"doc(Calculates the longitude and latitude in the target GCS, applying the
appropriate datum shift.

:param outLatLong:
    (output) The calculated longitude,latitude in the datum of targetGCS.

:param inLatLong:
    (input) The longitude,latitude in the datum of this GCS.

:param targetGCS:
    (input) The Coordinate System corresponding to outLatLong.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_LatLongFromLatLong =R"doc(Calculates the longitude and latitude in the target GCS, applying the
appropriate datum shift.

:param outLatLong:
    (output) The calculated longitude,latitude,elevation in the datum of
    targetGCS.

:param inLatLong:
    (input) The longitude,latitude,elevation in the datum of this GCS.

:param targetGCS:
    (input) The Coordinate System corresponding to outLatLong.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetReprojectElevation =R"doc(Sets whether reprojections from this coordinate system sadjust
elevations.

:returns:
    The previous ReprojectElevation setting.

Remark:
    s The ReprojectElevation setting affects coordinate reprojections
    performed by the #LatLongFromLatLong method. If ReprojectElevation
    is false, the elevation value is unchanged.

Remark:
    s The default value is false.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetReprojectElevation =R"doc(Gets whether reprojections from this coordinate system adjust
elevations.

:returns:
    The ReprojectElevation setting.

Remark:
    s The ReprojectElevation setting affects coordinate reprojections
    performed by the #LatLongFromLatLong method. If ReprojectElevation
    is false, the elevation value is unchanged.

Remark:
    s The default value is false. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_CheckCartesianRange =R"doc(Determines whether the input GeoPoints are within the useful range of
the coordinate system.

:param points:
    (input) The points to test.

:param numPoints:
    (input) Number of points to test.

Remark:
    s The input points must be in the cartesian units of the
    coordinate system.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_CheckGeoPointRange =R"doc(Determines whether the input GeoPoints are within the useful range of
the coordinate system.

:param points:
    (input) The points to test.

:param numPoints:
    (input) Number of points to test. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_UnitsFromMeters =R"doc(Returns the scale factor needed to convert to the units of the
coordinate system from meters by multiplication.  )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_LatLongFromCartesian2D =R"doc(Calculates the longitude and latitude from cartesian x and y.
Elevation is unchanged.

:param outLatLong:
    (output) The calculated longitude and latitude in the datum of this
    GCS.

:param inCartesian:
    (input) The input cartesian coordinates. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_LatLongFromCartesian =R"doc(Calculates the longitude, latitude, and elevation from cartesian x,y,
and z.

:param outLatLong:
    (output) The calculated longitude,latitude,elevation in the datum of
    this GCS.

:param inCartesian:
    (input) The input cartesian coordinates.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_CartesianFromLatLong2D =R"doc(Calculates the cartesian x and y of the input Longitude/Latitude
point. The input elevation is ignored.

:param outCartesian:
    (output) The calculated cartesian coordinates.

:param inLatLong:
    (input) The longitude,latitude,elevation in the datum of this GCS.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_CartesianFromLatLong =R"doc(Calculates the cartesian coordinates of the input
Longitude/Latitude/Elevation point.

:param outCartesian:
    (output) The calculated cartesian coordinates.

:param inLatLong:
    (input) The longitude,latitude,elevation in the datum of this GCS.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetStoredEPSGCode =R"doc(Sets the EPSG code in the coordinate system definition.

:param value:
    (input) The new EPSG code. Can be 0 to 32768

:returns:
    SUCCESS is successful )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetStoredEPSGCode =R"doc(Returns the EPSG code as stored in the coordinate system definition.

:returns:
    The EPSG code as stored in the definition. A value of 0 indicates
    it is undefined. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetEPSGEllipsoidCode =R"doc(Finds the EPSG code for the ellipsoid used by this coordinate system.

Remark:
    s Sometimes a search through the ellipsoid library to find a
    matching EPSG ellipsoid is required. Since there are a limited
    number of ellipsoids, this is not very time consuming. The
    " noSearch " argument is included for symmetry with GetEPSGCode and
    GetEPSGDatumCode.

:returns:
    The EPSG code, or 0 if this coordinate system does not match any
    EPSG CS known to the system. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetEPSGDatumCode =R"doc(Finds the EPSG code for the datum used by this coordinate system.

Remark:
    s Sometimes a search through the datum library to find a matching
    EPSG datum is required. This can be time consuming. To prevent the
    search, pass true for the " noSearch " argument.

:returns:
    The EPSG code, or 0 if this coordinate system does not match any
    EPSG CS known to the system.  )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetEPSGCode =R"doc(Finds the EPSG code for this coordinate system.

Remark:
    s Sometimes a search through the coordinate system library to find
    a matching EPSG coordinate system is required. This can be time
    consuming. To prevent the search, pass true for the " noSearch "
    argument.

:returns:
    The EPSG code, or 0 if this coordinate system does not match any
    EPSG CS known to the system. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_HasEquivalentDatum =R"doc(Compares the Datum of this coordinate system with the argument and
returns true if they have equivalent datum (including ellipsoid).

:param compareTo:
    (input) The BaseGCS to compare to.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_OutputAsASC =R"doc(Creates a string that contains the CSMAP ASC format text definition of
the BaseGCS. This format is only useful for dictionary management
purposes.

:param GCSAsASC:
    (output) Reference to string that receives the text ASC desctiption of
    GCS )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetMathematicalDomainExtent =R"doc(Returns the extent of the mathematical domain as returned by
GetMathematicalDomain(). Although GetMathematicalDomain() usually
returns 4 points defining an axis aligned bounding box, some
projections have more complex domain shapes composed of dozens of
points. The present method computes the bounding box of this domain.
The values returned are in degrees. It is technically possible for the
mininum longitude to be greater than the maximum longitude. This
occurs if the extent of the domain overlaps the boundary between -180
degrees and +180 longitude.

:param minLongitude:
    The minimum longitude of the domain in degrees.

:param maxLongitude:
    The maximum longitude of the domain in degrees.

:param minLatitude:
    The minimum latitude of the domain in degrees.

:param maxLatitude:
    The maximum latitude of the domain in degrees.

:returns:
    BSIERROR in case of error or if computations are not implemented
    for this projection method and BSISUCCESS otherwise. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetMathematicalDomain =R"doc(Returns the mathematical domain of application for GCS. The domain
will usually be much larger than the user domain yet caller must
remember that distortion may result outside the user domain. This
method is intended to provide a strong limit to displaying geospatial
objects expressed in a BaseGCS. Outside this limit the representation
is meaningless and may lead to conversion errors and wild points. It
is assumed that any geospatial object can be fully represented within
its own interpretation BaseGCS. The usefulness of the present method
becomes evident when we must reproject a geospatial object expressed
in a BaseGCS into another BaseGCS that has a mathematical domain
smaller than the one of the geospatial object. The proper way to deal
with domains is to obtain the two mathematical domains of both
BaseGCS, intersect them together and convert the result in cartesian
coordinate of either BaseGCS. The result shape is the mathematical
limit of the geospatial object when reprojected to the other
coordinate reference system. To illustrate the process let us assume
we have a DGN using the New Zealand Grid BaseGCS for a map in New
Zealand. As a base map we want to use Bing. Raster Manager will
compute the mathematical limit of reprojecting Bing into a New Zealand
GCS resulting in clipping Bing to the New Zealand area only.

:param shape:
    A list of GeoPoint (latitude/longitude) that contains the
    definition of the shape of the mathematical domain. The shape
    contains the closing point. This shape is usually rectangular but
    for some specific projections may contain more points. The shape
    is always returned even if an error occurs In this case the shape
    will either contain the user domain definition or a shape
    containing the whole Earth (excluding the poles)

:returns:
    BSIERROR in case of error or if computations are not implemented
    for this projection method and BSISUCCESS otherwise. Note that a
    valid shape is always returned even if an error occurs.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_Compare =R"doc(Compares this coordinate system with the argument and returns true if
they have equivalent projection, parameters, datum, and ellipsoid.

:param compareTo:
    The BaseGCS to compare to.

:param datumDifferent:
    true if the datum is different.

:param csDifferent:
    true if the coordinate system projection is different.

:param verticalDatumDifferent:
    true if the vertical datum is different.

:param localTransformDifferent:
    true if the local transform is different.

:param stopFirstDifference:
    If true, the comparison stops when the first difference is
    encountered. Only one of datumDifferent, csDifferent, and
    modifiersDifferent will be set.

:returns:
    True if the coordinate systems are identical, false otherwise.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_CorrectVerticalDatumToPreserveLegacyElevation =R"doc(If a BaseGCS has been created from a WKT that does not include a
vertical datum definition the elevation will have changed since we
went from not reprojecting elevation by default to always reprojecting
elevation by default. CorrectVerticalDatumToPreserveLegacyElevation
attempts to choose a vertical datum that will preserve the same
elevation that would have been generated if reproject elevation had
been switched off i.e. we now have reproject elevation switched on and
the extent passed will be at the same elevation when reprojected as it
was when reproject elevation was switched off. datum set

:param extent:
    the extent in this CS

:param targetGCS:
    the target CS we are reprojecting to

:returns:
    ERROR if we were not able to generate a linear transform between
    this CS and the target CS, SUCCESS if a new vertical datum was
    selected or if the existing vertical datum was not changed - note
    that if the existing vertical datum was not changed then:- it was
    not possible to choose a new datum that would preserve the
    expected legacy elevation - the existing vertical datum already
    preserves the expected legacy elevation .)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_IsEqual =R"doc(Compares this coordinate system with the argument and returns true if
they are equal. This method differs from the IsEquivalent() method as
it requires that all fields including name, description, source,
projection method, unit etc be identical.

:param compareTo:
    (input) The BaseGCS to compare to. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_IsEquivalent =R"doc(Compares this coordinate system with the argument and returns true if
they have equivalent projection, parameters, datum, ellipsoid, and
modifiers.

:param compareTo:
    (input) The BaseGCS to compare to. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetCenterPoint =R"doc(Gets the latitude and longitude of a " center " point in the coordinate
system. This might be the origin of longitude/origin of latitude, or
perhaps the central meridian and latitude of latitude, depending on
the projection in use.

:param centerPoint:
    (output) The center point.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetDistanceInMeters =R"doc(Computes distance (in meters) and starting azimuthal angle (in
degrees) from one geographic point to another. This distance is the
geodetic distance following the surface of the ellipsoid of the
BaseGCS. It does not take into account the elevation of points
provided or the fact the GCS can indicate another vertical datum
setting.

:param distance:
    (output) The distance, in meters from startPoint to endPoint.

:param azimuth:
    (output) The initial azimuth, in degrees clockwise from true north,
    needed to get from startPoint to endPoint.

:param startPoint:
    (input) The starting point.

:param endPoint:
    (input) The end point.

Remark:
    s If either distance or azimuth is not needed, pass NULL.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetDistance =R"doc(Computes distance (in the units of this GCS) and starting azimuthal
angle (in degrees) from one geographic point to another. This distance
is the geodetic distance following the surface of the ellipsoid of the
BaseGCS. It does not take into account the elevation of points
provided or the fact the GCS can indicate another vertical datum
setting.

:param distance:
    (output) The distance, in units of this GCS, from startPoint to
    endPoint.

:param azimuth:
    (output) The initial azimuth, in degrees clockwise from true north,
    needed to get from startPoint to endPoint.

:param startPoint:
    (input) The starting point.

:param endPoint:
    (input) The end point.

Remark:
    s If either distance or azimuth is not needed, pass NULL.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetConvergenceAngle =R"doc(Gets the convergence angle, in degrees, of the coordinate system at
the specified longitude/latitude.

:param point:
    (input) The point at which the convergence angle is to be computed.

See also:
    #GetScaleAlongMeridian, #GetScaleAlongParallel.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetGridScale =R"doc(Gets the grid scale of the coordinate system at the specified
longitude/latitude.

:param point:
    (input) The point at which the grid scale is to be computed.

:returns:
    The grid scale at the position specified.

Remark:
    s Non-conformal projections have two different grid scale factors:
    the scale along a meridian and the scale along a parallel. In the
    case of azimuthal projections, the two scale factors are along a
    radial line from the origin and normal to such radial lines,
    respectively. In these cases, GetGridScale will return the more
    interesting of the two. For example, in the American Polyconic,
    the grid scale factor along all parallels is always 1.0; therefore
    GetGridScale returns the grid scale factor along a meridian for
    this projection.

See also:
    #GetScaleAlongMeridian, #GetScaleAlongParallel.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetScaleAlongParallel =R"doc(Gets the grid scale along a parallel of the coordinate system at the
specified longitude/latitude.

:param point:
    (input) The point at which the grid scale is to be computed.

:returns:
    The grid scale along the parallel at the position specified.

Remark:
    s This is sometimes called the 'k' scale in geo coordinate system
    literature.

Remark:
    s The scale along a parallel is equal to the scale along a
    meridian for conformal projections.

See also:
    #GetScaleAlongMeridian, #GetGridScale.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetScaleAlongMeridian =R"doc(Gets the grid scale along a meridian of the coordinate system at the
specified longitude/latitude.

:param point:
    (input) The point at which the grid scale is to be computed.

:returns:
    The grid scale along the meridian at the position specified.

Remark:
    s This is sometimes called the 'h' scale in geo coordinate system
    literature.

Remark:
    s The scale along a meridian is equal to the scale along a
    parallel for conformal projections.

See also:
    #GetScaleAlongParallel, #GetGridScale.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetEllipsoidNames =R"doc(Gets the available Ellipsoid Names.

:returns:
    vector of strings of datum names. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetDatumNames =R"doc(Gets the available Datum Names.

:returns:
    vector of strings of datum names. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetUnitNames =R"doc(Gets all available Units, linear and degree-based.

:returns:
    vector of strings of unit names.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetLinearUnitNames =R"doc(Gets the available Linear Units.

:returns:
    vector of strings of unit names.  )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_DefinitionComplete =R"doc(Signals that the caller has finished setting the coordinate system
parameters, and that the coordinate system internal definition should
be initialized with the current parameter set.

:returns:
    SUCCESS or a CS_MAP error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetAffineParameters =R"doc(Sets the affine parameters for the affine post-processing portion of
Transverse Mercator with post affine or Lambert Conformal Conic with
post affine projections. The transformation must be valid. In order to
be valid, the determinant of the matrix formed by parameters A1 A2 and
B1 B2 must be different than 0.0. To express no rotation, scale nor
shearing, set A1 and B2 equal to 1.0 and A2 and B1 equal to 0.0.

:param A0:
    (input) The X translation of the affine transformation

:param A1:
    (input) The A1 parameter of the rotation/scale/shearing portion of the
    affine.

:param A2:
    (input) The A2 parameter of the rotation/scale/shearing portion of the
    affine.

:param B0:
    (input) The Y translation of the affine transformation

:param B1:
    (input) The B1 parameter of the rotation/scale/shearing portion of the
    affine.

:param B2:
    (input) The B2 parameter of the rotation/scale/shearing portion of the
    affine.

:returns:
    SUCCESS or error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetAffineParameters =R"doc(Gets the affine parameters for the affine post-processing portion of
Transverse Mercator with post affine or Lambert Conformal Conic with
post affine projections.

:param A0:
    (output) The X translation of the affine transformation

:param A1:
    (output) The A1 parameter of the rotation/scale/shearing portion of the
    affine.

:param A2:
    (output) The A2 parameter of the rotation/scale/shearing portion of the
    affine.

:param B0:
    (output) The Y translation of the affine transformation

:param B1:
    (output) The B1 parameter of the rotation/scale/shearing portion of the
    affine.

:param B2:
    (output) The B2 parameter of the rotation/scale/shearing portion of the
    affine.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetAffineB2 =R"doc(Sets the B2 Affine post-processing parameter for Projections that have
one.

:returns:
    SUCCESS or error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetAffineB2 =R"doc(Gets the B2 Affine post-processing parameter for Projections that have
one.

:returns:
    The B2 Affine post-processing parameter for Projections that have
    one.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetAffineB1 =R"doc(Sets the B1 Affine post-processing parameter for Projections that have
one.

:returns:
    SUCCESS or error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetAffineB1 =R"doc(Gets the B1 Affine post-processing parameter for Projections that have
one.

:returns:
    The B1 Affine post-processing parameter for Projections that have
    one.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetAffineB0 =R"doc(Sets the B0 Affine post-processing parameter for Projections that have
one.

:returns:
    SUCCESS or error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetAffineB0 =R"doc(Gets the B0 Affine post-processing parameter for Projections that have
one.

:returns:
    The B0 Affine post-processing parameter for Projections that have
    one.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetAffineA2 =R"doc(Sets the A2 Affine post-processing parameter for Projections that have
one.

:returns:
    SUCCESS or error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetAffineA2 =R"doc(Gets the A2 Affine post-processing parameter for Projections that have
one.

:returns:
    The A2 Affine post-processing parameter for Projections that have
    one.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetAffineA1 =R"doc(Sets the A1 Affine post-processing parameter for Projections that have
one.

:returns:
    SUCCESS or error code .)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetAffineA1 =R"doc(Gets the A1 Affine post-processing parameter for Projections that have
one.

:returns:
    The A1 Affine post-processing parameter for Projections that have
    one.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetAffineA0 =R"doc(Sets the A0 Affine post-processing parameter for Projections that have
one.

:returns:
    SUCCESS or error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetAffineA0 =R"doc(Gets the A0 Affine post-processing parameter for Projections that have
one.

:returns:
    The A0 Affine post-processing parameter for Projections that have
    one.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetDanishSys34Region =R"doc(Sets the Danish System 34 Region for Danish Sys 34 Projections.

:returns:
    The Region.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetDanishSys34Region =R"doc(Gets the Danish System 34 Region for Danish Sys 34 Projections.

:returns:
    The Region.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetQuadrant =R"doc(Sets the Quadrant for Projections that use that parameter.

:returns:
    The Quadrant for Projections that use that parameter.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetQuadrant =R"doc(Gets the Quadrant for Projections that use that parameter.

:returns:
    The Quadrant for Projections that use that parameter.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetHemisphere =R"doc(Sets the Hemisphere (1 for north or -1 for south) for the Univeral
Transverse Mercator projection.

:returns:
    SUCCESS or error code .)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetHemisphere =R"doc(Gets the Hemisphere (1 for north or -1 for south) for the Univeral
Transverse Mercator projection.

:returns:
    The UTM Zone number for Projections that use that parameter.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetUTMZone =R"doc(Sets the UTM Zone number (1-60) for the Universal Transverse Mercator
projections.

:returns:
    SUCCESS or error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetUTMZone =R"doc(Gets the UTM Zone number (1-60) for the Univeral Transverse Mercator
projection.

:returns:
    The UTM Zone number for Projections that use that parameter.-)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetEllipsoidScaleFactor =R"doc(Sets the ellisoid scale factor for a Lambert Conformal Conic Michigan
variation. The value given must be reasonnably close to 1.0.

:returns:
    SUCCESS or error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetEllipsoidScaleFactor =R"doc(Gets the ellipsoid scale factor, used by Lambert Conformal Conic
Michigan variation.

:returns:
    The ellipsoid scale factor.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetElevationAboveGeoid =R"doc(Sets the elevation above the geoid, in CS units, for Projections that
have one.

:returns:
    SUCCESS or error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetElevationAboveGeoid =R"doc(Gets the elevation above the geoid, in CS units, for Projections that
use that parameter.

:returns:
    The elevation above the geoid, in CS Units for Projections that
    use that parameter.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetGeoidSeparation =R"doc(Sets the geoid separation, in CS units, for Projections that have one.

:returns:
    SUCCESS or error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetGeoidSeparation =R"doc(Gets the geoid separation, in CS units, for Projections that use that
parameter.

:returns:
    The geoid separation, in CS Units for Projections that use that
    parameter.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetPoint2Latitude =R"doc(Sets the latitude of the second point of the central geodesic (in
degrees) for Projections that have one.

:returns:
    SUCCESS or error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetPoint2Latitude =R"doc(Gets the latitude of the second point of the central geodesic (in
degrees) for Projections that have one.

:returns:
    The latitude of the second point of the central geodesic for
    Projections that have one.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetPoint2Longitude =R"doc(Sets the longitude of the second point of the central geodesic (in
degrees) for Projections that have one.

:returns:
    SUCCESS or error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetPoint2Longitude =R"doc(Gets the longitude of the second point of the central geodesic (in
degrees) for Projections that have one.

:returns:
    The longitude of the second point of the central geodesic for
    Projections that have one.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetPoint1Latitude =R"doc(Sets the latitude of the first point of the central geodesic (in
degrees) for Projections that have one.

:returns:
    SUCCESS or error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetPoint1Latitude =R"doc(Gets the latitude of the first point of the central geodesic (in
degrees) for Projections that have one.

:returns:
    The latitude of the first point of the central geodesic for
    Projections that have one.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetPoint1Longitude =R"doc(Sets the longitude of the first point of the central geodesic (in
degrees) for Projections that have one.

:returns:
    SUCCESS or error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetPoint1Longitude =R"doc(Gets the longitude of the first point of the central geodesic (in
degrees) for Projections that have one.

:returns:
    The longitude of the first point of the central geodesic for
    Projections that have one. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetCentralPointLatitude =R"doc(Sets the central point latitude (in degrees) for Projections that have
one.

:returns:
    SUCCESS or error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetCentralPointLatitude =R"doc(Gets the central point latitude (in degrees) for Projections that have
one.

:returns:
    The central point latitude for Projections that have one.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetCentralPointLongitude =R"doc(Sets the central point longitude (in degrees) for Projections that
have one.

:returns:
    SUCCESS or error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetCentralPointLongitude =R"doc(Gets the central point longitude (in degrees) for Projections that
have one.

:returns:
    The central point longitude for Projections that have one.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetEasternMeridian =R"doc(Sets the central meridian (in degrees) for Projections that have one.

:returns:
    SUCCESS or error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetEasternMeridian =R"doc(Gets the eastern meridian (in degrees) for Projections that have one.

:returns:
    The eastern meridian longitude for Projections that have one.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetCentralMeridian =R"doc(Sets the central meridian (in degrees) for Projections that have one.

:returns:
    SUCCESS or error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetCentralMeridian =R"doc(Gets the central meridian (in degrees) for Projections that have one.

:returns:
    The central meridian longitude for Projections that have one.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetAzimuth =R"doc(Sets the azimuth angle for Projections that have one.

:returns:
    SUCCESS or error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetAzimuth =R"doc(Gets the azimuth angle for Projections that have one.

:returns:
    The azimuth angle for Projections that have one.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetStandardParallel2 =R"doc(Sets the second standard parallel for Projections that have one.

:returns:
    SUCCESS or error code. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetStandardParallel2 =R"doc(Gets the first standard parallel for Projections that have one.

:returns:
    The first standard parallel for Projections that have one.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetStandardParallel1 =R"doc(Sets the first standard parallel for Projections that have one.

:returns:
    SUCCESS or error code .)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetStandardParallel1 =R"doc(Gets the first standard parallel for Projections that have one.

:returns:
    The first standard parallel for Projections that have one.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetMaximumUsefulLatitude =R"doc(Gets the maximum useful latitude for the Geographic coordinate system.

:returns:
    The maximum useful latitude for Geographic (Longitude/Latitude)
    coordinate systems.

Remark:
    If the value of MaximumLatitude is not specified in the coordinate
    system library, a maximum latitude is calculated.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetMinimumUsefulLatitude =R"doc(Gets the minimum useful latitude for the Geographic Coordinate System.

:returns:
    The minimum useful latitude for Geographic (Longitude/Latitude)
    coordinate systems.

Remark:
    If the value of MinimumLatitude is not specified in the coordinate
    system library, a minimum latitude is calculated.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetMaximumUsefulLongitude =R"doc(Gets the maximum useful longitude for the Geographic Coordinate
System.

:returns:
    The maximum useful longitude for Geographic (Longitude/Latitude)
    coordinate systems.

Remark:
    If the value of MaximumLongitude is not specified in the
    coordinate system library, a maximum longitude is calculated.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetMinimumUsefulLongitude =R"doc(Gets the minimum useful longitude for the Geographic Coordinate
System.

:returns:
    The minimum useful longitude for Geographic (Longitude/Latitude)
    coordinate systems.

Remark:
    If the value of MinimumLongitude is not specified in the
    coordinate system library, a minimum longitude is calculated.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetMaximumLatitude =R"doc(Sets the maximum latitude for the Geographic Coordinate System.

:returns:
    SUCCESS or error code )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetMaximumLatitude =R"doc(Gets the maximum latitude for the Geographic Coordinate System.

:returns:
    The maximum latitude for Geographic (Longitude/Latitude)
    coordinate systems.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetMinimumLatitude =R"doc(Sets the minimum latitude for the Geographic Coordinate System.

:returns:
    SUCCESS or error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetMinimumLatitude =R"doc(Gets the minimum latitude for the Geographic Coordinate System.

:returns:
    The minimum latitude for Geographic (Longitude/Latitude)
    coordinate systems. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetMaximumLongitude =R"doc(Sets the maximum longitude for the Geographic Coordinate System.

:returns:
    SUCCESS or error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetMaximumLongitude =R"doc(Gets the maximum longitude for the Geographic Coordinate System.

:returns:
    The maximum longitude for Geographic (Longitude/Latitude)
    coordinate systems.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetMinimumLongitude =R"doc(Sets the minimum longitude for the Geographic Coordinate System.

:returns:
    SUCCESS or error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetMinimumLongitude =R"doc(Gets the minimum longitude for the Geographic Coordinate System.

:returns:
    The minimum longitude for Geographic (Longitude/Latitude)
    coordinate systems.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetEllipsoidEccentricity =R"doc(Gets the eccentricity value for the Ellipsoid.

:returns:
    The eccentricity value for the Ellipsoid.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetEllipsoidEquatorialRadius =R"doc(Gets the equatorial radius of the Ellipsoid.

:returns:
    The equatorial radius of the Ellipsoid.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetEllipsoidPolarRadius =R"doc(Gets the polar radius of the Coordinate System.

:returns:
    The polar radius of the Ellipsoid.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetScaleReduction =R"doc(Sets the Scale Reduction of the Coordinate System.

:returns:
    SUCCESS or an error code. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetScaleReduction =R"doc(Gets the scale reduction of the Coordinate System.

:returns:
    The scale reduction for the Coordinate System.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetFalseNorthing =R"doc(Sets the false northing of the Coordinate System.

:returns:
    SUCCESS or an error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetFalseNorthing =R"doc(Gets the false northing of the Coordinate System.

:returns:
    The value added to all y cartesian coordinates.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetFalseEasting =R"doc(Sets the false easting of the Coordinate System.

:returns:
    SUCCESS or an error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetFalseEasting =R"doc(Gets the false easting of the Coordinate System.

:returns:
    The value added to all x cartesian coordinates.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetOriginLatitude =R"doc(Sets the origin latitude of the Coordinate System.

:returns:
    SUCCESS or an error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetOriginLatitude =R"doc(Gets the origin latitude of the Coordinate System.

:returns:
    The origin latitude of the Coordinate System.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetEllipsoidSource =R"doc(Gets the Coordinate System Ellipsoid source citation.

:returns:
    Source citation of the Coordinate System Ellipsoid.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetEllipsoidDescription =R"doc(Gets the description of the Coordinate System Ellipsoid.

:returns:
    The description of the Coordinate System Ellipsoid. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetEllipsoidCode =R"doc(Sets the internal index of the Coordinate System Ellipsoid. Must be an
index into the array returned by the GetEllipsoidNames static method.

Remark:
    s The Ellipsoid can only be set if the Datum Code is
    Ellipsoid::NO_ELLIPSOID_CODE(-1). Otherwise, the Datum determines
    the Ellipsoid.

:returns:
    SUCCESS or an error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetEllipsoidCode =R"doc(Gets the internal index of the Coordinate System Ellipsoid.

:returns:
    Index of the Coordinate System Ellipsoid. Ellipsoid::
    NO_ELLIPSOID_CODE (-1) is returned if there are no ellipsoid set.
    If a custom ellipsoid is set the Ellipsoid::CUSTOM_ELLIPSOID_CODE.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetEllipsoidName =R"doc(Gets the name of the Coordinate System Ellipsoid.

:returns:
    Name of the Coordinate System Ellipsoid.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetVerticalDatumByKey =R"doc(Sets the Vertical Datum by vertical datum key See
SetVerticalDatumCode() for details.

:returns:
    SUCCESS or an error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetVerticalDatumCode =R"doc(Sets the Vertical Datum Code. In only a few instances, the Vertical
Datum can be set separately from the Datum. Currently, when the Datum
of this GCS is either NAD83 or NAD27, the Vertical Datum can be set to
either NAVD88 or NGVD29 independently of the Datum.

:returns:
    SUCCESS or an error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetNetVerticalDatumCode =R"doc(Gets the Vertical Datum Code. In only a few instances, the Vertical
Datum can be set separately from the Datum. Currently, when the Datum
of this GCS is either NAD83 or NAD27, the Vertical Datum can be set to
either NAVD88 or NGVD29 independently of the Datum. This method
contrary to GetVerticalDatumCode() never returns vdcFromDatum but
returns the explicit datum code for ellipsoid, NGVD29 or NAVD88.

:returns:
    Member of the VerticalDatum enum indicating Vertical Datum.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetVerticalDatumCode =R"doc(Gets the Vertical Datum Code. In only a few instances, the Vertical
Datum can be set separately from the Datum. Currently, when the Datum
of this GCS is either NAD83 or NAD27, the Vertical Datum can be set to
either NAVD88 or NGVD29 independently of the Datum.

:returns:
    Member of the VerticalDatum enum indicating Vertical Datum.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetVerticalDatumName =R"doc(Gets the name of the Coordinate System Vertical Datum. It will be
either NAVD88, NGVD29, Ellipsoid or Geoid. The pointer returned is a
pointer to a constant string defined in the library. NOTE:This method
used to be published but hopefully it is not used anywhere since it
was binding by the implementation to returning either constants or
string internal to the BaseGCS which is bad practice. We will be
phasing off the support of this methid that will be replaced
eventually.

:returns:
    Name of the Coordinate System Vertical Datum. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_DatumExtendedParametersValid =R"doc(Returns whether the delta, rotation, and scale parameters are valid
for the Datum of this GCS.

:param deltaValid:
    (output) Returns true if the datum is valid and its WGS84ConvertCode
    indicates that the delta parameters are used.

:param rotationValid:
    (output) Returns true if the datum is valid and its WGS84ConvertCode
    indicates that the rotation parameters are used.

:param scaleValid:
    (output) Returns true if the datum is valid and its WGS84ConvertCode
    indicates that the scale parameter is used.

:param gridValid:
    (output) Returns true if the datum is valid and its WGS84ConvertCode
    indicates that grid file is used.

:returns:
    true if any of the output valid flags are true.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_DatumParametersValid =R"doc(Returns whether the delta, rotation, and scale parameters are valid
for the Datum of this GCS.

:param deltaValid:
    (output) Returns true if the datum is valid and its WGS84ConvertCode
    indicates that the delta parameters are used.

:param rotationValid:
    (output) Returns true if the datum is valid and its WGS84ConvertCode
    indicates that the rotation parameters are used.

:param scaleValid:
    (output) Returns true if the datum is valid and its WGS84ConvertCode
    indicates that the scale parameter is used.

:returns:
    true if any of the output valid flags are true.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetDatumGridFile =R"doc(Utilitarian method. The present method will return the grid file
definition if the datum is currently based on a stored geodetic
transform path containing a single transform that must use the Grid
File method to WGS84 and contain a single grid file definition. If any
of those conditions are not met ERROR is returned, otherwise the grid
file definition is returned with a SUCCESS status.

:param gridFileDef:
    (output) Reference to the grid file that will receive the current datum
    grid file definition.

:returns:
    SUCCESS is successful or ERROR if any prerequisite condition
    indicated above is not met. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetDatumScale =R"doc(Gets the datum transformation scaling in parts per million of the
Datum of this GCS, if known.

:returns:
    The datum transformation scale in ppm.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetDatumRotation =R"doc(Gets the angles from the WGS84 x, y, and z axes to those of the Datum
of this GCS

:param rotation:
    (output) The rotation angles. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetDatumDelta =R"doc(Gets the vector from the geocenter of the WGS84 Datum to the geocenter
of the Datum of this GCS.

:param delta:
    (output) The vector from the geocenter of the WGS84 Datum to the
    geocenter of this Datum.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetDatumConvertMethod =R"doc(Gets the method used to convert longitude/latitude from the Datum of
this GCS to the WGS84 datum.

:returns:
    The convert method. @note:If this GCS does not have a Datum,
    ConvertType_NONE is returned.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetDatumSource =R"doc(Gets the Coordinate System Datum source citation.

:returns:
    Source citation of the Coordinate System Datum.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetDatumDescription =R"doc(Gets the description of the Coordinate System Datum.

:returns:
    Description of the Coordinate System Datum.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_HasCustomDatum =R"doc(Indicates if the GCS uses a custom datum

:returns:
    true if the GCS uses a custom datum. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetDatum =R"doc(Sets the datum. If the datum indicates it is stored in a user library
then the GCS will automatically be changed to this user library. If
the datum is self contained and unstored then the stored datum code
will be set to -2. The datum is captured and must not be destroyed by
the caller.

:returns:
    SUCCESS if successful )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetDatum =R"doc(Returns the pointer to the internal datum. The datum must not be
deallocated. The datum returned will be the internal datum set using
SetDatum() or the datum obtained from the library. If the BaseGCS has
no datum and is ellipsoid based then NULL is returned

:returns:
    Pointer to internal datum or NULL if no datum. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetDatumCode =R"doc(Sets the internal index of the Datum for the Coordinate System Datum.
Must be an index into the array returned by the GetDatumNames() static
method for system datums. It can also be the index of the datum in a
user-defined library majored by Datum::USER_DATUM_CODE_OFFSET
(1000000). It can also be set to Datum::NO_DATUM_CODE (-1) to indicate
that the GCS does not use a datum and is ellipsoid based after which
the SetEllipsoidCode() method must be used to indicate the proper
ellipsoid.

:returns:
    SUCCESS or an error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetDatumCode =R"doc(Gets the internal index of the Coordinate System Datum. This index
will be from 0 to the number of datums in the system library for
system defined datum. The code will be over 1000000 for user-defined
datum stored in a user-library. If the GCS does not use a datum but is
directly based on the ellipsoid then the code will be
Datum::NO_DATUM_CODE (-1). For a fully self-contained datum as set
using SetDatum() then the code will be Datum::CUSTOM_DATUM_CODE(-2) in
which case the GCS cannot be stored in any library.

:returns:
    Index of the Coordinate System Datum.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetDatumName =R"doc(Gets the name of the Coordinate System Datum.

:returns:
    Name of the Coordinate System Datum. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetUnitByKeyname =R"doc(Sets the Units to those indicated by the unit keyname. The unit key
name must be an exact match to one of the csmap dictionary names (case
insensitive). Typically the units in use are 'METER', 'IFOOT' for
internatial foot and 'FOOT' for US Survey foot. The only possible unit
for a latitude/longitude GCS is 'DEGREE'.

:returns:
    SUCCESS or an error code. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetEPSGUnitCode =R"doc(Finds the EPSG code for the unit used by this coordinate system.

:returns:
    The EPSG code, or 0 if the unit cannot be found in the CS Map
    table or the there is no EPSG code corresponding to the unit used.
    Mathieu St-Pierre )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetUnitCode =R"doc(Sets the Units to those indicated by the unit code. The unit code must
come from either GetUnitCode or an index into the array returned by
GetUnitNames.

:returns:
    SUCCESS or an error code. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetUnitCode =R"doc(Gets the internal index for the Coordinate System units.

:returns:
    index into internal table of unit names.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetUnits =R"doc(Gets the name of the Coordinate System units.

:returns:
    Name of source of the Coordinate System units.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetSource =R"doc(Sets the source of the Coordinate System

:returns:
    SUCCESS or an error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetSource =R"doc(Gets the source of the Coordinate System.

:returns:
    The source of the Coordinate System.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetLocation =R"doc(Gets the location for which the Coordinate System applies.

:returns:
    The location for which the Coordinate System applies.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetGroup =R"doc(Sets the group of the Coordinate System. The group specified must be
the identifier of a known group. In all cases the group name may not
be more than 23 characters long.

:returns:
    SUCCESS or an error code. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetGroup =R"doc(Gets the CSMap group to which the Coordinate System belongs.

:returns:
    The CSMap group to which the Coordinate System belongs.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetProjectionCode =R"doc(Sets CS_Map projection code of the Coordinate System.

:returns:
    SUCCESS or an error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetProjectionCode =R"doc(Gets CS_Map projection code of the Coordinate System.

:returns:
    The CS_Map projection code of the Coordinate System.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetProjection =R"doc(Gets the name of the projection used by the Coordinate System.

:returns:
    The name of the projection used by the Coordinate System.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetDescription =R"doc(Sets the description of the Coordinate System

:returns:
    SUCCESS or an error code. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetDescription =R"doc(Gets the description of the Coordinate System.

:returns:
    The description of the Coordinate System. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_SetName =R"doc(Sets the name of the Coordinate System

:returns:
    SUCCESS or an error code.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetName =R"doc(Gets the name of the Coordinate System

:returns:
    The name of the Coordinate System. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_IsStandard =R"doc(Returns whether the Coordinate System is a standard coordinate system
or not.

:returns:
    True if the Coordinate System originated from the coordinate
    system library, False otherwise. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_Validate =R"doc(Tests the coordinate system definition for validity.

:returns:
    True if the Coordinate System parameters are valid, false if not.

:param errorList:
    (output) A list of validation errors generated by CSMap.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetError =R"doc(Gets the error code associated with constructor failure if IsValid is
false.

:returns:
    The CSMap error code.

See also:
    #GetErrorMessage )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_IsValid =R"doc(Returns whether the Coordinate System is valid or not.

:returns:
    True if the Coordinate System is valid, False otherwise.

See also:
    #GetError

Remark:
    s If the coordinate system is constructed using the coordinate
    system keyname constructor, and the specified name does not
    correspond to a coordinate system in the coordinate system
    library, IsValid is false, and GetError and GetErrorMessage can be
    used to obtain more details. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_CanSaveToGeoTiffKeys =R"doc(Reveals whether the coordinate system can be saved to GeoTiffKeys.

:returns:
    true if the coordinate system can be saved to GeoTiffKeys, false
    if not. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_ECEFFromCartesian =R"doc(Private - We do not wish to publicise this method yet.
ECEFFromCartesian - Converts from source cartesian to the ECEF. 3D
conversion is applied.

:returns:
    REPROJECT_Success if the process was fully successful.
    REPROJECT_CSMAPERR_OutOfUsefulRange if at least one conversion
    used for computing was out of the normal useful domain of either
    coordinate system. This can be interpreted as a warning when the
    extent is known to extend past the domain of the GCS. This will
    occur invariably in GCS such as Danmark 34 system that use a non-
    square domain (polygon domain).
    REPROJECT_CSMAPERR_VerticalDatumConversionError - Indicates
    elevation shift could not be applied due to some configuration
    file missing. This will not normally affect the result of the
    present method but should be reported to the user to fix the
    configuration issue. Any other error is a hard error depending on
    the value.

:param outECEF:
    (output) Receives the output coordinate.

:param inCartesian:
    (input) The input coordinate.

Sarah Keenan.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_CartesianFromECEF =R"doc(Private - We do not wish to publicise this method yet.
CartesianFromECEF - Converts from ECEF to the cartesian of the target.
3D conversion is applied.

:returns:
    REPROJECT_Success if the process was fully successful.
    REPROJECT_CSMAPERR_OutOfUsefulRange if at least one conversion
    used for computing was out of the normal useful domain of either
    coordinate system. This can be interpreted as a warning when the
    extent is known to extend past the domain of the GCS. This will
    occur invariably in GCS such as Danmark 34 system that use a non-
    square domain (polygon domain).
    REPROJECT_CSMAPERR_VerticalDatumConversionError - Indicates
    elevation shift could not be applied due to some configuration
    file missing. This will not normally affect the result of the
    present method but should be reported to the user to fix the
    configuration issue. Any other error is a hard error depending on
    the value.

:param outCartesian:
    (output) Receives the output coordinate.

:param inECEF:
    (input) The input coordinate.

:param targetGCS:
    (input) Target coordinate system

Sarah Keenan.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_CartesianFromCartesian =R"doc(CartesianFromCartesian - Converts from the cartesian representation of
a GCS to the cartesian of the target. 3D conversion is applied.

:returns:
    REPROJECT_Success if the process was fully successful.
    REPROJECT_CSMAPERR_OutOfUsefulRange if at least one conversion
    used for computing was out of the normal useful domain of either
    coordinate system. This can be interpreted as a warning when the
    extent is known to extend past the domain of the GCS. This will
    occur invariably in GCS such as Danmark 34 system that use a non-
    square domain (polygon domain).
    REPROJECT_CSMAPERR_VerticalDatumConversionError - Indicates
    elevation shift could not be applied due to some configuration
    file missing. This will not normally affect the result of the
    present method but should be reported to the user to fix the
    configuration issue. Any other error is a hard error depending on
    the value.

:param outCartesian:
    (output) Receives the output coordinate.

:param inCartesian:
    (input) The input coordinate.

:param targetGCS:
    (input) target coordinate system

 .)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetLinearTransformToECEF =R"doc(Computes a linear transformation over a designated area that
approximates the transformation between this source coordinate system
and ECEF.

:returns:
    REPROJECT_Success if the process was fully successful.
    REPROJECT_CSMAPERR_OutOfUsefulRange if at least one conversion
    used for computing was out of the normal useful domain of either
    coordinate system. This can be interpreted as a warning when the
    extent is known to extend past the domain of the GCS. This will
    occur invariably in GCS such as Denmark 34 system that use a non-
    square domain (polygon domain).
    REPROJECT_CSMAPERR_VerticalDatumConversionError - Indicates
    elevation shift could not be applied due to some configuration
    file missing. This will not normally affect the result of the
    present method but should be reported to the user to fix the
    configuration issue. Any other error is a hard error depending on
    the value.

:param outTransform:
    (output) the transform effective at the point elementOrigin in source
    coordinates

:param extent:
    (input) the extent in source GCS coordinate to use to find the
    transform. This extent must of course be valid (not empty) but
    shall also define an extent no less than 0.01 of the linear units
    of the input GCS wide in all dimensions. If the input GCS is
    longitude/latitude then the extent will be no less than 0.0000001
    (1e-07) degrees for the first two ordinate and 0.01[Meter] for the
    elevation (z) ordinate.

:param maxError:
    (output) If provided receives the max error observed over the extent

:param meanError:
    (output) If provided receives the mean error observed over the extent
    Sarah.Keenan )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetLinearTransformECEF =R"doc(Computes a linear transformation over a designated area that
approximates the transformation between ECEF and given target
coordinate system.

:returns:
    REPROJECT_Success if the process was fully successful.
    REPROJECT_CSMAPERR_OutOfUsefulRange if at least one conversion
    used for computing was out of the normal useful domain of either
    coordinate system. This can be interpreted as a warning when the
    extent is known to extend past the domain of the GCS. This will
    occur invariably in GCS such as Denmark 34 system that use a non-
    square domain (polygon domain).
    REPROJECT_CSMAPERR_VerticalDatumConversionError - Indicates
    elevation shift could not be applied due to some configuration
    file missing. This will not normally affect the result of the
    present method but should be reported to the user to fix the
    configuration issue. Any other error is a hard error depending on
    the value.

:param outTransform:
    (output) the transform effective at the point elementOrigin in source
    coordinates

:param extentECEF:
    (input) the extent in ECEF coordinate to use to find the transform.
    This extent must of course be valid (not empty) but shall also
    define an extent no less than 0.01[meter] wide in all three
    dimensions.

:param targetGCS:
    (input) target coordinate system

:param maxError:
    (output) If provided receives the max error observed over the extent

:param meanError:
    (output) If provided receives the mean error observed over the extent
    Sarah.Keenan)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetLinearTransform =R"doc(Computes a linear transformation over a designated area that
approximates the transformation between source and given target
coordinate system.

:returns:
    REPROJECT_Success if the process was fully successful.
    REPROJECT_CSMAPERR_OutOfUsefulRange if at least one conversion
    used for computing was out of the normal useful domain of either
    coordinate system. This can be interpreted as a warning when the
    extent is known to extend past the domain of the GCS. This will
    occur invariably in GCS such as Denmark 34 system that use a non-
    square domain (polygon domain).
    REPROJECT_CSMAPERR_VerticalDatumConversionError - Indicates
    elevation shift could not be applied due to some configuration
    file missing. This will not normally affect the result of the
    present method but should be reported to the user to fix the
    configuration issue. Any other error is a hard error depending on
    the value.

:param outTransform:
    (output) the transform effective at the point elementOrigin in source
    coordinates

:param extent:
    (input) the extent in source GCS coordinate to use to find the
    transform. This extent must of course be valid (not empty) but
    shall also define an extent no less than 0.01 of the linear units
    of the input GCS wide in all dimensions. If the input GCS is
    longitude/latitude then the extent will be no less than 0.0000001
    (1e-07) degrees for the first two ordinate and 0.01[Meter] for the
    elevation (z) ordinate.

:param targetGCS:
    (input) target coordinate system

:param maxError:
    (output) If provided receives the max error observed over the extent

:param meanError:
    (output) If provided receives the mean error observed over the extent)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_InitFromGeoTiffKeys =R"doc(Used in conjunction with the CreateGCS factory method to set the
BaseGCS from a set of GeoTiff Keys. Note that the original list of
geotiff keys will be preserved inside the BaseGCS object. This
mechanism allows to obtain the geotiff keys exactly as they were when
interpreted for the sake of conformity to a client data standard.

:returns:
    SUCCESS, a CS_MAP error code, or a GeoCoord error code.

:param warning:
    (output) if non-NULL, this might reveal a warning even if the return
    value is SUCCESS.

:param warningErrorMsg:
    (output) if non-NULL, the WString is filled in with the CS_MAP warning
    or error message.

:param geoTiffKeys:
    (input) an object implementing the IGeoTiffKeysList interface.

:param allowUnitsOverride:
    (input) if true then default units can be overriden by the presence a
    proj linear unit even though the units associated to the GCS
    specifies different units This parameter is necessary since many
    client make use of this mechanism. This parameter is optional
    regardless optional parameters are discouraged. For reasons of
    backward compatibility this was considered necessary.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetCompoundCSWellKnownText =R"doc(Gets the COMPD_CS Well Known Text string from a coordinate system
definition. This compound coordinate system is composed of a PROJCS or
GEOCS section followed by a VERT_CS section that contains the
definition of the vertical datum used.

:returns:
    SUCCESS or a CS_MAP error code.

:param wellKnownText:
    Out The Well Known Text specifying the coordinate system.

:param wktFlavor:
    (input) The WKT Flavor desired. If not known, use wktFlavorUnknown

:param originalIfPresent:
    (input) true indicates that if the BaseGCS originates from a WKT
    fragment then this WKT should be returned. In this case the
    wktFlavor is only used if an original was not present. Note that
    if the original was not a compound WKT but a plain WKT then this
    original fragment will be used internally in the composition of
    the compound WKT. This parameter is optional regardless optional
    parameters are discouraged. For reasons of backward compatibility
    this was considered necessary.

:param doNotInsertTOWGS84:
    (input) If true indicates that the TOWGS84 clause should not be added.
    default is false which indicates to add it if applicable to flavor
    and datum transformation.

:param posVectorRotationSignConvention:
    (input) If true indicates that the TOWGS84 rotation signal convention
    should follow Position Vector (EPSG:9607) convention. The default
    is false to use the Coordinate Frame (EPSG:9606) convention.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_GetWellKnownText =R"doc(Gets the Well Known Text string from a coordinate system definition.

:returns:
    SUCCESS or a CS_MAP error code.

:param wellKnownText:
    Out The Well Known Text specifying the coordinate system.

:param wktFlavor:
    (input) The WKT Flavor desired. If not known, use wktFlavorUnknown

:param originalIfPresent:
    (input) true indicates that if the BaseGCS originates from a WKT
    fragment then this WKT should be returned. In this case the
    wktFlavor is only used if an original was not present. This
    parameter is optional regardless optional parameters are
    discouraged. For reasons of backward compatibility this was
    considered necessary.

:param doNotInsertTOWGS84:
    (input) If true indicates that the TOWGS84 clause should not be added.
    default is false which indicates to add it if applicable to flavor
    and datum transformation.

:param posVectorRotationSignConvention:
    (input) If true indicates that the TOWGS84 rotation signal convention
    should follow Position Vector (EPSG:9607) convention. The default
    is false to use the Coordinate Frame (EPSG:9606) convention.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_InitFromEPSGCode =R"doc(Used in conjunction with the CreateGCS factory method to set the
BaseGCS from an EPSG coordinate system code. The valid EPSG code
ranges are from 20000 through 32767 for projected coordinate systems
and 4000 through 4199 for geographic (Lat/long) coordinate systems.

:returns:
    SUCCESS or a CS_MAP error code.

:param warning:
    (output) if non-NULL, this might reveal a warning even if the return
    value is SUCCESS.

:param warningErrorMsg:
    (output) if non-NULL, the WString is filled in with the CS_MAP warning
    or error message.

:param epsgCode:
    (input) The EPSG code for the desired coordinate system.

Remark:
    s Only those EPSG coordinate systems that are in our library will
    be successfully created. The method first looks for a coordinate
    system named EPSGnnnnn, where nnnnn is the EPSG code. If that
    fails, it looks in CS-Map's lookup table to see if the EPSG code
    appears there. If that fails, it returns an error code and the
    IsValid method of the coordinate system will return false.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_InitFromOSGEOXML =R"doc(Used in conjunction with the CreateGCS factory method to set the
BaseGCS from a " OSGEO XML " string.

:returns:
    SUCCESS or a CS_MAP error code.

:param autoXML:
    (input) The XML specifying the coordinate system. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_InitFromWellKnownText =R"doc(Used in conjunction with the CreateGCS factory method to set the
BaseGCS from a " well known text " string.

:returns:
    SUCCESS or a CS_MAP error code.

:param warning:
    (output) if non-NULL, this might reveal a warning even if the return
    value is SUCCESS.

:param warningErrorMsg:
    (output) if non-NULL, the WString is filled in with the CS_MAP warning
    or error message.

:param wktFlavor:
    (input) The WKT Flavor. If not known, use wktFlavorUnknown.

:param wellKnownText:
    (input) The Well Known Text specifying the coordinate system.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_InitLatLong =R"doc(Used in conjunction with the no-argument contructor to set the BaseGCS
to give cartesian angular values. This is often useful for applying
datum shifts when you have Longitude Latitude values in one datum and
you need then in a different datum.

:returns:
    SUCCESS or a CS_MAP error code.

:param errorMsg:
    (output) if non-NULL, the WString is filled in with the CS_MAP error
    message when an error occurs.

:param datumName:
    (input) The name of the datum used in the GCS, such as " WGS84 ".

:param ellipsoidName:
    (input) The name of the ellipsoid used in the GCS, such as " WGS84 ".
    This is used only if the datumName is NULL.

:param unitName:
    (input) The name of the linear unit for the Cartesian coordinates, such
    as " METER ".

:param originLongitude:
    (input) Allows displacement of the longitude values if a different
    origin is desired - usually 0.0.

:param originLatitude:
    (input) Allows displacement of the latitude values if a different
    origin is desired - usually 0.0. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_InitTransverseMercator =R"doc(Used in conjunction with the no-argument contructor to set the BaseGCS
to an Transverse Mercator projection.

:returns:
    SUCCESS or a CS_MAP error code.

:param errorMsg:
    (output) if non-NULL, the WString is filled in with the CS_MAP error
    message when an error occurs.

:param datumName:
    (input) The name of the datum used in the GCS, such as " WGS84 ".

:param unitName:
    (input) The name of the linear unit for the Cartesian coordinates, such
    as " METER ".

:param originLongitude:
    (input) The longitude of the tangency point.

:param originLatitude:
    (input) The latitude of the tangency point.

:param scale:
    (input) This scale reduction at the origin.

:param falseEasting:
    (input) The value to add to each Cartesian X value.

:param falseNorthing:
    (input) The value to add to each Cartesian Y value.

:param quadrant:
    (input) Quadrant for the cartesian coordinate system. If north is up
    and east is right, pass 1.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_InitAzimuthalEqualArea =R"doc(Used in conjunction with the no-argument contructor to set the BaseGCS
to an Azimuthal Equal Area projection. Such a projection is the
mathematical equivalent of placing a flat sheet of paper on the
surface of the area at originLongitude, originLatitude, projecting the
earth's surface onto that paper, and then adding the " falseEasting ",
" falseNorthing " values to yield cartesian coordinates.

:returns:
    SUCCESS or a CS_MAP error code.

:param errorMsg:
    (output) if non-NULL, the WString is filled in with the CS_MAP error
    message when an error occurs.

:param datumName:
    (input) The name of the datum used in the GCS, such as " WGS84 ".

:param unitName:
    (input) The name of the linear unit for the Cartesian coordinates, such
    as " METER ".

:param originLongitude:
    (input) The longitude of the tangency point.

:param originLatitude:
    (input) The latitude of the tangency point.

:param azimuthAngle:
    (input) The angle, clockwise from true north in decimal degrees, of the
    rotation to be applied.

:param scale:
    (input) This argument is ignored. The scale is always 1.0.

:param falseEasting:
    (input) The value to add to each Cartesian X value.

:param falseNorthing:
    (input) The value to add to each Cartesian Y value.

:param quadrant:
    (input) Quadrant for the cartesian coordinate system. If north is up
    and east is right, pass 1. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_ClearConverterCache =R"doc(This method is only intended to be called when previous conversion
call returned warnings related to datum conversion (typically grid
files missing). If after such a warning actions are taken to remedy to
the missing files then calling this method will clear the conversion
cache insuring datum converter is computed anew using newly installed
data.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_AllocateClean =R"doc(Allocates an empty baseGCS which will be in the valid but modified
state. once allocated the m_csParameters structure can be filled and
once complete DefinitionComplete() be called. This method is intended
for manual creation of a BaseGCS after CreateGCS() has been called (no
parameters). Note that vertical datum set is unchanged. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_BaseGCS_CreateGCS =R"doc(Returns an empty BaseGCSPtr. This factory method is designed to be
used in conjunction with the initialization methods such as the
InitAzimuthalEqualArea method.)doc";

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

    c0.def_static("CreateGCS", py::overload_cast<>(&BaseGCS::CreateGCS), DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, CreateGCS));
    c0.def_static("CreateGCS", py::overload_cast<WCharCP>(&BaseGCS::CreateGCS), "coordinateSystemKeyName"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, CreateGCS));
    c0.def_static("CreateGCS", py::overload_cast<BaseGCSCR>(&BaseGCS::CreateGCS), "baseGcs"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, CreateGCS));

    c0.def("AllocateClean", &BaseGCS::AllocateClean, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, AllocateClean));
    c0.def("ClearConverterCache", &BaseGCS::ClearConverterCache, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, ClearConverterCache));

    c0.def("InitAzimuthalEqualArea", [](BaseGCS& self, WCharCP datumName, WCharCP unitName, double originLongitude, double originLatitude, double azimuthAngle, double scale, double falseEasting, double falseNorthing, int quadrant)
        {
        WString errorMsg;
        StatusInt status = self.InitAzimuthalEqualArea (&errorMsg, datumName, unitName, originLongitude, originLatitude, azimuthAngle, scale, falseEasting, falseNorthing, quadrant);
        return py::make_tuple (errorMsg, status);
        }, "datumName"_a, "unitName"_a, "originLongitude"_a, "originLatitude"_a, "azimuthAngle"_a, "scale"_a, "falseEasting"_a, "falseNorthing"_a, "quadrant"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, InitAzimuthalEqualArea));

    c0.def("InitTransverseMercator", [](BaseGCS& self, WCharCP datumName, WCharCP unitName, double originLongitude, double originLatitude, double scale, double falseEasting, double falseNorthing, int quadrant)
        {
        WString errorMsg;
        StatusInt status = self.InitTransverseMercator(&errorMsg, datumName, unitName, originLongitude, originLatitude, scale, falseEasting, falseNorthing, quadrant);
        return py::make_tuple(status, errorMsg);
        }, "datumName"_a, "unitName"_a, "originLongitude"_a, "originLatitude"_a, "scale"_a, "falseEasting"_a, "falseNorthing"_a, "quadrant"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, InitTransverseMercator));

    c0.def("InitLatLong", &BaseGCS::InitLatLong, "errorMsg"_a, "datumName"_a, "ellipsoidName"_a, "unitName"_a, "originLongitude"_a, "originLatitude"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, InitLatLong));

    c0.def("InitLatLong", [](BaseGCS& self, WCharCP datumName, WCharCP ellipsoidName, WCharCP unitName, double  originLongitude, double  originLatitude)
        {
        WString errorMsg;
        StatusInt status = self.InitLatLong (&errorMsg, datumName, ellipsoidName, unitName, originLongitude, originLatitude);
        return py::make_tuple(status, errorMsg);
        }, "datumName"_a, "ellipsoidName"_a, "unitName"_a, "originLongitude"_a, "originLatitude"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, InitLatLong));

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
        }, "wktFlavor"_a, "wellKnownText"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, InitFromWellKnownText));

   c0.def("InitFromOSGEOXML", &BaseGCS::InitFromOSGEOXML, "osgeoXML"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, InitFromOSGEOXML));

   c0.def("InitFromWellKnownText", [](BaseGCS& self, WCharCP wellKnownText)
        {
        StatusInt warning;
        WString   warningErrorMsg;
        StatusInt status = self.InitFromWellKnownText (&warning, &warningErrorMsg, wellKnownText);
        return py::make_tuple(warning, warningErrorMsg, status);
        }, "wellKnownText"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, InitFromWellKnownText));

    c0.def("InitFromEPSGCode", [](BaseGCS& self, int epsgCode)
        {
        StatusInt warning;
        WString   warningErrorMsg;
        StatusInt status = self.InitFromEPSGCode(&warning, &warningErrorMsg, epsgCode);
        return py::make_tuple(warning, warningErrorMsg, status);
        }, "epsgCode"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, InitFromEPSGCode));

    c0.def("GetWellKnownText", [](BaseGCSCR self, BaseGCS::WktFlavor wktFlavor, bool originalIfPresent, bool doNotInsertTOWGS84, bool posVectorRotationSignConvention)
        {
        WString   wellKnownText;
        StatusInt status = self.GetWellKnownText(wellKnownText, wktFlavor, originalIfPresent, doNotInsertTOWGS84, posVectorRotationSignConvention);
        return py::make_tuple(wellKnownText, status);
        }, "wktFlavor"_a, "originalIfPresent"_a = false, "doNotInsertTOWGS84"_a = false, "posVectorRotationSignConvention"_a = false, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetWellKnownText));

    c0.def("GetCompoundCSWellKnownText", [](BaseGCSCR self, BaseGCS::WktFlavor wktFlavor, bool originalIfPresent, bool doNotInsertTOWGS84, bool posVectorRotationSignConvention)
        {
        WString   wellKnownText;
        StatusInt status = self.GetCompoundCSWellKnownText(wellKnownText, wktFlavor, originalIfPresent, doNotInsertTOWGS84, posVectorRotationSignConvention);
        return py::make_tuple(wellKnownText, status);
        }, "wktFlavor"_a, "originalIfPresent"_a = false, "doNotInsertTOWGS84"_a = false, "posVectorRotationSignConvention"_a = false, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetCompoundCSWellKnownText));

    //Note : geoTiffKeys is __BENTLEY_INTERNAL_ONLY__, this method is not possible to be called successfully in python before IGeoTiffKeysList published.
    //c0.def("InitFromGeoTiffKeys", [](BaseGCS& self, ::IGeoTiffKeysList* geoTiffKeys, bool allowUnitsOverride)
    //    {
    //    StatusInt warning;
    //    WString   warningErrorMsg;
    //    StatusInt status = self.InitFromGeoTiffKeys(&warning, &warningErrorMsg, geoTiffKeys, allowUnitsOverride);
    //    return py::make_tuple(warning, warningErrorMsg, status);
    //    }, "geoTiffKeys"_a, "allowUnitsOverride"_a = false, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, InitFromGeoTiffKeys));

    c0.def("GetLinearTransform", [](BaseGCSCR self, DRange3dCR extent, BaseGCSCR targetGCS)
        {
        Transform outTransform;
        double maxError, meanError;
        WString   wellKnownText;
        StatusInt status = self.GetLinearTransform(&outTransform, extent, targetGCS, &maxError, &meanError);
        return py::make_tuple(outTransform, maxError, meanError, status);
        }, "extent"_a, "targetGCS"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetLinearTransform));

    c0.def("GetLinearTransformECEF", [](BaseGCSCR self, DRange3dCR extentECEF, BaseGCSCR targetGCS)
        {
        Transform outTransform;
        double maxError, meanError;
        WString   wellKnownText;
        StatusInt status = self.GetLinearTransformECEF(&outTransform, extentECEF, targetGCS, &maxError, &meanError);
        return py::make_tuple(outTransform, maxError, meanError, status);
        }, "extentECEF"_a, "targetGCS"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetLinearTransformECEF));

    c0.def("GetLinearTransformToECEF", [](BaseGCSCR self, DRange3dCR extent)
        {
        Transform outTransform;
        double maxError, meanError;
        WString   wellKnownText;
        StatusInt status = self.GetLinearTransformToECEF (&outTransform, extent, &maxError, &meanError);
        return py::make_tuple(outTransform, maxError, meanError, status);
        }, "extent"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetLinearTransformToECEF));

    c0.def("CartesianFromCartesian", [](BaseGCSCR self, DPoint3dCR inCartesian, BaseGCSCR targetGCS)
        {
        DPoint3d outCartesian;
        ReprojectStatus status = self.CartesianFromCartesian(outCartesian, inCartesian, targetGCS);
        return py::make_tuple(outCartesian, status);
        }, "inCartesian"_a, "targetGCS"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, CartesianFromCartesian));

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
        }, "inECEF"_a, "targetGCS"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, CartesianFromECEF));

    c0.def("ECEFFromCartesian", [](BaseGCSCR self, DPoint3dCR inCartesian)
        {
        DPoint3d outECEF;
        ReprojectStatus status = self.ECEFFromCartesian(outECEF, inCartesian);
        return py::make_tuple(outECEF, status);
        }, "inCartesian"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, ECEFFromCartesian));

    //Note : geoTiffKeys is __BENTLEY_INTERNAL_ONLY__, Below methods are not possible to be called successfully in python before IGeoTiffKeysList published.
    //c0.def ("SetGeoTiffKeys", &BaseGCS::SetGeoTiffKeys, "geoTiffKeys"_a);
    //c0.def ("GetGeoTiffKeys", &BaseGCS::GetGeoTiffKeys, "geoTiffKeys"_a, "originalsIfPresent"_a);

    c0.def("CanSaveToGeoTiffKeys", &BaseGCS::CanSaveToGeoTiffKeys, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, CanSaveToGeoTiffKeys));
    c0.def("IsValid", &BaseGCS::IsValid, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, IsValid));
    c0.def("GetError", &BaseGCS::GetError, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetError));

    c0.def("GetErrorMessage", [](BaseGCSCR self, WStringR errorMsg) {return self.GetErrorMessage(errorMsg);}, "errorMsg"_a);
    c0.def_static("GetErrorMessageS", py::overload_cast<WStringR, StatusInt>(&BaseGCS::GetErrorMessage), "errorMsg"_a, "errorCode"_a);

    c0.def("Validate", &BaseGCS::Validate, "errorList"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, Validate));
    c0.def("IsStandard", &BaseGCS::IsStandard, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, IsStandard));

    c0.def_property("Name", &BaseGCS::GetName, &BaseGCS::SetName);
    c0.def("GetName", &BaseGCS::GetName, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetName));
    c0.def("SetName", &BaseGCS::SetName, "name"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetName));

    c0.def_property("Description", &BaseGCS::GetDescription, &BaseGCS::SetDescription);
    c0.def("GetDescription", &BaseGCS::GetDescription, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetDescription));
    c0.def("SetDescription", &BaseGCS::SetDescription, "description"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetDescription));

    c0.def_property_readonly("Projection", &BaseGCS::GetProjection);
    c0.def("GetProjection", &BaseGCS::GetProjection, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetProjection));

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
    c0.def("GetProjectionCode", &BaseGCS::GetProjectionCode, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetProjectionCode));
    c0.def("SetProjectionCode", &BaseGCS::SetProjectionCode, "projectionCode"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetProjectionCode));

    c0.def("GetGroup", &BaseGCS::GetGroup, "group"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetGroup));
    c0.def("SetGroup", &BaseGCS::SetGroup, "source"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetGroup));

    c0.def("GetLocation", &BaseGCS::GetLocation, "location"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetLocation));
    c0.def("GetSource", &BaseGCS::GetSource, "source"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetSource));
    c0.def("SetSource", &BaseGCS::SetSource, "source"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetSource));

    c0.def("GetUnits", &BaseGCS::GetUnits, "units"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetUnits));

    c0.def_property("UnitCode", &BaseGCS::GetUnitCode, &BaseGCS::SetUnitCode);
    c0.def("GetUnitCode", &BaseGCS::GetUnitCode, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetUnitCode));
    c0.def("SetUnitCode", &BaseGCS::SetUnitCode, "code"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetUnitCode));

    c0.def_property_readonly("EPSGUnitCode", &BaseGCS::GetEPSGUnitCode);
    c0.def("GetEPSGUnitCode", &BaseGCS::GetEPSGUnitCode, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetEPSGUnitCode));

    c0.def("SetUnitByKeyname", &BaseGCS::SetUnitByKeyname, "unitKeyname"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetUnitByKeyname));
    c0.def("GetDatumName", &BaseGCS::GetDatumName, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetDatumName));

    c0.def_property("DatumCode", &BaseGCS::GetDatumCode, &BaseGCS::SetDatumCode);
    c0.def("GetDatumCode", &BaseGCS::GetDatumCode, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetDatumCode));
    c0.def("SetDatumCode", &BaseGCS::SetDatumCode, "datumCode"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetDatumCode));

    c0.def_property("Datum", &BaseGCS::GetDatum, &BaseGCS::SetDatum);
    c0.def("GetDatum", &BaseGCS::GetDatum, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetDatum));
    c0.def("SetDatum", &BaseGCS::SetDatum, "datum"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetDatum));

    c0.def("HasCustomDatum", &BaseGCS::HasCustomDatum, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, HasCustomDatum));

    c0.def_property_readonly("DatumDescription", &BaseGCS::GetDatumDescription);
    c0.def("GetDatumDescription", &BaseGCS::GetDatumDescription, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetDatumDescription));

    c0.def("GetDatumSource", &BaseGCS::GetDatumSource, "datumSource"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetDatumSource));

    c0.def_property_readonly("DatumConvertMethod", &BaseGCS::GetDatumConvertMethod);
    c0.def("GetDatumConvertMethod", &BaseGCS::GetDatumConvertMethod, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetDatumConvertMethod));

    c0.def("GetDatumDelta", &BaseGCS::GetDatumDelta, "delta"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetDatumDelta));
    c0.def("GetDatumRotation", &BaseGCS::GetDatumRotation, "rotation"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetDatumRotation));

    c0.def_property_readonly("DatumScale", &BaseGCS::GetDatumScale);
    c0.def("GetDatumScale", &BaseGCS::GetDatumScale, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetDatumScale));

    //Need GridFileDefinition published for usage
    //c0.def("GetDatumGridFile", &BaseGCS::GetDatumGridFile, "gridFileDef"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetDatumGridFile));

    c0.def("DatumParametersValid", &BaseGCS::DatumParametersValid, "deltaValid"_a, "rotationValid"_a, "scaleValid"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, DatumParametersValid));
    c0.def("DatumExtendedParametersValid", &BaseGCS::DatumExtendedParametersValid, "deltaValid"_a, "rotationValid"_a, "scaleValid"_a, "gridValid"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, DatumExtendedParametersValid));

    c0.def_property_readonly("VerticalDatumName", &BaseGCS::GetVerticalDatumName);
    c0.def("GetVerticalDatumName", &BaseGCS::GetVerticalDatumName, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetVerticalDatumName));

    c0.def_property_readonly("VerticalDatumCode", &BaseGCS::GetVerticalDatumCode);
    c0.def("GetVerticalDatumCode", &BaseGCS::GetVerticalDatumCode, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetVerticalDatumCode));

    c0.def_property("VerticalDatumCode", &BaseGCS::GetNetVerticalDatumCode, &BaseGCS::SetVerticalDatumCode);
    c0.def("GetNetVerticalDatumCode", &BaseGCS::GetNetVerticalDatumCode, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetNetVerticalDatumCode));
    c0.def("SetVerticalDatumCode", &BaseGCS::SetVerticalDatumCode, "VertDatumCode"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetVerticalDatumCode));

    c0.def("SetVerticalDatumByKey", &BaseGCS::SetVerticalDatumByKey, "verticalDatumKey"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetVerticalDatumByKey));

    c0.def_property_readonly("EllipsoidName", &BaseGCS::GetEllipsoidName);
    c0.def("GetEllipsoidName", &BaseGCS::GetEllipsoidName, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetEllipsoidName));

    c0.def_property("EllipsoidCode", &BaseGCS::GetEllipsoidCode, &BaseGCS::SetEllipsoidCode);
    c0.def("GetEllipsoidCode", &BaseGCS::GetEllipsoidCode, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetEllipsoidCode));
    c0.def("SetEllipsoidCode", &BaseGCS::SetEllipsoidCode, "ellipsoidCode"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetEllipsoidCode));

    c0.def_property_readonly("EllipsoidDescription", &BaseGCS::GetEllipsoidDescription);
    c0.def("GetEllipsoidDescription", &BaseGCS::GetEllipsoidDescription, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetEllipsoidDescription));

    c0.def("GetEllipsoidSource", &BaseGCS::GetEllipsoidSource, "ellipsoidSource"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetEllipsoidSource));
 
    c0.def_property("OriginLatitude", &BaseGCS::GetOriginLatitude, &BaseGCS::SetOriginLatitude);
    c0.def("GetOriginLatitude", &BaseGCS::GetOriginLatitude, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetOriginLatitude));
    c0.def("SetOriginLatitude", &BaseGCS::SetOriginLatitude, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetOriginLatitude));

    c0.def_property("FalseEasting", &BaseGCS::GetFalseEasting, &BaseGCS::SetFalseEasting);
    c0.def("GetFalseEasting", &BaseGCS::GetFalseEasting, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetFalseEasting));
    c0.def("SetFalseEasting", &BaseGCS::SetFalseEasting, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetFalseEasting));

    c0.def_property("FalseNorthing", &BaseGCS::GetFalseNorthing, &BaseGCS::SetFalseNorthing);
    c0.def("GetFalseNorthing", &BaseGCS::GetFalseNorthing, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetFalseNorthing));
    c0.def("SetFalseNorthing", &BaseGCS::SetFalseNorthing, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetFalseNorthing));

    c0.def_property("ScaleReduction", &BaseGCS::GetScaleReduction, &BaseGCS::SetScaleReduction);
    c0.def("GetScaleReduction", &BaseGCS::GetScaleReduction, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetScaleReduction));
    c0.def("SetScaleReduction", &BaseGCS::SetScaleReduction, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetScaleReduction));

    c0.def_property_readonly("EllipsoidPolarRadius", &BaseGCS::GetEllipsoidPolarRadius);
    c0.def("GetEllipsoidPolarRadius", &BaseGCS::GetEllipsoidPolarRadius, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetEllipsoidPolarRadius));

    c0.def_property_readonly("EllipsoidEquatorialRadius", &BaseGCS::GetEllipsoidEquatorialRadius);
    c0.def("GetEllipsoidEquatorialRadius", &BaseGCS::GetEllipsoidEquatorialRadius, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetEllipsoidEquatorialRadius));

    c0.def_property_readonly("EllipsoidEccentricity", &BaseGCS::GetEllipsoidEccentricity);
    c0.def("GetEllipsoidEccentricity", &BaseGCS::GetEllipsoidEccentricity, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetEllipsoidEccentricity));

    c0.def_property("MinimumLongitude", &BaseGCS::GetMinimumLongitude, &BaseGCS::SetMinimumLongitude);
    c0.def("GetMinimumLongitude", &BaseGCS::GetMinimumLongitude, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetMinimumLongitude));
    c0.def("SetMinimumLongitude", &BaseGCS::SetMinimumLongitude, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetMinimumLongitude));

    c0.def_property("MaximumLongitude", &BaseGCS::GetMaximumLongitude, &BaseGCS::SetMaximumLongitude);
    c0.def("GetMaximumLongitude", &BaseGCS::GetMaximumLongitude, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetMaximumLongitude));
    c0.def("SetMaximumLongitude", &BaseGCS::SetMaximumLongitude, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetMaximumLongitude));

    c0.def_property("MinimumLatitude", &BaseGCS::GetMinimumLatitude, &BaseGCS::SetMinimumLatitude);
    c0.def("GetMinimumLatitude", &BaseGCS::GetMinimumLatitude, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetMinimumLatitude));
    c0.def("SetMinimumLatitude", &BaseGCS::SetMinimumLatitude, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetMinimumLatitude));

    c0.def_property("MaximumLatitude", &BaseGCS::GetMaximumLatitude, &BaseGCS::SetMaximumLatitude);
    c0.def("GetMaximumLatitude", &BaseGCS::GetMaximumLatitude, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetMaximumLatitude));
    c0.def("SetMaximumLatitude", &BaseGCS::SetMaximumLatitude, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetMaximumLatitude));

    c0.def_property_readonly("MinimumUsefulLongitude", &BaseGCS::GetMinimumUsefulLongitude);
    c0.def("GetMinimumUsefulLongitude", &BaseGCS::GetMinimumUsefulLongitude, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetMinimumUsefulLongitude));

    c0.def_property_readonly("MaximumUsefulLongitude", &BaseGCS::GetMaximumUsefulLongitude);
    c0.def("GetMaximumUsefulLongitude", &BaseGCS::GetMaximumUsefulLongitude, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetMaximumUsefulLongitude));

    c0.def_property_readonly("MinimumUsefulLatitude", &BaseGCS::GetMinimumUsefulLatitude);
    c0.def("GetMinimumUsefulLatitude", &BaseGCS::GetMinimumUsefulLatitude, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetMinimumUsefulLatitude));

    c0.def_property_readonly("MaximumUsefulLatitude", &BaseGCS::GetMaximumUsefulLatitude);
    c0.def("GetMaximumUsefulLatitude", &BaseGCS::GetMaximumUsefulLatitude, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetMaximumUsefulLatitude));

    c0.def_property("StandardParallel1", &BaseGCS::GetStandardParallel1, &BaseGCS::SetStandardParallel1);
    c0.def("GetStandardParallel1", &BaseGCS::GetStandardParallel1, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetStandardParallel1));
    c0.def("SetStandardParallel1", &BaseGCS::SetStandardParallel1, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetStandardParallel1));

    c0.def_property("StandardParallel2", &BaseGCS::GetStandardParallel2, &BaseGCS::SetStandardParallel2);
    c0.def("GetStandardParallel2", &BaseGCS::GetStandardParallel2, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetStandardParallel2));
    c0.def("SetStandardParallel2", &BaseGCS::SetStandardParallel2, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetStandardParallel2));

    c0.def_property("Azimuth", &BaseGCS::GetAzimuth, &BaseGCS::SetAzimuth);
    c0.def("GetAzimuth", &BaseGCS::GetAzimuth, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetAzimuth));
    c0.def("SetAzimuth", &BaseGCS::SetAzimuth, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetAzimuth));

    c0.def_property("CentralMeridian", &BaseGCS::GetCentralMeridian, &BaseGCS::SetCentralMeridian);
    c0.def("GetCentralMeridian", &BaseGCS::GetCentralMeridian, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetCentralMeridian));
    c0.def("SetCentralMeridian", &BaseGCS::SetCentralMeridian, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetCentralMeridian));

    c0.def_property("EasternMeridian", &BaseGCS::GetEasternMeridian, &BaseGCS::SetEasternMeridian);
    c0.def("GetEasternMeridian", &BaseGCS::GetEasternMeridian, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetEasternMeridian));
    c0.def("SetEasternMeridian", &BaseGCS::SetEasternMeridian, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetEasternMeridian));

    c0.def_property("CentralPointLongitude", &BaseGCS::GetCentralPointLongitude, &BaseGCS::SetCentralPointLongitude);
    c0.def("GetCentralPointLongitude", &BaseGCS::GetCentralPointLongitude, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetCentralPointLongitude));
    c0.def("SetCentralPointLongitude", &BaseGCS::SetCentralPointLongitude, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetCentralPointLongitude));

    c0.def_property("CentralPointLatitude", &BaseGCS::GetCentralPointLatitude, &BaseGCS::SetCentralPointLatitude);
    c0.def("GetCentralPointLatitude", &BaseGCS::GetCentralPointLatitude, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetCentralPointLatitude));
    c0.def("SetCentralPointLatitude", &BaseGCS::SetCentralPointLatitude, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetCentralPointLatitude));

    c0.def_property("Point1Longitude", &BaseGCS::GetPoint1Longitude, &BaseGCS::SetPoint1Longitude);
    c0.def("GetPoint1Longitude", &BaseGCS::GetPoint1Longitude, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetPoint1Longitude));
    c0.def("SetPoint1Longitude", &BaseGCS::SetPoint1Longitude, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetPoint1Longitude));

    c0.def_property("Point1Latitude", &BaseGCS::GetPoint1Latitude, &BaseGCS::SetPoint1Latitude);
    c0.def("GetPoint1Latitude", &BaseGCS::GetPoint1Latitude, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetPoint1Latitude));
    c0.def("SetPoint1Latitude", &BaseGCS::SetPoint1Latitude, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetPoint1Latitude));

    c0.def_property("Point2Longitude", &BaseGCS::GetPoint2Longitude, &BaseGCS::SetPoint2Longitude);
    c0.def("GetPoint2Longitude", &BaseGCS::GetPoint2Longitude, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetPoint2Longitude));
    c0.def("SetPoint2Longitude", &BaseGCS::SetPoint2Longitude, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetPoint2Longitude));

    c0.def_property("Point2Latitude", &BaseGCS::GetPoint2Latitude, &BaseGCS::SetPoint2Latitude);
    c0.def("GetPoint2Latitude", &BaseGCS::GetPoint2Latitude, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetPoint2Latitude));
    c0.def("SetPoint2Latitude", &BaseGCS::SetPoint2Latitude, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetPoint2Latitude));

    c0.def_property("GeoidSeparation", &BaseGCS::GetGeoidSeparation, &BaseGCS::SetGeoidSeparation);
    c0.def("GetGeoidSeparation", &BaseGCS::GetGeoidSeparation, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetGeoidSeparation));
    c0.def("SetGeoidSeparation", &BaseGCS::SetGeoidSeparation, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetGeoidSeparation));

    c0.def_property("ElevationAboveGeoid", &BaseGCS::GetElevationAboveGeoid, &BaseGCS::SetElevationAboveGeoid);
    c0.def("GetElevationAboveGeoid", &BaseGCS::GetElevationAboveGeoid, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetElevationAboveGeoid));
    c0.def("SetElevationAboveGeoid", &BaseGCS::SetElevationAboveGeoid, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetElevationAboveGeoid));

    c0.def_property("EllipsoidScaleFactor", &BaseGCS::GetEllipsoidScaleFactor, &BaseGCS::SetEllipsoidScaleFactor);
    c0.def("GetEllipsoidScaleFactor", &BaseGCS::GetEllipsoidScaleFactor, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetEllipsoidScaleFactor));
    c0.def("SetEllipsoidScaleFactor", &BaseGCS::SetEllipsoidScaleFactor, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetEllipsoidScaleFactor));

    c0.def_property("UTMZone", &BaseGCS::GetUTMZone, &BaseGCS::SetUTMZone);
    c0.def("GetUTMZone", &BaseGCS::GetUTMZone, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetUTMZone));
    c0.def("SetUTMZone", &BaseGCS::SetUTMZone, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetUTMZone));

    c0.def_property("Hemisphere", &BaseGCS::GetHemisphere, &BaseGCS::SetHemisphere);
    c0.def("GetHemisphere", &BaseGCS::GetHemisphere, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetHemisphere));
    c0.def("SetHemisphere", &BaseGCS::SetHemisphere, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetHemisphere));

    c0.def_property("Quadrant", &BaseGCS::GetQuadrant, &BaseGCS::SetQuadrant);
    c0.def("GetQuadrant", &BaseGCS::GetQuadrant, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetQuadrant));
    c0.def("SetQuadrant", &BaseGCS::SetQuadrant, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetQuadrant));

    c0.def_property("DanishSys34Region", &BaseGCS::GetDanishSys34Region, &BaseGCS::SetDanishSys34Region);
    c0.def("GetDanishSys34Region", &BaseGCS::GetDanishSys34Region, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetDanishSys34Region));
    c0.def("SetDanishSys34Region", &BaseGCS::SetDanishSys34Region, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetDanishSys34Region));

    c0.def_property("AffineA0", &BaseGCS::GetAffineA0, &BaseGCS::SetAffineA0);
    c0.def("GetAffineA0", &BaseGCS::GetAffineA0, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetAffineA0));
    c0.def("SetAffineA0", &BaseGCS::SetAffineA0, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetAffineA0));

    c0.def_property("AffineA1", &BaseGCS::GetAffineA1, &BaseGCS::SetAffineA1);
    c0.def("GetAffineA1", &BaseGCS::GetAffineA1, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetAffineA1));
    c0.def("SetAffineA1", &BaseGCS::SetAffineA1, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetAffineA1));

    c0.def_property("AffineA2", &BaseGCS::GetAffineA2, &BaseGCS::SetAffineA2);
    c0.def("GetAffineA2", &BaseGCS::GetAffineA2, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetAffineA2));
    c0.def("SetAffineA2", &BaseGCS::SetAffineA2, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetAffineA2));

    c0.def_property("AffineB0", &BaseGCS::GetAffineB0, &BaseGCS::SetAffineB0);
    c0.def("GetAffineB0", &BaseGCS::GetAffineB0, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetAffineB0));
    c0.def("SetAffineB0", &BaseGCS::SetAffineB0, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetAffineB0));

    c0.def_property("AffineB1", &BaseGCS::GetAffineB1, &BaseGCS::SetAffineB1);
    c0.def("GetAffineB1", &BaseGCS::GetAffineB1, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetAffineB1));
    c0.def("SetAffineB1", &BaseGCS::SetAffineB1, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetAffineB1));

    c0.def_property("AffineB2", &BaseGCS::GetAffineB2, &BaseGCS::SetAffineB2);
    c0.def("GetAffineB2", &BaseGCS::GetAffineB2, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetAffineB2));
    c0.def("SetAffineB2", &BaseGCS::SetAffineB2, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetAffineB2));

    c0.def("GetAffineParameters", [](BaseGCSCR self) 
        {
        double A0, A1, A2, B0, B1, B2;
        self.GetAffineParameters(&A0, &A1, &A2, &B0, &B1, &B2);
        return py::make_tuple(A0, A1, A2, B0, B1, B2);
        }, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetAffineParameters));
    c0.def("SetAffineParameters", &BaseGCS::SetAffineParameters, "A0"_a, "A1"_a, "A2"_a, "B0"_a, "B1"_a, "B2"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetAffineParameters));

    c0.def("DefinitionComplete", &BaseGCS::DefinitionComplete, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, DefinitionComplete));
    c0.def_static("GetLinearUnitNames", &BaseGCS::GetLinearUnitNames, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetLinearUnitNames));
    c0.def_static("GetUnitNames", &BaseGCS::GetUnitNames, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetUnitNames));
    c0.def_static("GetDatumNames", &BaseGCS::GetDatumNames, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetDatumNames));
    c0.def_static("GetEllipsoidNames", &BaseGCS::GetEllipsoidNames, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetEllipsoidNames));
    c0.def("GetScaleAlongMeridian", &BaseGCS::GetScaleAlongMeridian, "point"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetScaleAlongMeridian));
    c0.def("GetScaleAlongParallel", &BaseGCS::GetScaleAlongParallel, "point"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetScaleAlongParallel));
    c0.def("GetGridScale", &BaseGCS::GetGridScale, "point"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetGridScale));
    c0.def("GetConvergenceAngle", &BaseGCS::GetConvergenceAngle, "point"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetConvergenceAngle));

    c0.def("GetDistance", [](BaseGCSCR self, GeoPointCR  startPoint, GeoPointCR  endPoint)
        {
        double distance, azimuth;
        StatusInt status = self.GetDistance (&distance, &azimuth, startPoint, endPoint);
        return py::make_tuple (status, distance, azimuth);
        }, "startPoint"_a, "endPoint"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetDistance));

    c0.def("GetDistanceInMeters", [](BaseGCSCR self, GeoPointCR  startPoint, GeoPointCR  endPoint)
        {
        double distance, azimuth;
        StatusInt status = self.GetDistanceInMeters (&distance, &azimuth, startPoint, endPoint);
        return py::make_tuple (status, distance, azimuth);
        }, "startPoint"_a, "endPoint"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetDistanceInMeters));

    c0.def("GetCenterPoint", &BaseGCS::GetCenterPoint, "centerPoint"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetCenterPoint));
    c0.def("IsEquivalent", &BaseGCS::IsEquivalent, "compareTo"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, IsEquivalent));
    c0.def("IsEqual", &BaseGCS::IsEqual, "compareTo"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, IsEqual));
    c0.def("CorrectVerticalDatumToPreserveLegacyElevation", &BaseGCS::CorrectVerticalDatumToPreserveLegacyElevation, "extent"_a, "targetGCS"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, CorrectVerticalDatumToPreserveLegacyElevation));

    c0.def("Compare", [](BaseGCSCR self, BaseGCSCR compareTo, bool stopFirstDifference)
        {
        bool datumDifferent, csDifferent, verticalDatumDifferent, localTransformDifferent;
        bool status = self.Compare(compareTo, datumDifferent, csDifferent, verticalDatumDifferent, localTransformDifferent, stopFirstDifference);
        return py::make_tuple (status, datumDifferent, csDifferent, verticalDatumDifferent, localTransformDifferent);
        }, "compareTo"_a, "stopFirstDifference"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, Compare));

    c0.def("GetMathematicalDomain", &BaseGCS::GetMathematicalDomain, "shape"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetMathematicalDomain));

    c0.def("GetMathematicalDomainExtent", [](BaseGCSCR self)
        {
        double minLongitude, maxLongitude, minLatitude, maxLatitude;
        StatusInt status = self.GetMathematicalDomainExtent (minLongitude, maxLongitude, minLatitude, maxLatitude);
        return py::make_tuple (status, minLongitude, maxLongitude, minLatitude, maxLatitude);
        }, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetMathematicalDomainExtent));

#ifdef DICTIONARY_MANAGEMENT_ONLY
    c0.def("OutputAsASC", &BaseGCS::OutputAsASC, "GCSAsASC"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, OutputAsASC));
#endif

    c0.def("HasEquivalentDatum", &BaseGCS::HasEquivalentDatum, "compareTo"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, HasEquivalentDatum));
    c0.def("GetEPSGCode", py::overload_cast<bool>(&BaseGCS::GetEPSGCode, py::const_), "noSearch"_a=false, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetEPSGCode));
    c0.def("GetEPSGDatumCode", &BaseGCS::GetEPSGDatumCode, "noSearch"_a = false, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetEPSGDatumCode));
    c0.def("GetEPSGEllipsoidCode", &BaseGCS::GetEPSGEllipsoidCode, "noSearch"_a = false, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetEPSGEllipsoidCode));

    c0.def_property("StoredEPSGCode", &BaseGCS::GetStoredEPSGCode, &BaseGCS::SetStoredEPSGCode);
    c0.def("GetStoredEPSGCode", &BaseGCS::GetStoredEPSGCode, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetStoredEPSGCode));
    c0.def("SetStoredEPSGCode", &BaseGCS::SetStoredEPSGCode, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetStoredEPSGCode));

    c0.def("CartesianFromLatLong", &BaseGCS::CartesianFromLatLong, "outCartesian"_a, "inLatLong"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, CartesianFromLatLong));
    c0.def("CartesianFromLatLong2D", &BaseGCS::CartesianFromLatLong2D, "outCartesian"_a, "inLatLong"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, CartesianFromLatLong2D));
    c0.def("LatLongFromCartesian", &BaseGCS::LatLongFromCartesian, "outLatLong"_a, "inCartesian"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, LatLongFromCartesian));
    c0.def("LatLongFromCartesian2D", &BaseGCS::LatLongFromCartesian2D, "outLatLong"_a, "inCartesian"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, LatLongFromCartesian2D));
    c0.def("UnitsFromMeters", &BaseGCS::UnitsFromMeters, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, UnitsFromMeters));
    c0.def("CheckGeoPointRange", &BaseGCS::CheckGeoPointRange, "points"_a, "numPoints"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, CheckGeoPointRange));
    c0.def("CheckCartesianRange", &BaseGCS::CheckCartesianRange, "points"_a, "numPoints"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, CheckCartesianRange));

    c0.def_property("ReprojectElevation", &BaseGCS::GetReprojectElevation, &BaseGCS::SetReprojectElevation);
    c0.def("GetReprojectElevation", &BaseGCS::GetReprojectElevation, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, GetReprojectElevation));
    c0.def("SetReprojectElevation", &BaseGCS::SetReprojectElevation, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, SetReprojectElevation));

    c0.def("LatLongFromLatLong", &BaseGCS::LatLongFromLatLong, "outLatLong"_a, "inLatLong"_a, "targetGCS"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, LatLongFromLatLong));
    c0.def("LatLongFromLatLong2D", &BaseGCS::LatLongFromLatLong2D, "outLatLong"_a, "inLatLong"_a, "targetGCS"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, LatLongFromLatLong2D));

    c0.def_static("RadiansFromDegrees", &BaseGCS::RadiansFromDegrees, "inDegrees"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, RadiansFromDegrees));
    c0.def_static("DegreesFromRadians", &BaseGCS::DegreesFromRadians, "inRadians"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, DegreesFromRadians));
    c0.def("LatLongFromXYZ", &BaseGCS::LatLongFromXYZ, "outLatLong"_a, "inXYZ"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, LatLongFromXYZ));
    c0.def("XYZFromLatLong", &BaseGCS::XYZFromLatLong, "outXYZ"_a, "inLatLong"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, BaseGCS, XYZFromLatLong));

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
    c1.def("GetName", &Group::GetName, DOC(Bentley, DgnPlatform, GeoCoordinates, Group, GetName));

    c1.def_property_readonly("Description", &Group::GetDescription);
    c1.def("GetDescription", &Group::GetDescription, DOC(Bentley, DgnPlatform, GeoCoordinates, Group, GetDescription));

    c1.def("GetMemberEnumerator", &Group::GetMemberEnumerator, DOC(Bentley, DgnPlatform, GeoCoordinates, Group, GetMemberEnumerator));
    c1.def("GetGroupEnumerator", &Group::GetGroupEnumerator, DOC(Bentley, DgnPlatform, GeoCoordinates, Group, GetGroupEnumerator));
    c1.def("Destroy", &Group::Destroy, DOC(Bentley, DgnPlatform, GeoCoordinates, Group, Destroy));

    //===================================================================================
    // Struct GroupEnumerator
    py::class_<GroupEnumerator, std::unique_ptr<GroupEnumerator, py::nodelete>> c2(m, "GroupEnumerator");

    c2.def("MoveNext", &GroupEnumerator::MoveNext, DOC(Bentley, DgnPlatform, GeoCoordinates, GroupEnumerator, MoveNext));
    c2.def("GetCurrent", &GroupEnumerator::GetCurrent, DOC(Bentley, DgnPlatform, GeoCoordinates, GroupEnumerator, GetCurrent));
    c2.def("Destroy", &GroupEnumerator::Destroy, DOC(Bentley, DgnPlatform, GeoCoordinates, GroupEnumerator, Destroy));

    //===================================================================================
    // Struct MemberEnumerator
    py::class_<MemberEnumerator, std::unique_ptr<MemberEnumerator, py::nodelete>> c3(m, "MemberEnumerator");

    c3.def("MoveNext", &MemberEnumerator::MoveNext, DOC(Bentley, DgnPlatform, GeoCoordinates, MemberEnumerator, MoveNext));
    c3.def("GetCurrentGCSName", &MemberEnumerator::GetCurrentGCSName, DOC(Bentley, DgnPlatform, GeoCoordinates, MemberEnumerator, GetCurrentGCSName));
    c3.def("GetCurrentGCSDescription", &MemberEnumerator::GetCurrentGCSDescription, DOC(Bentley, DgnPlatform, GeoCoordinates, MemberEnumerator, GetCurrentGCSDescription));
    c3.def("Destroy", &MemberEnumerator::Destroy, DOC(Bentley, DgnPlatform, GeoCoordinates, MemberEnumerator, Destroy));

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
    c5.def("MoveNext", &UnitEnumerator::MoveNext, DOC(Bentley, DgnPlatform, GeoCoordinates, UnitEnumerator, MoveNext));
    c5.def("GetCurrent", &UnitEnumerator::GetCurrent, DOC(Bentley, DgnPlatform, GeoCoordinates, UnitEnumerator, GetCurrent));
    c5.def("Destroy", &UnitEnumerator::Destroy, DOC(Bentley, DgnPlatform, GeoCoordinates, UnitEnumerator, Destroy));

    //===================================================================================
    // struct Ellipsoid
    py::class_< Ellipsoid, std::unique_ptr<Ellipsoid, py::nodelete>> c6(m, "Ellipsoid");
    c6.def_static ("CreateEllipsoid", py::overload_cast<WCharCP>(&Ellipsoid::CreateEllipsoid), "keyName"_a);
    c6.def("IsValid", &Ellipsoid::IsValid, DOC(Bentley, DgnPlatform, GeoCoordinates, Ellipsoid, IsValid));
    c6.def("GetError", &Ellipsoid::GetError, DOC(Bentley, DgnPlatform, GeoCoordinates, Ellipsoid, GetError));
    c6.def("GetErrorMessage", &Ellipsoid::GetErrorMessage, "errorMsg"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, Ellipsoid, GetErrorMessage));

    c6.def_property("Name", &Ellipsoid::GetName, &Ellipsoid::SetName);
    c6.def("GetName", &Ellipsoid::GetName, DOC(Bentley, DgnPlatform, GeoCoordinates, Ellipsoid, GetName));
    c6.def("SetName", &Ellipsoid::SetName, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, Ellipsoid, SetName));

    c6.def_property_readonly("Description", &Ellipsoid::GetDescription);
    c6.def("GetDescription", &Ellipsoid::GetDescription, DOC(Bentley, DgnPlatform, GeoCoordinates, Ellipsoid, GetDescription));

    c6.def("GetSource", &Ellipsoid::GetSource, "source"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, Ellipsoid, GetSource));

    c6.def_property_readonly("PolarRadius", &Ellipsoid::GetPolarRadius);
    c6.def("GetPolarRadius", &Ellipsoid::GetPolarRadius, DOC(Bentley, DgnPlatform, GeoCoordinates, Ellipsoid, GetPolarRadius));

    c6.def_property_readonly("EquatorialRadius", &Ellipsoid::GetEquatorialRadius);
    c6.def("GetEquatorialRadius", &Ellipsoid::GetEquatorialRadius, DOC(Bentley, DgnPlatform, GeoCoordinates, Ellipsoid, GetEquatorialRadius));

    c6.def_property_readonly("Eccentricity", &Ellipsoid::GetEccentricity);
    c6.def("GetEccentricity", &Ellipsoid::GetEccentricity, DOC(Bentley, DgnPlatform, GeoCoordinates, Ellipsoid, GetEccentricity));

    c6.def_property("EPSGCode", &Ellipsoid::GetEPSGCode, &Ellipsoid::SetEPSGCode);
    c6.def("GetEPSGCode", &Ellipsoid::GetEPSGCode, DOC(Bentley, DgnPlatform, GeoCoordinates, Ellipsoid, GetEPSGCode));
    c6.def("SetEPSGCode", &Ellipsoid::SetEPSGCode, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, Ellipsoid, SetEPSGCode));

    c6.def("Destroy", &Ellipsoid::Destroy, DOC(Bentley, DgnPlatform, GeoCoordinates, Ellipsoid, Destroy));

#ifdef DICTIONARY_MANAGEMENT_ONLY
    c6.def("OutputAsASC", &Ellipsoid::OutputAsASC, DOC(Bentley, DgnPlatform, GeoCoordinates, Ellipsoid, OutputAsASC));
#endif

    c6.def_static("CreateEnumerator", &Ellipsoid::CreateEnumerator, DOC(Bentley, DgnPlatform, GeoCoordinates, Ellipsoid, CreateEnumerator));

    //===================================================================================
    // struct Ellipsoid
    py::class_< EllipsoidEnumerator, std::unique_ptr<EllipsoidEnumerator, py::nodelete>> c7(m, "EllipsoidEnumerator");

    c7.def("MoveNext", &EllipsoidEnumerator::MoveNext, DOC(Bentley, DgnPlatform, GeoCoordinates, EllipsoidEnumerator, MoveNext));
    c7.def("GetCurrent", &EllipsoidEnumerator::GetCurrent, DOC(Bentley, DgnPlatform, GeoCoordinates, EllipsoidEnumerator, GetCurrent));
    c7.def("Destroy", &EllipsoidEnumerator::Destroy, DOC(Bentley, DgnPlatform, GeoCoordinates, EllipsoidEnumerator, Destroy));

    //===================================================================================
    // struct Datum
    py::class_< Datum, std::unique_ptr<Datum, py::nodelete>> c8(m, "Datum");

    c8.attr("NO_DATUM_CODE") = Datum::NO_DATUM_CODE;
    c8.attr("CUSTOM_DATUM_CODE") = Datum::CUSTOM_DATUM_CODE;
    c8.attr("USER_DATUM_CODE_OFFSET") = Datum::USER_DATUM_CODE_OFFSET;
    c8.attr("DATUM_CODE_SEPARATOR") = Datum::DATUM_CODE_SEPARATOR;

    c8.def_static("CreateDatum", py::overload_cast<WCharCP>(&Datum::CreateDatum), "keyName"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, CreateDatum));

    c8.def("IsValid", &Datum::IsValid, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, IsValid));
    c8.def("GetError", &Datum::GetError, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, GetError));
    c8.def("GetErrorMessage", &Datum::GetErrorMessage, "errorMsg"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, GetErrorMessage));

    c8.def_property("Name", &Datum::GetName, &Datum::SetName);
    c8.def("GetName", &Datum::GetName, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, GetName));
    c8.def("SetName", &Datum::SetName, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, SetName));

    c8.def_property("Description", &Datum::GetDescription, &Datum::SetDescription);
    c8.def("GetDescription", &Datum::GetDescription, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, GetDescription));
    c8.def("SetDescription", &Datum::SetDescription, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, SetDescription));

    c8.def_property("Source", &Datum::GetSource, &Datum::SetSource);
    c8.def("GetSource", &Datum::GetSource, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, GetSource));
    c8.def("SetSource", &Datum::SetSource, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, SetSource));

    c8.def_property("Source", &Datum::GetConvertToWGS84MethodCode, &Datum::SetConvertToWGS84MethodCode);
    c8.def("GetConvertToWGS84MethodCode", &Datum::GetConvertToWGS84MethodCode, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, GetConvertToWGS84MethodCode));
    c8.def("SetConvertToWGS84MethodCode", &Datum::SetConvertToWGS84MethodCode, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, SetConvertToWGS84MethodCode));

    c8.def("UsesAGeocentricMethod", &Datum::UsesAGeocentricMethod, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, UsesAGeocentricMethod));
    c8.def("GetDelta", &Datum::GetDelta, "delta"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, GetDelta));
    c8.def("SetDelta", &Datum::SetDelta, "delta"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, SetDelta));

    c8.def("GetRotation", &Datum::GetRotation, "rotation"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, GetRotation));
    c8.def("SetRotation", &Datum::SetRotation, "rotation"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, SetRotation));

    c8.def_property("Scale", &Datum::GetScale, &Datum::SetScale);
    c8.def("GetScale", &Datum::GetScale, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, GetScale));
    c8.def("SetScale", &Datum::SetScale, "scalePPM"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, SetScale));

    //Need GridFileDefinition published for usage
    //c8.def("SetGridFile", &Datum::SetGridFile, "gridFileDef"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, SetGridFile));
    //c8.def("GetGridFile", &Datum::GetGridFile, "gridFileDef"_a, "strict"_a = true, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, GetGridFile));

    c8.def_property("EPSGCode", &Datum::GetEPSGCode, &Datum::SetEPSGCode);
    c8.def("GetEPSGCode", &Datum::GetEPSGCode, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, GetEPSGCode));
    c8.def("SetEPSGCode", &Datum::SetEPSGCode, "value"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, SetEPSGCode));

    c8.def_property_readonly("EllipsoidName", &Datum::GetEllipsoidName);
    c8.def("GetEllipsoidName", &Datum::GetEllipsoidName, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, GetEllipsoidName));

    c8.def_property("EllipsoidCode", &Datum::GetEllipsoidCode, &Datum::SetEllipsoidCode);
    c8.def("GetEllipsoidCode", &Datum::GetEllipsoidCode, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, GetEllipsoidCode));
    c8.def("SetEllipsoidCode", &Datum::SetEllipsoidCode, "ellipsoidCode"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, SetEllipsoidCode));

    c8.def_property("EllipsoidDescription", &Datum::GetEllipsoidDescription, &Datum::GetEllipsoidSource);
    c8.def("GetEllipsoidDescription", &Datum::GetEllipsoidDescription, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, GetEllipsoidDescription));
    c8.def("GetEllipsoidSource", &Datum::GetEllipsoidSource, "ellipsoidSource"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, GetEllipsoidSource));

    c8.def_property_readonly("EllipsoidPolarRadius", &Datum::GetEllipsoidPolarRadius);
    c8.def("GetEllipsoidPolarRadius", &Datum::GetEllipsoidPolarRadius, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, GetEllipsoidPolarRadius));

    c8.def_property_readonly("EllipsoidEquatorialRadius", &Datum::GetEllipsoidEquatorialRadius);
    c8.def("GetEllipsoidEquatorialRadius", &Datum::GetEllipsoidEquatorialRadius, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, GetEllipsoidEquatorialRadius));

    c8.def_property_readonly("EllipsoidEccentricity", &Datum::GetEllipsoidEccentricity);
    c8.def("GetEllipsoidEccentricity", &Datum::GetEllipsoidEccentricity, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, GetEllipsoidEccentricity));

    c8.def_property("Ellipsoid", &Datum::GetEllipsoid, &Datum::SetEllipsoid);
    c8.def("GetEllipsoid", &Datum::GetEllipsoid, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, GetEllipsoid));
    c8.def("SetEllipsoid", &Datum::SetEllipsoid, "newEllipsoid"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, SetEllipsoid));

    c8.def("ParametersValid", [](Datum const& self)
        {
        bool deltaValid, rotationValid, scaleValid;
        self.ParametersValid(deltaValid, rotationValid, scaleValid);
        return py::make_tuple (deltaValid, rotationValid, scaleValid);
        }, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, ParametersValid));

    c8.def("ExtendedParametersValid", [](Datum const& self)
        {
        bool deltaValid, rotationValid, scaleValid, gridValid;
        self.ExtendedParametersValid(deltaValid, rotationValid, scaleValid, gridValid);
        return py::make_tuple (deltaValid, rotationValid, scaleValid, gridValid);
        }, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, ExtendedParametersValid));

    c8.def("Destroy", &Datum::Destroy, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, Destroy));

#ifdef DICTIONARY_MANAGEMENT_ONLY
    c8.def("OutputAsASC", &Datum::OutputAsASC, "DatumAsASC"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, Datum, OutputAsASC));
#endif

    c8.def_static ("CreateEnumerator", &Datum::CreateEnumerator);

    //===================================================================================
    // struct DatumEnumerator
    py::class_< DatumEnumerator, std::unique_ptr<DatumEnumerator, py::nodelete>> c9(m, "DatumEnumerator");

    c9.def("MoveNext", &DatumEnumerator::MoveNext, DOC(Bentley, DgnPlatform, GeoCoordinates, DatumEnumerator, MoveNext));
    c9.def("GetCurrent", &DatumEnumerator::GetCurrent, DOC(Bentley, DgnPlatform, GeoCoordinates, DatumEnumerator, GetCurrent));
    c9.def("Destroy", &DatumEnumerator::Destroy, DOC(Bentley, DgnPlatform, GeoCoordinates, DatumEnumerator, Destroy));
    }
