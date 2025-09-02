/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgnectypes.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnECTypes.h>
#include <functional>



static const char * __doc_Bentley_DgnPlatform_DgnECUnit_FromID =R"doc(Initialize from invariant ID.

:param id:
    Invariant ID string

:returns:
    A DgnECUnit corresponding to the invariant ID. Does not validate
    ECUnit names against the schema.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECUnit_GetID =R"doc(:returns:
    the invariant ID of this unit.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECUnit_GetWorkingUnit =R"doc(:returns:
    the working unit associated with this DgnECUnit)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECUnit_GetECUnitName =R"doc(:returns:
    the name of the ECUnit, or NULL if not an ECUnit)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECUnit_IsWorkingUnit =R"doc(:returns:
    true if this unit specifies a working unit)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECUnit_IsECUnit =R"doc(:returns:
    true if this unit represents an ECUnit. Does not validate the unit
    name actually exists in the standard units schema)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECUnit_IsSpecified =R"doc(:returns:
    true if this unit represents an ECUnit or a Working Unit)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnECTypeAdapter_GetForArrayMember =R"doc(Obtain a type adapter for members of the specified array property. If
the property specifies a MemberExtendedType custom attribute, it will
be used to locate the type adapter.

:param arrayProperty:
    The array property for which to obtain a member type adapter

:returns:
    a type adapter for members of the specified array property)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnECTypeAdapter_GetForProperty =R"doc(Obtain a type adapter for the specified property. If the property
specifies an ExtendType custom attribute, it will be used to locate
the type adapter.

:param ecProperty:
    The property for which to obtain a type adapter

:returns:
    a type adapter for the specified property)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnECTypeAdapter_GetStandardValues =R"doc(Get a list of strings representing permissible values for this
property

:param values:
    Permissible values, as a list of user-friendly strings

:param context:
    The context under which to evaluate

:returns:
    true if the list of permissible values was populated successfully)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnECTypeAdapter_Validate =R"doc(Determine if the proposed value is valid for the ECProperty specified
by the context

:param v:
    The proposed value

:param context:
    The context in which to evaluate

:returns:
    true if the value is valid for the property)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnECStandaloneTypeAdapterContext_ReInitialize =R"doc(Re-initialize this context If instance can be cast to DgnECInstance
and the file/modelRef/elemRef arguments are NULL, they will be taken
from the DgnECInstance

:param ecproperty:
    The ECProperty the type adapter will operate on

:param instance:
    The IECInstance which will supply the property values

:param accessString:
    The access string of the property within the instance.

:param componentIndex:
    For point properties, the component index (x=0,y=1,z=2) if the
    type adapter should operate only on a single component of the
    point

:param dgnFile:
    The DgnFile from which the property value originated

:param modelRef:
    The DgnModelRef associated with the property value

:param elemRef:
    The ElementRef associated with the property value

:returns:
    true if the context was successfully re-initialized)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnECTypeAdapterContext_CreateStandalone =R"doc(Create a context for an IECInstance. If the instance can be cast to
DgnECInstance and the file/modelRef/elemRef arguments are NULL, they
will be taken from the DgnECInstance Standalone contexts can be re-
initialized and re-used, which is useful for avoiding repeated
allocations.

:param ecproperty:
    The ECProperty the type adapter will operate on

:param instance:
    The IECInstance which will supply the property values

:param accessString:
    The access string of the property within the instance.

:param componentIndex:
    For point properties, the component index (x=0,y=1,z=2) if the
    type adapter should operate only on a single component of the
    point

:param dgnFile:
    The DgnFile from which the property value originated

:param modelRef:
    The DgnModelRef associated with the property value

:param elemRef:
    The ElementRef associated with the property value

