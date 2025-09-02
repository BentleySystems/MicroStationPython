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
from PyQt5.QtWidgets import QMainWindow, QTextEdit, QComboBox, QLabel, QListWidget, QPushButton, QVBoxLayout, QHBoxLayout, QWidget, QFrame
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

'''
ViewInfoExample demonstrates use of ViewInfo related APIs.

Load this sample, View info dialog will be opened automatically.

This example provides the following operations for view groups.

Display detailed view info.
Reset view info.
'''

def viewInfo_Reset(viewNo):
    """
    Resets the view information for a given view number.
    This function performs the following steps:
    1. Retrieves the active DGN model reference.
    2. Loads the DGN file associated with the active model.
    3. Retrieves the active view group from the DGN file.
    4. Ensures a specific level ("Test Level 1") exists in the level cache.
    5. Initializes a window rectangle and a 3D range for the view.
    6. Creates a new ViewInfo object with specified parameters.
    7. Sets the geometry of the view using origin, delta, and rotation matrix.
    8. Creates and sets an auxiliary coordinate system (ACS) for the view.
    9. Toggles the display of the specified level in the view.
    10. Sets the level display mask for the view.
    11. Sets the background color of the view.
    12. Updates the view information in the active view group.
    13. Synchronizes the view display.
    14. Performs a full update of the view display.
    Args:
        viewNo (int): The view number to reset.
    Returns:
        None
    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    if ACTIVEMODEL is None:
        return None
    
    loadDgnFile  = ACTIVEMODEL.GetDgnFile()
    if loadDgnFile is None:
        return None
    
    vgc = loadDgnFile.GetViewGroups()
    activeViewGroup = vgc.GetActive()
    if activeViewGroup is None:
        return None

    levelCache = loadDgnFile.GetLevelCache()
    level = levelCache.GetLevelByName(str("Test Level 1"))
    if level.IsValid() == False:
        level = levelCache.CreateLevel(str("Test Level 1"), LEVEL_NULL_CODE, LEVEL_NULL_ID)

    windowRect = BSIRect()
    windowRect.Init(20, 20, 320, 320)
    range = DRange3d(30, 30, 30, 300, 300, 300)
  
    vInfo = ViewInfo.Create (False, ACTIVEMODEL.GetDgnModel(), viewNo, range, windowRect, StandardView.eTop, True) # Create a new view info object.
    
    origin = DPoint3d.From (100, 100,0)
    delta = DPoint3d.From (100000, 100000,0)

    rot = RotMatrix()
    standardView = StandardView.eBottom
    ViewInfo.GetStandardViewByName (rot, standardView, str("Top"))

    vInfo.SetGeometry (origin, delta, rot) # Set the geometry of the view.

    viewACS = IACSManager.GetManager().CreateACS()
    if viewACS is not None:
        viewACS.SetName(str("TestACS"))
        viewACS.SetType(ACSType.eCylindrical)
        vInfo.SetAuxCoordinateSystem(viewACS) # Set the auxiliary coordinate system of the view.

    retVal = vInfo.GetLevelDisplay (ACTIVEMODEL, level.GetLevelId())
    isOn = retVal[1]
    if isOn == True:
        vInfo.SetLevelDisplay (ACTIVEMODEL, level.GetLevelId(), False) # Set the display of the level in the view.

    levelId = loadDgnFile.GetLevelCache().GetLevelByName (str("Default")).GetLevelId()
    mask = BitMask.Create(False)
    mask.SetBit (levelId, True)
    vInfo.SetLevelDisplayMask (ACTIVEMODEL, mask) # Set the display mask of the level in the view.
    
    rgb = RgbColorDef()
    rgb.blue = 255
    rgb.green = 0 
    rgb.red = 0
    vInfo.SetBackgroundColor (rgb) # Set the background color of the view.

    activeViewGroup.SetViewInfo (vInfo, viewNo) # Set the view info object to the view group.
    activeViewGroup.SynchViewDisplay (0, False, False, False)

    vp = IViewManager.GetManager().GetActiveViewSet().GetViewport(viewNo)
    info = IndexedViewSet.FullUpdateInfo()
    info.SetStartEndMsg(True)
    IViewManager.GetActiveViewSet().UpdateView(vp, DgnDrawMode.eDRAW_MODE_Normal, DrawPurpose.eUpdate, info) # Update the display by doing a full update.

def GetViewInfo(viewNo):
    """
    Retrieves the view information for a specified view number from the active DGN model reference.
    Args:
        viewNo (int): The view number for which to retrieve the view information.
    Returns:
        ViewInfo: The view information object for the specified view number, or None if the view information
                  cannot be retrieved due to an inactive model, missing DGN file, or inactive view group.
    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    if ACTIVEMODEL is None:
        return None
    
    loadDgnFile  = ACTIVEMODEL.GetDgnFile()
    if loadDgnFile is None:
        return None
    
    vgc = loadDgnFile.GetViewGroups()
    activeViewGroup = vgc.GetActive()
    if activeViewGroup is None:
        return None
    
    actViewInfo = activeViewGroup.GetViewInfo (viewNo)
    return actViewInfo

