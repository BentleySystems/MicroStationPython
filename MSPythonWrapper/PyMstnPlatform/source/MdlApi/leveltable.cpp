/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MdlApi\leveltable.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/MdlApi/leveltable.h>
#include <Mstn/MdlApi/leveltable.fdf>



static const char * __doc_MstnPlatform_LevelName_HasValidCharacters =R"doc(@Description Check if specified Name String is valid

Parameter ``nameStringIn``:
    level name

Returns:
    true if the Name String is valid, else false

See also:
    LevelName.SetName LevelName.ReplaceInvalidCharacters Bentley
    Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_LevelAttribute_GetMask =R"doc(Return the level-attribute bit-mask for a given attribute list type.

Parameter ``attributeTypeIn``:
    level attribute mask type to get

Returns:
    level attribute bit-mask for given type.

Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_GetSeedLevel =R"doc(@Description Get level-id of seed level. When a new level is created,
then the user designated seed level whose attributes need to be
applied on the newly created level.

Remark:
    s <i>Level.CreateLevel</i> does not apply the attributes of the
    seed level. <i>Level.CreateLevel</i> will only create a newly
    allocated level. The attributes of the seed level can then be
    applied using <i>Level.CopyLevelData</i>. To create a level &
    apply the seed in one step, call the function
    <i>Level.CreateFromSeed</i>

Parameter ``modelRefIn``:
    model ref

Returns:
    DgnPlatform::LevelId of seed level

Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_SetElementByLevel =R"doc(@Description set or unset elements symbology to that of BYLEVEL.

Parameter ``numElementChangedOut``:
    number of elements changed

Parameter ``modelRefIn``:
    model ref

Parameter ``levelIdIn``:
    level to change elements symbology

Parameter ``elementAttributeStringIn``:
    mask of attributes, 1:color, 2:style, 3:weight

Parameter ``inEntireFileIn``:
    if true, then set elements symbology in entire file of modelrefIn,
    else set elements symbology only in the specified model

Parameter ``isSetByLevel``:
    if true, then set elements symbology to that of BYLEVEL, else
    unset elements symbology to that of BYLEVEL.

Returns:
    ERROR if the model-ref or the level ids are invalid, else SUCCESS

Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_MoveElementLevel =R"doc(@Description Move elements of source level to destination level. The
model-refs of both the source level and destination level are the
same.

Parameter ``numElementMovedOut``:
    number of elements moved

Parameter ``destLevelIdIn``:
    destination level to move elements to

Parameter ``modelRefIn``:
    model ref

Parameter ``sourceLevelIdIn``:
    source level from which to elements from

Parameter ``inEntireFileIn``:
    if true, then move elements in entire file of modelRefIn, else
    move elements only in the specified model

Returns:
    ERROR if the model-ref or the level ids are invalid, else SUCCESS

Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_CopyElement =R"doc(@Description Copy elements in source level to destination level.

Parameter ``numElementCopiedOut``:
    number of elements copied

Parameter ``destModelRefIn``:
    destination model to copy elements to

Parameter ``destLevelIdIn``:
    destination level to copy elements to

Parameter ``sourceModelRefIn``:
    source model ref whose elements to copy

Parameter ``sourceLevelIdIn``:
    source level from which to copy elements from

Parameter ``inEntireFileIn``:
    if true, then move elements in entire file of sourceModelRefIn,
    else copy elements only in the specified model

Returns:
    ERROR if the model-ref or the level ids are invalid, else SUCCESS

Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_DeleteElement =R"doc(@Description Delete elements on specified level.

Parameter ``numElementDeletedOut``:
    number of elements deleted

Parameter ``modelRefIn``:
    source model ref whose elements to delete

Parameter ``levelIdIn``:
    source level from which to delete elements

Parameter ``inEntireFileIn``:
    if true, then delete elements in entire file that contains
    modelRefIn, else delete elements only in the specified model

Parameter ``updateViewIn``:
    if true, then update the views

Returns:
    ERROR if the model-ref or the level ids are invalid, else SUCCESS

Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_SelectElement =R"doc(@Description Select elements on specified level.

Parameter ``numElementSelectedOut``:
    number of elements selected

Parameter ``modelRefIn``:
    source model ref whose elements to copy

Parameter ``levelIdIn``:
    source level from which to copy elements from

Returns:
    ERROR if the model-ref or the level ids are invalid, else SUCCESS

Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_Draw =R"doc(@Description Draw all elements on specified level

@Param[in] viewDrawIn views to update. Should point to an array
dimensioned to DgnPlatform::MAX_VIEWS, and viewDraw[i] controls
whether view i is drawn. If NULL, all views are drawn.

Parameter ``incrementalIn``:
    if false, don't erase before drawing

Parameter ``drawModeIn``:
    erasing portion of drawing

Parameter ``modelRefIn``:
    model ref

Parameter ``levelIdIn``:
    level to draw

Parameter ``startEndMsgIn``:
    if true then want in prog/complete msg

Parameter ``drawSharedIn``:
    if true, then draw all models/attachments which use the same level

Returns:
    ERROR if the model-ref or level id is invalid, else SUCCESS

See also:
    Level.Draw Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_CopyLevel =R"doc(@Description Copy a level from source model into destination model.
Creates a new level in the destination model with the same level-name
& level-code as the source level.

Parameter ``levelIdOut``:
    id of new level in pDestModelRefIn

Parameter ``destModelRefIn``:
    destination model-ref to copy into

Parameter ``sourceModelRefIn``:
    source model ref

Parameter ``sourceLevelIdIn``:
    id of library level to copy

Parameter ``setExternalIn``:
    if true, then set the imported level as " external ". Should be true
    only if pSourceModelRef is LEVEL_LIBRARY_MODELREF.

Returns:
    SUCCESS if the level data is successfully copied.

Remark:
    s Possible return failure codes are:<DL COMPACT> <DT>
    **MSGID_errorTableIsReadOnly** <DD> the level-table of the
    destination model-ref is in a read-only state <DT>
    **MSGID_errorTableIsOfAttachment** <DD> the destination model-ref
    is for an attachment <DT> **ERROR** <DD> if model-ref or level id
    is invalid or the copy failed for some unspecified reason </DL>

Remark:
    s A successful level copy set raises a LEVEL_CHANGE_ATTRIBUTE
    event.

Remark:
    s Call LevelTable.Rewrite to save the updated level-table.

See also:
    LevelTable.Rewrite

Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_GetHidden =R"doc(@Description Get the hidden flag.

Parameter ``levelHiddenOut``:
    level hidden flag

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Returns:
    ERROR if the model-ref or level id is invalid, else SUCCESS

See also:
    LevelTable.GetHiddenMask Level.IsHidden Level.SetHidden
    Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_GetFrozen =R"doc(@Description Get the frozen flag

Parameter ``levelFrozenOut``:
    level frozen flag

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Parameter ``frozenTypeIn``:
    one of <TT>LEVEL_FROZEN_TYPE_</TT>... (defined in leveltable.h)

Returns:
    ERROR if the model-ref or level id is invalid, else SUCCESS

See also:
    LevelTable.GetFrozenMask LevelTable.SetFrozenMask
    LevelTable.GetDisplayFrozenMask Level.IsFrozen
    Level.SetFrozen Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_CopyLevelDataByAttributeMask =R"doc(@Description Copy level related data as specified by the level-
attributes mask from source level into destination level. This
function does not copy the level-name & level-code.

Parameter ``destModelRefIn``:
    destination model

Parameter ``destLevelIdIn``:
    destination level id

Parameter ``sourceModelRefIn``:
    source model

Parameter ``sourceLevelIdIn``:
    source level id

Parameter ``copyAttributesMaskIn``:
    mask of attributes to copy - will never copy level name

Returns:
    SUCCESS if the level data is successfully copied.

Remark:
    s Possible return failure codes are:<DL COMPACT> <DT>
    **MSGID_errorTableIsReadOnly** <DD> the level-table of the
    destination model-ref is in a read-only state <DT>
    **MSGID_errorLevelIsReadOnly** <DD> the specified destination
    level is in a read-only state <DT> **ERROR** <DD> if
    source/destination model-ref or level id is invalid or the copy
    failed for some unspecified reason </DL>

Remark:
    s A successful level copy raises a LEVEL_CHANGE_ATTRIBUTE event.

Remark:
    s Call LevelTable.Rewrite to save the updated level-table.

See also:
    LevelTable.Rewrite Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_CopyLevelData =R"doc(@Description Copy all level related data from source level into
destination level. This function does not copy the level-name & level-
code.

Parameter ``destModelRefIn``:
    destination model

Parameter ``destLevelIdIn``:
    destination level id

Parameter ``sourceModelRefIn``:
    source model

Parameter ``sourceLevelIdIn``:
    source level id

Returns:
    SUCCESS if the level data is successfully copied.

Remark:
    s Possible return failure codes are:<DL COMPACT> <DT>
    **MSGID_errorTableIsReadOnly** <DD> the level-table of the
    destination model-ref is in a read-only state <DT>
    **MSGID_errorLevelIsReadOnly** <DD> the specified destination
    level is in a read-only state <DT> **ERROR** <DD> if
    source/destination model-ref or level id is invalid or the copy
    failed for some unspecified reason </DL>

Remark:
    s A successful level copy raises a LEVEL_CHANGE_ATTRIBUTE event.

Remark:
    s Call LevelTable.Rewrite to save the updated level-table.

See also:
    LevelTable.Rewrite Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_CompareLevelData =R"doc(@Description Compare level related data between level1 and level2. The
function will compare only those attributes as specified in
pCompareAttributesMaskIn. If pCompareAttributesMaskIn is NULL, then
all the attributes will be compared.

Parameter ``compareAttributesOut``:
    if non-null, then return a set of bits that represent the
    attributes of the levels that are not the same.

Parameter ``modelRef1In``:
    model 1

Parameter ``levelId1In``:
    level id of model 1

Parameter ``modelRef2In``:
    model 2

Parameter ``levelId2In``:
    level id of model 2

Parameter ``compareAttributesIn``:
    mask of attributes to compare

