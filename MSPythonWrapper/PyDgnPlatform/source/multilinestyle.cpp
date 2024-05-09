/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\multilinestyle.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/MultilineStyle.h>



static const char * __doc_Bentley_DgnPlatform_MultilineStyle_SetMidCap =R"doc(Replace the Mid or Joint Cap symbology of the style.

Parameter ``symb``:
    The new symbology to use. Bentley Systems +-----------------------
    ---------------------------------------------------------------)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_GetMidCap =R"doc(Get a pointer to a copy of the Mid or Joint Cap symbology from the
style.

Returns:
    A pointer to the Mid or Joint Cap symbology. Bentley Systems +----
    ------------------------------------------------------------------
    ----------------)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_SetEndCap =R"doc(Replace the End Cap symbology of the style.

Parameter ``symb``:
    The new symbology to use. Bentley Systems +-----------------------
    ---------------------------------------------------------------)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_GetEndCap =R"doc(Get a pointer to a copy of the End Cap symbology from the style.

Returns:
    A pointer to the End Cap symbology. Bentley Systems +-------------
    ------------------------------------------------------------------
    -------)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_SetOrgCap =R"doc(Replace the Origin Cap symbology of the style.

Parameter ``symb``:
    The new symbology to use. Bentley Systems +-----------------------
    ---------------------------------------------------------------)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_GetOrgCap =R"doc(Get a pointer to a copy of the Origin Cap symbology from the style.

Returns:
    A pointer to the Origin Cap symbology. Bentley Systems +----------
    ------------------------------------------------------------------
    ----------)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_ClearProfiles =R"doc(Empty all profile lines in the multi-line. Bentley Systems +----------
----------------------------------------------------------------------
------)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_RemoveProfile =R"doc(Remove a profile line from the style.

Parameter ``profileNum``:
    The profile to remove. Valid values are 0 to
    GetProfileLineCount()-1.

Returns:
    SUCCESS if the profile is removed Bentley Systems +---------------
    ------------------------------------------------------------------
    -----)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_InsertProfile =R"doc(Add a profile line to the style.

Parameter ``profile``:
    The profile to add.

Parameter ``profileNum``:
    The index to add the profile. Use -1 to add it at the end.

Returns:
    SUCCESS if the profile is added. Bentley Systems +----------------
    ------------------------------------------------------------------
    ----)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_ReplaceProfile =R"doc(Replace the profile at a given location.

Parameter ``profile``:
    The new profile definition.

Parameter ``profileNum``:
    The profile of interest. Valid values are 0 to
    GetProfileLineCount()-1.

Returns:
    A pointer to the profile object, or NULL if profileNum is out of
    range. Bentley Systems +------------------------------------------
    --------------------------------------------)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_GetProfile =R"doc(Get a pointer to a copy of the profile line in the style.

Parameter ``profileNum``:
    The profile of interest. Valid values are 0 to
    GetProfileLineCount()-1.

Returns:
    A pointer to the profile object, or NULL if profileNum is out of
    range. Bentley Systems +------------------------------------------
    --------------------------------------------)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_SetEndAngle =R"doc(Set the end cap angle for the multi-line style.

Parameter ``value``:
    The new end cap angle in radians. Bentley Systems +---------------
    ------------------------------------------------------------------
    -----)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_GetEndAngle =R"doc(Get the end cap angle for the multi-line style.

Returns:
    The angle of the end cap line in radians. Bentley Systems +-------
    ------------------------------------------------------------------
    -------------)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_SetOriginAngle =R"doc(Set the origin cap angle for the multi-line style.

Parameter ``value``:
    The new origin cap angle in radians. Bentley Systems +------------
    ------------------------------------------------------------------
    --------)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_GetOriginAngle =R"doc(Get the origin cap angle for the multi-line style.

Returns:
    The angle of the origin cap line in radians. Bentley Systems +----
    ------------------------------------------------------------------
    ----------------)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_GetProfileLineCount =R"doc(Get the number of multi-line profile lines in the style.

Returns:
    The number of profile lines. Bentley Systems +--------------------
    ------------------------------------------------------------------)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_SetFilled =R"doc(Set the flag that determines if a multi-line is filled.

Parameter ``value``:
    The new value for whether the multi-line is filled. Bentley
    Systems +---------------------------------------------------------
    -----------------------------)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_GetFilled =R"doc(Get the flag that determines if a multi-line is filled from the style.

Returns:
    The whether the multi-line is filled. Bentley Systems +-----------
    ------------------------------------------------------------------
    ---------)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_SetFillColor =R"doc(Set the fill color of the .

