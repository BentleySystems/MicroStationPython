# $Copyright:(c) 2025 Bentley Systems, Incorporated. All rights reserved. $
import os
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

REGEX_NUMERIC_SUBSTRING_SEARCH = "-?\\d+"
s_textStyleName = "TagExampleStyle"
textBlock = None

class IncrementTextToolState(DgnElementSetTool):
    def __init__(self, toolId):
        """
        Initialize the IncrementText tool.

        :param toolId: Identifier for the tool.
        :type toolId: int
        """
        self.TOOLSTATE_Locating = 0,
        self.TOOLSTATE_Dynamics = 1
        DgnElementSetTool.__init__(self, toolId)
        self.m_self = self  # Keep self reference
        self.m_toolState = self.TOOLSTATE_Locating

    def SetupForFind(self):
        """
        Setup the parameters for finding text using regular expressions.

        This method assigns a regular expression for numeric substring search
        to the `regEx` attribute and initializes the `findParams` attribute
        with an instance of `TextBlock.FindTextParameters`. If `findParams`
        is successfully initialized, it sets the parameter to use regular
        expressions for text search.

        :return: None
        """
        self.regEx.AssignA(REGEX_NUMERIC_SUBSTRING_SEARCH)
        self.findParams = TextBlock.FindTextParameters()
        if self.findParams is None:
            return
        self.findParams.SetUseRegularExpressions(True)
        
    def incrementText(self, m_textBlock):
        """
        Increment the numeric portion of the text within a TextBlock by 1.
        
        :param m_textBlock: The TextBlock object containing the text to be incremented.
        :type m_textBlock: TextBlock
        
        :return: BentleyStatus.eSUCCESS if the text was successfully incremented, BentleyStatus.eERROR otherwise.
        :rtype: BentleyStatus
        """
        if m_textBlock is None:
            return BentleyStatus.eERROR

        # Use regular expression to find the numeric portion
        self.regEx = WString("")
        self.findParams = TextBlock.FindTextParameters()
        self.SetupForFind()

        # Locate the last instance of number in the Text block string.
        searchStart = m_textBlock.CreateStartCaret()
        endCaret = m_textBlock.CreateEndCaret()
        foundRegion = None
        lastFoundRegion = None
        while True:
            foundRegion = m_textBlock.FindText(str(self.regEx), self.findParams, searchStart, endCaret)
            if not foundRegion:
                break
            searchStart = foundRegion.GetMatchEnd().Clone()
            lastFoundRegion = foundRegion

        # Return if the FindText result cannot be modified.
        if not lastFoundRegion or not lastFoundRegion.CanBeModified():
            return BentleyStatus.eERROR

        # Extract the Find result- number string.
        matchEnd = lastFoundRegion.GetMatchEnd().Clone()
        numString = m_textBlock.ToString(lastFoundRegion.GetMatchStart(), matchEnd)
        if not numString:
            return BentleyStatus.eERROR

        # Increment the value of the number by 1.
        incrementValue = 1
        newValue = int(str(numString)) + incrementValue

        # Replace the incremented number string in the Text block.
        m_textBlock.ReplaceText(str(newValue), lastFoundRegion.GetMatchStart(), matchEnd)

        return BentleyStatus.eSUCCESS
    
    def CreateTextElement(self, textEditElementHandle, m_textBlock, ev):
        """
        Create a text element from a text block and set its user origin.

        :param textEditElementHandle: Handle to the text edit element.
        :type textEditElementHandle: object
        :param m_textBlock: The text block to be converted into a text element.
        :type m_textBlock: object
        :param ev: Event containing the point to set as the user origin.
        :type ev: object
        
        :return: BentleyStatus.eSUCCESS if the text element is created successfully, otherwise BentleyStatus.eERROR.
        :rtype: BentleyStatus
        """
        if m_textBlock is None:
            return BentleyStatus.eERROR
        m_textBlock.SetUserOrigin(ev.GetPoint())
        return BentleyStatus.eERROR if eTEXTBLOCK_TO_ELEMENT_RESULT_Success != TextHandlerBase.CreateElement(textEditElementHandle, None, m_textBlock) else BentleyStatus.eSUCCESS
    
    def ValidateSelection(self, path):
        """
        Validates the selection based on the provided path.
        This method constructs an element handle from the given HitPath and checks if the selection
        is a Text element. If the selection is a Text element, it retrieves the text block and checks
        if the string in the text block is a numeric or alphanumeric string.
        
        :param path: The HitPath object representing the selection path.
        :type path: HitPath
        
        :return: The text block if the selection is a valid numeric or alphanumeric Text element, otherwise None.
        :rtype: TextBlock or None
        """
        if not path:
            return None

        # Construct an element handle from the HitPath.
        textEditElementHandle = ElementHandle(path.GetHeadElem(), path.GetRoot())

        # Check if the selection is a Text element.
        textQuery = textEditElementHandle.GetITextQuery()
        textPart = DimensionTextPartId.Create(0, eDIMTEXTPART_Primary, eDIMTEXTSUBPART_Main)
        textBlock = textQuery.GetTextPart(textEditElementHandle, textPart)
        if textBlock is None or textBlock.IsEmpty():
            return None

        # Get the string from the Text block.
        string = textBlock.ToString().GetWCharCP()[:-1]
        print(type(string), string)
        if not string:
            return None
        print(string.isnumeric(), string.isalnum())
        # Check if the string in the text block is a numeric/alphanumeric string.
        if string.isnumeric() or string.isalnum():
            return textBlock
        return None
    
    def SetToolState (self, toolState):
        """
        Set the state of the tool.

        :param toolState: The new state to set for the tool.
        :type toolState: Any
        """
        self.m_toolState = toolState

    def _SetupAndPromptForNextAction(self):
        """
        Sets up the tool state and prompts for the next action based on the current tool state.

        This method enables or disables the locate and snap functionalities of the AccuSnap instance
        depending on the current tool state.

        - If the tool state is `TOOLSTATE_Locating`, it enables locate and disables snap.
        - If the tool state is `TOOLSTATE_Dynamics`, it disables locate and enables snap.

        :return: None
        """
        if self.m_toolState == self.TOOLSTATE_Locating:
            AccuSnap.GetInstance().EnableLocate(True)
            AccuSnap.GetInstance().EnableSnap(False)
        elif self.m_toolState == self.TOOLSTATE_Dynamics:
            AccuSnap.GetInstance().EnableLocate(False)
            AccuSnap.GetInstance().EnableSnap(True)

    def _OnDataButton(self, ev):
        """
        Handles the data button event.
        This method is triggered when the data button is pressed. It performs the following actions:
        - Retrieves the active DGN model reference.
        - Displays a message indicating whether the DGN model was selected successfully.
        - Locates and validates the selected text block.
        - Increments the text within the text block.
        - Changes the tool state to 'Dynamics' and prompts the user for a 'Place/Reject' action.
        - If the text block is already defined, it creates a text element, adds it to the model, and increments the text.
        
        :param ev: The event object associated with the data button press.
        :type ev: Event
        
        :return: False if the text block is not valid or text incrementation fails, otherwise None.
        :rtype: bool or None
        """
        global textBlock
        ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
        self.dgnModel = ACTIVEMODEL.GetDgnModel()
        if textBlock is None:
            if self.dgnModel != None:
                MessageCenter.ShowInfoMessage("DGN Model selected successfully.", "", False)
            else:
                MessageCenter.ShowErrorMessage("No DGN Model selected.", "", False)
            
            path = self._DoLocate(ev, True, ComponentMode.eInnermost)
            if not path:
                return False

            textBlock = self.ValidateSelection(path)
            if textBlock is None or textBlock.IsEmpty():
                return False
            
            if BentleyStatus.eSUCCESS != self.incrementText(textBlock):
                return False
            
            # Change the state of the tool to 'Dynamics'.
            # Start dynamics and prompt the user for a 'Place/Reject' action.
            toolState = self.TOOLSTATE_Dynamics
            self.SetToolState(toolState)
            self._SetupAndPromptForNextAction()
            _BeginDynamics()
        else:
            textEditElementHandle = EditElementHandle()
            if BentleyStatus.eSUCCESS == self.CreateTextElement(textEditElementHandle, textBlock, ev) and textEditElementHandle.IsValid():
                textEditElementHandle.AddToModel()
                self.incrementText(textBlock)
                MessageCenter.ShowInfoMessage("Text incremented successfully.", "", False)
            else:
                MessageCenter.ShowErrorMessage("Text incrementation failed.", "", False)
    
    def _OnDynamicFrame(ev):
        """
        Handles the dynamic frame event by creating a text element and temporarily displaying it.

        :param ev: The event object containing information about the dynamic frame event.
        :type ev: Event

        :raises ValueError: If the text element handle is not valid.

        :return: None
        """
        # Create the text element and temporarily displays it.
        textEditElementHandle = EditElementHandle()
        if BentleyStatus.eSUCCESS == self.CreateTextElement(textEditElementHandle, textBlock, ev) and textEditElementHandle.IsValid():
            redrawElems = RedrawElems()
            redrawElems.SetDrawMode(eDRAW_MODE_TempDraw)
            redrawElems.SetDrawPurpose(DrawPurpose.eDynamics)
            redrawElems.SetViewport(ev.GetViewport())
            redrawElems.SetRedrawOp()
            redrawElems.DoRedraw(textEditElementHandle)

    def _OnRestartTool(self):
        """
        Restart the tool by installing a new instance of IncrementTextToolState.

        This method is called to restart the tool, which involves creating and 
        installing a new instance of the IncrementTextToolState class using the 
        current ToolId.

        :return: None
        """
        IncrementTextToolState.InstallNewInstance(self.ToolId)

    def InstallNewInstance(toolId):
        """
        Create and install a new instance of IncrementTextToolState.

        :param toolId: Identifier for the tool to be installed.
        :type toolId: int
        """
        tool = IncrementTextToolState(toolId)
        tool.InstallTool()

def initializeTextIncrement():
    IncrementTextToolState.InstallNewInstance(1)

if __name__ == "__main__":
    keyinXml = os.path.dirname(__file__) + '/IncrementText.commands.xml'
    PythonKeyinManager.GetManager().LoadCommandTableFromXml(WString(__file__), WString(keyinXml))