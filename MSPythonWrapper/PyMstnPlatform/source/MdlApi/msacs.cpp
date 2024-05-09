/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MdlApi\msacs.cpp $
|"mdlLevel_
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/MdlApi/msacs.fdf>



static const char * __doc_MstnPlatform_ACS_CreateElmdscrFromParams =R"doc(@description Creates an ACS element descriptor from the given
parameters.

Parameter ``edPP``:
    is the newly created ACS element descriptor, which you must free
    when done.

Parameter ``type``:
    is one of the valid ACS type constants. Possible values are:<UL>
    <LI>ACS_TYPE_NONE <LI>ACS_TYPE_RECT <LI>ACS_TYPE_CYL
    <LI>ACS_TYPE_SPHERE </UL>

Parameter ``originP``:
    origin of the ACS.

Parameter ``rotationP``:
    rotation of the ACS.

Parameter ``nameP``:
    name of the ACS.

Parameter ``descriptionP``:
    the description of the ACS.

Returns:
    SUCCESS if the element descriptor was created successfully,
    MDLERR_BADARG if any of the parameters was not valid.

Remark:
    

)doc";

static const char * __doc_MstnPlatform_ACS_SetTypeOfElmdscr =R"doc(@description Sets the ACS type of the ACS element descriptor.

Parameter ``edP``:
    ACS element descriptor which is being accessed

Parameter ``acsTypeP``:
    type to set in the ACS, and should be one of:<UL>
    <LI>ACS_TYPE_NONE <LI>ACS_TYPE_RECT <LI>ACS_TYPE_CYL
    <LI>ACS_TYPE_SPHERE </UL>

Returns:
    SUCCESS if the element is an ACS element, MDLERR_BADARG if it is
    not.

See also:
    ACS.GetTypeOfElmdscr

Remark:
    

)doc";

static const char * __doc_MstnPlatform_ACS_GetTypeOfElmdscr =R"doc(@description Get the ACS type of the ACS element descriptor.

Parameter ``acsTypeP``:
    points to a variable which will contain one of the following
    values upon a return of SUCCESS. <UL> <LI>ACS_TYPE_NONE
    <LI>ACS_TYPE_RECT <LI>ACS_TYPE_CYL <LI>ACS_TYPE_SPHERE </UL>

Parameter ``edP``:
    points to the ACS element.

Returns:
    SUCCESS if the element is an ACS element, MDLERR_BADARG if it is
    not.

See also:
    ACS.SetTypeOfElmdscr

Remark:
    

)doc";

static const char * __doc_MstnPlatform_ACS_GetCanonicalDescription =R"doc(@description Canonize the specified ACS description string. The result
is the name string stripped of leading and trailing whitespace
characters, whose length and content has been validated.

Parameter ``canonicalP``:
    points to a string buffer where the canonized description is
    placed. This buffer should be MAX_ACS_DESCR_LENGTH MSWChars long.

Parameter ``descrP``:
    ACS description to be canonized.

Returns:
    SUCCESS unless the name string is too large (MDLERR_BADARG) or
    there is not enough memory to allocate working buffers
    (MDLERR_INSFMEMORY).

See also:
    ACS.GetDescriptionOfElmdscr

Remark:
    

)doc";

static const char * __doc_MstnPlatform_ACS_GetCanonicalName =R"doc(@description Canonizes the specified ACS name string. The result is
the name string stripped of leading and trailing whitespace
characters, whose length and content has been validated.

Parameter ``canonicalP``:
    is a pointer to a string buffer where the canonized name is
    placed. This buffer should be MAX_ACS_NAME_LENGTH MSWChars long.

Parameter ``nameP``:
    ACS name to be canonized.

Returns:
    SUCCESS unless the name string is too large or there is not enough
    memory to allocate working buffers.

See also:
    ACS.GetNameOfElmdscr

Remark:
    

)doc";

static const char * __doc_MstnPlatform_ACS_SetDescriptionOfElmdscr =R"doc(@description Sets the description on the specified ACS element.

Parameter ``edPP``:
    points to ACS element descriptor pointer.

Parameter ``description``:
    points to a buffer where the description is stored.

Returns:
    SUCCESS if the operation was completed successfully, otherwise
    ERROR.

See also:
    ACS.GetDescriptionOfElmdscr

Remark:
    

)doc";

static const char * __doc_MstnPlatform_ACS_SetNameOfElmdscr =R"doc(@description Sets the name on the specified ACS element.

Parameter ``edPP``:
    points to ACS element descriptor pointer.

Parameter ``name``:
    points to a buffer where the name is stored.

Returns:
    SUCCESS if the operation was completed successfully, otherwise
    ERROR.

See also:
    ACS.GetNameOfElmdscr

Remark:
    

)doc";

static const char * __doc_MstnPlatform_ACS_GetDescriptionOfElmdscr =R"doc(@description Gets the description from the specified ACS element.

Parameter ``acsDescriptionP``:
    points to a buffer where the description is copied. This buffer
    should be MAX_ACS_DESCR_LENGTH MSWChars long

Parameter ``edP``:
    points to the ACS element to get the description from.

