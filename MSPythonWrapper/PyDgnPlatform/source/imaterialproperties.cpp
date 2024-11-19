/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\imaterialproperties.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/IMaterialProperties.h>



static const char * __doc_Bentley_DgnPlatform_IMaterialPropertiesExtension_DeleteElementProjection =R"doc(Remove a projection from an element

Parameter ``eeh``:
    source element to remove the projection from

Returns:
    SUCCESS if the projection was removed Bentley Systems +-----------
    ----+---------------+---------------+---------------+-------------
    --+------)doc";

static const char * __doc_Bentley_DgnPlatform_IMaterialPropertiesExtension_AddElementProjection =R"doc(Add a projection to this element

Parameter ``eeh``:
    source element to attach the projection to

Parameter ``offset``:
    the projection offset from the element origin

Parameter ``scale``:
    the projection scale this is a factor based on the element size

Parameter ``angles``:
    the rotation applied to the projection relative to the orientation
    of the element

Parameter ``mode``:
    the type of projection to apply this parameter must be either
    MapMode::DirectionalDrape, MapMode::Cubic, MapMode::Spherical,
    MapMode::Cylindrical

Parameter ``variant``:
    any variation to the default settings for the mode

Returns:
    SUCCESS if the projection was attached Bentley Systems +----------
    -----+---------------+---------------+---------------+------------
    ---+------)doc";

static const char * __doc_Bentley_DgnPlatform_IMaterialPropertiesExtension_GetMaterialProjectionParameters =R"doc(Extract the paramaters relating to the projection and the element

Parameter ``eh``:
    source element to query

Parameter ``type``:
    the material attachment type to query the data for

Parameter ``units``:
    the units of the material layer associated with this projection

Parameter ``params``:
    the calculated parameters of the attached projection

Returns:
    SUCCESS if the projection is attached to the element and the
    parameters can be calculated Bentley Systems +---------------+----
    -----------+---------------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_IMaterialPropertiesExtension_FindMaterialProjection =R"doc(Find which projection if any is associated with this element

Parameter ``eh``:
    source element to query

Returns:
    The type of projection attactment found Bentley Systems +---------
    ------+---------------+---------------+---------------+-----------
    ----+------)doc";

static const char * __doc_Bentley_DgnPlatform_IMaterialPropertiesExtension_DetachSubEntityMaterial =R"doc(Detach a material from a component of an element. Note:Extension
Implementors must call the appropriate IMaterialListener method for
valid dettachments

Parameter ``eeh``:
    source element to be modified

Parameter ``subEntities``:
    sub entities to remove the material attachments from

Returns:
    SUCCESS if the dettachment was made Bentley Systems +-------------
    --+---------------+---------------+---------------+---------------
    +------)doc";

static const char * __doc_Bentley_DgnPlatform_IMaterialPropertiesExtension_AttachSubEntityMaterial =R"doc(Attach a material to a component of an element. As an example this
method should be used for attaching materials to faces of solids. It
is best to associate the ElementId identifier component of the
MaterialId object passed in with the EditElementHandle, as this avoids
mateial changes when materials are renamed. Note:Extension
Implementors must call the appropriate IMaterialListener method for
valid attachments

Parameter ``eeh``:
    source element to be modified

Parameter ``subEntities``:
    sub entities to attach the material to

Parameter ``materialId``:
    material to be associated with the subEntity

Returns:
    SUCCESS if the attachment was made Bentley Systems +--------------
    -+---------------+---------------+---------------+---------------+
    ------)doc";

static const char * __doc_Bentley_DgnPlatform_IMaterialPropertiesExtension_GetSubEntityAttachments =R"doc(Fill in a map of material attachments to sub components of this
element.

Parameter ``eh``:
    The element to query.

Parameter ``attachments``:
    A vector containing WString, materialId pairs of attachments to
    sub elements

Returns:
    SUCCESS if the method is succeded Bentley Systems +---------------
    +---------------+---------------+---------------+---------------+-
    -----)doc";

static const char * __doc_Bentley_DgnPlatform_IMaterialPropertiesExtension_HasSubEntityAttachments =R"doc(Query if this element has multiple materials associated with it

Parameter ``eh``:
    The element to query.

Returns:
    true if there are multiple materials associated with this element,
    false otherwise Bentley Systems +---------------+---------------+-
    --------------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_IMaterialPropertiesExtension_SupportsSubEntityAttachments =R"doc(Query whether the element has the ability to associate multiple
materials with itself

Parameter ``eh``:
    The element to query.

Returns:
    true if multiple materials can be associated with this element,
    false otherwise Bentley Systems +---------------+---------------+-
    --------------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_IMaterialPropertiesExtension_DeleteMaterialAttachment =R"doc(Delete a material attachment from an element.

Parameter ``eeh``:
    The element detach the material from.

Returns:
    SUCCESS if the attachment was removed Bentley Systems +-----------
    ----+---------------+---------------+---------------+-------------
    --+------)doc";

static const char * __doc_Bentley_DgnPlatform_IMaterialPropertiesExtension_AddMaterialAttachment =R"doc(Associate a material with an element via a material attachment.

Parameter ``eeh``:
    The element attach the material to.

Parameter ``materialId``:
    The material associated with the attachment

Returns:
    SUCCESS if the attachment was made Bentley Systems +--------------
    -+---------------+---------------+---------------+---------------+
    ------)doc";

