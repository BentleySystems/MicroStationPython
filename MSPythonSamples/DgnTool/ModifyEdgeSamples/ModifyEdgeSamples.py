# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright:(c) 2025 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''

from MSPyBentley import *
from MSPyDgnView import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyBentleyGeom import *
from MSPyMstnPlatform import *

import time
import win32gui
from PyQt5 import QtCore
from PyQt5.QtWidgets import QApplication, QMainWindow, QVBoxLayout, QWidget, QLineEdit, QCheckBox, QPushButton

"""
This script defines a tool and a GUI application for modifying edges in a DGN model. 
It provides functionality to blend edges with a specified radius and optionally allow tangent edges.
"""

class ModifyEdge(LocateSubEntityTool, DgnElementSetTool):
    def __init__(self, toolId, promptId, radius, allowTangentEdges):
        """
        Initialize the ModifyEdgeSamples tool.

        :param toolId: Identifier for the tool.
        :type toolId: int
        :param promptId: Identifier for the prompt.
        :type promptId: int
        :param radius: Radius for blending edges.
        :type radius: float
        :param allowTangentEdges: Flag to allow tangent edges.
        :type allowTangentEdges: bool
        """
        LocateSubEntityTool.__init__(self)
        DgnElementSetTool.__init__(self, toolId)
        self.m_self = self
        self.toolId = toolId
        self.promptId = promptId
        self.modelRef = ISessionMgr.ActiveDgnModelRef.GetDgnModel()
        self.activeDgnFile = ISessionMgr.GetActiveDgnFile()
        if self.modelRef != None:
            MessageCenter.ShowInfoMessage("DGN Model selected successfully.", "", False)
        else:
            MessageCenter.ShowErrorMessage("No DGN Model selected.", "", False)
        self.m_blendEdgeRadius = radius
        self.m_blendEdgeAllowTangentEdges = allowTangentEdges

    def _OnRestartTool(self):
        """
        Restart the tool by installing a new instance of ModifyEdge with the current ToolId.

        :return: None
        """
        ModifyEdge.InstallNewInstance(self.ToolId)
    
    def CollectCurves(self):
        """
        Collect curves from the current context.

        :return: Always returns False.
        :rtype: bool
        """
        return False
    
    def CollectSurfaces(self):
        """
        Collects surfaces for modification.

        :return: Always returns False.
        :rtype: bool
        """
        return False
    
    def OnProcessSolidPrimitive(self, geomPtr, path):
        """
        Processes a solid primitive geometry.

        :param geomPtr: A pointer to the geometry object to be processed.
        :type geomPtr: object
        :param path: The path associated with the geometry object.
        :type path: object
        
        :return: Returns an error status.
        :rtype: BentleyStatus
        """
        return BentleyStatus.eERROR
    
    def OnProcessPolyface(self, geomPtr, path):
        """
        Processes a polyface geometry.

        :param geomPtr: Pointer to the geometry object to be processed.
        :type geomPtr: object
        :param path: Path to the geometry object.
        :type path: str
        
        :return: Status of the processing operation.
        :rtype: BentleyStatus
        """
        return BentleyStatus.eSUCCESS
    
    def GetSubEntityTypeMask(self):
        """
        Get the mask for the sub-entity type.

        :return: The mask for the sub-entity type, specifically for edges.
        :rtype: int
        """
        return ISubEntity.eSubEntityType_Edge
    
    def AcceptIdentifiesSubEntity(self):
        """
        Determines whether the tool accepts identified sub-entities.

        :return: Always returns True, indicating that sub-entities are accepted.
        :rtype: bool
        """
        return True
    
    def RequireSubEntitySupport(self):
        """
        Indicates whether sub-entity support is required.

        :returns: True if sub-entity support is required, False otherwise.
        :rtype: bool
        """
        return True

    def IsElementValidForOperation(self, element, path, cantAcceptReason):
        """
        Determines if the given element is valid for modification based on its geometry cache.

        This method checks if the element's geometry cache contains exactly one BRep solid and 
        that there is no missing geometry. It overrides the base class implementation to ensure 
        that the element is fully represented by a single solid. The method relies on the 
        _Collect and _OnProcess methods to collect only BRep solids.

        :param element: The element to be checked.
        :type element: Element
        :param path: The path associated with the element.
        :type path: Path
        :param cantAcceptReason: The reason why the element cannot be accepted, if applicable.
        :type cantAcceptReason: str
        
        :return: True if the element is valid for modification, False otherwise.
        :rtype: bool
        """
        # Self class implementation returns True if geometry cache isn't empty, which in this case means the cache contains at least 1 BRep solid.
        # To be valid for modification element should be fully represented by a single solid reject if there are multiple solid bodies or missing geometry.
        # NOTE: Simple count test is sufficient(w/o also checking TryGetAsBRep) as override of _Collect and _OnProcess methods have tool only collecting BRep solids.
        return self.IsElementValidForOperation(element, path, cantAcceptReason) and 1 == ElementGraphicsTool.GetElementGraphicsCacheCount(element) and not ElementGraphicsTool.IsGeometryMissing(element)

    def GetSmartFeatureNode(self, elementHandle, ev):
        """
        GetSmartFeatureNode(elementHandle, ev)

        Creates a blend feature node by identifying edges and faces from a given element handle 
        and event, and applying a specified radius to the blend.

        :param elementHandle: The handle to the element to be processed.
        :type elementHandle: ElementHandle
        :param ev: The event used for locating sub-entities.
        :type ev: Event

        :return: A feature node representing the blend feature created.
        :rtype: FeatureNode

        :raises SolidUtilError: If the conversion of the element to a body fails.
        :raises FeatureCreateError: If the creation of the blend feature fails.

        :note:
            - The radius for the blend is calculated based on the model's unit of resolution (UOR).
            - The function supports tangent edges if `self.m_blendEdgeAllowTangentEdges` is set to True.
        """
        edgeList = ISubEntityPtrArray()
        solid = SolidUtil.Convert.ElementToBody(elementHandle, True, True, False)   # Convert the profile element to a body
        SolidUtil.GetBodyEdges(edgeList, solid[1])  # Get the number of edges in the solid body
        radius =  float(self.m_blendEdgeRadius)
        model = self.modelRef.GetDgnModel()
        radius = model.GetModelInfo().UorPerMeter * radius
        isSmoothEdges = self.m_blendEdgeAllowTangentEdges
        faceIds = FaceIdArray()
        intersectEntitiesNative = ISubEntityPtrArray()
        intersectPtsNative = DPoint3dArray()
        intersectParamsNative = DPoint2dArray()
        LocateSubEntityTool().DoPickSubEntities(elementHandle, ev, intersectEntitiesNative, intersectPtsNative, intersectParamsNative)
        for entity in intersectEntitiesNative:
            faceId = SolidUtil.TopologyID.IdFromFace(entity, False)
            faceIds.append(faceId[1])
        edge = EdgeId()
        edge.SetFaces(faceIds[0], faceIds[1])
        edgeIdArray = EdgeIdArray()
        edgeIdArray.append(edge)
        featureNode = FeatureCreate.CreateBlendFeature(edgeIdArray, radius, isSmoothEdges)
        return featureNode

    def _OnDataButton(self, ev):
        """
        Handles the data button event to modify edges in a DGN model.
        This method performs the following steps:
        1. Retrieves the active DGN model reference.
        2. Displays a message indicating whether the DGN model was successfully selected.
        3. Locates an element based on the event and creates an `ElementHandle` for it.
        4. Retrieves a smart feature node associated with the element.
        5. Creates a mapping of child elements to control flags.
        6. Attempts to create and write a smart feature element to modify edges.
        7. Displays a success or error message based on the operation's outcome.
        :param ev: The event object containing information about the data button event.
        :type ev: Event
        """
        ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
        self.dgnModel = ACTIVEMODEL.GetDgnModel()
        if self.dgnModel != None:
            MessageCenter.ShowInfoMessage("DGN Model selected successfully.", "", False)
        else:
            MessageCenter.ShowErrorMessage("No DGN Model selected.", "", False)
        
        path = self._DoLocate(ev, True, ComponentMode.eInnermost)
        solidEditElementHandle = ElementHandle(path.GetHeadElem(), path.GetRoot())
        elementHandle = ElementHandle(solidEditElementHandle.ElementId, ACTIVEMODEL)
        newEditElementHandle = EditElementHandle()
        featureNode = self.GetSmartFeatureNode(elementHandle, ev)
        controlFlags = BoolArray()
        controlFlags.append(False)
        controlFlags.append(False)
        controlFlags.append(False)
        childElementToControlFlagsMap = {elementHandle.GetElementRef(): controlFlags}
        status = SmartFeatureElement.CreateAndWriteSmartFeatureElement(newEditElementHandle, elementHandle, ACTIVEMODEL, featureNode, childElementToControlFlagsMap)
        if status == BentleyStatus.eSUCCESS:
            MessageCenter.ShowInfoMessage("Edges are modified successfully.", "", False)
            return
        else:
            MessageCenter.ShowErrorMessage("Edges are not modified.", "", False)
            return

    def InstallNewInstance(toolId, radius = 0, allowTangentEdges = False):
        """
        Install a new instance of the ModifyEdge tool with the specified parameters.

        :param toolId: The identifier for the tool.
        :type toolId: int
        :param radius: The radius value to be used by the tool. Default is 0.
        :type radius: float, optional
        :param allowTangentEdges: Flag to allow tangent edges. Default is False.
        :type allowTangentEdges: bool, optional
        """
        tool = ModifyEdge(toolId, 0, radius, allowTangentEdges)
        tool.InstallTool()
    
    def OnRestartTool(self):
        """
        Restart the tool by installing a new instance of ModifyEdge.

        This method calls the `InstallNewInstance` method of the `ModifyEdge` class
        with an argument of 1 to restart the tool.

        :return: None
        """
        ModifyEdge.InstallNewInstance(1)
    
    def OnPostInstall(self):
        """
        This method is called after the installation process is completed.

        Note:
            This method currently calls itself recursively, which will lead to infinite recursion and a stack overflow error.
        """
        self.OnPostInstall()

    def OnResetButton(self, ev):
        """
        Handles the event when the reset button is pressed.

        :param ev: The event object associated with the reset button press.
        :type ev: Event
        
        :return: Always returns True.
        :rtype: bool
        """
        return True