Parameter ``value``:
    The new fill color. Bentley Systems +-----------------------------
    ---------------------------------------------------------)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_GetFillColor =R"doc(Get the fill color from the style. Note that a style can have a fill
color but it won't show unless the element is filled. See GetFilled().

Returns:
    The fill color. Bentley Systems +---------------------------------
    -----------------------------------------------------)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_GetFile =R"doc(Get the file associated with the multi-line style.

Returns:
    The file associated with the style. Bentley Systems +-------------
    ------------------------------------------------------------------
    -------)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_GetID =R"doc(Get the ID of the multi-line style.

Returns:
    The ID of the style. Bentley Systems +----------------------------
    ----------------------------------------------------------)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_SetName =R"doc(Change the in-memory name of the style. This will not change the file
until Replace is called.

Parameter ``name``:
    The new name for the style. Bentley Systems +---------------------
    -----------------------------------------------------------------)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_GetName =R"doc(Get the name of the multi-line style.

Returns:
    The name of the style. Bentley Systems +--------------------------
    ------------------------------------------------------------)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_RemapDependents =R"doc(Remap all the elements that reference one style to different style.

Parameter ``destStyle``:
    IN remap to this style.

Parameter ``sourceStyle``:
    IN remap from this style.

Parameter ``file``:
    IN file in which to search. +-------------------------------------
    -------------------------------------------------)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_HasDependants =R"doc(Tests whether any elements store a persistent reference to the style.

Returns:
    true if there are dependents. Bentley Systems +-------------------
    ------------------------------------------------------------------
    -)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_Compare =R"doc(Compare two multi-line styles.

Parameter ``style``:
    The style that will be compared.

Returns:
    A property mask with bits set describing which parameters are
    different. Bentley Systems +--------------------------------------
    ------------------------------------------------)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_CopyValues =R"doc(Copy values from one multi-line style to another.

Parameter ``style``:
    The style to copy values from.

Returns:
    SUCCESS if the values are copied as requested. Bentley Systems +--
    ------------------------------------------------------------------
    ------------------)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_Create =R"doc(Create a multi-line style object in memory.

Parameter ``name``:
    A name for the style.

Parameter ``file``:
    The file that the style will be associated with.

Returns:
    A pointer to the new style or NULL if creation failed. Bentley
    Systems +---------------------------------------------------------
    -----------------------------)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_Replace =R"doc(Update a multi-line style in the file specified in the style.

Parameter ``oldName``:
    When renaming a style, pass in the old style name to replace. In
    the common case where this parameter is NULL, it is assumed that
    the style retains its name.

Parameter ``destFile``:
    The destination file. Can be NULL to write to the file where the
    style was read.

Returns:
    SUCCESS if the style is successfully updated in the file. Bentley
    Systems +---------------------------------------------------------
    -----------------------------)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_Delete =R"doc(Delete a multi-line style from the file specified in the style.

Parameter ``name``:
    The name of the style to delete.

Parameter ``file``:
    The file that contains the style.

Returns:
    SUCCESS if the style is successfully deleted from the file.
    Bentley Systems +-------------------------------------------------
    -------------------------------------)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_Add =R"doc(Add a multi-line style to the file specified in the style. The style
must have at least one profile defined or it will be an error.

Returns:
    SUCCESS if the style is successfully added to the file. Bentley
    Systems +---------------------------------------------------------
    -----------------------------)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_ReplaceSettings =R"doc(Gets the settings multi-line style from a file.

Parameter ``settings``:
    The style to save as the active settings.

Parameter ``file``:
    The file to look in for the style.

Returns:
    Pointer to the style or NULL if it is not found. Bentley Systems +
    ------------------------------------------------------------------
    --------------------)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_GetSettings =R"doc(Gets the settings multi-line style from a file.

Parameter ``file``:
    The file to look in for the style.

Returns:
    Pointer to the style or NULL if it is not found. Bentley Systems +
    ------------------------------------------------------------------
    --------------------)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_GetByName =R"doc(Get a multi-line style from a file by name.

Parameter ``name``:
    The name of the style to get.

Parameter ``file``:
    The file to look in for the style.

Returns:
    Pointer to the style or NULL if it is not found. Bentley Systems +
    ------------------------------------------------------------------
    --------------------)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStyle_GetByID =R"doc(Get a multi-line style from a file by Style ID.

Parameter ``id``:
    The style ID of the style to get.

Parameter ``file``:
    The file to look in for the style.

