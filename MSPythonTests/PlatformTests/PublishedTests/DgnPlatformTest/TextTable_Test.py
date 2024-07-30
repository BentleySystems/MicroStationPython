##--------------------------------------------------------------------------------------+
#
#  $Source: TextTable_Test.py $
#
#  $Copyright: (c) 2021 Bentley Systems, Incorporated. All rights reserved. $
#
#--------------------------------------------------------------------------------------##
import os
#import sys
import pytest
import ctypes

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from util import *

from typing import Dict
from enum import Enum

#import ctypes
# python_dll = ctypes.PyDLL("python3.dll")

# These need to match the equivalent strings in DgnPlatform
TEXTTABLE_ECSchemaName = "TextTableElementPrivateSchema"

TEXTTABLE_ECCLASSNAME_Table = "TableData"
TEXTTABLE_ECCLASSNAME_Row = "RowData"
TEXTTABLE_ECCLASSNAME_Column = "ColumnData"
TEXTTABLE_ECCLASSNAME_Cell = "CellData"
TEXTTABLE_ECCLASSNAME_Merge = "MergeData"
TEXTTABLE_ECCLASSNAME_Edge = "EdgeData"
TEXTTABLE_ECCLASSNAME_Cell = "CellData"
TEXTTABLE_ECCLASSNAME_Symbology = "Symbology"
TEXTTABLE_ECCLASSNAME_EdgeRun = "EdgeRun"

dgnFileName = '2dMetricGeneral.dgn'

InstanceCountMap = Dict[SchemaNameClassNamePair, int]

class BackDoor:
    def GetTextTablePrivateInstanceCounts (counts, eh):
        return TextTableHandler.GetInstance().GetPrivateInstanceCounts (counts, eh)

##=================================================================================######
# @bsiclass
#===============#===============#===============#===============#===============#======##
class ExpectedInstanceCounts:
    def __init__ (self):
        self.m_expectedCounts : InstanceCountMap = {}
        # Every table has exactly one table data instance
        self.AddEntry (TEXTTABLE_ECCLASSNAME_Table, 1)

        # Every table at least one symbology instance
        self.AddEntry (TEXTTABLE_ECCLASSNAME_Symbology, 1)


    def AddEntry (self, className, count):
        names = SchemaNameClassNamePair (TEXTTABLE_ECSchemaName, className)
        self.m_expectedCounts[names] = count


    def VerifyCounts (self, eh):
        actualCounts : InstanceCountMap = {}

        # BackDoor.GetTextTablePrivateInstanceCounts (actualCounts, eh)

        # for names, expectedCount in self.m_expectedCounts.items ():
        #     matchingEntry = actualCounts.get (names) #, "Not Found"

        #     actualCount = 0
        #     if (None != matchingEntry):
        #         actualCount = matchingEntry.__len__ ()

        #     EXPECT_EQ (expectedCount, actualCount) #<< "Instance count mismatch for class: " << names.m_className

        #     actualCounts.pop (names)


        # # There are instances on the element that were not expected.
        # if (actualCounts.__len__() <= 1):
        #     return

        # for names, actualCount in actualCounts:
        #     ##printf ("For class <%ls>, expected 0 instances, but actually found %d\n", names.m_className, actualCount)
        #     EXPECT_EQ (1, actualCount) #<< "Instance count mismatch for class: " << names.m_className


##=================================================================================######
# @bsiclass
#===============#===============#===============#===============#===============#======##
class TableDrawTester (IElementGraphicsProcessor):
    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _AnnounceContext (self, context):
        self.m_context = context

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _AnnounceTransform (self, trans):
        if (None != trans):
            self.m_currentTransform = trans
        else:
            self.m_currentTransform.InitIdentity ()

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _ProcessCurveVector (self, curves, isFilled):    
        ##printf ("Got a curve\n")

        return eSUCCESS
    

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _ProcessTextString (self, text):
        ##printf ("Got a text string\n")

        return eSUCCESS

##=================================================================================######
# @bsistruct
#===============#===============#===============#===============#===============#======##
class MergeDescr:
    def __init__ (self, i,  r, c):
        self.m_rootIndex = i
        self.m_rowSpan = r
        self.m_colSpan = c

##=================================================================================######
# @bsistruct
#===============#===============#===============#===============#===============#======##
class TestTextTableTestTestFixture:
    def loadDgnFileByFileName (self, fileName):
        dataDir = os.environ['MSPYTESTDATA']
        ret = DgnDocument.CreateFromFileName (fileName, dataDir, -101, DgnDocument.FetchMode.eWrite)

        if (ret[1] != DgnFileStatus.eDGNFILE_STATUS_Success):
            assert False

        dgnFile = DgnFile (ret[0], DgnFileOpenMode.eReadWrite)
        dgnFile.LoadDgnFile ()
        dgnFile.FillDictionaryModel ()

        return dgnFile

    def GetDgnModel (self):
        self.dgnFile = self.loadDgnFileByFileName (dgnFileName)
        self.model, retVal = self.dgnFile.LoadRootModelById (self.dgnFile.DefaultModelId, True)
        return self.model

    def setup_method (self):
        DgnPlatformFixture_Initialize ()

        self.GetDgnModel ()
        textStyleName = self.GetTextStyleName()
        textStyle = DgnTextStyle (textStyleName, self.dgnFile)
        textStyle.SetDoubleProperty (TextStyleProperty.eTextStyle_Height, self.GetTextStyleHeight ())
        textStyle.SetDoubleProperty (TextStyleProperty.eTextStyle_Width,  self.GetTextStyleHeight ())
        EXPECT_EQ(eSUCCESS, textStyle.Add())

        self.m_textStyleId = textStyle.GetID()

    def teardown_method (self):
        DgnTextStyle.Delete (self.GetTextStyleName(), self.dgnFile)
        #self.dgnFile.ProcessChanges(DgnSaveReason.eFileClose)
        self.dgnFile.Release ()

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def GetTextStyleName (self):
        return "TextStyleForTable"

    def GetTextStyleHeight (self):
        return 0.25 * self.model.GetModelInfo().GetUorPerStorage() 

    def GetTextStyleId (self):
        return self.m_textStyleId

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def CreateBasicTable (self, numRows = 5, numCols = 3):
        return TextTable.Create (numRows, numCols, self.GetTextStyleId(), 1000.0, self.model)

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def BuildExpectedCellList (expectedCells, numRows, numCols, exclusions):
        for iRow  in range (0, numRows):
            for iCol in range (0, numCols):
                index = TableCellIndex (iRow, iCol)
                if (None != exclusions):
                    if (index in exclusions):
                        continue

                expectedCells.append (index)

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def VerifyCellCollection (table, exclusions):
        expectedCells = TableCellIndexArray ()
        TestTextTableTestTestFixture.BuildExpectedCellList (expectedCells, table.GetRowCount(), table.GetColumnCount(), exclusions)

        #TODO public: __cdecl Bentley::DgnPlatform::TextTableCell::TextTableCell(struct Bentley::DgnPlatform::TextTableCell const &)" (??0TextTableCell@DgnPlatform@Bentley@@QEAA@AEBU012@@Z) referenced in function "public: void * __cdecl <lambda_33a0f28ea74bc72233ef732a905516a8>::operator()(void const *)const " (??R<lambda_33a0f28ea74bc72233ef732a905516a8>@@QEBAPEAXPEBX@Z)
        #iCell = 0
        #cellCollection = table.GetCellCollection()
        #for cell in cellCollection:
        #    foundIndex     = cell.GetIndex()
        #    expectedIndex  = expectedCells[iCell]
        #    iCell += 1

        #    ASSERT_TRUE (expectedIndex == foundIndex)

        #ASSERT_EQ (expectedCells.__len__(), iCell)


    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def VerifyCellsWithMergeBlocks (table, mergeBlocks, eh):
        # Verify that the expected cells were consumed
        cellsThatWereConsumed = TableCellIndexArray ()

        for merge in mergeBlocks:
            skippedFirst = False
            oldConsumedCount = cellsThatWereConsumed.__len__ ()

            for iRow in range (merge.m_rootIndex.rowId, merge.m_rootIndex.rowId + merge.m_rowSpan):
                for iCol in range (merge.m_rootIndex.colId, merge.m_rootIndex.colId + merge.m_colSpan):
                    if (False == skippedFirst):
                        skippedFirst = True
                        continue 

                    cellsThatWereConsumed.append (TableCellIndex (iRow, iCol))

            #double check
            EXPECT_EQ (merge.m_rowSpan * merge.m_colSpan - 1, cellsThatWereConsumed.__len__() - oldConsumedCount)

        TestTextTableTestTestFixture.VerifyCellCollection (table, cellsThatWereConsumed)

        expectedCounts = ExpectedInstanceCounts ()

        if (0 != mergeBlocks.__len__()):
            expectedCounts.AddEntry (TEXTTABLE_ECCLASSNAME_Merge, mergeBlocks.__len__())

        expectedCounts.VerifyCounts(eh)


    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableBasicCreate (self):
        seedTable = self.CreateBasicTable ()

        ASSERT_TRUE (seedTable != None)

        EXPECT_EQ (5, seedTable.GetRowCount ())
        EXPECT_EQ (3, seedTable.GetColumnCount ())

        TestTextTableTestTestFixture.VerifyCellCollection (seedTable, None)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableBasicDraw (self):
        seedTable = self.CreateBasicTable ()

        ASSERT_TRUE (None != seedTable)

        tableElement = EditElementHandle ()
        TextTableHandler.CreateTextTableElement (tableElement, seedTable)

        tester = TableDrawTester ()
        ElementGraphicsOutput.Process (tableElement, tester)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableMergeCells (self):
        seedTable = self.CreateBasicTable ()

        ASSERT_TRUE (None != seedTable)

        # Verify that all the cells are present
        TestTextTableTestTestFixture.VerifyCellCollection (seedTable, None)

        # Merge a 2x2 block of cells
        seedTable.MergeCells (TableCellIndex (1, 1), 2, 2)

        # Verify that three cells were consumed
        cellsThatWereConsumed = TableCellIndexArray ()
        cellsThatWereConsumed.append (TableCellIndex (1, 2))
        cellsThatWereConsumed.append (TableCellIndex (2, 1))
        cellsThatWereConsumed.append (TableCellIndex (2, 2))

        TestTextTableTestTestFixture.VerifyCellCollection (seedTable, cellsThatWereConsumed)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableDrawFills (self):
        seedTable = self.CreateBasicTable ()

        ASSERT_TRUE (None != seedTable)

        symbValues = TableSymbologyValues ()
        symbValues.SetFillColor(12)
    
        seedTable.SetDefaultFill (symbValues, TableRows.eAll)

        tableElement = EditElementHandle ()
        TextTableHandler.CreateTextTableElement (tableElement, seedTable)

        tester = TableDrawTester ()
        ElementGraphicsOutput.Process (tableElement, tester)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableDeleteRow (self):
        seedTable = self.CreateBasicTable ()

        ASSERT_TRUE (None != seedTable)

        # Verify that all the cells are present
        TestTextTableTestTestFixture.VerifyCellCollection (seedTable, None)

        # Delete a row
        initialRowCount = seedTable.GetRowCount()
        seedTable.DeleteRow (1)

        EXPECT_EQ (initialRowCount - 1, seedTable.GetRowCount())

        # Verify that the expected cells are there
        TestTextTableTestTestFixture.VerifyCellCollection (seedTable, None)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableInsertRow (self):
        seedTable = self.CreateBasicTable ()

        ASSERT_TRUE (None != seedTable)

        # Verify that all the cells are present
        TestTextTableTestTestFixture.VerifyCellCollection (seedTable, None)

        # Delete a row
        initialRowCount = seedTable.GetRowCount()
        seedTable.InsertRow (0, TableInsertDirection.eAfter)

        EXPECT_EQ (initialRowCount + 1, seedTable.GetRowCount())

        # Verify that the expected cells are there
        TestTextTableTestTestFixture.VerifyCellCollection (seedTable, None)

