/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MdlApi\mscell.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/MdlApi/mscell.fdf>



static const char * __doc_MstnPlatform_Cell_ReplaceLibraryHeaderElement =R"doc(@Description Replace the data for a cell header in a library. Since
this will replace all linkages on the element except name and
description, care must be taken to avoid removing linkages that should
remain. Typically Cell.ReadLibraryElements is used to get the cell
header so that the original linkages are in place. @Param(input) library
is the pointer to the cell library to use. @Param(input) cellEdP is the
new cell element to use to replace the header. @Param(input) cellType is
the cell type; see Cell.AddLibDescr for a description of types.
@Return SUCCESS if the operation is completed successfully, otherwise
ERROR.

Remark:
    

@See Cell.ReadLibraryElements Cell.GetElmDscr Cell.ModifyInfo
)doc";

static const char * __doc_MstnPlatform_Cell_ModifyInfo =R"doc(@Description Replace the name and description of a cell in a library.
@Param(input) newName is the new cell name. Pass NULL to use the old
name. @Param(input) newdescr is the new cell description. Pass NULL to
use the old description. @Param(input) cellName is the name of the cell
to modify. @Param(input) library is the pointer to the cell library to
use. @Return SUCCESS if the operation is completed successfully,
otherwise ERROR. @Remarks Cell names are case-insensitive, so this
function will not work to change only the case of a name. If the cell
name contains invalid characters, this operation will fail. See
Model.NameIsValid to test for validity. Cell names are limited to
DgnPlatform::MAX_CELLNAME_LENGTH wchars.

Remark:
    

@See Cell.ReadLibraryElements mdlCell_getElmDscr
Cell.ReplaceLibraryHeaderElement )doc";

static const char * __doc_MstnPlatform_Cell_ReadLibraryElements =R"doc(@Description Get the component elements of the specified cell from the
cell library. Calling this function with justHeader false is the same
as calling Cell.GetElmDscr with no transformations. @Param(output)
cellElementsPP is an element descriptor containing the elements of the
cell. @Param(input) cellName the name of the cell to find and read.
@Param(input) library the cell library to read the cell from, or NULL to
search. @Param(input) justHeader if set true, only the cell header is
read and returned. @Return SUCCESS if the operation is completed
successfully, otherwise ERROR.

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Cell_SetOriginAndRange =R"doc(@Description Set the cell's range, range diagonal, and origin. The
origin is set to the middle of the range. This function only validates
the range of the cell against the ACTIVEMODEL. If you are working with
a different modelRef, you must use Elmdscr.Validate and
Cell.SetRange. @Param(input) cellDP the cell's element descriptor.

See also:
    Cell.SetRange

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Cell_SetRange =R"doc(@Description The Cell.Create and Cell.SetRange functions are
generally used to create library cells in memory for subsequent
addition to a cell library using Cell.AddLibDescr. The programmer
typically creates a cell element, creates a new element descriptor,
adds the component elements to that element descriptor, calls
Cell.SetRange, and then adds the cell to the library using
Cell.AddLibDescr. @Param[in,out] cellDP the element descriptor of
the cell. @Param(input) modelRef indicates the model to validate the cell
range against. ACTIVEMODEL is typically used. @Remarks The
Cell.SetRange function must be called to update the range block
diagonal in the header of a cell library element descriptor. The range
block diagonal is the range of the un-rotated cell, so this function
must be called after the cell definition is complete (immediately
before Cell.AddLibDescr is called). The cell range is used when
creating cell handles.

See also:
    Cell.AddLibDescr Cell.SetOriginAndRange

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Cell_Rename =R"doc(@Description Changes the name of cell in the current cell library.
@Param(input) newName is the new name of the cell in the library. This
must be less than DgnPlatform::MAX_CELLNAME_LENGTH characters, and
must be valid as tested by Model.NameIsValid. @Param(input) oldName
old name for cell in library @Return SUCCESS if the specified cell was
renamed. If an error occurs, they return one the following values:
MDLERR_CELLNOTFOUND, MDLERR_CELLEXISTS, MDLERR_INVALIDLIBRARY,
MDLERR_NOCELLLIBRARY or MDLERR_FILEREADONLY.

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Cell_SetDescription =R"doc(@Description Set the description of the specified cell element. When
setting the description of a cell using an element descriptor you need
to be careful about changing the length of the cell description as the
element descriptor has only been allocated to be large enough for the
current description length. The proper way to change the cell
descriptor is:

```
MSElement   element;
memcpy (&element, &cellDP->el, Element.Size (&cellDP->el));
Cell.SetDescription (&element, L" NEW DESCRIPTION ");
Elmdscr.ReplaceElement (&cellDP, &element);
```

@Param(input) elmP the cell element on which the description will be set.
@Param(input) cellDescrP the description to give the cell. @Return
SUCCESS if the operation is completed successfully, otherwise ERROR.