:returns:
    a reusable context which can be passed to an IDgnECTypeAdapter)doc";


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnECTypes(py::module_& m)
    {
    //===================================================================================
    // struct DgnECExtendedType
    py::class_< DgnECExtendedType> c1(m, "DgnECExtendedType");

    if (true)
        {
        //===================================================================================
        // enum StandardType
        py::enum_< DgnECExtendedType::StandardType>(c1, "StandardType", py::arithmetic())
            .value("eElementType", DgnECExtendedType::ElementType)
            .value("eLevel", DgnECExtendedType::Level)
            .value("eColor", DgnECExtendedType::Color)
            .value("eWeight", DgnECExtendedType::Weight)
            .value("eStyle", DgnECExtendedType::Style)
            .value("eElementClass", DgnECExtendedType::ElementClass)
            .value("eCoordinates", DgnECExtendedType::Coordinates)
            .value("eDistance", DgnECExtendedType::Distance)
            .value("eArea", DgnECExtendedType::Area)
            .value("eVolume", DgnECExtendedType::Volume)
            .value("eAngle", DgnECExtendedType::Angle)
            .value("eTextStyle", DgnECExtendedType::TextStyle)
            .value("eRenderingMaterial", DgnECExtendedType::RenderingMaterial)
            .value("eDirectionAngle", DgnECExtendedType::DirectionAngle)
            .value("eUnitlessPoint", DgnECExtendedType::UnitlessPoint)
            .value("eNamedScale", DgnECExtendedType::NamedScale)
            .value("eProjectionNamedGroup", DgnECExtendedType::ProjectionNamedGroup)            
            .value("eFileSize", DgnECExtendedType::FileSize)
            .value("eFileSizeLong", DgnECExtendedType::FileSizeLong)
            .value("eDisplayPriority", DgnECExtendedType::DisplayPriority)
            .value("eFontName", DgnECExtendedType::FontName)
            .value("eBigFontName", DgnECExtendedType::BigFontName)
            .value("eElementID", DgnECExtendedType::ElementID)
            .value("eHatchCell", DgnECExtendedType::HatchCell)
            .value("eXyzRotations", DgnECExtendedType::XyzRotations)
            .value("eUnitDefinition", DgnECExtendedType::UnitDefinition)
            .export_values();
        }

    //===================================================================================
    // struct IDgnECTypeAdapterContext
    py::class_< IDgnECTypeAdapterContext, IDgnECTypeAdapterContextPtr, ECN::IECTypeAdapterContext> c2(m, "IDgnECTypeAdapterContext");    

    c2.def(py::init(&IDgnECTypeAdapterContext::Create), "ecproperty"_a, "instance"_a, "accessString"_a, "componentIndex"_a = ECN::IECTypeAdapterContext::COMPONENT_INDEX_None);

    c2.def_static("CreateStandalone",
                  py::overload_cast<ECN::ECPropertyCR, ECN::IECInstanceCR, WCharCP, UInt32, DgnFileP, DgnModelRefP, ElementRefP>(&IDgnECTypeAdapterContext::CreateStandalone),
                  "ecproperty"_a, "instance"_a, "accessString"_a, "componentIndex"_a = ECN::IECTypeAdapterContext::COMPONENT_INDEX_None, "dgnFile"_a = nullptr,
                  "modelRef"_a = nullptr, "elemRef"_a = nullptr, DOC(Bentley, DgnPlatform, IDgnECTypeAdapterContext, CreateStandalone));

    //===================================================================================
    // struct IDgnECStandaloneTypeAdapterContext
    py::class_< IDgnECStandaloneTypeAdapterContext, IDgnECStandaloneTypeAdapterContextPtr, IDgnECTypeAdapterContext> c3(m, "IDgnECStandaloneTypeAdapterContext");

    c3.def("ReInitialize",
           &IDgnECStandaloneTypeAdapterContext::ReInitialize,
           "ecproperty"_a, "instance"_a, "accessString"_a, "componentIndex"_a = ECN::IECTypeAdapterContext::COMPONENT_INDEX_None, "dgnFile"_a = nullptr,
           "modelRef"_a = nullptr, "elemRef"_a = nullptr, DOC(Bentley, DgnPlatform, IDgnECStandaloneTypeAdapterContext, ReInitialize));        

    py::class_< IDgnECTypeAdapter, RefCountedPtr<IDgnECTypeAdapter> > c4(m, "IDgnECTypeAdapter");

    c4.def("Validate", &IDgnECTypeAdapter::Validate, "v"_a, "context"_a, DOC(Bentley, DgnPlatform, IDgnECTypeAdapter, Validate));
    c4.def("GetStandardValues", &IDgnECTypeAdapter::GetStandardValues, "values"_a, "context"_a, DOC(Bentley, DgnPlatform, IDgnECTypeAdapter, GetStandardValues));
    c4.def_static("GetForProperty", &IDgnECTypeAdapter::GetForProperty, "ecProperty"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, IDgnECTypeAdapter, GetForProperty));
    c4.def_static("GetForArrayMember", &IDgnECTypeAdapter::GetForArrayMember, "arrayProperty"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, IDgnECTypeAdapter, GetForArrayMember));
    

    //===================================================================================
    // struct DgnECUnit
    py::class_< DgnECUnit> c6(m, "DgnECUnit");

    if (true)
        {
        //===================================================================================
        // enum WorkingUnit
        py::enum_<DgnECUnit::WorkingUnit>(c6, "WorkingUnit", py::arithmetic())
            .value("eDistance", DgnECUnit::Distance)
            .value("eArea", DgnECUnit::Area)
            .value("eVolume", DgnECUnit::Volume)
            .value("eAngle", DgnECUnit::Angle)
            .value("eUnspecified", DgnECUnit::Unspecified)
            .export_values();
        }

    c6.def(py::init<DgnECUnit::WorkingUnit>(), "workingUnit"_a = DgnECUnit::Unspecified);
    c6.def(py::init<WCharCP>(), "standardECUnitName"_a );

    c6.def("IsSpecified", &DgnECUnit::IsSpecified, DOC(Bentley, DgnPlatform, DgnECUnit, IsSpecified));
    c6.def("IsECUnit", &DgnECUnit::IsECUnit, DOC(Bentley, DgnPlatform, DgnECUnit, IsECUnit));
    c6.def("IsWorkingUnit", &DgnECUnit::IsWorkingUnit, DOC(Bentley, DgnPlatform, DgnECUnit, IsWorkingUnit));
    
    c6.def_property_readonly("ECUnitName", &DgnECUnit::GetECUnitName);
    c6.def("GetECUnitName", &DgnECUnit::GetECUnitName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnECUnit, GetECUnitName));
    
    c6.def_property_readonly("WorkingUnit", &DgnECUnit::GetWorkingUnit);
    c6.def("GetWorkingUnit", &DgnECUnit::GetWorkingUnit, DOC(Bentley, DgnPlatform, DgnECUnit, GetWorkingUnit));
    
    c6.def_property_readonly("ID", &DgnECUnit::GetID);
    c6.def("GetID", &DgnECUnit::GetID, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnECUnit, GetID));
    
    c6.def_static("FromID", &DgnECUnit::FromID, "id"_a, DOC(Bentley, DgnPlatform, DgnECUnit, FromID));
    }
