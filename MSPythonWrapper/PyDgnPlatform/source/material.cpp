/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\material.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/Material.h>



static const char * __doc_Bentley_DgnPlatform_MaterialManager_HasInternalMaterials =R"doc(Returns if the file contains an internal material table with at least
one material in it

Parameter ``dgnFile``:
    The file to look for internal materials in)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_CopyGeometryMapSharedCellDefs =R"doc(Copy the shared cell definitions associated with geometry maps between
files

Parameter ``destModelRef``:
    The destination model for the geometry map shared cells

Parameter ``sourceModelRef``:
    The source model of the materials

Returns:
    ERROR if the input arguments are invalid)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_GetProjectionGroupParameters =R"doc(Get the projection data associated with a projection NamedGroup

Parameter ``origin``:
    The origin of the projection in UORS

Parameter ``size``:
    The size of the projection in UORS

Parameter ``angles``:
    The rotation applied to the projection


Parameter ``group``:
    The named group representing the projection

Returns (Tuple, 0):
    SUCCESS if the projection group data was available

Returns (Tuple, 1):
	mode.The projection mode to be used

Returns (Tuple, 2):
	variant.Any variation to the projection data



)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_ModifyProjectionGroup =R"doc(Modify the projection data associated with a projection NamedGroup

Parameter ``origin``:
    The origin of the projection in UORS

Parameter ``size``:
    The size of the projection in UORS

Parameter ``angles``:
    The rotation applied to the projection

Parameter ``mode``:
    The projection mode to be used

Parameter ``variant``:
    Any variation to the projection data

Parameter ``group``:
    The named group representing the projection

Returns:
    SUCCESS if the projection group data was modified)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_CreateProjectionGroup =R"doc(Create a Group based projection where a single projection is applied
to a set of elements. The method will create a NamedGroup with the
supplied name and associate it with the element agenda passed in
attaching the projection data to the NamedGroup

Parameter ``origin``:
    The origin of the projection in UORS

Parameter ``size``:
    The size of the projection in UORS

Parameter ``angles``:
    The rotation applied to the projection

Parameter ``mode``:
    The projection mode to be used

Parameter ``variant``:
    Any variation to the projection data

Parameter ``agenda``:
    The elements contained in the projection

Parameter ``name``:
    The name of the projection

Parameter ``modelRef``:
    The model the projection NamedGroup is to be applied to

Returns:
    SUCCESS if the projection group was created)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_GetProjectionParametersFromMaterial =R"doc(Get the projection parameters for an element when a material based
projection is applied to the element

Parameter ``eh``:
    The element to calculate the projection data for

Parameter ``material``:
    The material to extract the projection information from

Parameter ``map``:
    The map used for the projection

Parameter ``layer``:
    The layer used for the projection

Parameter ``params``:
    The calculated projection parameters

Returns:
    SUCCESS if the projection parameters could be calculated)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_RevertMaterial =R"doc(Revert a material to its file state. This method only returns a
changed material for material palettes which require a call to
#FlushPalette in order to write the materials to file.

Parameter ``materialId``:
    The id of the material to revert

Parameter ``palette``:
    The palette containing the material

Parameter ``renderModelRef``:
    The model that this material will be rendered in. This is used to
    set up units for texture mapping.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_SaveInternalPaletteAsExternal =R"doc(Save the materials in an internal palette as an external palette. This
does not modify any materials or attachments.

Parameter ``internalPalette``:
    internal palette to copy materials out of

Parameter ``externalFileName``:
    external .pal file name to save materials into

Parameter ``renderModelRef``:
    modelref containing internal mateirals)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_ConvertInternalTableAndPalettesToExternal =R"doc(Convert an internal material table and all its palettes to an external
table using a single palette. This method will also convert all the
elements which have internal material id linkages on them to be of the
external type

Parameter ``internalTable``:
    The internal table to convert

Parameter ``externalTableName``:
    The full path to the external (.mat) table

Parameter ``paletteOutputFolder``:
    The folder where to put the generated .pal files

Parameter ``renderModelRef``:
    The model that this material will be rendered in. This is used to
    set up units for texture mapping.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_ConvertInternalTableAndPalettesToExternalWithUnifiedPaletteName =R"doc(Convert an internal material table and all its palettes to an external
table using a single palette. This method will also convert all the
elements which have internal material id linkages on them to be of the
external type

Parameter ``internalTable``:
    The internal table to convert

Parameter ``externalTableName``:
    The full path to the external (.mat) table

Parameter ``externalPalette``:
    The (.pal) palette to put the materials in

Parameter ``renderModelRef``:
    The model that this material will be rendered in. This is used to
    set up units for texture mapping.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_ConvertExternalTableAndPalettesToInternal =R"doc(Convert an external material table with external palettes to an
internal table. Returning the new table

Parameter ``externalTable``:
    The table to internalize

Parameter ``renderModelRef``:
    The model that this material will be rendered in. This is used to
    set up units for texture mapping.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_FlushPalette =R"doc(Flush the in memory contents of the palette to file.

Parameter ``palette``:
    The palette to flush

Parameter ``renderModelRef``:
    The model that this material will be rendered in. This is used to
    set up units for texture mapping.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_PalettePersistenceRequiresFlush =R"doc(For palette file io to be as efficient as possible different types of
palette may require different modes of writing the data. (.dgn) file
palette materials for example can be written very quickly and so
saving a material can be done instantly. Other palette file schemes
are not as efficient such as the text file (.pal) palette, which
requires the entire palette to be written at once. Saving an
individual material in this scheme is slow. This function returns if a
flush operation is necessary to persist the palette information to
file. If the return value is false the materials are instantly
persisted on a call to #SaveMaterial. If the return value is true the
modified materials are maintained in memory until the #FlushPalette
method is called

Parameter ``palette``:
    The palette)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_UnloadPalette =R"doc(Parameter ``palette``:
    The palette to unload

Parameter ``option``:
    Options relating to how to process the attachments and assignments

Parameter ``model``:
    The model containing the current material table)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_RenamePalette =R"doc(Rename a palette updating the materials in that palette. Returns the
new paletteInfo object for the palette

Parameter ``oldPalette``:
    The old palette name

Parameter ``newName``:
    The new paletteName.

Parameter ``model``:
    The model containing the current material table)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_CreateEmptyPalFile =R"doc(Create an empty .pal material file

Parameter ``moniker``:
    filename and path)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_GetPalettesInDgnLib =R"doc(Get the list of palettes contained within a dgn file

Parameter ``paletteList``:
    populated list of palettes

Parameter ``dgnLibFilename``:
    full path to the dgn file)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_GetPalettesInSearchPath =R"doc(Get a list of palettes in .dgnlib, .pal, .mli files found by the
supplied environment variable

Parameter ``paletteList``:
    populated list of palettes

Parameter ``envVar``:
    environment variable i.e. MS_MATERIAL)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_FindTexture =R"doc(Finds the full path for a given texture.

Parameter ``textureName``:
    The filename of the texture

Parameter ``renderDgnFile``:
    The file the texture is to be used in. The path of the dgn is also
    looked at when finding the texture)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_GetPatternSearchPath =R"doc(Returns the location to use when searching for pattern texture files.

Parameter ``renderDgnMoniker``:
    moniker for search path)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_GetMaterialSearchPath =R"doc(Returns the location to use when searching for external material
palettes and tables.

Parameter ``renderDgnMoniker``:
    moniker for search path)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_SetActiveTable =R"doc(Sets the material table as the active table for the specified model

Parameter ``table``:
    The table to make active

Parameter ``model``:
    The model to make the table active for)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_SaveTable =R"doc(Save a material table either to the dgn file or to an external .mat
file

Parameter ``table``:
    The table name to save)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_GetTableNameForId =R"doc(Get the name of the table for a give table id.

Parameter ``name``:
    The name of the table

Parameter ``sourceDgn``:
    The dgn file to look in

Parameter ``id``:
    The id of the table

Returns:
    SUCCESS if the material table with the id was found)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_DeleteTableById =R"doc(Delete a material table from its id

Parameter ``sourceDgn``:
    The dgn file to look in

Parameter ``id``:
    The id of the material table)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_DeleteTable =R"doc(Delete a material table from the dgn file

Parameter ``sourceDgn``:
    The dgn file to look in

Parameter ``name``:
    The name of the table to delete

Returns:
    SUCCESS if the table was found and deleted)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_GetTableList =R"doc(Get a list of material tables and their descriptions stored in the dgn
file specified.

Parameter ``tableNames``:
    The list of table names

Parameter ``descriptions``:
    The list of table descriptions

Parameter ``sourceDgn``:
    The dgn file to look in)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_LoadPalTable =R"doc(Load the .mat material table for a given model

Parameter ``model``:
    model to load the table for

Parameter ``source``:
    If NULL the last stored material table name will be used to load.
    If that doesnt exist then a table name based on the dgn filename
    will be used. If not NULL then the specified .mat file will be
    loaded)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_LoadActiveDgnTable =R"doc(Returns the active table stored in the dgn file for a given model

Parameter ``sourceModel``:
    The model to load the table for)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_LoadActiveTable =R"doc(Returns the active material table for a given model. While all
MaterialTables in a given file are shared between its models,
individual models may have different tables active.

Parameter ``model``:
    The model to load the table for)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_SaveMaterial =R"doc(Saves the specified material to the store specified by its palette. If
the store specified does not already exist, DgnPlatform will attempt
to create it. However, it is not guaranteed that all types of material
stores can be created or written to. Also whilst the material will be
saved to memory it may not be persisted into its file storage.

Parameter ``materialId``:
    optional. The materialId generated for the material containing the
    elementId of the material and its name.

Parameter ``material``:
    The material to be saved.

Parameter ``suggestedFile``:
    Supplying this argument improves performance if it matches the
    source of the material's palette and is not read-only. Optional.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_RenameMaterial =R"doc(Renames the specified material in the specified store. Returns ERROR
if the material isn't found or the store can't be written to.

Parameter ``existingId``:
    An identifier specifying the name and/or numeric ID of the
    material to rename. Numeric ID searches are faster and preferable
    when possible.

Parameter ``oldPaletteName``:
    The palette the material is in

Parameter ``newName``:
    The new name for the specified material.

Parameter ``newPaletteName``:
    The new palette to put the material in

Parameter ``store``:
    The location where the material is currently stored.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_DeleteMaterial =R"doc(Deletes the specified material from the specified store.

Parameter ``id``:
    The material id of the material to find

Parameter ``store``:
    The store to find the material in