##=================================================================================######
# @bsistruct
#===============#===============#===============#===============#===============#======##
class TextTableTestAction:
    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _CreateTable (self, textStyleID, dgnModel):
        return None

    def _PreAction (self, textTable):
        pass

    def _DoAction (self, textTable):
        pass

    def _VerifyAction (self, textTable, eh):
        pass

##=================================================================================######
# @bsistruct
#===============#===============#===============#===============#===============#======##
class NoAction (TextTableTestAction):
    def __init__ (self):
        pass

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _DoAction (self, table):
        pass
        # Don't do anything, a table is created and written by the test logic

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _VerifyAction (self, table, eeh):
        EXPECT_EQ (5, table.GetRowCount ())
        EXPECT_EQ (3, table.GetColumnCount ())

        # Expect the minimum instances on the element
        expectedCounts = ExpectedInstanceCounts ()
        expectedCounts.VerifyCounts (eeh)

##=================================================================================######
# @bsistruct
#===============#===============#===============#===============#===============#======##
class OverrideRowHeightAction (TextTableTestAction):
    def __init__ (self, v, i):
        self.m_overrideHeight = v
        self.m_index = i

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _DoAction (self, table):
        defaultRowHeight = table.GetDefaultRowHeight()
        EXPECT_TRUE (defaultRowHeight != self.m_overrideHeight)
        #tableRefCount = sys.getrefcount (table)
        row = table.GetRow(self.m_index)
        #rowRefCount = sys.getrefcount (row)
        row.SetHeight (self.m_overrideHeight)


    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _VerifyAction (self, table, eh):
        defaultRowHeight = table.GetDefaultRowHeight()

        for iRow in range (0, table.GetRowCount()):
            expectedHeight = self.m_overrideHeight if self.m_index == iRow else defaultRowHeight

            EXPECT_EQ (expectedHeight, table.GetRow(iRow).GetHeight())

        expectedCounts = ExpectedInstanceCounts ()
        expectedCounts.AddEntry (TEXTTABLE_ECCLASSNAME_Row, 1)
        expectedCounts.VerifyCounts(eh)

##=================================================================================######
# @bsistruct
#===============#===============#===============#===============#===============#======##
class OverrideColumnWidthAction (TextTableTestAction):
    def __init__ (self, v, i):
        self.m_overrideWidth = v
        self.m_index = i

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _DoAction (self, table):
        defaultColumnWidth = table.GetDefaultColumnWidth()
        EXPECT_TRUE (defaultColumnWidth != self.m_overrideWidth)

        table.GetColumn(self.m_index).SetWidth (self.m_overrideWidth)


    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _VerifyAction (self, table, eh):
        defaultColumnWidth = table.GetDefaultColumnWidth()

        for iCol in range (0, table.GetColumnCount()):
            expectedWidth = self.m_overrideWidth if (self.m_index == iCol) else defaultColumnWidth
            EXPECT_EQ (expectedWidth, table.GetColumn(iCol).GetWidth())

        expectedCounts = ExpectedInstanceCounts ()
        expectedCounts.AddEntry (TEXTTABLE_ECCLASSNAME_Column, 1)
        expectedCounts.VerifyCounts(eh)

##=================================================================================######
# @bsistruct
#===============#===============#===============#===============#===============#======##
class ClearRowHeightAction (TextTableTestAction):
    def __init__ (self, i):
        self.m_index = i

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _PreAction (self, table):
        overrideHeight = 12345.0
        defaultRowHeight = table.GetDefaultRowHeight()
        EXPECT_TRUE (defaultRowHeight != overrideHeight)

        table.GetRow(self.m_index).SetHeight (overrideHeight)

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _DoAction (self, table):
        table.GetRow(self.m_index).SetHeightFromContents()


    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _VerifyAction (self, table, eh):
        defaultRowHeight = table.GetDefaultRowHeight()

        for iCol in range (0, table.GetRowCount()):
            expectedHeight = defaultRowHeight
            EXPECT_EQ (expectedHeight, table.GetRow(iCol).GetHeight())


        # Expect just the minimum instances on the element (we removed the rowumn)
        expectedCounts = ExpectedInstanceCounts ()
        expectedCounts.VerifyCounts(eh)

##=================================================================================######
# @bsistruct
#===============#===============#===============#===============#===============#======##
class SetCellTextAction (TextTableTestAction):
    def __init__ (self, v, i):
        self.m_applyString = WString (v)
        self.m_cellIndex = i

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _DoAction (self, table):
        dgnFile = table.GetModel().GetDgnFile ()
        textStyleId = table.GetTextStyleId (TextTableRegion.eBody)
        textStyle  = DgnTextStyle.GetByID (textStyleId, dgnFile)
        textBlock  = TextBlock (textStyle, table.GetModel())

        textBlock.AppendText (str (self.m_applyString))

        cell = table.GetCell (self.m_cellIndex)
        cell.SetTextBlock (textBlock)


    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _VerifyAction (self, table, eh):
        foundCell = table.GetCell (self.m_cellIndex)
        foundTextBlock = foundCell.GetTextBlock()
        foundString = foundTextBlock.ToString()

        EXPECT_STREQ (self.m_applyString, foundString)

        anotherCell = TableCellIndex (self.m_cellIndex.rowId - 1, self.m_cellIndex.colId - 1)
        foundCell = table.GetCell (anotherCell)

        EXPECT_TRUE (None == foundCell.GetTextBlock())

        expectedCounts = ExpectedInstanceCounts ()
        expectedCounts.AddEntry (TEXTTABLE_ECCLASSNAME_Cell, 1)
        expectedCounts.VerifyCounts(eh)

##=================================================================================######
# @bsistruct
#===============#===============#===============#===============#===============#======##
class ChangeCellTextAction (TextTableTestAction):
    def __init__ (self, v, i):
        self.m_applyString = WString (v)
        self.m_cellIndex = i

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _PreAction (self, table):
        dgnFile    = table.GetModel().GetDgnFile()
        textStyleId = table.GetTextStyleId(TextTableRegion.eBody)
        textStyle  = DgnTextStyle.GetByID(textStyleId, dgnFile)
        textBlock  = TextBlock (textStyle, table.GetModel())

        textBlock.AppendText ("abcdefghi")

        cell = table.GetCell (self.m_cellIndex)
        cell.SetTextBlock (textBlock)


    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _DoAction (self, table):
        dgnFile    = table.GetModel().GetDgnFile()
        textStyleId = table.GetTextStyleId(TextTableRegion.eBody)
        textStyle  = DgnTextStyle.GetByID(textStyleId, dgnFile)
        textBlock  = TextBlock (textStyle, table.GetModel())

        textBlock.AppendText (str (self.m_applyString))

        cell = table.GetCell (self.m_cellIndex)
        cell.SetTextBlock (textBlock)


    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _VerifyAction (self, table, eh):
        foundCell = table.GetCell (self.m_cellIndex)
        foundTextBlock = foundCell.GetTextBlock()
        foundString = foundTextBlock.ToString()

        EXPECT_STREQ (self.m_applyString, foundString)

        anotherCell = TableCellIndex (self.m_cellIndex.rowId - 1, self.m_cellIndex.colId - 1)
        foundCell = table.GetCell (anotherCell)

        EXPECT_TRUE (None == foundCell.GetTextBlock())

        expectedCounts = ExpectedInstanceCounts ()
        expectedCounts.AddEntry (TEXTTABLE_ECCLASSNAME_Cell, 1)
        expectedCounts.VerifyCounts(eh)

##=================================================================================######
# @bsistruct
#===============#===============#===============#===============#===============#======##
class ClearCellTextAction (TextTableTestAction):
    def __init__ (self, i):
        self.m_cellIndex = i

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _PreAction (self, table):
        dgnFile    = table.GetModel().GetDgnFile()
        textStyleId = table.GetTextStyleId(TextTableRegion.eBody)
        textStyle  = DgnTextStyle.GetByID(textStyleId, dgnFile)
        textBlock  = TextBlock(textStyle, table.GetModel())

        textBlock.AppendText ("abcdefghi")

        cell = table.GetCell (self.m_cellIndex)
        cell.SetTextBlock (textBlock)


    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _DoAction (self, table):
        dgnFile    = table.GetModel().GetDgnFile()
        textStyleId = table.GetTextStyleId(TextTableRegion.eBody)
        textStyle  = DgnTextStyle.GetByID(textStyleId, dgnFile)
        textBlock  = TextBlock (textStyle, table.GetModel())

        # textBlock is empty

        cell = table.GetCell (self.m_cellIndex)
        cell.SetTextBlock (textBlock)


    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _VerifyAction (self, table, eh):
        foundCell = table.GetCell (self.m_cellIndex)
        EXPECT_TRUE (None == foundCell.GetTextBlock())

        anotherCell = TableCellIndex (self.m_cellIndex.rowId - 1, self.m_cellIndex.colId - 1)

        foundCell = table.GetCell (anotherCell)
        EXPECT_TRUE (None == foundCell.GetTextBlock())

        # Expect just the minimum instances on the element (we removed cell)
        expectedCounts = ExpectedInstanceCounts ()
        expectedCounts.VerifyCounts(eh)

##=================================================================================######
# @bsistruct
#===============#===============#===============#===============#===============#======##
class DeleteRowAction (TextTableTestAction):
    def __init__ (self, r):
        self.m_rowIndex = r
        self.m_rowCount = 0

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    07#13
    #---------------+---------------+---------------+---------------+---------------+------##
    def _PreAction (self, table):
        self.m_rowCount = table.GetRowCount()


    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    07#13
    #---------------+---------------+---------------+---------------+---------------+------##
    def _DoAction (self, table):
        # Delete a row
        table.DeleteRow (self.m_rowIndex)


    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    07#13
    #---------------+---------------+---------------+---------------+---------------+------##
    def _VerifyAction (self, table, eh):
        EXPECT_EQ (self.m_rowCount - 1, table.GetRowCount())

        expectedCounts = ExpectedInstanceCounts ()
        expectedCounts.VerifyCounts(eh)

##=================================================================================######
# @bsistruct
#===============#===============#===============#===============#===============#======##
class MergeCellsAction (TextTableTestAction):
    def __init__ (self, i, r, c, e):
        self.m_rootIndex = i
        self.m_rowSpan = r
        self.m_colSpan = c
        self.m_expectFail = e

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _CreateTable (self, textStyleId, model):
        numRows = 3
        numCols = 3

        #       0     1     2   
        #    #------------------
        #  0 #     #     #     #
        #    #-----+-----+-----+
        #  1 #     #     #     #
        #    #-----+-----+-----#
        #  2 #     #     #     #
        #    #-----+-----+-----+

        return TextTable.Create (numRows, numCols, textStyleId, 1000.0, model)

     #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _DoAction (self, table):
        # Merge a block of cells
        failed = (eSUCCESS != table.MergeCells (self.m_rootIndex, self.m_rowSpan, self.m_colSpan))
        ASSERT_EQ (self.m_expectFail, failed)


    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _VerifyAction (self, table, eh):
        mergeBlocks = []

        if (False == self.m_expectFail):
            mergeBlocks.append (MergeDescr (self.m_rootIndex, self.m_rowSpan, self.m_colSpan))

        TestTextTableTestTestFixture.VerifyCellsWithMergeBlocks (table, mergeBlocks, eh)

##=================================================================================######
# @bsistruct
#===============#===============#===============#===============#===============#======##
class MergeCellsWithExistingAction (TextTableTestAction):
    def __init__ (self, e, i, r, c, f, consume):
        self.m_rootIndex = i
        self.m_rowSpan = r
        self.m_colSpan = c
        self.m_expectFail = f
        self.m_expectConsume = consume
        self.m_existingMerge = e

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _CreateTable (self, textStyleId, model):
        numRows = 4
        numCols = 4

        table = TextTable.Create (numRows, numCols, textStyleId, 1000.0, model)
        table.MergeCells (self.m_existingMerge.m_rootIndex, self.m_existingMerge.m_rowSpan, self.m_existingMerge.m_colSpan)

        return table


    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _DoAction (self, table):
        # Merge a block of cells
        failed = (eSUCCESS != table.MergeCells (self.m_rootIndex, self.m_rowSpan, self.m_colSpan))
        ASSERT_EQ (self.m_expectFail, failed)


    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _VerifyAction (self, table, eh):
        mergeBlocks = []

        if (False == self.m_expectConsume):
            mergeBlocks.append (self.m_existingMerge)

        if (False == self.m_expectFail):
            mergeBlocks.append (MergeDescr (self.m_rootIndex, self.m_rowSpan, self.m_colSpan))

        TestTextTableTestTestFixture.VerifyCellsWithMergeBlocks (table, mergeBlocks, eh)

