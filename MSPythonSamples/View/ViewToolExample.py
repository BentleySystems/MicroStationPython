# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2025 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''
import sys
import time
import random
import win32gui
import os
import json
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtCore import Qt
from PyQt5.QtGui import QIntValidator, QDoubleValidator, QPixmap
from PyQt5.QtWidgets import QSizePolicy, QMainWindow, QLineEdit, QTextEdit, QComboBox, QLabel, QListWidget, QCheckBox, QPushButton, QVBoxLayout, QHBoxLayout, QWidget, QFrame

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

'''
This sample allows for exact sizing of MicroStation's standard views.  View size can be
specified with an absolute pixel size (widthxheight) or by a ratio.  What
this enables you to create a view's raster images of an exact size (640x480, 1024x768, etc.).
Normally when doing a File->Save As you can only specify the width or the height of the
output image...the other value is computed by taking the value you entered
and multiplying it by the current view ratio.  Now you can set what the
current views ratio is so images will be the size you want without having
to muck about trying to stretch views to get the right size.

This sample also shows a way to localize the UI strings using a json file.
'''

def get_loc_string(key):
    """
    Retrieves the localized string for a given key from a JSON file.
    Args:
        key (str): The key for which to retrieve the localized string.
    Returns:
        str: The localized string if the key is found in the JSON file, otherwise the key itself.
    Notes:
        - The JSON file is expected to be named 'transkit.json' and located in the same directory as this script.
        - If the JSON file does not exist, the function will return the key itself.
    """
    transkitFile = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'transkit.json')
    if not os.path.exists(transkitFile):
        return key
    
    data = read_json_file(transkitFile)
    if key in data:
        return data[key]
    return key

def read_json_file(file_path):
    """
    Reads a JSON file and returns its contents as a dictionary.

    Args:
        file_path (str): The path to the JSON file.

    Returns:
        dict: The contents of the JSON file.
    """
    with open(file_path, 'r', encoding='utf-8') as file:
        data = json.load(file)
    return data

def OnPostUpdate(isPreUpdate, eraseMode, modelList, regions, context, numCovers, displayDescr):
    """
    Handles the post-update event for the view update.

    Returns:
        int: Always returns 0.
    """
    if w and w.isVisible() and w.combo_box:
        selected_index = w.combo_box.currentIndex()
        w.combo_box.blockSignals(True)
        w.combo_box.setCurrentIndex(-1)
        w.combo_box.blockSignals(False)
        w.combo_box.setCurrentIndex(selected_index)
        
    return 0