Returns:
    SUCCESS if the material was found and deleted.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_FindMaterialInPalette =R"doc(Find a material by name in a specific palette

Parameter ``materialName``:
    The name of the material to find

Parameter ``palette``:
    The palette to find the material in

Parameter ``renderModelRef``:
    The model that this material will be rendered in. This is used to
    set up units for texture mapping.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_FindMaterialsInPalette =R"doc(Find a list of materials in a palette


Parameter ``materials``:
    A list populated with the materials found

Parameter ``palette``:
    The palette to find the materials in

Parameter ``renderModelRef``:
    The model that this material will be rendered in. This is used to
    set up units for texture mapping.

Parameter ``includeLibrary``:
    Also load the materials from the library if one is specified on
    the paletteInfo

Returns (Tuple, 0):
    SUCCESS if one or more materials were found

Returns (Tuple, 1):
	status. Indicates the result of a search. 

)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_FindMaterialAttachment =R"doc(Find if a material is attached to the element handle passed in. Note
should use the IMaterialProperties class for evaluating attachments as
they could be stored on sub components of a complex element

Parameter ``searchStatus``:
    Indicates the result of a search. OK to pass NULL.

Parameter ``eh``:
    The element handle to find the attachment on

Parameter ``renderModelRef``:
    The model that this material will be rendered in. This is used to
    set up units for texture mapping.

Parameter ``loadSourceIfNotCached``:
    Attempt to load this source if it hasn't already been encountered
    by the MaterialManager. The materials in the DGN file pointed to
    by renderModelRef itself are loaded automatically along with any
    materials in its associated MaterialTable. Specifying false for
    this argument improves performance.

Returns:
    The material pointer if the material is found otherwise NULL)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_FindMaterialBySymbology =R"doc(Find a material in the active material table based on its assignment
for level and color

Parameter ``searchStatus``:
    Indicates the result of a search. OK to pass NULL.

Parameter ``levelID``:
    The level id of the level the material is assigned to

Parameter ``rawColor``:
    The color of the assignment

Parameter ``renderModelRef``:
    The model that this material will be rendered in. This is used to
    set up units for texture mapping.

Parameter ``useSymbologyOverride``:
    Search for materials which are assigned to the level override

Parameter ``loadSourceIfNotCached``:
    Attempt to load this source if it hasn't already been encountered
    by the MaterialManager. The materials in the DGN file pointed to
    by renderModelRef itself are loaded automatically along with any
    materials in its associated MaterialTable. Specifying false for
    this argument improves performance.

Parameter ``context``:
    Optional if not NULL will search on the contexts list of cached
    assignments for a faster lookup)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_FindMaterialByNameFromAnySource =R"doc(Find a material or materials by its name from any material source


Parameter ``materials``:
    A list populated with the materials found

Parameter ``name``:
    The material name to find

Parameter ``renderModelRef``:
    The model that this material will be rendered in. This is used to
    set up units for texture mapping.

Parameter ``loadSourceIfNotCached``:
    Attempt to load this source if it hasn't already been encountered
    by the MaterialManager. The materials in the DGN file pointed to
    by renderModelRef itself are loaded automatically along with any
    materials in its associated MaterialTable. Specifying false for
    this argument improves performance.

Returns (Tuple, 0):
    SUCCESS if the search found one or more materials

Returns (Tuple, 1):
	status. Indicates the result of a search.

)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialManager_FindMaterial =R"doc(Find a material definition from the specified source. These results
are cached after an initial search. The pointer returned is only valid
as long as renderModelRef's DGN file is still loaded.

Parameter ``searchStatus``:
    Indicates the result of a search. OK to pass NULL.

Parameter ``id``:
    An identifier specifying the name and/or numeric ID of the
    material to be searched for. Numeric ID searches are faster and
    preferable when possible.

Parameter ``source``:
    The document to search for the material in. If the document is an
    already loaded DGN file, passing that DGN instead of its moniker
    is faster.

Parameter ``renderModelRef``:
    The model that this material will be rendered in. This is used to
    set up units for texture mapping.

Parameter ``loadSourceIfNotCached``:
    Attempt to load this source if it hasn't already been encountered
    by the MaterialManager. The materials in the DGN file pointed to
    by renderModelRef itself are loaded automatically along with any
    materials in its associated MaterialTable. Specifying false for
    this argument improves performance.

Returns:
    The material if found.)doc";

static const char * __doc_Bentley_DgnPlatform_TextureFunctionInfo_SetMaxImageSize =R"doc(Set the maximum size of the texture to be returned by in the results
structure

Parameter ``size``:
    The maximum size of the texture to return in the results structure)doc";

static const char * __doc_Bentley_DgnPlatform_TextureFunctionInfo_GetMaxImageSize =R"doc(Get the maximum size of the texture to be returned by in the results
structure)doc";

static const char * __doc_Bentley_DgnPlatform_TextureFunctionInfo_SetElementRange =R"doc(Set the range of the eleement that the texture is applied to

Parameter ``range``:
    The range of the element the texture is applied to)doc";

static const char * __doc_Bentley_DgnPlatform_TextureFunctionInfo_GetElementRange =R"doc(Get the range of the element that the texture is applied to)doc";

static const char * __doc_Bentley_DgnPlatform_TextureFunctionInfo_SetMaterialMapLayer =R"doc(Set the material layer for which the texture handler is evaluated for

Parameter ``layer``:
    The material map layer)doc";

static const char * __doc_Bentley_DgnPlatform_TextureFunctionInfo_GetMaterialMapLayer =R"doc(Get the material layer of the texture handler for evaluation)doc";

static const char * __doc_Bentley_DgnPlatform_TextureFunctionInfo_SetMaterialMap =R"doc(Set the material map which contains the texture

Parameter ``map``:
    The material map which contains the texture)doc";

static const char * __doc_Bentley_DgnPlatform_TextureFunctionInfo_GetMaterialMap =R"doc(Get the material map that contains the texture for evaluation)doc";

static const char * __doc_Bentley_DgnPlatform_TextureFunctionInfo_SetMaterial =R"doc(Set the material that the texture is to be evaluated for

Parameter ``material``:
    The material that contains the texture)doc";

static const char * __doc_Bentley_DgnPlatform_TextureFunctionInfo_SetModelRef =R"doc(Set the modelref of the model being processed

Parameter ``modelRef``:
    The modelref being processed)doc";

static const char * __doc_Bentley_DgnPlatform_TextureFunctionInfo_GetModelRef =R"doc(Get the modelref of the model being processed)doc";

static const char * __doc_Bentley_DgnPlatform_TextureFunctionInfo_SetWantModifiedMaterialLayer =R"doc(Sets if the texture function has a material layer available to modify

Parameter ``modifiedMaterialLayer``:
    True if the texture handler has a material layer it can modify)doc";

static const char * __doc_Bentley_DgnPlatform_TextureFunctionInfo_WantModifiedMaterialLayer =R"doc(Gets if the texture function has a material layer available to modify)doc";

static const char * __doc_Bentley_DgnPlatform_TextureFunctionInfo_SetReturnImage =R"doc(Sets if the texture function is to return an image for use as the
texture

Parameter ``returnImage``:
    True if the texture function is to return an image)doc";

static const char * __doc_Bentley_DgnPlatform_TextureFunctionInfo_ReturnImage =R"doc(Is the texture function returning an image for use as the texture)doc";

static const char * __doc_Bentley_DgnPlatform_TextureFunctionInfo_GetViewNumber =R"doc(Get the view number from the viewport)doc";

static const char * __doc_Bentley_DgnPlatform_TextureFunctionResults_SetModifiableLayer =R"doc(set the material layer that the texture evaluation method can modify

Parameter ``layer``:
    The layer to modify.)doc";

static const char * __doc_Bentley_DgnPlatform_TextureFunctionResults_GetModifiableLayer =R"doc(The texture handler may want to modify the material layer associated
with the texture its generating This method allows the layer to be
modifed.)doc";

static const char * __doc_Bentley_DgnPlatform_TextureFunctionResults_SetTextureRange =R"doc(Set the range of the image

Parameter ``range``:
    The range of the texture image)doc";

static const char * __doc_Bentley_DgnPlatform_TextureFunctionResults_GetTextureRange =R"doc(Get the range of the image)doc";

static const char * __doc_Bentley_DgnPlatform_TextureFunctionResults_SetImage =R"doc(Set the image to use for the texture

Parameter ``image``:
    The image to use for the texture)doc";

static const char * __doc_Bentley_DgnPlatform_TextureFunctionResults_GetImage =R"doc(Get the image to use for the texture)doc";

static const char * __doc_Bentley_DgnPlatform_TextureImage_Create =R"doc(Create an instance of this object and allocate an image buffer of the
appropriate size. If image is not NULL, will copy the image passed in
into this allocated buffer.

Parameter ``image``:
    NULL or the image to be returned

Parameter ``imageSize``:
    the size of the image in pixels

Parameter ``hasAlpha``:
    the image is an RGBARGBA buffer or an RGBRGB buffer)doc";

static const char * __doc_Bentley_DgnPlatform_TextureImage_HasAlpha =R"doc(Returns if the image has an alpha value)doc";

static const char * __doc_Bentley_DgnPlatform_TextureImage_GetImageSize =R"doc(Get the image size associated with this object)doc";

static const char * __doc_Bentley_DgnPlatform_TextureImage_GetImage =R"doc(Get the image associated with this object)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialTable_GetPaletteList =R"doc(Get a list of all the palettes used by this material table.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialTable_AddPalette =R"doc(Add a material palette for use by this material table.

Parameter ``[in]``:
    palette The palette to add to this table.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialTable_DeleteAssignment =R"doc(Delete an assignment from the material table

Parameter ``[in]``:
    assignment The assignment to delete

Returns:
    SUCCESS if the assignment was found and deleted)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialTable_FindAssignmentsByMaterial =R"doc(Find all the assignments which a given material will use.

Parameter ``[in]``:
    materialId The material id of the material whos assignments to
    find

Parameter ``[in]``:
    option The search options for finding assignments

Returns:
    a list of material assignments which the material uses)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialTable_FillMaterialAssignmentList =R"doc(Fill a list of all the assignments used in this material table

Parameter ``[in]``:
    list The list to populate with assignments from this table)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialTable_FindAssignmentByMaterial =R"doc(Search for an assignment which the material id is used in based on the
options passed in

Parameter ``[in]``:
    materialId The material id for the assignment to find

Parameter ``[in]``:
    option The search options for finding the assignments