##=================================================================================######
# @bsistruct
#===============#===============#===============#===============#===============#======##
class DeleteMergedCellsAction (TextTableTestAction):
    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    class DeleteTarget(Enum):
        NOTHING = 0                     # No delete
        ROW_BEFORE = 1                  # Delete the row preceeding the merge block
        ROW_WITH_ROOT = 2               # Delete the row containing the root of the merge block
        ROW_INTERIOR = 3                # Delete a row that intersects the merge block
        ROW_ALL_MERGED = 4              # Delete all the rows that intersect the merge block
        ROW_AFTER = 5                   # Delete the row after the merge block
        COLUMN_BEFORE = 6               # Delete the column preceeding the merge block
        COLUMN_WITH_ROOT = 7            # Delete the column containing the root of the merge block
        COLUMN_INTERIOR = 8             # Delete a column that intersects the merge block
        COLUMN_ALL_MERGED = 9           # Delete all the column that intersect the merge block
        COLUMN_AFTER = 10               # Delete the column after the merge block

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def __init__ (self, deleteTarget):
        self.m_deleteTarget = deleteTarget
        self.m_rootIndex = TableCellIndex (1, 1)
        self.m_rowSpan = 2
        self.m_colSpan = 2
        self.m_numMergeInstances = 0

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _CreateTable (self, textStyleId, model):
        numRows = 4
        numCols = 4

        # We want a table big enough that the merge block isn't on the edges.  So that
        # we can insert and delete rows#cols before after the merge.

        #       0     1     2     3  
        #    #-----------------------#
        #  0 #     #     #     #     #
        #    #-----+-----+-----+-----#
        #  1 #     #           #     #
        #    #-----+           #-----#
        #  2 #     #           #     #
        #    #-----+-----+-----+-----#
        #  3 #     #     #     #     #
        #    #-----+-----+-----+-----#

        return TextTable.Create (numRows, numCols, textStyleId, 1000.0, model)
 
    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _PreAction (self, table):
        # Merge a block of cells
        table.MergeCells (self.m_rootIndex, self.m_rowSpan, self.m_colSpan)

        # At this point, the table should have one merge instance
        self.m_numMergeInstances = 1


    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _DoAction (self, table):
        rowsToDelete = []
        colsToDelete = []
        rootRowChange      = 0
        rootColChange      = 0
        rowSpanChange      = 0
        colSpanChange      = 0
        numInstancesChange = 0

        #match needs python 3.10 or later
        #match self.m_deleteTarget.value:
        #    case DeleteMergedCellsAction.DeleteTarget.NOTHING.value:
        if DeleteMergedCellsAction.DeleteTarget.NOTHING.value == self.m_deleteTarget.value:
            rootRowChange = 0
            rowSpanChange = 0
            numInstancesChange = 0
        elif DeleteMergedCellsAction.DeleteTarget.ROW_BEFORE.value == self.m_deleteTarget.value:
            rootRowChange = 1
            rowSpanChange = 0
            numInstancesChange = 0
            rowsToDelete.append (self.m_rootIndex.rowId - 1)
        elif DeleteMergedCellsAction.DeleteTarget.ROW_WITH_ROOT.value == self.m_deleteTarget.value:
            rootRowChange = 0
            rowSpanChange = 1
            numInstancesChange = 0
            rowsToDelete.append (self.m_rootIndex.rowId)
        elif DeleteMergedCellsAction.DeleteTarget.ROW_INTERIOR.value == self.m_deleteTarget.value:
            rootRowChange = 0
            rowSpanChange = 1
            numInstancesChange = 0
            rowsToDelete.append (self.m_rootIndex.rowId + 1)
        elif DeleteMergedCellsAction.DeleteTarget.ROW_ALL_MERGED.value == self.m_deleteTarget.value:
            rootRowChange = 0
            rowSpanChange = 2
            numInstancesChange = 1
            rowsToDelete.append (self.m_rootIndex.rowId)
            rowsToDelete.append (self.m_rootIndex.rowId)
        elif DeleteMergedCellsAction.DeleteTarget.ROW_AFTER.value == self.m_deleteTarget.value:
            rootRowChange = 0
            rowSpanChange = 0
            numInstancesChange = 0
            rowsToDelete.append (self.m_rootIndex.rowId + self.m_rowSpan)
        elif DeleteMergedCellsAction.DeleteTarget.COLUMN_BEFORE.value == self.m_deleteTarget.value:
            rootColChange = 1
            colSpanChange = 0
            numInstancesChange = 0
            colsToDelete.append (self.m_rootIndex.colId - 1)
        elif DeleteMergedCellsAction.DeleteTarget.COLUMN_WITH_ROOT.value == self.m_deleteTarget.value:
            rootColChange = 0
            colSpanChange = 1
            numInstancesChange = 0
            colsToDelete.append (self.m_rootIndex.colId)
        elif DeleteMergedCellsAction.DeleteTarget.COLUMN_INTERIOR.value == self.m_deleteTarget.value:
            rootColChange = 0
            colSpanChange = 1
            numInstancesChange = 0
            colsToDelete.append (self.m_rootIndex.colId + 1)
        elif DeleteMergedCellsAction.DeleteTarget.COLUMN_ALL_MERGED.value == self.m_deleteTarget.value:
            rootColChange = 0
            colSpanChange = 2
            numInstancesChange = 1
            colsToDelete.append (self.m_rootIndex.colId)
            colsToDelete.append (self.m_rootIndex.colId)
        elif DeleteMergedCellsAction.DeleteTarget.COLUMN_AFTER.value == self.m_deleteTarget.value:
            rootColChange = 0
            colSpanChange = 0
            numInstancesChange = 0
            colsToDelete.append (self.m_rootIndex.colId + self.m_colSpan)
        else:
            print ("Fale else")
            #FAIL()

        for row in rowsToDelete:
            EXPECT_EQ (eSUCCESS, table.DeleteRow (row))

        for col in colsToDelete:
            EXPECT_EQ (eSUCCESS, table.DeleteColumn (col))

        self.m_rootIndex.rowId     -= rootRowChange
        self.m_rootIndex.colId     -= rootColChange
        self.m_rowSpan           -= rowSpanChange
        self.m_colSpan           -= colSpanChange
        self.m_numMergeInstances -= numInstancesChange


    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _VerifyAction (self, table, eh):
        mergeBlocks = []
        if (1 == self.m_numMergeInstances):
            mergeBlocks.append (MergeDescr (self.m_rootIndex, self.m_rowSpan, self.m_colSpan))

        TestTextTableTestTestFixture.VerifyCellsWithMergeBlocks (table, mergeBlocks, eh)

##=================================================================================######
# @bsistruct
#===============#===============#===============#===============#===============#======##
class InsertMergedCellsAction (TextTableTestAction):
    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    class InsertTarget(Enum):
        Nothing        = 0,    # No delete

        RowBefore      = 1,    # Insert a row before the merge block
        RowJustBefore  = 2,    # Insert a row immediately before the rootIndex of the merge block
        RowInterior    = 3,    # Insert a row that intersects the merge block
        RowJustAfter   = 4,    # Insert a row immediately after the last row of the merge block
        RowAfter       = 5,    # Insert a row after the merge block

        ColumnBefore   = 6,    # Insert a column before the merge block
        ColumnJustBefore= 7,    # Insert a column immediately before the rootIndex of the merge block
        ColumnInterior = 8,    # Insert a column that intersects the merge block
        ColumnJustAfter = 9,    # Insert a column immediately after the last column of the merge block
        ColumnAfter    = 10,   # Insert a column after the merge block
    
    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def __init__ (self, insertTarget):
        self.m_insertTarget = insertTarget
        self.m_rootIndex = TableCellIndex (1, 1)
        self.m_rowSpan = 2
        self.m_colSpan = 2
        self.m_expectedMerges = []
    
    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _CreateTable (self, textStyleId, model):
        numRows = 4
        numCols = 4

        # We want a table big enough that the merge block isn't on the edges.  So that
        # we can insert and delete rows#cols before after the merge.

        #       0     1     2     3  
        #    #-----------------------#
        #  0 #     #     #     #     #
        #    #-----+-----+-----+-----#
        #  1 #     #           #     #
        #    #-----+           #-----#
        #  2 #     #           #     #
        #    #-----+-----+-----+-----#
        #  3 #     #     #     #     #
        #    #-----+-----+-----+-----#

        return TextTable.Create (numRows, numCols, textStyleId, 1000.0, model)

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _PreAction (self, table):
        # Merge a block of cells
        table.MergeCells (self.m_rootIndex, self.m_rowSpan, self.m_colSpan)


    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _DoAction (self, table):
        if (InsertMergedCellsAction.InsertTarget.Nothing.value == self.m_insertTarget.value):
            # Do nothing.
            # Expect no change to the existing merge.
            self.m_expectedMerges.append (MergeDescr (self.m_rootIndex, self.m_rowSpan, self.m_colSpan))
        elif (InsertMergedCellsAction.InsertTarget.RowBefore.value == self.m_insertTarget.value):
            # Add the row before the row that's above the merge.
            table.InsertRow (self.m_rootIndex.rowId - 1, TableInsertDirection.eBefore)

            # Expect the merge to move down by one row.
            rootIndex = TableCellIndex (self.m_rootIndex.rowId + 1, self.m_rootIndex.colId)
            self.m_expectedMerges.append (MergeDescr (rootIndex, self.m_rowSpan, self.m_colSpan))
        elif (InsertMergedCellsAction.InsertTarget.RowJustBefore.value == self.m_insertTarget.value):
            # Add the row immediately before the merge.
            table.InsertRow (self.m_rootIndex.rowId, TableInsertDirection.eBefore)

            # Expect a new merge since the cells were merged in the seed row.
            self.m_expectedMerges.append (MergeDescr (self.m_rootIndex, 1, self.m_colSpan))

            # Also expect the original merge to move down by one row.
            rootIndex = TableCellIndex (self.m_rootIndex.rowId + 1, self.m_rootIndex.colId)
            self.m_expectedMerges.append (MergeDescr (rootIndex, self.m_rowSpan, self.m_colSpan))
        elif (InsertMergedCellsAction.InsertTarget.RowInterior.value == self.m_insertTarget.value):
            # Add the row within the merge.
            table.InsertRow (self.m_rootIndex.rowId, TableInsertDirection.eAfter)

            # Expect the merge to grow by one row.
            self.m_expectedMerges.append (MergeDescr (self.m_rootIndex, self.m_rowSpan+1, self.m_colSpan))
        elif (InsertMergedCellsAction.InsertTarget.RowJustAfter.value == self.m_insertTarget.value):
            # Add the row immediately after the merge.
            table.InsertRow (self.m_rootIndex.rowId + self.m_rowSpan - 1, TableInsertDirection.eAfter)

            # Expect no change to the original merge.
            self.m_expectedMerges.append (MergeDescr (self.m_rootIndex, self.m_rowSpan, self.m_colSpan))

            # Also expect a new merge since the cells were merged in the seed row.
            rootIndex = TableCellIndex (self.m_rootIndex.rowId + self.m_rowSpan, self.m_rootIndex.colId)
            self.m_expectedMerges.append (MergeDescr (rootIndex, 1, self.m_colSpan))
        elif (InsertMergedCellsAction.InsertTarget.RowAfter.value == self.m_insertTarget.value):
            # Add the row after the row that's past the merge.
            table.InsertRow (self.m_rootIndex.rowId + self.m_rowSpan, TableInsertDirection.eAfter)

            # Expect no change to the merge.
            self.m_expectedMerges.append (MergeDescr (self.m_rootIndex, self.m_rowSpan, self.m_colSpan))
        elif (InsertMergedCellsAction.InsertTarget.ColumnBefore.value == self.m_insertTarget.value):
            # Add a column before the column that's above the merge.
            table.InsertColumn (self.m_rootIndex.colId - 1, TableInsertDirection.eBefore)

            # Expect the merge to move right by one column.
            rootIndex = TableCellIndex (self.m_rootIndex.rowId, self.m_rootIndex.colId + 1)
            self.m_expectedMerges.append (MergeDescr (rootIndex, self.m_rowSpan, self.m_colSpan))
        elif (InsertMergedCellsAction.InsertTarget.ColumnJustBefore.value == self.m_insertTarget.value):
            # Add a column immediately before the merge.
            table.InsertColumn (self.m_rootIndex.colId, TableInsertDirection.eBefore)

            # Expect a new merge since the cells were merged in the seed column.
            self.m_expectedMerges.append (MergeDescr (self.m_rootIndex, self.m_rowSpan, 1))

            # Also expect the original merge to move right by one column.
            rootIndex = TableCellIndex (self.m_rootIndex.rowId, self.m_rootIndex.colId + 1)
            self.m_expectedMerges.append (MergeDescr (rootIndex, self.m_rowSpan, self.m_colSpan))
        elif (InsertMergedCellsAction.InsertTarget.ColumnInterior.value == self.m_insertTarget.value):
            # Add the row within the merge.
            table.InsertColumn (self.m_rootIndex.colId, TableInsertDirection.eAfter)

            # Expect the merge to grow by one column.
            self.m_expectedMerges.append (MergeDescr (self.m_rootIndex, self.m_rowSpan, self.m_colSpan+1))
        elif (InsertMergedCellsAction.InsertTarget.ColumnJustAfter.value == self.m_insertTarget.value):
            # Add a column immediately after the merge.
            table.InsertColumn (self.m_rootIndex.colId + self.m_colSpan - 1, TableInsertDirection.eAfter)

            # Expect no change to the original merge.
            self.m_expectedMerges.append (MergeDescr (self.m_rootIndex, self.m_rowSpan, self.m_colSpan))

            # Also expect a new merge since the cells were merged in the seed row.
            rootIndex = TableCellIndex (self.m_rootIndex.rowId, self.m_rootIndex.colId + self.m_colSpan)
            self.m_expectedMerges.append (MergeDescr (rootIndex, self.m_rowSpan, 1))
        elif (InsertMergedCellsAction.InsertTarget.ColumnAfter.value == self.m_insertTarget.value):
            # Add the row after the row that's past the merge.
            table.InsertColumn (self.m_rootIndex.colId + self.m_colSpan, TableInsertDirection.eAfter)

            # Expect no change to the merge.
            self.m_expectedMerges.append (MergeDescr (self.m_rootIndex, self.m_rowSpan, self.m_colSpan))
        else:
            #FAIL()
            assert False

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _VerifyAction (self, table, eh):
        TestTextTableTestTestFixture.VerifyCellsWithMergeBlocks (table, self.m_expectedMerges, eh)