def GetViewInfo(viewNo):
    """
    Retrieves information about a specified view in the active DGN model.
    Args:
        viewNo (int): The number of the view to retrieve information for. If set to -1, the function will find the first open view.
    Returns:
        ViewInfo: An object containing information about the specified view, or None if the view or active model is not found.
    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    if ACTIVEMODEL is None:
        return None
    
    loadDgnFile  = ACTIVEMODEL.GetDgnFile()
    vgc = loadDgnFile.GetViewGroups()
    activeViewGroup = vgc.GetActive()
    if activeViewGroup is None:
        return None
    
    if viewNo == -1:
        retTuple = activeViewGroup.FindFirstOpenView()
        viewNo = retTuple[1]
        if retTuple[0] != ViewGroupStatus.eVG_Success:
             MstnView.turnOn (viewNo)
    
    actViewInfo = activeViewGroup.GetViewInfo (viewNo)
    return actViewInfo

def SaveViewScreenshotToPNG(viewIndex):
    """
    Saves a screenshot of the specified view to a PNG file.
    Args:
        viewIndex (int): The index of the view to capture. Must be between 0 and 7 inclusive.
    Returns:
        str: The file path of the saved PNG image if successful, None otherwise.
    Raises:
        ValueError: If the viewIndex is not between 0 and 7 inclusive.
    Notes:
        - If the specified view is not visible, it will be turned on.
        - The screenshot is saved to a temporary directory.
    """
    if viewIndex < 0 or viewIndex > 7:
        print ("Invalid view number!")
        return
    
    if MstnView.isVisible(viewIndex) == False:
        MstnView.turnOn (viewIndex)

    viewportInfo = ViewPortInfo()        # Create an instance of ViewPortInfo 
    MstnViewPortInfo.From(viewportInfo, viewIndex) # Initialize the ViewPortInfo instance with the contents of the numbered view

    origin = viewportInfo.GetPixelOrigin () # Get the viewport origin in pixels
    corner = viewportInfo.GetPixelCorner () # Get the viewport corner in pixels

    imagesize = Point2d()
    imagesize.x = corner.x - origin.x # Get viewport width in pixels
    imagesize.y = corner.y - origin.y # Get viewport height in pixels

    actViewInfo = GetViewInfo(viewIndex) # Get viewinfo
    if actViewInfo is None:
        return
    
    #Save view screenshot to RGB buffer
    retVal, imageMap = MstnImage.saveViewToRGB(imagesize, actViewInfo.ViewFlags.renderMode, False, False, viewIndex)

    if BentleyStatus.eSUCCESS != retVal:
        print("Failed to save view screenshot as an image")
        return

    # Create the png save path.
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")
    tempFileName = os.path.splitext(os.path.basename(os.path.abspath(__file__)))[0] + ".png"
    pngFilePath = str (emptyDir) + str (tempFileName)
    BeFileName.BeDeleteFile (pngFilePath)

    #Save RGBA buffer as a png Image
    retVal = MstnImage.extCreateFileFromRGB(pngFilePath, ImageFileFormat.eIMAGEFILE_PNG, ImageColorMode.eRGB, imagesize, 
                                            imageMap, CompressionType.eCOMPRESSTYPE_DEFAULT, 
                                            CompressionRatio.eCOMPRESSIONRATIO_DEFAULT, None)
    
    if BentleyStatus.eSUCCESS == retVal:
         return pngFilePath

    return None

class Window(QtWidgets.QMainWindow):
    def __init__(self):
        """
        Initializes the ViewToolExample class.

        Calls the initializer of the superclass and sets up the user interface.
        """
        super().__init__()
        self.initUI()

    def closeEvent(self, event):
        """
        Handles the window close event.
        Call event.accept() to allow closing, or event.ignore() to prevent it.
        """

        ViewCallback.SetUpdatePostFunction(None,os.path.abspath(__file__) + ".OnPostUpdate")

        print("Window is closing.")      

        event.accept()

    def initUI(self):
        """
        Initializes the user interface for the main window.
        This method sets up the main window's title, central widget, and layouts.
        It creates and configures various UI elements including labels, combo boxes,
        checkboxes, line edits, and buttons. It also sets up event connections for
        these elements and adjusts the window size and position.
        UI Elements:
        - Central widget
        - Horizontal layout for the main window
        - Vertical layout for the left side
        - Horizontal layout for the label and combo box
        - Horizontal layouts for checkboxes and line edits
        - Button for resetting values
        - Image control for displaying a PNG image
        Event Connections:
        - Combo box selection change
        - Checkbox clicks
        - Button click
        Additional Setup:
        - Adjusts the width of the combo box to fit its contents
        - Makes line edits read-only and sets validators for numeric input
        - Adjusts the size of the main window to fit its contents
        - Moves the main window to a specified location
        - Initializes dialog item values with view info
        - Attaches Qt window to Tool Setting dialog
        - Sets a callback function for view updates
        """
        self.setWindowTitle(get_loc_string('View Tool'))

        # Create a central widget
        central_widget = QWidget(self)
        self.setCentralWidget(central_widget)
        
        # Create a horizontal layout for the main window
        main_layout = QHBoxLayout(central_widget)

        # Create a vertical layout for the left side
        left_layout = QVBoxLayout()
   
        # Create a horizontal layout for the label and combo box
        combo_layout = QHBoxLayout()
        combo_layout.setSpacing(20)  # Set space between widgets
        combo_layout.setContentsMargins(0, 0, 0, 0)  # Remove margins
        self.combo_label = QLabel(get_loc_string('View:'))
        self.combo_label.setFixedSize(self.combo_label.sizeHint())
        self.combo_box = QComboBox()
        self.combo_box.addItems(['1', '2', '3', '4', '5', '6', '7', '8'])
        self.combo_box.setCurrentIndex(-1)
        self.combo_box.currentIndexChanged.connect(self.on_combo_box_select)  # Connect combo_box event
        combo_layout.addWidget(self.combo_label)
        combo_layout.addWidget(self.combo_box)
        combo_layout.setAlignment(Qt.AlignRight)  # Set alignment to right
        left_layout.addLayout(combo_layout)

        # Adjust the width of the combo box to fit its contents
        self.combo_box.setFixedWidth(self.combo_box.view().sizeHintForColumn(0) + 100)

        # Create a horizontal layout for checkbox1 and edit_box1
        checkbox1_layout = QHBoxLayout()
        self.checkbox1 = QCheckBox(get_loc_string('Width:'))
        self.edit_box1 = QLineEdit()
        self.edit_box1.setReadOnly(True)  # Make edit_box1 read-only
        self.edit_box1.setValidator(QIntValidator())  # Only allow numbers
        self.checkbox1.clicked.connect(self.on_checkbox1_clicked)  # Connect checkbox1 clicked event
        checkbox1_layout.addWidget(self.checkbox1)
        checkbox1_layout.addWidget(self.edit_box1)
        left_layout.addLayout(checkbox1_layout)

        # Create a horizontal layout for checkbox2 and edit_box2
        checkbox2_layout = QHBoxLayout()
        self.checkbox2 = QCheckBox(get_loc_string('Height:'))
        self.edit_box2 = QLineEdit()
        self.edit_box2.setReadOnly(True)  # Make edit_box2 read-only
        self.edit_box2.setValidator(QIntValidator())  # Only allow numbers
        self.checkbox2.clicked.connect(self.on_checkbox2_clicked)  # Connect checkbox2 clicked event
        checkbox2_layout.addWidget(self.checkbox2)
        checkbox2_layout.addWidget(self.edit_box2)
        left_layout.addLayout(checkbox2_layout)

        # Create a horizontal layout for checkbox3 and edit_box3
        checkbox3_layout = QHBoxLayout()
        self.checkbox3 = QCheckBox(get_loc_string('Ratio:'))
        self.edit_box3 = QLineEdit()
        self.edit_box3.setReadOnly(True)  # Make edit_box3 read-only
        self.edit_box3.setValidator(QDoubleValidator())  # Only allow numbers
        self.checkbox3.clicked.connect(self.on_checkbox3_clicked)  # Connect checkbox3 clicked event
        checkbox3_layout.addWidget(self.checkbox3)
        checkbox3_layout.addWidget(self.edit_box3)
        left_layout.addLayout(checkbox3_layout)

        # Create and add a button to the left layout
        self.button = QPushButton(get_loc_string('Reset'))
        self.button.clicked.connect(self.on_button_click)  # Connect button click event
        left_layout.addWidget(self.button)

        # Create an image control to display a PNG image on the right side
        self.image_label = QLabel()
        self.image_label.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
        self.image_label.setAlignment(Qt.AlignCenter)

        # Add the left layout and right panel to the main layout
        main_layout.addLayout(left_layout)
        main_layout.addWidget(self.image_label)

        # Adjust the size of the main window to fit its contents
        self.adjustSize()
        # Move the main window to the specified location
        self.move(100, 200)

        # Initialize the Window dialog Item values with the view info
        self.InitDlgItemValue(-1)

        # Add Qt window to Tool Setting dialog
        self.storedWinId = self.winId()
        self.loop = QtCore.QEventLoop()
        PyCadInputQueue.AttachQtToolSetting(int(self.storedWinId))

        # Callback that is called after a view updates
        ViewCallback.SetUpdatePostFunction(OnPostUpdate, os.path.abspath(__file__) + ".OnPostUpdate")

    def SetCheckboxValues(self, viewNo):
        viewWnd = MSWindow.viewWindowGet(viewNo)
        if viewWnd is None:
            return
        
        clipRect = BSIRect()
        status = MSWindow.contentRectGetLocal (clipRect, viewWnd)
        if status != BentleyStatus.eSUCCESS:
            return

        self.edit_box1.setText(str(clipRect.Width()))
        self.edit_box2.setText(str(clipRect.Height()))
        self.edit_box3.setText(str(round(clipRect.Width() / clipRect.Height(), 4)))

    def InitDlgItemValue (self, viewNo):
        actViewInfo = GetViewInfo (viewNo)
        if actViewInfo is None:
            return None
        
        index = actViewInfo.GetViewNumber()
        self.combo_box.setCurrentIndex(index)

    def on_checkbox1_clicked(self):
        if self.checkbox1.checkState() == Qt.Checked:
            if self.checkbox2.isChecked() and self.checkbox3.isChecked():
                self.checkbox1.setChecked(False)
                self.edit_box1.setReadOnly(True)
            else:
                self.edit_box1.setReadOnly(False)
        else:
            self.edit_box1.setReadOnly(True)

    def on_checkbox2_clicked(self):
        if self.checkbox2.checkState() == Qt.Checked:
            if self.checkbox1.isChecked() and self.checkbox3.isChecked():
                self.checkbox2.setChecked(False)
                self.edit_box2.setReadOnly(True)
            else:
                self.edit_box2.setReadOnly(False)
        else:
            self.edit_box2.setReadOnly(True)

    def on_checkbox3_clicked(self):
        if self.checkbox3.checkState() == Qt.Checked:
            if self.checkbox1.isChecked() and self.checkbox2.isChecked():
                self.checkbox3.setChecked(False)
                self.edit_box3.setReadOnly(True)
            else:
                self.edit_box3.setReadOnly(False)
        else:
            self.edit_box3.setReadOnly(True)

    def on_combo_box_select(self, index):
        """
        Handles the event when a combo box selection is made.
        Args:
            index (int): The index of the selected item in the combo box.
        This method performs the following actions:
        1. Sets the checkbox values based on the selected index.
        2. Saves a screenshot of the view to a PNG file.
        3. Updates the image label with the new pixmap if the PNG file was saved successfully.
        """
        self.SetCheckboxValues(index)

        pngfilepath = SaveViewScreenshotToPNG(index)
        if pngfilepath is not None:
            new_pixmap = QPixmap(pngfilepath)
            self.image_label.setPixmap(new_pixmap)

    def on_button_click(self):
        """
        Handles the button click event.
        This method performs the following actions:
        1. Checks if exactly two checkboxes are checked. If not, prints a message and returns.
        2. Retrieves the selected index from the combo box and gets the corresponding view window.
        3. Retrieves integer values from three edit boxes (width, height, and ratio).
        4. If any of the retrieved values are zero, returns.
        5. Adjusts the width or height based on the ratio if the third checkbox is checked.
        6. Sets the extent of the view window with the calculated width and height.
        7. Manually emits a signal by blocking and unblocking signals of the combo box.
        """
        checkboxes_checked = [self.checkbox1.isChecked(), self.checkbox2.isChecked(), self.checkbox3.isChecked()]
        if checkboxes_checked.count(True) != 2:
            print('Please ensure exactly two checkboxes are checked.')
            return 

        selected_index = self.combo_box.currentIndex()
        viewWnd = MSWindow.viewWindowGet(selected_index)
        if viewWnd is None:
            return

        # Get the int value in checkbox1, checkbox2, and checkbox3
        width = int(self.edit_box1.text()) if self.edit_box1.text() else 0
        height = int(self.edit_box2.text()) if self.edit_box2.text() else 0
        ratio = float(self.edit_box3.text()) if self.edit_box3.text() else 0.0

        if width == 0 or height == 0 or ratio == 0.0:
            return
        
        if self.checkbox3.isChecked():
            if self.checkbox1.isChecked():
                height = int(width / ratio)
            elif self.checkbox2.isChecked():
                width = int(height * ratio)
        
        MSWindow.extentSet(viewWnd, width, height)
        
        # Manually emit signal
        self.combo_box.blockSignals(True)
        self.combo_box.setCurrentIndex(-1)
        self.combo_box.blockSignals(False)
        self.combo_box.setCurrentIndex(selected_index)

    def ms_mainLoop(self):
        """
        Main loop that processes events and handles Python main loop.

        This method continuously checks if a stored window ID is valid and processes
        events in a loop. It also calls the Python main loop function from the 
        PyCadInputQueue module and sleeps for a short duration to prevent high CPU usage.

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
    global w

    app = QtWidgets.QApplication([])
    w = Window()
    w.show()
    w.ms_mainLoop()
    
if __name__ == '__main__':
    Run()