Returns:
    true if the level data of the two levels matches for attributes
    specified in pCompareAttributesMaskIn

Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_SetReadOnly =R"doc(@Description Set level read-only on/off. Setting a level as read-only
means that its attributes cannot be changed. (exception:setting the
level's display on/off is not affected by this setting). A read-only
level cannot be deleted.

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Parameter ``isReadOnlyIn``:
    read-only flag - true or false

Returns:
    SUCCESS if the level read-only flag is successfully set.

Remark:
    s Possible return failure codes are:<DL COMPACT> <DT>
    **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
    only state <DT> **MSGID_errorTableIsOfAttachment** <DD> the
    specified model-ref is for an attachment <DT>
    **MSGID_errorLevelIsActive** <DD> the specified level is active
    and if setting the level to read-only <DT> **ERROR** <DD> if
    model-ref or level id is invalid or the level read-only flag
    cannot be set for some unspecified reason </DL>

Remark:
    s A successful level read-only flag set raises a
    LEVEL_CHANGE_ATTRIBUTE event.

Remark:
    s Call LevelTable.Rewrite to save the updated level-table.

See also:
    LevelTable.GetReadOnlyMask Level.GetReadOnly
    Level.IsReadOnly Level.Rewrite

See also:
    LevelTable.Rewrite

Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_SetTransparency =R"doc(@Description Set level display transparency. This sets the display
transparency to apply on an element of the level.

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Parameter ``transparencyIn``:
    level transparency (value between 0.0 & 1.0)

Returns:
    SUCCESS if the level transparency is successfully set.

Remark:
    s Possible return failure codes are:<DL COMPACT> <DT>
    **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
    only state <DT> **MSGID_errorLevelIsReadOnly** <DD> the specified
    level is in a read-only state <DT>
    **MSGID_errorCannotChangeExternalLevel** <DD> the specified level
    is a library level <DT> **ERROR** <DD> if model-ref or level id is
    invalid or the level color cannot be set for some unspecified
    reason </DL>

Remark:
    s A successful level transparency set raises a
    LEVEL_CHANGE_ATTRIBUTE event.

Remark:
    s Call LevelTable.Rewrite to save the updated level-table

See also:
    Level.GetTransparency LevelTable.Rewrite Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_SetDisplayPriority =R"doc(@Description Set level display priority

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Parameter ``priorityIn``:
    level priority - may be NULL

Returns:
    SUCCESS if the level priority is successfully set.

Remark:
    s Possible return failure codes are:<DL COMPACT> <DT>
    **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
    only state <DT> **MSGID_errorLevelIsReadOnly** <DD> the specified
    level is in a read-only state <DT>
    **MSGID_errorCannotChangeExternalLevel** <DD> the specified level
    is a library level <DT> **ERROR** <DD> if model-ref or level id is
    invalid or the level color cannot be set for some unspecified
    reason </DL>

Remark:
    s A successful priority set raises a LEVEL_CHANGE_ATTRIBUTE event.

Remark:
    s Call LevelTable.Rewrite to save the updated level-table

See also:
    Level.GetDisplayPriority LevelTable.Rewrite Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_SetHidden =R"doc(@Description Set level hidden on/off. A Hidden Level will not be
visible in the User Interface i.e. none of the Level Controls will
display such a level. Applications can use this together with Element
Access set to READ_ONLY/VIEW_ONLY to throw elements into the design
file that can only be viewed. Using regular Microstation, the user has
no control over such elements. By default Hidden is OFF

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Parameter ``hiddenIn``:
    hidden flag - true or false

Returns:
    SUCCESS if the level hidden flag is successfully set.

Remark:
    s Possible return failure codes are:<DL COMPACT> <DT>
    **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
    only state <DT> **MSGID_errorLevelIsReadOnly** <DD> the specified
    level is in a read-only state <DT>
    **MSGID_errorTableIsOfAttachment** <DD> the specified model-ref is
    for an attachment <DT> **ERROR** <DD> if model-ref or level id is
    invalid or the level hidden cannot be set for some unspecified
    reason </DL>

Remark:
    s A successful level hidden flag set raises a
    LEVEL_CHANGE_ATTRIBUTE event.

Remark:
    s Call LevelTable.Rewrite to save the updated level-table

See also:
    LevelTable.GetHiddenMask Level.GetHidden Level.IsHidden
    Level.Rewrite

See also:
    LevelTable.Rewrite Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_SetPlot =R"doc(@Description Set level plot on/off. Turning off the plot disables
plotting of all elements on the level.

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Parameter ``plotIn``:
    plot flag - true or false

Returns:
    SUCCESS if the level plot flag is successfully set.

Remark:
    s Possible return failure codes are:<DL COMPACT> <DT>
    **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
    only state <DT> **MSGID_errorLevelIsReadOnly** <DD> the specified
    level is in a read-only state <DT> **ERROR** <DD> if model-ref or
    level id is invalid or the level plot cannot be set for some
    unspecified reason </DL>

Remark:
    s A successful level plot flag set raises a LEVEL_CHANGE_ATTRIBUTE
    event.

Remark:
    s Call LevelTable.Rewrite to save the updated level-table

See also:
    LevelTable.GetPlotMask Level.GetPlot Level.Rewrite

See also:
    LevelTable.Rewrite Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_SetFrozen =R"doc(@Description Set level frozen on/off. Turning on the frozen makes all
the elements on the level invisible. This is like turning off the
display flag of a level with the following differences:<UL> <LI> If a
cell-instance is on a frozen level, then all the elements of the cell-
instance are not displayed, irrespective of the contained element's
level. <LI> If an attachment is on a frozen level, then the attachment
is not displayed. </UL>

Remark:
    s There are two types of frozen controls described as follows:<DL
    COMPACT> <DT> <TT>LEVEL_FROZEN_TYPE_GLOBAL</TT> <DD>Turning on the
    global frozen flag makes an element on the level invisible across
    every use of the element in the file. <DT>
    <TT>LEVEL_FROZEN_TYPE_VP_FREEZE</TT> <DD>Turning on the viewport
    frozen flag makes an element on the level invisible only in the
    context of the model-ref. The specified model-ref should be either
    a layout model-ref, or a viewport model-ref or an attachment
    model-ref of a layout or a viewport. If the specified model-ref is
    an attachment model-ref, then the global frozen flag is propagated
    to all the model-refs (within the layout or viewport) with same
    file-object as the specified model-ref. </DL>

Parameter ``modelRefIn``:
    model

Parameter ``levelIdIn``:
    level id

Parameter ``frozenTypeIn``:
    one of <TT>LEVEL_FROZEN_TYPE_GLOBAL</TT> or
    <TT>LEVEL_FROZEN_TYPE_VP_FREEZE</TT> (defined in leveltable.h)

Parameter ``frozenIn``:
    frozen flag - true or false

Returns:
    SUCCESS if the level freeze flag is successfully set.

Remark:
    s Possible return failure codes are:<DL COMPACT> <DT>
    **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
    only state <DT> **ERROR** <DD> if model-ref or level id is invalid
    or the level freeze cannot be set for some unspecified reason
    </DL>

Remark:
    s A successful level freeze flag raises a LEVEL_CHANGE_DISPLAY
    event.

Remark:
    s Call LevelTable.Rewrite to save the updated level-table

See also:
    LevelTable.GetFrozenMask LevelTable.SetFrozenMask
    LevelTable.GetDisplayFrozenMask Level.IsFrozen
    Level.GetFrozen Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_SetDisplay =R"doc(@Description Set level display on/off. Turning off the display makes
all the elements on the level invisible in all the views.

Remark:
    s Call View.SetLevelDisplay to control the level display in a
    specific view.

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Parameter ``displayIn``:
    display flag - true or false

Returns:
    SUCCESS if the level display flag is successfully set.

Remark:
    s Possible return failure codes are:<DL COMPACT> <DT>
    **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
    only state <DT> **ERROR** <DD> if model-ref or level id is invalid
    or the level display cannot be set for some unspecified reason
    </DL>

Remark:
    s A successful level display flag raises a LEVEL_CHANGE_DISPLAY
    event.

Remark:
    s Call LevelTable.Rewrite to save the updated level-table

See also:
    Level.SetDisplayMask Level.GetDisplayMask
    Level.GetDisplay Level.Rewrite View.SetLevelDisplay
    View.GetLevelDisplay

See also:
    LevelTable.Rewrite Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_SetElementAccess =R"doc(@Description Set the level's element access mode. This can take one of
4 values - LevelElementAccess::All, LevelElementAccess::Locked,
LevelElementAccess::ReadOnly & LevelElementAccess::ViewOnly. The mode
applies to elements on the level. The meaning attached to each of the
modes is:<TABLE border=" 1 " cellspacing=" 3 " cellpadding=" 3 "> <TR>
<TH>Access Mode</TH> <TH>Meaning</TH> </TR> <TR>
<TD><TT>LevelElementAccess::All</TT></TD> <TD>Elements on the level
have all access. This is the default mode.</TD> </TR> <TR>
<TD><TT>LevelElementAccess::Locked</TT></TD> <TD>Elements on the level
are locked. They can be copied, but cannot be modified or deleted. New
elements can be added to the level - once added they are immediately
locked. The level can be set active.</TD> </TR> <TR>
<TD><TT>LevelElementAccess::ReadOnly</TT></TD> <TD>Elements on the
level are for read-only purposes. They cannot be modified or deleted.
The elements may be copied into another level. The level cannot be set
active.</TD> </TR> <TR> <TD><TT>LevelElementAccess::ViewOnly</TT></TD>
<TD>Elements on the level can only be viewed. They cannot be copied,
modified or deleted. The level cannot be set active.</TD> </TR>
</TABLE>

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Parameter ``elementAccessIn``:
    element access - one of <TT>LEVEL_ELEMENT_ACCESS_</TT>... (defined
    in leveltypes.h)

Returns:
    SUCCESS if the level element access is successfully set.

Remark:
    s Possible return failure codes are:<DL COMPACT> <DT>
    **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
    only state <DT> **MSGID_errorLevelIsReadOnly** <DD> the specified
    level is in a read-only state <DT>
    **MSGID_errorTableIsOfAttachment** <DD> the specified model-ref is
    for an attachment <DT> **ERROR** <DD> if model-ref or level id is
    invalid or the level element access cannot be set for some
    unspecified reason </DL>

Remark:
    s A successful level element access raises a
    LEVEL_CHANGE_ATTRIBUTE event.

Remark:
    s Call LevelTable.Rewrite to save the updated level-table

See also:
    Level.GetElementAccess LevelTable.Rewrite

See also:
    LevelTable.Rewrite Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_SetElementSymbology =R"doc(@Description Set element symbology. This functions allows setting the
one or more of the element color, style, weight & fill color
simultaneously.

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Parameter ``colorIn``:
    element color - maybe NULL

Parameter ``styleIn``:
    element style - maybe NULL

Parameter ``styleParamsIn``:
    custom line style modifiers - maybe NULL

Parameter ``weightIn``:
    element weight - maybe NULL

Returns:
    SUCCESS if the level element fill color is successfully set.

Remark:
    s Possible return failure codes are:<DL COMPACT> <DT>
    **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
    only state <DT> **MSGID_errorLevelIsReadOnly** <DD> the specified
    level is in a read-only state <DT>
    **MSGID_errorCannotChangeExternalLevel** <DD> the specified level
    is a library level <DT> **MSGID_errorElementAccessIsReadOnly**
    <DD> the element-access for the level is atleast
    LevelElementAccess::ReadOnly <DT> **ERROR** <DD> if model-ref or
    level id is invalid or the level element symbology cannot be set
    for some unspecified reason </DL>

Remark:
    s A successful level element symbology set raises a
    LEVEL_CHANGE_ATTRIBUTE event.

Remark:
    s Call LevelTable.Rewrite to save the updated level-table

Remark:
    s If modelRefIn is a DgnPlatform::DgnAttachment, then colorIn and
    styleIn (if defined) *must* identify color and style in the
    referenced file.

See also:
    Level.GetElementSymbology LevelTable.Rewrite

See also:
    LevelTable.Rewrite Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_SetElementWeight =R"doc(@Description Set element weight. This sets the style to apply on an
element of the level, when the element has its weight set to BYLEVEL.
This is also be termed as the level's BYLEVEL weight.

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Parameter ``weightIn``:
    element weight

Returns:
    SUCCESS if the level element weight is successfully set.

Remark:
    s Possible return failure codes are:<DL COMPACT> <DT>
    **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
    only state <DT> **MSGID_errorLevelIsReadOnly** <DD> the specified
    level is in a read-only state <DT>
    **MSGID_errorCannotChangeExternalLevel** <DD> the specified level
    is a library level <DT> **MSGID_errorElementAccessIsReadOnly**
    <DD> the element-access for the level is atleast
    LevelElementAccess::ReadOnly <DT> **ERROR** <DD> if model-ref or
    level id is invalid or the element weight cannot be set for some
    unspecified reason </DL>

Remark:
    s A successful level element weight set raises a
    LEVEL_CHANGE_ATTRIBUTE event.

Remark:
    s Call LevelTable.Rewrite to save the updated level-table

See also:
    Level.GetElementWeight Level.GetElementSymbology
    Level.SetElementSymbology LevelTable.Rewrite

See also:
    Level.GetElementSymbology Level.SetElementSymbology
    LevelTable.Rewrite Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_SetElementStyle =R"doc(@Description Set element style. This sets the style to apply on an
element of the level, when the element has its style set to BYLEVEL.
This is also be termed as the level's BYLEVEL style.

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Parameter ``styleIn``:
    element style - maybe NULL

Parameter ``styleParamsIn``:
    custom line style modifiers - maybe NULL

Returns:
    SUCCESS if the level element style is successfully set.

Remark:
    s Possible return failure codes are:<DL COMPACT> <DT>
    **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
    only state <DT> **MSGID_errorLevelIsReadOnly** <DD> the specified
    level is in a read-only state <DT>
    **MSGID_errorCannotChangeExternalLevel** <DD> the specified level
    is a library level <DT> **MSGID_errorElementAccessIsReadOnly**
    <DD> the element-access for the level is atleast
    LevelElementAccess::ReadOnly <DT> **ERROR** <DD> if model-ref or
    level id is invalid or the element style cannot be set for some
    unspecified reason </DL>

Remark:
    s A successful level element style set raises a
    LEVEL_CHANGE_ATTRIBUTE event.

Remark:
    s Call LevelTable.Rewrite to save the updated level-table

Remark:
    s If modelRefIn is a DgnPlatform::DgnAttachment, then styleIn (if
    defined) is assumed to identify a style in the referenced file.

See also:
    Level.GetElementStyle Level.GetElementSymbology
    Level.SetElementSymbology LevelTable.Rewrite

See also:
    Level.GetElementSymbology Level.SetElementSymbology
    LevelTable.Rewrite Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_SetElementMaterialId =R"doc(@Description Set level element material id.

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Parameter ``materialIdIn``:
    material id

Returns:
    SUCCESS if the level color is successfully set.

Remark:
    s Possible return failure codes are:<DL COMPACT> <DT>
    **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
    only state <DT> **MSGID_errorLevelIsReadOnly** <DD> the specified
    level is in a read-only state <DT>
    **MSGID_errorCannotChangeExternalLevel** <DD> the specified level
    is a library level <DT> **ERROR** <DD> if model-ref or level id is
    invalid or the level color cannot be set for some unspecified
    reason </DL>

Remark:
    s A successful level material id set raises a
    LEVEL_CHANGE_ATTRIBUTE event.

Remark:
    s Call LevelTable.Rewrite to save the updated level-table

Remark:
    s If modelRefIn is a DgnPlatform::DgnAttachment, materialIdIn is
    assumed to identify a material in the referenced file.

See also:
    Level.GetElementMaterialId Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_SetElementColor =R"doc(@Description Set element color. This sets the color to apply on an
element of the level, when the element has its color set to BYLEVEL.
This is also be termed as the level's BYLEVEL color.

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Parameter ``colorIn``:
    element color

Returns:
    SUCCESS if the level element color is successfully set.

Remark:
    s Possible return failure codes are:<DL COMPACT> <DT>
    **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
    only state <DT> **MSGID_errorLevelIsReadOnly** <DD> the specified
    level is in a read-only state <DT>
    **MSGID_errorCannotChangeExternalLevel** <DD> the specified level
    is a library level <DT> **MSGID_errorElementAccessIsReadOnly**
    <DD> the element-access for the level is atleast
    LevelElementAccess::ReadOnly <DT> **ERROR** <DD> if model-ref or
    level id is invalid or the element color cannot be set for some
    unspecified reason </DL>

Remark:
    s A successful level element color set raises a
    LEVEL_CHANGE_ATTRIBUTE event.

Remark:
    s Call LevelTable.Rewrite to save the updated level-table *

Remark:
    s If modelRefIn is a DgnPlatform::DgnAttachment, then colorIn (if
    defined) is assumed to identify a color in the referenced file.

See also:
    Level.GetElementColor Level.GetElementSymbology
    Level.SetElementSymbology LevelTable.Rewrite

See also:
    Level.GetElementSymbology Level.SetElementSymbology
    LevelTable.Rewrite Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_SetWeight =R"doc(@Description Set level weight. This sets the weight to apply on an
element of the level, when " level symbology " is turned on for the
view. This is also termed as the level's OVERRIDE weight. Note that
this function has an additional " override " flag. The " override " flag
has to be ON in order to use the weight.

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Parameter ``weightIn``:
    level weight

Parameter ``weightOverrideIn``:
    level weight override - true or false

Returns:
    SUCCESS if the level weight is successfully set.

Remark:
    s Possible return failure codes are:<DL COMPACT> <DT>
    **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
    only state <DT> **MSGID_errorLevelIsReadOnly** <DD> the specified
    level is in a read-only state <DT>
    **MSGID_errorCannotChangeExternalLevel** <DD> the specified level
    is a library level <DT> **ERROR** <DD> if model-ref or level id is
    invalid or the level weight cannot be set for some unspecified
    reason </DL>

Remark:
    s A successful level weight set raises a LEVEL_CHANGE_ATTRIBUTE
    event.

Remark:
    s Call LevelTable.Rewrite to save the updated level-table

See also:
    Level.GetWeight Level.GetSymbology Level.SetSymbology
    LevelTable.Rewrite

See also:
    LevelTable.Rewrite Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_SetStyle =R"doc(@Description Set level style. This sets the style to apply on an
element of the level, when " level symbology " is turned on for the
view. This is also termed as the level's OVERRIDE style. Note that
this function has an additional " override " flag. The " override " flag
has to be ON in order to use the style.

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Parameter ``styleIn``:
    level style - may be NULL

Parameter ``styleParamsIn``:
    custom line style modifiers - may be NULL

Parameter ``styleOverrideIn``:
    level style override (true or false) - may be NULL

Returns:
    SUCCESS if the level style is successfully set.

Remark:
    s Possible return failure codes are:<DL COMPACT> <DT>
    **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
    only state <DT> **MSGID_errorLevelIsReadOnly** <DD> the specified
    level is in a read-only state <DT>
    **MSGID_errorCannotChangeExternalLevel** <DD> the specified level
    is a library level <DT> **ERROR** <DD> if model-ref or level id is
    invalid or the level style cannot be set for some unspecified
    reason </DL>

Remark:
    s A successful level style set raises a LEVEL_CHANGE_ATTRIBUTE
    event.

Remark:
    s Call LevelTable.Rewrite to save the updated level-table

Remark:
    s If modelRefIn is a DgnPlatform::DgnAttachment, then piStyleIn
    (if defined) is assumed to identify a style in the referenced
    file.

See also:
    Level.GetStyle Level.GetSymbology
    msmthLevel.SetSymbologyC LevelTable.Rewrite

See also:
    Level.GetSymbology Level.SetSymbology LevelTable.Rewrite
    Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_SetMaterialId =R"doc(@Description Set level material id.

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Parameter ``materialIdIn``:
    material id - may be NULL

Parameter ``materialOverrideIn``:
    material override (true or false) - may be NULL

Returns:
    SUCCESS if the level color is successfully set.

Remark:
    s Possible return failure codes are:<DL COMPACT> <DT>
    **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
    only state <DT> **MSGID_errorLevelIsReadOnly** <DD> the specified
    level is in a read-only state <DT>
    **MSGID_errorCannotChangeExternalLevel** <DD> the specified level
    is a library level <DT> **ERROR** <DD> if model-ref or level id is
    invalid or the level color cannot be set for some unspecified
    reason </DL>

Remark:
    s A successful level material id set raises a
    LEVEL_CHANGE_ATTRIBUTE event.

Remark:
    s Call LevelTable.Rewrite to save the updated level-table

Remark:
    s If modelRefIn is a DgnPlatform::DgnAttachment, materialIdIn is
    assumed to identify a material in the referenced file.

See also:
    Level.GetMaterialId Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_SetColor =R"doc(@Description Set level color. This sets the color to apply on an
element of the level, when " level symbology " is turned on for the
view. This is also termed as the level's OVERRIDE color. Note that
this function has an additional " override " flag. The " override " flag
has to be ON in order to use the color.

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Parameter ``colorIn``:
    level color - may be NULL

Parameter ``colorOverrideIn``:
    level color override (true or false) - may be NULL

Returns:
    SUCCESS if the level color is successfully set.

Remark:
    s Possible return failure codes are:<DL COMPACT> <DT>
    **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
    only state <DT> **MSGID_errorLevelIsReadOnly** <DD> the specified
    level is in a read-only state <DT>
    **MSGID_errorCannotChangeExternalLevel** <DD> the specified level
    is a library level <DT> **ERROR** <DD> if model-ref or level id is
    invalid or the level color cannot be set for some unspecified
    reason </DL>

Remark:
    s A successful level color set raises a LEVEL_CHANGE_ATTRIBUTE
    event.

Remark:
    s Call LevelTable.Rewrite to save the updated level-table

Remark:
    s If modelRefIn is a DgnPlatform::DgnAttachment, then colorIn (if
    defined) is assumed to identify a color in the referenced file.

See also:
    Level.GetColor Level.GetSymbology Level.SetSymbology
    LevelTable.Rewrite

See also:
    Level.GetSymbology Level.SetSymbology LevelTable.Rewrite
    Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_SetDescription =R"doc(@Description Set level description

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Parameter ``descriptionIn``:
    level name

Returns:
    SUCCESS if the level description is successfully set.

Remark:
    s Possible return failure codes are:<DL COMPACT> <DT>
    **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
    only state <DT> **MSGID_errorCannotChangeAttachmentLevelCode**
    <DD> the specified model-ref is for an attachment <DT>
    **MSGID_errorLevelIsReadOnly** <DD> the specified level is in a
    read-only state <DT> **MSGID_errorCannotChangeExternalLevel** <DD>
    the specified level is a library level <DT> **ERROR** <DD> if
    model-ref or level id is invalid or the level description cannot
    be set for some unspecified reason </DL>

Remark:
    s A successful level description set raises a
    LEVEL_CHANGE_ATTRIBUTE event.

Remark:
    s Call LevelTable.Rewrite to save the updated level-table

See also:
    Level.GetDescription LevelTable.Rewrite

See also:
    LevelTable.Rewrite

Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_SetCode =R"doc(@Description Set level code. A level's code should be unique in the
context of all the levels in a level-table i.e. all level codes in the
context of a level-table should be unique.

Remark:
    s A level code is displayed under the " Number " column of the
    level-manager.

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Parameter ``levelCodeIn``:
    level code

Returns:
    SUCCESS if the level code is successfully set.

Remark:
    s Possible return failure codes are:<DL COMPACT> <DT>
    **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
    only state <DT> **MSGID_errorCannotChangeAttachmentLevelCode**
    <DD> the specified model-ref is for an attachment <DT>
    **MSGID_errorLevelIsReadOnly** <DD> the specified level is in a
    read-only state <DT> **MSGID_errorCannotChangeExternalLevel** <DD>
    the specified level is a library level <DT>
    **MSGID_errorCannotChangeDefaultLevelCode** <DD> the specified
    level is the default level <DT> **MSGID_errorLevelCodeIsNull**
    <DD> the specified level code is LEVEL_NULL_CODE <DT>
    **MSGID_errorLevelCodeIsDuplicate** <DD> the specified level code
    is duplicate <DT> **ERROR** <DD> if model-ref or level id is
    invalid or the level code cannot be set for some unspecified
    reason </DL>

Remark:
    s A successful level code set raises a LEVEL_CHANGE_CODE event.

Remark:
    s Call LevelTable.Rewrite to save the updated level-table

See also:
    Level.GetCode LevelTable.Rewrite

See also:
    LevelTable.Rewrite

Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_SetName =R"doc(@Description Set level name. A level's name should be unique in the
level table.

Remark:

Remark:
    s A space character is valid character, though leading and
    trailing spaces are disallowed. This function will strip off
    leading and trailing spaces from the specified name.

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Parameter ``nameIn``:
    level name

Returns:
    SUCCESS if the level is successfully renamed.

Remark:
    s Possible return failure codes are:<DL COMPACT> <DT>
    **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
    only state <DT> **MSGID_errorCannotChangeAttachmentLevelName**
    <DD> the specified model-ref is for an attachment <DT>
    **MSGID_errorLevelIsReadOnly** <DD> the specified level is in a
    read-only state <DT> **MSGID_errorCannotChangeExternalLevel** <DD>
    the specified level is a library level <DT>
    **MSGID_errorCannotChangeDefaultLevelName** <DD> the specified
    level is the default level <DT> **MSGID_errorLevelNameIsNull**
    <DD> the specified level name is null <DT>
    **MSGID_errorLevelNameIsInvalid** <DD> the specified level name
    has invalid characters <DT> **MSGID_errorLevelNameIsDuplicate**
    <DD> the specified level name is duplicate <DT> **ERROR** <DD> if
    model-ref or level id is invalid or the level name cannot be set
    for some unspecified reason </DL>

Remark:
    s A successful level name set raises a LEVEL_CHANGE_NAME event.

Remark:
    s Call LevelTable.Rewrite to save the updated level-table

See also:
    Level.GetName Level.GetPathName
    LevelName.HasValidCharacters
    LevelName.ReplaceInvalidCharacters LevelTable.Rewrite

See also:
    LevelTable.Rewrite Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_Delete =R"doc(@Description Delete a level.

Remark:
    s A level can be deleted only in the context of the current file
    (i.e. modelRefIn should be a root-model of the current file).

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id to delete

Returns:
    SUCCESS if the level is successfully deleted.

Remark:
    s Possible return failure codes are:<DL COMPACT> <DT>
    **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
    only state <DT> **MSGID_errorCannotDeleteAttachmentLevel** <DD>
    the specified model-ref is for an attachment <DT>
    **MSGID_errorLevelIsReadOnly** <DD> the specified level is in a
    read-only state <DT> **MSGID_errorLevelIsUsed** <DD> the specified
    level is used by some element in the file <DT>
    **MSGID_errorCannotDeleteExternalLevel** <DD> the specified level
    is a library level <DT> **MSGID_errorCannotDeleteDefaultLevel**
    <DD> the specified level is the default level <DT>
    **MSGID_errorCannotDeleteDefpointsLevel** <DD> the specified level
    is the DWG DEFPOINTS level <DT> **ERROR** <DD> if model-ref or
    level-id is invalid or the level cannot be deleted for some
    unspecified reason </DL>

Remark:
    s A successful level delete raises a LEVEL_DELETE event.

Remark:
    s Call LevelTable.Rewrite to save the updated level-table

See also:
    Level.Create LevelTable.Rewrite

See also:
    LevelTable.Rewrite Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_CreateFromSeed =R"doc(@Description Create a new level. The new level takes its attributes as
specified " copyAttributeMaskIn " from the " seed " level. Typically,
" copyAttributeMaskIn " is got by calling function
<i>LevelAttribute.GetMask
(MS_LEVEL_CREATE_FROM_SEED_ATTRIBUTE_MASK)</i>

Parameter ``levelIdOut``:
    level id of new level

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelNameIn``:
    level name of new level

Parameter ``levelCodeIn``:
    level code of new level - maybe LEVEL_NULL_CODE.

Parameter ``seedLevelIdIn``:
    seed level

Parameter ``copyAttributeMaskIn``:
    seed level

Returns:
    SUCCESS if level is successfully created.

Remark:
    s A successful level create raises a LEVEL_CREATE event.

Remark:
    s Call LevelTable.Rewrite to save the updated level-table

See also:
    Level.Create usmtnLevel.GetSeedLevelC LevelTable.Rewrite

See also:
    LevelTable.Rewrite Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_Create =R"doc(@Description Create a new level.

Remark:
    s A new level can be created only in the context of the current
    file (i.e. specified model-ref should be a root-model of the
    current file).

Remark:
    s The specified level-name should be unique in the context of the
    all other root levels of the level-table. Otherwise the level is
    not created.

Remark:
    s The specified level-code should be unique in the context of the
    entire level-table. Otherwise the level is not created.
    LEVEL_NULL_CODE can be specified for the level-code, in which
    case, Level.Create will automatically generate a unique level-
    code and assign it to the new level. Such a level-code will be
    termed as a " system - assigned " level-code.

Parameter ``levelIdOut``:
    level id of new level

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelNameIn``:
    level name of new level

Parameter ``levelCodeIn``:
    level code of new level - maybe LEVEL_NULL_CODE.

Returns:
    SUCCESS if level is successfully created.

Remark:
    s Possible return failure codes are:<DL COMPACT> <DT>
    **MSGID_errorTableIsReadOnly** <DD> the level-table is in a read-
    only state <DT> **MSGID_errorCannotCreateNewAttachmentLevel** <DD>
    the specified model-ref is for an attachment <DT>
    **MSGID_errorLevelNameIsDuplicate** <DD> the specified level-name
    is duplicate <DT> **MSGID_errorLevelCodeIsDuplicate** <DD> the
    specified level-code is duplicate <DT> **ERROR** <DD> if the
    model-ref is invalid or the new level cannot be created for some
    unspecified reason </DL>

Remark:
    s A successful level create raises a LEVEL_CREATE event.

Remark:
    s Call LevelTable.Rewrite to save the updated level-table

See also:
    Level.Delete LevelTable.Rewrite

See also:
    LevelTable.Rewrite Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_GetTransparency =R"doc(@Description Get level display transparency

Parameter ``transparencyOut``:
    level display transparency (value between 0.0 & 1.0)

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Returns:
    ERROR if the model-ref or level id is invalid, else SUCCESS

See also:
    Level.SetTransparency Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_GetDisplayPriority =R"doc(@Description Get level display priority

Parameter ``priorityOut``:
    level display priority

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Returns:
    ERROR if the model-ref or level id is invalid, else SUCCESS

See also:
    Level.SetDisplayPriority Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_GetElementCount =R"doc(@Description Get the the number of elements of specified model-ref
that use specified level.

Parameter ``usageCountOut``:
    number of elements that use the level

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Returns:
    ERROR if the model-ref or level id is invalid, else SUCCESS

See also:
    Level.GetUsageMask Level.IsUsed Level.GetUsage
    Level.ReportUsage Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_ReportUsage =R"doc(@Description Generate a report that describes where a level is used in
the context of the file of specified model-ref

Parameter ``reportStringOut``:
    report string

Parameter ``modelRefIn``:
    model ref

Parameter ``levelIdIn``:
    level id

Returns:
    ERROR if the model-ref or level id is invalid, else SUCCESS

See also:
    Level.GetUsageMask Level.IsUsed Level.GetUsage
    Level.GetElementCount Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_GetUsage =R"doc(@Description Get the level usage flag.

Parameter ``usageOut``:
    usage flag - true or false

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Parameter ``inFile``:
    if true, then check the level is used in the entire file

Returns:
    ERROR if the model-ref or level id is invalid, else SUCCESS

Remark:
    s <UL> <LI> If *pUsageOut is true, then the level is used. <LI> If
    *pUsageOut is false, then the level is not used. </UL>

See also:
    Level.GetUsageMask Level.IsUsed Level.ReportUsage
    Level.GetElementCount Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_IsUsed =R"doc(@Description Check if a level is used. A level is used if there is an
element on the level.

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Parameter ``inFile``:
    if false, then check if a level is used in the context of
    modelRefIn only. if true, then returns if a level is used in the
    entire file of modelRefIn.

Returns:
    true if the level is used, else false

See also:
    Level.GetUsageMask Level.GetUsage Level.ReportUsage
    Level.GetElementCount Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_GetIdFromCodeIncludingLibraries =R"doc(@Description Given a level-code, get its level-id, including levels
that are in level libraries.

Parameter ``levelIdOut``:
    level id

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelCodeIn``:
    level code

Returns:
    SUCCESS if the level-id is successfully returned.

See also:
    Level.GetIdFromCode

Remark:
    s Possible return failure codes are:<DL COMPACT> <DT>
    **MSGID_errorLevelCodeIsInvalid** <DD> the level-code is not valid
    <DT> **ERROR** <DD> if the model-ref is invalid or the level
    cannot be returned for some unspecified reason </DL>

See also:
    Level.GetIdFromName Level.GetIdFromElementId
    Level.GetIdFromElementRef Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_GetIdFromCode =R"doc(@Description Given a level-code, get its level-id.

Parameter ``levelIdOut``:
    level id

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelCodeIn``:
    level code

Returns:
    SUCCESS if the level-id is successfully returned.

Remark:
    s This function does not look in level libraries.

See also:
    Level.GetIdFromCodeIncludingLibraries

Remark:
    s Possible return failure codes are:<DL COMPACT> <DT>
    **MSGID_errorLevelCodeIsInvalid** <DD> the level-code is not valid
    <DT> **ERROR** <DD> if the model-ref is invalid or the level
    cannot be returned for some unspecified reason </DL>

See also:
    Level.GetIdFromName Level.GetIdFromElementId
    Level.GetIdFromElementRef Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_GetIdFromNameIncludingLibraries =R"doc(@Description Given a level-name, get its level-id, including levels
that are in level libraries.

Parameter ``levelIdOut``:
    level id

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelNameIn``:
    level name

Returns:
    SUCCESS if the level-id is successfully returned.

See also:
    Level.GetIdFromName

Remark:
    s Possible return failure codes are:<DL COMPACT> <DT>
    **MSGID_errorLevelNameIsInvalid** <DD> the level-name is not valid
    <DT> **ERROR** <DD> if the model-ref is invalid or the level
    cannot be returned for some unspecified reason </DL>

See also:
    Level.GetIdFromCode Level.GetIdFromElementId
    Level.GetIdFromElementRef Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_GetIdFromName =R"doc(@Description Given a level-name, get its level-id.

Parameter ``levelIdOut``:
    level id

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelNameIn``:
    level name

Returns:
    SUCCESS if the level-id is successfully returned.

Remark:
    s This function does not look in level libraries.

See also:
    Level.GetIdFromNameIncludingLibraries

Remark:
    s Possible return failure codes are:<DL COMPACT> <DT>
    **MSGID_errorLevelNameIsInvalid** <DD> the level-name is not valid
    <DT> **ERROR** <DD> if the model-ref is invalid or the level
    cannot be returned for some unspecified reason </DL>

See also:
    Level.GetIdFromCode Level.GetIdFromElementId
    Level.GetIdFromElementRef Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_GetUniqueID =R"doc(@Description Get the level element's unique ID. The level element's
unique id is assigned by the system and cannot be modified. This
unique ID should not be confused with the level id returned by
Level.GetIdFromName (or Level.GetIdFromCode or
LevelIterator.GetFirst ..). The unique ID is an Int64 is stored at
element->ehdr.uniqueId and is unique in the context of a file-object.
The level-id is also system assigned, but is a UInt and is unique in
the context of a level-table.

Parameter ``uniqueIDOut``:
    unique ID

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Returns:
    ERROR if the model-ref or level id is invalid, else SUCCESS

Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_IsFrozen =R"doc(@Description Check if a level is frozen.

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Parameter ``frozenTypeIn``:
    one of <TT>LEVEL_FROZEN_TYPE_</TT>... (defined in leveltable.h)

Returns:
    true if the level is frozen, else false

See also:
    LevelTable.GetFrozenMask LevelTable.SetFrozenMask
    LevelTable.GetDisplayFrozenMask Level.GetFrozen
    Level.SetFrozen Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_IsReadOnly =R"doc(@Description Check if a level is read-only.

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Returns:
    true if the level is read-only, else false

See also:
    LevelTable.GetReadOnlyMask Level.GetReadOnly
    Level.SetReadOnly Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_IsHidden =R"doc(@Description Check if a level is hidden.

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Returns:
    true if the level is hidden, else false

See also:
    LevelTable.GetHiddenMask Level.GetHidden Level.SetHidden
    Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_IsExternal =R"doc(@Description Check if a level is an external (library) level or not.

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Returns:
    true if the level is external, else false

See also:
    LevelTable.GetExternalMask Level.GetExternal
    Level.GetLibraryRef Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_GetAttributesDifferFromSource =R"doc(@Description Get the 'level's attributes differ from source' flag.

Parameter ``levelDifferOut``:
    true if the level differs from its source

Parameter ``differencesMaskOut``:
    list of attributes which differ.

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Returns:
    ERROR if the model-ref or level id is invalid, else SUCCESS

Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_GetPlot =R"doc(@Description Get the plot flag.

Parameter ``levelPlotOut``:
    level plot flag

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Returns:
    ERROR if the model-ref or level id is invalid, else SUCCESS

See also:
    LevelTable.GetPlotMask Level.SetPlot Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_GetDisplay =R"doc(@Description Get the display flag.

Parameter ``levelDisplayOut``:
    level display flag - true or false

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Returns:
    ERROR if the model-ref or level id is invalid, else SUCCESS

See also:
    Level.SetDisplayMask Level.GetDisplayMask
    Level.SetDisplay Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_IsElementViewOnly =R"doc(@Description Check if elements on the specified level are view-only

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Returns:
    true if the level's element-access is view-only, else false

See also:
    Level.SetElementAccess Level.GetElementAccess

Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_IsElementReadOnly =R"doc(@Description Check if elements on the specified level are read-only

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Returns:
    true if the level's element-access is atleast read-only, else
    false

See also:
    Level.SetElementAccess Level.GetElementAccess Bentley
    Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_IsElementLocked =R"doc(@Description Check if elements on the specified level are locked.

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Returns:
    true if the level's element-access is atleast locked, else false,
    else SUCCESS

See also:
    Level.SetElementAccess Level.GetElementAccess Bentley
    Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_GetElementAccess =R"doc(@Description Get the element access mode.

Parameter ``elementAccessOut``:
    element access - one of <TT>LEVEL_ELEMENT_ACCESS_</TT>... (defined
    in leveltypes.h)

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Returns:
    ERROR if the model-ref or level id is invalid, else SUCCESS

See also:
    Level.SetElementAccess Level.IsElementLocked
    Level.IsElementReadOnly Level.IsElementViewOnly Bentley
    Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_GetElementSymbology =R"doc(@Description Get the element symbology.

Parameter ``elementColorOut``:
    element color

Parameter ``elementStyleOut``:
    element style

Parameter ``elementStyleParamsOut``:
    custom line style modifiers

Parameter ``elementWeightOut``:
    element weight

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Returns:
    ERROR if the model-ref or level id is invalid, else SUCCESS

See also:
    Level.SetElementSymbology Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_GetElementWeight =R"doc(@Description Get the level element weight. This weight value is
applied on an element when the the element's weight is set to BYLEVEL.

Parameter ``weightOut``:
    element weight

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Returns:
    ERROR if the model-ref or level id is invalid, else SUCCESS

See also:
    Level.SetElementWeight Level.GetElementSymbology
    Level.SetElementSymbology

See also:
    Level.GetElementSymbology Level.SetElementSymbology Bentley
    Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_GetElementStyle =R"doc(@Description Get the level element style and custom-line style
override info. This style value is applied on an element when the
element's style is set to BYLEVEL.

Parameter ``styleOut``:
    element style

Parameter ``styleParamsOut``:
    custom line style modifiers

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Returns:
    ERROR if the model-ref or level id is invalid, else SUCCESS

See also:
    Level.SetElementStyle Level.GetElementSymbology
    Level.SetElementSymbology

See also:
    Level.GetElementSymbology Level.SetElementSymbology Bentley
    Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_GetElementMaterialId =R"doc(@Description Get level element material id associated with the level.

Parameter ``materialIdOut``:
    element material id

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Returns:
    ERROR if the model-ref or level id is invalid, else SUCCESS

See also:
    Level.SetElementMaterialId Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_GetElementColor =R"doc(@Description Get the level element color. This color value is applied
on an element when the element's color is set to BYLEVEL.

Parameter ``colorOut``:
    element color

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Returns:
    ERROR if the model-ref or level id is invalid, else SUCCESS

See also:
    Level.SetElementColor Level.GetElementSymbology
    Level.SetElementSymbology

See also:
    Level.GetElementSymbology Level.SetElementSymbology Bentley
    Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_GetSymbology =R"doc(@Description Get the level symbology and symbology-override flags.

Parameter ``colorOut``:
    color

Parameter ``colorOverrideOut``:
    color override - true or false

Parameter ``styleOut``:
    style

Parameter ``styleParamsOut``:
    custom line style modifiers

Parameter ``styleOverrideOut``:
    style override - true or false

Parameter ``weightOut``:
    weight

Parameter ``weightOverrideOut``:
    weight override - true or false

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Returns:
    ERROR if the model-ref or level id is invalid, else SUCCESS

See also:
    Level.SetSymbology Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_GetWeight =R"doc(@Description Get the level weight and weight-override flag. An element
is displayed with this style in a view when the weight-override flag
is true and when level-symbology for the view is turned ON.

Parameter ``weightOut``:
    level weight

Parameter ``weightOverrideOut``:
    level weight override - true or false

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Returns:
    ERROR if the model-ref or level id is invalid, else SUCCESS

See also:
    Level.SetWeight Level.GetSymbology Level.SetSymbology

See also:
    Level.GetSymbology Level.SetSymbology Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_GetStyle =R"doc(@Description Get the level style, custom-line style override info and
style-override flag. An element is displayed with this style in a view
when the style-override flag is true and when level-symbology for the
view is turned ON.

Parameter ``styleOut``:
    level style

Parameter ``styleParamsOut``:
    custom line style modifiers

Parameter ``styleOverrideOut``:
    level style override - true or false

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Returns:
    ERROR if the model-ref or level id is invalid, else SUCCESS

See also:
    Level.SetStyle Level.GetSymbology Level.SetSymbology

See also:
    Level.GetSymbology Level.SetSymbology Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_GetMaterialId =R"doc(@Description Get material id associated with the level.

Parameter ``materialIdOut``:
    level material id

Parameter ``materialOverrideOut``:
    level material override

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Returns:
    ERROR if the model-ref or level id is invalid, else SUCCESS

See also:
    Level.SetMaterialId Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_GetColor =R"doc(@Description Get level color and color-override flag. An element is
displayed with this color in a view when the color-override flag is
true and when level-symbology for the view is turned ON.

Parameter ``colorOut``:
    level color

Parameter ``colorOverrideOut``:
    level color override - true or false

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Returns:
    ERROR if the model-ref or level id is invalid, else SUCCESS

See also:
    Level.SetColor Level.GetSymbology Level.SetSymbology

See also:
    Level.GetSymbology Level.SetSymbology Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_GetDescription =R"doc(@Description Get level description.

Parameter ``descriptionOut``:
    level description

Parameter ``stringSizeIn``:
    number of characters pLevelDescriptionOut can hold

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Returns:
    ERROR if the model-ref or level id is invalid, else SUCCESS

See also:
    Level.SetDescription Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_GetCreateTimeStamp =R"doc(@Description Get level create time stamp

Parameter ``createTimeStampOut``:
    level create time stamp

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Returns:
    ERROR if the model-ref or level id is invalid, else SUCCESS

See also:
    Level.SetDescription Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_IsCodeAutoGenerated =R"doc(@Description Get if the level code is auto generated (that means
generated by MicroStation) or is manually set by the user

