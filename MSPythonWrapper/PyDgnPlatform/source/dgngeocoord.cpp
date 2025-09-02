/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgngeocoord.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnGeoCoord/DgnGeoCoord.h>
#include "PyDgnPlatform.h"

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_DgnGCS_SetPaperScale =R"doc(Sets the Paper Scale for this GCS. The Paper Scale affects the
Cartesian coordinates and makes measurements unreliable. Its use is
not recommended. The default and recommended value is 1.0.

:param paperScale:
    (input) The new Paper Scale value.

:param modelRef:
    (input) The model that this GCS came from.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_DgnGCS_GetPaperScale =R"doc(Gets the Paper Scale for this GCS. The Paper scale affects the
Cartesian coordinates and makes measurements unreliable. Its use is
not recommended.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_DgnGCS_RemoveEventHandler =R"doc(Removes a coordinate system event handler.

:param handler:
    (input) The event handler. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_DgnGCS_SetEventHandler =R"doc(Sets a coordinate system event handler.

:param handler:
    (input) The event handler.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_DgnGCS_ReloadGeoReferences =R"doc(Method that reloads geographically transformed and geographically
projected references, responding to GCS changes in modelRef.

:param modelRef:
    (input) The modelRef for which the GCS has changed.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_DgnGCS_FromCache =R"doc(Factory method that constructs an DgnGCS instance by attempting to
locate the element that saves the geographic coordinate system
parameters in the specifed DgnModel, and creating the instance based
on those parameters. If the DgnGCS for a particular DgnModel has
previously been requested, it is cached and this call is very
efficient.

:param cache:
    (input) The DgnModel

:param primaryCoordSys:
    (input) true to find the primary coordinate system, false to find the
    " reference " coordinate system. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_DgnGCS_DeleteFromModel =R"doc(Permanently deletes the saved Geographic Coordinate System parameters
saved in the model.

:param modelRef:
    (input) The model to delete from.

:param primaryCoordSys:
    (input) true to delete the primary coordinate system, false to delete
    the " reference " coordinate system.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_DgnGCS_FromModel =R"doc(Factory method that constructs an DgnGCS instance by attempting to
locate the element that saves the geographic coordinate system
parameters in the model, and creating the instance based on those
parameters. If the DgnGCS for a particular model has previously been
requested, it is cached and this call is very efficient.

:param modelRef:
    (input) The model to look in.

:param primaryCoordSys:
    (input) true to find the primary coordinate system, false to find the
    " reference " coordinate system. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_DgnGCS_ToModel =R"doc(Writes the GCS parameters to the model. Some GCS are not storable in a
DGN file even though valid. Such GCS include custom GCS with a custom
datum refering to grid file paths with more than 75 characters long.
Also GCS with custom datum defining more than one chained geodetic
transform cannot be stored.

:param modelRef:
    (input) The model to write the GCS to.

:param primaryCoordSys:
    (input) true to write as the primary coordinate system, false to write
    as the " reference " coordinate system.

:param writeToFile:
    (input) true to save to the file, false to save only as cached.

:param reprojectData:
    (input) true if the data in the model is to be reprojected from the
    existing GCS to the new GCS.

:param reportProblems:
    (input) true if reprojection problems should be reported to the user.

Remark:
    s If writeToFile is false, reprojectData is ignored and the data
    in the model is not reprojected.

:returns:
    ERROR if the GCS cannot be stored in the model. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_DgnGCS_GetDisplayName =R"doc(Gets a name suitable for display in user interface.

:param outputBuffer:
    (output) Buffer to hold the projection name.

:param bufferSize:
    (input) dimension of outputBuffer. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_DgnGCS_GetProjectionName =R"doc(Gets the localized name of the Geographic Projection used in the
Coordinate System.

:param outputBuffer:
    (output) Buffer to hold the projection name.

:param bufferSize:
    (input) dimension of outputBuffer. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_DgnGCS_GetLocalTransform =R"doc(Calculates the best approximate transform that can be applied at the
elementOrigin to transform coordinates from this GCS's design
coordinates to those of the destination GCS.

