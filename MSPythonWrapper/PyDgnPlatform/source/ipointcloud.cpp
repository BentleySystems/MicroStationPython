/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\ipointcloud.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/IPointCloud.h>



static const char * __doc_Bentley_DgnPlatform_IPointCloudEdit_SetPointCloudClipProperties =R"doc(Sets the PointCloudClipProperties on an element.

Parameter ``eeh``:
    Element on which the PointCloudClipProperties are set.

Parameter ``props``:
    PointCloudClipProperties to set on the element.

Returns:
    SUCCESS or ERROR.)doc";

static const char * __doc_Bentley_DgnPlatform_IPointCloudEdit_SetPointCloudProperties =R"doc(Sets the PointCloudProperties on an element.

Parameter ``eeh``:
    Element on which the PointCloudProperties are set.

Parameter ``props``:
    PointCloudProperties to set on the element.

Returns:
    SUCCESS or ERROR.)doc";

static const char * __doc_Bentley_DgnPlatform_IPointCloudQuery_GetPointCloudClipProperties =R"doc(Gets the PointCloudClipProperties associated to the provided element.

Parameter ``eh``:
    Element from which the PointCloudClipProperties are extracted.

Returns:
    Point cloud clip properties.)doc";

static const char * __doc_Bentley_DgnPlatform_IPointCloudQuery_GetPointCloudProperties =R"doc(Gets the PointCloudProperties associated to the provided element.

Parameter ``eh``:
    Element from which the PointCloudProperties are extracted.

Returns:
    Point cloud properties.)doc";

static const char * __doc_Bentley_DgnPlatform_PointCloudProperties_SetGlobalOrigin =R"doc(Sets translation factor between points coordinates and UOR.

Parameter ``val``:
    Global origin.)doc";

static const char * __doc_Bentley_DgnPlatform_PointCloudProperties_GetGlobalOrigin =R"doc(Gets translation factor between points coordinates and UOR.

Returns:
    Global origin.)doc";

static const char * __doc_Bentley_DgnPlatform_PointCloudProperties_SetUorPerMeter =R"doc(Sets scale factor between points coordinates and UOR.

Parameter ``val``:
    UOR per meter.)doc";

static const char * __doc_Bentley_DgnPlatform_PointCloudProperties_GetUorPerMeter =R"doc(Gets scale factor between points coordinates and UOR.

Returns:
    UOR per meter.)doc";

static const char * __doc_Bentley_DgnPlatform_PointCloudProperties_SetViewDensity =R"doc(Sets the density of a point cloud. This represents the density of
points displayed for this point cloud. Default is 1.0.

Parameter ``density``:
    The view density expressed as percentage (a float value between
    0.0 and 1.0).)doc";

static const char * __doc_Bentley_DgnPlatform_PointCloudProperties_GetViewDensity =R"doc(Gets the density of a point cloud. This represents the density of
points displayed for this point cloud.

Returns:
    The density (a float value between 0.0 and 1.0).)doc";

static const char * __doc_Bentley_DgnPlatform_PointCloudProperties_SetViewState =R"doc(Sets if the point cloud is displayed in a specific view.

Parameter ``state``:
    Set to true to display in the view.

Parameter ``viewNumber``:
    The view number to query [0..7].)doc";

static const char * __doc_Bentley_DgnPlatform_PointCloudProperties_GetViewState =R"doc(Indicates if the point cloud is displayed in a specific view.

Parameter ``viewNumber``:
    The view number to query [0..7].

Returns:
    true if the point cloud is displayed in the specified view.)doc";

static const char * __doc_Bentley_DgnPlatform_PointCloudProperties_SetDescription =R"doc(Sets the description of the point cloud.

Parameter ``description``:
    Description of the point cloud.)doc";

static const char * __doc_Bentley_DgnPlatform_PointCloudProperties_GetDescription =R"doc(Gets the description of the point cloud.

Returns:
    Description of the point cloud.)doc";