##=================================================================================######
# @bsistruct
#===============#===============#===============#===============#===============#======##
class EdgeColorSetter:
    def __init__ (self, table, rowIndex, colorVal):
        self.m_table = table
        self.m_rowIndex = rowIndex
        self.m_symb = TableSymbologyValues ()
        self.m_symb.SetLineColor(colorVal)


    def SetColor (self, colIndex, numCells, top):
        edges = TableCellListEdges.eTop if top else TableCellListEdges.eBottom

        cells = TableCellIndexArray ()
        for iCol in range (0, numCells):
            cells.append (TableCellIndex (self.m_rowIndex, colIndex + iCol))

        self.m_table.SetEdgeSymbology (self.m_symb, edges, cells)

##=================================================================================######
# @bsistruct
#===============#===============#===============#===============#===============#======##
class SetEdgeColorAction (TextTableTestAction):
    def __init__ (self, color, row, colStart, numCols, top):
        self.m_colorVal = color
        self.m_rowIndex = row
        self.m_colStartIndex = colStart
        self.m_numCols = numCols
        self.m_top = top

    def SetExpectedRunCount (self, numRuns):
        self.m_expectedRunCount = numRuns

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _DoAction (self, table):
        setter = EdgeColorSetter (table, self.m_rowIndex, 12)
        setter.SetColor (self.m_colStartIndex, self.m_numCols, self.m_top)


    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _VerifyAction (self, table, eh):
        expectedCounts = ExpectedInstanceCounts ()
        expectedCounts.AddEntry (TEXTTABLE_ECCLASSNAME_Symbology, 2)
        expectedCounts.AddEntry (TEXTTABLE_ECCLASSNAME_EdgeRun, self.m_expectedRunCount)
        expectedCounts.VerifyCounts(eh)

##================================================================================ = ######
# @bsistruct
#===============#===============#===============#===============#===============#======##
class MergeAdjacentEdgeRunsAction(TextTableTestAction):
    def __init__ (self):
        self.m_rowIndex = 0
        self.m_colorVal = 12

#---------------------------------------------------------------------------------######
# @bsimethod                                                    Ping.Chen    03/2024
#---------------+---------------+---------------+---------------+---------------+------##
    def _PreAction (self, table):
        setter = EdgeColorSetter(table, self.m_rowIndex, self.m_colorVal)

        # #----#----#----#
        setter.SetColor(0, 2, True)
        # #oooo#oooo#----#


#---------------------------------------------------------------------------------######
# @bsimethod                                                    Ping.Chen    03/2024
#---------------+---------------+---------------+---------------+---------------+------##
    def _DoAction (self, table):
        setter = EdgeColorSetter(table, self.m_rowIndex, self.m_colorVal)

        # #oooo#oooo#----#
        setter.SetColor(2, 1, True)
        # #oooo#oooo#oooo#


#---------------------------------------------------------------------------------######
# @bsimethod                                                    Ping.Chen    03/2024
#---------------+---------------+---------------+---------------+---------------+------##
    def _VerifyAction (self, table, eh):
        expectedCounts = ExpectedInstanceCounts()
        expectedCounts.AddEntry(TEXTTABLE_ECCLASSNAME_Symbology, 2)
        expectedCounts.AddEntry(TEXTTABLE_ECCLASSNAME_EdgeRun, 1)
        expectedCounts.VerifyCounts(eh)

##================================================================================ = ######
# @bsistruct
#===============#===============#===============#===============#===============#======##
class MergeNonAdjacentEdgeRunsAction(TextTableTestAction):
    def __init__ (self):
        self.m_rowIndex = 0
        self.m_colorVal = 12

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _PreAction (self, table):
        setter = EdgeColorSetter(table, self.m_rowIndex, self.m_colorVal)

        # #----#----#----#
        setter.SetColor(0, 1, True)
        setter.SetColor(2, 1, True)
        # #oooo#----#oooo#


    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _DoAction (self, table):
        setter = EdgeColorSetter(table, self.m_rowIndex, self.m_colorVal)

        # #oooo#----#oooo#
        setter.SetColor(1, 1, True)
        # #oooo#oooo#oooo#


    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _VerifyAction (self, table, eh):
        expectedCounts = ExpectedInstanceCounts()
        expectedCounts.AddEntry(TEXTTABLE_ECCLASSNAME_Symbology, 2)
        expectedCounts.AddEntry(TEXTTABLE_ECCLASSNAME_EdgeRun, 1)
        expectedCounts.VerifyCounts(eh)

##================================================================================ = ######
# @bsistruct
#===============#===============#===============#===============#===============#======##
class DeleteColumnJoinsEdgeRunsAction(TextTableTestAction):
    def __init__ (self):
        self.m_rowIndex = 0
        self.m_colorVal = 12

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _PreAction (self, table):
        setter = EdgeColorSetter(table, self.m_rowIndex, self.m_colorVal)

        # #----#----#----#
        setter.SetColor(0, 1, True)
        setter.SetColor(2, 1, True)
        # #oooo#----#oooo#


    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _DoAction (self, table):
        # #oooo#----#oooo#
        table.DeleteColumn(1)
        # #oooo#oooo#


    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _VerifyAction (self, table, eh):
        expectedCounts = ExpectedInstanceCounts()
        expectedCounts.AddEntry(TEXTTABLE_ECCLASSNAME_Symbology, 2)
        expectedCounts.AddEntry(TEXTTABLE_ECCLASSNAME_EdgeRun, 1)

        expectedCounts.VerifyCounts(eh)

##================================================================================ = ######
# @bsistruct
#===============#===============#===============#===============#===============#======##
class DeleteColumnRemovesSymbologyEntryAction (TextTableTestAction):
    def __init__ (self):
        self.m_rowIndex = 2
        self.m_colIndex = 1
        self.m_colorVal = 12

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _PreAction (self, table):
        setter = EdgeColorSetter(table, self.m_rowIndex, self.m_colorVal)

        # #----#----#----#
        setter.SetColor (self.m_colIndex, 1, True)
        # #----#oooo#----#


    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _DoAction (self, table):
        # #----#oooo#----#
        table.DeleteColumn (self.m_colIndex)
        # #----#----#


    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _VerifyAction (self, table, eh):
        expectedCounts = ExpectedInstanceCounts()
        # empty - we added symbology and an edge run, but then deleted the colum which used them.

        expectedCounts.VerifyCounts(eh)

##================================================================================ = ######
# @bsistruct
#===============#===============#===============#===============#===============#======##
class InsertColumnExtendsSymbologyAction(TextTableTestAction):
    def __init__ (self):
        self.m_rowIndex = 2
        self.m_colIndex = 1
        self.m_colorVal = 12

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _PreAction (self, table):
        setter = EdgeColorSetter(table, self.m_rowIndex, self.m_colorVal)

        # #----#----#----#
        setter.SetColor (self.m_colIndex, 1, True)
        # #----#oooo#----#


    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _DoAction (self, table):
        # #----#oooo#----#
        table.InsertColumn (self.m_colIndex - 1, TableInsertDirection.eAfter)
        # #----#oooo#oooo#----#


    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _VerifyAction (self, table, eh):
        expectedCounts = ExpectedInstanceCounts()
        expectedCounts.AddEntry(TEXTTABLE_ECCLASSNAME_Symbology, 2)
        expectedCounts.AddEntry(TEXTTABLE_ECCLASSNAME_EdgeRun, 3)

        expectedCounts.VerifyCounts(eh)

##================================================================================ = ######
# @bsistruct
#===============#===============#===============#===============#===============#======##
class SetDefaultTextSymbology(TextTableTestAction):
    def __init__ (self):
        self.m_colorVal = 12

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _DoAction (self, table):
        table.SetDefaultTextColor (self.m_colorVal)

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _VerifyAction (self, table, eh):
        color = table.GetDefaultTextColor()
        EXPECT_EQ(color, self.m_colorVal)

        expectedCounts = ExpectedInstanceCounts()
        expectedCounts.AddEntry(TEXTTABLE_ECCLASSNAME_Symbology, 2)

        expectedCounts.VerifyCounts(eh)

##================================================================================ = ######
# @bsistruct
#===============#===============#===============#===============#===============#======##
class ClearDefaultTextSymbology(TextTableTestAction):
    def __init__ (self):
        self.m_colorVal = 12
        self.m_tableColorVal = 0

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _PreAction (self, table):
        EXPECT_NE (self.m_tableColorVal, self.m_colorVal)
        table.SetDefaultTextColor (self.m_colorVal)

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _DoAction (self, table):
        table.ClearDefaultTextColor()

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _VerifyAction (self, table, eh):
        color = table.GetDefaultTextColor()
        EXPECT_EQ(color, ctypes.c_uint (-1).value)

        expectedCounts = ExpectedInstanceCounts()
        # empty - we added default text symbology, but then cleared it.

        expectedCounts.VerifyCounts(eh)