Parameter ``isAutoGeneratedOut``:
    true if the level code is auto generated

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Returns:
    ERROR if the model-ref or level id is invalid, else SUCCESS

See also:
    Level.SetCode Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_GetCode =R"doc(@Description Get level code.

Parameter ``levelCodeOut``:
    level code

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Returns:
    ERROR if the model-ref or level id is invalid, else SUCCESS

See also:
    Level.SetCode Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_GetName =R"doc(@Description Get level name.

Parameter ``levelNameOut``:
    level name

Parameter ``stringSizeIn``:
    number of (WChar) characters pLevelNameOut can hold

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Returns:
    ERROR if the model-ref or level id is invalid, else SUCCESS

See also:
    Level.SetName Level.GetPathName Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_IsValidByCode =R"doc(@Description Check if level with specified code is a valid existing
level.

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level code

Returns:
    true if the level is valid, else false. Returns false if
    modelRefIn is invalid.

See also:
    Level.IsValid Level.IsValidByName Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_IsValidByName =R"doc(@Description Check if level with specified name is a valid existing
level.

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelNameIn``:
    level name

Returns:
    true if the level is valid, else false. Returns false if
    modelRefIn is invalid.

See also:
    Level.IsValid Level.IsValidByCode Bentley Systems

Remark:
    )doc";