See also:
    Cell.ExtractDescription Cell.SetName

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Cell_ExtractDescription =R"doc(@Description Retrieve the description from a cell element and copy it
to the provided buffer. Note that graphic cells and shared cell
instances as placed by MicroStation do not keep their descriptions.
For shared cells, you should use this function on the definition. For
graphic cells, you must find the cell in a library and extract its
description that way. @Param(input) cellDescrP the buffer where the
extracted cell description will be placed. @Param(input) bufferSize the
maximum number of MSWChars to copy to the cellDescrP buffer.
@Param(input) elmP is the cell element from which the description is
extracted. @Return SUCCESS if the operation is completed successfully,
otherwise ERROR

See also:
    Cell.SetDescription Cell.ExtractName

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Cell_SetName =R"doc(@Description Set the name of the specified cell. When setting the name
of a cell using an element descriptor you need to be careful about
changing the length of the cell name as the element descriptor has
only been allocated to be large enough for the current name length.
The proper way to change the cell descriptor is:<BR>

```
MSElement   element;
memcpy (&element, &cellDP->el, Element.Size (&cellDP->el));
Cell.SetName (&element, L" NEW NAME ");
Elmdscr.ReplaceElement (&cellDP, &element);
```

@Param(input) elmP the cell element on which the name will be set.
@Param(input) cellNameP the name to give to the cell. @Return SUCCESS if
the operation is completed successfully, otherwise ERROR .

See also:
    Cell.ExtractName Cell.SetDescription

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Cell_ExtractName =R"doc(@Description Retrieve the name string from a non-shared or shared cell
element and copy it to the provided buffer. @Param(output) cellNameP the
buffer where the extracted cell name will be placed. @Param(input)
bufferSize the maximum number of MSWChars to copy to cellNameP.
@Param(input) elmP the cell element from which the name is extracted.
@Return SUCCESS if the cell name is successfully found and copied to
the buffer, otherwise ERROR.

See also:
    Cell.SetName Cell.ExtractDescription

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Cell_PlaceCell =R"doc(@Description Place a cell in the active model of the current design
file.

Remark:
    s If library is NULL, Cell.PlaceCell scans the current cell
    library for the cell using cellName, and if not found then scans
    libraries in the MS_CELLLIST path.

Remark:
    s If sharedFlag is 1 and a shared cell definition for cellName
    exists in the design file, a new shared cell instance is placed
    without the cell library being read, and library is ignored. If
    the sharedFlag is 1 and no shared cell definition exists, the cell
    will be read from the library and both the shared cell definition
    and instance will be created.

Remark:
    s If the active model's Annotation Scale lock is ON, the active
    annotation scale is propagated to the cell. The cell model (from
    cell library) needs to have the " Can be placed as annotation cell "
    toggle ON in order to be placed as an annotation cell. If that
    toggle is OFF, the active annotation scale is propagated only to
    the annotations contained in that cell model. @Param(input) rOrigin
    the location to place the cell origin. If origin is NULL, the cell
    is placed at the (0, 0, 0) point in the current coordinate system.
    @Param(input) scale points to a Dpoint3d structure holding the X, Y,
    and (in 3D) Z scale factors to be applied to the cell elements
    before they are placed. If scale is NULL, the cell is placed at a
    scale factor of 1.0. @Param(input) trueScale if true, use cell model
    and master model units to scale the cell. @Param(input) rotMatrix the
    rotation matrix that defines the orientation for cell placement.
    If rMatrix is NULL, the identity matrix is used. rMatrix does not
    necessarily need to be orthogonal or normalized. (Cells can be
    placed skewed). @Param(input) attributes is an array of attribute
    information to append to the cell header before it is placed. The
    first short of this array is the length, in shorts, of the
    attribute data. Note that attribute linkage lengths must be a
    multiple of four words. If attributes is NULL, the cell has no
    attributes attached to the header. @Param(input) ggroup the graphic
    group number for the cell's elements. A value of 0 means that the
    elements will not be part of a graphic group. @Param(input)
    relativeMode determines how the levels for the cell's elements are
    assigned. All elements for a point cell are assigned to baseLevel.
    If relativeMode is true, the lowest level used in the cell
    definition is assigned to baseLevel and all other element levels
    are adjusted accordingly. If relativeMode is false, the levels are
    taken from the cell library unchanged. @Param(input) baseLevel
    determines how the levels for the cell's elements are assigned.
    All elements for a point cell are assigned to baseLevel. For a
    graphic cell, this is ignored if relativeMode is false. This is a
    level ID, gotten through functions such as Level.GetIdFromName.
    Relative placement internally works by level numbers. @Param(input)
    sharedFlag indicates whether the cell should be placed as shared
    or unshared. If sharedFlag is 0, an unshared cell is placed. If
    sharedFlag is 1, a shared cell is created. If sharedFlag is 2, the
    state of the user-specified shared flag is used. Cell.PlaceCell
    also creates and places the shared cell definition if it does not
    exist in the file. @Param(input) cellName is the name of the cell to
    be placed. @Param(input) library name of library or NULL. If the
    library is NULL, the cell will be searched for in the active cell
    library, then all files found on MS_CELLLIST. If the shared flag
    is 1, then the active file will be searched for a shared cell
    definition first. @Remarks The rotation matrix, rotMatrix, is
    applied before the scale factors. @Return the file position of a
    newly placed cell. If an error occurs, it returns 0 and sets
    mdlErrno to the specific error cause.