Returns:
    a pointer to a material assignment if its found or NULL)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialTable_FindAssignmentBySymbology =R"doc(Find an assignment in this table by the symbology of an element

Parameter ``[in]``:
    levelID The level id of the assignment to find

Parameter ``[in]``:
    rawColor The color of the assignment to find

Parameter ``[in]``:
    dgnFile The dgn file which the assignment is for

Returns:
    a pointer to a material assignment if its found or NULL)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialTable_AddAssignment =R"doc(Adds the specified assignment to this table.

Parameter ``[in]``:
    assignment The assignment to add to this table.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialTable_SetDescription =R"doc(Set the description of this material table

Parameter ``[in]``:
    description The description)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialTable_GetDescription =R"doc(Get a description of this material table.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialTable_SetName =R"doc(Set the name of this material table.

Parameter ``[in]``:
    name The name of the material table)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialTable_GetName =R"doc(Get the name of the material table)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialTable_SetRenderDgn =R"doc(Set the dgn file which the tables assignments and palettes will be
used for

Parameter ``[in]``:
    renderDgn The dgn file which the materials will be used for)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialTable_SetSource =R"doc(Set the source fiel for the material table

Parameter ``[in]``:
    source The moniker to the material table file)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialTable_GetSource =R"doc(Get the moniker which refers to the material table file)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialTable_Copy =R"doc(Copies all table properties (including source and associated DGN file)
from rhs to this table.

Parameter ``[in]``:
    rhs The material table to copy)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialTable_InitDefaults =R"doc(Clears all table properties except for source and associated DGN file.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialTable_Create =R"doc(Create a material table for use with the dgn file. This is typically
used for .mat material tables

Parameter ``[in]``:
    source The moniker which contains the file to use

Parameter ``[in]``:
    renderDgn The dgn file which this file is for

Returns:
    a material table pointer)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialAssignment_SetMaterialName =R"doc(Set the name of the material which this assignment will use.

Parameter ``[in]``:
    materialName The name of the material which will be used by this
    assignment)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialAssignment_SetMaterialElementId =R"doc(Set the ElementId of the materaial that this assignment will apply to

Parameter ``[in]``:
    elementID The element id of the material which will be used by
    this assignment)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialAssignment_GetColorMask =R"doc(Get the MaterialColorMask of colors that this assignment applies to)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialAssignment_SetLevelName =R"doc(Set the level name which this assignment will use

Parameter ``[in]``:
    levelName The level name)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialAssignment_GetLevelName =R"doc(Get the level name that this assignment applies to)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialAssignment_SetMaterialId =R"doc(Set the material id that this assignment applies to

Parameter ``[in]``:
    materialID The material id to assign)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialAssignment_GetMaterialId =R"doc(Get the material id this assignment uses)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialAssignment_Copy =R"doc(Copy the contents of the assignment passed in into this assignment

Parameter ``[in]``:
    rhs The assignment to copy)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialAssignment_InitDefaults =R"doc(Initialize this assignment to its default values)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialAssignment_Create =R"doc(Create an empty material assignment)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialColorMask_ToString =R"doc(Output the colours used in this mask as a string)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialColorMask_FromString =R"doc(Set the mask to the colors based on the contents of the string

Parameter ``[in]``:
    colorRangeStr A string containing colors)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialColorMask_FillColorIndexList =R"doc(Fill a list of all the color indicies used in this mask

Parameter ``[in]``:
    colorIndexList The list to populate with colors)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialColorMask_ContainsRgbColor =R"doc(Does this mask contain the rgb color

Parameter ``[in]``:
    color The color to find

Returns:
    True if this mask contains the color.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialColorMask_ContainsColor =R"doc(Does this mask contain a reference to this color

Parameter ``[in]``:
    rawColor The color to find

Parameter ``[in]``:
    dgnFile The dgn file the color is used in for conversion

Returns:
    True if this mask contains the color.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialColorMask_ContainsAllColorIndices =R"doc(Does this color mask have all the color table indicies selected.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialColorMask_RemoveRgbColor =R"doc(Remove an rgb color from the color mask

Parameter ``[in]``:
    color The color to remove)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialColorMask_RemoveColor =R"doc(Remove a raw color from this mask

Parameter ``[in]``:
    rawColor The color to remove

Parameter ``[in]``:
    dgnFile The dgn file the color is used in for conversion)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialColorMask_AddColor =R"doc(Add a raw color to this mask

Parameter ``[in]``:
    rawColor The color to add

Parameter ``[in]``:
    dgnFile The dgn file the color is used in for conversion)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialColorMask_GetAllRgbColors =R"doc(Get all the Rgb Colors in this mask

Parameter ``[in]``:
    colorDefs Set whos contents to populate with the colors used)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialColorMask_RemoveColorMask =R"doc(Remove the entries in the passed in color mask from this one

Parameter ``[in]``:
    rhs The mask to remove the entries from)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialColorMask_AddRgbColor =R"doc(Add an rgb color to this mask

Parameter ``[in]``:
    color The color to add to the mask)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialColorMask_AddColorMask =R"doc(Add the usages from the mask passed in to this color mask

Parameter ``[in]``:
    rhs The mask to add its colors to this mask)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialColorMask_AddAllColorIndices =R"doc(Set all the color table entries to be used for this mask)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialColorMask_IsEmpty =R"doc(Does this mask refer to any colors. True if the mask is empty)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialColorMask_Copy =R"doc(Copy the contents of the MaterialColorMask passed in into this object

Parameter ``[in]``:
    rhs The MaterialColorMask to copy)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialId_SetElementId =R"doc(Set the element id of this material id.

Parameter ``[in]``:
    elementId The element id to set for this material id)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialId_GetElementId =R"doc(Get the element id associated with this material id)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialId_SetName =R"doc(Set the name associated with this material id

Parameter ``[in]``:
    name The name to set this material id to)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialId_GetName =R"doc(Get the name associated with this material id)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialId_DeSerialize =R"doc(Deserialize the string into this material id's members. If it is
required that a material id is persisted in a dgn file then this
method should be used to create a MaterialId from the persisted data

Parameter ``[in]``:
    str The serialized material id

Returns:
    SUCCESS if the string contained a valid material id)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialId_Serialize =R"doc(Serialize the contents of this material id into a string. If it is
required that a material id is persisted in a dgn file then the string
returned by this method is what should be stored.

Parameter ``[in,``:
    out] str The serialized material id

Returns:
    SUCCESS if the id could be serialized)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialId_IsNameOrIdValid =R"doc(Is either the name or the id of this id valid

Returns:
    True if the name or the id are valid)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialId_IsValid =R"doc(Is this a valid material id

Returns:
    True if the name and id are valid)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialId_Copy =R"doc(Copy the passed in material id contents into this object

Parameter ``[in]``:
    rhs The material to copy)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialId_InitDefaults =R"doc(Set a material id to its default values, no name and invalid element
id)doc";

static const char * __doc_Bentley_DgnPlatform_Material_GetPreviews =R"doc(Get the collection of previews associated with this material)doc";

static const char * __doc_Bentley_DgnPlatform_Material_GetSettings =R"doc(Get the material settings for this material)doc";

static const char * __doc_Bentley_DgnPlatform_Material_SetModelRef =R"doc(Set the modelRef that this material is to be used in

Parameter ``[in]``:
    modelRef The modelref the material is used in)doc";

static const char * __doc_Bentley_DgnPlatform_Material_GetPalette =R"doc(Get the Palette this material is located in)doc";

static const char * __doc_Bentley_DgnPlatform_Material_SetName =R"doc(Set the name of this material. The maximum length for a material name
is 30 characters - if the provided name exceeds that length, this
function will return ERROR and the name will not be changed.

Parameter ``[in]``:
    name The name to set the material to.

Returns:
    SUCCESS if the name was set.)doc";

static const char * __doc_Bentley_DgnPlatform_Material_Equals =R"doc(Return if this material is equal to the material passed to this
method.

Parameter ``[in]``:
    rhs The material to compare to

Parameter ``[in]``:
    testModelRef True to also compare the modelref. If false the
    modelref wont be compared but all the other parameters will be

Returns:
    True if the materials are equal)doc";

static const char * __doc_Bentley_DgnPlatform_Material_Copy =R"doc(Copy the contents of the passed in material into this material

Parameter ``[in]``:
    copyFrom Material to copy from)doc";

static const char * __doc_Bentley_DgnPlatform_Material_InitDefaults =R"doc(Initialize the material to a set of default values.

Parameter ``[in]``:
    modelRef The modelref which the material will be used in)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialPreviewCollection_AddPreview =R"doc(Add a preview to this collection. If a preview of this type already
exists in the collection it will be replaced.

Parameter ``[in]``:
    type The preview type to add to the collection.

Returns:
    A reference to the added preview)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialPreviewCollection_ClearAll =R"doc(Delete all the members from this collection)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialPreviewCollection_Copy =R"doc(Clear the contents of this collection and copy the contents of the
passed in collection into this one

Parameter ``[in]``:
    rhs The collection to copy)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialPreviewCollection_InitDefaults =R"doc(Initialize this collection to its defaults.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialPreview_SetRenderMode =R"doc(Set the render mode used for this preview

Parameter ``[in]``:
    renderMode The render mode)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialPreview_GetRenderMode =R"doc(Get the render mode used for this preview.

Returns:
    The render mode used for this preview.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialPreview_SetBrightness =R"doc(Set the brightness multiplier for this widget preview.

Parameter ``[in]``:
    brightness The brightness multiplier used for this preview.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialPreview_GetBrightness =R"doc(Get the brightness multiplier used for the tonemapping for this
preview.

Returns:
    the brightness multiplier used for this preview.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialPreview_SetExampleSize =R"doc(Set the size in UORS of this example widget

Parameter ``[in]``:
    size The size in uors of the example widget.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialPreview_GetExampleSize =R"doc(Get the size in UORS of the the example widget. A widget can be
created with a specific size so the repeat of the textures across its
surface can be precisely determined.

Returns:
    the example size.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialPreview_SetSize =R"doc(Set the size of the preview image

Parameter ``[in]``:
    x The number of pixels in x

Parameter ``[in]``:
    y The number of pixels in y)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialPreview_GetSize =R"doc(Get the size of the preview image

Returns:
    the preview image size)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialPreview_SetType =R"doc(Set the preview type for this MaterialPreview

