/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\levelcache.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/LevelCache.h>



static const char * __doc_Bentley_DgnPlatform_LevelUtils_ReplaceInvalidCharacters =R"doc(Modify the specified string so that it is a valid level name
@DotNetMethodExclude)doc";

static const char * __doc_Bentley_DgnPlatform_LevelUtils_ContainsInvalidCharacters =R"doc(Query if the specified string is not a valid level name)doc";

static const char * __doc_Bentley_DgnPlatform_FileLevelCache_GetLibraries =R"doc(Get a vector of Level Libraries associated with this LevelCache.)doc";

static const char * __doc_Bentley_DgnPlatform_FileLevelCache_IsLevelUsedInFile =R"doc(Test if any element in file of " this " FileLevelCache is on the
specified level See LevelCache_Usage)doc";

static const char * __doc_Bentley_DgnPlatform_FileLevelCache_IsLevelUsedInModel =R"doc(Test if any element in specified model-ref is on the specified level.
See LevelCache_Usage)doc";

static const char * __doc_Bentley_DgnPlatform_FileLevelCache_GetHighestUsedLevelCode =R"doc(Get the highest used LevelCode in this level cache)doc";

static const char * __doc_Bentley_DgnPlatform_FileLevelCache_GetHighestUsedLevelId =R"doc(Get the highest used LevelId in this level cache.

Parameter ``includeLibraries``:
    If true, get the highest use LevelId in the level cache and all of
    its associated level libraries.)doc";

static const char * __doc_Bentley_DgnPlatform_FileLevelCache_SetLevelReadOnly =R"doc(Mark a level read-only or read-write)doc";

static const char * __doc_Bentley_DgnPlatform_FileLevelCache_RemoveLevel =R"doc(Remove a level from the cache Example:
LevelCacheCodeSamples_RemoveLevel

Parameter ``next``:
    The next level in the level cache. Useful when deleting levels
    while iterating a level cache. Pass NULL if you do not want to
    know the next level.

Parameter ``level``:
    The level to remove. *Becomes invalid.*

Returns:
    Non-zero error status if the level cannot be removed:

Remark:
    s If this function succeeds, the input level becomes invalid. \li
    LevelCacheErrorCode::CannotFindLevel - The specified level is
    invalid or is not from this level cache. \li
    LevelCacheErrorCode::TableIsReadOnly - The level table is read-
    only \li LevelCacheErrorCode::LevelIsReadOnly - The level itself
    is read-only \li LevelCacheErrorCode::LevelIsUsed - The level is
    in use)doc";

static const char * __doc_Bentley_DgnPlatform_FileLevelCache_CopyLevel =R"doc(Copy the specified level from another file into the level cache of
this file.

Remark:
    s This function is useful for copying a level from one file into
    another. It cannot be used to copy a level within a file. To copy
    a level with control over name, code, and what data is copied, use
    CreateLevel and EditLevelHandle::CopyLevelData

Remark:
    s If successful, this function creates a new level in the level
    cache of this file and then copies the data from the source level.
    The new level is *always* assigned a new internal LevelId. The
    source level's LevelId is never copied.

Returns:
    A handle to the newly created level or an invalid handle if
    creation or copying failed. To detect failure, call the handle's
    LevelDefinition::IsValid method. If that returns false, call
    LevelDefinition::GetStatus method and check for:\li
    LevelCacheErrorCode::LevelNameIsDuplicate - the name of the source
    level is already used by an existing level in this cache \li
    LevelCacheErrorCode::LevelCodeIsDuplicate - the LevelCode of the
    source level is already used by a level in this cache \li
    LevelCacheErrorCode::CannotFindLevel - the source level is invalid

Parameter ``source``:
    The source level to copy.

Parameter ``replaceDuplicateLevelCode``:
    [optional] if true, and the level code is a duplicate, assign a
    new level code. @param)doc";

static const char * __doc_Bentley_DgnPlatform_FileLevelCache_CreateDefaultLevel =R"doc(Create the default level using the default level name and
LEVEL_DEFAULT_LEVEL_CODE and LEVEL_DEFAULT_LEVEL_ID)doc";

static const char * __doc_Bentley_DgnPlatform_FileLevelCache_CreateLevel =R"doc(Create a level in this level cache.

Parameter ``levelName``:
    Name to be assigned to the new level. Pass NULL if level is to
    have no name.

Parameter ``levelCode``:
    Code to be assigned to the new level. Pass LEVEL_NULL_CODE to have
    this LevelCache generate and assign a LevelCode to the new level.

Parameter ``idIn``:
    Internal LevelId to be assigned to the new level. Pass
    LEVEL_NULL_ID to have this LevelCache generate and assign a
    LevelId to the new level.

Returns:
    A handle to the newly created level or an invalid handle if
    creation failed. To detect failure, call the handle's
    LevelDefinition::IsValid method. If that returns false, call
    LevelDefinition::GetStatus method and check for:\li
    LevelCacheErrorCode::LevelIdIsDuplicate - *i* is a LevelId already
    used by a level in this cache \li
    LevelCacheErrorCode::LevelNameIsDuplicate - *n* is a name that is
    already used by a level in this cache \li
    LevelCacheErrorCode::LevelNameIsInvalid - *n* contains invalid
    characters. See LevelUtils::ContainsInvalidCharacters \li
    LevelCacheErrorCode::LevelCodeIsDuplicate - *c* is a LevelCode
    already used by a level in this cache)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentLevelCache_EditProperties =R"doc(Edit level properties in the level cache

Remark:
    s If the levelCache is changed by the operation, the changes are
    written according to the writeChanges argument.

Parameter ``context``:
    The property-editing context to apply to all levels in the
    LevelCache

Parameter ``writeChanges``:
    Controls whether changes are written to the file.)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentLevelCache_IsDirty =R"doc(Returns true if this level cache or any level definition in it has
been modified since it was created or since the last call to Write.)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentLevelCache_Write =R"doc(Write this level cache, including all of the level definitions that it
contains, to the file that contains it.

Returns:
    non-zero error status if the file update failed.)doc";

static const char * __doc_Bentley_DgnPlatform_LevelCache_SetPersistHiddenState =R"doc(Set if the " hidden " state of individual levels is persisted when
converting to element.

Parameter ``persistStateIn``:
    If true, then the " hidden " state of individual levels is persisted)doc";

static const char * __doc_Bentley_DgnPlatform_LevelCache_IsHiddenStatePersisted =R"doc(Check if the " hidden " state of individual levels is persisted when
converting to element.

Returns:
    true if the hidden state of individual levels is persisted)doc";

static const char * __doc_Bentley_DgnPlatform_LevelCache_EqualLevelData =R"doc(Compare this level cache to *rhs.*

