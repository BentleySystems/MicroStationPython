# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright:(c) 2025 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''

import time
import win32gui
from MSPyDgnView import *
from MSPyBentley import *
from MSPyECObjects import *
from MSPyBentleyGeom import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *

from PyQt5 import QtCore
from PyQt5.QtWidgets import QApplication, QMainWindow, QToolBar, QAction, QTableWidget, QTableWidgetItem, QVBoxLayout, QWidget

class TextTableForm(QMainWindow):
    def __init__(self):
        """
        Initializes the ManagedTextTableExample class.

        This constructor initializes the DGN model and file references, sets up the text style height and table element ID,
        and initializes the user interface.

        Attributes:
            dgnModel (DgnModel): The active DGN model reference.
            dgnFile (DgnFile): The active DGN file reference.
            m_textStyleHeight (float): The height of the text style, initialized to 0.
            m_tableElementId (int or None): The ID of the table element, initialized to None.

        Methods:
            initUI(): Initializes the user interface.

        Raises:
            None

        Side Effects:
            Displays a message in the MessageCenter indicating whether the DGN model was selected successfully or not.
        """
        super().__init__()
        self.dgnModel = ISessionMgr.ActiveDgnModelRef.GetDgnModel()
        self.dgnFile = ISessionMgr.GetActiveDgnFile()
        if self.dgnModel != None:
            MessageCenter.ShowInfoMessage("DGN Model selected successfully.", "", False)
        else:
            MessageCenter.ShowErrorMessage("No DGN Model selected.", "", False)
        self.m_textStyleHeight = 0
        self.m_tableElementId = None
        self.initUI()

    def initUI(self):
        """
        Initializes the user interface for the application.
        This method sets up the main window, toolbar, and table widget for the application.
        It configures the window title, geometry, and layout. It also creates actions for
        the toolbar and connects them to their respective slots.
        The following actions are added to the toolbar:
        - Get From Text Table: Retrieves data from a text table.
        - Set Text Table From Form: Sets data to the text table from the form.
        - Add Column: Adds a new column to the table.
        - Add Row: Adds a new row to the table.
        - Remove Column: Removes a column from the table.
        The table widget is initialized with 4 columns and no rows, with column headers
        labeled 'Column1', 'Column2', 'Column3', and 'Column4'.
        The method also attaches the Qt window to the Tool Setting dialog.
        
        :return: None
        """
        self.setWindowTitle('View Info')
        self.setGeometry(100, 200, 1200, 900)

        # Create a central widget
        central_widget = QWidget(self)
        self.setCentralWidget(central_widget)

        # Create a vertical layout
        layout = QVBoxLayout(central_widget)

        self.toolbar = QToolBar()
        self.addToolBar(self.toolbar)

        self.TlbGetFrom = QAction('Get From Text Table', self)
        self.TlbGetFrom.triggered.connect(self.TlbGetFrom_Click)
        self.toolbar.addAction(self.TlbGetFrom)

        self.TlbSet = QAction('Set Text Table From Form', self)
        self.TlbSet.triggered.connect(self.TlbSet_Click)
        self.toolbar.addAction(self.TlbSet)

        self.toolbar.addSeparator()

        self.TlbAddColumn = QAction('Add Column', self)
        self.TlbAddColumn.triggered.connect(self.TlbAddColumn_Click)
        self.toolbar.addAction(self.TlbAddColumn)
        
        self.TlbAddRow = QAction('Add Row', self)
        self.TlbAddRow.triggered.connect(self.TlbAddRow_Click)
        self.toolbar.addAction(self.TlbAddRow)

        self.TlbRemoveColumn = QAction('Remove Column', self)
        self.TlbRemoveColumn.triggered.connect(self.TlbRemoveColumn_Click)
        self.toolbar.addAction(self.TlbRemoveColumn)

        self.dgData = QTableWidget()
        self.dgData.setColumnCount(4)
        self.dgData.setHorizontalHeaderLabels(['Column1', 'Column2', 'Column3', 'Column4'])
        self.dgData.setRowCount(0)

        # layout = QVBoxLayout()
        layout.addWidget(self.toolbar)
        layout.addWidget(self.dgData)

        self.setGeometry(300, 300, 766, 542)
        self.setWindowTitle('Text Table Element Example')

        # Add Qt window to Tool Setting dialog
        self.storedWinId = self.winId()
        self.loop = QtCore.QEventLoop()
        PyCadInputQueue.AttachQtToolSetting(int(self.storedWinId))

    def UpdateDataGridViewRowsAndColumns(self, tTable):
        """
        Updates the rows and columns of the DataGridView to match the given table.
        This method adjusts the number of rows and columns in the DataGridView (`dgData`) to match the row and column count
        of the provided table (`tTable`). If the DataGridView has more rows or columns than the table, the excess rows or 
        columns are removed. If the DataGridView has fewer rows or columns than the table, additional rows or columns are 
        added.
        
        :param tTable: The table whose row and column count will be used to update the DataGridView.
        :type tTable: TableType
        """
        rowDiff = self.dgData.rowCount() - tTable.RowCount
        if rowDiff > 0:
            for i in range(rowDiff):
                self.dgData.removeRow(self.dgData.rowCount() - 1)
        elif rowDiff < 0:
            for i in range(abs(rowDiff)):
                self.dgData.insertRow(self.dgData.rowCount())

        columnDiff = self.dgData.columnCount() - tTable.ColumnCount
        if columnDiff > 0:
            for i in range(columnDiff):
                self.dgData.removeColumn(self.dgData.columnCount() - 1)
        elif columnDiff < 0:
            for i in range(abs(columnDiff)):
                columnName = "Column" + str(self.dgData.columnCount() + 1)
                self.dgData.insertColumn(self.dgData.columnCount())
                self.dgData.setHorizontalHeaderItem(self.dgData.columnCount() - 1, QTableWidgetItem(columnName))

    def TlbGetFrom_Click(self):
        """
        Handles the click event for retrieving and displaying a text table.

        This method finds an element by its ID in the DGN model, extracts the text table from it,
        and updates the data grid view with the rows and columns of the text table. If the element
        is not found, it shows an error message and attempts to create the text table element again.

        :raises: Shows an error message if the table element is not found.
        """
        elem = self.dgnModel.FindElementByID(self.m_tableElementId)
        if elem:
            element = EditElementHandle(elem)
            tTable = TextTableHandler.GetInstance().ExtractTextTable(element)
            self.UpdateDataGridViewRowsAndColumns(tTable)
            for row in range(tTable.RowCount):
                for column in range(tTable.ColumnCount):
                    index = TableCellIndex(row, column)
                    cell = tTable.GetCell(index)
                    tb = cell.TextBlock
                    self.dgData.setItem(row, column, QTableWidgetItem("" if tb is None else str(tb.ToString())))
        else:
            MessageCenter.ShowErrorMessage("Looks like the table has been deleted. Generating it again", "", False)
            CreateTextTableElement()

    def TlbSet_Click(self):
        """
        Handles the click event for the toolbar set button.

        This method iterates through the rows and columns of the `dgData` table,
        extracts the text from each cell, and populates a list with the extracted
        data. The list is then used to populate a text table.

        :return: None
        """
        list = []
        for row in range(self.dgData.rowCount()):
            rowData = []
            for column in range(self.dgData.columnCount()):
                item = self.dgData.item(row, column)
                rowData.append("" if item is None else "" if item.text() == "" else item.text())
            list.append(rowData)
        self.PopulateTextTable(list)

    def PopulateTextTable(self, list):
        """
        Populates a text table with data from the provided list.

        :param list: A list of lists containing the data to populate the table. 
                     Each inner list represents a row of data.
        :type list: list

        :raises ValueError: If the table element is not found in the model.
        """
        table = TextTable.Create(self.dgData.rowCount(), self.dgData.columnCount(), self.m_textStyleId, self.m_textStyleHeight, self.dgnModel)
        for i in range(self.dgData.rowCount()):
            tData = list[i]
            for j in range(self.dgData.columnCount()):
                self.PopulateCell(table, i, j, tData[j])
        newTableElem = EditElementHandle()
        TextTableHandler.CreateTextTableElement(newTableElem, table, self.dgnModel)
        elem = self.dgnModel.FindElementByID(self.m_tableElementId)
        if elem:
            oldTableElem = elem
            newTableElem.ReplaceInModel(oldTableElem)
        else:
            MessageCenter.ShowErrorMessage("Looks like the table is removed. Generating it again.", "", False)
            newTableElem.AddToModel()
            self.m_tableElementId = newTableElem.ElementId

    def PopulateCell(self, table, row, column, value):
        """
        Populate a specific cell in the table with the given value.

        :param table: The table object where the cell is located.
        :type table: Table
        :param row: The row index of the cell.
        :type row: int
        :param column: The column index of the cell.
        :type column: int
        :param value: The text value to be inserted into the cell.
        :type value: str
        """
        index = TableCellIndex(row, column)
        cell = table.GetCell(index)
        self.m_testTextStyle.SetDoubleProperty(eTextStyle_Height, 10000.0)
        tb = TextBlock(self.m_testTextStyle, self.dgnModel)
        tb.AppendText(value)
        cell.SetTextBlock(tb)

    def TlbAddColumn_Click(self):
        """
        Handles the click event for adding a new column to the data grid.

        This method generates a new column name based on the current number of columns,
        inserts a new column into the data grid, and sets the header item for the new column.

        :return: None
        """
        columnName = "Column" + str(self.dgData.columnCount() + 1)
        self.dgData.insertColumn(self.dgData.columnCount())
        self.dgData.setHorizontalHeaderItem(self.dgData.columnCount() - 1, QTableWidgetItem(columnName))
    
    def TlbAddRow_Click(self):
        """
        Handles the click event for adding a new row to the data grid.

        This method increments the row count of the data grid (`dgData`), inserts a new row at the end,
        and sets the vertical header item for the new row with its corresponding row number.

        :return: None
        """
        rowName = str(self.dgData.rowCount() + 1)
        self.dgData.insertRow(self.dgData.rowCount())
        self.dgData.setVerticalHeaderItem(self.dgData.rowCount() - 1, QTableWidgetItem(rowName))

    def TlbRemoveColumn_Click(self):
        """
        Handles the click event for removing the current column from the data grid.

        This method attempts to remove the currently selected column from the data grid (`dgData`).
        If an error occurs during the removal process, an error message is displayed using the `MessageCenter`.

        :raises Exception: If an error occurs while removing the column, the exception is caught and an error message is shown.
        """
        try:
            self.dgData.removeColumn(self.dgData.currentColumn())
        except Exception as ex:
            MessageCenter.ShowErrorMessage("Error removing column: {}".format(ex), "", False)
    
    def ms_mainLoop(self):
        """
        Main loop that processes events and handles Python input queue.

        This method continuously checks if a specific window is still open
        and processes events in a loop until the window is closed. It also
        calls the Python main loop for handling input and sleeps for a short
        duration to prevent high CPU usage.

        :return: None
        """
        while win32gui.IsWindow(self.storedWinId):
            self.loop.processEvents()
            PyCadInputQueue.PythonMainLoop()
            time.sleep(0.001)

