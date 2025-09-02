# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''
import sys
import time
import random
import win32gui
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtCore import Qt
from PyQt5.QtCore import pyqtSignal as Signal
from PyQt5.QtWidgets import QMainWindow, QPushButton, QListWidget, QVBoxLayout, QHBoxLayout, QWidget
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

'''
This example provides the following operations for view groups.

Add view group
Delete view group
Rename view group(Edit name in list)
Apply view group(Double click).
'''

def GetViewGroupCollection():
    """
    Retrieves the collection of view groups from the active DGN model reference.
    Returns:
        An object of type ViewGroupCollection if the active DGN model reference and 
        its associated DGN file are valid, otherwise None.
    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    if ACTIVEMODEL is None:
        return None
    
    loadDgnFile  = ACTIVEMODEL.GetDgnFile()
    if loadDgnFile is None or loadDgnFile.IsReadOnly():
        print("Error: File is readonly!")
        return None
    
    return loadDgnFile.GetViewGroups()
    
class Window(QtWidgets.QMainWindow):
    """
    A class to represent the main window of the application.
    Methods
    -------
    __init__():
        Initializes the main window.
    initUI():
        Sets up the user interface of the main window.
    on_button_add():
        Handles the 'Add' button click event to add a new view group.
    on_button_del():
        Handles the 'Delete' button click event to delete the selected view group.
    on_button_apply():
        Handles the 'Apply' button click event to apply the selected view group.
    ms_mainLoop():
        Main loop to process events and handle the tool setting dialog.
    """

    def __init__(self):
        """
        Initialize the ViewGroupExample class.

        This constructor initializes the parent class and sets up the user interface
        by calling the initUI method. It also initializes the list_box attribute to None.
        """
        super().__init__()
        self.list_box = None
        self.initUI()

    def initUI(self):
        """
        Initializes the user interface for the View Group window.
        This method sets up the main window, including the central widget, 
        main layout, list box, and buttons. It also connects the buttons 
        to their respective event handlers.
        Steps:
        1. Create a central widget and set it as the central widget of the main window.
        2. Create a main horizontal layout and set it to the central widget.
        3. Create a list box and populate it with items from the view group collection.
        4. Create a vertical layout for the buttons.
        5. Create and add three buttons (Add, Delete, Apply) to the vertical layout.
        6. Add the button layout to the main layout.
        7. Attach the Qt window to the Tool Setting dialog.
        Connects:
        - `self.list_box.doubleClicked` to `self.on_button_apply`
        - `AddBtn.clicked` to `self.on_button_add`
        - `DelBtn.clicked` to `self.on_button_del`
        - `ApplyBtn.clicked` to `self.on_button_apply`
        """
        self.setWindowTitle('View Group')
        self.setGeometry(100, 200, 1000, 300)

        # 1) Create a central widget
        central_widget = QWidget(self)
        self.setCentralWidget(central_widget)

        # 2) Create a main horizontal layout
        main_layout = QHBoxLayout(central_widget)

        # 3) Create a list box
        self.list_box = QListWidget(self)
        viewGroups=GetViewGroupCollection()
        for viewGroup in viewGroups:
            self.list_box.addItem(str(viewGroup.GetName()))

        main_layout.addWidget(self.list_box)
        self.list_box.doubleClicked.connect(self.on_button_apply)

        # 4) Create a vertical layout for the buttons
        button_layout = QVBoxLayout()

        # 5) Create 3 buttons
        AddBtn = QPushButton('Add', self)
        DelBtn = QPushButton('Delete', self)
        ApplyBtn = QPushButton('Apply', self)
        button_layout.addWidget(AddBtn)
        button_layout.addWidget(DelBtn)
        button_layout.addWidget(ApplyBtn)
        button_layout.addStretch()  # Add stretch to push buttons to the top

        AddBtn.clicked.connect(self.on_button_add)
        DelBtn.clicked.connect(self.on_button_del)
        ApplyBtn.clicked.connect(self.on_button_apply)
  
        # 6)Add the button layout to the main layout
        main_layout.addLayout(button_layout)

        # 7)Add Qt window to Tool Setting dialog
        self.storedWinId = self.winId()
        self.loop = QtCore.QEventLoop()
        PyCadInputQueue.AttachQtToolSetting(int(self.storedWinId))

    def on_button_add(self):
        """
        Handles the event when the "Add" button is pressed.
        This function performs the following steps:
        1. Retrieves the active DGN model reference.
        2. Checks if the model reference is in the master file.
        3. Retrieves the collection of view groups.
        4. Gets the active view group.
        5. Generates a unique name for the new view group.
        6. Sets up options for copying the view group.
        7. Copies the active view group with the specified options.
        8. Makes the new view group active.
        9. Adds the new view group's name to the list box.
        
        :return: None
        """
        ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
        dgnModel = ACTIVEMODEL.GetDgnModel()
        if not ModelRef.InMasterFile(dgnModel):
            return

        viewGroups=GetViewGroupCollection()
        if viewGroups is None:
            return

        activeViewGroup = viewGroups.GetActive()
        name = WString()
        viewGroups.GetUniqueNameFromBase (name, None, dgnModel, False)
        if not viewGroups.NameUnused (str(name)):
           return
        
        vgCopyOptions = ViewGroupCopyOptions()
        vgCopyOptions.SetCopyType (ViewGroupCopyTypeOption.eMakePermanent)
        vgCopyOptions.SetNewName (str(name))
        vgCopyOptions.SetNewDescription (None)
        vgCopyOptions.SetCopyViewLevels()
        vgCopyOptions.SetCopyViewACS()
        vgCopyOptions.SetCopyViewClip()

        retTuple = ViewGroup.Copy(dgnModel, activeViewGroup, vgCopyOptions)
        if ViewGroupStatus.eVG_Success != retTuple[0] or retTuple[1] is None:
            return

        viewGroups.MakeActive (retTuple[1], False)
        self.list_box.addItem(str(name))

    def on_button_del(self):
        """
        Deletes the selected item from the list box and the corresponding view group.
        This method performs the following steps:
        1. Checks if any items are selected in the list box.
        2. Ensures exactly one item is selected.
        3. Retrieves the collection of view groups.
        4. Ensures there is more than one view group.
        5. Finds the view group by the name of the selected item.
        6. Deletes the view group and removes the item from the list box.
        :raises ValueError: If no items or more than one item is selected.
        :raises RuntimeError: If the view group collection is not found or if there is only one view group.
        """
        selected_items = self.list_box.selectedItems()
        if not selected_items:
            return
        
        if len(selected_items) != 1:
            print("Please select exactly one item to delete.")
            return
        
        viewGroups=GetViewGroupCollection()
        if viewGroups is None:
            return

        if viewGroups.Size == 1:
            print("Cannot delete the last view group.")
            return
        
        viewGroup = viewGroups.FindByName (str(selected_items[0].text()))
        if viewGroup:
            viewGroups.Delete(viewGroup)
            self.list_box.takeItem(self.list_box.row(selected_items[0]))

    def on_button_apply(self):
        """
        Handles the apply button click event.
        This method checks if exactly one item is selected in the list box. If not, it prints an error message.
        If one item is selected, it retrieves the view group collection and attempts to find a view group by the selected item's name.
        If the view group is found, it makes the view group active and prints a confirmation message.
        :return: None
        """
        selected_items = self.list_box.selectedItems()
        if len(selected_items) != 1:
            print("Please select exactly one item to apply.")
            return

        viewGroups=GetViewGroupCollection()
        if viewGroups is None:
            return

        viewGroup = viewGroups.FindByName (str(selected_items[0].text()))
        if viewGroup:
            viewGroups.MakeActive (viewGroup, False)
            print(f"Making {selected_items[0].text()} active")
  
    def ms_mainLoop(self):
        """
        Main loop that processes events and handles Python input queue.

        This function runs a loop that continues as long as the stored window ID is valid.
        It processes events, handles the Python input queue, and sleeps for a short duration
        to prevent high CPU usage.

        :return: None
        """
        while win32gui.IsWindow(self.storedWinId):
            self.loop.processEvents()
            PyCadInputQueue.PythonMainLoop()
            time.sleep(0.001)

def Run():
    """
    Initializes the Qt application, creates a Window instance, displays it,
    and starts the main event loop.

    This function performs the following steps:
    1. Creates a QApplication instance.
    2. Instantiates the Window class.
    3. Displays the window.
    4. Starts the main event loop of the application.

    Note: Ensure that the QtWidgets module and the Window class are properly
    imported before calling this function.
    """
    app = QtWidgets.QApplication([])
    w = Window()
    w.show()
    w.ms_mainLoop()
    
if __name__ == '__main__':
   Run()