static const char * __doc_MstnPlatform_Level_IsValid =R"doc(@Description Check if the specified level id is a valid existing
level.

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelIdIn``:
    level id

Returns:
    true if the level is valid, else false. Returns false if
    modelRefIn is invalid.

See also:
    Level.IsValidByName Level.IsValidByCode

Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_SetActiveByCode =R"doc(@Description Set level with specified code as active. This function
handles setting a library level as active. If the level with specified
code is a library level, then, if necessary, the library level is
copied into the current-file before setting the level active.

Parameter ``levelCodeIn``:
    level code

Returns:
    ERROR if the level code is invalid or the level cannot be set as
    active, else SUCCESS

See also:
    Level.IsActive Level.GetActive Level.SetActive
    Params.SetActive Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_SetActiveByName =R"doc(@Description Set level with specified name as active. This function
handles setting a library level as active. If the level with specified
name is a library level, then, if necessary, the library level is
copied into the current-file before setting the level active.

Parameter ``levelNameIn``:
    level name

Returns:
    ERROR if the level name is invalid or the level cannot be set as
    active, else SUCCESS

See also:
    Level.IsActive Level.GetActive Level.SetActive
    Params.SetActive Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_SetActive =R"doc(@Description Set level as active.

Parameter ``levelIdIn``:
    level id