See also:
    Cell.GetElmDscr

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Cell_IsPointCell =R"doc(@Description Determine whether the cell cellHeader is a point cell.
@Param(input) hdr cell header element @Return true if cellHeader is a
point cell, false for any other type.

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Cell_CopyCellDefinition =R"doc(@Description Duplicate a cell definition from one cell library to
another.

Remark:
    s This function always try to convert nested cells to references
    (see Cell.AddLibDescr). @Param(input) destLibrary the cell library
    to copy the cell to. @Param(input) cellName the name of the cell to
    copy. @Param(input) sourceLibrary the cell library to copy the cell
    from. @Return SUCCESS if the cell is copied, otherwise an error
    code.

Remark:
    

@See Cell.GetLibraryObject )doc";

static const char * __doc_MstnPlatform_Cell_FindCellEx =R"doc(@Description Search for a cell with the specified cell name. The
search order is first the library passed in as preferredLib; then the
current active cell library; and then sequentially though the files
listed in MS_CELLLIST and MS_BLOCKLIST if the searchAll parameter is
true. The first cell found with the requested name will stop the
search. This function differs from Cell.FindCell by the rights
parameter which allows the caller to specify the desired permission
level. @Param(output) library is the library where the cell was found, if
the search was successful. This argument will be NULL if the cell was
not found. @Param(input) preferredLib the cell library to search first,
or NULL. @Param(input) cellName the name of the cell to search for.
@Param(input) searchAll indicates whether all of the cell libraries in
the MS_CELLLIST and MS_BLOCKLIST paths are to be searched. Setting
this value to 0 indicates that only the preferredLib library is
searched; setting this value to 1 indicates that all cell libraries
are to be searched; setting this value to 2 indicates that all cell
libraries are to be searched and messages generated as the search
progresses. Messages are sent to the error display field in the
MicroStation window. @Param(input) rights The level of rights that should
be tested. See DgnFileObj.CheckRights for a description of the
choices. @Return SUCCESS if the cell was found, otherwise
MDLERR_CELLNOTFOUND.

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Cell_FindCell =R"doc(@Description Search for a cell with the specified cell name. The
search order is first the library passed in as preferredLib; then the
current active cell library; and then sequentially though the files
listed in MS_CELLLIST and MS_BLOCKLIST if the searchAll parameter is
true. The first cell found with the requested name will stop the
search. @Remarks This function will only find cells which have export
rights or better. Because of the rights limitation, protected
libraries will be skipped and cells will be searched for through th
rest of the path. To specify rights, see Cell.FindCellEx.
@Param(output) library is the library where the cell was found, if the
search was successful. This argument will be NULL if the cell was not
found. @Param(input) preferredLib the cell library to search first, or
NULL. @Param(input) cellName the name of the cell to search for.
@Param(input) searchAll indicates whether all of the cell libraries in
the MS_CELLLIST and MS_BLOCKLIST paths are to be searched. Setting
this value to 0 indicates that only the preferredLib library is
searched; setting this value to 1 indicates that all cell libraries
are to be searched; setting this value to 2 indicates that all cell
libraries are to be searched and messages generated as the search
progresses. Messages are sent to the error display field in the
MicroStation window. @Return SUCCESS if the cell was found, otherwise
MDLERR_CELLNOTFOUND.

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Cell_GetElmDscr =R"doc(@Description Read the specified cell from the cell library and returns
the cell's element descriptor. The address of the element descriptor
for the cell's graphic elements is returned in cellDscrPP. @Remarks If
empty text nodes are in a cell, MicroStation removes them before it
places the cell. These empty text nodes are placed immediately after
the cell. For this reason, Cell.GetElmDscr also extracts the empty
text node elements and returns them in a separate element descriptor,
txtNodeDscrPP. Applications should treat these empty text nodes
similarly. If txtNodeDscrPP is NULL, then empty text nodes will be
lost. @Remarks If sharedFlag is 1 or 2 and the user has turned shared
cells on, the function first searches the active file for a shared
cell instance without reading the cell library. If no shared cell is
found, then the library is searched. @Param(output) cellDscrPP cell
element descriptor @Param(output) txtNodeDscrPP element descriptor for
empty text nodes. If NULL, these text nodes are lost. @Param(input)
rOrigin the location of the cell's origin. If origin is NULL, the cell
is transformed to the (0, 0, 0) point in the current coordinate
system. @Param(input) scale points to a Dpoint3d structure holding the X,
Y and (in 3D) Z scale factors to be applied to the cell's elements. If
scale is NULL, the cell is not scaled. @Param(input) trueScale indicates
whether the cell definition and DGN file units are used in scaling the
cell, resulting in cells that have the same size between models with
different units. ACTIVEMODEL is assumed for the destination.
@Param(input) rotMatrix is the rotation matrix that defines the cell's
orientation. If rMatrix is NULL, the identity matrix is used.
@Param(input) attributes an array of attribute information to append to
the cell header. This parameter has been deprecated; please see the
mdlLinkage functions to append attributes to the cell header.
@Param(input) ggroup is the graphic group number for the cell's elements.
A value of 0 means that the elements will not be part of a graphic
group. @Param(input) sharedFlag indicates whether the element descriptor
is for a shared or unshared cell. If sharedFlag is 0, an unshared cell
is returned. If sharedFlag is 1, a shared cell is returned if found,
otherwise an unshared cell. If sharedFlag is 2, the state of the user-
specified shared flag is used. @Param(input) updateMasterFile indicates
that the cell is to be placed in the active model ref, so all
necessary styles, etc. should be copied to the active file. If this
parameter is set to false, then the display of the cell elements may
not match the original model. @Param(input) cellName the name of the cell
to be returned. @Param(input) library the library object containing the
cell. If this argument is NULL, the cell is searched for. It is
usually acquired via Cell.FindCell or Cell.GetLibraryObject.
@Return SUCCESS if the cell is read and cellDscrPP is valid.
Otherwise, it returns an error status.