class ModifyEdgeForm(QMainWindow):
    def __init__(self):
        """
        Initializes the ModifyEdgeSamples class.

        This constructor initializes the DGN model and file references, sets default values for various attributes, 
        and initializes the user interface.

        Attributes:
            dgnModel (DgnModel): The active DGN model reference.
            dgnFile (DgnFile): The active DGN file reference.
            m_textStyleHeight (float): The height of the text style, initialized to 0.
            m_tableElementId (int or None): The ID of the table element, initialized to None.
            textboxValue (str): The value of the textbox, initialized to an empty string.
            allowTangentEdges (bool): A flag indicating whether tangent edges are allowed, initialized to False.

        Raises:
            MessageCenter.ShowInfoMessage: If the DGN model is selected successfully.
            MessageCenter.ShowErrorMessage: If no DGN model is selected.
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
        self.textboxValue = ""
        self.allowTangentEdges = False
        self.initUI()

    def initUI(self):
        """
        Initializes the user interface for the Modify Edge Samples application.
        This method sets up the main window, including a central widget, a vertical layout,
        a textbox for input, a checkbox for an additional option, and a button to trigger
        the modification action. It also connects the relevant signals to their respective
        slots.
        The UI components include:
        - A QLineEdit for entering the radius value.
        - A QCheckBox to allow tangent edge modification.
        - A QPushButton to initiate the edge modification process.
        The method also attaches the Qt tool setting to the PyCad input queue.
        
        :return: None
        """
        # Create a central widget
        central_widget = QWidget(self)
        self.setCentralWidget(central_widget)

        # Create a vertical layout
        layout = QVBoxLayout(central_widget)

        self.setWindowTitle("Modify Edge Samples")
        self.setGeometry(10, 10, 400, 140)
        # Center the window on the screen
        screen_geometry = QApplication.desktop().screenGeometry()
        x = (screen_geometry.width() - self.width()) // 2
        y = (screen_geometry.height() - self.height()) // 2
        self.move(x, y)

        # Create textbox
        self.textbox = QLineEdit(self)
        self.textbox.move(20, 20)
        self.textbox.resize(280,40)
        self.textbox.setPlaceholderText("Enter radius value")
        self.textbox.textChanged.connect(self.on_click_text_box)
        
        # Create checkbox
        self.checkbox = QCheckBox('Allow Tangent Edge', self)
        self.checkbox.move(20, 80)
        self.checkbox.stateChanged.connect(self.update_label)

        # Create button
        self.button = QPushButton('Modify Edge', self)
        self.button.move(20, 120)
        self.button.clicked.connect(self.on_click_button)

        layout.addWidget(self.textbox)
        layout.addWidget(self.checkbox)
        layout.addWidget(self.button)

        self.storedWinId = self.winId()
        self.loop = QtCore.QEventLoop()
        QtCore.QCoreApplication.processEvents()
        PyCadInputQueue.AttachQtToolSetting(int(self.storedWinId))

    def on_click_text_box(self):
        """
        Handles the click event for the text box.

        This method is triggered when the text box is clicked. It retrieves the 
        current text from the text box and assigns it to the `textboxValue` attribute.

        :return: None
        """
        self.textboxValue = self.textbox.text()
    
    def update_label(self):
        """
        Update the label based on the state of the checkbox.

        This method updates the `allowTangentEdges` attribute to reflect whether
        the checkbox is checked or not. If the checkbox is checked, `allowTangentEdges`
        will be set to True; otherwise, it will be set to False.
        """
        self.allowTangentEdges = self.checkbox.isChecked()
    
    def on_click_button(self):
        """
        Handles the click event for a button.

        This method is triggered when the associated button is clicked. It installs a new instance of 
        the ModifyEdge class with the provided parameters.

        :param self: Reference to the current instance of the class.
        :type self: object
        """
        ModifyEdge.InstallNewInstance(1, self.textboxValue, self.allowTangentEdges)
    
    def ms_mainLoop(self):
        """
        Main loop that processes events and handles Python input queue.

        This function continuously checks if a specific window is still open.
        While the window is open, it processes events in the loop and handles
        the Python input queue. It also includes a small sleep interval to
        prevent high CPU usage.

        :return: None
        """
        while win32gui.IsWindow(self.storedWinId):
            self.loop.processEvents()
            PyCadInputQueue.PythonMainLoop()
            time.sleep(0.001)

def Run():
    """
    Run the main application.

    This function initializes the QApplication, creates an instance of the ModifyEdgeForm,
    displays it, and starts the main loop of the application.

    :returns: The instance of the ModifyEdgeForm.
    :rtype: ModifyEdgeForm
    """
    app = QApplication([])
    modifyEdgeForm = ModifyEdgeForm()
    modifyEdgeForm.show()
    modifyEdgeForm.ms_mainLoop()

if __name__ == "__main__":
    keyinXml = os.path.dirname(__file__) + '/ModifyEdgeSamples.commands.xml'
    PythonKeyinManager.GetManager().LoadCommandTableFromXml(WString(__file__), WString(keyinXml))