##================================================================================ = ######
# @bsistruct
#===============#===============#===============#===============#===============#======##
class DefaultTextSymbSharesEntryWithEdgeRunAction(TextTableTestAction):
    def __init__ (self):
        super ().__init__ ()
        self.m_rowIndex = 2
        self.m_colorVal = 12

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _PreAction (self, table):
        setter = EdgeColorSetter(table, self.m_rowIndex, self.m_colorVal)

        # Adds one symbology entry(total of two).
        # #----#----#----#
        setter.SetColor(0, 1, True)
        setter.SetColor(2, 1, True)
        # #oooo#----#oooo#


    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _DoAction (self, table):
        # Should not add a new symbology entry
        table.SetDefaultTextColor (self.m_colorVal)


    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _VerifyAction (self, table, eh):
        color = table.GetDefaultTextColor()
        EXPECT_EQ(color, self.m_colorVal)

        expectedCounts = ExpectedInstanceCounts()
        expectedCounts.AddEntry(TEXTTABLE_ECCLASSNAME_Symbology, 2)
        expectedCounts.AddEntry(TEXTTABLE_ECCLASSNAME_EdgeRun, 3)

        expectedCounts.VerifyCounts(eh)

##================================================================================ = ######
# @bsistruct
#===============#===============#===============#===============#===============#======##
class SetGetSymbologyAction(TextTableTestAction):
    class EdgeSymbologyId(Enum):
        A = 0
        B = 1
        C = 2
        D = 3
        E = 4

    class SetInstruction :
        def __init__ (self):
            self.m_symb = TableSymbologyValues ()
            self.m_cells = TableCellIndexArray ()


    class GetInstruction :
        def __init__ (self):
            self.m_expectedResults = []
            self.m_cells = TableCellIndexArray ()

    def __init__ (self, set, get):
        self.m_setInstructions = set
        self.m_getInstructions = get

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _DoAction (self, table):
        for instruction in self.m_setInstructions :
            table.SetEdgeSymbology(instruction.m_symb, instruction.m_edges, instruction.m_cells)

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def _VerifyAction (self, table, eh):
        for instruction in self.m_getInstructions :
            expected = instruction.m_expectedResults
            actual = TableSymbologyValuesPtrArray ()

            table.GetEdgeSymbology(actual, instruction.m_edges, instruction.m_cells)
            EXPECT_EQ(expected.__len__(), actual.__len__())

            for expectedValue in expected :
                EXPECT_TRUE(eSUCCESS == self.RemoveExpectedSymbology(expectedValue, actual))

            EXPECT_EQ(0, actual.__len__())


    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def ActualMatchedExpectedSymbology(expected, actual):
        if (expected.HasLineVisible() and expected.GetLineVisible() != actual.GetLineVisible()):
            return False

        if (expected.HasLineColor() and expected.GetLineColor() != actual.GetLineColor()):
            return False

        if (expected.HasLineStyle() and expected.GetLineStyle() != actual.GetLineStyle()):
            return False

        if (expected.HasLineWeight() and expected.GetLineWeight() != actual.GetLineWeight()):
            return False

        return True

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def RemoveExpectedSymbology (self, expected, collection):
        class FindEquivalentPredicate :
            def __init__ (self, item):
                self.m_expected = item

            def check_match (self, candidate):
                return SetGetSymbologyAction.ActualMatchedExpectedSymbology (self.m_expected, candidate)

        predicate = FindEquivalentPredicate (expected)
        for candidate in collection:
            if predicate.check_match (candidate):
                collection.remove (candidate)
                return eSUCCESS

        return eERROR

    #---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def CreateSymbValues (symbId):
        # Each one should be a unique combination.
        # These are for edges, so no fill color.
        symb = TableSymbologyValues ()

        if symbId == SetGetSymbologyAction.EdgeSymbologyId.A.value:
            symb.SetLineColor(2)
        elif symbId == SetGetSymbologyAction.EdgeSymbologyId.B.value :
            symb.SetLineColor(2)
            symb.SetLineWeight(2)
        elif symbId == SetGetSymbologyAction.EdgeSymbologyId.C.value :
            symb.SetLineColor(4)
            symb.SetLineStyle(4)
            symb.SetLineWeight(4)
        elif symbId == SetGetSymbologyAction.EdgeSymbologyId.D.value :
            symb.SetLineStyle(6)
        elif symbId == SetGetSymbologyAction.EdgeSymbologyId.E.value :
            symb.SetLineWeight(8)

        return symb