Returns:
    Pointer to the style or NULL if it is not found. Bentley Systems +
    ------------------------------------------------------------------
    --------------------)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineProfile_SetDistance =R"doc(Set the offset distance of a profile.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineProfile_GetDistance =R"doc(Get the offset distance of a profile)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineProfile_ScaleDistance =R"doc(Scale the offset in a profile)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineSymbology_SetCapColorFromSegment =R"doc(Set whether to use the profile color to define half the cap. If this
is set, a cap that goes between a red and blue profile will be red for
90 degrees and blue for 90 degrees. This is ignored on profiles.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineSymbology_UseCapColorFromSegment =R"doc(Determine whether to use the profile color to define half the cap.
This is ignored on profiles.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineSymbology_SetCapOuterArc =R"doc(Set whether to draw an arc between the outermost profiles of the cap.
This is ignored on profiles.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineSymbology_UseCapOuterArc =R"doc(Determine whether to draw an arc between the outermost profiles of the
cap. This is ignored on profiles.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineSymbology_SetCapInnerArc =R"doc(Set whether to draw concentric arcs between profiles across the cap.
This is ignored on profiles.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineSymbology_UseCapInnerArc =R"doc(Determine whether to draw a concentric arcs across the cap. This is
ignored on profiles.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineSymbology_SetCapLine =R"doc(Set whether to draw a line across the cap. This is ignored on
profiles.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineSymbology_UseCapLine =R"doc(Determine whether to draw a line across the cap. This is ignored on
profiles.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineSymbology_SetClass =R"doc(Set the class (drawing or construction) in the symbology

Parameter ``conclass``:
    The new class. The only valid values are DgnElementClass::Primary
    or DgnElementClass::Construction.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineSymbology_GetClass =R"doc(Set the color in the symbology)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineSymbology_SetUseClass =R"doc(Set whether to use the class from the symbology (true) or from the
header (false).

Parameter ``val``:
    The new value for the use class symbology bit.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineSymbology_UsesClass =R"doc(Determine if the profile or cap uses the class value defined in this
symbology

Returns:
    True if the local class is used, false if the value from the
    element header is used.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineSymbology_SetColor =R"doc(Set the color in the symbology)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineSymbology_GetColor =R"doc(Get the color from the symbology)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineSymbology_SetUseColor =R"doc(Set whether to use the color from the symbology (true) or from the
header (false).

Parameter ``val``:
    The new value for the use color symbology bit.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineSymbology_UsesColor =R"doc(Determine if the profile or cap uses the color value defined in this
symbology

Returns:
    True if the local color is used, false if the value from the
    element header is used.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineSymbology_SetWeight =R"doc(Set the weight in the symbology)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineSymbology_GetWeight =R"doc(Get the weight from the symbology)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineSymbology_SetUseWeight =R"doc(Set whether to use the weight from the symbology (true) or from the
header (false).

Parameter ``val``:
    The new value for the use weight symbology bit.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineSymbology_UsesWeight =R"doc(Determine if the profile or cap uses the weight value defined in this
symbology

Returns:
    True if the local weight is used, false if the value from the
    element header is used.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineSymbology_SetLinestyleParams =R"doc(Set the line style parameters in the symbology)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineSymbology_GetLinestyleParams =R"doc(Get the line style parameters from the symbology)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineSymbology_SetLinestyle =R"doc(Set the line style symbology.

Remark:
    s You must also call SetUseLinestyle(true) for this line style to
    be used.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineSymbology_GetLinestyle =R"doc(Get the line style Id from the symbology.

Returns:
    The line style Id)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineSymbology_UsesLinestyle =R"doc(Determine if the profile or cap uses the line style value defined in
this symbology

Returns:
    True if the local line style Id is used, false if the value from
    the element header is used.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineSymbology_SetLevel =R"doc(Set the level symbology.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineSymbology_GetLevel =R"doc(Get the Level Id from the symbology.

Returns:
    The level Id, or 0 if the element level is used.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineSymbology_UsesLevel =R"doc(Determine if the profile or cap uses the locally defined level value

Returns:
    True if the local level definition is used, false if the value
    from the element header is used.

Remark:
    s Level is a little different than other properties. The value 0
    is stored if the level is unused, so use SetLevel(0) to use the
    value from the header.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineSymbology_Copy =R"doc(Duplicate a symbology

Parameter ``other``:
    The symbology to copy)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStylePropMask_CopyValues =R"doc(Copies the values from another property mask.

Parameter ``other``:
    The property mask to copy.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStylePropMask_ClearAllBits =R"doc(Reset all the property flags to false.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStylePropMask_AnyBitSet =R"doc(Tests whether any of the flags are set.

Returns:
    True if any bits are set.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStylePropMask_SetProfileBit =R"doc(Get one of the MlinestylePropFlags flags for a cap multi-line property
such as color or offset.

Parameter ``profileIndex``:
    Which profile the property is associated with.

Parameter ``item``:
    The property being queried

Parameter ``bitValue``:
    The new value for the property.

Returns:
    SUCCESS if the bit is set in the mask.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStylePropMask_GetProfileBit =R"doc(Get one of the MlinestylePropFlags flags for a cap multi-line property
such as color or offset.

Parameter ``profileIndex``:
    Which profile the property is associated with.

Parameter ``item``:
    The property being queried

Returns:
    The value of the requested bit.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStylePropMask_SetCapBit =R"doc(Get one of the MlinestylePropFlags flags for a cap multi-line property
such as color or cap arc.

Parameter ``capIndex``:
    Which cap the property is associated with.

Parameter ``item``:
    The property being queried

Parameter ``bitValue``:
    The new value for the property.

Returns:
    SUCCESS if the bit is set in the mask.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStylePropMask_GetCapBit =R"doc(Get one of the MlinestylePropFlags flags for a cap multi-line property
such as color or cap arc.

Parameter ``capIndex``:
    Which cap the property is associated with.

Parameter ``item``:
    The property being queried

Returns:
    The value of the requested bit.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStylePropMask_SetGeneralBit =R"doc(Set one of the MlinestylePropFlags flags for an overall multi-line
property such as origin angle or fill.

Parameter ``item``:
    The property being set.

Parameter ``bitValue``:
    The new value for the property.

Returns:
    SUCCESS if the bit is set in the mask.)doc";

static const char * __doc_Bentley_DgnPlatform_MultilineStylePropMask_GetGeneralBit =R"doc(Get one of the MlinestylePropFlags flags for an overall multi-line
property such as origin angle or fill.

Parameter ``item``:
    The property being queried

Returns:
    The value of the requested bit.)doc";