:param outTransform:
    (output) The calculated Transform.

:param elementOrigin:
    (input) The point, in design coordinates (UORs) of this GCS, at which
    the transform will be applied.

:param extent:
    (input) The extent, in design coordinates (UORs) of a bvector that
    tells the span of the data to which the transform will be applied.
    If NULL, a reasonable guess is used.

:param doRotate:
    (input) true to allow rotation in the transform.

:param doScale:
    (input) true to allow scaling in the transform.

:param destMstnGCS:
    (output) The destination DgnGCS .

:returns:
    SUCCESS or a CS_MAP error code if elementOrigin could not be
    reprojected. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_DgnGCS_GetLinearTransformToBaseGCS =R"doc(Calculates the best approximate transform that can be applied at the
elementOrigin to transform coordinates from this GCS's design
coordinates to those of the destination Base GCS.

:param outTransform:
    (output) The calculated Transform.

:param extent:
    (input) The extent in design coordinates (UORs) of this GCS to use to
    find the transform. This extent must of course be valid (not
    empty) but shall also define an extent no less than 0.01 of the
    linear units of the input GCS wide in all dimensions. If the input
    GCS is longitude/latitude then the extent will be no less than
    0.0000001 (1e-07) degrees for the first two ordinate and
    0.01[Meter] for the elevation (z) ordinate.

:param maxError:
    (output) If provided receives the max error observed over the extent

:param meanError:
    (output) If provided receives the mean error observed over the extent

:returns:
    SUCCESS or a CS_MAP error code if elementOrigin could not be
    reprojected. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_DgnGCS_ReprojectUors2D =R"doc(Reprojects an array of 2d points in the design coordinates (UORs) of
this model to the 2d design coordinates (UORs) of the design file
associated with destMstnGCS.

:param outUorsDest:
    (output) An array dimensioned to numPoints to hold the calculated UORs.

:param outLatLongDest:
    (output) An optional array that will be filled with the geographic
    coordinates in the datum of the destMstnGCS. If not NULL, the
    array must be dimensioned to numPoints.

:param outLatLongSrc:
    (output) An optional array that will be filled with the geographic
    coordinates in the datum of this GCS. If not NULL, the array must
    be dimensioned to numPoints.

:param inUors:
    (input) An array holding the input points in design file coordinaates.

:param numPoints:
    (input) The number of points in inUors.

:param destMstnGCS:
    (output) The destination DgnGCS .

:returns:
    SUCCESS or a CS_MAP error code if any of the points could not be
    reprojected. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_DgnGCS_LatLongFromUors2D =R"doc(Calculates the longitude, latitude from 2d design coordinates (UORS).

:param outLatLong:
    (output) The calculated longitude,latitude in the datum of this GCS.

:param inUors:
    (input) The input design coordinates. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_DgnGCS_UorsFromLatLong2D =R"doc(Calculates the 2d design coordinates (UORS) of the input
Longitude/Latitude point.

:param outUors:
    (output) The calculated design coordinates.

:param inLatLong:
    (input) The longitude,latitude in the datum of this GCS. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_DgnGCS_ReprojectUors =R"doc(Reprojects an array of points in the design coordinates (UORs) of this
model to the design coordinates (UORs) of the design file associated
with destMstnGCS.

:param outUorsDest:
    (output) An array dimensioned to numPoints to hold the calculated UORs.

:param outLatLongDest:
    (output) An optional array that will be filled with the geographic
    coordinates in the datum of the destMstnGCS. If not NULL, the
    array must be dimensioned to numPoints.

:param outLatLongSrc:
    (output) An optional array that will be filled with the geographic
    coordinates in the datum of this GCS. If not NULL, the array must
    be dimensioned to numPoints.

:param inUors:
    (input) An array holding the input points in design file coordinaates.

:param numPoints:
    (input) The number of points in inUors.

:param destMstnGCS:
    (output) The destination DgnGCS .

:returns:
    SUCCESS or a CS_MAP error code if any of the points could not be
    reprojected. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_DgnGCS_LatLongFromUorsXYZ =R"doc(Calculates the longitude, latitude, and elevation from design