##=================================================================================######
# @bsistruct
#===============#===============#===============#===============#===============#======##
class TestTextTableActionTestFixture (TestTextTableTestTestFixture):
    def setup_method (self):
        super ().setup_method ()
        self.m_tableElementId = 0


    def CreateTable (self, testAction):
        table = testAction._CreateTable (self.GetTextStyleId(), self.model) #None #TextTable ()
        if (None != table):
            return table

        return super ().CreateBasicTable ()


    def ReadTable (self):
        EXPECT_TRUE (0 != self.m_tableElementId)

        elementRef = self.model.FindElementByID (self.m_tableElementId)
        EXPECT_TRUE (None != elementRef)

        element = EditElementHandle (elementRef)
        table = TextTableHandler.GetInstance().ExtractTextTable (element)

        return table, element

    def AddTableToModel (self, table):
        ASSERT_TRUE (0 == self.m_tableElementId)

        tableElement = EditElementHandle ()
        st = TextTableHandler.CreateTextTableElement (tableElement, table)
        st = tableElement.AddToModel()

        self.m_tableElementId = tableElement.GetElementId()

        ASSERT_TRUE (0 != self.m_tableElementId)
        #self.dgnFile.ProcessChanges(DgnSaveReason.eFileSaveAs) 
                
    def ReplaceTableInModel (self, table, elem):
        ASSERT_EQ (self.m_tableElementId, elem.GetElementId())

        TextTableHandler.GetInstance().SetTextTable (elem, table)
        elem.ReplaceInModel(elem.GetElementRef())

        ASSERT_EQ (self.m_tableElementId, elem.GetElementId())

    def DoCreateTableTest (self, testAction):
        seedTable = self.CreateTable(testAction)
        EXPECT_TRUE (None != seedTable)

        testAction._PreAction (seedTable)
        testAction._DoAction (seedTable)

        self.AddTableToModel (seedTable)

        foundTable, foundElement = self.ReadTable ()
        EXPECT_TRUE (None != foundTable)
        EXPECT_TRUE (None != foundElement)

        testAction._VerifyAction (foundTable, foundElement)


    def DoModifyTableTest (self, testAction):
        seedTable = self.CreateTable(testAction)
        EXPECT_TRUE (None != seedTable)

        testAction._PreAction (seedTable)

        self.AddTableToModel (seedTable)

        applyActionTable, applyActionElement = self.ReadTable ()
        EXPECT_TRUE (applyActionTable != None)
        EXPECT_TRUE (applyActionElement != None)

        testAction._DoAction (applyActionTable)

        self.ReplaceTableInModel (applyActionTable, applyActionElement)

        postActionTable, postActionElement = self.ReadTable ()
        EXPECT_TRUE (postActionTable != None)
        EXPECT_TRUE (postActionElement != None)

        testAction._VerifyAction (postActionTable, postActionElement)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestCreate_OverrideRowHeight (self):
         rowIndex = 1
         overrideHeightValue = 1000

         testAction = OverrideRowHeightAction (overrideHeightValue, rowIndex)
         self.DoCreateTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestCreate_OverrideColumnWidth (self):
         columnIndex = 1
         overrideWidthValue = 1000.0

         testAction = OverrideColumnWidthAction (overrideWidthValue, columnIndex)
         self.DoCreateTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestCreate_NoAction (self):
         testAction = NoAction ()
         self.DoCreateTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestModify_NoAction (self):
        testAction = NoAction ()
        self.DoModifyTableTest (testAction)    

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestModify_OverrideRowHeight (self):
        columnIndex = 1
        overrideHeightValue = 1000.0

        testAction = OverrideRowHeightAction (overrideHeightValue, columnIndex)
        self.DoModifyTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestModify_OverrideColumnWidth (self):
        columnIndex = 1
        overrideWidthValue = 1000.0

        testAction = OverrideColumnWidthAction (overrideWidthValue, columnIndex)
        self.DoModifyTableTest (testAction)


    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestCreate_ClearRowHeight (self):
        rowIndex = 1
        testAction = ClearRowHeightAction (rowIndex)
        self.DoCreateTableTest (testAction)


    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestModify_ClearRowHeight (self):
        rowIndex = 1
        testAction = ClearRowHeightAction (rowIndex)
        self.DoModifyTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestCreate_SetCellText (self):
        cellString = "Hello Table"
        cellIndex = TableCellIndex (1, 1)

        testAction = SetCellTextAction (cellString, cellIndex)
        self.DoCreateTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestModify_SetCellText (self):
        cellString = "Hello Table"
        cellIndex = TableCellIndex (1, 1)

        testAction = SetCellTextAction (cellString, cellIndex)
        self.DoModifyTableTest (testAction)


    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestCreate_ChangeCellText (self):
        cellString = "Hello Table"
        cellIndex = TableCellIndex (1, 1)

        testAction = ChangeCellTextAction (cellString, cellIndex)
        self.DoCreateTableTest (testAction)
    

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestModify_ChangeCellText (self):
        cellString = "Hello Table"
        cellIndex = TableCellIndex (1, 1)

        testAction = ChangeCellTextAction (cellString, cellIndex)
        self.DoModifyTableTest (testAction)


    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestCreate_ClearCellText (self):
        cellIndex = TableCellIndex (1, 1)

        testAction = ClearCellTextAction (cellIndex)
        self.DoCreateTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestModify_ClearCellText (self):
        cellIndex = TableCellIndex (1, 1)

        testAction = ClearCellTextAction (cellIndex)
        self.DoModifyTableTest (testAction)


    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestCreate_DeleteRow (self):
        rowIndex = 1

        testAction = DeleteRowAction (rowIndex)
        self.DoCreateTableTest (testAction)


    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestModify_DeleteRow (self):
        rowIndex = 1

        testAction = DeleteRowAction (rowIndex)
        self.DoModifyTableTest (testAction)


    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestMergeCells_TopLeft (self):
        cellIndex = TableCellIndex (0, 0)
        rowSpan = 2
        colSpan = 2

        #       0     1     2   
        #    #------------------
        #  0 #           #     #
        #    #           #-----+
        #  1 #           #     #
        #    #-----+-----+-----+
        #  2 #     #     #     #
        #    #-----+-----+-----+

        testAction = MergeCellsAction (cellIndex, rowSpan, colSpan, False)
        self.DoModifyTableTest (testAction)


    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestMergeCells_BottomRight (self):
        cellIndex = TableCellIndex (1, 1)
        rowSpan = 2
        colSpan = 2

        #       0     1     2   
        #    #-----+-----+-----#
        #  0 #     #     #     #
        #    #-----+-----+-----#
        #  1 #     #           #
        #    #-----+           #
        #  2 #     #           #
        #    #-----+-----+-----#

        testAction = MergeCellsAction (cellIndex, rowSpan, colSpan, False)
        self.DoModifyTableTest (testAction)


    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestMergeCells_FullRow (self):
        cellIndex = TableCellIndex (0, 0)
        rowSpan = 1
        colSpan = 3

        #       0     1     2  
        #    #-----------------#
        #  0 #                 #
        #    #-----+-----+-----#
        #  1 #     #     #     #
        #    #-----+-----+-----#
        #  2 #     #     #     #
        #    #-----+-----+-----#

        testAction = MergeCellsAction (cellIndex, rowSpan, colSpan, False)
        self.DoModifyTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestMergeCells_FullColumn (self):
        cellIndex = TableCellIndex (0, 2)
        rowSpan = 3
        colSpan = 1

        #       0     1     2
        #    #-----------------#
        #  0 #     #     #     #
        #    #-----+-----+     #
        #  1 #     #     #     #
        #    #-----+-----+     #
        #  2 #     #     #     #
        #    #-----+-----+-----#

        testAction = MergeCellsAction (cellIndex, rowSpan, colSpan, False)
        self.DoModifyTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestMergeCells_TooWide (self):
        cellIndex = TableCellIndex (0, 1)
        rowSpan = 1
        colSpan = 3

        #       0     1     2 
        #    #----------------#
        #  0 #     # fail     xxxx
        #    #-----+-----+----#
        #  1 #     #     #    #
        #    #-----+-----+----#
        #  2 #     #     #    #
        #    #-----+-----+----#

        testAction = MergeCellsAction (cellIndex, rowSpan, colSpan, True)
        self.DoModifyTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestMergeCells_TooTall (self):
        cellIndex = TableCellIndex (1, 2)
        rowSpan = 3
        colSpan = 1

        #       0     1     2
        #    #-----------------#
        #  0 #     #     #     #  origin 1,2
        #    #-----+-----+-----#  span   3,1
        #  1 #     #     #     #
        #    #-----+-----+ fail#
        #  2 #     #     #     #
        #    #-----+-----+     #
        #                 xxxxx

        testAction = MergeCellsAction (cellIndex, rowSpan, colSpan, True)
        self.DoModifyTableTest (testAction)


    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestMergeCellsWithExisting_AboveLeft (self):
        old = MergeDescr (TableCellIndex (2, 1), 2, 2)
        cellIndex = TableCellIndex (0, 0)
        rowSpan = 2
        colSpan = 2

        #       0     1     2     3             0     1     2     3             0     1     2     3
        #    #-----------------------#  +    #-----------------------# =    #-----------------------#
        #  0 #     #     #     #     #  +  0 #origin 0,0 #     #     # =  0 #           #     #     #
        #    #-----+-----+-----+-----#  +    #span   2,2 #-----+-----# =    #   new     #-----+-----#
        #  1 #     #     #     #     #  +  1 #           #     #     # =  1 #           #     #     #
        #    #-----+-----+-----+-----#  +    #-----+-----+-----+-----# =    #-----+-----+-----+-----#
        #  2 #     #           #     #  +  2 #     #     #     #     # =  2 #     #           #     #
        #    #-----+    old    #-----#  +    #-----+-----+-----+-----# =    #-----+    old    #-----#
        #  3 #     #           #     #  +  3 #     #     #     #     # =  3 #     #           #     #
        #    #-----+-----+-----+-----#  +    #-----+-----+-----+-----# =    #-----+-----+-----+-----#

        testAction = MergeCellsWithExistingAction (old, cellIndex, rowSpan, colSpan, False, False)
        self.DoModifyTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestMergeCellsWithExisting_AboveRight (self):
        old = MergeDescr (TableCellIndex (2, 1), 2, 2)
        cellIndex = TableCellIndex (0, 2)
        rowSpan = 2
        colSpan = 2

        #       0     1     2     3            0     1     2     3              0     1     2     3  
        #    #-----------------------#  +    #-----------------------# =    #-----------------------#
        #  0 #     #     #     #     #  +  0 #     #     #origin 0,2 # =  0 #     #     #           #
        #    #-----+-----+-----+-----#  +    #-----+-----+span   2,2 # =    #-----+-----+    new    #
        #  1 #     #     #     #     #  +  1 #     #     #           # =  1 #     #     #           #
        #    #-----+-----+-----+-----#  +    #-----+-----+-----+-----# =    #-----+-----+-----+-----#
        #  2 #     #           #     #  +  2 #     #     #     #     # =  2 #     #           #     #
        #    #-----+    old    #-----#  +    #-----+-----+-----+-----# =    #-----+    old    #-----#
        #  3 #     #           #     #  +  3 #     #     #     #     # =  3 #     #           #     #
        #    #-----+-----+-----+-----#  +    #-----+-----+-----+-----# =    #-----+-----+-----+-----#

        testAction = MergeCellsWithExistingAction (old, cellIndex, rowSpan, colSpan, False, False)
        self.DoModifyTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestMergeCellsWithExisting_ConsumedLeft (self):
        old = MergeDescr (TableCellIndex (0, 0), 1, 2)
        cellIndex = TableCellIndex (0, 0)
        rowSpan = 1
        colSpan = 3

        #       0     1     2     3            0     1     2     3              0     1     2     3  
        #    #-----------------------#  +    #-----------------------# =    #-----------------------#
        #  0 #    old    #     #     #  +  0 #       new       #     # =  0 #     consumed    #     #
        #    #-----+-----+-----+-----#  +    #-----+-----+-----+-----# =    #-----+-----+-----+-----#
        #  1 #     #     #     #     #  +  1 #     #     #     #     # =  1 #     #     #     #     #
        #    #-----+-----+-----+-----#  +    #-----+-----+-----+-----# =    #-----+-----+-----+-----#
        #  2 #     #     #     #     #  +  2 #     #     #     #     # =  2 #     #     #     #     #
        #    #-----+-----+-----#-----# =    #-----+-----+-----#-----#       #-----+-----+-----#-----#
        #  3 #     #     #     #     #  +  3 #     #     #     #     # =  3 #     #     #     #     #
        #    #-----+-----+-----+-----#  +    #-----+-----+-----+-----# =    #-----+-----+-----+-----#

        testAction = MergeCellsWithExistingAction (old, cellIndex, rowSpan, colSpan, False, True)
        self.DoModifyTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestMergeCellsWithExisting_ConsumedRight (self):
        old = MergeDescr (TableCellIndex (1, 1), 1, 2)
        cellIndex = TableCellIndex (1, 0)
        rowSpan = 1
        colSpan = 3

        #       0     1     2     3            0     1     2     3              0     1     2     3  
        #    #-----------------------#  +    #-----------------------# =    #-----------------------#
        #  0 #     #     #     #     #  +  0 #     #     #     #     # =  0 #     #     #     #     #
        #    #-----+-----+-----+-----#  +    #-----+-----+-----+-----# =    #-----+-----+-----+-----#
        #  1 #     #    old    #     #  +  1 #       new       #     # =  1 #     consumed    #     #
        #    #-----+-----+-----+-----#  +    #-----+-----+-----+-----# =    #-----+-----+-----+-----#
        #  2 #     #     #     #     #  +  2 #     #     #     #     # =  2 #     #     #     #     #
        #    #-----+-----+-----#-----# =    #-----+-----+-----#-----#       #-----+-----+-----#-----#
        #  3 #     #     #     #     #  +  3 #     #     #     #     # =  3 #     #     #     #     #
        #    #-----+-----+-----+-----#  +    #-----+-----+-----+-----# =    #-----+-----+-----+-----#

        testAction = MergeCellsWithExistingAction (old, cellIndex, rowSpan, colSpan, False, True)
        self.DoModifyTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestMergeCellsWithExisting_ConsumedFromAbove (self):
        old = MergeDescr (TableCellIndex (2, 1), 2, 2)
        cellIndex = TableCellIndex (0, 1)
        rowSpan = 4
        colSpan = 2

        #       0     1     2     3            0     1     2     3              0     1     2     3  
        #    #-----------------------#  +    #-----------------------# =    #-----------------------#
        #  0 #     #     #     #     #  +  0 #     #           #     # =  0 #     #           #     #
        #    #-----+-----+-----+-----#  +    #-----+           #-----# =    #-----+           #-----#
        #  1 #     #     #     #     #  +  1 #     #           #     # =  1 #     #           #     #
        #    #-----+-----+-----+-----#  +    #-----+    new    #-----# =    #-----+  consumed #-----#
        #  2 #     #           #     #  +  2 #     #           #     # =  2 #     #           #     #
        #    #-----+    old    #-----#  +    #-----+           #-----# =    #-----+           #-----#
        #  3 #     #           #     #  +  3 #     #           #     # =  3 #     #           #     #
        #    #-----+-----+-----+-----#  +    #-----+-----+-----+-----# =    #-----+-----+-----+-----#

        testAction = MergeCellsWithExistingAction (old, cellIndex, rowSpan, colSpan, False, True)
        self.DoModifyTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestMergeCellsWithExisting_ConsumedLeftAndRight (self):
        old = MergeDescr (TableCellIndex (2, 1), 2, 2)
        cellIndex = TableCellIndex (2, 0)
        rowSpan = 2
        colSpan = 4

        #       0     1     2     3            0     1     2     3              0     1     2     3  
        #    #-----------------------#  +    #-----------------------# =    #-----------------------#
        #  0 #     #     #     #     #  +  0 #     #     #     #     # =  0 #     #     #     #     #
        #    #-----+-----+-----+-----#  +    #-----+-----+-----+-----# =    #-----+-----+-----+-----#
        #  1 #     #     #     #     #  +  1 #     #     #     #     # =  1 #     #     #     #     #
        #    #-----+-----+-----+-----#  +    #-----+-----+-----+-----# =    #-----+-----+-----+-----#
        #  2 #     #           #     #  +  2 #                       # =  2 #                       #
        #    #-----+    old    #-----#  +    #          new          # =    #       consumed        #
        #  3 #     #           #     #  +  3 #                       # =  3 #                       #
        #    #-----+-----+-----+-----#  +    #-----+-----+-----+-----# =    #-----+-----+-----+-----#

        testAction = MergeCellsWithExistingAction (old, cellIndex, rowSpan, colSpan, False, True)
        self.DoModifyTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestMergeCellsWithExisting_ConsumedFromAboveLeft (self):
        old = MergeDescr (TableCellIndex (2, 1), 2, 2)
        cellIndex = TableCellIndex (0, 0)
        rowSpan = 4
        colSpan = 3

        #       0     1     2     3            0     1     2     3              0     1     2     3  
        #    #-----------------------#  +    #-----------------------# =    #-----------------------#
        #  0 #     #     #     #     #  +  0 #                 #     # =  0 #                 #     #
        #    #-----+-----+-----+-----#  +    #                 #-----# =    #                 #-----#
        #  1 #     #     #     #     #  +  1 #                 #     # =  1 #                 #     #
        #    #-----+-----+-----+-----#  +    #       new       #-----# =    #    consumed     #-----#
        #  2 #     #           #     #  +  2 #                 #     # =  2 #                 #     #
        #    #-----+    old    #-----#  +    #                 #-----# =    #                 #-----#
        #  3 #     #           #     #  +  3 #                 #     # =  3 #                 #     #
        #    #-----+-----+-----+-----#  +    #-----+-----+-----+-----# =    #-----+-----+-----+-----#

        testAction = MergeCellsWithExistingAction (old, cellIndex, rowSpan, colSpan, False, True)
        self.DoModifyTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestMergeCellsWithExisting_OverlapOneCell (self):
        old = MergeDescr (TableCellIndex (2, 1), 2, 2)
        cellIndex = TableCellIndex (0, 2)
        rowSpan = 3
        colSpan = 1

        #       0     1     2     3            0     1     2     3         
        #    #-----------------------#  +    #-----------------------# =  
        #  0 #     #     #     #     #  +  0 #     #     #     #     # =  
        #    #-----+-----+-----+-----#  +    #-----+-----+     #-----# =  
        #  1 #     #     #     #     #  +  1 #     #     # new #     # =   FAIL
        #    #-----+-----+-----+-----#  +    #-----+-----+     #-----# =   DUE TO
        #  2 #     #           #     #  +  2 #     #     #     #     # =   OVERLAP
        #    #-----+    old    #-----#  +    #-----+-----+-----+-----# =  
        #  3 #     #           #     #  +  3 #     #     #     #     # =  
        #    #-----+-----+-----+-----#  +    #-----+-----+-----+-----# =  

        testAction = MergeCellsWithExistingAction (old, cellIndex, rowSpan, colSpan, True, False)
        self.DoModifyTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestMergeCellsWithExisting_OverlapTwoCell (self):
        old = MergeDescr (TableCellIndex (2, 1), 2, 2)
        cellIndex = TableCellIndex (0, 1)
        rowSpan = 3
        colSpan = 2

        #       0     1     2     3            0     1     2     3         
        #    #-----------------------#  +    #-----------------------# =  
        #  0 #     #     #     #     #  +  0 #     #           #     # =  
        #    #-----+-----+-----+-----#  +    #-----+           #-----# =  
        #  1 #     #     #     #     #  +  1 #     #    new    #     # =   FAIL
        #    #-----+-----+-----+-----#  +    #-----+           #-----# =   DUE TO
        #  2 #     #           #     #  +  2 #     #           #     # =   OVERLAP
        #    #-----+    old    #-----#  +    #-----+-----+-----+-----# =  
        #  3 #     #           #     #  +  3 #     #     #     #     # =  
        #    #-----+-----+-----+-----#  +    #-----+-----+-----+-----# =  

        testAction = MergeCellsWithExistingAction (old, cellIndex, rowSpan, colSpan, True, False)
        self.DoModifyTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestMergeCellsWithExisting_OverlapAcrossTop (self):
        old = MergeDescr (TableCellIndex (2, 1), 2, 2)
        cellIndex = TableCellIndex (2, 0)
        rowSpan = 1
        colSpan = 4

        #       0     1     2     3            0     1     2     3         
        #    #-----------------------#  +    #-----------------------# =  
        #  0 #     #     #     #     #  +  0 #     #     #     #     # =  
        #    #-----+-----+-----+-----#  +    #-----+-----+-----+-----# =  
        #  1 #     #     #     #     #  +  1 #     #     #     #     # =   FAIL
        #    #-----+-----+-----+-----#  +    #-----+-----+-----+-----# =   DUE TO
        #  2 #     #           #     #  +  2 #          new          # =   OVERLAP
        #    #-----+    old    #-----#  +    #-----+-----+-----+-----# =  
        #  3 #     #           #     #  +  3 #     #     #     #     # =  
        #    #-----+-----+-----+-----#  +    #-----+-----+-----+-----# =  

        testAction = MergeCellsWithExistingAction (old, cellIndex, rowSpan, colSpan, True, False)
        self.DoModifyTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestMergeCellsWithExisting_OverlapAcrossBottom (self):
        old = MergeDescr (TableCellIndex (2, 1), 2, 2)
        cellIndex = TableCellIndex (3, 0)
        rowSpan = 1
        colSpan = 4

        #       0     1     2     3            0     1     2     3         
        #    #-----------------------#  +    #-----------------------# =  
        #  0 #     #     #     #     #  +  0 #     #     #     #     # =  
        #    #-----+-----+-----+-----#  +    #-----+-----+-----+-----# =  
        #  1 #     #     #     #     #  +  1 #     #     #     #     # =   FAIL
        #    #-----+-----+-----+-----#  +    #-----+-----+-----+-----# =   DUE TO
        #  2 #     #           #     #  +  2 #     #     #     #     # =   OVERLAP
        #    #-----+    old    #-----#  +    #-----+-----+-----+-----# =  
        #  3 #     #           #     #  +  3 #          new          # =  
        #    #-----+-----+-----+-----#  +    #-----+-----+-----+-----# =  

        testAction = MergeCellsWithExistingAction (old, cellIndex, rowSpan, colSpan, True, False)
        self.DoModifyTableTest (testAction)


    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestDeleteMergedCells_Nothing (self):
        testAction = DeleteMergedCellsAction (DeleteMergedCellsAction.DeleteTarget.NOTHING)
        self.DoModifyTableTest (testAction)


    def test_TextTableActionTestDeleteMergedCells_RowBefore (self):
        testAction = DeleteMergedCellsAction (DeleteMergedCellsAction.DeleteTarget.ROW_BEFORE)
        self.DoModifyTableTest (testAction)


    def test_TextTableActionTestDeleteMergedCells_RowWithRoot (self):
        testAction = DeleteMergedCellsAction (DeleteMergedCellsAction.DeleteTarget.ROW_WITH_ROOT)
        self.DoModifyTableTest (testAction)


    def test_TextTableActionTestDeleteMergedCells_RowInterior (self):
        testAction = DeleteMergedCellsAction (DeleteMergedCellsAction.DeleteTarget.ROW_INTERIOR)
        self.DoModifyTableTest (testAction)


    def test_TextTableActionTestDeleteMergedCells_RowAllMerged (self):
        testAction = DeleteMergedCellsAction (DeleteMergedCellsAction.DeleteTarget.ROW_ALL_MERGED)
        self.DoModifyTableTest (testAction)


    def test_TextTableActionTestDeleteMergedCells_RowAfter (self):
        testAction = DeleteMergedCellsAction (DeleteMergedCellsAction.DeleteTarget.ROW_AFTER)
        self.DoModifyTableTest (testAction)


    def test_TextTableActionTestDeleteMergedCells_ColumnBefore (self):
        testAction = DeleteMergedCellsAction (DeleteMergedCellsAction.DeleteTarget.COLUMN_BEFORE)
        self.DoModifyTableTest (testAction)


    def test_TextTableActionTestDeleteMergedCells_ColumnWithRoot (self):
        testAction = DeleteMergedCellsAction (DeleteMergedCellsAction.DeleteTarget.COLUMN_WITH_ROOT)
        self.DoModifyTableTest (testAction)


    def test_TextTableActionTestDeleteMergedCells_ColumnInterior (self):
        testAction = DeleteMergedCellsAction (DeleteMergedCellsAction.DeleteTarget.COLUMN_INTERIOR)
        self.DoModifyTableTest (testAction)


    def test_TextTableActionTestDeleteMergedCells_ColumnAllMerged (self):
        testAction = DeleteMergedCellsAction (DeleteMergedCellsAction.DeleteTarget.COLUMN_ALL_MERGED)
        self.DoModifyTableTest (testAction)


    def test_TextTableActionTestDeleteMergedCells_ColumnAfter (self):
        testAction = DeleteMergedCellsAction (DeleteMergedCellsAction.DeleteTarget.COLUMN_AFTER)
        self.DoModifyTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestInsertMergedCells_Nothing (self):
        testAction = InsertMergedCellsAction (InsertMergedCellsAction.InsertTarget.Nothing)
        self.DoModifyTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestInsertMergedCells_RowBefore (self):
        testAction = InsertMergedCellsAction (InsertMergedCellsAction.InsertTarget.RowBefore)
        self.DoModifyTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestInsertMergedCells_RowJustBefore (self):
        testAction = InsertMergedCellsAction (InsertMergedCellsAction.InsertTarget.RowJustBefore)
        self.DoModifyTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestInsertMergedCells_RowInterior (self):
        testAction = InsertMergedCellsAction (InsertMergedCellsAction.InsertTarget.RowInterior)
        self.DoModifyTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestInsertMergedCells_RowJustAfter (self):
        testAction = InsertMergedCellsAction (InsertMergedCellsAction.InsertTarget.RowJustAfter)
        self.DoModifyTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestInsertMergedCells_RowAfter (self):
        testAction = InsertMergedCellsAction (InsertMergedCellsAction.InsertTarget.RowAfter)
        self.DoModifyTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestInsertMergedCells_ColumnBefore (self):
        testAction = InsertMergedCellsAction (InsertMergedCellsAction.InsertTarget.ColumnBefore)
        self.DoModifyTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestInsertMergedCells_ColumnJustBefore (self):
        testAction = InsertMergedCellsAction (InsertMergedCellsAction.InsertTarget.ColumnJustBefore)
        self.DoModifyTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestInsertMergedCells_ColumnInterior (self):
        testAction = InsertMergedCellsAction (InsertMergedCellsAction.InsertTarget.ColumnInterior)
        self.DoModifyTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestInsertMergedCells_ColumnJustAfter (self):
        testAction = InsertMergedCellsAction (InsertMergedCellsAction.InsertTarget.ColumnJustAfter)
        self.DoModifyTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestInsertMergedCells_ColumnAfter (self):
        testAction = InsertMergedCellsAction (InsertMergedCellsAction.InsertTarget.ColumnAfter)
        self.DoModifyTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestCreate_SetEdgeColorAtStart (self):
        colorVal = 12
        rowIndex = 0
        colStart = 0
        colSpan = 1
        isTop   = False

        testAction = SetEdgeColorAction (colorVal, rowIndex, colStart, colSpan, isTop)

        # #oooo#----#----#
        testAction.SetExpectedRunCount(2)

        self.DoCreateTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestModify_SetEdgeColorAtStart (self):
        colorVal = 12
        rowIndex = 0
        colStart = 0
        colSpan = 1
        isTop   = False

        testAction = SetEdgeColorAction (colorVal, rowIndex, colStart, colSpan, isTop)

        # #oooo#----#----#
        testAction.SetExpectedRunCount(2)

        self.DoModifyTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestCreate_SetEdgeColorInterior (self):
        colorVal = 12
        rowIndex = 0
        colStart = 1
        colSpan = 1
        isTop   = False

        testAction = SetEdgeColorAction (colorVal, rowIndex, colStart, colSpan, isTop)

        # #----#oooo#----#
        testAction.SetExpectedRunCount(3)

        self.DoCreateTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestModify_SetEdgeColorInterior (self):
        colorVal = 12
        rowIndex = 0
        colStart = 1
        colSpan = 1
        isTop   = False

        testAction = SetEdgeColorAction (colorVal, rowIndex, colStart, colSpan, isTop)

        # #----#oooo#----#
        testAction.SetExpectedRunCount(3)

        self.DoModifyTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestCreate_SetEdgeColorAtEnd (self):
        colorVal = 12
        rowIndex = 0
        colStart = 1
        colSpan = 2
        isTop   = False

        testAction = SetEdgeColorAction (colorVal, rowIndex, colStart, colSpan, isTop)

        # #----#oooo#oooo#
        testAction.SetExpectedRunCount(2)

        self.DoCreateTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestModify_SetEdgeColorAtEnd (self):
        colorVal = 12
        rowIndex = 0
        colStart = 1
        colSpan = 2
        isTop   = False

        testAction = SetEdgeColorAction (colorVal, rowIndex, colStart, colSpan, isTop)

        # #----#oooo#oooo#
        testAction.SetExpectedRunCount(2)

        self.DoModifyTableTest (testAction)


    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestCreate_MergeAdjacentEdgeRuns (self):
        testAction = MergeAdjacentEdgeRunsAction ()
        self.DoCreateTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestModify_MergeAdjacentEdgeRuns (self):
        testAction = MergeAdjacentEdgeRunsAction ()
        self.DoModifyTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestCreate_MergeNonAdjacentEdgeRuns (self):
        testAction = MergeNonAdjacentEdgeRunsAction ()
        self.DoCreateTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestModify_MergeNonAdjacentEdgeRuns (self):
        testAction = MergeNonAdjacentEdgeRunsAction ()
        self.DoModifyTableTest (testAction)


    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestCreate_DeleteColumnJoinsEdgeRuns (self):
        testAction = DeleteColumnJoinsEdgeRunsAction ()
        self.DoCreateTableTest (testAction)


    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestModify_DeleteColumnJoinsEdgeRuns (self):
        testAction = DeleteColumnJoinsEdgeRunsAction ()
        self.DoModifyTableTest (testAction)


    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestCreate_DeleteColumnRemovesSymbologyEntry (self):
        testAction = DeleteColumnRemovesSymbologyEntryAction ()
        self.DoCreateTableTest (testAction)


    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestModify_DeleteColumnRemovesSymbologyEntry (self):
        testAction = DeleteColumnRemovesSymbologyEntryAction ()
        self.DoModifyTableTest (testAction)


    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestCreate_InsertColumnExtendsSymbology (self):
        testAction = InsertColumnExtendsSymbologyAction ()
        self.DoCreateTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestModify_InsertColumnExtendsSymbology (self):
        testAction = InsertColumnExtendsSymbologyAction ()
        self.DoModifyTableTest (testAction)


    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestCreate_SetDefaultTextSymbology (self):
        testAction = SetDefaultTextSymbology ()
        self.DoCreateTableTest (testAction)


    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestModify_SetDefaultTextSymbology (self):
        testAction = SetDefaultTextSymbology ()
        self.DoModifyTableTest (testAction)


    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestCreate_ClearDefaultTextSymbology (self):
        testAction = ClearDefaultTextSymbology ()
        self.DoCreateTableTest (testAction)


    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestModify_ClearDefaultTextSymbology (self):
        testAction = ClearDefaultTextSymbology ()
        self.DoModifyTableTest (testAction)


    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestCreate_DefaultTextSymbSharesEntryWithEdgeRunAction (self):
        testAction = DefaultTextSymbSharesEntryWithEdgeRunAction ()
        self.DoCreateTableTest (testAction)


    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestModify_DefaultTextSymbSharesEntryWithEdgeRunAction (self):
        testAction = DefaultTextSymbSharesEntryWithEdgeRunAction ()
        self.DoModifyTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestCreate_SetGetSymbology_Simple (self):
        setInstructions = []
        getInstructions = []

        #       0     1     2
        #    #-----------------#
        #  0 #     #     #     #
        #    #-----+-----+-----#
        #  1 #     #     #     #
        #    #--a--+--a--+-----#
        #  2 #     b     #     #
        #    #-----+-----+-----#
        #  3 #     c     #     #
        #    #-----+-----+-----#
        #  4 #     #     #     #
        #    #-----#-----#-----#

        symbIdA = SetGetSymbologyAction.EdgeSymbologyId.A.value
        symbIdB = SetGetSymbologyAction.EdgeSymbologyId.B.value
        symbIdC = SetGetSymbologyAction.EdgeSymbologyId.C.value

        # Set symb A on two edges
        setInstruction = SetGetSymbologyAction.SetInstruction ()

        setInstruction.m_symb = SetGetSymbologyAction.CreateSymbValues(symbIdA)
        setInstruction.m_edges = TableCellListEdges.eTop
        setInstruction.m_cells.append (TableCellIndex (2, 0))
        setInstruction.m_cells.append (TableCellIndex (2, 1))

        setInstructions.append (setInstruction)
    

        # Set symb B on one edge
        setInstruction = SetGetSymbologyAction.SetInstruction ()

        setInstruction.m_symb = SetGetSymbologyAction.CreateSymbValues(symbIdB)
        setInstruction.m_edges = TableCellListEdges.eRight
        setInstruction.m_cells.append (TableCellIndex (2, 0))

        setInstructions.append (setInstruction)


        # Set symb C on one edge
        setInstruction = SetGetSymbologyAction.SetInstruction ()

        setInstruction.m_symb = SetGetSymbologyAction.CreateSymbValues(symbIdC)
        setInstruction.m_edges = TableCellListEdges.eLeft
        setInstruction.m_cells.append (TableCellIndex (3, 1))

        setInstructions.append (setInstruction)

        # Expect symb A
        getInstruction = SetGetSymbologyAction.GetInstruction ()

        getInstruction.m_edges = TableCellListEdges.eBottom
        getInstruction.m_cells.append (TableCellIndex (1, 0))
        getInstruction.m_cells.append (TableCellIndex (1, 1))
        getInstruction.m_expectedResults.append (SetGetSymbologyAction.CreateSymbValues(symbIdA))

        getInstructions.append (getInstruction)

        # Expect symbs B and C
        getInstruction = SetGetSymbologyAction.GetInstruction ()

        getInstruction.m_edges = TableCellListEdges.eRight
        getInstruction.m_cells.append (TableCellIndex (2, 0))
        getInstruction.m_cells.append (TableCellIndex (3, 0))
        getInstruction.m_expectedResults.append (SetGetSymbologyAction.CreateSymbValues(symbIdB))
        getInstruction.m_expectedResults.append (SetGetSymbologyAction.CreateSymbValues(symbIdC))

        getInstructions.append (getInstruction)

        testAction = SetGetSymbologyAction (setInstructions, getInstructions)
        self.DoCreateTableTest (testAction)

    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTableActionTestCreate_SetGetSymbology_OutsideInside (self):
        setInstructions = []
        getInstructions = []

        #       0     1     2
        #    #-----------------#
        #  0 #     #     #     #
        #    #-----+-----+-----#
        #  1 #     #     #     #
        #    #--a--+--a--+--a--#
        #  2 a     c     c     a
        #    #--b--+--b--+--a--#
        #  3 a     c     a     #
        #    #--b--+--b--+-----#
        #  4 a     c     a     #
        #    #--a--#--a--#-----#

        symbIdA = SetGetSymbologyAction.EdgeSymbologyId.A
        symbIdB = SetGetSymbologyAction.EdgeSymbologyId.B
        symbIdC = SetGetSymbologyAction.EdgeSymbologyId.C

        cells = TableCellIndexArray ()
        cells.append (TableCellIndex (2, 0))
        cells.append (TableCellIndex (2, 1))
        cells.append (TableCellIndex (2, 2))
        cells.append (TableCellIndex (3, 0))
        cells.append (TableCellIndex (3, 1))
        cells.append (TableCellIndex (4, 0))
        cells.append (TableCellIndex (4, 1))

        # Set symb A on outside edges
        setInstruction = SetGetSymbologyAction.SetInstruction ()

        setInstruction.m_symb = SetGetSymbologyAction.CreateSymbValues(symbIdA)
        setInstruction.m_edges = TableCellListEdges.eExterior
        setInstruction.m_cells = cells

        setInstructions.append (setInstruction)

        # Set symb B on horizontal inside edges
        setInstruction = SetGetSymbologyAction.SetInstruction ()

        setInstruction.m_symb = SetGetSymbologyAction.CreateSymbValues(symbIdB)
        setInstruction.m_edges = TableCellListEdges.eInteriorHorizontal
        setInstruction.m_cells = cells

        setInstructions.append (setInstruction)

        # Set symb C on vertical inside edges
        setInstruction = SetGetSymbologyAction.SetInstruction ()

        setInstruction.m_symb = SetGetSymbologyAction.CreateSymbValues(symbIdC)
        setInstruction.m_edges = TableCellListEdges.eInteriorVertical
        setInstruction.m_cells = cells

        setInstructions.append (setInstruction)

        # Expect symb A only outside edges
        getInstruction = SetGetSymbologyAction.GetInstruction ()

        getInstruction.m_edges = TableCellListEdges.eExterior
        getInstruction.m_cells = cells
        getInstruction.m_expectedResults.append (SetGetSymbologyAction.CreateSymbValues(symbIdA))

        getInstructions.append (getInstruction)

        # Expect symbs B and C on inside edges
        getInstruction = SetGetSymbologyAction.GetInstruction ()

        getInstruction.m_edges = TableCellListEdges.eInterior
        getInstruction.m_cells = cells
        getInstruction.m_expectedResults.append (SetGetSymbologyAction.CreateSymbValues(symbIdB))
        #getInstruction.m_expectedResults.append (SetGetSymbologyAction.CreateSymbValues(symbIdC))

        getInstructions.append (getInstruction)

        # Expect symbs A, B and C on all edges
        getInstruction = SetGetSymbologyAction.GetInstruction ()

        getInstruction.m_edges = TableCellListEdges.eAll
        getInstruction.m_cells = cells
        getInstruction.m_expectedResults.append (SetGetSymbologyAction.CreateSymbValues(symbIdA))
        #getInstruction.m_expectedResults.append (SetGetSymbologyAction.CreateSymbValues(symbIdB))
        #getInstruction.m_expectedResults.append (SetGetSymbologyAction.CreateSymbValues(symbIdC))

        getInstructions.append (getInstruction)

        # Expect symbs A, B on bottom of second row
        getInstruction = SetGetSymbologyAction.GetInstruction ()

        getInstruction.m_edges = TableCellListEdges.eBottom
        getInstruction.m_cells.append (TableCellIndex (2, 0))
        getInstruction.m_cells.append (TableCellIndex (2, 1))
        getInstruction.m_cells.append (TableCellIndex (2, 2))
        getInstruction.m_expectedResults.append (SetGetSymbologyAction.CreateSymbValues(symbIdA))
        #getInstruction.m_expectedResults.append (SetGetSymbologyAction.CreateSymbValues(symbIdB))

        getInstructions.append (getInstruction)

        testAction = SetGetSymbologyAction (setInstructions, getInstructions)
        self.DoCreateTableTest (testAction)  #TODO...