Parameter ``rhs``:
    the other level cache

Parameter ``compareElementIds``:
    If true, the ElementIds of the levels are also compared. Defaults
    to false.

Parameter ``compareAttributesMask``:
    Optional bit mask to specify what level properties to compare.
    Defaults to all properties.

Returns:
    true if the levels in this level match the levels in *rhs.*

Remark:
    s This function considers only level data, not any data or flags
    that may be associated with the level cache itself.)doc";

static const char * __doc_Bentley_DgnPlatform_LevelCache_IsReadOnly =R"doc(Query if the level cache is read-only)doc";

static const char * __doc_Bentley_DgnPlatform_LevelCache_GetLastModifiedTimeForLevelDefinitions =R"doc(Gets the time that file that defines the levels in this cache was last
modified.

Parameter ``timeStampOut``:
    The file's last-modified timestamp in milliseconds since 1970

Returns:
    non-zero error status if this level cache is new and has never
    been written to file.)doc";

static const char * __doc_Bentley_DgnPlatform_LevelCache_GetLowestAvailableLevelCode =R"doc(Get the lowest available LevelCode in this level cache)doc";

static const char * __doc_Bentley_DgnPlatform_LevelCache_GetLowestAvailableLevelId =R"doc(Get the lowest available LevelId in this level cache)doc";

static const char * __doc_Bentley_DgnPlatform_LevelCache_ComputeHighestUsedLevelCode =R"doc(Computes and returns the highest LevelCode used in this cache.)doc";

static const char * __doc_Bentley_DgnPlatform_LevelCache_ComputeHighestUsedLevelId =R"doc(Computes and returns the highest LevelId used in this cache.)doc";

static const char * __doc_Bentley_DgnPlatform_LevelCache_GetLevelCount =R"doc(Returns the count of level definitions in this cache.

Parameter ``includeLibraries``:
    If true, get the total count of levels in the level cache and all
    of its associated level libraries.)doc";

static const char * __doc_Bentley_DgnPlatform_LevelCache_GetLevelByDisplayName =R"doc(Look up a level definition by its (formatted) display name

Parameter ``levelDisplayName``:
    The name to look up

Parameter ``includeLibraries``:
    if true, search associated level libraries for levelName in
    addition to this LevelCache.

Returns:
    A handle to the level or an invalid handle if no level by this
    name was not found. Check the value of LevelHandle::IsValid to
    detect failure.)doc";

static const char * __doc_Bentley_DgnPlatform_LevelCache_GetLevelByName =R"doc(Look up a level definition by its user-defined name

Parameter ``levelName``:
    The name to look up

Parameter ``includeLibraries``:
    if true, search associated level libraries for levelName in
    addition to this LevelCache.

Returns:
    A handle to the level or an invalid handle if no level by this
    name was not found. Check the value of LevelHandle::IsValid to
    detect failure.)doc";

static const char * __doc_Bentley_DgnPlatform_LevelCache_GetLevelByCode =R"doc(Look up a level definition by its user-defined LevelCode

Parameter ``levelCode``:
    The level code to look up

Parameter ``includeLibraries``:
    if true, search associated level libraries for levelCode in
    addition to this LevelCache.

Returns:
    A handle to the level or an invalid handle if no level with this
    code was not found. Check the value of LevelHandle::IsValid to
    detect failure.)doc";

static const char * __doc_Bentley_DgnPlatform_LevelCache_GetLevel =R"doc(Look up a level definition by its internal LevelId Example:
LevelCacheCodeSamples_GetElementLevelDefinition Example:
LevelCacheCodeSamples_GetByLevelColor

Parameter ``levelId``:
    the level Id to look up

Parameter ``includeLibraries``:
    if true, search associated level libraries for levelId in addition
    to this LevelCache.

Returns:
    A handle to the level or an invalid handle if *levelId* was not
    found. Check the value of LevelHandle::IsValid to detect failure.)doc";

static const char * __doc_Bentley_DgnPlatform_EditLevelHandle_EditElementRelatedProperties =R"doc(Edit the element-related properties defined by this level)doc";

static const char * __doc_Bentley_DgnPlatform_EditLevelHandle_SetPlotStyle =R"doc(Set the PlotStyle)doc";

static const char * __doc_Bentley_DgnPlatform_EditLevelHandle_SetTransparency =R"doc(Set the level display transparency.

Returns:
    true if the new value is different from the current value.)doc";

static const char * __doc_Bentley_DgnPlatform_EditLevelHandle_SetDisplayPriority =R"doc(Set the level display priority.

Returns:
    true if the new value is different from the current value.)doc";

static const char * __doc_Bentley_DgnPlatform_EditLevelHandle_SetLocate =R"doc(Specify if elements on this level may be located.

Returns:
    true if the new value is different from the current value.)doc";

static const char * __doc_Bentley_DgnPlatform_EditLevelHandle_SetFrozen =R"doc(Specify if elements on this level are frozen.

Returns:
    true if the new value is different from the current value.)doc";

static const char * __doc_Bentley_DgnPlatform_EditLevelHandle_SetElementAccess =R"doc(Specify access restrictions to be applied to elements on this level

Parameter ``access``:
    can be one of:-- LevelElementAccess::All:Elements on the level
    have all access. This is the default mode --
    LevelElementAccess::Locked:Elements on the level are locked. They
    can be copied, but cannot be modified or deleted. New elements can
    be added to the level - once added they are immediately locked.
    The level can be set active.

Returns:
    true if the new value is different from the current value.)doc";

static const char * __doc_Bentley_DgnPlatform_EditLevelHandle_SetHidden =R"doc(Specify if this level is hidden, i.e., should not be shown to the
user.

Returns:
    true if the new value is different from the current value.)doc";

static const char * __doc_Bentley_DgnPlatform_EditLevelHandle_SetSnap =R"doc(Specify if elements on this level may be snapped to.

Returns:
    true if the new value is different from the current value.)doc";

static const char * __doc_Bentley_DgnPlatform_EditLevelHandle_SetByCell =R"doc(*TBD...*)doc";

static const char * __doc_Bentley_DgnPlatform_EditLevelHandle_SetPlot =R"doc(Specify if elements on this level should be plotted.

Returns:
    true if the new value is different from the current value.)doc";

static const char * __doc_Bentley_DgnPlatform_EditLevelHandle_SetDisplay =R"doc(Specify if elements on this level should be displayed.

Returns:
    true if the new value is different from the current value.)doc";

static const char * __doc_Bentley_DgnPlatform_EditLevelHandle_SetOverrideMaterialOn =R"doc(Specify if level material should be used when applying level
symbology.

Returns:
    true if the new value is different from the current value.)doc";