//=======================================================================================
// Trampoline class for IMlineStyleTransactionListener.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyMlineStyleTransactionListener : IMlineStyleTransactionListener
    {
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _OnMlineStyleChange(MultilineStyleCP before, MultilineStyleCP after, StyleEventType type, StyleEventSource source) override
        { PYBIND11_OVERRIDE_PURE_EX(void, IMlineStyleTransactionListener, _OnMlineStyleChange, before, after, type, source); }
    };

//=======================================================================================
// Trampoline class for MlineStyleEvents.
// @bsiclass                                                                   02/23
//=======================================================================================
struct PyMlineStyleEvents : MlineStyleEvents
    {
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/        
    virtual void _OnMlineStyleChange(MultilineStyleCP before, MultilineStyleCP after, StyleEventType type, StyleEventSource source) override
        { PYBIND11_OVERRIDE_PURE_EX(void, IMlineStyleTransactionListener, _OnMlineStyleChange, before, after, type, source); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_MultilineStyle(py::module_& m)
    {
    //===================================================================================
    // enum MultilineCapType
    py::enum_< MultilineCapType>(m, "MultilineCapType", py::arithmetic())
        .value("eMULTILINE_ORG_CAP", MULTILINE_ORG_CAP)
        .value("eMULTILINE_END_CAP", MULTILINE_END_CAP)
        .value("eMULTILINE_MID_CAP", MULTILINE_MID_CAP)
        .export_values();

    //===================================================================================
    // enum MultilineCapIndex
    py::enum_< MultilineCapIndex>(m, "MultilineCapIndex", py::arithmetic())
        .value("eMULTILINE_ORG_CAP_INDEX", MULTILINE_ORG_CAP_INDEX)
        .value("eMULTILINE_END_CAP_INDEX", MULTILINE_END_CAP_INDEX)
        .value("eMULTILINE_MID_CAP_INDEX", MULTILINE_MID_CAP_INDEX)
        .export_values();

    //===================================================================================
    // struct IMlineStyleTransactionListener
    py::class_< IMlineStyleTransactionListener, std::unique_ptr< IMlineStyleTransactionListener, py::nodelete>, IPyMlineStyleTransactionListener> c1(m, "IMlineStyleTransactionListener");

    c1.def("_OnMlineStyleChange", &IMlineStyleTransactionListener::_OnMlineStyleChange, "before"_a, "after"_a, "type"_a, "source"_a);

    //===================================================================================
    // struct MlineStyleEvents
    py::class_< MlineStyleEvents, std::unique_ptr< MlineStyleEvents, py::nodelete>, PyMlineStyleEvents, IMlineStyleTransactionListener> c2(m, "MlineStyleEvents");

    c2.def("_OnMlineStyleChange", &MlineStyleEvents::_OnMlineStyleChange, "before"_a, "after"_a, "type"_a, "source"_a);        

    //===================================================================================
    // struct MultilineStylePropMask
    py::class_< MultilineStylePropMask, MultilineStylePropMaskPtr> c3(m, "MultilineStylePropMask");

    c3.def(py::init(&MultilineStylePropMask::Create));
    c3.def("GetGeneralBit", &MultilineStylePropMask::GetGeneralBit, "item"_a, DOC(Bentley, DgnPlatform, MultilineStylePropMask, GetGeneralBit));
    c3.def("SetGeneralBit", &MultilineStylePropMask::SetGeneralBit, "item"_a, "bitValue"_a, DOC(Bentley, DgnPlatform, MultilineStylePropMask, SetGeneralBit));
    c3.def("GetCapBit", &MultilineStylePropMask::GetCapBit, "capIndex"_a, "item"_a, DOC(Bentley, DgnPlatform, MultilineStylePropMask, GetCapBit));
    c3.def("SetCapBit", &MultilineStylePropMask::SetCapBit, "capIndex"_a, "item"_a, "bitValue"_a, DOC(Bentley, DgnPlatform, MultilineStylePropMask, SetCapBit));
    c3.def("GetProfileBit", &MultilineStylePropMask::GetProfileBit, "profileIndex"_a, "item"_a, DOC(Bentley, DgnPlatform, MultilineStylePropMask, GetProfileBit));
    c3.def("SetProfileBit", &MultilineStylePropMask::SetProfileBit, "profileIndex"_a, "item"_a, "bitValue"_a, DOC(Bentley, DgnPlatform, MultilineStylePropMask, SetProfileBit));
    c3.def("AnyBitSet", &MultilineStylePropMask::AnyBitSet, DOC(Bentley, DgnPlatform, MultilineStylePropMask, AnyBitSet));
    c3.def("ClearAllBits", &MultilineStylePropMask::ClearAllBits, DOC(Bentley, DgnPlatform, MultilineStylePropMask, ClearAllBits));
    c3.def("CopyValues", &MultilineStylePropMask::CopyValues, "other"_a, DOC(Bentley, DgnPlatform, MultilineStylePropMask, CopyValues));

    //===================================================================================
    // struct MultilineStyleCollection
    py::class_< MultilineStyleCollection> c4(m, "MultilineStyleCollection");

    c4.def(py::init<DgnFileR>(), "dgnFile"_a);
    //c4.def("__iter__", [] (MultilineStyleCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

    //===================================================================================
    // struct MultilineSymbology
    py::class_< MultilineSymbology, MultilineSymbologyPtr> c5(m, "MultilineSymbology");

    c5.def("Copy", &MultilineSymbology::Copy, "other"_a, DOC(Bentley, DgnPlatform, MultilineSymbology, Copy));
    
    c5.def("UsesLevel", &MultilineSymbology::UsesLevel, DOC(Bentley, DgnPlatform, MultilineSymbology, UsesLevel));
    
    c5.def_property("Level", &MultilineSymbology::GetLevel, &MultilineSymbology::SetLevel);
    c5.def("GetLevel", &MultilineSymbology::GetLevel, DOC(Bentley, DgnPlatform, MultilineSymbology, GetLevel));
    c5.def("SetLevel", &MultilineSymbology::SetLevel, "levelId"_a, DOC(Bentley, DgnPlatform, MultilineSymbology, SetLevel));
    
    c5.def_property("IsUsesLinestyle", &MultilineSymbology::UsesLinestyle, &MultilineSymbology::SetUseLinestyle);
    c5.def("UsesLinestyle", &MultilineSymbology::UsesLinestyle, DOC(Bentley, DgnPlatform, MultilineSymbology, UsesLinestyle));
    c5.def("SetUsesLinestyle", &MultilineSymbology::SetUseLinestyle, "uses"_a);
    
    c5.def_property("Linestyle", &MultilineSymbology::GetLinestyle, &MultilineSymbology::SetLinestyle);
    c5.def("GetLinestyle", &MultilineSymbology::GetLinestyle, DOC(Bentley, DgnPlatform, MultilineSymbology, GetLinestyle));
    c5.def("SetLinestyle", &MultilineSymbology::SetLinestyle, "lineStyleId"_a, DOC(Bentley, DgnPlatform, MultilineSymbology, SetLinestyle));
    
    c5.def_property("LinestyleParams", &MultilineSymbology::GetLinestyleParams, &MultilineSymbology::SetLinestyleParams);
    c5.def("GetLinestyleParams", &MultilineSymbology::GetLinestyleParams, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MultilineSymbology, GetLinestyleParams));
    c5.def("SetLinestyleParams", &MultilineSymbology::SetLinestyleParams, "params"_a, DOC(Bentley, DgnPlatform, MultilineSymbology, SetLinestyleParams));
    
    c5.def_property("IsUsesWeight", &MultilineSymbology::UsesWeight, &MultilineSymbology::SetUseWeight);
    c5.def("UsesWeight", &MultilineSymbology::UsesWeight, DOC(Bentley, DgnPlatform, MultilineSymbology, UsesWeight));
    c5.def("SetUseWeight", &MultilineSymbology::SetUseWeight, "useWeight"_a, DOC(Bentley, DgnPlatform, MultilineSymbology, SetUseWeight));
    
    c5.def_property("Weight", &MultilineSymbology::GetWeight, &MultilineSymbology::SetWeight);
    c5.def("GetWeight", &MultilineSymbology::GetWeight, DOC(Bentley, DgnPlatform, MultilineSymbology, GetWeight));
    c5.def("SetWeight", &MultilineSymbology::SetWeight, "weight"_a, DOC(Bentley, DgnPlatform, MultilineSymbology, SetWeight));
    
    c5.def_property("IsUsesColor", &MultilineSymbology::UsesColor, &MultilineSymbology::SetUseColor);
    c5.def("UsesColor", &MultilineSymbology::UsesColor, DOC(Bentley, DgnPlatform, MultilineSymbology, UsesColor));
    c5.def("SetUseColor", &MultilineSymbology::SetUseColor, "useColor"_a, DOC(Bentley, DgnPlatform, MultilineSymbology, SetUseColor));
    
    c5.def_property("Color", &MultilineSymbology::GetColor, &MultilineSymbology::SetColor);
    c5.def("GetColor", &MultilineSymbology::GetColor, DOC(Bentley, DgnPlatform, MultilineSymbology, GetColor));
    c5.def("SetColor", &MultilineSymbology::SetColor, "color"_a, DOC(Bentley, DgnPlatform, MultilineSymbology, SetColor));
    
    c5.def_property("IsUsesClass", &MultilineSymbology::UsesClass, &MultilineSymbology::SetUseClass);
    c5.def("UsesClass", &MultilineSymbology::UsesClass, DOC(Bentley, DgnPlatform, MultilineSymbology, UsesClass));
    c5.def("SetUseClass", &MultilineSymbology::SetUseClass, "useClass"_a, DOC(Bentley, DgnPlatform, MultilineSymbology, SetUseClass));
    
    c5.def_property("Class", &MultilineSymbology::GetClass, &MultilineSymbology::SetClass);
    c5.def("GetClass", &MultilineSymbology::GetClass, DOC(Bentley, DgnPlatform, MultilineSymbology, GetClass));
    c5.def("SetClass", &MultilineSymbology::SetClass, "class"_a, DOC(Bentley, DgnPlatform, MultilineSymbology, SetClass));
    
    c5.def_property("IsUseCapLine", &MultilineSymbology::UseCapLine, &MultilineSymbology::SetCapLine);
    c5.def("UseCapLine", &MultilineSymbology::UseCapLine, DOC(Bentley, DgnPlatform, MultilineSymbology, UseCapLine));
    c5.def("SetCapLine", &MultilineSymbology::SetCapLine, "val"_a, DOC(Bentley, DgnPlatform, MultilineSymbology, SetCapLine));
    
    c5.def_property("IsUseCapInnerArc", &MultilineSymbology::UseCapInnerArc, &MultilineSymbology::SetCapInnerArc);
    c5.def("UseCapInnerArc", &MultilineSymbology::UseCapInnerArc, DOC(Bentley, DgnPlatform, MultilineSymbology, UseCapInnerArc));
    c5.def("SetCapInnerArc", &MultilineSymbology::SetCapInnerArc, "val"_a, DOC(Bentley, DgnPlatform, MultilineSymbology, SetCapInnerArc));
    
    c5.def_property("IsUseCapOuterArc", &MultilineSymbology::UseCapOuterArc, &MultilineSymbology::SetCapOuterArc);
    c5.def("UseCapOuterArc", &MultilineSymbology::UseCapOuterArc, DOC(Bentley, DgnPlatform, MultilineSymbology, UseCapOuterArc));
    c5.def("SetCapOuterArc", &MultilineSymbology::SetCapOuterArc, "val"_a, DOC(Bentley, DgnPlatform, MultilineSymbology, SetCapOuterArc));
    
    c5.def_property("IsUseCapColorFromSegment", &MultilineSymbology::UseCapColorFromSegment, &MultilineSymbology::SetCapColorFromSegment);
    c5.def("UseCapColorFromSegment", &MultilineSymbology::UseCapColorFromSegment, DOC(Bentley, DgnPlatform, MultilineSymbology, UseCapColorFromSegment));
    c5.def("SetCapColorFromSegment", &MultilineSymbology::SetCapColorFromSegment, "val"_a, DOC(Bentley, DgnPlatform, MultilineSymbology, SetCapColorFromSegment));

    //===================================================================================
    // struct MultilineProfile
    py::class_< MultilineProfile, MultilineProfilePtr, MultilineSymbology> c6(m, "MultilineProfile");

    c6.def(py::init(py::overload_cast<>(&MultilineProfile::Create)));
    c6.def("ScaleDistance", &MultilineProfile::ScaleDistance, "scale"_a, DOC(Bentley, DgnPlatform, MultilineProfile, ScaleDistance));

    c6.def_property("Distance", &MultilineProfile::GetDistance, &MultilineProfile::SetDistance);
    c6.def("GetDistance", &MultilineProfile::GetDistance, DOC(Bentley, DgnPlatform, MultilineProfile, GetDistance));
    c6.def("SetDistance", &MultilineProfile::SetDistance, "distance"_a, DOC(Bentley, DgnPlatform, MultilineProfile, SetDistance));

    //===================================================================================
    // struct MultilineStyle
    py::class_< MultilineStyle, MultilineStylePtr> c7(m, "MultilineStyle");

    c7.def_static("GetByID", &MultilineStyle::GetByID, "id"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, MultilineStyle, GetByID));
    c7.def_static("GetByName", &MultilineStyle::GetByName, "name"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, MultilineStyle, GetByName));
    c7.def_static("GetSettings", &MultilineStyle::GetSettings, "dgnFile"_a, DOC(Bentley, DgnPlatform, MultilineStyle, GetSettings));
    c7.def_static("ReplaceSettings", &MultilineStyle::ReplaceSettings, "settings"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, MultilineStyle, ReplaceSettings));
    c7.def("Add", &MultilineStyle::Add, "dgnFile"_a = nullptr, DOC(Bentley, DgnPlatform, MultilineStyle, Add));
    c7.def_static("Delete", &MultilineStyle::Delete, "name"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, MultilineStyle, Delete));
    c7.def("Replace", &MultilineStyle::Replace, "oldName"_a, "destFile"_a, DOC(Bentley, DgnPlatform, MultilineStyle, Replace));
    c7.def_static("Create", &MultilineStyle::Create, "name"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, MultilineStyle, Create));
    c7.def("CopyValues", &MultilineStyle::CopyValues, "style"_a, DOC(Bentley, DgnPlatform, MultilineStyle, CopyValues));
    c7.def("Compare", &MultilineStyle::Compare, "style"_a, DOC(Bentley, DgnPlatform, MultilineStyle, Compare));
    c7.def("HasDependants", &MultilineStyle::HasDependants, DOC(Bentley, DgnPlatform, MultilineStyle, HasDependants));
    c7.def_static("RemapDependents", &MultilineStyle::RemapDependents, "destStyle"_a, "sourceStyle"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, MultilineStyle, RemapDependents));
    
    c7.def_property("Name", &MultilineStyle::GetName, &MultilineStyle::SetName);
    c7.def("GetName", &MultilineStyle::GetName, DOC(Bentley, DgnPlatform, MultilineStyle, GetName));
    c7.def("SetName", &MultilineStyle::SetName, "name"_a, DOC(Bentley, DgnPlatform, MultilineStyle, SetName));
    
    c7.def_property_readonly("ID", &MultilineStyle::GetID);
    c7.def("GetID", &MultilineStyle::GetID, DOC(Bentley, DgnPlatform, MultilineStyle, GetID));
    
    c7.def_property_readonly("File", &MultilineStyle::GetFile);
    c7.def("GetFile", &MultilineStyle::GetFile, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MultilineStyle, GetFile));
    
    c7.def("SetScale", &MultilineStyle::Scale, "scale"_a);
    
    c7.def_property("FillColor", &MultilineStyle::GetFillColor, &MultilineStyle::SetFillColor);
    c7.def("GetFillColor", &MultilineStyle::GetFillColor, DOC(Bentley, DgnPlatform, MultilineStyle, GetFillColor));
    c7.def("SetFillColor", &MultilineStyle::SetFillColor, "fillColor"_a, DOC(Bentley, DgnPlatform, MultilineStyle, SetFillColor));
    
    c7.def_property("Filled", &MultilineStyle::GetFilled, &MultilineStyle::SetFilled);
    c7.def("GetFilled", &MultilineStyle::GetFilled, DOC(Bentley, DgnPlatform, MultilineStyle, GetFilled));
    c7.def("SetFilled", &MultilineStyle::SetFilled, "filled"_a, DOC(Bentley, DgnPlatform, MultilineStyle, SetFilled));
    
    c7.def_property_readonly("ProfileLineCount", &MultilineStyle::GetProfileLineCount);
    c7.def("GetProfileLineCount", &MultilineStyle::GetProfileLineCount, DOC(Bentley, DgnPlatform, MultilineStyle, GetProfileLineCount));
    
    c7.def_property("OriginAngle", &MultilineStyle::GetOriginAngle, &MultilineStyle::SetOriginAngle);
    c7.def("GetOriginAngle", &MultilineStyle::GetOriginAngle, DOC(Bentley, DgnPlatform, MultilineStyle, GetOriginAngle));
    c7.def("SetOriginAngle", &MultilineStyle::SetOriginAngle, "angle"_a, DOC(Bentley, DgnPlatform, MultilineStyle, SetOriginAngle));
    
    c7.def_property("EndAngle", &MultilineStyle::GetEndAngle, &MultilineStyle::SetEndAngle);
    c7.def("GetEndAngle", &MultilineStyle::GetEndAngle, DOC(Bentley, DgnPlatform, MultilineStyle, GetEndAngle));
    c7.def("SetEndAngle", &MultilineStyle::SetEndAngle, "angle"_a, DOC(Bentley, DgnPlatform, MultilineStyle, SetEndAngle));
    
    c7.def("GetProfile", &MultilineStyle::GetProfile, "profileNum"_a, DOC(Bentley, DgnPlatform, MultilineStyle, GetProfile));
    c7.def("ReplaceProfile", &MultilineStyle::ReplaceProfile, "profile"_a, "profileNum"_a, DOC(Bentley, DgnPlatform, MultilineStyle, ReplaceProfile));
    c7.def("InsertProfile", &MultilineStyle::InsertProfile, "profile"_a, "profileNum"_a, DOC(Bentley, DgnPlatform, MultilineStyle, InsertProfile));
    c7.def("RemoveProfile", &MultilineStyle::RemoveProfile, "profileNum"_a, DOC(Bentley, DgnPlatform, MultilineStyle, RemoveProfile));
    c7.def("ClearProfiles", &MultilineStyle::ClearProfiles, DOC(Bentley, DgnPlatform, MultilineStyle, ClearProfiles));
    
    c7.def_property("OrgCap", &MultilineStyle::GetOrgCap, &MultilineStyle::SetOrgCap);
    c7.def("GetOrgCap", &MultilineStyle::GetOrgCap, DOC(Bentley, DgnPlatform, MultilineStyle, GetOrgCap));
    c7.def("SetOrgCap", &MultilineStyle::SetOrgCap, "symb"_a, DOC(Bentley, DgnPlatform, MultilineStyle, SetOrgCap));
    
    c7.def_property("EndCap", &MultilineStyle::GetEndCap, &MultilineStyle::SetEndCap);
    c7.def("GetEndCap", &MultilineStyle::GetEndCap, DOC(Bentley, DgnPlatform, MultilineStyle, GetEndCap));
    c7.def("SetEndCap", &MultilineStyle::SetEndCap, "symb"_a, DOC(Bentley, DgnPlatform, MultilineStyle, SetEndCap));
    
    c7.def_property("MidCap", &MultilineStyle::GetMidCap, &MultilineStyle::SetMidCap);
    c7.def("GetMidCap", &MultilineStyle::GetMidCap, DOC(Bentley, DgnPlatform, MultilineStyle, GetMidCap));
    c7.def("SetMidCap", &MultilineStyle::SetMidCap, "symb"_a, DOC(Bentley, DgnPlatform, MultilineStyle, SetMidCap));
    }