See also:
    Cell.PlaceCell Cell.GetElmDscrExtended

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Cell_GetLibraryObject =R"doc(@Description Returns a pointer to the cell library object of the given
name. This is used by Cell.GetElmDscr, Cell.PlaceCell, and other
functions that require a cell library handle. @Param(output) ppLibraryObj
pointer to the cell library object. @Param(input) pLibName name of the
cell library to find. @Param(input) unused Unused; pass false. @Return
SUCCESS if the library of the given name is found, otherwise ERROR.

See also:
    Cell.PlaceCell Cell.GetElmDscr

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Cell_FixLevelsByCode =R"doc(@Description Adjust element levels in a cell element descriptor,
elemDscr. This adjustment is based on the cell type and the values of
relativeMode and baseLevelId. It uses the following logic:

```
if (cell is a point cell)
{
set all levels to baseLevel
}
else if (relativeMode is true)
{
adjust so the lowest level used in cell is baseLevel
}
```

If relative mode is chosen, the baseLevelId is converted to a level
code and all element level codes are adjusted by the difference
between the base level code and lowest level code in the cell.

@Param(input) elemDscr cell element descriptor @Param(input) pModelRef model
ref of element descriptor @Param(input) relativeMode relative or absolute
@Param(input) baseLevelId used for point cells and relative mode. This is
a level number, not a level code. @Remarks This function is needed
because Cell.GetElmDscr does not apply the above logic before it
returns the cell's element descriptor. This functionality was left out
of Cell.GetElmDscr so that you could get the original level values.
@Return SUCCESS if the level codes could be adjusted.

See also:
    Cell.GetElmDscr Cell.FixLevels

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Cell_FixLevels =R"doc(@Description This function is just a direct call to
Cell.FixLevelsByCode, so that function should be called instead. It
will adjust element levels in a cell element descriptor, elemDscr.
This adjustment is based on the cell type and the values of
relativeMode and baseLevel. It uses the following logic:

```
if (cell is a point cell)
{
set all levels to baseLevel
}
else if (relativeMode is true)
{
adjust so the lowest level used in cell is baseLevel
}
```

If relative mode is chosen, the all element level ids are adjusted by
the difference between the lowest level id in the cell and the base
level id provided.

@Param(input) elemDscr cell element descriptor @Param(input) relativeMode
true for relative level. @Param(input) baseLevel used for point cells and
relative mode. @Param(input) library This is no longer used and can be
NULL. Instead the model ref from elemDscr->h.dgnModelRef is used.
@Remarks This function is needed because Cell.GetElmDscr does not
apply the above logic before it returns the cell's element descriptor.
This functionality was left out of Cell.GetElmDscr so that you
could get the original level values. @Return SUCCESS if the levels
could be fixed.

See also:
    Cell.GetElmDscr Cell.FixLevelsByCode

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Cell_Extract =R"doc(@Description Extracts the information from a cell header element. If
any parameters are NULL, this function does not attempt to fill them
in. All parameters are returned in the current (design file)
coordinate system. @Param(output) origin is the cell origin. @Param(output)
shape returns an array of eight Dpoint3d's which represent the minimum
bounding box for the cell in the coordinate system of the cell. This
idea can be illustrated by using MicroStation's element selection tool
to select a cell. MicroStation places handles on the boundary which
defines the cell, and these handles correlate to the eight Dpoint3ds
returned by Cell.Extract. Note that this must point to an array
large enough to hold the 8 points. @Param(output) rMatrix the rotation
matrix for the cell. @Param(output) scale the cell's X, Y and Z scale
factors. @Param(output) cellName the cell's name in Unicode. @Param(input)
bufferSize if extracting cell's name, number of widechars name buffer
can hold. This is ignored if cellName is NULL. @Param(input) cell cell
element to extract information from. @Remarks The points in shape are
transformed into the current coordinate system before they are
returned. They do not necessarily represent a minimum bounding box in
the current coordinate system. @Return SUCCESS if cell is a valid
MicroStation element of type CELL_HEADER_ELM. Otherwise, it returns
MDLERR_BADELEMENT.