static const char * __doc_Bentley_DgnPlatform_EditLevelHandle_SetOverrideWeightOn =R"doc(Specify if level weight should be used when applying level symbology.

Returns:
    true if the new value is different from the current value.)doc";

static const char * __doc_Bentley_DgnPlatform_EditLevelHandle_SetOverrideLineStyleOn =R"doc(Specify if level style should be used when applying level symbology.

Returns:
    true if the new value is different from the current value.)doc";

static const char * __doc_Bentley_DgnPlatform_EditLevelHandle_SetOverrideColorOn =R"doc(Specify if level color should be used when applying level symbology.

Returns:
    true if the new value is different from the current value.)doc";

static const char * __doc_Bentley_DgnPlatform_EditLevelHandle_SetByLevelMaterial =R"doc(Set the material to use when an element's material is defined as " by - level ".

Returns:
    true if the new value is different from the current value.)doc";

static const char * __doc_Bentley_DgnPlatform_EditLevelHandle_SetByLevelWeight =R"doc(Set the weight to use when an element's weight is defined as " by - level ".

Returns:
    true if the new value is different from the current value.)doc";

static const char * __doc_Bentley_DgnPlatform_EditLevelHandle_SetByLevelLineStyle =R"doc(Set the style to use when an element's style is defined as " by - level ".

Returns:
    true if the new value is different from the current value.)doc";

static const char * __doc_Bentley_DgnPlatform_EditLevelHandle_SetByLevelColor =R"doc(Set the color to use when an element's color is defined as " by - level ".

Returns:
    true if the new value is different from the current value.)doc";

static const char * __doc_Bentley_DgnPlatform_EditLevelHandle_SetOverrideMaterial =R"doc(Set the material to use when applying level symbology.

Returns:
    true if the new value is different from the current value.)doc";

static const char * __doc_Bentley_DgnPlatform_EditLevelHandle_SetOverrideWeight =R"doc(Set the weight to use when applying level symbology.

Returns:
    true if the new value is different from the current value.)doc";

static const char * __doc_Bentley_DgnPlatform_EditLevelHandle_SetOverrideColor =R"doc(Set the color to use when applying level symbology.

Returns:
    true if the new value is different from the current value.)doc";

static const char * __doc_Bentley_DgnPlatform_EditLevelHandle_CopyLevelData =R"doc(Copy attribute values from *sourceLevel* to this level.

Remark:
    s LEVEL_ID_ATTRIBUTE, LEVEL_CODE_ATTRIBUTE, and
    LEVEL_NAME_ATTRIBUTE are not supported. In order to change a
    level's code or name, you must call SetLevelCode or SetName. These
    methods can fail. You cannot change a level's ID. Call CreateLevel
    in order to create a level with a specified LevelId.

Parameter ``sourceLevel``:
    The level to copy from.

Parameter ``m``:
    [optional] Identifies the properties to copy.

Returns:
    true if any property value was actually modified)doc";

static const char * __doc_Bentley_DgnPlatform_EditLevelHandle_SetDescription =R"doc(Change the description of this level.

Returns:
    true if the new description is different from the old.)doc";

static const char * __doc_Bentley_DgnPlatform_EditLevelHandle_SetLevelCode =R"doc(Change the LevelCode of this level.

Parameter ``levelCode``:
    The level code to set.

Parameter ``autoGenerated``:
    If true, then the system does not attempt to retain this Level
    Code. If false, the system retains that level code from library
    levels.

Returns:
    \li LevelCacheErrorCode::TableIsReadOnly - The level table is
    read-only \li LevelCacheErrorCode::LevelCodeIsDuplicate - *code*
    is a LevelCode that is already used by another level in this cache)doc";

static const char * __doc_Bentley_DgnPlatform_EditLevelHandle_SetName =R"doc(Change the name of this level.

Returns:
    \li LevelCacheErrorCode::TableIsReadOnly - The level table is
    read-only \li LevelCacheErrorCode::LevelNameIsDuplicate - *name*
    is a name that is already used by another level in this cache \li
    LevelCacheErrorCode::LevelNameIsInvalid - *name* contains invalid
    characters. See LevelUtils::ContainsInvalidCharacters)doc";

static const char * __doc_Bentley_DgnPlatform_EditLevelHandle_IsDirty =R"doc(Query if this level has been changed since the last call to
FileLevelCache::Write)doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_GetPlotStyle =R"doc(Get the PlotStyle)doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_GetTransparency =R"doc(Get the level display transparency)doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_GetDisplayPriority =R"doc(Get the level display priority)doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_GetCodeAutoGenerated =R"doc(Query if the LevelCode associated with this level was generated and
assigned by the LevelCache automatically, rather than by the user.)doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_GetLocate =R"doc(Query if elements on this level may be located)doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_GetFrozen =R"doc(Query if elements on this level are frozen)doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_GetElementAccess =R"doc(Query access restrictions to be applied to elements on this level.

Returns:
    -- LevelElementAccess::All:Elements on the level have all access.
    This is the default mode -- LevelElementAccess::Locked:Elements
    on the level are locked. They can be copied, but cannot be
    modified or deleted. New elements can be added to the level - once
    added they are immediately locked. The level can be set active.)doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_GetHidden =R"doc(Query if this level is hidden, i.e., should not be shown to the user)doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_GetReadOnly =R"doc(Query if this level should not be modified)doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_GetSnap =R"doc(Query if elements on this level may be snapped to)doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_GetByCell =R"doc(*TBD...*)doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_GetPlot =R"doc(Query if elements on this level should be plotted)doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_GetDisplay =R"doc(Query if elements on this level should be displayed)doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_GetOverrideMaterialOn =R"doc(Query if level material should be used when applying level symbology)doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_GetOverrideWeightOn =R"doc(Query if level weight should be used when applying level symbology)doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_GetOverrideLineStyleOn =R"doc(Query if level style should be used when applying level symbology)doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_GetOverrideColorOn =R"doc(Query if level color should be used when applying level symbology)doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_GetByLevelMaterial =R"doc(Get the material to use when an element's material is defined as " by - level ")doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_GetByLevelWeight =R"doc(Get the weight to use when an element's weight is defined as " by - level ")doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_GetByLevelLineStyle =R"doc(Get the style to use when an element's style is defined as " by - level ")doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_GetByLevelColor =R"doc(Get the color to use when an element's color is defined as " by - level "
Example:LevelCacheCodeSamples_GetByLevelColor)doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_GetOverrideMaterial =R"doc(Get the material to use when applying level symbology)doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_GetOverrideWeight =R"doc(Get the weight to use when applying level symbology)doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_GetOverrideLineStyle =R"doc(Get the style to use when applying level symbology)doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_GetOverrideColor =R"doc(Get the color to use when applying level symbology)doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_EqualLevelData =R"doc(Compare the data contained this level definition to the data contained
in *sourceLevel.*