Returns:
    ERROR if the level id is invalid or the level cannot be set as
    active

Remark:
    s Returns **MSGID_errorElementAccessIsReadOnly** if element-access
    mode of the level is set to LevelElementAccess::ReadOnly or
    LevelElementAccess::ViewOnly

See also:
    Level.IsActive Level.GetActive Level.SetActiveByName
    Params.SetActive Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_GetActive =R"doc(@Description Get the current active level.

Parameter ``levelIdOut``:
    active level id

Returns:
    SUCCESS

See also:
    Level.IsActive Level.SetActive Level.SetActiveByName
    Params.SetActive Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_Level_IsActive =R"doc(@Description Check if a level of the current-file is the active level.

Parameter ``levelIdIn``:
    level id

Returns:
    true if iLevelIdIn is the active level, else false

See also:
    Level.GetActive Level.SetActive Level.SetActiveByName
    Params.SetActive Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_LevelTable_DrawLevels =R"doc(@Description Draw all elements on a list of specified levels

Parameter ``viewDraw``:
    views to update. Should point to an array dimensioned to
    DgnPlatform::MAX_VIEWS, and viewDraw[i] controls whether view i is
    drawn. If NULL, all views are drawn.

Parameter ``incrementalIn``:
    if false, don't erase before drawing

Parameter ``drawModeIn``:
    erasing portion of drawing

Parameter ``modelRefIn``:
    model ref

Parameter ``levelBitMaskIn``:
    bitmask representing the list of levels to draw

Parameter ``startEndMsgIn``:
    if true then want in prog/complete msg

Parameter ``drawSharedIn``:
    if true, then draw all models/attachments which use the same level

Returns:
    ERROR if the input level bit-mask is NULL or the model-ref is
    invalid, else SUCCESS

See also:
    Level.Draw Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_LevelTable_SetFrozenMask =R"doc(@Description Set the frozen flag for all levels of level-table.

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``frozenMaskIn``:
    level frozen mask to set

Parameter ``frozenTypeIn``:
    one of <TT>LEVEL_FROZEN_TYPE_</TT>... (defined in leveltable.h)

Parameter ``updateViewIn``:
    if true, then update the views

Returns:
    ERROR if the model-ref is invalid or the level-table is READ-ONLY,
    else SUCCESS @Group " Level Tables "

See also:
    usmthLevelTable.GetFrozenMaskC
    usmthLevelTable.GetDisplayFrozenMaskC usmthLevel.GetFrozenC
    usmthLevel.IsFrozenC usmthLevel.SetFrozenC Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_LevelTable_SetDisplayMask =R"doc(@Description Set the display flag for all levels of level-table.

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``displayMaskIn``:
    level display mask to set

Parameter ``updateViewIn``:
    if true, then update the views

Returns:
    ERROR if the model-ref is invalid or the level-table is READ-ONLY,
    else SUCCESS @Group " Level Tables "

See also:
    usmthLevel.GetDisplayMaskC usmthLevel.GetDisplayC
    usmthLevel.SetDisplayC Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_LevelTable_GetUsageMask =R"doc(@Description Get the level usage mask for level-table. Returns a bit-
mask that represents whether a level is used or not.

@Remarks The bit-mask is 1 based. For example to get the used flag for
a level with the function BitMask.TestBit, your call should look
like:BitMask.TestBit(pUsedBitMask, levelid -1) @Remarks Note the
" const "ness of the returned bit-mask. It is important not to cast into
a non-const bit-mask. This bit-mask should not be changed.

Parameter ``modelRefIn``:
    model-ref of level-table

Returns:
    The usage mask as a BitMask. Returns NULL if modelRefIn is
    invalid. @Group " Level Tables "

See also:
    usmthLevel.GetUsageC usmthLevel.IsUsedC Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_LevelTable_GetDisplayFrozenMask =R"doc(@Description Get the effective combined display + frozen mask for
level-table. Returns in a bit-mask form a represention of whether is
level is displayed or not frozen (each bit is represented as:display-
bit & inverse frozen-bit).

@Remarks The bit-mask is 1 based. For example to get the display-
frozen flag for a level with the function BitMask.TestBit, your
call should look like:BitMask.TestBit(pDisplayFrozenBitMask,
levelid -1) @Remarks Note the " const "ness of the returned bit-mask. It
is important not to cast into a non-const bit-mask. This bit-mask
should not be changed.

Parameter ``modelRefIn``:
    model-ref of level-table

Returns:
    The display + frozen mask as a BitMask. Returns NULL if modelRefIn
    is invalid. @Group " Level Tables "

See also:
    usmthLevelTable.GetFrozenMaskC
    usmthLevelTable.GetDisplayMaskC Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_LevelTable_GetFrozenMask =R"doc(@Description Get the frozen mask for level-table. Returns a bit-mask
that represents whether a level is frozen or not.

@Remarks The bit-mask is 1 based. For example to get the frozen flag
for a level with the function BitMask.TestBit, your call should
look like:BitMask.TestBit(pFrozenBitMask, levelid -1) @Remarks
Note the " const "ness of the returned bit-mask. It is important not to
cast into a non-const bit-mask. This bit-mask should not be changed.

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``frozenTypeIn``:
    one of <TT>LEVEL_FROZEN_TYPE_</TT>... (defined in leveltable.h)

Returns:
    The frozen mask as a BitMask. Returns NULL if modelRefIn is
    invalid. @Group " Level Tables "

See also:
    usmthLevelTable.SetFrozenMaskC
    usmthLevelTable.GetDisplayFrozenMaskC usmthLevel.GetFrozenC
    usmthLevel.IsFrozenC usmthLevel.SetFrozenC Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_LevelTable_GetReadOnlyMask =R"doc(@Description Get the read-only mask for level-table. Returns a bit-
mask that represents whether a level is read-only or not. If a level
is readonly, then its attributes cannot be changed.

@Remarks The bit-mask is 1 based. For example to get the read-only
flag for a level with the function BitMask.TestBit, your call
should look like:BitMask.TestBit(pReadOnlyBitMask, levelid -1)
@Remarks Note the " const "ness of the returned bit-mask. It is
important not to cast into a non-const bit-mask. This bit-mask should
not be changed.

Parameter ``modelRefIn``:
    model-ref of level-table

Returns:
    The read-only mask as a BitMask. Returns NULL if modelRefIn is
    invalid. @Group " Level Tables "

See also:
    usmthLevel.GetReadOnlyC usmthLevel.IsReadOnlyC
    usmthLevel.SetReadOnlyC Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_LevelTable_GetHiddenMask =R"doc(@Description Get the hidden mask for level-table. Returns a bit-mask
that represents whether a level is hidden or not. If a level is
hidden, then it is not displayed in the level manager.

@Remarks The bit-mask is 1 based. For example to get the hidden flag
for a level with the function BitMask.TestBit, your call should
look like:BitMask.TestBit(pHiddenBitMask, levelid -1) @Remarks
Note the " const "ness of the returned bit-mask. It is important not to
cast into a non-const bit-mask. This bit-mask should not be changed.

Parameter ``modelRefIn``:
    model-ref of level-table

Returns:
    The hidden mask as a BitMask. Returns NULL if modelRefIn is
    invalid. @Group " Level Tables "

See also:
    usmthLevel.GetHiddenC usmthLevel.IsHiddenC
    usmthLevel.SetHiddenC Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_LevelTable_GetExternalMask =R"doc(@Description Get the external mask for level-table. Returns a bit-mask
that represents whether a level is external or not. A level is
external, if it is associated with a library level.

@Remarks The bit-mask is 1 based. For example to get the external flag
for a level with the function BitMask.TestBit, your call should
look like:BitMask.TestBit(pExternalBitMask, levelid -1) @Remarks
Note the " const "ness of the returned bit-mask. It is important not to
cast into a non-const bit-mask. This bit-mask should not be changed.

Parameter ``modelRefIn``:
    model-ref of level-table

Returns:
    The external mask as a BitMask. Returns NULL if modelRefIn is
    invalid. @Group " Level Tables "

See also:
    usmthLevel.GetExternalC usmthLevel.IsExternalC
    usmthLevel.GetLibraryRefC Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_LevelTable_GetPlotMask =R"doc(@Description Get the plot mask for level-table. Returns a bit-mask
that represents which level's plot is turned on or off.

@Remarks The bit-mask is 1 based. For example to get the plot flag for
a level with the function BitMask.TestBit, your call should look
like:BitMask.TestBit(pPlotBitMask, levelid -1) @Remarks Note the
" const "ness of the returned bit-mask. It is important not to cast into
a non-const bit-mask. This bit-mask should not be changed.

Parameter ``modelRefIn``:
    model-ref of level-table

Returns:
    The plot mask as a BitMask. Returns NULL if modelRefIn is invalid
    @Group " Level Tables "

See also:
    usmthLevel.GetPlotC usmthLevel.SetPlotC Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_LevelTable_GetDisplayMask =R"doc(@Description Get the display mask for level-table. Returns a bit-mask
that represents which level's display is turned on or off.

@Remarks The bit-mask is 1 based. For example to get the display flag
for a level with the function BitMask.TestBit, your call should
look like:BitMask.TestBit(pDisplayBitMask, levelid -1) @Remarks
Note the " const "ness of the returned bit-mask. It is important not to
cast into a non-const bit-mask. This bit-mask should not be changed.

Parameter ``modelRefIn``:
    model-ref of level-table

Returns:
    The display mask as a BitMask. Returns NULL if modelRefIn is
    invalid. @Group " Level Tables "

See also:
    usmthLevel.SetDisplayMaskC
    usmthLevelTable.GetDisplayFrozenMaskC usmthLevel.GetDisplayC
    usmthLevel.SetDisplayC Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_LevelTable_Rewrite =R"doc(@Description Rewrite the level-table data into current-file. This
action has one of the following effects:<UL> <LI> If the level-table
does not exist in the file, then it is added into the file. <LI> If
the level-table already exists in the file, then the information in
this level-table is updated based on changes made to the level-data.
<LI> For an attachment's level-table, if there are no more any
override levels, then this function will remove the attachment's
override level-table from file. </UL>

<p> This function should be called whenever any of the level-table's
data is changed by calls to any of the Level.Set... or
LevelTable.Set... functions. The call to LevelTable.Rewrite will
make the changes permanent. Otherwise, the changes will be valid only
in the current session. The call to LevelTable.Rewrite is
accumalative, i.e. it writes all the changes made to level data. In
other words, multiple changes in the context of a single model-ref can
be made before calling LevelTable.Rewrite. The rewrite function
will rewrite all the changes made to levels of the specified model-
ref. </p>

@Remarks A successful write to file raises a LEVEL_TABLE_REWRITE
event.

Parameter ``modelRefIn``:
    model-ref of level-table

Returns:
    ERROR if the model-ref is invalid, else SUCCESS

Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_LevelTable_SetReadOnly =R"doc(@Description Set read-only flag of level-table. Setting a level-table
as read-only has the following implications:<UL> <LI>No new levels
can be created in the level-table. <LI>None of the exisiting levels
can be deleted from the level-table. <LI>None of the level attributes
can be modified. <LI>No new level library can be attached to the
level-table. <LI>None of the existing level libraries can be detached
from the level-table. </UL> By default, read-only is OFF.

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``isReadOnlyIn``:
    read-only flag - true or false