See also:
    Cell.Create

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Cell_ExistsInLibrary =R"doc(@Description Indicates whether a cell with the specified name exists
in the current cell library. @Param(input) cellName name of the cell to
search for. @Return true if the cell name exists in the library;
otherwise it returns false.

See also:
    Cell.PlaceCell Cell.GetElmDscr

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Cell_DeleteInLibrary =R"doc(@Description Remove a cell from the current active cell library by
name. @Param(input) cellName name of cell to be deleted. @Return SUCCESS
if the specified cell was deleted or one of the following error
values:MDLERR_CELLNOTFOUND, MDLERR_CELLEXISTS, MDLERR_INVALIDLIBRARY,
MDLERR_NOCELLLIBRARY or MDLERR_FILEREADONLY.

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Cell_CreateFromFenceByType =R"doc(@Description Create a new cell in the current cell library that
contains the elements in the fence. It creates the new cell from the
current selection set if no fence is defined. @Param(input) cellName the
name of the cell in the library. This must be less than
DgnPlatform::MAX_CELLNAME_LENGTH characters, and must be valid as
tested by Model.NameIsValid. @Param(input) descr is the cell
description; it may not exceed MAX_CELLDSCR_LENGTH characters.
@Param(input) rOrigin the origin of the cell. If NULL is passed for
cellOrigin, tcb->celor is used. @Param(input) cellType the type of cell
to create (point, graphic, parametric) @Remarks This function collects
up all the elements in the fence or selection set and creates a cell
element out of them. @Return SUCCESS or the error that occurred which
prevented the cell creation. mdlErrno is also set to the error value.
Possible values include MDLERR_INVALIDLIBRARY, MDLERR_NOCELLLIBRARY
and MDLERR_FILEREADONLY.

See also:
    Cell.Create Cell.AddLibDescr

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Cell_CreateFromFence =R"doc(@Description Create a new cell in the current cell library that
contains the elements in the fence. It creates the new cell from the
current selection set if no fence is defined. @Param(input) cellName the
name of the cell in the library. This must be less than
DgnPlatform::MAX_CELLNAME_LENGTH characters, and must be valid as
tested by Model.NameIsValid. @Param(input) descr is the cell
description; it may not exceed MAX_CELLDSCR_LENGTH characters.
@Param(input) rOrigin the origin of the cell. If NULL is passed for
cellOrigin, tcb->celor is used. @Param(input) pointCell true if the cell
is to be a point cell, otherwise false. @Remarks This function
collects up all the elements in the fence or selection set and creates
a cell element out of them. @Return SUCCESS or the error that occurred
which prevented the cell creation. mdlErrno is also set to the error
value. Possible values include MDLERR_INVALIDLIBRARY,
MDLERR_NOCELLLIBRARY and MDLERR_FILEREADONLY.

See also:
    Cell.Create Cell.AddLibDescr

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Cell_Create =R"doc(@Description Creates a new cell element based on the data provided.
This can be used as an orphan cell, or later added to a cell library
using Cell.AddLibDescr. Typically this function is used to create a
cell header, and Elmdscr.AppendDscr is then used to add elements.
@Param(output) cellElm This is a pointer to a full MSElement union which
is filled in. @Param(input) cellName the name of the cell; may be NULL.
@Param(input) origin the origin of the cell. If NULL is passed for
cellOrigin, the (0, 0, 0) point for the current coordinate system is
used. @Param(input) pointCell true if the cell is to be a point cell,
otherwise false. @Return SUCCESS if the operation is completed
successfully, otherwise ERROR

See also:
    Cell.AddLibDescr Cell.CreateFromFence

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Cell_AttachLibraryEx =R"doc(@Description Attach a new cell library to the current design file. If
a library is successfully attached, filename is set to the cell
library's full file specification. @Param(output) filename name of cell
library opened. This should be a string buffer at least MAXFILELENGTH
characters long. @Param(input) inputname is the name of the cell library.
inputName may contain a path specification. However, if it does not,
then MS_CELL and defaultDir (if defined) are searched for the file. If
this parameter is NULL, then the active library is detached.
@Param(input) defaultDir additional path to search. Can be NULL.
@Param(input) fromkeyin if true, the path information from inputName is
used. If it is false, Cell.AttachLibraryEx assumes that inputName
came from the information stored in the design file header (where the
path information is not always correct), and it only uses the path
information from inputName if the library cannot be found anywhere
else. MDL applications should normally set fromKeyin to true.
@Param(input) libraryFlag specifies how to handle the cell library if its
format is not up to date. If the cell library is a V7 cell library,
then it can be upgraded. See for the possible values. @Return SUCCESS
if the operation is completed and a cell library was attached,
otherwise an error value.