##---------------------------------------------------------------------------------######
# @bsimethod                                                    Ping.Chen      03/2024
#---------------+---------------+---------------+---------------+---------------+------##
def addIndent (indent):
    childIndent= WString (indent)
    childIndent = childIndent.AppendA (WString ("    ").GetWCharCP ())

    return childIndent

##---------------------------------------------------------------------------------######
# @bsimethod                                                    Ping.Chen    03/2024
#---------------+---------------+---------------+---------------+---------------+------##
def appendFormattedString (out_stream, fmt_str, *args):
    formatted_line = fmt_str.format(*args)
    out_stream.AppendA (formatted_line)

##---------------------------------------------------------------------------------######
# @bsimethod                                                    Ping.Chen      03/2024
#---------------+---------------+---------------+---------------+---------------+------##
def valuesCollectionToString (collection, indent):
    outStr = WString ()

    for propertyValue in collection:
        value = propertyValue.GetValue()
        accessor = propertyValue.GetValueAccessor()
        accessString = accessor.GetManagedAccessString ()

        appendFormattedString (outStr, "{}{}: {}\n", indent, accessString, value.ToString())

        if (propertyValue.HasChildValues ()):
            childIndent = addIndent (indent)
            childString = valuesCollectionToString (propertyValue.GetChildValues(), childIndent.GetWCharCP ())

            outStr.AppendA (childString.GetWCharCP ())

    appendFormattedString (outStr, "\n")

    return outStr