coordinates (UORS) interpreted as XYZ coordinates.

:param outLatLong:
    (output) The calculated longitude,latitude,elevation in the datum of
    this GCS.

:param inUors:
    (input) The input design coordinates.

:returns:
    SUCCESS or a CS_MAP error code if any of the points could not be
    reprojected. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_DgnGCS_LatLongFromUors =R"doc(Calculates the longitude, latitude, and elevation from design
coordinates (UORS).

:param outLatLong:
    (output) The calculated longitude,latitude,elevation in the datum of
    this GCS.

:param inUors:
    (input) The input design coordinates.

:returns:
    SUCCESS or a CS_MAP error code if any of the points could not be
    reprojected. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_DgnGCS_UorsFromLatLong =R"doc(Calculates the design coordinates (UORS) of the input
Longitude/Latitude/Elevation point.

:param outUors:
    (output) The calculated design coordinates.

:param inLatLong:
    (input) The longitude,latitude,elevation in the datum of this GCS.

:returns:
    SUCCESS or a CS_MAP error code if any of the points could not be
    reprojected. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_DgnGCS_UorsFromCartesian2D =R"doc(Calculates the design coordinates (UORs) from cartesian coordinates in
the units specified by the GCS.

:param outUors:
    (output) The calculated design coordinates.

:param inCartesian:
    INOUT The cartesian coordinates in the units specified in the GCS.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_DgnGCS_UorsFromCartesian =R"doc(Calculates the design coordinates (UORs) from cartesian coordinates in
the units specified by the GCS.

:param outUors:
    (output) The calculated design coordinates.

:param inCartesian:
    INOUT The cartesian coordinates in the units specified in the GCS.)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_DgnGCS_CartesianFromUors2D =R"doc(Calculates the cartesian coordinates in the units specified by the GCS
from design coordinates (UORs).

:param outCartesian:
    (output) The calculated cartesian coordinates in the units specified in
    the GCS.

:param inUors:
    (input) The design coordinates. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_DgnGCS_CartesianFromUors =R"doc(Calculates the cartesian coordinates in the units specified by the GCS
from design coordinates (UORs).

:param outCartesian:
    (output) The calculated cartesian coordinates in the units specified in
    the GCS.

:param inUors:
    (input) The design coordinates. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_DgnGCS_CreateGCS =R"doc(Creates an instance of DgnGCS for the given model, looking up the
Coordinate System parameters from the Coordinate System Library by
name.

:param coordinateSystemName:
    (input) The common name of the coordinate system..

:param modelRef:
    (input) The modelRef to use for the design file unit defintion.

Remark:
    s The DgnGCS instance is not stored in the designated modelRef -)doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_IGeoCoordinateEventHandler_AfterReferenceGeoCoordinationChanged =R"doc(This method is called after a reference has had changes to its
geocoordinated state. For example if it is changed between
" Projected ", " AEC Transform ", and " No ".

:param modelRef:
    (input) The modelRef of the reference that's getting changed.

:param oldState:
    (input) The old state. 0 for no geocoordination, 1 for Projected, 2 for
    AEC transformed.

:param newState:
    (input) The new state. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_IGeoCoordinateEventHandler_BeforeReferenceGeoCoordinationChanged =R"doc(This method is called before a reference geocoordinated state is
changed. For example if it is changed between " Projected ", " AEC Transform ", and " No ".

:param modelRef:
    (input) The modelRef of the reference that's getting changed.

:param oldState:
    (input) The old state. 0 for no geocoordination, 1 for Projected, 2 for
    AEC transformed.

:param newState:
    (input) The new state. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_IGeoCoordinateEventHandler_AfterCoordinateSystemDeleted =R"doc(This method is called after the GeoCoordinate system in a model has
been deleted.

:param currentGCS:
    (input) The GeoCoordinateSystem that was deleted.

:param modelRef:
    (input) The modelRef for which the GCS was deleted.