static const char * __doc_Bentley_DgnPlatform_PointCloudProperties_SetLockedGeoReference =R"doc(Sets georeference lock state.

Parameter ``isLocked``:
    If true, locks the point cloud's geoReference.)doc";

static const char * __doc_Bentley_DgnPlatform_PointCloudProperties_GetLockedGeoReference =R"doc(Returns Indicates if the point cloud's geoReference can be changed.

Returns:
    true if the point cloud's geoReference can be changed; false
    otherwise.)doc";

static const char * __doc_Bentley_DgnPlatform_PointCloudProperties_SetLocate =R"doc(Sets locate state.

Parameter ``isOn``:
    If true, sets the point cloud as locatable.)doc";

static const char * __doc_Bentley_DgnPlatform_PointCloudProperties_GetLocate =R"doc(Indicates if the point cloud is locatable.

Returns:
    true if the point cloud is locatable; false otherwise.)doc";

static const char * __doc_Bentley_DgnPlatform_PointCloudProperties_SetFileMoniker =R"doc(Sets the moniker that identifies the point cloud file. Will add a
reference to the DgnDocumentMoniker.

Parameter ``moniker``:
    The DgnDocumentMoniker that identifies the point cloud file.)doc";

static const char * __doc_Bentley_DgnPlatform_PointCloudProperties_GetFileMoniker =R"doc(Gets the moniker that identifies the point cloud file.

Returns:
    A moniker.)doc";

static const char * __doc_Bentley_DgnPlatform_PointCloudProperties_GetTransform =R"doc(Gets the transformation matrix.

Returns:
    A transformation matrix.)doc";

static const char * __doc_Bentley_DgnPlatform_PointCloudProperties_Create =R"doc(Creates an instance of a PointCloudProperties.