static const char * __doc_Bentley_DgnPlatform_IMaterialPropertiesExtension_FindMaterial =R"doc(Query whether the element has a material associated with it. This will
resolve the element's effective material, based on the priority of
material assignments, attachments, overrides, etc. This pointer is
valid only as long as the element's design file remains loaded and the
material is not modified by another caller.

Parameter ``eh``:
    The element to query.

Parameter ``level``:
    The effective level of the element. Because of overrides, this may
    differ from the level declared in the ElementHandle.

Parameter ``colorIndex``:
    The effective color of the element. Because of overrides, this may
    differ from the color declared in the ElementHandle.

Parameter ``renderModelRef``:
    The model that this material will be used with - needed to
    determine the scaling for maps that make use of real world units.

Parameter ``useSymbologyOverride``:
    Specifies whether the lookup will search for an override material
    or a by-level material.

Returns:
    The material associated with the element. Bentley Systems +-------
    --------+---------------+---------------+---------------+---------
    ------+------)doc";

static const char * __doc_Bentley_DgnPlatform_IMaterialPropertiesExtension_StoresAttachmentInfo =R"doc(Query if an element has an attachment associated with it. It can be
that the element has an attachment but the material for that
attachment no longer exists. This method will populate the MaterialId
passed in with either the ElementId of the internal attachment for the
missing material if the stored attachment is internal. Or the name of
the missing material if the attachment type stored is a linkage

Parameter ``eh``:
    The element to query.

Parameter ``id``:
    The id to populate with the information

Returns:
    SUCCESS if attachment information is stored for this element
    Bentley Systems +---------------+---------------+---------------+-
    --------------+---------------+------)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_IMaterialProperties(py::module_& m)
    {
    //===================================================================================
    // struct IMaterialPropertiesExtension
    py::class_< IMaterialPropertiesExtension, Handler::Extension> c1(m, "IMaterialPropertiesExtension", py::multiple_inheritance());

    c1.def("FindMaterialAttachment", &IMaterialPropertiesExtension::FindMaterialAttachment, "eh"_a, "renderModelRef"_a, py::return_value_policy::reference_internal);
    c1.def("StoresAttachmentInfo", &IMaterialPropertiesExtension::StoresAttachmentInfo, "eh"_a, "id"_a, DOC(Bentley, DgnPlatform, IMaterialPropertiesExtension, StoresAttachmentInfo));
    c1.def("FindMaterial", &IMaterialPropertiesExtension::FindMaterial, "eh"_a, "levelId"_a, "colorIndex"_a, "renderModelRef"_a, "useSymbologyOverride"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, IMaterialPropertiesExtension, FindMaterial));
    c1.def("AddMaterialAttachment", &IMaterialPropertiesExtension::AddMaterialAttachment, "eeh"_a, "materialId"_a, DOC(Bentley, DgnPlatform, IMaterialPropertiesExtension, AddMaterialAttachment));
    c1.def("DeleteMaterialAttachment", &IMaterialPropertiesExtension::DeleteMaterialAttachment, "eeh"_a, DOC(Bentley, DgnPlatform, IMaterialPropertiesExtension, DeleteMaterialAttachment));
    c1.def("SupportsSubEntityAttachments", &IMaterialPropertiesExtension::SupportsSubEntityAttachments, "eh"_a, DOC(Bentley, DgnPlatform, IMaterialPropertiesExtension, SupportsSubEntityAttachments));
    c1.def("HasSubEntityAttachments", &IMaterialPropertiesExtension::HasSubEntityAttachments, "eh"_a, DOC(Bentley, DgnPlatform, IMaterialPropertiesExtension, HasSubEntityAttachments));
    c1.def("GetSubEntityAttachments", &IMaterialPropertiesExtension::GetSubEntityAttachments, "eh"_a, "attachments"_a, DOC(Bentley, DgnPlatform, IMaterialPropertiesExtension, GetSubEntityAttachments));
    c1.def("AttachSubEntityMaterial", &IMaterialPropertiesExtension::AttachSubEntityMaterial, "eeh"_a, "subEntities"_a, "materialId"_a, DOC(Bentley, DgnPlatform, IMaterialPropertiesExtension, AttachSubEntityMaterial));
    c1.def("DetachSubEntityMaterial", &IMaterialPropertiesExtension::DetachSubEntityMaterial, "eh"_a, "subentities"_a, DOC(Bentley, DgnPlatform, IMaterialPropertiesExtension, DetachSubEntityMaterial));
    c1.def("FindMaterialProjection", &IMaterialPropertiesExtension::FindMaterialProjection, "eh"_a, DOC(Bentley, DgnPlatform, IMaterialPropertiesExtension, FindMaterialProjection));
    c1.def("GetMaterialProjectionParameters", &IMaterialPropertiesExtension::GetMaterialProjectionParameters, "eh"_a, "type"_a, "units"_a, "params"_a, DOC(Bentley, DgnPlatform, IMaterialPropertiesExtension, GetMaterialProjectionParameters));
    c1.def("AddElementProjection", &IMaterialPropertiesExtension::AddElementProjection, "eeh"_a, "offset"_a, "scale"_a, "angles"_a, "mode"_a, "variant"_a, DOC(Bentley, DgnPlatform, IMaterialPropertiesExtension, AddElementProjection));
    c1.def("DeleteElementProjection", &IMaterialPropertiesExtension::DeleteElementProjection, "eeh"_a, DOC(Bentley, DgnPlatform, IMaterialPropertiesExtension, DeleteElementProjection));

    c1.def_static ("Cast", &IMaterialPropertiesExtension::Cast, py::return_value_policy::reference_internal);

    }