:param primaryCoordSys:
    (input) true if deleted the primary coordinate system, false if deleted
    the " reference " coordinate system. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_IGeoCoordinateEventHandler_BeforeCoordinateSystemDeleted =R"doc(This method is called before the GeoCoordinate system in a model is
deleted.

:param currentGCS:
    (input) The GeoCoordinateSystem that is about to be deleted.

:param modelRef:
    (input) The modelRef for which the GCS is changing.

:param primaryCoordSys:
    (input) true if deleting the primary coordinate system, false if
    deleting the " reference " coordinate system.

:returns:
    SUCCESS or a nonzero error code to abort deletion of the
    coordinate system. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_IGeoCoordinateEventHandler_AfterCoordinateSystemChanged =R"doc(This method is called after the GeoCoordinate system of a model has
been changed.

:param oldGCS:
    (input) The previous GeoCoordinateSystem (NULL if there is none).

:param newGCS:
    (input) The new GeoCoordinateSystem.

:param modelRef:
    (input) The modelRef for which the GCS changed.

:param primaryCoordSys:
    (input) true if changed the primary coordinate system, false if changed
    the " reference " coordinate system.

:param writtenToFile:
    (input) true if changes written to the file, false if change saved only
    as cached.

:param reprojectData:
    (input) true if the data in the model was reprojected from the existing
    GCS to the new GCS. )doc";

static const char * __doc_Bentley_DgnPlatform_GeoCoordinates_IGeoCoordinateEventHandler_BeforeCoordinateSystemChanged =R"doc(This method is called before the GeoCoordinate system of a model is
changed.

:param oldGCS:
    (input) The existing GeoCoordinateSystem (NULL if there is none).

:param newGCS:
    (input) The new GeoCoordinateSystem.

:param modelRef:
    (input) The modelRef for which the GCS is changing.

:param primaryCoordSys:
    (input) true if changing the primary coordinate system, false if
    changing the " reference " coordinate system.

:param writingToFile:
    (input) true if changes will be written to the file, false if change
    saved only as cached.

:param reprojectData:
    (input) true if the data in the model will be reprojected from the
    existing GCS to the new GCS.

:returns:
    SUCCESS or a nonzero error code to abort the change of the
    coordinate system. )doc";

using namespace GeoCoordinates;