Returns:
    An instance of a PointCloudProperties.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_IPointCloud(py::module_& m)
    {
    //===================================================================================
    // struct PointCloudProperties
    py::class_< PointCloudProperties, PointCloudPropertiesPtr> c1(m, "PointCloudProperties");

    c1.def_static("Create", py::overload_cast<>(&PointCloudProperties::Create), DOC(Bentley, DgnPlatform, PointCloudProperties, Create));
    c1.def_static("Create", py::overload_cast<ElementRefP>(&PointCloudProperties::Create), "elRef"_a, DOC(Bentley, DgnPlatform, PointCloudProperties, Create));
    c1.def_static("Create", py::overload_cast<DgnDocumentMonikerR, DgnModelRefCR>(&PointCloudProperties::Create), "moniker"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, PointCloudProperties, Create));
    
    c1.def_property_readonly("Transform", &PointCloudProperties::GetTransform);
    c1.def("GetTransform", &PointCloudProperties::GetTransform, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, PointCloudProperties, GetTransform));

    c1.def_property("FileMoniker", &PointCloudProperties::GetFileMoniker, &PointCloudProperties::SetFileMoniker);
    c1.def("GetFileMoniker", &PointCloudProperties::GetFileMoniker, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, PointCloudProperties, GetFileMoniker));
    c1.def("SetFileMoniker", &PointCloudProperties::SetFileMoniker, "moniker"_a, DOC(Bentley, DgnPlatform, PointCloudProperties, SetFileMoniker));
    
    c1.def_property("Locate", &PointCloudProperties::GetLocate, &PointCloudProperties::SetLocate);
    c1.def("GetLocate", &PointCloudProperties::GetLocate, DOC(Bentley, DgnPlatform, PointCloudProperties, GetLocate));
    c1.def("SetLocate", &PointCloudProperties::SetLocate, "isOn"_a, DOC(Bentley, DgnPlatform, PointCloudProperties, SetLocate));
    
    c1.def_property("LockedGeoReference", &PointCloudProperties::GetLockedGeoReference, &PointCloudProperties::SetLockedGeoReference);
    c1.def("GetLockedGeoReference", &PointCloudProperties::GetLockedGeoReference, DOC(Bentley, DgnPlatform, PointCloudProperties, GetLockedGeoReference));
    c1.def("SetLockedGeoReference", &PointCloudProperties::SetLockedGeoReference, "isLocked"_a, DOC(Bentley, DgnPlatform, PointCloudProperties, SetLockedGeoReference));
    
    c1.def_property("Description", &PointCloudProperties::GetDescription, &PointCloudProperties::SetDescription);
    c1.def("GetDescription", &PointCloudProperties::GetDescription, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, PointCloudProperties, GetDescription));
    c1.def("SetDescription", &PointCloudProperties::SetDescription, "description"_a, DOC(Bentley, DgnPlatform, PointCloudProperties, SetDescription));
    
    c1.def("GetViewState", &PointCloudProperties::GetViewState, "viewNumber"_a, DOC(Bentley, DgnPlatform, PointCloudProperties, GetViewState));
    c1.def("SetViewState", &PointCloudProperties::SetViewState, "viewNumber"_a, "state"_a, DOC(Bentley, DgnPlatform, PointCloudProperties, SetViewState));
    
    c1.def_property("ViewDensity", &PointCloudProperties::GetViewDensity, &PointCloudProperties::SetViewDensity);
    c1.def("GetViewDensity", &PointCloudProperties::GetViewDensity, DOC(Bentley, DgnPlatform, PointCloudProperties, GetViewDensity));
    c1.def("SetViewDensity", &PointCloudProperties::SetViewDensity, "density"_a, DOC(Bentley, DgnPlatform, PointCloudProperties, SetViewDensity));
    
    c1.def_property("UorPerMeter", &PointCloudProperties::GetUorPerMeter, &PointCloudProperties::SetUorPerMeter);
    c1.def("GetUorPerMeter", &PointCloudProperties::GetUorPerMeter, DOC(Bentley, DgnPlatform, PointCloudProperties, GetUorPerMeter));
    c1.def("SetUorPerMeter", &PointCloudProperties::SetUorPerMeter, "value"_a, DOC(Bentley, DgnPlatform, PointCloudProperties, SetUorPerMeter));
    
    c1.def_property("GlobalOrigin", &PointCloudProperties::GetGlobalOrigin, &PointCloudProperties::SetGlobalOrigin);
    c1.def("GetGlobalOrigin", &PointCloudProperties::GetGlobalOrigin, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, PointCloudProperties, GetGlobalOrigin));
    c1.def("SetGlobalOrigin", &PointCloudProperties::SetGlobalOrigin, "pt"_a, DOC(Bentley, DgnPlatform, PointCloudProperties, SetGlobalOrigin));

    //===================================================================================
    // struct IPointCloudQuery
    py::class_ < IPointCloudQuery, std::unique_ptr< IPointCloudQuery, py::nodelete> > c2(m, "IPointCloudQuery");

    c2.def("GetPointCloudProperties", &IPointCloudQuery::GetPointCloudProperties, "eh"_a, DOC(Bentley, DgnPlatform, IPointCloudQuery, GetPointCloudProperties));
    c2.def("GetPointCloudClipProperties", &IPointCloudQuery::GetPointCloudClipProperties, "eh"_a, DOC(Bentley, DgnPlatform, IPointCloudQuery, GetPointCloudClipProperties));

    //===================================================================================
    // struct IPointCloudEdit
    py::class_< IPointCloudEdit, std::unique_ptr< IPointCloudEdit, py::nodelete>, IPointCloudQuery> c3(m, "IPointCloudEdit");

    c3.def("SetPointCloudProperties", &IPointCloudEdit::SetPointCloudProperties, "eeh"_a, "props"_a, DOC(Bentley, DgnPlatform, IPointCloudEdit, SetPointCloudProperties));
    c3.def("SetPointCloudClipProperties", &IPointCloudEdit::SetPointCloudClipProperties, "eeh"_a, "props"_a, DOC(Bentley, DgnPlatform, IPointCloudEdit, SetPointCloudClipProperties));
    }