def GetOrCreateTextStyle(textTableForm):
    """
    Retrieves or creates a text style named "TextTable Style" in the active DGN file.

    If the text style does not exist, it creates a new one with specified width and height properties,
    and adds it to the active DGN file.

    :param textTableForm: The main form object containing the DGN file and text style attributes.
    :type textTableForm: object
    
    :return: None
    """
    activeDgnFile = textTableForm.dgnFile
    textTableForm.m_testTextStyle = DgnTextStyle.GetByName("TextTable Style", activeDgnFile)
    if textTableForm.m_testTextStyle is None:
        textTableForm.m_testTextStyle = DgnTextStyle("TextTable Style", activeDgnFile)
        textTableForm.m_testTextStyle.SetInt32Property(TextStyleProperty.eTextStyle_Width, 1000)
        textTableForm.m_testTextStyle.SetInt32Property(TextStyleProperty.eTextStyle_Height, 1000)
        textTableForm.m_testTextStyle.Add(activeDgnFile)
    textTableForm.m_textStyleId = textTableForm.m_testTextStyle.ID
    textTableForm.m_textStyleHeight = textTableForm.m_testTextStyle.GetDoubleProperty(TextStyleProperty.eTextStyle_Height)[1]

def CreateTextTableElement(textTableForm):
    """
    Creates a text table element and adds it to the model.

    :param textTableForm: The main form containing necessary attributes for creating the text table.
    :type textTableForm: TextTableForm
    
    :return: None
    :rtype: None

    The function performs the following steps:
    1. Creates a text table with 1 row and 4 columns using the provided text style ID, text style height, and DGN model from the main form.
    2. Sets the table name to "SomeTable" and the table description to "SomeDescription".
    3. Creates an EditElementHandle to handle the text table element.
    4. Attempts to create the text table element and add it to the model.
    5. If successful, adds the text table element to the model, updates the main form with the table element ID, and shows an info message.
    6. If unsuccessful, shows an error message.
    """
    someTable = TextTable.Create(1, 4, textTableForm.m_textStyleId, textTableForm.m_textStyleHeight, textTableForm.dgnModel)
    someTable.SetTableName(WString("SomeTable"))
    someTable.TableDescription = WString("SomeDescription")
    textTableEditElementHandle = EditElementHandle()
    status = TextTableHandler.CreateTextTableElement(textTableEditElementHandle, someTable, textTableForm.dgnModel)
    if status == BentleyStatus.eSUCCESS:
        textTableEditElementHandle.AddToModel()
        textTableForm.m_tableElementId = textTableEditElementHandle.ElementId
        MessageCenter.ShowInfoMessage("Text table added successfully.", "", False)
    else:
        MessageCenter.ShowErrorMessage("Text table not added.", "", False)
    return

def Run():
    """
    Run the main application.

    This function initializes the QApplication, creates the main form,
    sets up the text style, creates the text table element, and starts
    the main event loop of the application.
    """
    app = QApplication([])
    textTableForm = TextTableForm()
    GetOrCreateTextStyle(textTableForm)
    CreateTextTableElement(textTableForm)
    textTableForm.show()
    textTableForm.ms_mainLoop()

if __name__ == "__main__":
    Run()