Parameter ``[in]``:
    exampleType The example type that the material preview was
    rendered with.

Parameter ``[in]``:
    previewMode The preview mode.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialPreview_GetType =R"doc(Get the PreviewType of this MaterialPreview object

Returns:
    The preview type of this object)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialPreview_ClearImage =R"doc(Clear the preview image)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialPreview_Equals =R"doc(Compare this object to the MaterialPreview passed in based on the
flags passed in

Parameter ``[in]``:
    rhs The MaterialPreview to compare.

Parameter ``[in]``:
    anyBrightness The comparison ignores the brightness value.

Parameter ``[in]``:
    anyExample The comparison ignores the example.

Parameter ``[in]``:
    anyRenderMode The comparison ignores the render mode

Returns:
    True if the MaterialPreview's are equal)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialPreview_Copy =R"doc(Copy the contents of the the passed in MaterialPreview into this
object.

Parameter ``[in]``:
    rhs The MaterialPreview to copy from)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialPreview_InitDefaults =R"doc(Initialize this object to default values for its members)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_Material(py::module_& m)
    {
    //===================================================================================
    // enum class MaterialOpenMode
    py::enum_< MaterialOpenMode>(m, "MaterialOpenMode")
        .value("eReadOnly", MaterialOpenMode::ReadOnly)
        .value("ePreferablyReadWrite", MaterialOpenMode::PreferablyReadWrite)
        .value("eReadWrite", MaterialOpenMode::ReadWrite)
        .export_values();

    //===================================================================================
    // enum class MaterialSearchStatus
    py::enum_< MaterialSearchStatus>(m, "MaterialSearchStatus")
        .value("eSuccess", MaterialSearchStatus::Success)
        .value("eInvalidId", MaterialSearchStatus::InvalidId)
        .value("eInvalidModelRef", MaterialSearchStatus::InvalidModelRef)
        .value("eNotFound", MaterialSearchStatus::NotFound)
        .value("eCouldNotLoadSource", MaterialSearchStatus::CouldNotLoadSource)
        .value("eInvalidLevelId", MaterialSearchStatus::InvalidLevelId)
        .export_values();

    //===================================================================================
    // enum class PaletteUnloadOption
    py::enum_< PaletteUnloadOption>(m, "PaletteUnloadOption")
        .value("eRemoveAssignmentsAndAttachments", PaletteUnloadOption::RemoveAssignmentsAndAttachments)
        .value("eConvertToExternalAssignmentsAndAttachments", PaletteUnloadOption::ConvertToExternalAssignmentsAndAttachments)
        .export_values();

    //===================================================================================
    // enum class MaterialAnnouncerPriority
    py::enum_< MaterialAnnouncerPriority>(m, "MaterialAnnouncerPriority")
        .value("eFirst", MaterialAnnouncerPriority::First)
        .value("eDCDrape", MaterialAnnouncerPriority::DCDrape)
        .value("eRasterDrape", MaterialAnnouncerPriority::RasterDrape)
        .value("eGeoDTM", MaterialAnnouncerPriority::GeoDTM)
        .value("eDynamicTextureManipulation", MaterialAnnouncerPriority::DynamicTextureManipulation)
        .value("eAnimation", MaterialAnnouncerPriority::Animation)
        .export_values();

    //===================================================================================
    // enum class MaterialAnnouncerPurpose
    py::enum_< MaterialAnnouncerPurpose>(m, "MaterialAnnouncerPurpose")
        .value("eViewUpdate", MaterialAnnouncerPurpose::ViewUpdate)
        .value("eModelFacetExport", MaterialAnnouncerPurpose::ModelFacetExport)
        .value("eVueRender", MaterialAnnouncerPurpose::VueRender)
        .export_values();

    //===================================================================================
    // enum class CustomUndoListenerPurpose
    py::enum_< CustomUndoListenerPurpose>(m, "CustomUndoListenerPurpose")
        .value("ePaletteUnload", CustomUndoListenerPurpose::PaletteUnload)
        .value("eConvertInternalToExternal", CustomUndoListenerPurpose::ConvertInternalToExternal)
        .export_values();

    //===================================================================================
    // struct MaterialPreview
    py::class_< MaterialPreview, MaterialPreviewPtr> c1(m, "MaterialPreview", py::multiple_inheritance());

    if (true)
        {
        //===================================================================================
        // enum ExampleType
        py::enum_< MaterialPreview::ExampleType>(c1, "ExampleType", py::arithmetic())
            .value("eEXAMPLE_None", MaterialPreview::EXAMPLE_None)
            .value("eEXAMPLE_UserDefined", MaterialPreview::EXAMPLE_UserDefined)
            .value("eEXAMPLE_PaletteSpecific", MaterialPreview::EXAMPLE_PaletteSpecific)
            .value("eEXAMPLE_Widget", MaterialPreview::EXAMPLE_Widget)
            .export_values();

        //===================================================================================
        // enum PreviewMode
        py::enum_< MaterialPreview::PreviewMode>(c1, "PreviewMode", py::arithmetic())
            .value("ePREVIEWMODE_Luxology", MaterialPreview::PREVIEWMODE_Luxology)
            .value("ePREVIEWMODE_QuickVision", MaterialPreview::PREVIEWMODE_QuickVision)
            .value("ePREVIEWMODE_Vue", MaterialPreview::PREVIEWMODE_Vue)
            .export_values();

        //===================================================================================
        // enum PreviewRenderMode
        py::enum_< MaterialPreview::PreviewRenderMode>(c1, "PreviewRenderMode", py::arithmetic())
            .value("eRENDERMODE_VisibleEdges", MaterialPreview::RENDERMODE_VisibleEdges)
            .value("eRENDERMODE_FilledVisibleEdges", MaterialPreview::RENDERMODE_FilledVisibleEdges)
            .value("eRENDERMODE_Shaded", MaterialPreview::RENDERMODE_Shaded)
            .value("eRENDERMODE_Luxology", MaterialPreview::RENDERMODE_Luxology)
            .value("eRENDERMODE_Vue", MaterialPreview::RENDERMODE_Vue)
            .value("eRENDERMODE_VuePathTrace", MaterialPreview::RENDERMODE_VuePathTrace)
            .value("eRENDERMODE_VueWithEdges", MaterialPreview::RENDERMODE_VueWithEdges)
            .value("eRENDERMODE_LuxologyWithEdges", MaterialPreview::RENDERMODE_LuxologyWithEdges)
            .export_values();

        //===================================================================================
        // struct PreviewType
        py::class_< MaterialPreview::PreviewType> c1_1(c1, "PreviewType");

        c1_1.def(py::init<>());
        c1_1.def(py::init<UInt16, MaterialPreview::PreviewMode>(), "exampleType"_a, "previewMode"_a);
        c1_1.def_readwrite("exampleType", &MaterialPreview::PreviewType::m_exampleType);
        c1_1.def_readwrite("previewMode", &MaterialPreview::PreviewType::m_previewMode);

        }

    c1.def("InitDefaults", &MaterialPreview::InitDefaults, DOC(Bentley, DgnPlatform, MaterialPreview, InitDefaults));
    c1.def("Copy", &MaterialPreview::Copy, "rhs"_a, DOC(Bentley, DgnPlatform, MaterialPreview, Copy));
    c1.def("Equals", &MaterialPreview::Equals, "rhs"_a, "anyBridgeness"_a = false, "anyExample"_a = false, "anyRenderMode"_a = false, DOC(Bentley, DgnPlatform, MaterialPreview, Equals));

    c1.def("GetImage", [] (MaterialPreview const& self)
           {
           py::bytes data;
           if (self.GetImageBufferSize() > 0 && nullptr != self.GetImage())
               data = py::bytes((const char*) self.GetImage(), self.GetImageBufferSize());
           return data;
           });

    c1.def("SetImage", [] (MaterialPreview& self, py::bytes const& data)
           {
           std::string strData = (std::string) data;
           self.SetImage((const byte*) strData.data(), strData.size());
           }, "data"_a);

    c1.def("GetImageAsRGB", [] (MaterialPreview const& self, py::bytearray& data, Point2dCR size)
           {
           BentleyStatus retVal = ERROR;
           size_t dataSize = size.x * size.y * 3;
           if (dataSize > 0)
               {
               byte* outData = (byte*) _alloca(dataSize);
               retVal = self.GetImageAsRGB(outData, size);
               if (retVal == SUCCESS)
                   data = py::bytearray((const char*) outData, dataSize);
               }
           return retVal;
           }, "data"_a, "size"_a);

    c1.def("SetImageFromRGB", [] (MaterialPreview& self, py::bytes const& data, Point2dCR size)
           {
           BentleyStatus retVal = ERROR;
           size_t dataSize = size.x * size.y * 3;
           std::string strData = (std::string) data;
           if (dataSize == strData.size())
               retVal = self.SetImageFromRGB((const byte*) strData.data(), size);

           return retVal;
           }, "data"_a, "size"_a);

    c1.def("ClearImage", &MaterialPreview::ClearImage, DOC(Bentley, DgnPlatform, MaterialPreview, ClearImage));
    
    c1.def_property_readonly("Type", &MaterialPreview::GetType);
    c1.def("GetType", &MaterialPreview::GetType, DOC(Bentley, DgnPlatform, MaterialPreview, GetType));

    c1.def("SetType", &MaterialPreview::SetType, "exampleType"_a, "previewMode"_a, DOC(Bentley, DgnPlatform, MaterialPreview, SetType));
    
    c1.def_property_readonly("Size", &MaterialPreview::GetSize);
    c1.def("GetSize", &MaterialPreview::GetSize, DOC(Bentley, DgnPlatform, MaterialPreview, GetSize));

    c1.def("SetSize", &MaterialPreview::SetSize, "x"_a, "y"_a, DOC(Bentley, DgnPlatform, MaterialPreview, SetSize));

    c1.def_property("ExampleSize", &MaterialPreview::GetExampleSize, &MaterialPreview::SetExampleSize);
    c1.def("GetExampleSize", &MaterialPreview::GetExampleSize, DOC(Bentley, DgnPlatform, MaterialPreview, GetExampleSize));
    c1.def("SetExampleSize", &MaterialPreview::SetExampleSize, "size"_a, DOC(Bentley, DgnPlatform, MaterialPreview, SetExampleSize));

    c1.def_property("Brightness", &MaterialPreview::GetBrightness, &MaterialPreview::SetBrightness);
    c1.def("GetBrightness", &MaterialPreview::GetBrightness, DOC(Bentley, DgnPlatform, MaterialPreview, GetBrightness));
    c1.def("SetBrightness", &MaterialPreview::SetBrightness, "newVal"_a, DOC(Bentley, DgnPlatform, MaterialPreview, SetBrightness));
    
    c1.def_property("RenderMode", &MaterialPreview::GetRenderMode, &MaterialPreview::SetRenderMode);
    c1.def("GetRenderMode", &MaterialPreview::GetRenderMode, DOC(Bentley, DgnPlatform, MaterialPreview, GetRenderMode));
    c1.def("SetRenderMode", &MaterialPreview::SetRenderMode, "mode"_a, DOC(Bentley, DgnPlatform, MaterialPreview, SetRenderMode));

    //===================================================================================
    // struct MaterialPreviewCollection
    py::class_< MaterialPreviewCollection> c2(m, "MaterialPreviewCollection");
    
    c2.def("InitDefaults", &MaterialPreviewCollection::InitDefaults, DOC(Bentley, DgnPlatform, MaterialPreviewCollection, InitDefaults));
    c2.def("Copy", &MaterialPreviewCollection::Copy, "rhs"_a, DOC(Bentley, DgnPlatform, MaterialPreviewCollection, Copy));
    c2.def("__eq__", [] (MaterialPreviewCollection const& self, MaterialPreviewCollection const& other) { return self.Equals(other); });
    c2.def("__iter__", [] (MaterialPreviewCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());
    c2.def("__len__", &MaterialPreviewCollection::Size);
    c2.def("ClearAll", &MaterialPreviewCollection::ClearAll, DOC(Bentley, DgnPlatform, MaterialPreviewCollection, ClearAll));
    c2.def("AddPreview", &MaterialPreviewCollection::AddPreview, "type"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialPreviewCollection, AddPreview));
    c2.def("DeletePreviewAt", [] (MaterialPreviewCollection& self, size_t index)
           {
           if (index >= self.Size())
               throw py::index_error();

           auto it = static_cast<MaterialPreviewCollection const&>(self).begin();
           std::advance(it, index);
           return self.DeletePreview(it);
           }, "index"_a);
    c2.def("GetPreview", &MaterialPreviewCollection::GetPreviewP, "type"_a, py::return_value_policy::reference_internal);


    //===================================================================================
    // struct Material
    py::class_< Material, MaterialPtr> c5(m, "DgnMaterial", py::multiple_inheritance());
    py::bind_vector< MaterialList >(m, "MaterialList", py::module_local(false));

    c5.def(py::init(py::overload_cast<DgnModelRefR>(&Material::Create)), "modelRef"_a);
    c5.def(py::init(py::overload_cast<MaterialCR, DgnModelRefR>(&Material::Create)), "initFrom"_a, "modelRef"_a);
    c5.def("InitDefaults", &Material::InitDefaults, "modelRef"_a, DOC(Bentley, DgnPlatform, Material, InitDefaults));
    c5.def("Copy", &Material::Copy, "copyFrom"_a, DOC(Bentley, DgnPlatform, Material, Copy));
    c5.def("Equals", &Material::Equals, "rhs"_a, "testModelRef"_a, DOC(Bentley, DgnPlatform, Material, Equals));
    c5.def("GetName", [] (Material const& self) { return self.GetName(nullptr); }, py::return_value_policy::reference_internal);
    c5.def("SetName", &Material::SetName, "name"_a, DOC(Bentley, DgnPlatform, Material, SetName));
    
    c5.def_property_readonly("Palette", &Material::GetPaletteR);    
    c5.def("GetPalette", &Material::GetPaletteR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, Material, GetPalette));
    
    c5.def_property("ModelRef", &Material::GetModelRefR, &Material::SetModelRef);
    c5.def("GetModelRef", &Material::GetModelRefR, py::return_value_policy::reference_internal);
    c5.def("SetModelRef", &Material::SetModelRef, "modelRef"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, Material, SetModelRef));
    
    c5.def_property_readonly("Settings", &Material::GetSettingsR, py::return_value_policy::reference_internal);
    c5.def("GetSettings", &Material::GetSettingsR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, Material, GetSettings));
    
    c5.def_property_readonly("PBRSettings", &Material::GetPBRSettingsR);
    c5.def("GetPBRSettings", &Material::GetPBRSettingsR, py::return_value_policy::reference_internal);
    
    c5.def_property_readonly("Previews", &Material::GetPreviewsR);
    c5.def("GetPreviews", &Material::GetPreviewsR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, Material, GetPreviews));

    //===================================================================================
    // struct MaterialId
    py::class_< MaterialId> c6(m, "MaterialId");

    c6.def(py::init<>());
    c6.def(py::init<ElementId>(), "elementId"_a);
    c6.def(py::init<WCharCP>(), "name"_a);
    c6.def(py::init<ElementId, WCharCP>(), "elementId"_a, "name"_a);
    c6.def("InitDefaults", &MaterialId::InitDefaults, DOC(Bentley, DgnPlatform, MaterialId, InitDefaults));
    c6.def("Copy", &MaterialId::Copy, "copyFrom"_a, DOC(Bentley, DgnPlatform, MaterialId, Copy));
    c6.def("IsValid", &MaterialId::IsValid, DOC(Bentley, DgnPlatform, MaterialId, IsValid));
    c6.def("IsNameOrIdValid", &MaterialId::IsNameOrIdValid, DOC(Bentley, DgnPlatform, MaterialId, IsNameOrIdValid));
    c6.def("Serialize", &MaterialId::Serialize, "str"_a, DOC(Bentley, DgnPlatform, MaterialId, Serialize));
    c6.def("DeSerialize", &MaterialId::DeSerialize, "str"_a, DOC(Bentley, DgnPlatform, MaterialId, DeSerialize));
    
    c6.def_property("Name", &MaterialId::GetName, &MaterialId::SetName);
    c6.def("GetName", &MaterialId::GetName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialId, GetName));
    c6.def("SetName", &MaterialId::SetName, "name"_a, DOC(Bentley, DgnPlatform, MaterialId, SetName));
    
    c6.def_property("ElementId", &MaterialId::GetElementId, &MaterialId::SetElementId);
    c6.def("GetElementId", &MaterialId::GetElementId, DOC(Bentley, DgnPlatform, MaterialId, GetElementId));
    c6.def("SetElementId", &MaterialId::SetElementId, "elemId"_a, DOC(Bentley, DgnPlatform, MaterialId, SetElementId));
    
    c6.def(py::self == py::self);
    c6.def("Equals", &MaterialId::Equals);

    //===================================================================================
    // struct IMaterialStore
    py::class_< IMaterialStore, IMaterialStorePtr> c7(m, "IMaterialStore", py::multiple_inheritance());


    //===================================================================================
    // struct IMaterialProvider
    py::class_< IMaterialProvider, std::unique_ptr<IMaterialProvider, py::nodelete> > c8(m, "IMaterialProvider");


    //===================================================================================
    // struct MaterialColorMask
    py::class_< MaterialColorMask> c9(m, "MaterialColorMask");
    
    c9.def("InitDefaults", &MaterialColorMask::InitDefaults);
    c9.def("Copy", &MaterialColorMask::Copy, "copyFrom"_a, DOC(Bentley, DgnPlatform, MaterialColorMask, Copy));
    c9.def("__eq__", [] (MaterialColorMask const& self, MaterialColorMask const& other) { return self.Equals(other); });
    c9.def("IsEmpty", &MaterialColorMask::IsEmpty, DOC(Bentley, DgnPlatform, MaterialColorMask, IsEmpty));

    c9.def("AddAllColorIndices", &MaterialColorMask::AddAllColorIndices, DOC(Bentley, DgnPlatform, MaterialColorMask, AddAllColorIndices));
    c9.def("AddColorMask", &MaterialColorMask::AddColorMask, "rhs"_a, DOC(Bentley, DgnPlatform, MaterialColorMask, AddColorMask));
    c9.def("AddRgbColor", &MaterialColorMask::AddRgbColor, "color"_a, DOC(Bentley, DgnPlatform, MaterialColorMask, AddRgbColor));
    c9.def("RemoveColorMask", &MaterialColorMask::RemoveColorMask, "rhs"_a, DOC(Bentley, DgnPlatform, MaterialColorMask, RemoveColorMask));
    c9.def("GetAllRgbColors", &MaterialColorMask::GetAllRgbColors, "colorDefs"_a, DOC(Bentley, DgnPlatform, MaterialColorMask, GetAllRgbColors));
    c9.def("AddColor", &MaterialColorMask::AddColor, "rawColor"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, MaterialColorMask, AddColor));
    c9.def("RemoveColor", &MaterialColorMask::RemoveColor, "rawColor"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, MaterialColorMask, RemoveColor));
    c9.def("RemoveRgbColor", &MaterialColorMask::RemoveRgbColor, "color"_a, DOC(Bentley, DgnPlatform, MaterialColorMask, RemoveRgbColor));
    c9.def("ContainsAllColorIndices", &MaterialColorMask::ContainsAllColorIndices, DOC(Bentley, DgnPlatform, MaterialColorMask, ContainsAllColorIndices));
    c9.def("ContainsColor", &MaterialColorMask::ContainsColor, "rawColor"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, MaterialColorMask, ContainsColor));
    c9.def("ContainsRgbColor", &MaterialColorMask::ContainsRgbColor, "color"_a, DOC(Bentley, DgnPlatform, MaterialColorMask, ContainsRgbColor));
    c9.def("FillColorIndexList", &MaterialColorMask::FillColorIndexList, "colorIndexList"_a, DOC(Bentley, DgnPlatform, MaterialColorMask, FillColorIndexList));
    c9.def("FromString", &MaterialColorMask::FromString, "colorRangeStr"_a, DOC(Bentley, DgnPlatform, MaterialColorMask, FromString));
    c9.def("ToString", &MaterialColorMask::ToString, DOC(Bentley, DgnPlatform, MaterialColorMask, ToString));

    //===================================================================================
    // struct MaterialAssignment
    py::class_< MaterialAssignment, MaterialAssignmentPtr> c10(m, "MaterialAssignment", py::multiple_inheritance());

    c10.def_static("Create", py::overload_cast<>(&MaterialAssignment::Create), DOC(Bentley, DgnPlatform, MaterialAssignment, Create));
    c10.def_static("Create", py::overload_cast<MaterialIdCR, WCharCP, UInt32, DgnFileR>(&MaterialAssignment::Create), "id"_a, "levelName"_a, "rawColor"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, MaterialAssignment, Create));
    c10.def_static("Create", py::overload_cast<MaterialIdCR, WCharCP, UInt32, UInt32, DgnFileR>(&MaterialAssignment::Create), "id"_a, "levelName"_a, "colorIndexStart"_a, "colorIndexEnd"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, MaterialAssignment, Create));
    c10.def("InitDefaults", &MaterialAssignment::InitDefaults, DOC(Bentley, DgnPlatform, MaterialAssignment, InitDefaults));
    c10.def("Copy", &MaterialAssignment::Copy, "copyFrom"_a, DOC(Bentley, DgnPlatform, MaterialAssignment, Copy));
    c10.def("__eq__", [] (MaterialAssignment const& self, MaterialAssignment const& other) { return self.Equals(other); });
    
    c10.def_property("MaterialId", &MaterialAssignment::GetMaterialId, &MaterialAssignment::SetMaterialId);    
    c10.def("GetMaterialId", &MaterialAssignment::GetMaterialId, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialAssignment, GetMaterialId));
    c10.def("SetMaterialId", &MaterialAssignment::SetMaterialId, "matId"_a, DOC(Bentley, DgnPlatform, MaterialAssignment, SetMaterialId));    
    
    c10.def_property("LevelName", &MaterialAssignment::GetLevelName, &MaterialAssignment::SetLevelName);    
    c10.def("GetLevelName", &MaterialAssignment::GetLevelName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialAssignment, GetLevelName));
    c10.def("SetLevelName", &MaterialAssignment::SetLevelName, "levelName"_a, DOC(Bentley, DgnPlatform, MaterialAssignment, SetLevelName));    
    
    c10.def_property_readonly("ColorMask", &MaterialAssignment::GetColorMaskR);
    c10.def("GetColorMask", &MaterialAssignment::GetColorMaskR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialAssignment, GetColorMask));
    
    c10.def("SetMaterialElementId", &MaterialAssignment::SetMaterialElementId, "elemId"_a, DOC(Bentley, DgnPlatform, MaterialAssignment, SetMaterialElementId));
    c10.def("SetMaterialName", &MaterialAssignment::SetMaterialName, "materialName"_a, DOC(Bentley, DgnPlatform, MaterialAssignment, SetMaterialName));

    //===================================================================================
    // struct MaterialTable
    py::class_< MaterialTable, MaterialTablePtr> c11(m, "MaterialTable", py::multiple_inheritance());

    if (true)
        {
        //===================================================================================
        // enum AssignmentFindOption
        py::enum_< MaterialTable::AssignmentFindOption>(c11, "AssignmentFindOption", py::arithmetic())
            .value("eASSIGNMENTFINDOPTION_FullMaterialId", MaterialTable::ASSIGNMENTFINDOPTION_FullMaterialId)
            .value("eASSIGNMENTFINDOPTION_NameOnly", MaterialTable::ASSIGNMENTFINDOPTION_NameOnly)
            .value("eASSIGNMENTFINDOPTION_ElementIdOnly", MaterialTable::ASSIGNMENTFINDOPTION_ElementIdOnly)
            .value("eASSIGNMENTFINDOPTION_NameExcludingElementId", MaterialTable::ASSIGNMENTFINDOPTION_NameExcludingElementId)
            .export_values();
        }

    c11.def_static("Create", py::overload_cast<DgnDocumentMonikerCR, DgnFileR>(&MaterialTable::Create), "source"_a, "renderDgn"_a, DOC(Bentley, DgnPlatform, MaterialTable, Create));
    c11.def_static("Create", py::overload_cast<DgnFileR>(&MaterialTable::Create), "sourceDgn"_a, DOC(Bentley, DgnPlatform, MaterialTable, Create));
    c11.def("InitDefaults", &MaterialTable::InitDefaults, DOC(Bentley, DgnPlatform, MaterialTable, InitDefaults));
    c11.def("Copy", &MaterialTable::Copy, "copyFrom"_a, DOC(Bentley, DgnPlatform, MaterialTable, Copy));
    c11.def("__eq__", [] (MaterialTable const& self, MaterialTable const& other) { return self.Equals(other); });

    c11.def_property("Source", &MaterialTable::GetSource, &MaterialTable::SetSource);
    c11.def("GetSource", &MaterialTable::GetSource, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialTable, GetSource));
    c11.def("SetSource", &MaterialTable::SetSource, "source"_a, DOC(Bentley, DgnPlatform, MaterialTable, SetSource));
    
    c11.def_property("RenderDgn", &MaterialTable::GetRenderDgnR, &MaterialTable::SetRenderDgn);
    c11.def("GetRenderDgn", &MaterialTable::GetRenderDgnR, py::return_value_policy::reference_internal);
    c11.def("SetRenderDgn", &MaterialTable::SetRenderDgn, "renderDgn"_a, DOC(Bentley, DgnPlatform, MaterialTable, SetRenderDgn));
    
    c11.def_property("Name", &MaterialTable::GetName, &MaterialTable::SetName);
    c11.def("GetName", &MaterialTable::GetName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialTable, GetName));
    c11.def("SetName", &MaterialTable::SetName, "name"_a, DOC(Bentley, DgnPlatform, MaterialTable, SetName));
    
    c11.def_property("Description", &MaterialTable::GetDescription, &MaterialTable::SetDescription);
    c11.def("GetDescription", &MaterialTable::GetDescription, DOC(Bentley, DgnPlatform, MaterialTable, GetDescription));
    c11.def("SetDescription", &MaterialTable::SetDescription, "description"_a, DOC(Bentley, DgnPlatform, MaterialTable, SetDescription));

    c11.def("AddAssignment", &MaterialTable::AddAssignment, "assignment"_a, DOC(Bentley, DgnPlatform, MaterialTable, AddAssignment));    
    c11.def("FindAssignmentBySymbology", 
            py::overload_cast<LevelId, UInt32, DgnFileR>(&MaterialTable::FindAssignmentBySymbology, py::const_), 
            "levelId"_a, "rawColor"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, MaterialTable, FindAssignmentBySymbology));

    c11.def("FindAssignmentBySymbology",
            py::overload_cast<WCharCP, UInt32, DgnFileR>(&MaterialTable::FindAssignmentBySymbology, py::const_),
            "levelName"_a, "rawColor"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, MaterialTable, FindAssignmentBySymbology));

    c11.def("FindAssignmentByMaterial", &MaterialTable::FindAssignmentByMaterial, "materialId"_a, "option"_a = MaterialTable::ASSIGNMENTFINDOPTION_FullMaterialId, DOC(Bentley, DgnPlatform, MaterialTable, FindAssignmentByMaterial));
    c11.def("FillMaterialAssignmentList", &MaterialTable::FillMaterialAssignmentList, "list"_a, DOC(Bentley, DgnPlatform, MaterialTable, FillMaterialAssignmentList));
    c11.def("FindAssignmentsByMaterial", &MaterialTable::FindAssignmentsByMaterial, "materialId"_a, "option"_a = MaterialTable::ASSIGNMENTFINDOPTION_FullMaterialId, DOC(Bentley, DgnPlatform, MaterialTable, FindAssignmentsByMaterial));
    c11.def("DeleteAssignment", &MaterialTable::DeleteAssignment, "assignment"_a, DOC(Bentley, DgnPlatform, MaterialTable, DeleteAssignment));
    c11.def("AddPalette", &MaterialTable::AddPalette, "palette"_a, DOC(Bentley, DgnPlatform, MaterialTable, AddPalette));
    c11.def("GetPaletteList", &MaterialTable::GetPaletteList, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialTable, GetPaletteList));

    //===================================================================================
    // struct TextureImage
    py::class_< TextureImage, TextureImagePtr> c14(m, "TextureImage", py::multiple_inheritance());

    c14.def_property_readonly("ImageData", [] (TextureImage const& self)
                              {
                              py::bytes data;
                              auto& imageSize = self.GetImageSize();
                              size_t dataSize = (UInt32)imageSize.x * (UInt32)imageSize.y * (self.HasAlpha() ? 4 : 3);
                              if (dataSize > 0 && nullptr != self.GetImage())
                                  data = py::bytes((const char*) self.GetImage(), dataSize);

                              return data;
                              });
    c14.def("GetImage", [] (TextureImage const& self)
            {
            py::bytes data;
            auto& imageSize = self.GetImageSize();
            size_t dataSize = (UInt32) imageSize.x * (UInt32) imageSize.y * (self.HasAlpha() ? 4 : 3);
            if (dataSize > 0 && nullptr != self.GetImage())
                data = py::bytes((const char*) self.GetImage(), dataSize);

            return data;
            }, DOC(Bentley, DgnPlatform, TextureImage, GetImage));

    c14.def_property_readonly("ImageSize", &TextureImage::GetImageSize);
    c14.def("GetImageSize", &TextureImage::GetImageSize, DOC(Bentley, DgnPlatform, TextureImage, GetImageSize));

    c14.def("HasAlpha", &TextureImage::HasAlpha, DOC(Bentley, DgnPlatform, TextureImage, HasAlpha));

    c14.def_static("Create", [] (py::bytes const& data, Point2dCR imageSize, bool hasAlpha)
                   {
                   std::string strData = data.cast<std::string>();
                   return TextureImage::Create((byte*) strData.data(), imageSize, hasAlpha);
                   }, "data"_a, "imageSize"_a, "hasAlpha"_a, DOC(Bentley, DgnPlatform, TextureImage, Create));

    //===================================================================================
    // struct TextureFunctionResults
    py::class_< TextureFunctionResults> c15(m, "TextureFunctionResults");

    c15.def(py::init<>());

    c15.def("GetImage", &TextureFunctionResults::GetImageR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, TextureFunctionResults, GetImage));

    c15.def("SetImage", [] (TextureFunctionResults& self, TextureImageP image)
            { 
            TextureImagePtr imagePtr(image);
            self.SetImage(imagePtr);
            }, "image"_a, DOC(Bentley, DgnPlatform, TextureFunctionResults, SetImage));
    
    c15.def_property("TextureRange", &TextureFunctionResults::GetTextureRange, &TextureFunctionResults::SetTextureRange);
    c15.def("GetTextureRange", &TextureFunctionResults::GetTextureRange, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, TextureFunctionResults, GetTextureRange));
    c15.def("SetTextureRange", &TextureFunctionResults::SetTextureRange, "range"_a, DOC(Bentley, DgnPlatform, TextureFunctionResults, SetTextureRange));
    
    c15.def_property("ModifiableLayer", &TextureFunctionResults::GetModifiableLayer, &TextureFunctionResults::SetModifiableLayer);
    c15.def("GetModifiableLayer", &TextureFunctionResults::GetModifiableLayer, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, TextureFunctionResults, GetModifiableLayer));
    c15.def("SetModifiableLayer", &TextureFunctionResults::SetModifiableLayer, "layer"_a, DOC(Bentley, DgnPlatform, TextureFunctionResults, SetModifiableLayer));

    //===================================================================================
    // struct TextureFunctionInfo
    py::class_< TextureFunctionInfo> c16(m, "TextureFunctionInfo");

    c16.def(py::init<>());

    c16.def_property("Viewport", &TextureFunctionInfo::GetViewportCP, &TextureFunctionInfo::SetViewportCP);
    c16.def("GetViewport", &TextureFunctionInfo::GetViewportCP, py::return_value_policy::reference_internal);
    c16.def("SetViewport", &TextureFunctionInfo::SetViewportCP, "vp"_a, py::keep_alive<1, 2>());
    
    c16.def_property_readonly("ViewNumber", &TextureFunctionInfo::GetViewNumber);
    c16.def("GetViewNumber", &TextureFunctionInfo::GetViewNumber, DOC(Bentley, DgnPlatform, TextureFunctionInfo, GetViewNumber));
    
    c16.def_property("IsReturnImage", &TextureFunctionInfo::ReturnImage, &TextureFunctionInfo::SetReturnImage);
    c16.def("ReturnImage", &TextureFunctionInfo::ReturnImage, DOC(Bentley, DgnPlatform, TextureFunctionInfo, ReturnImage));
    c16.def("SetReturnImage", &TextureFunctionInfo::SetReturnImage, "newVal"_a, DOC(Bentley, DgnPlatform, TextureFunctionInfo, SetReturnImage));
    
    c16.def_property("IsWantModifiedMaterialLayer", &TextureFunctionInfo::WantModifiedMaterialLayer, &TextureFunctionInfo::SetWantModifiedMaterialLayer);    
    c16.def("WantModifiedMaterialLayer", &TextureFunctionInfo::WantModifiedMaterialLayer, DOC(Bentley, DgnPlatform, TextureFunctionInfo, WantModifiedMaterialLayer));
    c16.def("SetWantModifiedMaterialLayer", &TextureFunctionInfo::SetWantModifiedMaterialLayer, "newVal"_a, DOC(Bentley, DgnPlatform, TextureFunctionInfo, SetWantModifiedMaterialLayer));
    
    c16.def_property("ModelRef", &TextureFunctionInfo::GetModelRef, &TextureFunctionInfo::SetModelRef);
    c16.def("GetModelRef", &TextureFunctionInfo::GetModelRef, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, TextureFunctionInfo, GetModelRef));
    c16.def("SetModelRef", &TextureFunctionInfo::SetModelRef, "modelRef"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, TextureFunctionInfo, SetModelRef));
    
    c16.def_property("Material", &TextureFunctionInfo::GetMaterial, &TextureFunctionInfo::SetMaterial);
    c16.def("GetMaterial", &TextureFunctionInfo::GetMaterial, py::return_value_policy::reference_internal);
    c16.def("SetMaterial", &TextureFunctionInfo::SetMaterial, "newVal"_a, DOC(Bentley, DgnPlatform, TextureFunctionInfo, SetMaterial));
    
    c16.def_property("MaterialMap", &TextureFunctionInfo::GetMaterialMap, &TextureFunctionInfo::SetMaterialMap);
    c16.def("GetMaterialMap", &TextureFunctionInfo::GetMaterialMap, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, TextureFunctionInfo, GetMaterialMap));
    c16.def("SetMaterialMap", &TextureFunctionInfo::SetMaterialMap, "newVal"_a, DOC(Bentley, DgnPlatform, TextureFunctionInfo, SetMaterialMap));
    
    c16.def_property("MaterialMapLayer", &TextureFunctionInfo::GetMaterialMapLayer, &TextureFunctionInfo::SetMaterialMapLayer);
    c16.def("GetMaterialMapLayer", &TextureFunctionInfo::GetMaterialMapLayer, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, TextureFunctionInfo, GetMaterialMapLayer));
    c16.def("SetMaterialMapLayer", &TextureFunctionInfo::SetMaterialMapLayer, "layer"_a, DOC(Bentley, DgnPlatform, TextureFunctionInfo, SetMaterialMapLayer));
    
    c16.def_property("ElementRange", &TextureFunctionInfo::GetElementRange, &TextureFunctionInfo::SetElementRange);
    c16.def("GetElementRange", &TextureFunctionInfo::GetElementRange, DOC(Bentley, DgnPlatform, TextureFunctionInfo, GetElementRange));
    c16.def("SetElementRange", &TextureFunctionInfo::SetElementRange, "range"_a, DOC(Bentley, DgnPlatform, TextureFunctionInfo, SetElementRange));
    
    c16.def_property("MaxImageSize", &TextureFunctionInfo::GetMaxImageSize, &TextureFunctionInfo::SetMaxImageSize);
    c16.def("GetMaxImageSize", &TextureFunctionInfo::GetMaxImageSize, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, TextureFunctionInfo, GetMaxImageSize));
    c16.def("SetMaxImageSize", &TextureFunctionInfo::SetMaxImageSize, "size"_a, DOC(Bentley, DgnPlatform, TextureFunctionInfo, SetMaxImageSize));

    //===================================================================================
    // struct MaterialManager
    py::class_< MaterialManager> c17(m, "MaterialManager");

    c17.def("FindMaterial", [] (MaterialManager& self, MaterialIdCR id, DgnDocumentMonikerCR source, DgnModelRefR renderModelRef, bool loadSourceIfNotCached)
            {
            MaterialSearchStatus status = MaterialSearchStatus::Success;
            auto pMat = const_cast<MaterialP>(self.FindMaterial(&status, id, source, renderModelRef, loadSourceIfNotCached));
            return py::make_tuple(MaterialPtr(pMat), status);
            }, "id"_a, "source"_a, "renderModelRef"_a, "loadSourceIfNotCached"_a, DOC(Bentley, DgnPlatform, MaterialManager, FindMaterial));

    c17.def("FindMaterial", [] (MaterialManager& self, MaterialIdCR id, DgnFileR source, DgnModelRefR renderModelRef, bool loadSourceIfNotCached)
            {
            MaterialSearchStatus status = MaterialSearchStatus::Success;
            auto pMat = const_cast<MaterialP>(self.FindMaterial(&status, id, source, renderModelRef, loadSourceIfNotCached));
            return py::make_tuple(MaterialPtr(pMat), status);
            }, "id"_a, "source"_a, "renderModelRef"_a, "loadSourceIfNotCached"_a, DOC(Bentley, DgnPlatform, MaterialManager, FindMaterial));

    c17.def("FindMaterialByNameFromAnySource", [] (MaterialManager& self, MaterialList& materials, WCharCP name, DgnModelRefR renderModelRef, bool loadSourceIfNotCached)
            {
            MaterialSearchStatus status = MaterialSearchStatus::Success;
            auto retVal = self.FindMaterialByNameFromAnySource(&status, materials, name, renderModelRef, loadSourceIfNotCached);
            return py::make_tuple(retVal, status);
            }, "materials"_a, "name"_a, "renderModelRef"_a, "loadSourceIfNotCached"_a, DOC(Bentley, DgnPlatform, MaterialManager, FindMaterialByNameFromAnySource));

    c17.def("FindMaterialBySymbology", [] (MaterialManager& self, LevelId levelID, UInt32 rawColor, DgnModelRefR renderModelRef, bool useSymbologyOverride, bool loadSourceIfNotCached, ViewContextP context)
            {
            MaterialSearchStatus status = MaterialSearchStatus::Success;
            auto pMat = const_cast<MaterialP>(self.FindMaterialBySymbology(&status, levelID, rawColor, renderModelRef, useSymbologyOverride, loadSourceIfNotCached, context));
            return py::make_tuple(MaterialPtr(pMat), status);
            }, "levelID"_a, "rawColor"_a, "renderModelRef"_a, "useSymbologyOverride"_a, "loadSourceIfNotCached"_a, "context"_a, DOC(Bentley, DgnPlatform, MaterialManager, FindMaterialBySymbology));

    c17.def("FindMaterialAttachment", [] (MaterialManager& self, ElementHandleCR eh, DgnModelRefR renderModelRef, bool loadSourceIfNotCached)
            {
            MaterialSearchStatus status = MaterialSearchStatus::Success;
            auto pMat = const_cast<MaterialP>(self.FindMaterialAttachment(&status, eh, renderModelRef, loadSourceIfNotCached));
            return py::make_tuple(MaterialPtr(pMat), status);
            }, "eh"_a, "renderModelRef"_a, "loadSourceIfNotCached"_a, DOC(Bentley, DgnPlatform, MaterialManager, FindMaterialAttachment));

    c17.def("FindMaterialsInPalette", [] (MaterialManager& self, MaterialList& materials, PaletteInfoCR palette, DgnModelRefR renderModelRef, bool includeLibrary)
            {
            MaterialSearchStatus status = MaterialSearchStatus::Success;
            auto retVal = self.FindMaterialsInPalette(&status, materials, palette, renderModelRef, includeLibrary);
            return py::make_tuple(retVal, status);
            }, "materials"_a, "palette"_a, "renderModelRef"_a, "includeLibrary"_a, DOC(Bentley, DgnPlatform, MaterialManager, FindMaterialsInPalette));

    c17.def("FindMaterialInPalette", 
            py::overload_cast<WCharCP, PaletteInfoCR, DgnModelRefR>(&MaterialManager::FindMaterialInPalette), 
            "materialName"_a, "palette"_a, "renderModelRef"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialManager, FindMaterialInPalette));

    c17.def("FindMaterialInPalette", 
            py::overload_cast<WCharCP, PaletteInfoCR, DgnModelRefR, bool>(&MaterialManager::FindMaterialInPalette),
            "materialName"_a, "palette"_a, "renderModelRef"_a, "includelibrary"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialManager, FindMaterialInPalette));

    c17.def("DeleteMaterial", py::overload_cast<MaterialIdCR, DgnDocumentMonikerCR>(&MaterialManager::DeleteMaterial), "id"_a, "store"_a, DOC(Bentley, DgnPlatform, MaterialManager, DeleteMaterial));
    c17.def("DeleteMaterial", py::overload_cast<MaterialIdCR, PaletteInfoCR>(&MaterialManager::DeleteMaterial), "id"_a, "palette"_a, DOC(Bentley, DgnPlatform, MaterialManager, DeleteMaterial));
    c17.def("DeleteMaterial", py::overload_cast<MaterialIdCR, DgnFileR>(&MaterialManager::DeleteMaterial), "id"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, MaterialManager, DeleteMaterial));
    
    c17.def("RenameMaterial", 
            py::overload_cast<MaterialIdCR, WCharCP, WCharCP, WCharCP, DgnDocumentMonikerCR>(&MaterialManager::RenameMaterial),
            "existingId"_a, "oldPaletteName"_a, "newName"_a, "newPaletteName"_a, "store"_a, DOC(Bentley, DgnPlatform, MaterialManager, RenameMaterial));

    c17.def("RenameMaterial",
            py::overload_cast<MaterialIdCR, WCharCP, WCharCP, WCharCP, DgnFileR>(&MaterialManager::RenameMaterial),
            "existingId"_a, "oldPaletteName"_a, "newName"_a, "newPaletteName"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, MaterialManager, RenameMaterial));

    c17.def("SaveMaterial", &MaterialManager::SaveMaterial, "materialId"_a, "material"_a, "suggestedFile"_a, DOC(Bentley, DgnPlatform, MaterialManager, SaveMaterial));
    c17.def("GetActiveTable", &MaterialManager::GetActiveTableCP, "model"_a, py::return_value_policy::reference_internal);
    c17.def("LoadActiveTable", &MaterialManager::LoadActiveTable, "model"_a, DOC(Bentley, DgnPlatform, MaterialManager, LoadActiveTable));
    c17.def("LoadActiveDgnTable", &MaterialManager::LoadActiveDgnTable, "sourceModel"_a, DOC(Bentley, DgnPlatform, MaterialManager, LoadActiveDgnTable));
    c17.def("LoadPalTable", &MaterialManager::LoadPalTable, "model"_a, "source"_a = nullptr, DOC(Bentley, DgnPlatform, MaterialManager, LoadPalTable));
    c17.def("GetTableList", &MaterialManager::GetTableList, "tableNames"_a, "descriptions"_a, "sourceDgn"_a, DOC(Bentley, DgnPlatform, MaterialManager, GetTableList));
    c17.def("DeleteTable", &MaterialManager::DeleteTable, "sourceDgn"_a, "name"_a, DOC(Bentley, DgnPlatform, MaterialManager, DeleteTable));
    c17.def("DeleteTableById", &MaterialManager::DeleteTableById, "sourceDgn"_a, "id"_a, DOC(Bentley, DgnPlatform, MaterialManager, DeleteTableById));
    c17.def("GetTableNameForId", &MaterialManager::GetTableNameForId, "name"_a, "sourceDgn"_a, "id"_a, DOC(Bentley, DgnPlatform, MaterialManager, GetTableNameForId));
    c17.def("SaveTable", py::overload_cast<MaterialTableCR>(&MaterialManager::SaveTable), "table"_a, DOC(Bentley, DgnPlatform, MaterialManager, SaveTable));
    c17.def("SetActiveTable", &MaterialManager::SetActiveTable, "table"_a, "model"_a, DOC(Bentley, DgnPlatform, MaterialManager, SetActiveTable));
    c17.def("GetMaterialSearchPath", py::overload_cast<DgnDocumentMonikerCP>(&MaterialManager::GetMaterialSearchPath), "renderDgnMoniker"_a, DOC(Bentley, DgnPlatform, MaterialManager, GetMaterialSearchPath));
    c17.def("GetMaterialSearchPath", py::overload_cast<DgnDocumentMonikerCP, DgnDocumentMonikerCP>(&MaterialManager::GetMaterialSearchPath), "renderDgnMoniker"_a, "materialTableMoniker"_a, DOC(Bentley, DgnPlatform, MaterialManager, GetMaterialSearchPath));
    c17.def("GetPatternSearchPath", &MaterialManager::GetPatternSearchPath, "renderDgnMoniker"_a, DOC(Bentley, DgnPlatform, MaterialManager, GetPatternSearchPath));
    c17.def("FindTexture", &MaterialManager::FindTexture, "textureName"_a, "renderDgnFile"_a, DOC(Bentley, DgnPlatform, MaterialManager, FindTexture));
    c17.def("GetPalettesInSearchPath", &MaterialManager::GetPalettesInSearchPath, "paletteList"_a, "envVar"_a, DOC(Bentley, DgnPlatform, MaterialManager, GetPalettesInSearchPath));
    c17.def("GetPalettesInDgnLib", py::overload_cast<MaterialPaletteList&, WCharCP>(&MaterialManager::GetPalettesInDgnLib), "paleteList"_a, "dgnLibFileName"_a, DOC(Bentley, DgnPlatform, MaterialManager, GetPalettesInDgnLib));
    c17.def("GetPalettesInDgnLib", py::overload_cast<MaterialPaletteList&, DgnFileR>(&MaterialManager::GetPalettesInDgnLib), "paleteList"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, MaterialManager, GetPalettesInDgnLib));
    c17.def("CreateEmptyPalFile", &MaterialManager::CreateEmptyPalFile, "moniker"_a, DOC(Bentley, DgnPlatform, MaterialManager, CreateEmptyPalFile));
    c17.def("RenamePalette", &MaterialManager::RenamePalette, "oldPalette"_a, "newName"_a, "model"_a, DOC(Bentley, DgnPlatform, MaterialManager, RenamePalette));
    c17.def("UnloadPalette", &MaterialManager::UnloadPalette, "palette"_a, "option"_a, "model"_a, DOC(Bentley, DgnPlatform, MaterialManager, UnloadPalette));
    c17.def("PalettePersistenceRequiresFlush", &MaterialManager::PalettePersistenceRequiresFlush, "palette"_a, DOC(Bentley, DgnPlatform, MaterialManager, PalettePersistenceRequiresFlush));
    c17.def("FlushPalette", &MaterialManager::FlushPalette, "palette"_a, "renderModelRef"_a, DOC(Bentley, DgnPlatform, MaterialManager, FlushPalette));
    c17.def("ConvertExternalTableAndPalettesToInternal", &MaterialManager::ConvertExternalTableAndPalettesToInternal, "externalTable"_a, "renderModelRef"_a, DOC(Bentley, DgnPlatform, MaterialManager, ConvertExternalTableAndPalettesToInternal));
    
    c17.def("ConvertInternalTableAndPalettesToExternalWithUnifiedPaletteName",
            &MaterialManager::ConvertInternalTableAndPalettesToExternalWithUnifiedPaletteName,
            "internalTable"_a, "externalTableName"_a, "externalPalette"_a, "renderModelRef"_a, DOC(Bentley, DgnPlatform, MaterialManager, ConvertInternalTableAndPalettesToExternalWithUnifiedPaletteName));

    c17.def("ConvertInternalTableAndPalettesToExternal", 
            &MaterialManager::ConvertInternalTableAndPalettesToExternal,
            "internalTable"_a, "externalTableName"_a, "paletteOutputFolder"_a, "renderModelRef"_a, DOC(Bentley, DgnPlatform, MaterialManager, ConvertInternalTableAndPalettesToExternal));

    c17.def("SaveInternalPaletteAsExternal", [] (MaterialManager& self, PaletteInfoP internalPalette, WStringR externalFileName, DgnModelRefR renderModelRef)
            {
            return self.SaveInternalPaletteAsExternal(PaletteInfoPtr(internalPalette), externalFileName, renderModelRef);
            }, "internalPalette"_a, "externalFileName"_a, "renderModelRef"_a, DOC(Bentley, DgnPlatform, MaterialManager, SaveInternalPaletteAsExternal));

    c17.def("RevertMaterial", &MaterialManager::RevertMaterial, "materialId"_a, "palette"_a, "renderModelRef"_a, DOC(Bentley, DgnPlatform, MaterialManager, RevertMaterial));

    c17.def("GetProjectionParametersFromMaterial", 
            py::overload_cast<ElementHandleCR, MaterialCR, MaterialMapCR, MaterialMapLayerCR, MaterialProjectionParametersR>(&MaterialManager::GetProjectionParametersFromMaterial),
            "eh"_a, "material"_a, "map"_a, "layer"_a, "params"_a, DOC(Bentley, DgnPlatform, MaterialManager, GetProjectionParametersFromMaterial));

    c17.def("CreateProjectionGroup", &MaterialManager::CreateProjectionGroup, "origin"_a, "size"_a, "angles"_a, "mode"_a, "variant"_a, "agenda"_a, "name"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, MaterialManager, CreateProjectionGroup));
    c17.def("ModifyProjectionGroup", &MaterialManager::ModifyProjectionGroup, "origin"_a, "size"_a, "angles"_a, "mode"_a, "variant"_a, "group"_a, DOC(Bentley, DgnPlatform, MaterialManager, ModifyProjectionGroup));
    
    c17.def("GetProjectionGroupParameters", [] (MaterialManager& self, DPoint3dR origin, DPoint3dR size, DPoint3dR angles, NamedGroupR group)
            {
            MapMode mode;
            ProjectionVariant variant;
            auto retVal = self.GetProjectionGroupParameters(origin, size, angles, mode, variant, group);
            return py::make_tuple(retVal, mode, variant);
            }, "origin"_a, "size"_a, "angles"_a, "group"_a, DOC(Bentley, DgnPlatform, MaterialManager, GetProjectionGroupParameters));

    c17.def("GetProjectionGroupParameters", [] (MaterialManager& self, DPoint3dR offset, DPoint3dR size, DPoint3dR angles, ElementHandleCR eh)
            {
            MapMode mode;
            ProjectionVariant variant;
            auto retVal = self.GetProjectionGroupParameters(offset, size, angles, mode, variant, eh);
            return py::make_tuple(retVal, mode, variant);
            }, "offset"_a, "size"_a, "angles"_a, "eh"_a, DOC(Bentley, DgnPlatform, MaterialManager, GetProjectionGroupParameters));
            
    c17.def("CopyGeometryMapSharedCellDefs", &MaterialManager::CopyGeometryMapSharedCellDefs, "destModelRef"_a, "sourceModelRef"_a, DOC(Bentley, DgnPlatform, MaterialManager, CopyGeometryMapSharedCellDefs));
    c17.def("HasInternalMaterials", &MaterialManager::HasInternalMaterials, "dgnFile"_a, DOC(Bentley, DgnPlatform, MaterialManager, HasInternalMaterials));
    c17.def_static("GetManager", &MaterialManager::GetManagerR, py::return_value_policy::reference);    
    }