Returns:
    true if the specified attributes match.

Parameter ``differences``:
    [optional] if not NULL, records the attributes that do not match.

Parameter ``sourceLevel``:
    The level to which this level is to be compared.

Parameter ``attributesToCompare``:
    [optional] if not NULL, specifies which attributes to compare. If
    null, all attributes are compared.

Remark:
    s When comparing levels from different files, EqualLevelData
    attempts to detect if colors and styles are *equivalent.*

Remark:
    s EqualLevelData never compares LevelIDs. If you want to detect if
    two levels have the same LevelId, you must call GetLevelId on each
    of them. Two levels in the same level cache will never have the
    same LevelId. It is rarely meaningful to compare the LevelIDs of
    levels from different caches.

Remark:
    s This function does not compare the ElementIds of the levels)doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_GetStatus =R"doc(Returns non-zero error status if this is an invalid handle. The status
indicates why the level cache operation that produced this handle
failed. Example:LevelCacheCodeSamples_CreateLevel

See also:
    IsValid)doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_IsAlias =R"doc(Is this level an alias for another level in another level cache?)doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_IsValid =R"doc(Returns true if this handle refers to a level, false if this is an
invalid handle. Example:LevelCacheCodeSamples_CreateLevel

See also:
    GetStatus to query the reason why a handle is invalid.)doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_GetLevelCode =R"doc(Get the optional code assigned to this level)doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_FormatDisplayName =R"doc(Format the display name of this level from a format string. This
method is generally used by the _FormatLevelDisplayName method of
implementations of LevelCacheAdmin.)doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_GetDisplayName =R"doc(Get the display name of this level.)doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_GetName =R"doc(Get the name of this level. May be NULL.)doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_GetDescription =R"doc(Get the description or purpose of this level. May be NULL.)doc";

static const char * __doc_Bentley_DgnPlatform_LevelHandle_GetLevelId =R"doc(Get the internal identifier for this level)doc";

static const char * __doc_Bentley_DgnPlatform_LevelDefinitionLineStyle_GetStyleParams =R"doc(Get the parameters to be used with this line style.

Returns:
    false if this definition does not include parameters to be used
    with this line style.)doc";

static const char * __doc_Bentley_DgnPlatform_LevelDefinitionLineStyle_HasStyleParams =R"doc(Query if this definition includes parameters to be used with this line
style.)doc";

static const char * __doc_Bentley_DgnPlatform_LevelDefinitionLineStyle_GetStyle =R"doc(Get the line style code. @See GetDefinitionFile)doc";

static const char * __doc_Bentley_DgnPlatform_LevelDefinitionColor_GetColor =R"doc(Get the color code. @See GetDefinitionFile)doc";

static const char * __doc_Bentley_DgnPlatform_LevelDefinitionStyleBase_GetDefinitionModel =R"doc(Get a representative model in that file that defines a color or style.)doc";