def getStandardViewInfo (actViewInfo):
    """
    Retrieves and formats information about the standard view of the given active view information.
    Args:
        actViewInfo: An object representing the active view information. It is expected to have methods
                         GetRotation(), IsStandardViewRotation(), GetStandardViewName(), and GetViewNumber().
    Returns:
        str: A formatted string containing the view number and the standard view name.
    """
    rotation = actViewInfo.GetRotation()
    stdView = actViewInfo.IsStandardViewRotation(rotation, True)

    viewName = WString()
    actViewInfo.GetStandardViewName (viewName, stdView)

    viewNo = actViewInfo.GetViewNumber()
    sInfo = f"View {viewNo + 1} is {str(viewName)} \n"
    return sInfo
    
class Window(QtWidgets.QMainWindow):
    """
    A class to create a main window for displaying view information.
    Attributes
    ----------
    text_view : QTextEdit
        A text view control to display view information.
    combo_box : QComboBox
        A combo box to select different views.
    storedWinId : int
        The window ID of the Qt window.
    loop : QEventLoop
        An event loop for processing events.
    Methods
    -------
    __init__():
        Initializes the main window and its UI components.
    initUI():
        Sets up the user interface of the main window.
    set_text_view():
        Updates the text view with information about the selected view.
    on_combo_box_select(index):
        Handles the event when a new item is selected in the combo box.
    on_reset_view():
        Resets the view information to its default state.
    ms_mainLoop():
        Main loop for processing events and handling input.
    """
    def __init__(self):
        super().__init__()
        self.text_view = None
        self.combo_box = None
        self.initUI()

    def initUI(self):
        """
        Initialize the user interface for the View Info window.
        This method sets up the main window properties, creates and arranges
        various widgets including labels, combo boxes, text views, and buttons,
        and connects signals to their respective slots.
        The layout consists of:
        - A central widget with a vertical layout.
        - A horizontal layout for a label and combo box with a smaller spacing.
        - A horizontal line separator.
        - A label for the view info description.
        - A read-only text view control.
        - A reset button.
        Additionally, this method attaches the Qt window to the Tool Setting dialog.
        :return: None
        """
        self.setWindowTitle('View Info')
        self.setGeometry(100, 200, 1200, 900)

        # Create a central widget
        central_widget = QWidget(self)
        self.setCentralWidget(central_widget)

        # Create a vertical layout
        layout = QVBoxLayout(central_widget)

        # Create a horizontal layout for the label and combo box
        combo_layout = QHBoxLayout()
        combo_layout.setSpacing(1)  # Set the spacing between label and combo box to a smaller value

        # Create a static text (label) for the combo box
        combo_label = QLabel('View:', self)
        combo_label.setFixedSize(combo_label.sizeHint())  # Resize the label to fit the text
        combo_layout.addWidget(combo_label)

        # Create a combo box
        self.combo_box = QComboBox(self)
        self.combo_box.addItems(["1", "2", "3","4", "5", "6", "7", "8"])
        self.combo_box.setFixedWidth(100)  # Set the width of the combo box
        self.combo_box.currentIndexChanged.connect(self.on_combo_box_select)  # Connect the combo box selecting event to a custom method
        combo_layout.addWidget(self.combo_box)

        # Add the horizontal layout to the main vertical layout with left alignment
        layout.addLayout(combo_layout)
        layout.setAlignment(combo_layout, QtCore.Qt.AlignLeft)

        # Create a horizontal line
        line = QFrame(self)
        line.setFrameShape(QFrame.HLine)
        line.setFrameShadow(QFrame.Sunken)
        layout.addWidget(line)

        # Create a static text (label)
        label = QLabel('View info Description:', self)
        layout.addWidget(label)

        # Create a text view control (QTextEdit) below the list box
        self.text_view = QTextEdit(self)
        self.text_view.setReadOnly(True)  # Make the text view read-only
        layout.addWidget(self.text_view)
        self.set_text_view()

        # Create a button
        button = QPushButton('Reset', self)
        button.clicked.connect(self.on_reset_view)   # Connect the button click event to a custom method
        layout.addWidget(button)
        
        # Add Qt window to Tool Setting dialog
        self.storedWinId = self.winId()
        self.loop = QtCore.QEventLoop()
        PyCadInputQueue.AttachQtToolSetting(int(self.storedWinId))

    def set_text_view(self):
        """
        Updates the text view with information about the currently selected view.
        This method clears the current text view and populates it with various details
        about the selected view, including origin, extent, camera settings, view flags,
        model references, background color, and other view properties.
        The information is retrieved from the `viewInfo` object, which is obtained based
        on the current index of the combo box.
        The following details are appended to the text view:
        - Standard view information
        - Origin coordinates
        - Extent dimensions
        - Active Z depth
        - Camera angle, focal length, and position
        - Various view flags (e.g., text, grid, level overrides, line weight, transparency)
        - Root model and target model references
        - Root file name
        - Background color in RGB format
        - Named view status
        - 3D view treatment status
        - Aspect ratio skew
        - Auxiliary coordinate system origin
        - Display style name
        - Element color override status
        - Dynamic view display style index
        Returns:
            None
        """
        self.text_view.clear()
        selected_index = self.combo_box.currentIndex()
        viewInfo = GetViewInfo(selected_index)

        if viewInfo is None:
            return
        
        sInfo = getStandardViewInfo(viewInfo)
        self.text_view.append(sInfo)

        origin = viewInfo.GetOrigin()
        sInfo = f"Origin: ({origin.x}, {origin.y}, {origin.z})\n"
        self.text_view.append(sInfo)
        
        extent = viewInfo.GetDelta()
        sInfo = f"Extend: ({extent.x}, {extent.y}, {extent.z})\n"
        self.text_view.append(sInfo)

        activeZ = viewInfo.GetActiveZ()
        sInfo = f"Depth: {activeZ}\n"
        self.text_view.append(sInfo)

        cInfo = viewInfo.GetCamera()
        sInfo = f"Camera Angle: {cInfo.angle}, Focal Length: {cInfo.focalLength}, Position: ({cInfo.position.x}, {cInfo.position.y}, {cInfo.position.z})\n"
        self.text_view.append(sInfo)

        viewGeomInfo = viewInfo.GetGeomInfo()
        sInfo = f"Text: {'OFF' if viewGeomInfo.viewFlags.fast_text == 1 else 'ON'}\n "
        self.text_view.append(sInfo)

        sInfo = f"Grid: {'ON' if viewGeomInfo.viewFlags.grid == 1 else 'OFF'}\n "
        self.text_view.append(sInfo)

        sInfo = f"level overrides: {'ON' if viewGeomInfo.viewFlags.lev_symb == 1 else 'OFF'}\n "
        self.text_view.append(sInfo)

        sInfo = f"Line weight: {'ON' if viewGeomInfo.viewFlags.line_wghts == 1 else 'OFF'}\n "
        self.text_view.append(sInfo)

        sInfo = f"Transparency: {'ON' if viewGeomInfo.viewFlags.transparency == 1 else 'OFF'}\n "
        self.text_view.append(sInfo)

        sInfo = f"Scene lights: {'OFF' if viewGeomInfo.viewFlags.ignoreSceneLights == 1 else 'ON'}\n "
        self.text_view.append(sInfo)

        sInfo = f"Background: {'ON' if viewGeomInfo.viewFlags.background == 1 else 'OFF'}\n "
        self.text_view.append(sInfo)

        sInfo = f"Patterns: {'ON' if viewGeomInfo.viewFlags.patterns == 1 else 'OFF'}\n "
        self.text_view.append(sInfo)

        sInfo = f"Camera: {'ON' if viewGeomInfo.viewFlags.camera == 1 else 'OFF'}\n "
        self.text_view.append(sInfo)

        sInfo = f"TextNodes: {'ON' if viewGeomInfo.viewFlags.text_nodes == 1 else 'OFF'}\n "
        self.text_view.append(sInfo)

        sInfo = f"Fill: {'ON' if viewGeomInfo.viewFlags.fill == 1 else 'OFF'}\n "
        self.text_view.append(sInfo)

        sInfo = f"RenderDisplayShadows: {'ON' if viewGeomInfo.viewFlags.renderDisplayShadows == 1 else 'OFF'}\n "
        self.text_view.append(sInfo)

        sInfo = f"Dimensions: {'ON' if viewGeomInfo.viewFlags.dimens == 1 else 'OFF'}\n "
        self.text_view.append(sInfo)

        sInfo = f"Constructions: {'ON' if viewGeomInfo.viewFlags.constructs == 1 else 'OFF'}\n "
        self.text_view.append(sInfo)

        sInfo = f"NoClipVolume: {'OFF' if viewGeomInfo.viewFlags.noClipVolume == 1 else 'ON'}\n "
        self.text_view.append(sInfo)

        sInfo = f"inhibitLineStyles: {'OFF' if viewGeomInfo.viewFlags.inhibitLineStyles == 1 else 'ON'}\n "
        self.text_view.append(sInfo)

        sInfo = f"Tag: {'OFF' if viewGeomInfo.viewFlags.tagsOff == 1 else 'ON'} \n"
        self.text_view.append(sInfo)

        rootModel = viewInfo.GetRootModel()
        if rootModel is not None:
            sInfo = f"Root Model: {str(rootModel.GetModelName())}\n"
            self.text_view.append(sInfo)

        targetModelRef = viewInfo.GetTargetModelRef()
        if targetModelRef is not None:
            sInfo = f"Target Model: {str(targetModelRef.GetDgnModel().GetModelName())}\n"
            self.text_view.append(sInfo)

        rootFile = viewInfo.GetRootDgnFile()
        if rootFile is not None:
            sInfo = f"Root File: {str(rootFile.GetFileName())}\n"
            self.text_view.append(sInfo)

        bgColor = viewInfo.GetBackgroundColor()
        sInfo = f"Background color: RGB({bgColor.red}, {bgColor.green}, {bgColor.blue}) \n"
        self.text_view.append(sInfo)

        sInfo = f"Hold by named view: {'Yes' if viewInfo.IsNamed() else 'No'} \n"
        self.text_view.append(sInfo)

        sInfo = f"Treat view as 3d: {'Yes' if viewInfo.TreatViewAs3D() else 'No'} \n"
        self.text_view.append(sInfo)

        sInfo = f"AspectRatioSkew: {viewInfo.GetAspectRatioSkew():.3f} \n"
        self.text_view.append(sInfo)

        acs = viewInfo.GetAuxCoordinateSystem()
        acsOrigin = DPoint3d()
        acs.GetOrigin(acsOrigin)
        sInfo = f"ACS origin: ({acsOrigin.x}, {acsOrigin.y}, {acsOrigin.z}) \n"
        self.text_view.append(sInfo)

        displayStyle = viewInfo.GetDisplayStyle()
        if displayStyle is not None:
            sInfo = f"Display Style: {str(displayStyle.GetName())} \n"
            self.text_view.append(sInfo)

        viewDisplayOverrides = viewInfo.GetDisplayOverrides()
        if viewDisplayOverrides:
            sInfo = f"Element color override: {'Yes' if viewDisplayOverrides.flags.elementColor else 'No'} \n"
            self.text_view.append(sInfo)

        dvSetting = viewInfo.GetDynamicViewSettings()
        sInfo = f"Dynamic view display style index: {dvSetting.GetDisplayStyleIndex()} \n"
        self.text_view.append(sInfo)

    def on_combo_box_select(self, index):
        """
        Handles the event when a selection is made in the combo box.

        :param index: The index of the selected item in the combo box.
        :type index: int
        """
        self.set_text_view()

    def on_reset_view(self):
        """
        Resets the view based on the selected index in the combo box.

        This method retrieves the current index from the combo box, calls the 
        `viewInfo_Reset` function with the selected index to reset the view, 
        and then updates the text view accordingly.

        :return: None
        """
        selected_index = self.combo_box.currentIndex()
        viewInfo_Reset(selected_index)
        self.set_text_view()
     
    def ms_mainLoop(self):
        """
        Main loop that processes events and handles Python input queue.

        This function continuously checks if a stored window ID is valid and 
        processes events in a loop. It also calls the Python main loop for 
        handling input and sleeps for a short duration to prevent high CPU usage.

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