//=======================================================================================
// Trampoline class for IGeoCoordinateEventHandler.
// @bsiclass                                                                   09/23
//=======================================================================================
struct PyIGeoCoordinateEventHandler : IGeoCoordinateEventHandler
    {
    public:
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       9/2023
        +---------------+---------------+---------------+---------------+---------------+------*/    
        virtual StatusInt   BeforeCoordinateSystemChanged(DgnGCSP oldGCS, DgnGCSP newGCS, DgnModelRefP modelRef, bool primaryCoordSys, bool writingToFile, bool reprojectData) override
            { PYBIND11_OVERRIDE_PURE_EXR(StatusInt, IGeoCoordinateEventHandler, BeforeCoordinateSystemChanged, SUCCESS, oldGCS, newGCS, modelRef, primaryCoordSys, writingToFile, reprojectData); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       9/2023
        +---------------+---------------+---------------+---------------+---------------+------*/    
        virtual void        AfterCoordinateSystemChanged(DgnGCSP oldGCS, DgnGCSP newGCS, DgnModelRefP modelRef, bool primaryCoordSys, bool writtenToFile, bool reprojectData) override
            { PYBIND11_OVERRIDE_PURE_EX(void, IGeoCoordinateEventHandler, AfterCoordinateSystemChanged, oldGCS, newGCS, modelRef, primaryCoordSys, writtenToFile, reprojectData); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       9/2023
        +---------------+---------------+---------------+---------------+---------------+------*/    
        virtual StatusInt   BeforeCoordinateSystemDeleted(DgnGCSP currentGCS, DgnModelRefP modelRef, bool primaryCoordSys) override
            { PYBIND11_OVERRIDE_PURE_EXR(StatusInt, IGeoCoordinateEventHandler, BeforeCoordinateSystemDeleted, SUCCESS, currentGCS, modelRef, primaryCoordSys); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       9/2023
        +---------------+---------------+---------------+---------------+---------------+------*/    
        virtual void        AfterCoordinateSystemDeleted(DgnGCSP currentGCS, DgnModelRefP modelRef, bool primaryCoordSys) override
            { PYBIND11_OVERRIDE_PURE_EX(void, IGeoCoordinateEventHandler, AfterCoordinateSystemDeleted, currentGCS, modelRef, primaryCoordSys); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       9/2023
        +---------------+---------------+---------------+---------------+---------------+------*/    
        virtual void        BeforeReferenceGeoCoordinationChanged(DgnModelRefP modelRef, GeoCoordinationState oldState, GeoCoordinationState newState) override
            { PYBIND11_OVERRIDE_PURE_EX(void, IGeoCoordinateEventHandler, BeforeReferenceGeoCoordinationChanged, modelRef, oldState, newState); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       9/2023
        +---------------+---------------+---------------+---------------+---------------+------*/    
        virtual void        AfterReferenceGeoCoordinationChanged(DgnModelRefP modelRef, GeoCoordinationState oldState, GeoCoordinationState newState) override
            { PYBIND11_OVERRIDE_PURE_EX(void, IGeoCoordinateEventHandler, AfterReferenceGeoCoordinationChanged, modelRef, oldState, newState); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       9/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnGCS(py::module_& m)
    {
    //===================================================================================
    // Enum GeoCoordinationState
    py::enum_<GeoCoordinationState>(m, "GeoCoordinationState")
        .value("eNoGeoCoordination", GeoCoordinationState::NoGeoCoordination)
        .value("eReprojected", GeoCoordinationState::Reprojected)
        .value("eAECTransform", GeoCoordinationState::AECTransform)
        .export_values();

    //===================================================================================
    // Enum GeoCoordInterpretation
    py::enum_<GeoCoordInterpretation>(m, "GeoCoordInterpretation")
        .value("eCartesian", GeoCoordInterpretation::Cartesian)
        .value("eXYZ", GeoCoordInterpretation::XYZ)
        .export_values();

    //===================================================================================
    // interface IGeoCoordinateEventHandler
    py::class_< IGeoCoordinateEventHandler, PyIGeoCoordinateEventHandler> c0(m, "IGeoCoordinateEventHandler");
    py::bind_vector< T_GeoCoordEventHandlers>(m, "GeoCoordEventHandlersVector", py::module_local(false));

    c0.def(py::init<>());
    c0.def("BeforeCoordinateSystemChanged", &IGeoCoordinateEventHandler::BeforeCoordinateSystemChanged, "oldGCS"_a, "newGCS"_a, "modelRef"_a, "primaryCoordSys"_a, "writingToFile"_a, "reprojectData"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, IGeoCoordinateEventHandler, BeforeCoordinateSystemChanged));
    c0.def("AfterCoordinateSystemChanged",  &IGeoCoordinateEventHandler::AfterCoordinateSystemChanged,  "oldGCS"_a, "newGCS"_a, "modelRef"_a, "primaryCoordSys"_a, "writingToFile"_a, "reprojectData"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, IGeoCoordinateEventHandler, AfterCoordinateSystemChanged));
    c0.def("BeforeCoordinateSystemDeleted", &IGeoCoordinateEventHandler::BeforeCoordinateSystemDeleted, "currentGCS"_a, "modelRef"_a, "primaryCoordSys"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, IGeoCoordinateEventHandler, BeforeCoordinateSystemDeleted));
    c0.def("AfterCoordinateSystemDeleted",  &IGeoCoordinateEventHandler::AfterCoordinateSystemDeleted, "currentGCS"_a, "modelRef"_a, "primaryCoordSys"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, IGeoCoordinateEventHandler, AfterCoordinateSystemDeleted));
    c0.def("BeforeReferenceGeoCoordinationChanged", &IGeoCoordinateEventHandler::BeforeReferenceGeoCoordinationChanged, "modelRef"_a, "oldState"_a, "newState"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, IGeoCoordinateEventHandler, BeforeReferenceGeoCoordinationChanged));
    c0.def("AfterReferenceGeoCoordinationChanged", &IGeoCoordinateEventHandler::AfterReferenceGeoCoordinationChanged, "modelRef"_a, "oldState"_a, "newState"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, IGeoCoordinateEventHandler, AfterReferenceGeoCoordinationChanged));

    //===================================================================================
    // struct DgnGCS
    py::class_< DgnGCS, BaseGCS, DgnGCSPtr, DgnModelAppData> c1(m, "DgnGCS");

    c1.def_static("CreateGCS", py::overload_cast<WCharCP, DgnModelRefP>(&DgnGCS::CreateGCS), "coordinateSystemName"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, DgnGCS, CreateGCS));
    c1.def_static("CreateGCS", py::overload_cast<DgnModelRefP>(&DgnGCS::CreateGCS), "modelRef"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, DgnGCS, CreateGCS));
    c1.def_static("CreateGCS", py::overload_cast<BaseGCSCP, DgnModelRefP>(&DgnGCS::CreateGCS), "baseGCS"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, DgnGCS, CreateGCS));
    c1.def_static("CreateGCS", py::overload_cast<DgnGCSCR>(&DgnGCS::CreateGCS), "dgnGcs"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, DgnGCS, CreateGCS));

    c1.def("CartesianFromUors", &DgnGCS::CartesianFromUors, "outCartesian"_a, "inUors"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, DgnGCS, CartesianFromUors));
    c1.def("CartesianFromUors2D", &DgnGCS::CartesianFromUors2D, "outCartesian"_a, "inUors"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, DgnGCS, CartesianFromUors2D));
    c1.def("UorsFromCartesian", &DgnGCS::UorsFromCartesian, "outUors"_a, "inCartesian"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, DgnGCS, UorsFromCartesian));
    c1.def("UorsFromCartesian2D", &DgnGCS::UorsFromCartesian2D, "outUors"_a, "inCartesian"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, DgnGCS, UorsFromCartesian2D));
    c1.def("UorsFromLatLong", &DgnGCS::UorsFromLatLong, "outUors"_a, "inLatLong"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, DgnGCS, UorsFromLatLong));
    c1.def("LatLongFromUors", &DgnGCS::LatLongFromUors, "outLatLong"_a, "inUors"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, DgnGCS, LatLongFromUors));
    c1.def("LatLongFromUorsXYZ", &DgnGCS::LatLongFromUorsXYZ, "outLatLong"_a, "inUors"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, DgnGCS, LatLongFromUorsXYZ));

    c1.def("ReprojectUors", [](DgnGCS const& self, DPoint3dCP inUors, int numPoints, DgnGCSCR destMstnGCS)
        {
        ReprojectStatus status;
        DPoint3d outUorsDest; 
        GeoPoint outLatLongDest, outLatLongSrc;

        status = self.ReprojectUors(&outUorsDest, &outLatLongDest, &outLatLongSrc, inUors, numPoints, destMstnGCS);
        return py::make_tuple(status, outUorsDest, outLatLongDest, outLatLongSrc);
        }, "inUors"_a, "numPoints"_a, "destMstnGCS"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, DgnGCS, ReprojectUors));

    c1.def("ReprojectUors", [](DgnGCS const & self, DPoint3dCP inUors, int numPoints, GeoCoordInterpretation interpretation, DgnGCSCR destMstnGCS)
        {
        ReprojectStatus status;
        DPoint3d outUorsDest; 
        GeoPoint outLatLongDest, outLatLongSrc;

        status = self.ReprojectUors(&outUorsDest, &outLatLongDest, &outLatLongSrc, inUors, numPoints, interpretation, destMstnGCS);
        return py::make_tuple(status, outUorsDest, outLatLongDest, outLatLongSrc);
        }, "inUors"_a, "numPoints"_a, "interpretation"_a, "destMstnGCS"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, DgnGCS, ReprojectUors));

    c1.def("UorsFromLatLong2D", &DgnGCS::UorsFromLatLong2D, "outUors"_a, "inLatLong"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, DgnGCS, UorsFromLatLong2D));
    c1.def("LatLongFromUors2D", &DgnGCS::LatLongFromUors2D, "outLatLong"_a, "inUors"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, DgnGCS, LatLongFromUors2D));

    c1.def("ReprojectUors2D", [](DgnGCS& self, DPoint2dCP inUors, int numPoints, DgnGCSCR destMstnGCS)
        {
        ReprojectStatus status;
        DPoint2d outUorsDest; 
        GeoPoint2d outLatLongDest, outLatLongSrc;

        status = self.ReprojectUors2D(&outUorsDest, &outLatLongDest, &outLatLongSrc, inUors, numPoints, destMstnGCS);
        return py::make_tuple(status, outUorsDest, outLatLongDest, outLatLongSrc);
        }, "inUors"_a, "numPoints"_a, "destMstnGCS"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, DgnGCS, ReprojectUors2D));

    c1.def("GetLinearTransformToBaseGCS", [](DgnGCS& self, DRange3dCR extent, BaseGCSCR destBaseGCS)
        {
        ReprojectStatus status;
        Transform  outTransform;
        double maxError, meanError;

        status = self.GetLinearTransformToBaseGCS(&outTransform, extent, destBaseGCS, &maxError, &meanError);
        return py::make_tuple(status, outTransform, maxError, meanError);
        }, "extent"_a, "destBaseGCS"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, DgnGCS, GetLinearTransformToBaseGCS));

    c1.def("GetLocalTransform", py::overload_cast<TransformP, DPoint3dCR, DPoint3dCP, bool, bool, DgnGCSCR>(&DgnGCS::GetLocalTransform, py::const_),
                                "outTransform"_a, "elementOrigin"_a, "extent"_a, "doRotate"_a, "doScale"_a, "destMstnGCS"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, DgnGCS, GetLocalTransform));

    c1.def("GetLocalTransform", py::overload_cast<TransformP, DPoint3dCR, DPoint3dCP, bool, bool, GeoCoordInterpretation, DgnGCSCR>(&DgnGCS::GetLocalTransform, py::const_),
        "outTransform"_a, "elementOrigin"_a, "extent"_a, "doRotate"_a, "doScale"_a, "interpretation"_a, "destMstnGCS"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, DgnGCS, GetLocalTransform));

    c1.def("GetProjectionName", &DgnGCS::GetProjectionName, "outputBuffer"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, DgnGCS, GetProjectionName));
    c1.def("GetDisplayName", &DgnGCS::GetDisplayName, "outputBuffer"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, DgnGCS, GetDisplayName));

    c1.def("ToModel", &DgnGCS::ToModel, "modelRef"_a, "primaryCoordSys"_a, "writeToFile"_a, "reprojectData"_a, "reportProblems"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, DgnGCS, ToModel));

    c1.def_static("FromModel", &DgnGCS::FromModel, "modelRef"_a, "primaryCoordSys"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, DgnGCS, FromModel));
    c1.def_static("DeleteFromModel", &DgnGCS::DeleteFromModel, "modelRef"_a, "primaryCoordSys"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, DgnGCS, DeleteFromModel));
    c1.def_static("FromCache", &DgnGCS::FromCache, "cache"_a, "primaryCoordSys"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, DgnGCS, FromCache));
    c1.def_static("ReloadGeoReferences", &DgnGCS::ReloadGeoReferences, "modelRef"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, DgnGCS, ReloadGeoReferences));

    c1.def_static("SetEventHandler", &DgnGCS::SetEventHandler, "handler"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, DgnGCS, SetEventHandler));
    c1.def_static("RemoveEventHandler", &DgnGCS::RemoveEventHandler, "handler"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, DgnGCS, RemoveEventHandler));

    c1.def("GetPaperScale", &DgnGCS::GetPaperScale, DOC(Bentley, DgnPlatform, GeoCoordinates, DgnGCS, GetPaperScale));
    c1.def("SetPaperScale", &DgnGCS::SetPaperScale, "paperScale"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, GeoCoordinates, DgnGCS, SetPaperScale));
    }