##---------------------------------------------------------------------------------######
# @bsimethod                                                    Ping.Chen      03/2024
#---------------+---------------+---------------+---------------+---------------+------##
def instanceToString (instance, verbosity, indent):
    outStr = WString ()

    instanceEnabler = instance.GetEnabler()
    instanceClass   = instance.GetClass()
    instanceSchema  = instanceClass.GetSchema()

    if verbosity == 0:
        appendFormattedString (outStr, "{0}InstanceId: {1} Class: {2}:{3} \n", indent,
                                                                                instance.GetInstanceId ().c_str (),
                                                                                instanceSchema.GetName ().c_str (),
                                                                                instanceClass.GetName ().c_str ())
    else:
        appendFormattedString (outStr, "\n{0}---------------------",  indent)
        appendFormattedString (outStr, "\n{0}Instance Enabler:  {1}", indent, instanceEnabler.GetName())
        appendFormattedString (outStr, "\n{0}Instance schema:   {1}", indent, instanceSchema.GetName())
        appendFormattedString (outStr, "\n{0}Instance class:    {1}", indent, instanceClass.GetName())
        appendFormattedString (outStr, "\n{0}Instance ID:       {1}", indent, instance.GetInstanceId())
        appendFormattedString (outStr, "\n")


    if (0 == verbosity):
        return outStr

    collection = ECValuesCollection.Create (instance)

    childIndent = addIndent (indent)
    childString = valuesCollectionToString (collection, childIndent.GetWCharCP ())

    outStr.AppendA (childString.GetWCharCP ())

    return outStr


##=================================================================================######
# @bsistruct
#===============#===============#===============#===============#===============#======##
class TestTextTablePropertyTestTestFixture (TestTextTableTestTestFixture):
    def setup_method (self):
        super ().setup_method ()

    def teardown_method (self):
        super ().teardown_method ()


    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen    03/2024
    #---------------+---------------+---------------+---------------+---------------+------##

    def test_TextTablePropertyTestGetHeaderInstance (self):
        seedTable = super ().CreateBasicTable ()

        ASSERT_TRUE (None != seedTable)

        EXPECT_EQ (5, seedTable.GetRowCount ())
        EXPECT_EQ (3, seedTable.GetColumnCount ())

        tableElement = EditElementHandle ()
        TextTableHandler.CreateTextTableElement (tableElement, seedTable)

        query = ECQuery.CreateQuery(eECQUERY_PROCESS_SearchAllClasses)
        scope = FindInstancesScope.CreateScope (tableElement, FindInstancesScopeOption (DgnECHostType.eElement))

        index = 0

        print ("Listing instances\n")
        instanceCollection = DgnECManager.GetManager().FindInstances (scope, query)
        it = iter (instanceCollection)
        instance = next (it)
        instances = [value for value in it]
        for inst in instanceCollection[0]:
            ASSERT_TRUE (None != inst)

            instanceStr = instanceToString (inst, 1, "        ")

            print ("    Instance %d\n", index)
            index += 1

            print (instanceStr)


        print ("Count %d\n", index)


    ##---------------------------------------------------------------------------------######
    # @bsimethod                                                    Ping.Chen   03/2024
    #---------------+---------------+---------------+---------------+---------------+------##
    def test_TextTablePropertyTestTableNameAndDescription (self):
        table = super ().CreateBasicTable ()
        table.SetTableName (WString ("TestTableName"))
        table.TableDescription = WString ("TestTableDescription")

        EXPECT_TRUE ( table.GetTableName ().CompareTo ("TestTableName") == 0 )
        EXPECT_TRUE ( WString (str(table.TableDescription)).CompareTo ("TestTableDescription") == 0 )
    