See also:
    Cell.AttachLibrary

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Cell_AttachLibrary =R"doc(@Description Attaches a new cell library to the current design file.
If a library is successfully attached, filename is set to the cell
library's full file specification. If the library is a V7 cell library
then this function will fail. It is the equivalent of calling
Cell.AttachLibraryEx with LIBRARY_IgnoreV7Libraries. @Param(output)
filename name of cell library opened. This should be a string buffer
at least MAXFILELENGTH characters long. @Param(input) inputname is the
name of the cell library. inputName may contain a path specification.
However, if it does not, then MS_CELL and defaultDir (if defined) are
searched for the file. If this parameter is NULL, then the active
library is detached. @Param(input) defaultDir additional path to search.
Can be NULL. @Param(input) fromkeyin if true, the path information from
inputName is used. If it is false, Cell.AttachLibrary assumes that
inputName came from the information stored in the design file header
(where the path information is not always correct), and it only uses
the path information from inputName if the library cannot be found
anywhere else. MDL applications should normally set fromKeyin to true.
@Remarks To detach a cell library, pass a NULL string for inputName.
@Return SUCCESS if a cell library is attached. If it cannot find the
cell library, it returns a non-zero value.

See also:
    Cell.AttachLibraryEx

Remark:
    

)doc";

static const char * __doc_MstnPlatform_Cell_AddLibDescr =R"doc(@Description Create a new cell in the currently attached cell library.
This function also handles copying styles, dependencies, etc. into the
library. @Param(input) cellEdP a cell element descriptor (type 2) to add
to the library. @Param(input) cellType the type of the cell in the
library. Use CellAddType::FromContext to choose GRAPHIC or POINT based
on the type of the cell. Otherwise, possible values for cellType are
CellAddType::NormalCell for a normal graphic cell or
CellAddType::PointCell for a point cell. @Param(input)
convertNestedCellsToRefs if true, a nested cell with the same name as
a cell (model) in the destination library will be replaced by a
reference to that cell, which matches the behavior of the MicroStation
cell creation tool. When deciding whether to replace, only the cell
names are compared, not the geometry. Pre-V8 behavior of this function
was to set this to false. Cell.CreateFromFence calls this function
with convertNestedCellsToRefs set to true. @Return SUCCESS if the cell
is added to the library, or an error otherwise. mdlErrno is set to the
value that indicates the error cause. Possible values include
MDLERR_INVALIDLIBRARY, MDLERR_NOCELLLIBRARY and MDLERR_FILEREADONLY.
@Remarks If a cell with the same name already exists in the library,
it will be replaced.

See also:
    Cell.Create Cell.CreateFromFence

Remark:
    

)doc";