Returns:
    SUCCESS if the operation was completed successfully, otherwise
    ERROR.

See also:
    ACS.SetDescriptionOfElmdscr

Remark:
    

)doc";

static const char * __doc_MstnPlatform_ACS_GetNameOfElmdscr =R"doc(@description Gets the name from the specified ACS element descriptor.

Parameter ``acsNameP``:
    points to a buffer where the name is copied. This buffer should be
    MAX_ACS_NAME_LENGTH MSWChars long.

Parameter ``edP``:
    points to the ACS element to get the name from.

Returns:
    SUCCESS if the operation was completed successfully, otherwise
    ERROR.

See also:
    ACS.SetNameOfElmdscr

Remark:
    

)doc";

static const char * __doc_MstnPlatform_ACS_Locate =R"doc(@description Searches for an ACS using its assigned name.

Parameter ``edPP``:
    Copy of ACS element descriptor. You must free it when done.

Parameter ``filePosP``:
    file position of the located ACS element.

Parameter ``inName``:
    name of the ACS element to find.

Parameter ``modelRef``:
    model to search for the ACS element.

Returns:
    SUCCESS if the operation completed successfully, otherwise ERROR.

See also:
    ACS.TraverseElements

Remark:
    

)doc";

static const char * __doc_MstnPlatform_ACS_SetCurrent =R"doc(@description Defines the ACS of the active model. <UL>
<LI>ACS_RECTANGULAR <LI>ACS_CYLINDRICAL <LI>ACS_SPHERICAL </UL>

Parameter ``originP``:
    new ACS origin or pass NULL to leave unchanged

Parameter ``rotMatrixP``:
    new ACS orientation or pass NULL to leave unchanged

Parameter ``type``:
    new ACS type or pass NULL to leave unchanged

Returns:
    SUCCESS if the coordinate system is successfully defined.

See also:
    ACS.GetCurrent

Remark:
    

)doc";

static const char * __doc_MstnPlatform_ACS_SaveNamed =R"doc(@description Saves the current coordinate system with the specified
name and description. The name must consist of one to
MAX_ACS_NAME_LENGTH MSWChars, and the description can contain up to
MAX_ACS_DESCR_LENGTH MSWChars. The user or an MDL application can
recall saved coordinate systems with the ACS.AttachNamed function.

Parameter ``name``:
    name of the ACS

Parameter ``description``:
    description of the ACS

Returns:
    SUCCESS if the coordinate system is successfully saved. If the
    coordinate system name already exists, the existing ACS is
    overwritten. If no ACS is active, MDLERR_NOACSDEFINED is returned.

See also:
    ACS.AttachNamed ACS.DeleteNamed

Remark:
    

)doc";

static const char * __doc_MstnPlatform_ACS_GetCurrent =R"doc(@description Returns the current ACS's origin, rotation matrix, and
type. @Remarks The coordinate system type is specified by one of the
following types from msdefs.h:<UL> <LI>ACS_RECTANGULAR
<LI>ACS_CYLINDRICAL <LI>ACS_SPHERICAL </UL>

Parameter ``originP``:
    current ACS origin

Parameter ``rotMatrixP``:
    current ACS orientation

Parameter ``typeP``:
    current ACS type

Parameter ``nameP``:
    points to a buffer where the name is copied. This buffer should be
    MAX_ACS_NAME_LENGTH MSWChars long.

Parameter ``descriptionP``:
    points to a buffer where the description is copied. This buffer
    should be MAX_ACS_DESCR_LENGTH MSWChars long

Returns:
    SUCCESS if an ACS is active and MDLERR_NOACSDEFINED if no system
    is currently defined.

See also:
    ACS.SetCurrent

Remark:
    

)doc";

static const char * __doc_MstnPlatform_ACS_DeleteNamed =R"doc(@description Deletes the named coordinate system specified.

Parameter ``acsName``:
    name of the coordinate system

Returns:
    SUCCESS if the coordinate system is successfully deleted and
    MDLERR_ACSNOTFOUND if the specified coordinate system is not
    found.

See also:
    ACS.AttachNamed ACS.SaveNamed

Remark:
    

)doc";

static const char * __doc_MstnPlatform_ACS_AttachNamed =R"doc(@description Attaches the named auxiliary coordinate system (ACS) to
the active model.

Parameter ``unparsed``:
    the name of the coordinate system to attach

Parameter ``useRot``:
    true means apply the rotation stored in the named ACS, and false
    means ignore it

Parameter ``useOrg``:
    true means apply the origin stored in the named ACS, and false
    means ignore it

Returns:
    SUCCESS if the coordinate system is successfully attached and
    MDLERR_ACSNOTFOUND if the specified coordinate system is not
    found.

See also:
    ACS.DeleteNamed ACS.SaveNamed @See ACS.SaveNamed

Remark:
    

)doc";




