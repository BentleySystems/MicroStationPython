/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\texttablehandler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/TextTableHandler.h>



static const char * __doc_Bentley_DgnPlatform_TextTableHandler_IsTableNameExist =R"doc(Check if there is a table which name is same as the input tableName.

Parameter ``tableName``:
    The table name to find.

Parameter ``dgnFile``:
    The dgn file in which we are searching the table name.

Returns:
    true if the table name exists, false for not.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableHandler_CreateTextTableElement =R"doc(Create a new element that stores the state of the input table object.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableHandler_SetTextTable =R"doc(Update the element to reflect the status of the input table object.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableHandler_ExtractTextTable =R"doc(Creates a TextTable object representing the table stored on the input
element.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_SetTableName =R"doc(Set the name of this table.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetTableName =R"doc(Get the name of this table.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetSizeLock =R"doc(Get the value of this table's size lock. When the lock is false, the
table's size will grow or shrink. When the lock is true, the table's
size will never change.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_CloneAsSeed =R"doc(Creates a clone of the table in the context of the specified model,
with the specified number of empty rows and columns. The clone will
retain the table's symbology properties but none of the overrides
associated with specific rows, columns, or cells.

Parameter ``rowCount``:
    The number of rows in the cloned table.

Parameter ``columnCount``:
    The number of columns in the cloned table.

Parameter ``model``:
    The destination model.

Returns:
    An empty clone of the table with the specified number of rows and
    columns.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_Create =R"doc(Create a new table from scratch. All table properties will be
initialized to safe default values.

Parameter ``rowCount``:
    IN The number of rows in the table.

Parameter ``columnCount``:
    IN The number of columns in the table.

Parameter ``textStyleId``:
    IN The default TextStyle.

Parameter ``backupTextHeight``:
    IN Used when textStyleId refers to a style with zero text height.

Parameter ``model``:
    IN Used as context for textStyleId and UOR sizes.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_SetHeight =R"doc(Get the overrall height of this table. Each row will be resized
proportionally to its original size in the table. Will fail if the
input value is less than the sum of the minimum heights for all the
rows.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetHeight =R"doc(Get the overrall height of this table. This is equivalent to summing
all the row heights. This method ignores the effects of table
breaking.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_SetWidth =R"doc(Get the overall width of this table. Each column will be resized
proportionally to its original size in the table. Will fail if the
input value is less than the sum of the minimum widths for all the
columns.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetWidth =R"doc(Get the overall width of this table. This is equivalent to summing all
the column widths. This method ignores the effects of table breaking.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_SetEdgeSymbology =R"doc(Change the edge line symbology used to draw the edges of a collection
of cells.

Parameter ``symb``:
    IN The symbology to apply to the specified edges.

Parameter ``edges``:
    IN Specifies which edges to change.

Parameter ``cells``:
    IN Specifies which cells to change.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetEdgeSymbology =R"doc(Get the edge line symbologies used to draw the edges of a collection
of cells.

Parameter ``symb``:
    OUT A list of unique symbologies from the requested edges.

Parameter ``edges``:
    IN Specifies which edges to query.

Parameter ``cells``:
    IN Specifies which cells to query.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_MergeCells =R"doc(Change the row and/or column span of a cell. This will fail if it
would consume a part of another merged cell.

Parameter ``root``:
    IN The upper left cell index of the merged cell.

Parameter ``numRows``:
    IN the number of rows that will be spanned by the merged cell.

Parameter ``numCols``:
    IN the number of columns that will be spanned by the merged cell.

Returns:
    ERROR if the merging could not be done.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetCellCollection =R"doc(Get a collection that can be used to iterate all the cells in the
table. This method is more convenient than calling GetCell in a nested
for loop.

``
for (TextTableCellCR cell:table.GetCellCollection())
    // do something with cell
``)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_DeleteColumn =R"doc(Delete an existing column from the table.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_InsertColumn =R"doc(Insert a new column into the table. It is only possible to insert
directly before (to the left of) or after (to the right of) the seed
column.

Parameter ``indexOfSeedColumn``:
    IN The seed columns's properties but not its contents will be
    copied to form the new column.

Parameter ``dir``:
    IN The location of the new column either before or after the seed
    column.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_DeleteRow =R"doc(Delete an existing row from the table.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_InsertRow =R"doc(Insert a new row into the table. It is only possible to insert
directly before (above) or after (below) the seed row.

Parameter ``indexOfSeedRow``:
    IN The seed row's properties but not its contents will be copied
    to form the new row.

Parameter ``dir``:
    IN The location of the new row either before or after the seed
    row.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_ClearDefaultTextWeight =R"doc(Remove the default text weight. This is the opposite of
SetDefaultTextWeight.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_ClearDefaultTextColor =R"doc(Remove the default text color. This is the opposite of
SetDefaultTextColor.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_SetDefaultFill =R"doc(Change the default fill parameters which will be used by cells that
don't have a specific fill set.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_SetTextStyleId =R"doc(Change the default text style which will be used to create text for
empty cells.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_HasDefaultTextWeight =R"doc(Test if a default text weight is stored. Use GetDefaultTextWeight to
get the value.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_HasDefaultTextColor =R"doc(Test if a default text color is stored. Use GetDefaultTextColor to get
the value.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetTransform =R"doc(Get a transform which is composed of the table's origin and rotation.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetDefaultFill =R"doc(Get the default fill parameters which will be used by cells that don't
have a specific fill set.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetTextStyleId =R"doc(Get the default text style which will be used to create text for empty
cells.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_SetDefaultCellOrientation =R"doc(Change the default orientation which will be used by cells that don't
have a specific orientation set.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetDefaultCellOrientation =R"doc(Get the default orientation which will be used by cells that don't
have a specific orientation set.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_SetDefaultCellAlignment =R"doc(Change the default alignment which will be used by cells that don't
have a specific alignment set.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetDefaultCellAlignment =R"doc(Get the default alignment which will be used by cells that don't have
a specific alignment set.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_SetDefaultTextWeight =R"doc(Change the default weight which will be used for text that doesn't
have a specific weight set. Use ClearDefaultTextWeight to remove this
value.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetDefaultTextWeight =R"doc(Get the default weight which will be used for text that doesn't have a
specific weight set.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_SetDefaultTextColor =R"doc(Change the default color which will be used for text that doesn't have
a specific color set. Use ClearDefaultTextColor to remove this value.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetDefaultTextColor =R"doc(Get the default color which will be used for text that doesn't have a
specific color set.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_SetDefaultLineWeight =R"doc(Change the default line weight which will be used by edge lines that
don't have a specific weight set.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetDefaultLineWeight =R"doc(Get the default line weight which will be used by edge lines that
don't have a specific weight set.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_SetDefaultLineStyle =R"doc(Change the default line style which will be used by edge lines that
don't have a specific style set.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetDefaultLineStyle =R"doc(Get the default line style which will be used by edge lines that don't
have a specific style set.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_SetDefaultLineColor =R"doc(Change the default line color which will be used by edge lines that
don't have a specific color set.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetDefaultLineColor =R"doc(Get the default line color which will be used by edge lines that don't
have a specific color set.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_SetDefaultMargins =R"doc(Change the default cell margins in UORs which will be used by cells
that don't have specific margins set.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetDefaultMargins =R"doc(Get the default cell margins in UORs which will be used by cells that
don't have specific margins set.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_SetDefaultRowHeight =R"doc(Change the default row height in UORs which will be used by rows that
don't have a specific height set.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetDefaultRowHeight =R"doc(Get the default row height in UORs which will be used by rows that
don't have a specific height set.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_SetDefaultColumnWidth =R"doc(Change the default column width in UORs which will be used by columns
that don't have a specific width set.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetDefaultColumnWidth =R"doc(Get the default column width in UORs which will be used by columns
that don't have a specific width set.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_SetRepeatFooters =R"doc(Change the flag defining if footer rows will be repeated in sub tables
created by breaking.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetRepeatFooters =R"doc(Get the flag defining if footer rows will be repeated in sub tables
created by breaking.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_SetRepeatHeaders =R"doc(Change the flag defining if header rows will be repeated in sub tables
created by breaking.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetRepeatHeaders =R"doc(Get the flag defining if header rows will be repeated in sub tables
created by breaking.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_SetBreakGap =R"doc(Change the break gap in UORs for this table. This controlls the
spacing between subtables.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetBreakGap =R"doc(Get the break gap in UORs for this table. This controlls the spacing
between subtables.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_SetBreakLength =R"doc(Change the break length in UORs for this table. Any cells that don't
fit within this length will flow into a new subtable.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetBreakLength =R"doc(Get the break length in UORs for this table. Any cells that don't fit
within this length will flow into a new subtable.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_SetBreakPosition =R"doc(Change the break position for this table.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetBreakPosition =R"doc(Get the break position for this table.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_SetBreakType =R"doc(Change the break type of this table.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetBreakType =R"doc(Get the break type of this table.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetFooterColumnCount =R"doc(Get the number of footer columns in this table.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetHeaderColumnCount =R"doc(Get the number of header columns in this table.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetSummaryRowCount =R"doc(Get the number of summary rows in this table.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetFooterRowCount =R"doc(Get the number of footer rows in this table.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetHeaderRowCount =R"doc(Get the number of header rows in this table.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetTitleRowCount =R"doc(Get the number of title rows in this table.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_SetRotation =R"doc(Change the rotation which defines the orientation of this table.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetRotation =R"doc(Get the rotation which defines the orientation of this table.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_SetOrigin =R"doc(Change the origin which is the upper left corner of cell 0,0.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetOrigin =R"doc(Get the origin which is the upper left corner of cell 0,0.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetColumnCount =R"doc(Get the number of columns in this table.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetRowCount =R"doc(Get the number of rows in this table.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_GetModel =R"doc(Get the model used as context for this table.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTable_Copy =R"doc(Creates a duplicate of this table.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableColumn_SetHeaderFooterType =R"doc(Set the type of this column. The column's type controls the default
TextStyle for the column's cells. TableHeaderFooterType::Title is not
supported for columns. The type cannot by set to an arbitrary value.
The following rules apply:- All header columns must occur before all
columns of any other type. - All body columns must occur after all
header columns but before all footer columns. - All footer columns
must occur after all columns of any other type.

Parameter ``type``:
    IN new type

Returns:
    ERROR if the type could not be set. See the rules above.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableColumn_GetHeaderFooterType =R"doc(Get the type of this column. The column's type controls the default
TextStyle for the column's cells. TableHeaderFooterType::Title is not
supported for columns.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableColumn_SetWidthFromContents =R"doc(Shrink the width of this column to fit the current contents of the
cells. The width lock will be set to false for this column. See
TextTableColumn::GetWidthLock.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableColumn_ComputeMinimumWidth =R"doc(Compute the minimum width possible for this column given the content
of its cells.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableColumn_SetWidth =R"doc(Change the width of this column. The column width cannot be made
smaller than the width of the largest content including margins. The
width lock will be set to true for this column. See
TextTableColumn::GetWidthLock.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableColumn_GetWidth =R"doc(Get the width of this column in UORs.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableColumn_GetWidthLock =R"doc(Get the value of this column's width lock. When the lock is false, the
column's width will grow or shrink. When the lock is true, the
column's width will never change.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableColumn_GetIndex =R"doc(Get the unique index that represents this column.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableRow_SetHeaderFooterType =R"doc(Set the type of this row. The row's type controls the default
TextStyle for the row's cells. The type cannot by set to an arbitrary
value. The following rules apply:- All title rows must occur before
all rows of any other type. - All header rows must occur after all
title rows but before all rows of any other type. - All body rows must
occur after all title and header rows but before all footer rows. -
All footer rows must occur after all rows of any other type.

Parameter ``type``:
    IN new type

Returns:
    ERROR if the type could not be set. See the rules above.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableRow_GetHeaderFooterType =R"doc(Get the type of this row. The row's type controls the default
TextStyle for the row's cells.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableRow_SetHeightFromContents =R"doc(Shrink the height of this row to fit the current contents of the
cells. The height lock will be set to false for this row. See
TextTableRow::GetHeightLock.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableRow_ComputeMinimumHeight =R"doc(Compute the minimum height possible for this row given the content of
its cells.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableRow_SetHeight =R"doc(Change the height of this row. The row height cannot be made smaller
than the height of the largest content including margins. The height
lock will be set to true for this row. See
TextTableRow::GetHeightLock.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableRow_GetHeight =R"doc(Get the height of this row in UORs.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableRow_GetHeightLock =R"doc(Get the value of this row's height lock. When the lock is false, the
row's height will grow or shrink. When the lock is true, the row's
height will never change.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableRow_GetIndex =R"doc(Get the unique index that represents this row.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableCell_Unmerge =R"doc(Change this cell to span only a single row and a single column.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableCell_GetEdgeSymbology =R"doc(Get a list of symbologies used to display the edges of this cell. Note
that for a merged cell it is possible for even a single edge to return
multiple symbologies. For example, consider a cell that spans two
columns. That cell's Top edge may have two different symbologies. This
method is similiar to TextTable::GetEdgeSymbology except that it only
works on one cell.

Parameter ``symb``:
    OUT List of unique symbologies on the requested edges of this
    cell.

Parameter ``edges``:
    IN Edges from which to report. Interior, InteriorHorizontal and
    InteriorVertical are ignored.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableCell_GetFillSymbology =R"doc(Get the fill override property stored on this cell. If the cell
doesn't store an override its displayed fill will be based on the
default behavior of its row. See TextTable::GetDefaultFill.

Parameter ``symb``:
    OUT if (false == symb.HasFillVisible) this cell uses its row's
    default fill. Otherwise use symb.GetFillVisible and
    symb.GetFillColor to get the cell's fill override.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableCell_GetColumnSpan =R"doc(Get the number of columns spanned by this cell. Typically each cell
only spans a single column but the cell merging feature allows a cell
to span multiple. See TextTable::MergeCells.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableCell_GetRowSpan =R"doc(Get the number of rows spanned by this cell. Typically each cell only
spans a single row but the cell merging feature allows a cell to span
multiple. See TextTable::MergeCells.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableCell_CreateEmptyTextBlock =R"doc(Returns an empty TextBlock that is set up with the default formatting
options for this cell.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableCell_SetTextString =R"doc(Specify a text string to be displayed in this cell using the default
formatting options for this cell. Will replace the existing contents
of this cell.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableCell_SetTextBlock =R"doc(Specify text to be displayed in this cell. It can be useful to call
TextTableCell::CreateEmptyTextBlock to start building the text based
on the default formatting options. Will replace the existing contents
of this cell.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableCell_ClearContents =R"doc(Delete the contents of this cell.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableCell_SetFillSymbology =R"doc(Set or remove a uniform color fill for this cell. The options set by
this method will override the default fill behavior dictated by the
table. See TextTable::GetDefaultFill. To set a particular color call
symb.SetFillColor before calling SetFill. To turn off fill for this
cell call symb.SetFillVisible(false) before calling SetFill.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableCell_GetSize =R"doc(Get the size of this cell in UORs. The x,y coordinates of the returned
value represent the horizontal and vertical sizes of the cell in the
table's coordinate system. The size is determined by the hosting rows
and columns and cannot be controlled for individual cells.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableCell_SetMargins =R"doc(Change the margins stored in this cell. The margins control the
minimum gap between a cell's contents and its edges.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableCell_GetMargins =R"doc(Get the margins stored in this cell. The margins control the minimum
gap between a cell's contents and its edges.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableCell_SetOrientation =R"doc(Change the orientation stored in this cell. The orientation controls
the rotation of the contents within the cell.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableCell_GetOrientation =R"doc(Get the orientation stored in this cell. The orientation controls the
rotation of the contents within the cell.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableCell_SetAlignment =R"doc(Change the alignment stored in this cell. The alignment controls the
position of the contents within the cell.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableCell_GetAlignment =R"doc(Get the alignment stored in this cell. The alignment controls the
position of the contents within the cell.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableCell_IsEmpty =R"doc(Returns true if the cell has no contents.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableCell_GetTextBlock =R"doc(Get the TextBlock stored in this cell. May be NULL. Do not modify this
TextBlock. To change it, call TextBlock::Clone and then
TextTableCell::SetTextBlock.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableCell_GetTableRegion =R"doc(Get the TextTableRegion that hosts this cell. The region is determined
by the TableHeaderFooterType of the cell's row and column. It cannot
be controlled for individual cells.)doc";

static const char * __doc_Bentley_DgnPlatform_TextTableCell_GetIndex =R"doc(Get the unique TableCellIndex that represents this cell.)doc";

static const char * __doc_Bentley_DgnPlatform_TableSymbologyValues_SetFillColor =R"doc(Set the fill color value.)doc";

static const char * __doc_Bentley_DgnPlatform_TableSymbologyValues_GetFillColor =R"doc(Get the fill color value.)doc";

static const char * __doc_Bentley_DgnPlatform_TableSymbologyValues_SetFillVisible =R"doc(Set the value of the fill visibility flag.)doc";

static const char * __doc_Bentley_DgnPlatform_TableSymbologyValues_GetFillVisible =R"doc(Get the value of the fill visibility flag.)doc";

static const char * __doc_Bentley_DgnPlatform_TableSymbologyValues_SetLineWeight =R"doc(Set the weight value.)doc";

static const char * __doc_Bentley_DgnPlatform_TableSymbologyValues_GetLineWeight =R"doc(Get the line weight value.)doc";

static const char * __doc_Bentley_DgnPlatform_TableSymbologyValues_SetLineStyle =R"doc(Set the line style value.)doc";

static const char * __doc_Bentley_DgnPlatform_TableSymbologyValues_GetLineStyle =R"doc(Get the line style value.)doc";

static const char * __doc_Bentley_DgnPlatform_TableSymbologyValues_SetLineColor =R"doc(Set the color value.)doc";

static const char * __doc_Bentley_DgnPlatform_TableSymbologyValues_GetLineColor =R"doc(Get the line color value.)doc";

static const char * __doc_Bentley_DgnPlatform_TableSymbologyValues_SetLineVisible =R"doc(Set the value of the line visibility flag.)doc";

static const char * __doc_Bentley_DgnPlatform_TableSymbologyValues_GetLineVisible =R"doc(Get the value of the line visibility flag.)doc";

static const char * __doc_Bentley_DgnPlatform_TableSymbologyValues_HasFillColor =R"doc(Test if this object specifies a fill color value.)doc";

static const char * __doc_Bentley_DgnPlatform_TableSymbologyValues_HasFillVisible =R"doc(Test if this object specifies a fill visibility flag.)doc";

static const char * __doc_Bentley_DgnPlatform_TableSymbologyValues_HasLineWeight =R"doc(Test if this object specifies a line weight value.)doc";

static const char * __doc_Bentley_DgnPlatform_TableSymbologyValues_HasLineStyle =R"doc(Test if this object specifies a line style value.)doc";

static const char * __doc_Bentley_DgnPlatform_TableSymbologyValues_HasLineColor =R"doc(Test if this object specifies a line color value.)doc";

static const char * __doc_Bentley_DgnPlatform_TableSymbologyValues_HasLineVisible =R"doc(Test if this object specifies a line visibility flag.)doc";

static const char * __doc_Bentley_DgnPlatform_TableTextPartId_Create =R"doc(Create a new part id for a specified cell.)doc";

static const char * __doc_Bentley_DgnPlatform_TableTextPartId_GetCellIndex =R"doc(Extract the cell index.)doc";

static const char * __doc_Bentley_DgnPlatform_TableCellIndex_ColumnIndexFromString =R"doc(Get the cell index value from a string.
Returns (Tuple, 0):
	retVal.

Returns (Tuple, 1):
	colIndex.

)doc";

static const char * __doc_Bentley_DgnPlatform_TableCellIndex_RowIndexFromString =R"doc(Get the row index value from a string.
Returns (Tuple, 0):
	retVal.

Returns (Tuple, 1):
	rowIndex.

)doc";

static const char * __doc_Bentley_DgnPlatform_TableCellIndex_StringFromColumnIndex =R"doc(Create a string representation for a column index.)doc";

static const char * __doc_Bentley_DgnPlatform_TableCellIndex_StringFromRowIndex =R"doc(Create a string representation for a row index.)doc";

static const char * __doc_Bentley_DgnPlatform_TableCellIndex_FromString =R"doc(Initialize an index from a string in the format generated by ToString.)doc";

static const char * __doc_Bentley_DgnPlatform_TableCellIndex_ToString =R"doc(Create a string representation of the index.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_TextTableHandler(py::module_& m)
    {
    //===================================================================================
    // struct TableCellIndex
    py::class_< TableCellIndex> c1(m, "TableCellIndex");
    py::bind_vector< bvector<TableCellIndex> >(m, "TableCellIndexArray", py::module_local(false));

    c1.def_readwrite("rowId", &TableCellIndex::row);
    c1.def_readwrite("colId", &TableCellIndex::col);
    c1.def(py::init<>());
    c1.def(py::init<UInt32,UInt32>(), "row"_a, "col"_a);
    c1.def(py::self > py::self);
    c1.def(py::self < py::self);
    c1.def(py::self >= py::self);
    c1.def(py::self <= py::self);
    c1.def(py::self == py::self);
    c1.def(py::self != py::self);
    c1.def("ToString", &TableCellIndex::ToString, DOC(Bentley, DgnPlatform, TableCellIndex, ToString));
    c1.def_static("FromString", &TableCellIndex::FromString, "cellIndex"_a, "indexString"_a, DOC(Bentley, DgnPlatform, TableCellIndex, FromString));
    c1.def_static("StringFromRowIndex", &TableCellIndex::StringFromRowIndex, "rowIndex"_a, DOC(Bentley, DgnPlatform, TableCellIndex, StringFromRowIndex));
    c1.def_static("StringFromColumnIndex", &TableCellIndex::StringFromColumnIndex, "colIndex"_a, DOC(Bentley, DgnPlatform, TableCellIndex, StringFromColumnIndex));
    
    c1.def_static("RowIndexFromString", [] (WCharCP rowIndexString)
                  {
                  UInt32 rowIndex = 0;
                  auto retVal = TableCellIndex::RowIndexFromString(rowIndex, rowIndexString);
                  return py::make_tuple(retVal, rowIndex);
                  }, "rowIndexString"_a, DOC(Bentley, DgnPlatform, TableCellIndex, RowIndexFromString));

    c1.def_static("ColumnIndexFromString", [] (WCharCP colIndexString)
                  {
                  UInt32 colIndex = 0;
                  auto retVal = TableCellIndex::ColumnIndexFromString(colIndex, colIndexString);
                  return py::make_tuple(retVal, colIndex);
                  }, "colIndexString"_a, DOC(Bentley, DgnPlatform, TableCellIndex, ColumnIndexFromString));

    //===================================================================================
    // enum class TextTableRegion
    py::enum_< TextTableRegion>(m, "TextTableRegion")
        .value("eBody", TextTableRegion::Body)
        .value("eTitleRow", TextTableRegion::TitleRow)
        .value("eHeaderRow", TextTableRegion::HeaderRow)
        .value("eSummaryRow", TextTableRegion::SummaryRow)
        .value("eFooterRow", TextTableRegion::FooterRow)
        .value("eHeaderColumn", TextTableRegion::HeaderColumn)
        .value("eFooterColumn", TextTableRegion::FooterColumn)
        .export_values();

    //===================================================================================
    // enum class TableInsertDirection
    py::enum_< TableInsertDirection>(m, "TableInsertDirection")
        .value("eBefore", TableInsertDirection::Before)
        .value("eAfter", TableInsertDirection::After)
        .export_values();

    //===================================================================================
    // enum class TableBreakType
    py::enum_< TableBreakType>(m, "TableBreakType")
        .value("eNone", TableBreakType::None)
        .value("eHorizontal", TableBreakType::Horizontal)
        .value("eVertical", TableBreakType::Vertical)
        .export_values();

    //===================================================================================
    // enum class TableBreakPosition
    py::enum_< TableBreakPosition>(m, "TableBreakPosition")
        .value("eRight", TableBreakPosition::Right)
        .value("eLeft", TableBreakPosition::Left)
        .value("eAbove", TableBreakPosition::Above)
        .value("eBelow", TableBreakPosition::Below)
        .value("eManual", TableBreakPosition::Manual)
        .export_values();

    //===================================================================================
    // enum class TableCellAlignment
    py::enum_< TableCellAlignment>(m, "TableCellAlignment")
        .value("eLeftTop", TableCellAlignment::LeftTop)
        .value("eLeftMiddle", TableCellAlignment::LeftMiddle)
        .value("eLeftBottom", TableCellAlignment::LeftBottom)
        .value("eCenterTop", TableCellAlignment::CenterTop)
        .value("eCenterMiddle", TableCellAlignment::CenterMiddle)
        .value("eCenterBottom", TableCellAlignment::CenterBottom)
        .value("eRightTop", TableCellAlignment::RightTop)
        .value("eRightMiddle", TableCellAlignment::RightMiddle)
        .value("eRightBottom", TableCellAlignment::RightBottom)
        .export_values();

    //===================================================================================
    // enum class TableCellOrientation
    py::enum_< TableCellOrientation>(m, "TableCellOrientation")
        .value("eHorizontal", TableCellOrientation::Horizontal)
        .value("eRotate90", TableCellOrientation::Rotate90)
        .value("eRotate270", TableCellOrientation::Rotate270)
        .value("eVertical", TableCellOrientation::Vertical)
        .export_values();

    //===================================================================================
    // enum class TableHeaderFooterType
    py::enum_< TableHeaderFooterType>(m, "TableHeaderFooterType")
        .value("eTitle", TableHeaderFooterType::Title)
        .value("eHeader", TableHeaderFooterType::Header)
        .value("eBody", TableHeaderFooterType::Body)
        .value("eSummary", TableHeaderFooterType::Summary)
        .value("eFooter", TableHeaderFooterType::Footer)
        .export_values();

    //===================================================================================
    // enum class TableCellListEdges
    py::enum_< TableCellListEdges>(m, "TableCellListEdges")
        .value("eTop", TableCellListEdges::Top)
        .value("eBottom", TableCellListEdges::Bottom)
        .value("eLeft", TableCellListEdges::Left)
        .value("eRight", TableCellListEdges::Right)
        .value("eInterior", TableCellListEdges::Interior)
        .value("eExterior", TableCellListEdges::Exterior)
        .value("eInteriorHorizontal", TableCellListEdges::InteriorHorizontal)
        .value("eInteriorVertical", TableCellListEdges::InteriorVertical)
        .value("eAll", TableCellListEdges::All)
        .export_values();

    //===================================================================================
    // enum class TableRows
    py::enum_< TableRows>(m, "TableRows")
        .value("eOdd", TableRows::Odd)
        .value("eEven", TableRows::Even)
        .value("eAll", TableRows::All)
        .export_values();

    //===================================================================================
    // struct TableCellMarginValues
    py::class_< TableCellMarginValues> c2(m, "TableCellMarginValues");

    c2.def_readwrite("top", &TableCellMarginValues::m_top);
    c2.def_readwrite("bottom", &TableCellMarginValues::m_bottom);
    c2.def_readwrite("left", &TableCellMarginValues::m_left);
    c2.def_readwrite("right", &TableCellMarginValues::m_right);

    //===================================================================================
    // struct TableTextPartId
    py::class_< TableTextPartId, RefCountedPtr<TableTextPartId>, ITextPartId> c3(m, "TableTextPartId");

    c3.def_property_readonly("CellIndex", &TableTextPartId::GetCellIndex);
    c3.def("GetCellIndex", &TableTextPartId::GetCellIndex, DOC(Bentley, DgnPlatform, TableTextPartId, GetCellIndex));
    c3.def_static("Create", &TableTextPartId::Create, "cellIndex"_a, DOC(Bentley, DgnPlatform, TableTextPartId, Create));

    //===================================================================================
    // struct TableSymbologyValues
    py::class_< TableSymbologyValues, TableSymbologyValuesPtr> c4(m, "TableSymbologyValues");
    py::bind_vector< bvector<TableSymbologyValuesPtr> >(m, "TableSymbologyValuesPtrArray", py::module_local(false));

    c4.def("HasLineVisible", &TableSymbologyValues::HasLineVisible, DOC(Bentley, DgnPlatform, TableSymbologyValues, HasLineVisible));
    c4.def("HasLineColor", &TableSymbologyValues::HasLineColor, DOC(Bentley, DgnPlatform, TableSymbologyValues, HasLineColor));
    c4.def("HasLineStyle", &TableSymbologyValues::HasLineStyle, DOC(Bentley, DgnPlatform, TableSymbologyValues, HasLineStyle));
    c4.def("HasLineWeight", &TableSymbologyValues::HasLineWeight, DOC(Bentley, DgnPlatform, TableSymbologyValues, HasLineWeight));
    c4.def("HasFillVisible", &TableSymbologyValues::HasFillVisible, DOC(Bentley, DgnPlatform, TableSymbologyValues, HasFillVisible));
    c4.def("HasFillColor", &TableSymbologyValues::HasFillColor, DOC(Bentley, DgnPlatform, TableSymbologyValues, HasFillColor));

    c4.def_property("LineVisible", &TableSymbologyValues::GetLineVisible, &TableSymbologyValues::SetLineVisible);
    c4.def("GetLineVisible", &TableSymbologyValues::GetLineVisible, DOC(Bentley, DgnPlatform, TableSymbologyValues, GetLineVisible));
    c4.def("SetLineVisible", &TableSymbologyValues::SetLineVisible, "visible"_a, DOC(Bentley, DgnPlatform, TableSymbologyValues, SetLineVisible));
    
    c4.def_property("LineColor", &TableSymbologyValues::GetLineColor, &TableSymbologyValues::SetLineColor);
    c4.def("GetLineColor", &TableSymbologyValues::GetLineColor, DOC(Bentley, DgnPlatform, TableSymbologyValues, GetLineColor));
    c4.def("SetLineColor", &TableSymbologyValues::SetLineColor, "lineColor"_a, DOC(Bentley, DgnPlatform, TableSymbologyValues, SetLineColor));
    
    c4.def_property("LineStyle", &TableSymbologyValues::GetLineStyle, &TableSymbologyValues::SetLineStyle);
    c4.def("GetLineStyle", &TableSymbologyValues::GetLineStyle, DOC(Bentley, DgnPlatform, TableSymbologyValues, GetLineStyle));
    c4.def("SetLineStyle", &TableSymbologyValues::SetLineStyle, "lineStyle"_a, DOC(Bentley, DgnPlatform, TableSymbologyValues, SetLineStyle));
    
    c4.def_property("LineWeight", &TableSymbologyValues::GetLineWeight, &TableSymbologyValues::SetLineWeight);
    c4.def("GetLineWeight", &TableSymbologyValues::GetLineWeight, DOC(Bentley, DgnPlatform, TableSymbologyValues, GetLineWeight));
    c4.def("SetLineWeight", &TableSymbologyValues::SetLineWeight, "lineWeight"_a, DOC(Bentley, DgnPlatform, TableSymbologyValues, SetLineWeight));
    
    c4.def_property("FillVisible", &TableSymbologyValues::GetFillVisible, &TableSymbologyValues::SetFillVisible);
    c4.def("GetFillVisible", &TableSymbologyValues::GetFillVisible, DOC(Bentley, DgnPlatform, TableSymbologyValues, GetFillVisible));
    c4.def("SetFillVisible", &TableSymbologyValues::SetFillVisible, "fillVisible"_a, DOC(Bentley, DgnPlatform, TableSymbologyValues, SetFillVisible));
    
    c4.def_property("FillColor", &TableSymbologyValues::GetFillColor, &TableSymbologyValues::SetFillColor);
    c4.def("GetFillColor", &TableSymbologyValues::GetFillColor, DOC(Bentley, DgnPlatform, TableSymbologyValues, GetFillColor));
    c4.def("SetFillColor", &TableSymbologyValues::SetFillColor, "fillColor"_a, DOC(Bentley, DgnPlatform, TableSymbologyValues, SetFillColor));

    c4.def(py::init(&TableSymbologyValues::Create));

    //py::class_< TextTableCellIterator, std::unique_ptr<TextTableCellIterator, py::nodelete>> c100(m, "TextTableCellIterator");

    //===================================================================================
    // struct TextTableCell
    py::class_< TextTableCell, std::unique_ptr<TextTableCell, py::nodelete>> c5(m, "TextTableCell");

    c5.def_property_readonly("Index", &TextTableCell::GetIndex);
    c5.def("GetIndex", &TextTableCell::GetIndex, DOC(Bentley, DgnPlatform, TextTableCell, GetIndex));
    
    c5.def_property_readonly("TableRegion", &TextTableCell::GetTableRegion);
    c5.def("GetTableRegion", &TextTableCell::GetTableRegion, DOC(Bentley, DgnPlatform, TextTableCell, GetTableRegion));
    
    c5.def_property_readonly("TextBlock", &TextTableCell::GetTextBlock);
    c5.def("GetTextBlock", &TextTableCell::GetTextBlock, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, TextTableCell, GetTextBlock));
    
    c5.def("IsEmpty", &TextTableCell::IsEmpty, DOC(Bentley, DgnPlatform, TextTableCell, IsEmpty));

    c5.def_property("Alignment", &TextTableCell::GetAlignment, &TextTableCell::SetAlignment);
    c5.def("GetAlignment", &TextTableCell::GetAlignment, DOC(Bentley, DgnPlatform, TextTableCell, GetAlignment));
    c5.def("SetAlignment", &TextTableCell::SetAlignment, "alignment"_a, DOC(Bentley, DgnPlatform, TextTableCell, SetAlignment));
    
    c5.def_property("Orientation", &TextTableCell::GetOrientation, &TextTableCell::SetOrientation);
    c5.def("GetOrientation", &TextTableCell::GetOrientation, DOC(Bentley, DgnPlatform, TextTableCell, GetOrientation));
    c5.def("SetOrientation", &TextTableCell::SetOrientation, "orientation"_a, DOC(Bentley, DgnPlatform, TextTableCell, SetOrientation));
    
    c5.def_property("Margins", &TextTableCell::GetMargins, &TextTableCell::SetMargins);
    c5.def("GetMargins", &TextTableCell::GetMargins, DOC(Bentley, DgnPlatform, TextTableCell, GetMargins));
    c5.def("SetMargins", &TextTableCell::SetMargins, "margin"_a, DOC(Bentley, DgnPlatform, TextTableCell, SetMargins));

    c5.def_property_readonly("Size", &TextTableCell::GetSize);
    c5.def("GetSize", &TextTableCell::GetSize, DOC(Bentley, DgnPlatform, TextTableCell, GetSize));

    c5.def("SetFillSymbology", &TextTableCell::SetFillSymbology, "symb"_a, DOC(Bentley, DgnPlatform, TextTableCell, SetFillSymbology));
    c5.def("ClearContents", &TextTableCell::ClearContents, DOC(Bentley, DgnPlatform, TextTableCell, ClearContents));
    c5.def("SetTextBlock", &TextTableCell::SetTextBlock, "textBlock"_a, "needResize"_a = true, DOC(Bentley, DgnPlatform, TextTableCell, SetTextBlock));
    c5.def("SetTextString", &TextTableCell::SetTextString, "textString"_a, DOC(Bentley, DgnPlatform, TextTableCell, SetTextString));
    c5.def("CreateEmptyTextBlock", &TextTableCell::CreateEmptyTextBlock, DOC(Bentley, DgnPlatform, TextTableCell, CreateEmptyTextBlock));
    
    c5.def_property_readonly("RowSpan", &TextTableCell::GetRowSpan);
    c5.def("GetRowSpan", &TextTableCell::GetRowSpan, DOC(Bentley, DgnPlatform, TextTableCell, GetRowSpan));
    
    c5.def_property_readonly("ColumnSpan", &TextTableCell::GetColumnSpan);
    c5.def("GetColumnSpan", &TextTableCell::GetColumnSpan, DOC(Bentley, DgnPlatform, TextTableCell, GetColumnSpan));
    
    c5.def("GetFillSymbology", &TextTableCell::GetFillSymbology, "symb"_a, DOC(Bentley, DgnPlatform, TextTableCell, GetFillSymbology));
    c5.def("GetEdgeSymbology", &TextTableCell::GetEdgeSymbology, "symbs"_a, "edges"_a, DOC(Bentley, DgnPlatform, TextTableCell, GetEdgeSymbology));
    c5.def("Unmerge", &TextTableCell::Unmerge, DOC(Bentley, DgnPlatform, TextTableCell, Unmerge));

    //===================================================================================
    // struct TextTableRow
    py::class_< TextTableRow, std::unique_ptr<TextTableRow, py::nodelete>> c6(m, "TextTableRow");

    c6.def_property_readonly("Index", &TextTableRow::GetIndex);
    c6.def("GetIndex", &TextTableRow::GetIndex, DOC(Bentley, DgnPlatform, TextTableRow, GetIndex));
    
    c6.def_property_readonly("HeightLock", &TextTableRow::GetHeightLock);
    c6.def("GetHeightLock", &TextTableRow::GetHeightLock, DOC(Bentley, DgnPlatform, TextTableRow, GetHeightLock));
    
    c6.def_property("Height", &TextTableRow::GetHeight, py::overload_cast<double>(&TextTableRow::SetHeight));
    c6.def("GetHeight", &TextTableRow::GetHeight, DOC(Bentley, DgnPlatform, TextTableRow, GetHeight));
    c6.def("SetHeight", py::overload_cast<double>(&TextTableRow::SetHeight), "height"_a, DOC(Bentley, DgnPlatform, TextTableRow, SetHeight));
    
    c6.def("ComputeMinimumHeight", &TextTableRow::ComputeMinimumHeight, DOC(Bentley, DgnPlatform, TextTableRow, ComputeMinimumHeight));
    c6.def("SetHeightFromContents", py::overload_cast<>(&TextTableRow::SetHeightFromContents), DOC(Bentley, DgnPlatform, TextTableRow, SetHeightFromContents));
    
    c6.def_property("HeaderFooterType", &TextTableRow::GetHeaderFooterType, &TextTableRow::SetHeaderFooterType);
    c6.def("GetHeaderFooterType", &TextTableRow::GetHeaderFooterType, DOC(Bentley, DgnPlatform, TextTableRow, GetHeaderFooterType));
    c6.def("SetHeaderFooterType", &TextTableRow::SetHeaderFooterType, "type"_a, DOC(Bentley, DgnPlatform, TextTableRow, SetHeaderFooterType));

    //===================================================================================
    // struct TextTableColumn
    py::class_< TextTableColumn, std::unique_ptr<TextTableColumn, py::nodelete>> c7(m, "TextTableColumn");

    c7.def_property_readonly("Index", &TextTableColumn::GetIndex);
    c7.def("GetIndex", &TextTableColumn::GetIndex, DOC(Bentley, DgnPlatform, TextTableColumn, GetIndex));
    
    c7.def_property_readonly("WidthLock", &TextTableColumn::GetWidthLock);
    c7.def("GetWidthLock", &TextTableColumn::GetWidthLock, DOC(Bentley, DgnPlatform, TextTableColumn, GetWidthLock));
    
    c7.def_property("Width", &TextTableColumn::GetWidth, py::overload_cast<double>(&TextTableColumn::SetWidth));
    c7.def("GetWidth", &TextTableColumn::GetWidth, DOC(Bentley, DgnPlatform, TextTableColumn, GetWidth));
    c7.def("SetWidth", py::overload_cast<double>(&TextTableColumn::SetWidth), "width"_a, DOC(Bentley, DgnPlatform, TextTableColumn, SetWidth));
    
    c7.def("ComputeMinimumWidth", &TextTableColumn::ComputeMinimumWidth, DOC(Bentley, DgnPlatform, TextTableColumn, ComputeMinimumWidth));
    c7.def("SetWidthFromContents", py::overload_cast<>(&TextTableColumn::SetWidthFromContents), DOC(Bentley, DgnPlatform, TextTableColumn, SetWidthFromContents));
    
    c7.def_property("HeaderFooterType", &TextTableColumn::GetHeaderFooterType, &TextTableColumn::SetHeaderFooterType);
    c7.def("GetHeaderFooterType", &TextTableColumn::GetHeaderFooterType, DOC(Bentley, DgnPlatform, TextTableColumn, GetHeaderFooterType));
    c7.def("SetHeaderFooterType", &TextTableColumn::SetHeaderFooterType, "type"_a, DOC(Bentley, DgnPlatform, TextTableColumn, SetHeaderFooterType));

    //===================================================================================
    // struct TextTableCellCollection
    py::class_< TextTableCellCollection> c8(m, "TextTableCellCollection");

    //c8.def("__iter__", [] (TextTableCellCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

    //===================================================================================
    // struct TextTable
    py::class_< TextTable, TextTablePtr> c9(m, "TextTable");

    c9.def("Copy", &TextTable::Copy, "modelForCopy"_a, DOC(Bentley, DgnPlatform, TextTable, Copy));
    
    c9.def_property_readonly("Model", &TextTable::GetModel);
    c9.def("GetModel", &TextTable::GetModel, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, TextTable, GetModel));
    
    c9.def_property_readonly("RowCount", &TextTable::GetRowCount);
    c9.def("GetRowCount", &TextTable::GetRowCount, DOC(Bentley, DgnPlatform, TextTable, GetRowCount));
    
    c9.def_property_readonly("ColumnCount", &TextTable::GetColumnCount);
    c9.def("GetColumnCount", &TextTable::GetColumnCount, DOC(Bentley, DgnPlatform, TextTable, GetColumnCount));
    
    c9.def_property("Origin", &TextTable::GetOrigin, &TextTable::SetOrigin);
    c9.def("GetOrigin", &TextTable::GetOrigin, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, TextTable, GetOrigin));
    c9.def("SetOrigin", &TextTable::SetOrigin, "origin"_a, DOC(Bentley, DgnPlatform, TextTable, SetOrigin));
    
    c9.def_property("Rotation", &TextTable::GetRotation, &TextTable::SetRotation);
    c9.def("GetRotation", &TextTable::GetRotation, DOC(Bentley, DgnPlatform, TextTable, GetRotation));
    c9.def("SetRotation", &TextTable::SetRotation, "rotMatrix"_a, DOC(Bentley, DgnPlatform, TextTable, SetRotation));
    
    c9.def_property_readonly("TitleRowCount", &TextTable::GetTitleRowCount);
    c9.def("GetTitleRowCount", &TextTable::GetTitleRowCount, DOC(Bentley, DgnPlatform, TextTable, GetTitleRowCount));
    
    c9.def_property_readonly("HeaderRowCount", &TextTable::GetHeaderRowCount);
    c9.def("GetHeaderRowCount", &TextTable::GetHeaderRowCount, DOC(Bentley, DgnPlatform, TextTable, GetHeaderRowCount));
    
    c9.def_property_readonly("FooterRowCount", &TextTable::GetFooterRowCount);
    c9.def("GetFooterRowCount", &TextTable::GetFooterRowCount, DOC(Bentley, DgnPlatform, TextTable, GetFooterRowCount));
    
    c9.def_property_readonly("SummaryRowCount", &TextTable::GetSummaryRowCount);
    c9.def("GetSummaryRowCount", &TextTable::GetSummaryRowCount, DOC(Bentley, DgnPlatform, TextTable, GetSummaryRowCount));
    
    c9.def_property_readonly("HeaderColumnCount", &TextTable::GetHeaderColumnCount);
    c9.def("GetHeaderColumnCount", &TextTable::GetHeaderColumnCount, DOC(Bentley, DgnPlatform, TextTable, GetHeaderColumnCount));
    
    c9.def_property_readonly("FooterColumnCount", &TextTable::GetFooterColumnCount);
    c9.def("GetFooterColumnCount", &TextTable::GetFooterColumnCount, DOC(Bentley, DgnPlatform, TextTable, GetFooterColumnCount));
    
    c9.def_property("BreakType", &TextTable::GetBreakType, &TextTable::SetBreakType);
    c9.def("GetBreakType", &TextTable::GetBreakType, DOC(Bentley, DgnPlatform, TextTable, GetBreakType));
    c9.def("SetBreakType", &TextTable::SetBreakType, "breakType"_a, DOC(Bentley, DgnPlatform, TextTable, SetBreakType));
    
    c9.def_property("BreakPosition", &TextTable::GetBreakPosition, &TextTable::SetBreakPosition);
    c9.def("GetBreakPosition", &TextTable::GetBreakPosition, DOC(Bentley, DgnPlatform, TextTable, GetBreakPosition));
    c9.def("SetBreakPosition", &TextTable::SetBreakPosition, "breakPosition"_a, DOC(Bentley, DgnPlatform, TextTable, SetBreakPosition));
    
    c9.def_property("BreakLength", &TextTable::GetBreakLength, &TextTable::SetBreakLength);
    c9.def("GetBreakLength", &TextTable::GetBreakLength, DOC(Bentley, DgnPlatform, TextTable, GetBreakLength));
    c9.def("SetBreakLength", &TextTable::SetBreakLength, "breakLength"_a, DOC(Bentley, DgnPlatform, TextTable, SetBreakLength));
    
    c9.def_property("BreakGap", &TextTable::GetBreakGap, &TextTable::SetBreakGap);
    c9.def("GetBreakGap", &TextTable::GetBreakGap, DOC(Bentley, DgnPlatform, TextTable, GetBreakGap));
    c9.def("SetBreakGap", &TextTable::SetBreakGap, "breakGap"_a, DOC(Bentley, DgnPlatform, TextTable, SetBreakGap));
    
    c9.def_property("RepeatHeaders", &TextTable::GetRepeatHeaders, &TextTable::SetRepeatHeaders);
    c9.def("GetRepeatHeaders", &TextTable::GetRepeatHeaders, DOC(Bentley, DgnPlatform, TextTable, GetRepeatHeaders));
    c9.def("SetRepeatHeaders", &TextTable::SetRepeatHeaders, "repeatHeaders"_a, DOC(Bentley, DgnPlatform, TextTable, SetRepeatHeaders));
    
    c9.def_property("RepeatFooters", &TextTable::GetRepeatFooters, &TextTable::SetRepeatFooters);
    c9.def("GetRepeatFooters", &TextTable::GetRepeatFooters, DOC(Bentley, DgnPlatform, TextTable, GetRepeatFooters));
    c9.def("SetRepeatFooters", &TextTable::SetRepeatFooters, "repeatFooters"_a, DOC(Bentley, DgnPlatform, TextTable, SetRepeatFooters));
    
    c9.def_property("DefaultColumnWidth", &TextTable::GetDefaultColumnWidth, &TextTable::SetDefaultColumnWidth);
    c9.def("GetDefaultColumnWidth", &TextTable::GetDefaultColumnWidth, DOC(Bentley, DgnPlatform, TextTable, GetDefaultColumnWidth));
    c9.def("SetDefaultColumnWidth", &TextTable::SetDefaultColumnWidth, "colWidth"_a, DOC(Bentley, DgnPlatform, TextTable, SetDefaultColumnWidth));
    
    c9.def_property("DefaultRowHeight", &TextTable::GetDefaultRowHeight, &TextTable::SetDefaultRowHeight);
    c9.def("GetDefaultRowHeight", &TextTable::GetDefaultRowHeight, DOC(Bentley, DgnPlatform, TextTable, GetDefaultRowHeight));
    c9.def("SetDefaultRowHeight", &TextTable::SetDefaultRowHeight, "rowHeight"_a, DOC(Bentley, DgnPlatform, TextTable, SetDefaultRowHeight));
    
    c9.def_property("DefaultMargins", &TextTable::GetDefaultMargins, &TextTable::SetDefaultMargins);
    c9.def("GetDefaultMargins", &TextTable::GetDefaultMargins, DOC(Bentley, DgnPlatform, TextTable, GetDefaultMargins));
    c9.def("SetDefaultMargins", &TextTable::SetDefaultMargins, "margin"_a, DOC(Bentley, DgnPlatform, TextTable, SetDefaultMargins));
    
    c9.def_property("DefaultLineColor", &TextTable::GetDefaultLineColor, &TextTable::SetDefaultLineColor);
    c9.def("GetDefaultLineColor", &TextTable::GetDefaultLineColor, DOC(Bentley, DgnPlatform, TextTable, GetDefaultLineColor));
    c9.def("SetDefaultLineColor", &TextTable::SetDefaultLineColor, "lineColor"_a, DOC(Bentley, DgnPlatform, TextTable, SetDefaultLineColor));
    
    c9.def_property("DefaultLineStyle", &TextTable::GetDefaultLineStyle, &TextTable::SetDefaultLineStyle);
    c9.def("GetDefaultLineStyle", &TextTable::GetDefaultLineStyle, DOC(Bentley, DgnPlatform, TextTable, GetDefaultLineStyle));
    c9.def("SetDefaultLineStyle", &TextTable::SetDefaultLineStyle, "lineStyle"_a, DOC(Bentley, DgnPlatform, TextTable, SetDefaultLineStyle));
    
    c9.def_property("DefaultLineWeight", &TextTable::GetDefaultLineWeight, &TextTable::SetDefaultLineWeight);
    c9.def("GetDefaultLineWeight", &TextTable::GetDefaultLineWeight, DOC(Bentley, DgnPlatform, TextTable, GetDefaultLineWeight));
    c9.def("SetDefaultLineWeight", &TextTable::SetDefaultLineWeight, "lineWeight"_a, DOC(Bentley, DgnPlatform, TextTable, SetDefaultLineWeight));
    
    c9.def_property("DefaultTextColor", &TextTable::GetDefaultTextColor, &TextTable::SetDefaultTextColor);
    c9.def("GetDefaultTextColor", &TextTable::GetDefaultTextColor, DOC(Bentley, DgnPlatform, TextTable, GetDefaultTextColor));
    c9.def("SetDefaultTextColor", &TextTable::SetDefaultTextColor, "textColor"_a, DOC(Bentley, DgnPlatform, TextTable, SetDefaultTextColor));
    
    c9.def_property("DefaultTextWeight", &TextTable::GetDefaultTextWeight, &TextTable::SetDefaultTextWeight);
    c9.def("GetDefaultTextWeight", &TextTable::GetDefaultTextWeight, DOC(Bentley, DgnPlatform, TextTable, GetDefaultTextWeight));
    c9.def("SetDefaultTextWeight", &TextTable::SetDefaultTextWeight, "textWeight"_a, DOC(Bentley, DgnPlatform, TextTable, SetDefaultTextWeight));
    
    c9.def_property("DefaultCellAlignment", &TextTable::GetDefaultCellAlignment, &TextTable::SetDefaultCellAlignment);
    c9.def("GetDefaultCellAlignment", &TextTable::GetDefaultCellAlignment, DOC(Bentley, DgnPlatform, TextTable, GetDefaultCellAlignment));
    c9.def("SetDefaultCellAlignment", &TextTable::SetDefaultCellAlignment, "alignment"_a, DOC(Bentley, DgnPlatform, TextTable, SetDefaultCellAlignment));
    
    c9.def_property("DefaultCellOrientation", &TextTable::GetDefaultCellOrientation, &TextTable::SetDefaultCellOrientation);
    c9.def("GetDefaultCellOrientation", &TextTable::GetDefaultCellOrientation, DOC(Bentley, DgnPlatform, TextTable, GetDefaultCellOrientation));
    c9.def("SetDefaultCellOrientation", &TextTable::SetDefaultCellOrientation, "orientation"_a, DOC(Bentley, DgnPlatform, TextTable, SetDefaultCellOrientation));
    
    c9.def("GetTextStyleId", &TextTable::GetTextStyleId, "region"_a, DOC(Bentley, DgnPlatform, TextTable, GetTextStyleId));    
    c9.def("GetDefaultFill", &TextTable::GetDefaultFill, "symb"_a, "rows"_a, DOC(Bentley, DgnPlatform, TextTable, GetDefaultFill));
    
    c9.def_property_readonly("Transform", &TextTable::GetTransform);
    c9.def("GetTransform", &TextTable::GetTransform, DOC(Bentley, DgnPlatform, TextTable, GetTransform));
    
    c9.def("HasDefaultTextColor", &TextTable::HasDefaultTextColor, DOC(Bentley, DgnPlatform, TextTable, HasDefaultTextColor));    
    c9.def("HasDefaultTextWeight", &TextTable::HasDefaultTextWeight, DOC(Bentley, DgnPlatform, TextTable, HasDefaultTextWeight));
    
    c9.def("SetTextStyleId", &TextTable::SetTextStyleId, "textStyleId"_a, "region"_a, DOC(Bentley, DgnPlatform, TextTable, SetTextStyleId));
    c9.def("SetDefaultFill", &TextTable::SetDefaultFill, "value"_a, "rows"_a, DOC(Bentley, DgnPlatform, TextTable, SetDefaultFill));
    c9.def("ClearDefaultTextColor", &TextTable::ClearDefaultTextColor, DOC(Bentley, DgnPlatform, TextTable, ClearDefaultTextColor));
    c9.def("ClearDefaultTextWeight", &TextTable::ClearDefaultTextWeight, DOC(Bentley, DgnPlatform, TextTable, ClearDefaultTextWeight));
    c9.def("GetRow", [] (TextTable& self, UInt32 rowIndex) { return std::unique_ptr< TextTableRow, py::nodelete>(self.GetRow(rowIndex)); }, "rowIndex"_a);
    c9.def("GetColumn", [] (TextTable& self, UInt32 colIndex) { return std::unique_ptr< TextTableColumn, py::nodelete>(self.GetColumn(colIndex)); }, "colIndex"_a);
    c9.def("GetCell", [] (TextTable& self, TableCellIndexCR cellIndex) { return std::unique_ptr< TextTableCell, py::nodelete>(self.GetCell(cellIndex)); }, "cellIndex"_a);
    c9.def("InsertRow", &TextTable::InsertRow, "indexOfSeedRow"_a, "dir"_a, DOC(Bentley, DgnPlatform, TextTable, InsertRow));
    c9.def("DeleteRow", &TextTable::DeleteRow, "indexOfOldRow"_a, DOC(Bentley, DgnPlatform, TextTable, DeleteRow));
    c9.def("InsertColumn", &TextTable::InsertColumn, "indexOfSeedColumn"_a, "dir"_a, DOC(Bentley, DgnPlatform, TextTable, InsertColumn));
    c9.def("DeleteColumn", &TextTable::DeleteColumn, "indexOfOldColumn"_a, DOC(Bentley, DgnPlatform, TextTable, DeleteColumn));
    
    c9.def_property_readonly("CellCollection", &TextTable::GetCellCollection);
    c9.def("GetCellCollection", &TextTable::GetCellCollection, DOC(Bentley, DgnPlatform, TextTable, GetCellCollection));
    
    c9.def("MergeCells", &TextTable::MergeCells, "root"_a, "numRows"_a, "numCols"_a, DOC(Bentley, DgnPlatform, TextTable, MergeCells));
    c9.def("GetEdgeSymbology", &TextTable::GetEdgeSymbology, "symbs"_a, "edges"_a, "cells"_a, DOC(Bentley, DgnPlatform, TextTable, GetEdgeSymbology));
    c9.def("SetEdgeSymbology", &TextTable::SetEdgeSymbology, "symb"_a, "edges"_a, "cells"_a, DOC(Bentley, DgnPlatform, TextTable, SetEdgeSymbology));
    
    c9.def_property("Width", &TextTable::GetWidth, &TextTable::SetWidth);
    c9.def("GetWidth", &TextTable::GetWidth, DOC(Bentley, DgnPlatform, TextTable, GetWidth));
    c9.def("SetWidth", &TextTable::SetWidth, "width"_a, DOC(Bentley, DgnPlatform, TextTable, SetWidth));
    
    c9.def_property("Height", &TextTable::GetHeight, &TextTable::SetHeight);
    c9.def("GetHeight", &TextTable::GetHeight, DOC(Bentley, DgnPlatform, TextTable, GetHeight));
    c9.def("SetHeight", &TextTable::SetHeight, "height"_a, DOC(Bentley, DgnPlatform, TextTable, SetHeight));

    c9.def_static("Create", 
                  py::overload_cast<UInt32, UInt32, ElementId, double, DgnModelR>(&TextTable::Create), 
                  "rowCount"_a, "columnCount"_a, "textStyleId"_a, "backupTextHeight"_a, "dgnModel"_a, DOC(Bentley, DgnPlatform, TextTable, Create));

    c9.def("CloneAsSeed", &TextTable::CloneAsSeed, "rowCount"_a, "columnCount"_a, "dgnModel"_a, DOC(Bentley, DgnPlatform, TextTable, CloneAsSeed));
    
    c9.def_property_readonly("SizeLock", &TextTable::GetSizeLock);
    c9.def("GetSizeLock", &TextTable::GetSizeLock, DOC(Bentley, DgnPlatform, TextTable, GetSizeLock));
    
    c9.def_property("TableName", &TextTable::GetTableName, &TextTable::SetTableName);
    c9.def("GetTableName", &TextTable::GetTableName, DOC(Bentley, DgnPlatform, TextTable, GetTableName));
    c9.def("SetTableName", &TextTable::SetTableName, "name"_a, DOC(Bentley, DgnPlatform, TextTable, SetTableName));
    
    c9.def_property("TableDescription", &TextTable::GetTableDescription, &TextTable::SetTableDescription);

    //===================================================================================
    // struct TextTableHandler
    py::class_< TextTableHandler, std::unique_ptr< TextTableHandler, py::nodelete>, ExtendedElementHandler, ITextEdit> c10(m, "TextTableHandler");

    c10.def("ExtractTextTable", &TextTableHandler::ExtractTextTable, "eh"_a, DOC(Bentley, DgnPlatform, TextTableHandler, ExtractTextTable));

    c10.def("SetTextTable", 
            py::overload_cast<EditElementHandleR, TextTableR>(&TextTableHandler::SetTextTable),
            "eeh"_a, "textTable"_a, DOC(Bentley, DgnPlatform, TextTableHandler, SetTextTable));

    c10.def_static("CreateTextTableElement", &TextTableHandler::CreateTextTableElement, "eeh"_a, "textTable"_a, "modelRef"_a = nullptr, DOC(Bentley, DgnPlatform, TextTableHandler, CreateTextTableElement));
    c10.def("IsTableNameExist", &TextTableHandler::IsTableNameExist, "tableName"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, TextTableHandler, IsTableNameExist));
    c10.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr< TextTableHandler, py::nodelete>(&TextTableHandler::GetInstance()); });
    c10.def_static("GetInstance", &TextTableHandler::GetInstance, py::return_value_policy::reference);
    }