Returns:
    ERROR if the model-ref is invalid, else SUCCESS

See also:
    LevelTable.IsReadOnly LevelTable.GetReadOnly Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_LevelTable_IsReadOnly =R"doc(@Description Check if level-table is read-only.

Parameter ``modelRefIn``:
    model-ref of level-table

Returns:
    true if the level-table is read-only, else false

Remark:
    s If modelRefIn is invalid, then the function returns false.

See also:
    LevelTable.GetReadOnly LevelTable.SetReadOnly Bentley
    Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_LevelTable_GetReadOnly =R"doc(@Description Get read-only flag of level-table.

Parameter ``isReadOnlyOut``:
    read-only flag - true or false

Parameter ``modelRefIn``:
    model-ref of level-table

Returns:
    ERROR if the model-ref is invalid or isReadOnlyOut is NULL, else
    SUCCESS

See also:
    LevelTable.IsReadOnly LevelTable.SetReadOnly Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_LevelTable_GetHighestLevelCode =R"doc(@Description Get the value of highest used level code in level-table.

Parameter ``highestLevelCodeOut``:
    highest level code

Parameter ``modelRefIn``:
    model-ref of level-table

Returns:
    ERROR if the model-ref is invalid or pHighestLevelCode is NULL,
    else SUCCESS

Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_LevelTable_GetHighestLevelId =R"doc(@Description Get the value of highest used level id in level-table.

Parameter ``highestLevelIdOut``:
    highest level id

Parameter ``modelRefIn``:
    model-ref of level-table

Returns:
    ERROR if the model-ref is invalid or highestLevelIdOut is NULL,
    else SUCCESS

Bentley Systems

Remark:
     )doc";

static const char * __doc_MstnPlatform_LevelTable_GetLevelCount =R"doc(@Description Get the number of levels in level-table.

Parameter ``levelCountOut``:
    level count in level-table

Parameter ``modelRefIn``:
    model-ref of level-table

Parameter ``levelCountTypeIn``:
    one of <TT>LEVEL_COUNT_TYPE_</TT>... (defined in leveltable.h)

Remark:
    s The return value of levelCountOut will depend on value of
    levelCountTypeIn as follows:<TABLE border=" 1 " cellspacing=" 3 "
    cellpadding=" 3 "> <TR> <TH>levelCountTypeIn</TH>
    <TH>levelCountOut</TH> </TR> <TR>
    <TD><TT>LEVEL_COUNT_TYPE_ALL</TT></TD> <TD>The number of levels in
    level table</TD> </TR> <TR>
    <TD><TT>LEVEL_COUNT_TYPE_USED</TT></TD> <TD>The number of used
    levels in level table</TD> </TR> <TR>
    <TD><TT>LEVEL_COUNT_TYPE_UNUSED</TT></TD> <TD>The number of un-
    used levels in level table</TD> </TR> </TABLE>

Returns:
    ERROR if the model-ref is invalid or levelCountOut is NULL, else
    SUCCESS

Bentley Systems

Remark:
     )doc";