struct ACS {};

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_msacs(py::module_& m)
    {
    py::class_<ACS> c1(m, "ACS");

    c1.def_static("AttachNamed", &mdlACS_attachNamed, "acsName"_a, "useRot"_a, "useOrg"_a, DOC(MstnPlatform, ACS, AttachNamed));
    c1.def_static("DeleteNamed", &mdlACS_deleteNamed, "acsName"_a, DOC(MstnPlatform, ACS, DeleteNamed));
    c1.def_static("IsDefined", &mdlACS_isDefined);

    c1.def_static("GetCurrent", [] ()
          {
          DPoint3d origin;
          RotMatrix rotMatrix;
          ACSType type;
          WChar szName[512] = {0};
          WChar szDesc[512] = {0};
          auto retVal = mdlACS_getCurrent(&origin, &rotMatrix, &type, szName, szDesc);
          return py::make_tuple(retVal, origin, rotMatrix, type, szName, szDesc);
          }, DOC(MstnPlatform, ACS, GetCurrent));
    
    c1.def_static("SaveNamed", &mdlACS_saveNamed, "name"_a, "description"_a, DOC(MstnPlatform, ACS, SaveNamed));
    c1.def_static("SetCurrent", &mdlACS_setCurrent, "origin"_a, "rotMatrix"_a, "type"_a, DOC(MstnPlatform, ACS, SetCurrent));

    c1.def_static("Locate", [] (WCharCP name, DgnModelRefP modelRef)
          {
          MSElementDescrP edPP = nullptr;
          UInt32 filePos = -1;
          auto retVal = mdlACS_locate(&edPP, &filePos, name, modelRef);
          return py::make_tuple(retVal, RefCountedPtr<MSElementDescr>(edPP), filePos);
          }, "name"_a, "modelRef"_a, DOC(MstnPlatform, ACS, Locate));

    c1.def_static("GetNameOfElmdscr", [] (MSElementDescrCP edP)
          {
          WChar szName[512] = {0};
          auto retVal = mdlACS_getNameOfElmdscr(szName, edP);
          return py::make_tuple(retVal, szName);
          }, "edP"_a, DOC(MstnPlatform, ACS, GetNameOfElmdscr));

    c1.def_static("GetDescriptionOfElmdscr", [] (MSElementDescrCP edP)
          {
          WChar szName[512] = {0};
          auto retVal = mdlACS_getDescriptionOfElmdscr(szName, edP);
          return py::make_tuple(retVal, szName);
          }, "edP"_a, DOC(MstnPlatform, ACS, GetDescriptionOfElmdscr));

    c1.def_static("SetNameOfElmdscr", [] (MSElementDescrP edP, WCharCP name)
          {
          MSElementDescrP edP_ {edP};
          auto retVal = mdlACS_setNameOfElmdscr(&edP_, name);
          return py::make_tuple(retVal, RefCountedPtr<MSElementDescr>(edP_));
          }, "edP"_a, "name"_a, DOC(MstnPlatform, ACS, SetNameOfElmdscr));

    c1.def_static("SetDescriptionOfElmdscr", [] (MSElementDescrP edP, WCharCP description)
          {
          MSElementDescrP edP_ {edP};
          auto retVal = mdlACS_setDescriptionOfElmdscr(&edP_, description);
          return py::make_tuple(retVal, RefCountedPtr<MSElementDescr>(edP_));
          }, "edP"_a, "description"_a, DOC(MstnPlatform, ACS, SetDescriptionOfElmdscr));

    c1.def_static("GetCanonicalName", [] (WCharCP name)
          {
          WChar szCanonical[512] = {0};
          auto retVal = mdlACS_getCanonicalName(szCanonical, name);
          return py::make_tuple(retVal, szCanonical);
          }, "name"_a, DOC(MstnPlatform, ACS, GetCanonicalName));

    c1.def_static("GetCanonicalDescription", [] (WCharCP descr)
          {
          WChar szCanonical[512] = {0};
          auto retVal = mdlACS_getCanonicalDescription(szCanonical, descr);
          return py::make_tuple(retVal, szCanonical);
          }, "descr"_a, DOC(MstnPlatform, ACS, GetCanonicalDescription));

    c1.def_static("GetTypeOfElmdscr", [] (MSElementDescrCP edP)
          {
          short acsType = 0;
          auto retVal = mdlACS_getTypeOfElmdscr(&acsType, edP);
          return py::make_tuple(retVal, acsType);
          }, "edP"_a, DOC(MstnPlatform, ACS, GetTypeOfElmdscr));

    c1.def_static("SetTypeOfElmdscr", &mdlACS_setTypeOfElmdscr, "edP"_a, "acsType"_a, DOC(MstnPlatform, ACS, SetTypeOfElmdscr));

    c1.def_static("CreateElmdscrFromParams", [] (short type, DPoint3dCP origin, RotMatrixCP rotation, WCharCP name, WCharCP description)
          {
          MSElementDescrP edP = nullptr;
          auto retVal = mdlACS_createElmdscrFromParams(&edP, type, origin, rotation, name, description);
          return py::make_tuple(retVal, RefCountedPtr<MSElementDescr>(edP));
          }, "type"_a, "origin"_a, "rotation"_a, "name"_a, "description"_a, DOC(MstnPlatform, ACS, CreateElmdscrFromParams));
    }