struct Cell {};

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_mscell(py::module_& m)
    {
    //===================================================================================
    // enum class CellAddType
    py::enum_< CellAddType>(m, "CellAddType")
        .value("eFronContext", CellAddType::FromContext)
        .value("eNormalCell", CellAddType::NormalCell)
        .value("ePointCell", CellAddType::PointCell)
        .export_values();

    py::class_<Cell> c1(m, "Cell"); 

    c1.def_static("AddLibDescr", &mdlCell_addLibDescr, "cellEdP"_a, "cellType"_a, "convertNestedCellsToRefs"_a, DOC(MstnPlatform, Cell, AddLibDescr));
    c1.def_static("GetLibraryName", &mdlCell_getLibraryName, "fileName"_a);
    c1.def_static("AttachLibrary", &mdlCell_attachLibrary, "fileName"_a, "inputName"_a, "defaultDir"_a, "fromKeyin"_a, DOC(MstnPlatform, Cell, AttachLibrary));
    c1.def_static("AttachLibraryEx", &mdlCell_attachLibraryEx, "fileName"_a, "inputName"_a, "defaultDir"_a, "fromKeyin"_a, "libraryFlag"_a, DOC(MstnPlatform, Cell, AttachLibraryEx));

    m.attr("LIBRARY_IgnoreV7Libraries") = (int)LIBRARY_IgnoreV7Libraries;
    m.attr("LIBRARY_AutoConvertToV8") = (int)LIBRARY_AutoConvertToV8;
    m.attr("LIBRARY_PromptForConvertToV8") = (int)LIBRARY_PromptForConvertToV8;
    m.attr("LIBRARY_AutoConvertToV8NoBackup") = (int)LIBRARY_AutoConvertToV8NoBackup;

    c1.def_static("UpgradeLibrary", [](WStringR pLibraryFileName, WCharCP pBackupFileName, bool haveUnits, double uorPerStorage, double unitNumerator,
                                       double unitDenominator, WCharCP unitLabel, UnitFlags const* unitFlags, int libraryFlag,
                                       std::function<void(WCharCP, int)>& feedbackFunc)
          {
          WChar szName[512] = {0};
          wcscpy(szName, pLibraryFileName.c_str());

          auto retVal = mdlCell_upgradeLibrary(szName, pBackupFileName, haveUnits, uorPerStorage, unitNumerator, unitDenominator, unitLabel, unitFlags, libraryFlag,
                                               feedbackFunc.target<void(WCharCP, int)>());

          if (retVal == SUCCESS)
              pLibraryFileName.assign(szName);

          return retVal;
          }, "libraryFileName"_a, "backupFileName"_a, "haveUnits"_a, "uorPerStorage"_a, "unitNumerator"_a, "unitDenominator"_a, "unitLabel"_a, "unitFlags"_a, 
          "libraryFlag"_a, "feedbackFunc"_a);

    c1.def_static("Create", &mdlCell_create, "cellElm"_a, "cellName"_a, "origin"_a, "pointCell"_a, DOC(MstnPlatform, Cell, Create));
    c1.def_static("CreateFromFence", &mdlCell_createFromFence, "cellName"_a, "description"_a, "origin"_a, "pointCell"_a, DOC(MstnPlatform, Cell, CreateFromFence));
    c1.def_static("CreateFromFenceByType", &mdlCell_createFromFenceByType, "cellName"_a, "description"_a, "origin"_a, "cellType"_a, DOC(MstnPlatform, Cell, CreateFromFenceByType));
    c1.def_static("DeleteInLibrary", &mdlCell_deleteInLibrary, "cellName"_a, DOC(MstnPlatform, Cell, DeleteInLibrary));
    c1.def_static("ExistsInLibrary", &mdlCell_existsInLibrary, "cellName"_a, DOC(MstnPlatform, Cell, ExistsInLibrary));

    c1.def_static("Extract", [] (DPoint3dP origin, DPoint3dP shape, RotMatrixP rMatrix, DPoint3dP scale, WStringR cellName, MSElementCP cell)
          {
          WChar szName[512] = {0};
          auto retVal = mdlCell_extract(origin, shape, rMatrix, scale, szName, _countof(szName), cell);
          cellName.assign(szName);
          return retVal;
          }, "origin"_a, "shape"_a, "rMatrix"_a, "scale"_a, "cellName"_a, "cell"_a, DOC(MstnPlatform, Cell, Extract));

    c1.def_static("FixLevels", &mdlCell_fixLevels, "elemDescr"_a, "relativeMode"_a, "baseLevel"_a, "library"_a, DOC(MstnPlatform, Cell, FixLevels));
    c1.def_static("FixLevelsByCode", &mdlCell_fixLevelsByCode, "elemDescr"_a, "modelRef"_a, "relativeMode"_a, "baseLevel"_a, DOC(MstnPlatform, Cell, FixLevelsByCode));

    c1.def_static("GetLibraryObject", [] (WCharCP libName, bool unused)
          {
          DgnFileP libObj = nullptr;
          auto retVal = mdlCell_getLibraryObject(&libObj, libName, unused);
          return py::make_tuple(retVal, py::cast(libObj, py::return_value_policy::reference));
          }, "libName"_a, "unused"_a, DOC(MstnPlatform, Cell, GetLibraryObject));

    c1.def_static("GetElmDscr", [] (DPoint3dCP origin, DPoint3dCP scale, bool trueScale, RotMatrixCP rotMatrix, short const* attributes, UInt32 ggroup,
                                    int sharedFlag, bool updateMasterFile, WCharCP cellName, DgnFileP library)
          {
          MSElementDescrP cellDescr = nullptr;
          MSElementDescrP txtNodeDescr = nullptr;
          auto retVal = mdlCell_getElmDscr(&cellDescr, &txtNodeDescr, origin, scale, trueScale, rotMatrix, attributes, ggroup, sharedFlag, updateMasterFile, cellName, library);
          return py::make_tuple(retVal, cellDescr, txtNodeDescr);
          }, "origin"_a, "scale"_a, "trueScale"_a, "rotMatrix"_a, "attributes"_a, "ggroup"_a, "sharedFlag"_a, "updateMasterFile"_a, "cellName"_a, "library"_a, DOC(MstnPlatform, Cell, GetElmDscr));

    c1.def_static("GetElmDscrExtended", [] (DPoint3dCP origin, DPoint3dCP scale, bool trueScale, DgnModelRefP destModelRef, RotMatrixCP rotMatrix, short const* attributes,
                                            UInt32 ggroup, int sharedFlag, bool keepCellDimensionality, bool updateDestFile, WCharCP cellName, DgnFileP library)
          {
          MSElementDescrP cellDescr = nullptr;
          MSElementDescrP txtNodeDescr = nullptr;
          MSElementDescrP tagDescr = nullptr;
          auto retVal = mdlCell_getElmDscrExtended(&cellDescr, &txtNodeDescr, &tagDescr, origin, scale, trueScale, destModelRef, rotMatrix, attributes, ggroup,
                                                   sharedFlag, keepCellDimensionality, updateDestFile, cellName, library);
          return py::make_tuple(
              retVal,
              py::cast(cellDescr, py::return_value_policy::reference),
              py::cast(txtNodeDescr, py::return_value_policy::reference),
              py::cast(tagDescr, py::return_value_policy::reference));
          }, "origin"_a, "scale"_a, "trueScale"_a, "destModelRef"_a, "rotMatrix"_a, "attributes"_a, "ggroup"_a, "sharedFlag"_a, "keepCellDimensionality"_a,
          "updateDestFile"_a, "cellName"_a, "library"_a);

    c1.def_static("FindCell", [] (DgnFileP preferredLib, WCharCP cellName, int searchAll)
          {
          DgnFileP library = nullptr;
          auto retVal = mdlCell_findCell(&library, preferredLib, cellName, searchAll);
          return py::make_tuple(retVal, library);
          }, "preferredLib"_a, "cellName"_a, "searchAll"_a, DOC(MstnPlatform, Cell, FindCell));

    c1.def_static("FindCellEx", [] (DgnFileP preferredLib, WCharCP cellName, int searchAll, UInt32 rights)
          {
          DgnFileP library = nullptr;
          auto retVal = mdlCell_findCellEx(&library, preferredLib, cellName, searchAll, rights);
          return py::make_tuple(retVal, library);
          }, "preferredLib"_a, "cellName"_a, "searchAll"_a, "rights"_a, DOC(MstnPlatform, Cell, FindCellEx));

    c1.def_static("CopyCellDefinition", &mdlCell_copyCellDefinition, "destLibrary"_a, "cellName"_a, "sourceLibrary"_a, DOC(MstnPlatform, Cell, CopyCellDefinition));
    c1.def_static("IsPointCell", &mdlCell_isPointCell, "hdr"_a, DOC(MstnPlatform, Cell, IsPointCell));
    c1.def_static("PlaceCell", &mdlCell_placeCell, "origin"_a, "scale"_a, "trueScale"_a, "rotMatrix"_a, "attributes"_a, "ggroup"_a, "relativeMode"_a,
          "baseLevel"_a, "sharedFlag"_a, "cellName"_a, "library"_a, DOC(MstnPlatform, Cell, PlaceCell));

    c1.def_static("ExtractName", [] (WStringR cellName, MSElementCP elem)
          {
          WChar szName[512] = {0};
          auto retVal = mdlCell_extractName(szName, _countof(szName), elem);
          cellName.assign(szName);
          return retVal;
          }, "cellName"_a, "elem"_a, DOC(MstnPlatform, Cell, ExtractName));
    
    c1.def_static("SetName", &mdlCell_setName, "elem"_a, "cellName"_a, DOC(MstnPlatform, Cell, SetName));

    c1.def_static("ExtractDescription", [] (WStringR cellDescr, MSElementCP elem)
          {
          WChar szName[512] = {0};
          auto retVal = mdlCell_extractDescription(szName, _countof(szName), elem);
          cellDescr.assign(szName);
          return retVal;
          }, "cellDescr"_a, "elem"_a, DOC(MstnPlatform, Cell, ExtractDescription));

    c1.def_static("SetDescription", &mdlCell_setDescription, "elem"_a, "cellDescr"_a, DOC(MstnPlatform, Cell, SetDescription));
    c1.def_static("Rename", &mdlCell_rename, "newName"_a, "oldName"_a, DOC(MstnPlatform, Cell, Rename));
    c1.def_static("SetRange", &mdlCell_setRange, "cellDP"_a, "modelRef"_a, DOC(MstnPlatform, Cell, SetRange));
    c1.def_static("SetOriginAndRange", &mdlCell_setOriginAndRange, "cellDP"_a, DOC(MstnPlatform, Cell, SetOriginAndRange));

    c1.def_static("ReadLibraryElements", [] (WCharCP cellName, DgnFileP library, bool justHeader)
          {
          MSElementDescrP cellElements = nullptr;
          auto retVal = mdlCell_readLibraryElements(&cellElements, cellName, library, justHeader);
          return py::make_tuple(retVal, cellElements);
          }, "celName"_a, "library"_a, "justHeader"_a, DOC(MstnPlatform, Cell, ReadLibraryElements));

    c1.def_static("ModifyInfo", &mdlCell_modifyInfo, "newName"_a, "newDescr"_a, "cellName"_a, "library"_a, DOC(MstnPlatform, Cell, ModifyInfo));
    c1.def_static("ReplaceLibraryHeaderElement", &mdlCell_replaceLibraryHeaderElement, "library"_a, "cellEdP"_a, "cellType"_a, DOC(MstnPlatform, Cell, ReplaceLibraryHeaderElement));
    }