static const char * __doc_Bentley_DgnPlatform_LevelDefinitionStyleBase_GetDefinitionFile =R"doc(Get the file that defines a color or style.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_LevelCache(py::module_& m)
    {
    //===================================================================================
    // enum class LevelCacheErrorCode
    py::enum_< LevelCacheErrorCode>(m, "LevelCacheErrorCode")
        .value("eNone", LevelCacheErrorCode::None)
        .value("eError", LevelCacheErrorCode::Error)
        .value("eTableIsReadOnly", LevelCacheErrorCode::TableIsReadOnly)
        .value("eLevelIsReadOnly", LevelCacheErrorCode::LevelIsReadOnly)
        .value("eLevelNameIsNull", LevelCacheErrorCode::LevelNameIsNull)
        .value("eLevelNameIsInvalid", LevelCacheErrorCode::LevelNameIsInvalid)
        .value("eLevelNameIsDuplicate", LevelCacheErrorCode::LevelNameIsDuplicate)
        .value("eLevelIsUsed", LevelCacheErrorCode::LevelIsUsed)
        .value("eLevelCodeIsDuplicate", LevelCacheErrorCode::LevelCodeIsDuplicate)
        .value("eLevelIdIsDuplicate", LevelCacheErrorCode::LevelIdIsDuplicate)
        .value("eLibraryLevelNotEditable", LevelCacheErrorCode::LibraryLevelNotEditable)
        .value("eCannotFindLevel", LevelCacheErrorCode::CannotFindLevel)
        .value("eLevelTableIntegrityFailure", LevelCacheErrorCode::LevelTableIntegrityFailure)
        .value("eDgnAttachmentNotResolved", LevelCacheErrorCode::DgnAttachmentNotResolved)
        .value("eLevelNullId", LevelCacheErrorCode::LevelNullId)
        .value("eNoLevels", LevelCacheErrorCode::NoLevels)
        .value("eAttachmentSharesFileLevelCache", LevelCacheErrorCode::AttachmentSharesFileLevelCache)
        .export_values();

    // Level Display Name Format Defines
    m.attr("LEVEL_NAME_DISPLAY_FORMAT_STRING") = LEVEL_NAME_DISPLAY_FORMAT_STRING;
    m.attr("LEVEL_CODE_DISPLAY_FORMAT_STRING") = LEVEL_CODE_DISPLAY_FORMAT_STRING;
    m.attr("LEVEL_DESCRIPTION_DISPLAY_FORMAT_STRING") = LEVEL_DESCRIPTION_DISPLAY_FORMAT_STRING;

    // Level Display Name Format Values
    m.attr("LEVEL_NAME_DISPLAY_FORMAT") = LEVEL_NAME_DISPLAY_FORMAT;
    m.attr("LEVEL_CODE_DISPLAY_FORMAT") = LEVEL_CODE_DISPLAY_FORMAT;
    m.attr("LEVEL_DESCRIPTION_DISPLAY_FORMAT") = LEVEL_DESCRIPTION_DISPLAY_FORMAT;
    m.attr("LEVEL_ID_DISPLAY_FORMAT") = LEVEL_ID_DISPLAY_FORMAT;

    //===================================================================================
    // struct LevelDefinitionStyleBase
    py::class_< LevelDefinitionStyleBase> c2(m, "LevelDefinitionStyleBase");

    c2.def(py::init<DgnFileP>(), "dgnFile"_a);
    
    c2.def_property_readonly("DefinitionFile", &LevelDefinitionStyleBase::GetDefinitionFile);
    c2.def("GetDefinitionFile", &LevelDefinitionStyleBase::GetDefinitionFile, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, LevelDefinitionStyleBase, GetDefinitionFile));

    c2.def_property_readonly("DefinitionModel", &LevelDefinitionStyleBase::GetDefinitionModel);
    c2.def("GetDefinitionModel", &LevelDefinitionStyleBase::GetDefinitionModel, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, LevelDefinitionStyleBase, GetDefinitionModel));

    //===================================================================================
    // struct LevelDefinitionColor
    py::class_< LevelDefinitionColor, LevelDefinitionStyleBase> c3(m, "LevelDefinitionColor");

    c3.def(py::init<UInt32, DgnFileP>(), "color"_a, "dgnFile"_a);

    c3.def_property_readonly("Color", &LevelDefinitionColor::GetColor);
    c3.def("GetColor", &LevelDefinitionColor::GetColor, DOC(Bentley, DgnPlatform, LevelDefinitionColor, GetColor));
    
    c3.def(py::self == py::self);
    c3.def(py::self != py::self);

    //===================================================================================
    // struct LevelDefinitionLineStyle
    py::class_< LevelDefinitionLineStyle, LevelDefinitionStyleBase> c4(m, "LevelDefinitionLineStyle");

    c4.def(py::init<int, LineStyleParamsCP, DgnFileP>(), "color"_a, "params"_a, "dgnFile"_a);
    
    c4.def_property_readonly("Style", &LevelDefinitionLineStyle::GetStyle);
    c4.def("GetStyle", &LevelDefinitionLineStyle::GetStyle, DOC(Bentley, DgnPlatform, LevelDefinitionLineStyle, GetStyle));
    
    c4.def(py::self == py::self);
    c4.def(py::self != py::self);
    
    c4.def("HasStyleParams", &LevelDefinitionLineStyle::HasStyleParams, DOC(Bentley, DgnPlatform, LevelDefinitionLineStyle, HasStyleParams));
    c4.def_property_readonly("StyleParams", &LevelDefinitionLineStyle::GetStyleParamsP);
    c4.def("GetStyleParams", &LevelDefinitionLineStyle::GetStyleParamsP, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, LevelDefinitionLineStyle, GetStyleParams));

    //===================================================================================
    // struct LevelDefinitionIdBase
    py::class_< LevelDefinitionIdBase, LevelDefinitionStyleBase> c5(m, "LevelDefinitionIdBase");

    c5.def(py::init<ElementId, DgnFileP>(), "elementId"_a, "dgnFile"_a);    
    c5.def(py::self == py::self);
    c5.def_property_readonly("ElementId", &LevelDefinitionIdBase::GetId);
    c5.def("GetElementId", &LevelDefinitionIdBase::GetId);

    //===================================================================================
    // struct LevelDefinitionMaterial
    py::class_< LevelDefinitionMaterial, LevelDefinitionIdBase> c6(m, "LevelDefinitionMaterial");

    c6.def(py::init<ElementId, DgnFileP>(), "elementId"_a, "dgnFile"_a);
    c6.def(py::self == py::self);
    c6.def(py::self != py::self);

    //===================================================================================
    // struct LevelDefinitionPlotStyle
    py::class_< LevelDefinitionPlotStyle, LevelDefinitionIdBase> c7(m, "LevelDefinitionPlotStyle");

    c7.def(py::init<ElementId, DgnFileP>(), "elementId"_a, "dgnFile"_a);
    c7.def(py::self == py::self);
    c7.def(py::self != py::self);

    //===================================================================================
    // struct LevelHandle
    py::class_< LevelHandle> c8(m, "LevelHandle");
    
    c8.def(py::init<>());
    
    c8.def_property_readonly("LevelId", &LevelHandle::GetLevelId);
    c8.def("GetLevelId", &LevelHandle::GetLevelId, DOC(Bentley, DgnPlatform, LevelHandle, GetLevelId));
    
    c8.def_property_readonly("Description", &LevelHandle::GetDescription);
    c8.def("GetDescription", &LevelHandle::GetDescription, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, LevelHandle, GetDescription));
    
    c8.def_property_readonly("Name", &LevelHandle::GetName);
    c8.def("GetName", &LevelHandle::GetName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, LevelHandle, GetName));
    
    c8.def("GetDisplayName", &LevelHandle::GetDisplayName, "displayName"_a, DOC(Bentley, DgnPlatform, LevelHandle, GetDisplayName));    
    c8.def("FormatDisplayName", &LevelHandle::FormatDisplayName, "displayName"_a, "formatString"_a, DOC(Bentley, DgnPlatform, LevelHandle, FormatDisplayName));
    
    c8.def_property_readonly("LevelCode", &LevelHandle::GetLevelCode);
    c8.def("GetLevelCode", &LevelHandle::GetLevelCode, DOC(Bentley, DgnPlatform, LevelHandle, GetLevelCode));
    
    c8.def_property_readonly("LevelCache", &LevelHandle::GetLevelCacheP);
    c8.def("GetLevelCache", &LevelHandle::GetLevelCacheP, py::return_value_policy::reference_internal);
    
    c8.def("IsValid", &LevelHandle::IsValid, DOC(Bentley, DgnPlatform, LevelHandle, IsValid));    
    c8.def("IsAlias", &LevelHandle::IsAlias, DOC(Bentley, DgnPlatform, LevelHandle, IsAlias));
    
    c8.def_property_readonly("Status", &LevelHandle::GetStatus);
    c8.def("GetStatus", &LevelHandle::GetStatus, DOC(Bentley, DgnPlatform, LevelHandle, GetStatus));
    
    c8.def(py::self == py::self);
    c8.def(py::self != py::self);
    c8.def("EqualLevelData", &LevelHandle::EqualLevelData, "differences"_a, "sourceLevel"_a, "attributesToCompare"_a, DOC(Bentley, DgnPlatform, LevelHandle, EqualLevelData));
    
    c8.def_property_readonly("OverrideColor", &LevelHandle::GetOverrideColor);
    c8.def("GetOverrideColor", &LevelHandle::GetOverrideColor, DOC(Bentley, DgnPlatform, LevelHandle, GetOverrideColor));
    
    c8.def_property_readonly("OverrideLineStyle", &LevelHandle::GetOverrideLineStyle);
    c8.def("GetOverrideLineStyle", &LevelHandle::GetOverrideLineStyle, DOC(Bentley, DgnPlatform, LevelHandle, GetOverrideLineStyle));
    
    c8.def_property_readonly("OverrideWeight", &LevelHandle::GetOverrideWeight);
    c8.def("GetOverrideWeight", &LevelHandle::GetOverrideWeight, DOC(Bentley, DgnPlatform, LevelHandle, GetOverrideWeight));
    
    c8.def_property_readonly("OverrideMaterial", &LevelHandle::GetOverrideMaterial);
    c8.def("GetOverrideMaterial", &LevelHandle::GetOverrideMaterial, DOC(Bentley, DgnPlatform, LevelHandle, GetOverrideMaterial));
    
    c8.def_property_readonly("ByLevelColor", &LevelHandle::GetByLevelColor);
    c8.def("GetByLevelColor", &LevelHandle::GetByLevelColor, DOC(Bentley, DgnPlatform, LevelHandle, GetByLevelColor));
    
    c8.def_property_readonly("ByLevelLineStyle", &LevelHandle::GetByLevelLineStyle);
    c8.def("GetByLevelLineStyle", &LevelHandle::GetByLevelLineStyle, DOC(Bentley, DgnPlatform, LevelHandle, GetByLevelLineStyle));
    
    c8.def_property_readonly("ByLevelWeight", &LevelHandle::GetByLevelWeight);
    c8.def("GetByLevelWeight", &LevelHandle::GetByLevelWeight, DOC(Bentley, DgnPlatform, LevelHandle, GetByLevelWeight));
    
    c8.def_property_readonly("ByLevelMaterial", &LevelHandle::GetByLevelMaterial);
    c8.def("GetByLevelMaterial", &LevelHandle::GetByLevelMaterial, DOC(Bentley, DgnPlatform, LevelHandle, GetByLevelMaterial));
    
    c8.def_property_readonly("OverrideColorOn", &LevelHandle::GetOverrideColorOn);
    c8.def("GetOverrideColorOn", &LevelHandle::GetOverrideColorOn, DOC(Bentley, DgnPlatform, LevelHandle, GetOverrideColorOn));
    
    c8.def_property_readonly("OverrideLineStyleOn", &LevelHandle::GetOverrideLineStyleOn);
    c8.def("GetOverrideLineStyleOn", &LevelHandle::GetOverrideLineStyleOn, DOC(Bentley, DgnPlatform, LevelHandle, GetOverrideLineStyleOn));
    
    c8.def_property_readonly("OverrideWeightOn", &LevelHandle::GetOverrideWeightOn);
    c8.def("GetOverrideWeightOn", &LevelHandle::GetOverrideWeightOn, DOC(Bentley, DgnPlatform, LevelHandle, GetOverrideWeightOn));
    
    c8.def_property_readonly("OverrideMaterialOn", &LevelHandle::GetOverrideMaterialOn);
    c8.def("GetOverrideMaterialOn", &LevelHandle::GetOverrideMaterialOn, DOC(Bentley, DgnPlatform, LevelHandle, GetOverrideMaterialOn));
    
    c8.def_property_readonly("IsDisplay", &LevelHandle::GetDisplay);
    c8.def("GetDisplay", &LevelHandle::GetDisplay, DOC(Bentley, DgnPlatform, LevelHandle, GetDisplay));
    
    c8.def_property_readonly("IsPlot", &LevelHandle::GetPlot);
    c8.def("GetPlot", &LevelHandle::GetPlot, DOC(Bentley, DgnPlatform, LevelHandle, GetPlot));
    
    c8.def_property_readonly("IsByCell", &LevelHandle::GetByCell);
    c8.def("GetByCell", &LevelHandle::GetByCell, DOC(Bentley, DgnPlatform, LevelHandle, GetByCell));
    
    c8.def_property_readonly("IsSnap", &LevelHandle::GetSnap);
    c8.def("GetSnap", &LevelHandle::GetSnap, DOC(Bentley, DgnPlatform, LevelHandle, GetSnap));
    
    c8.def_property_readonly("IsReadOnly", &LevelHandle::GetReadOnly);
    c8.def("GetReadOnly", &LevelHandle::GetReadOnly, DOC(Bentley, DgnPlatform, LevelHandle, GetReadOnly));
    
    c8.def_property_readonly("IsHidden", &LevelHandle::GetHidden);
    c8.def("GetHidden", &LevelHandle::GetHidden, DOC(Bentley, DgnPlatform, LevelHandle, GetHidden));
    
    c8.def_property_readonly("ElementAccess", &LevelHandle::GetElementAccess);
    c8.def("GetElementAccess", &LevelHandle::GetElementAccess, DOC(Bentley, DgnPlatform, LevelHandle, GetElementAccess));
    
    c8.def_property_readonly("IsFrozen", &LevelHandle::GetFrozen);
    c8.def("GetFrozen", &LevelHandle::GetFrozen, DOC(Bentley, DgnPlatform, LevelHandle, GetFrozen));
    
    c8.def_property_readonly("CanLocate", &LevelHandle::GetLocate);
    c8.def("GetLocate", &LevelHandle::GetLocate, DOC(Bentley, DgnPlatform, LevelHandle, GetLocate));
    
    c8.def_property_readonly("IsCodeAutoGenerated", &LevelHandle::GetCodeAutoGenerated);
    c8.def("GetCodeAutoGenerated", &LevelHandle::GetCodeAutoGenerated, DOC(Bentley, DgnPlatform, LevelHandle, GetCodeAutoGenerated));
    
    c8.def_property_readonly("DisplayPriority", &LevelHandle::GetDisplayPriority);
    c8.def("GetDisplayPriority", &LevelHandle::GetDisplayPriority, DOC(Bentley, DgnPlatform, LevelHandle, GetDisplayPriority));
    
    c8.def_property_readonly("Transparency", &LevelHandle::GetTransparency);
    c8.def("GetTransparency", &LevelHandle::GetTransparency, DOC(Bentley, DgnPlatform, LevelHandle, GetTransparency));
    
    c8.def_property_readonly("PlotStyle", &LevelHandle::GetPlotStyle);
    c8.def("GetPlotStyle", &LevelHandle::GetPlotStyle, DOC(Bentley, DgnPlatform, LevelHandle, GetPlotStyle));

    //===================================================================================
    // struct EditLevelHandle
    py::class_< EditLevelHandle, LevelHandle> c9(m, "EditLevelHandle");

    c9.def(py::init<>());
    c9.def(py::init<LevelHandle>(), "levelHandle"_a);
    c9.def("IsDirty", &EditLevelHandle::IsDirty, DOC(Bentley, DgnPlatform, EditLevelHandle, IsDirty));
    c9.def("SetName", &EditLevelHandle::SetName, "name"_a, DOC(Bentley, DgnPlatform, EditLevelHandle, SetName));
    c9.def("SetLevelCode", &EditLevelHandle::SetLevelCode, "levelCode"_a, "autoGenerated"_a, DOC(Bentley, DgnPlatform, EditLevelHandle, SetLevelCode));
    c9.def("SetDescription", &EditLevelHandle::SetDescription, "description"_a, DOC(Bentley, DgnPlatform, EditLevelHandle, SetDescription));
    c9.def("CopyLevelData", &EditLevelHandle::CopyLevelData, "sourceLevel"_a, "mask"_a = nullptr, DOC(Bentley, DgnPlatform, EditLevelHandle, CopyLevelData));
    c9.def("SetOverrideColor", &EditLevelHandle::SetOverrideColor, "colorDef"_a, DOC(Bentley, DgnPlatform, EditLevelHandle, SetOverrideColor));
    c9.def("SetOverrideLineStyle", py::overload_cast<LsEntryCR, LineStyleParamsCP, DgnFileR>(&EditLevelHandle::SetOverrideLineStyle), "l"_a, "p"_a, "f"_a);
    c9.def("SetOverrideWeight", &EditLevelHandle::SetOverrideWeight, "weight"_a, DOC(Bentley, DgnPlatform, EditLevelHandle, SetOverrideWeight));
    c9.def("SetOverrideMaterial", &EditLevelHandle::SetOverrideMaterial, "materialDef"_a, DOC(Bentley, DgnPlatform, EditLevelHandle, SetOverrideMaterial));
    c9.def("SetByLevelColor", &EditLevelHandle::SetByLevelColor, "colorDef"_a, DOC(Bentley, DgnPlatform, EditLevelHandle, SetByLevelColor));
    c9.def("SetByLevelLineStyle", py::overload_cast<LsEntryCR, LineStyleParamsCP, DgnFileR>(&EditLevelHandle::SetByLevelLineStyle), "entry"_a, "params"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, EditLevelHandle, SetByLevelLineStyle));
    c9.def("SetByLevelWeight", &EditLevelHandle::SetByLevelWeight, "weight"_a, DOC(Bentley, DgnPlatform, EditLevelHandle, SetByLevelWeight));
    c9.def("SetByLevelMaterial", &EditLevelHandle::SetByLevelMaterial, "materialDef"_a, DOC(Bentley, DgnPlatform, EditLevelHandle, SetByLevelMaterial));
    c9.def("SetOverrideColorOn", &EditLevelHandle::SetOverrideColorOn, "value"_a, DOC(Bentley, DgnPlatform, EditLevelHandle, SetOverrideColorOn));
    c9.def("SetOverrideLineStyleOn", &EditLevelHandle::SetOverrideLineStyleOn, "value"_a, DOC(Bentley, DgnPlatform, EditLevelHandle, SetOverrideLineStyleOn));
    c9.def("SetOverrideWeightOn", &EditLevelHandle::SetOverrideWeightOn, "value"_a, DOC(Bentley, DgnPlatform, EditLevelHandle, SetOverrideWeightOn));
    c9.def("SetOverrideMaterialOn", &EditLevelHandle::SetOverrideMaterialOn, "value"_a, DOC(Bentley, DgnPlatform, EditLevelHandle, SetOverrideMaterialOn));
    c9.def("SetDisplay", &EditLevelHandle::SetDisplay, "value"_a, DOC(Bentley, DgnPlatform, EditLevelHandle, SetDisplay));
    c9.def("SetPlot", &EditLevelHandle::SetPlot, "value"_a, DOC(Bentley, DgnPlatform, EditLevelHandle, SetPlot));
    c9.def("SetByCell", &EditLevelHandle::SetByCell, "value"_a, DOC(Bentley, DgnPlatform, EditLevelHandle, SetByCell));
    c9.def("SetSnap", &EditLevelHandle::SetSnap, "value"_a, DOC(Bentley, DgnPlatform, EditLevelHandle, SetSnap));
    c9.def("SetHidden", &EditLevelHandle::SetHidden, "value"_a, DOC(Bentley, DgnPlatform, EditLevelHandle, SetHidden));
    c9.def("SetElementAccess", &EditLevelHandle::SetElementAccess, "access"_a, DOC(Bentley, DgnPlatform, EditLevelHandle, SetElementAccess));
    c9.def("SetFrozen", &EditLevelHandle::SetFrozen, "value"_a, DOC(Bentley, DgnPlatform, EditLevelHandle, SetFrozen));
    c9.def("SetLocate", &EditLevelHandle::SetLocate, "value"_a, DOC(Bentley, DgnPlatform, EditLevelHandle, SetLocate));
    c9.def("SetDisplayPriority", &EditLevelHandle::SetDisplayPriority, "priority"_a, DOC(Bentley, DgnPlatform, EditLevelHandle, SetDisplayPriority));
    c9.def("SetTransparency", &EditLevelHandle::SetTransparency, "transparency"_a, DOC(Bentley, DgnPlatform, EditLevelHandle, SetTransparency));
    c9.def("SetPlotStyle", &EditLevelHandle::SetPlotStyle, "plotStyleDef"_a, DOC(Bentley, DgnPlatform, EditLevelHandle, SetPlotStyle));
    c9.def("EditElementRelatedProperties", &EditLevelHandle::EditElementRelatedProperties, "context"_a, DOC(Bentley, DgnPlatform, EditLevelHandle, EditElementRelatedProperties));

    //===================================================================================
    // struct LevelCache
    py::class_< LevelCache, RefCountedPtr<LevelCache> > c10(m, "LevelCache");

    c10.def("GetLevel", &LevelCache::GetLevel, "levelId"_a, "includeLibraries"_a = false, DOC(Bentley, DgnPlatform, LevelCache, GetLevel));
    c10.def("GetLevelByCode", &LevelCache::GetLevelByCode, "levelCode"_a, "includeLibraries"_a = false, DOC(Bentley, DgnPlatform, LevelCache, GetLevelByCode));
    c10.def("GetLevelByName", &LevelCache::GetLevelByName, "levelName"_a, "includeLibraries"_a = false, DOC(Bentley, DgnPlatform, LevelCache, GetLevelByName));
    c10.def("GetLevelByDisplayName", &LevelCache::GetLevelByDisplayName, "levelDisplayName"_a, "includeLibraries"_a = false, DOC(Bentley, DgnPlatform, LevelCache, GetLevelByDisplayName));
    c10.def("GetLevelCount", &LevelCache::GetLevelCount, "includeLibraries"_a = false, DOC(Bentley, DgnPlatform, LevelCache, GetLevelCount));
    c10.def("ComputeHighestUsedLevelId", &LevelCache::ComputeHighestUsedLevelId, DOC(Bentley, DgnPlatform, LevelCache, ComputeHighestUsedLevelId));
    c10.def("ComputeHighestUsedLevelCode", &LevelCache::ComputeHighestUsedLevelCode, DOC(Bentley, DgnPlatform, LevelCache, ComputeHighestUsedLevelCode));

    c10.def_property_readonly("LowestAvailableLevelId", &LevelCache::GetLowestAvailableLevelId);
    c10.def("GetLowestAvailableLevelId", &LevelCache::GetLowestAvailableLevelId, DOC(Bentley, DgnPlatform, LevelCache, GetLowestAvailableLevelId));
    
    c10.def_property_readonly("LowestAvailableLevelCode", &LevelCache::GetLowestAvailableLevelCode);
    c10.def("GetLowestAvailableLevelCode", &LevelCache::GetLowestAvailableLevelCode, DOC(Bentley, DgnPlatform, LevelCache, GetLowestAvailableLevelCode));
    
    c10.def("GetLastModifiedTimeForLevelDefinitions", [] (LevelCache const& self)
            {
            UInt32 timeStampOut = 0;
            auto retVal = self.GetLastModifiedTimeForLevelDefinitions(timeStampOut);
            return py::make_tuple(retVal, timeStampOut);
            }, DOC(Bentley, DgnPlatform, LevelCache, GetLastModifiedTimeForLevelDefinitions));

    c10.def("IsReadOnly", &LevelCache::IsReadOnly, DOC(Bentley, DgnPlatform, LevelCache, IsReadOnly));
    c10.def("EqualLevelData", &LevelCache::EqualLevelData, "rhs"_a, "compareElementIds"_a = false, "compareAttributesMask"_a = nullptr, DOC(Bentley, DgnPlatform, LevelCache, EqualLevelData));
    c10.def("IsHiddenStatePersisted", &LevelCache::IsHiddenStatePersisted, DOC(Bentley, DgnPlatform, LevelCache, IsHiddenStatePersisted));
    c10.def("SetPersistHiddenState", &LevelCache::SetPersistHiddenState, "persistState"_a, DOC(Bentley, DgnPlatform, LevelCache, SetPersistHiddenState));
    c10.def("__iter__", [] (LevelCache& self) { return py::make_iterator(self.begin(), self.end()); });

    //===================================================================================
    // enum class EditPropertiesChangeWrite
    py::enum_< EditPropertiesChangeWrite>(m, "EditPropertiesChangeWrite")
        .value("eAlways", EditPropertiesChangeWrite::Always)
        .value("eIfNewChangesOnly", EditPropertiesChangeWrite::IfNewChangesOnly)
        .value("eNever", EditPropertiesChangeWrite::Never)
        .export_values();

    //===================================================================================
    // struct PersistentLevelCache
    py::class_< PersistentLevelCache, RefCountedPtr<PersistentLevelCache>, LevelCache> c11(m, "PersistentLevelCache");

    c11.def("Write", py::overload_cast<>(&PersistentLevelCache::Write), DOC(Bentley, DgnPlatform, PersistentLevelCache, Write));
    c11.def("IsDirty", &PersistentLevelCache::IsDirty, DOC(Bentley, DgnPlatform, PersistentLevelCache, IsDirty));
    c11.def("EditProperties", &PersistentLevelCache::EditProperties, "context"_a, "writeChanges"_a, DOC(Bentley, DgnPlatform, PersistentLevelCache, EditProperties));

    //===================================================================================
    // struct FileLevelCache
    py::class_< FileLevelCache, RefCountedPtr<FileLevelCache>, PersistentLevelCache> c12(m, "FileLevelCache");

    c12.def(py::init(&FileLevelCache::Create), "dgnFile"_a);
    c12.def("GetDgnFile", &FileLevelCache::GetDgnFileR, py::return_value_policy::reference_internal);
    c12.def("CreateLevel", &FileLevelCache::CreateLevel, "levelName"_a, "levelCode"_a, "levelId"_a, DOC(Bentley, DgnPlatform, FileLevelCache, CreateLevel));
    c12.def("CreateDefaultLevel", &FileLevelCache::CreateDefaultLevel, DOC(Bentley, DgnPlatform, FileLevelCache, CreateDefaultLevel));
    c12.def("CopyLevel", &FileLevelCache::CopyLevel, "source"_a, "replaceDuplicateLevelCode"_a = false, DOC(Bentley, DgnPlatform, FileLevelCache, CopyLevel));
    c12.def("RemoveLevel", &FileLevelCache::RemoveLevel, "nextLevel"_a, "level"_a, DOC(Bentley, DgnPlatform, FileLevelCache, RemoveLevel));
    c12.def("SetLevelReadOnly", &FileLevelCache::SetLevelReadOnly, "level"_a, "isReadonly"_a, DOC(Bentley, DgnPlatform, FileLevelCache, SetLevelReadOnly));
    c12.def("GetHighestUsedLevelId", &FileLevelCache::GetHighestUsedLevelId, "includeLibraries"_a = false, DOC(Bentley, DgnPlatform, FileLevelCache, GetHighestUsedLevelId));

    c12.def_property_readonly("HighestUsedLevelCode", py::overload_cast<>(&FileLevelCache::GetHighestUsedLevelCode, py::const_));
    c12.def("GetHighestUsedLevelCode", py::overload_cast<>(&FileLevelCache::GetHighestUsedLevelCode, py::const_), DOC(Bentley, DgnPlatform, FileLevelCache, GetHighestUsedLevelCode));
     
    c12.def("IsLevelUsedInModel", &FileLevelCache::IsLevelUsedInModel, "modelRef"_a, "levelId"_a, DOC(Bentley, DgnPlatform, FileLevelCache, IsLevelUsedInModel));
    c12.def("IsLevelUsedInFile", &FileLevelCache::IsLevelUsedInFile, "levelId"_a, DOC(Bentley, DgnPlatform, FileLevelCache, IsLevelUsedInFile));
    c12.def_property_readonly("Libraries", &FileLevelCache::GetLibraries);
    c12.def("GetLibraries", &FileLevelCache::GetLibraries, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, FileLevelCache, GetLibraries));

    //===================================================================================
    // struct DgnAttachmentLevelCache
    py::class_< DgnAttachmentLevelCache, RefCountedPtr< DgnAttachmentLevelCache>, PersistentLevelCache> c13(m, "DgnAttachmentLevelCache");

    c13.def_property_readonly("DgnAttachment", &DgnAttachmentLevelCache::GetDgnAttachmentR);
    c13.def("GetDgnAttachment", &DgnAttachmentLevelCache::GetDgnAttachmentR, py::return_value_policy::reference_internal);

    //===================================================================================
    // struct LevelUtils
    py::class_< LevelUtils> c15(m, "LevelUtils");

    c15.def_static("ContainsInvalidCharacters", &LevelUtils::ContainsInvalidCharacters, "levelName"_a, DOC(Bentley, DgnPlatform, LevelUtils, ContainsInvalidCharacters));
    c15.def_static("ReplaceInvalidCharacters", py::overload_cast<WStringR, WChar>(&LevelUtils::ReplaceInvalidCharacters), "levelName"_a, "replacement"_a, DOC(Bentley, DgnPlatform, LevelUtils, ReplaceInvalidCharacters));
    }