struct LevelTable {};
struct Level {};
struct LevelAttribute {};
struct LevelName {};

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_leveltable(py::module_& m)
    {

    py::enum_< LevelChangeType>(m, "LevelChangeType", py::arithmetic())
        .value("eLEVEL_TABLE_REWRITE", LEVEL_TABLE_REWRITE)
        .value("eLEVEL_CREATE", LEVEL_CREATE)
        .value("eLEVEL_DELETE", LEVEL_DELETE)
        .value("eLEVEL_CHANGE_NAME", LEVEL_CHANGE_NAME)
        .value("eLEVEL_CHANGE_CODE", LEVEL_CHANGE_CODE)
        .value("eLEVEL_CHANGE_PARENT", LEVEL_CHANGE_PARENT)
        .value("eLEVEL_CHANGE_DISPLAY", LEVEL_CHANGE_DISPLAY)
        .value("eLEVEL_CHANGE_ATTRIBUTE", LEVEL_CHANGE_ATTRIBUTE)
        .value("eLEVEL_CHANGE_ACTIVE", LEVEL_CHANGE_ACTIVE)
        .value("eLEVEL_LIBRARY_ATTACH", LEVEL_LIBRARY_ATTACH)
        .value("eLEVEL_LIBRARY_DETACH", LEVEL_LIBRARY_DETACH)
        .value("eLEVEL_CHANGE_USAGE", LEVEL_CHANGE_USAGE)
        .value("eLEVEL_CHANGE_ELEMENT_COUNT", LEVEL_CHANGE_ELEMENT_COUNT)
        .value("eLEVEL_TABLE_UNDO", LEVEL_TABLE_UNDO)
        .value("eLEVEL_TABLE_REDO", LEVEL_TABLE_REDO)
        .value("eLEVEL_TABLE_IMPORT", LEVEL_TABLE_IMPORT)
        .value("eLEVEL_PRE_CHANGE_ACTIVE", LEVEL_PRE_CHANGE_ACTIVE)
        .value("eLEVEL_PRE_DELETE", LEVEL_PRE_DELETE)
        .value("eLEVEL_REWRITE", LEVEL_REWRITE)
        .export_values();

    /**
     * Level Library Format Defines
     */
    py::enum_< LevelLibraryFormat>(m, "LevelLibraryFormat", py::arithmetic())
        .value("eLEVEL_LIBRARY_FORMAT_ANY", LEVEL_LIBRARY_FORMAT_ANY)
        .value("eLEVEL_LIBRARY_FORMAT_DGN", LEVEL_LIBRARY_FORMAT_DGN)
        .value("eLEVEL_LIBRARY_FORMAT_CSV", LEVEL_LIBRARY_FORMAT_CSV)
        .value("eLEVEL_LIBRARY_FORMAT_XML", LEVEL_LIBRARY_FORMAT_XML)
        .value("eLEVEL_LIBRARY_FORMAT_V7_LVL", LEVEL_LIBRARY_FORMAT_V7_LVL)
        .value("eLEVEL_LIBRARY_FORMAT_DWG", LEVEL_LIBRARY_FORMAT_DWG)
        .export_values();

    /**
     * Level Library Merge Methods
     */

    py::enum_< LevelLibraryImportMethod>(m, "LevelLibraryImportMethod", py::arithmetic())
        .value("eLEVEL_LIBRARY_IMPORT_BY_ANY", LEVEL_LIBRARY_IMPORT_BY_ANY)
        .value("eLEVEL_LIBRARY_IMPORT_BY_NAME", LEVEL_LIBRARY_IMPORT_BY_NAME)
        .value("eLEVEL_LIBRARY_IMPORT_BY_CODE", LEVEL_LIBRARY_IMPORT_BY_CODE)
        .export_values();

    /**
     * Level Count type
     */
    py::enum_< LevelCountType>(m, "LevelCountType", py::arithmetic())
        .value("eLEVEL_COUNT_TYPE_ALL", LEVEL_COUNT_TYPE_ALL)
        .value("eLEVEL_COUNT_TYPE_USED", LEVEL_COUNT_TYPE_USED)
        .value("eLEVEL_COUNT_TYPE_UNUSED", LEVEL_COUNT_TYPE_UNUSED)
        .value("eLEVEL_COUNT_TYPE_HIDDEN", LEVEL_COUNT_TYPE_HIDDEN)
        .export_values();

    /**
     * Level Iterator type
     */
    py::enum_< LevelIterateType>(m, "LevelIterateType", py::arithmetic())
        .value("eLEVEL_ITERATE_TYPE_ALL_LEVELS", LEVEL_ITERATE_TYPE_ALL_LEVELS)
        .value("eLEVEL_ITERATE_TYPE_USED_LEVELS", LEVEL_ITERATE_TYPE_USED_LEVELS)
        .value("eLEVEL_ITERATE_TYPE_UNUSED_LEVELS", LEVEL_ITERATE_TYPE_UNUSED_LEVELS)
        .export_values();


    /**
     * Level Library Count type
     */
    py::enum_< LevelLibraryCountType>(m, "LevelLibraryCountType", py::arithmetic())
        .value("eLEVEL_LIBRARY_COUNT_TYPE_ALL", LEVEL_LIBRARY_COUNT_TYPE_ALL)
        .value("eLEVEL_LIBRARY_COUNT_TYPE_MANUAL_ATTACHED", LEVEL_LIBRARY_COUNT_TYPE_MANUAL_ATTACHED)
        .value("eLEVEL_LIBRARY_COUNT_TYPE_AUTO_ATTACHED", LEVEL_LIBRARY_COUNT_TYPE_AUTO_ATTACHED)
        .export_values();

    /**
     * Level Frozen Type
     */
    py::enum_< LevelFrozenType>(m, "LevelFrozenType", py::arithmetic())
        .value("eLEVEL_FROZEN_TYPE_GLOBAL", LEVEL_FROZEN_TYPE_GLOBAL)
        .value("eLEVEL_FROZEN_TYPE_VP_FREEZE", LEVEL_FROZEN_TYPE_VP_FREEZE)
        .value("eLEVEL_FROZEN_TYPE_EFFECTIVE", LEVEL_FROZEN_TYPE_EFFECTIVE)
        .export_values();



    py::class_<LevelTable> c1(m, "LevelTable");

    c1.def_static("GetLevelCount", [] (DgnModelRefP modelRefIn, short levelCountTypeIn)
          {
          int levelCountOut = 0;
          auto retVal = mdlLevelTable_getLevelCount(&levelCountOut, modelRefIn, levelCountTypeIn);
          return py::make_tuple(retVal, levelCountOut);
          }, "modelRef"_a, "levelCountType"_a, DOC(MstnPlatform, LevelTable, GetLevelCount));

    c1.def_static("GetHighestLevelId", [] (DgnModelRefP modelRefIn)
          {
          LevelId highestLevelIdOut = 0;
          auto retVal = mdlLevelTable_getHighestLevelId(&highestLevelIdOut, modelRefIn);
          return py::make_tuple(retVal, highestLevelIdOut);
          }, "modelRef"_a, DOC(MstnPlatform, LevelTable, GetHighestLevelId));

    c1.def_static("GetHighestLevelCode", [] (DgnModelRefP modelRefIn)
          {
          LevelCode highestLevelCodeOut = 0;
          auto retVal = mdlLevelTable_getHighestLevelCode(&highestLevelCodeOut, modelRefIn);
          return py::make_tuple(retVal, highestLevelCodeOut);
          }, "modelRef"_a, DOC(MstnPlatform, LevelTable, GetHighestLevelCode));

    c1.def_static("GetReadOnly", [] (DgnModelRefP modelRefIn)
          {
          bool isReadOnlyOut = false;
          auto retVal = mdlLevelTable_getReadOnly(&isReadOnlyOut, modelRefIn);
          return py::make_tuple(retVal, isReadOnlyOut);
          }, "modelRef"_a, DOC(MstnPlatform, LevelTable, GetReadOnly));



    c1.def_static("IsReadOnly", &mdlLevelTable_isReadOnly, "modelRef"_a, DOC(MstnPlatform, LevelTable, IsReadOnly));
    c1.def_static("SetReadOnly", &mdlLevelTable_setReadOnly, "modelRef"_a, "isReadOnly"_a, DOC(MstnPlatform, LevelTable, SetReadOnly));
    c1.def_static("Rewrite", &mdlLevelTable_rewrite, "modelRef"_a, DOC(MstnPlatform, LevelTable, Rewrite));

    c1.def_static("GetDisplayMask", &mdlLevelTable_getDisplayMask, "modelRef"_a, py::return_value_policy::reference, DOC(MstnPlatform, LevelTable, GetDisplayMask));
    c1.def_static("GetPlotMask", &mdlLevelTable_getPlotMask, "modelRef"_a, py::return_value_policy::reference, DOC(MstnPlatform, LevelTable, GetPlotMask));
    c1.def_static("GetExternalMask", &mdlLevelTable_getExternalMask, "modelRef"_a, py::return_value_policy::reference, DOC(MstnPlatform, LevelTable, GetExternalMask));
    c1.def_static("GetHiddenMask", &mdlLevelTable_getHiddenMask, "modelRef"_a, py::return_value_policy::reference, DOC(MstnPlatform, LevelTable, GetHiddenMask));
    c1.def_static("GetReadOnlyMask", &mdlLevelTable_getReadOnlyMask, "modelRef"_a, py::return_value_policy::reference, DOC(MstnPlatform, LevelTable, GetReadOnlyMask));
    c1.def_static("GetFrozenMask", &mdlLevelTable_getFrozenMask, "modelRef"_a, "frozenType"_a, py::return_value_policy::reference, DOC(MstnPlatform, LevelTable, GetFrozenMask));
    c1.def_static("GetDisplayFrozenMask", &mdlLevelTable_getDisplayFrozenMask, "modelRef"_a, py::return_value_policy::reference, DOC(MstnPlatform, LevelTable, GetDisplayFrozenMask));
    c1.def_static("GetUsageMask", &mdlLevelTable_getUsageMask, "modelRef"_a, py::return_value_policy::reference, DOC(MstnPlatform, LevelTable, GetUsageMask));

    c1.def_static("SetDisplayMask", &mdlLevelTable_setDisplayMask, "modelRef"_a, "displayMask"_a, "updateView"_a, DOC(MstnPlatform, LevelTable, SetDisplayMask));
    c1.def_static("SetFrozenMask", &mdlLevelTable_setFrozenMask, "modelRef"_a, "frozenMask"_a, "frozenType"_a, "updateView"_a, DOC(MstnPlatform, LevelTable, SetFrozenMask));

    c1.def_static("DrawLevels", [] (std::array<bool, DgnPlatform::MAX_VIEWS>& viewDraw, bool incremental, DgnDrawMode drawMode,
                                          DgnModelRefP modelRef, BitMaskCP levelBitMask, bool startEndMsg, bool startShared)
          {
          return mdlLevelTable_drawLevels(viewDraw.data(), incremental, drawMode, modelRef, levelBitMask, startEndMsg, startShared);
          }, "viewDraw"_a, "incremental"_a, "drawMode"_a, "modelRef"_a, "levelBitMask"_a, "startEndMsg"_a, "startShared"_a, DOC(MstnPlatform, LevelTable, DrawLevels));

    py::class_<Level> c2(m, "Level");

    c2.def_static("IsActive", &mdlLevel_isActive, "levelId"_a, DOC(MstnPlatform, Level, IsActive));

    c2.def_static("GetActive", [] ()
          {
          LevelId levelId = -1;
          auto retVal = mdlLevel_getActive(&levelId);
          return py::make_tuple(retVal, levelId);
          }, DOC(MstnPlatform, Level, GetActive));

    c2.def_static("SetActive", &mdlLevel_setActive, "levelId"_a, DOC(MstnPlatform, Level, SetActive));
    c2.def_static("SetActiveByName", &mdlLevel_setActiveByName, "levelId"_a, "levelName"_a, DOC(MstnPlatform, Level, SetActiveByName));
    c2.def_static("SetActiveByCode", &mdlLevel_setActiveByCode, "levelCode"_a, DOC(MstnPlatform, Level, SetActiveByCode));
    c2.def_static("IsValid", &mdlLevel_isValid, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, IsValid));
    c2.def_static("IsValidByName", &mdlLevel_isValidByName, "modelRef"_a, "levelId"_a, "levelName"_a, DOC(MstnPlatform, Level, IsValidByName));
    c2.def_static("IsValidByCode", &mdlLevel_isValidByCode, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, IsValidByCode));

    c2.def_static("GetName", [] (DgnModelRefP modelRefIn, DgnPlatform::LevelId levelIdIn)
          {
          WChar szName[512] = {0};
          auto retVal = mdlLevel_getName(szName, _countof(szName), modelRefIn, levelIdIn);
          return py::make_tuple(retVal, szName);
          }, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, GetName));

    c2.def_static("GetCode", [] (DgnModelRefP modelRefIn, DgnPlatform::LevelId levelIdIn)
          {
          LevelCode code = 0;
          auto retVal = mdlLevel_getCode(&code, modelRefIn, levelIdIn);
          return py::make_tuple(retVal, code);
          }, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, GetCode));

    c2.def_static("IsCodeAutoGenerated", [] (DgnModelRefP modelRefIn, DgnPlatform::LevelId levelIdIn)
          {
          bool isAutoGeneratedOut = false;
          auto retVal = mdlLevel_isCodeAutoGenerated(&isAutoGeneratedOut, modelRefIn, levelIdIn);
          return py::make_tuple(retVal, isAutoGeneratedOut);
          }, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, IsCodeAutoGenerated));

    c2.def_static("GetCreateTimeStamp", [] (DgnModelRefP modelRefIn, DgnPlatform::LevelId levelIdIn)
          {
          UInt createTimeStampOut = 0;
          auto retVal = mdlLevel_getCreateTimeStamp(&createTimeStampOut, modelRefIn, levelIdIn);
          return py::make_tuple(retVal, createTimeStampOut);
          }, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, GetCreateTimeStamp));

    c2.def_static("GetDescription", [] (DgnModelRefP modelRefIn, DgnPlatform::LevelId levelIdIn)
          {
          WChar szDesc[512] = {0};
          auto retVal = mdlLevel_getDescription(szDesc, _countof(szDesc), modelRefIn, levelIdIn);
          return py::make_tuple(retVal, szDesc);
          }, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, GetDescription));

    c2.def_static("GetColor", [] (DgnModelRefP modelRefIn, DgnPlatform::LevelId levelIdIn)
          {
          UInt colorOut = 0;
          bool colorOverrideOut = false;
          auto retVal = mdlLevel_getColor(&colorOut, &colorOverrideOut, modelRefIn, levelIdIn);
          return py::make_tuple(retVal, colorOut, colorOverrideOut);
          }, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, GetColor));

    c2.def_static("GetMaterialId", [] (DgnModelRefP modelRefIn, DgnPlatform::LevelId levelIdIn)
          {
          ElementId materialIdOut = -1;
          bool materialOverrideOut = false;
          auto retVal = mdlLevel_getMaterialId(&materialIdOut, &materialOverrideOut, modelRefIn, levelIdIn);
          return py::make_tuple(retVal, materialIdOut, materialOverrideOut);
          }, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, GetMaterialId));

    c2.def_static("GetStyle", [] (DgnModelRefP modelRefIn, DgnPlatform::LevelId levelIdIn)
          {
          int styleOut = -1;
          LineStyleParams styleParamsOut;
          bool styleOverrideOut = false;
          auto retVal = mdlLevel_getStyle(&styleOut, &styleParamsOut, &styleOverrideOut, modelRefIn, levelIdIn);
          return py::make_tuple(retVal, styleOut, styleParamsOut, styleOverrideOut);
          }, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, GetStyle));

    c2.def_static("GetWeight", [] (DgnModelRefP modelRefIn, DgnPlatform::LevelId levelIdIn)
          {
          UInt weightOut = -1;
          bool weightOverrideOut = false;
          auto retVal = mdlLevel_getWeight(&weightOut, &weightOverrideOut, modelRefIn, levelIdIn);
          return py::make_tuple(retVal, weightOut, weightOverrideOut);
          }, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, GetWeight));

    c2.def_static("GetSymbology", [] (DgnModelRefP modelRefIn, DgnPlatform::LevelId levelIdIn)
          {
          UInt colorOut = 0, weightOut = 0;
          bool colorOverrideOut = false, styleOverrideOut = false, weightOverrideOut = false;
          int styleOut = 0;
          LineStyleParams styleParams;

          auto retVal = mdlLevel_getSymbology(&colorOut, &colorOverrideOut, &styleOut, &styleParams, &styleOverrideOut, &weightOut, &weightOverrideOut, modelRefIn, levelIdIn);
          return py::make_tuple(retVal, colorOut, colorOverrideOut, styleOut, styleParams, styleOverrideOut, weightOut, weightOverrideOut);
          }, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, GetSymbology));

    c2.def_static("GetElementColor", [] (DgnModelRefP modelRefIn, DgnPlatform::LevelId levelIdIn)
          {
          UInt colorOut = -1;
          auto retVal = mdlLevel_getElementColor(&colorOut, modelRefIn, levelIdIn);
          return py::make_tuple(retVal, colorOut);
          }, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, GetElementColor));

    c2.def_static("GetElementMaterialId", [] (DgnModelRefP modelRefIn, DgnPlatform::LevelId levelIdIn)
          {
          ElementId materialOut = -1;
          auto retVal = mdlLevel_getElementMaterialId(&materialOut, modelRefIn, levelIdIn);
          return py::make_tuple(retVal, materialOut);
          }, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, GetElementMaterialId));

    c2.def_static("GetElementStyle", [] (DgnModelRefP modelRefIn, DgnPlatform::LevelId levelIdIn)
          {
          int styleOut = -1;
          LineStyleParams styleParamsOut;
          auto retVal = mdlLevel_getElementStyle(&styleOut, &styleParamsOut, modelRefIn, levelIdIn);
          return py::make_tuple(retVal, styleOut, styleParamsOut);
          }, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, GetElementStyle));

    c2.def_static("GetElementWeight", [] (DgnModelRefP modelRefIn, DgnPlatform::LevelId levelIdIn)
          {
          UInt weightOut = -1;
          auto retVal = mdlLevel_getElementWeight(&weightOut, modelRefIn, levelIdIn);
          return py::make_tuple(retVal, weightOut);
          }, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, GetElementWeight));

    c2.def_static("GetElementSymbology", [] (DgnModelRefP modelRefIn, DgnPlatform::LevelId levelIdIn)
          {
          UInt elementColorOut = -1;
          int elementStyleOut = 0;
          LineStyleParams elementStyleParamsOut;
          UInt elementWeightOut = -1;

          auto retVal = mdlLevel_getElementSymbology(&elementColorOut, &elementStyleOut, &elementStyleParamsOut, &elementWeightOut, modelRefIn, levelIdIn);
          return py::make_tuple(retVal, elementColorOut, elementStyleOut, elementStyleParamsOut, elementWeightOut);
          }, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, GetElementSymbology));

    c2.def_static("GetElementAccess", [] (DgnModelRefP modelRefIn, DgnPlatform::LevelId levelIdIn)
          {
          LevelElementAccess access = LevelElementAccess::All;

          auto retVal = mdlLevel_getElementAccess(&access, modelRefIn, levelIdIn);
          return py::make_tuple(retVal, access);
          }, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, GetElementAccess));

    c2.def_static("IsElementLocked", &mdlLevel_isElementLocked, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, IsElementLocked));
    c2.def_static("IsElementReadOnly", &mdlLevel_isElementReadOnly, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, IsElementReadOnly));
    c2.def_static("IsElementViewOnly", &mdlLevel_isElementViewOnly, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, IsElementViewOnly));
    c2.def_static("IsElementViewOnly", &mdlLevel_isElementViewOnly, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, IsElementViewOnly));

    c2.def_static("GetDisplay", [] (DgnModelRefP modelRefIn, DgnPlatform::LevelId levelIdIn)
          {
          bool levelDisplayOut = false;

          auto retVal = mdlLevel_getDisplay(&levelDisplayOut, modelRefIn, levelIdIn);
          return py::make_tuple(retVal, levelDisplayOut);
          }, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, GetDisplay));

    c2.def_static("GetPlot", [] (DgnModelRefP modelRefIn, DgnPlatform::LevelId levelIdIn)
          {
          bool levelPlotOut = false;

          auto retVal = mdlLevel_getPlot(&levelPlotOut, modelRefIn, levelIdIn);
          return py::make_tuple(retVal, levelPlotOut);
          }, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, GetPlot));

    c2.def_static("GetAttributesDifferFromSource", [] (BitMaskP differencesMaskOut, DgnModelRefP modelRefIn, DgnPlatform::LevelId levelIdIn)
          {
          bool levelDifferOut = false;
          
          auto retVal = mdlLevel_getAttributesDifferFromSource(&levelDifferOut, differencesMaskOut, modelRefIn, levelIdIn);
          return py::make_tuple(retVal, levelDifferOut);
          }, "differencesMask"_a, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, GetAttributesDifferFromSource));

    c2.def_static("IsExternal", &mdlLevel_isExternal, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, IsExternal));
    c2.def_static("IsHidden", &mdlLevel_isHidden, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, IsHidden));
    c2.def_static("IsReadOnly", &mdlLevel_isReadOnly, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, IsReadOnly));
    c2.def_static("IsFrozen", &mdlLevel_isFrozen, "modelRef"_a, "levelId"_a, "frozenType"_a, DOC(MstnPlatform, Level, IsFrozen));

    c2.def_static("GetUniqueID", [] (DgnModelRefP modelRefIn, DgnPlatform::LevelId levelIdIn)
          {
          DgnPlatform::ElementId uniqueIDOut = -1;
          auto retVal = mdlLevel_getUniqueID(&uniqueIDOut, modelRefIn, levelIdIn);
          return py::make_tuple(retVal, uniqueIDOut);
          }, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, GetUniqueID));

    c2.def_static("GetIdFromName", [] (DgnModelRefP modelRefIn, DgnPlatform::LevelId levelIdIn, WCharCP levelName)
          {
          LevelId levelIdOut = -1;
          auto retVal = mdlLevel_getIdFromName(&levelIdOut, modelRefIn, levelIdIn, levelName);
          return py::make_tuple(retVal, levelIdOut);
          }, "modelRef"_a, "levelId"_a, "levelName"_a, DOC(MstnPlatform, Level, GetIdFromName));

    c2.def_static("GetIdFromNameIncludingLibraries", [] (DgnModelRefP modelRefIn, WCharCP levelName)
          {
          LevelId levelIdOut = -1;
          auto retVal = mdlLevel_getIdFromNameIncludingLibraries(&levelIdOut, modelRefIn, levelName);
          return py::make_tuple(retVal, levelIdOut);
          }, "modelRef"_a, "levelName"_a, DOC(MstnPlatform, Level, GetIdFromNameIncludingLibraries));

    c2.def_static("GetIdFromCode", [] (DgnModelRefP modelRefIn, LevelCode levelCode)
          {
          LevelId levelIdOut = -1;
          auto retVal = mdlLevel_getIdFromCode(&levelIdOut, modelRefIn, levelCode);
          return py::make_tuple(retVal, levelIdOut);
          }, "modelRef"_a, "levelCode"_a, DOC(MstnPlatform, Level, GetIdFromCode));

    c2.def_static("GetIdFromCodeIncludingLibraries", [] (DgnModelRefP modelRefIn, LevelCode levelCode)
          {
          LevelId levelIdOut = -1;
          auto retVal = mdlLevel_getIdFromCodeIncludingLibraries(&levelIdOut, modelRefIn, levelCode);
          return py::make_tuple(retVal, levelIdOut);
          }, "modelRef"_a, "levelCode"_a, DOC(MstnPlatform, Level, GetIdFromCodeIncludingLibraries));

    c2.def_static("IsUsed", &mdlLevel_isUsed, "modelRef"_a, "levelId"_a, "inFile"_a, DOC(MstnPlatform, Level, IsUsed));

    c2.def_static("GetUsage", [] (DgnModelRefP modelRefIn, LevelId levelId, bool inFile)
          {
          bool usageOut = false;
          auto retVal = mdlLevel_getUsage(&usageOut, modelRefIn, levelId, inFile);
          return py::make_tuple(retVal, usageOut);
          }, "modelRef"_a, "levelId"_a, "inFile"_a, DOC(MstnPlatform, Level, GetUsage));

    c2.def_static("ReportUsage", &mdlLevel_reportUsage, "reportString"_a, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, ReportUsage));

    c2.def_static("GetElementCount", [] (DgnModelRefP modelRefIn, LevelId levelId)
          {
          int usageCountOut = 0;
          auto retVal = mdlLevel_getElementCount(&usageCountOut, modelRefIn, levelId);
          return py::make_tuple(retVal, usageCountOut);
          }, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, GetElementCount));

    c2.def_static("GetDisplayPriority", [] (DgnModelRefP modelRefIn, LevelId levelId)
          {
          Int32 priorityOut = 0;
          auto retVal = mdlLevel_getDisplayPriority(&priorityOut, modelRefIn, levelId);
          return py::make_tuple(retVal, priorityOut);
          }, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, GetDisplayPriority));

    c2.def_static("GetTransparency", [] (DgnModelRefP modelRefIn, LevelId levelId)
          {
          double transparencyOut = 0;
          auto retVal = mdlLevel_getTransparency(&transparencyOut, modelRefIn, levelId);
          return py::make_tuple(retVal, transparencyOut);
          }, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, GetTransparency));

    c2.def_static("Create", [] (DgnModelRefP modelRefIn, WCharCP levelNameIn, LevelCode levelCodeIn)
          {
          LevelId levelIdOut = -1;
          auto retVal = mdlLevel_create(&levelIdOut, modelRefIn, levelNameIn, levelCodeIn);
          return py::make_tuple(retVal, levelIdOut);
          }, "modelRef"_a, "levelName"_a, "levelCode"_a, DOC(MstnPlatform, Level, Create));

    c2.def_static("CreateFromSeed", [] (DgnModelRefP modelRefIn, WCharCP levelNameIn, LevelCode levelCodeIn, LevelId seedLevelId, BitMaskCP copyAttributeMaskIn)
          {
          LevelId levelIdOut = -1;
          auto retVal = mdlLevel_createFromSeed(&levelIdOut, modelRefIn, levelNameIn, levelCodeIn, seedLevelId, copyAttributeMaskIn);
          return py::make_tuple(retVal, levelIdOut);
          }, "modelRef"_a, "levelName"_a, "levelCode"_a, "seedLevelId"_a, "copyAttributeMask"_a, DOC(MstnPlatform, Level, CreateFromSeed));

    c2.def_static("Delete", &mdlLevel_delete, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, Delete));
    c2.def_static("SetName", &mdlLevel_setName, "modelRef"_a, "levelId"_a, "name"_a, DOC(MstnPlatform, Level, SetName));
    c2.def_static("SetCode", &mdlLevel_setCode, "modelRef"_a, "levelId"_a, "levelCode"_a, DOC(MstnPlatform, Level, SetCode));
    c2.def_static("SetDescription", &mdlLevel_setDescription, "modelRef"_a, "levelId"_a, "description"_a, DOC(MstnPlatform, Level, SetDescription));
    c2.def_static("SetColor", &mdlLevel_setColor, "modelRef"_a, "levelId"_a, "color"_a, "colorOverride"_a, DOC(MstnPlatform, Level, SetColor));
    c2.def_static("SetMaterialId", &mdlLevel_setMaterialId, "modelRef"_a, "levelId"_a, "matrialId"_a, "materialOverride"_a, DOC(MstnPlatform, Level, SetMaterialId));
    c2.def_static("SetStyle", &mdlLevel_setStyle, "modelRef"_a, "levelId"_a, "style"_a, "styleParams"_a, "styleOverride"_a, DOC(MstnPlatform, Level, SetStyle));
    c2.def_static("SetWeight", &mdlLevel_setWeight, "modelRef"_a, "levelId"_a, "weight"_a, "weightOverride"_a, DOC(MstnPlatform, Level, SetWeight));

    c2.def_static("SetElementColor", &mdlLevel_setElementColor, "modelRef"_a, "levelId"_a, "color"_a, DOC(MstnPlatform, Level, SetElementColor));
    c2.def_static("SetElementMaterialId", &mdlLevel_setElementMaterialId, "modelRef"_a, "levelId"_a, "materialId"_a, DOC(MstnPlatform, Level, SetElementMaterialId));
    c2.def_static("SetElementStyle", &mdlLevel_setElementStyle, "modelRef"_a, "levelId"_a, "style"_a, "styleParams"_a, DOC(MstnPlatform, Level, SetElementStyle));
    c2.def_static("SetElementWeight", &mdlLevel_setElementWeight, "modelRef"_a, "levelId"_a, "weight"_a, DOC(MstnPlatform, Level, SetElementWeight));
    c2.def_static("SetElementSymbology", &mdlLevel_setElementSymbology, "modelRef"_a, "levelId"_a, "color"_a, "style"_a, "styleParams"_a, "weight"_a, DOC(MstnPlatform, Level, SetElementSymbology));
    c2.def_static("SetElementAccess", &mdlLevel_setElementAccess, "modelRef"_a, "levelId"_a, "elementAccess"_a, DOC(MstnPlatform, Level, SetElementAccess));
    c2.def_static("SetDisplay", &mdlLevel_setDisplay, "modelRef"_a, "levelId"_a, "display"_a, DOC(MstnPlatform, Level, SetDisplay));
    c2.def_static("SetFrozen", &mdlLevel_setFrozen, "modelRef"_a, "levelId"_a, "frozenType"_a, "frozen"_a, DOC(MstnPlatform, Level, SetFrozen));
    c2.def_static("SetPlot", &mdlLevel_setPlot, "modelRef"_a, "levelId"_a, "plot"_a, DOC(MstnPlatform, Level, SetPlot));
    c2.def_static("SetHidden", &mdlLevel_setHidden, "modelRef"_a, "levelId"_a, "hidden"_a, DOC(MstnPlatform, Level, SetHidden));
    c2.def_static("SetDisplayPriority", &mdlLevel_setDisplayPriority, "modelRef"_a, "levelId"_a, "priority"_a, DOC(MstnPlatform, Level, SetDisplayPriority));
    c2.def_static("SetTransparency", &mdlLevel_setTransparency, "modelRef"_a, "levelId"_a, "transparency"_a, DOC(MstnPlatform, Level, SetTransparency));
    c2.def_static("SetReadOnly", &mdlLevel_setReadOnly, "modelRef"_a, "levelId"_a, "isReadOnly"_a, DOC(MstnPlatform, Level, SetReadOnly));
    c2.def_static("CompareLevelData", &mdlLevel_compareLevelData, "compareAttributesOut"_a, "modelRef1"_a, "levelId1"_a, "modelRef2"_a, "levelId2"_a, "compareAttributesIn"_a, DOC(MstnPlatform, Level, CompareLevelData));
    c2.def_static("CopyLevelData", &mdlLevel_copyLevelData, "destModelRef"_a, "destLevelId"_a, "sourceModelRef"_a, "sourceLevelId"_a, DOC(MstnPlatform, Level, CopyLevelData));
    c2.def_static("CopyLevelDataByAttributeMask", &mdlLevel_copyLevelDataByAttributeMask, "destModelRef"_a, "destLevelId"_a, "sourceModelRef"_a, "sourceLevelId"_a, "copyAttributesMask"_a, DOC(MstnPlatform, Level, CopyLevelDataByAttributeMask));    

    c2.def_static("GetFrozen", [] (DgnModelRefP modelRefIn, DgnPlatform::LevelId levelIdIn, LevelFrozenType frozenTypeIn)
          {
          bool frozenOut = false;
          auto retVal = mdlLevel_getFrozen(&frozenOut, modelRefIn, levelIdIn, frozenTypeIn);
          return py::make_tuple(retVal, frozenOut);
          }, "modelRef"_a, "levelIdIn"_a, "frozenTypeIn"_a, DOC(MstnPlatform, Level, GetFrozen));

    c2.def_static("GetHidden", [] (DgnModelRefP modelRefIn, DgnPlatform::LevelId levelIdIn)
          {
          bool hiddenOut = false;
          auto retVal = mdlLevel_getHidden(&hiddenOut, modelRefIn, levelIdIn);
          return py::make_tuple(retVal, hiddenOut);
          }, "modelRef"_a, "levelIdIn"_a, DOC(MstnPlatform, Level, GetHidden));

    c2.def_static("CopyLevel", [] (DgnModelRefP destModelRefIn, DgnModelRefP sourceModelRefIn, LevelId sourceLevelIdIn, WCharCP newLevelNameIn, bool setExternalIn)
          {
          LevelId levelOut = -1;
          auto retVal = mdlLevel_copyLevelEx(&levelOut, destModelRefIn, sourceModelRefIn, sourceLevelIdIn, newLevelNameIn, setExternalIn);
          return py::make_tuple(retVal, levelOut);
          }, "destModelRef"_a, "sourceModelRef"_a, "sourceLevelId"_a, "newLevelNameIn"_a, "setExternal"_a, DOC(MstnPlatform, Level, CopyLevel));

    c2.def_static("Draw", [] (std::array<bool, DgnPlatform::MAX_VIEWS>& viewDraw, bool incrementalIn, DgnPlatform::DgnDrawMode drawModeIn, DgnModelRefP modelRefIn,
                               DgnPlatform::LevelId levelIdIn, bool startEndMsgIn, bool drawSharedIn)
          {
          return mdlLevel_draw(viewDraw.data(), incrementalIn, drawModeIn, modelRefIn, levelIdIn, startEndMsgIn, drawSharedIn);
          }, "viewDraw"_a, "incremental"_a, "drawMode"_a, "modelRef"_a, "levelId"_a, "startEndMsg"_a, "drawShared"_a, DOC(MstnPlatform, Level, Draw));

    c2.def_static("SelectElement", [] (DgnModelRefP modelRefIn, LevelId levelIdIn)
          {
          int numElementSelectedOut = 0;
          auto retVal = mdlLevel_selectElement(&numElementSelectedOut, modelRefIn, levelIdIn);
          return py::make_tuple(retVal, numElementSelectedOut);
          }, "modelRef"_a, "levelId"_a, DOC(MstnPlatform, Level, SelectElement));

    c2.def_static("DeleteElement", [] (DgnModelRefP modelRefIn, LevelId levelIdIn, bool inEntireFileIn, bool updateViewIn)
          {
          int numElementDeletedOut = 0;
          auto retVal = mdlLevel_deleteElement(&numElementDeletedOut, modelRefIn, levelIdIn, inEntireFileIn, updateViewIn);
          return py::make_tuple(retVal, numElementDeletedOut);
          }, "modelRef"_a, "levelId"_a, "inEntireFile"_a, "updateView"_a, DOC(MstnPlatform, Level, DeleteElement));

    c2.def_static("CopyElement", [] (DgnModelRefP destModelRefIn, LevelId destLevelIdIn, DgnModelRefP sourceModelRefIn, LevelId sourceLevelIdIn, bool inEntireFileIn)
          {
          int numElementCopiedOut = 0;
          auto retVal = mdlLevel_copyElement(&numElementCopiedOut, destModelRefIn, destLevelIdIn, sourceModelRefIn, sourceLevelIdIn, inEntireFileIn);
          return py::make_tuple(retVal, numElementCopiedOut);
          }, "destModelRef"_a, "destLevelId"_a, "sourceModelRef"_a, "sourceLevelId"_a, "inEntireFile"_a, DOC(MstnPlatform, Level, CopyElement));

    c2.def_static("MoveElementLevel", [] (LevelId destLevelIdIn, DgnModelRefP modelRefIn, LevelId sourceLevelIdIn, bool inEntireFileIn)
          {
          int numElementMovedOut = 0;
          auto retVal = mdlLevel_moveElementLevel(&numElementMovedOut, destLevelIdIn, modelRefIn, sourceLevelIdIn, inEntireFileIn);
          return py::make_tuple(retVal, numElementMovedOut);
          }, "destLevelId"_a, "modelRef"_a, "sourceLevelId"_a, "inEntireFile"_a, DOC(MstnPlatform, Level, MoveElementLevel));

    c2.def_static("SetElementByLevel", [] (DgnModelRefP modelRefIn, LevelId levelIdIn, BitMaskP elementAttributeStringIn, bool inEntireFileIn, bool isSetByLevel)
          {
          int numElementChangedOut = 0;
          auto retVal = mdlLevel_setElementByLevel(&numElementChangedOut, modelRefIn, levelIdIn, elementAttributeStringIn, inEntireFileIn, isSetByLevel);
          return py::make_tuple(retVal, numElementChangedOut);
          }, "modelRef"_a, "levelId"_a, "elementAttributeString"_a, "inEntireFile"_a, "isSetByLevel"_a, DOC(MstnPlatform, Level, SetElementByLevel));

    c2.def_static("GetSeedLevel", &mdlLevel_getSeedLevel, "modelRef"_a, DOC(MstnPlatform, Level, GetSeedLevel));

    py::class_<LevelAttribute> c3(m, "LevelAttribute");

    c3.def_static("GetMask", &mdlLevelAttribute_getMask, "attribyteType"_a, py::return_value_policy::reference, DOC(MstnPlatform, LevelAttribute, GetMask));

    py::class_<LevelName> c4(m, "LevelName");

    c4.def_static("HasValidCharacters", &mdlLevelName_hasValidCharacters, "nameString"_a, DOC(MstnPlatform, LevelName, HasValidCharacters));
    }