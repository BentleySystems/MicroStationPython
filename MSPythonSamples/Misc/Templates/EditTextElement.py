from MSPyBentley import *
from MSPyECObjects import *
from MSPyBentleyGeom import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *
import tkinter as tk
from tkinter import simpledialog

class TextEditTool(DgnElementSetTool):
    def __init__(self, toolId):
        """
        Initialize the TextEditTool.

        :param toolId: Identifier for the tool.
        :type toolId: int
        """
        DgnElementSetTool.__init__(self, toolId)
        self.m_self = self  # Keep self reference

    def _OnDataButton(self, ev):
        """
        Handle the data button event to select and edit a text element.

        :param ev: The event object containing information about the button event.
        :type ev: DgnButtonEvent
        :return: True if the event was handled successfully, False otherwise.
        :rtype: bool
        """
        path = self._DoLocate(ev, True, ComponentMode.eInnermost)
        if not path:
            return False

        textEditElementHandle = EditElementHandle(path.GetHeadElem(), path.GetRoot())
        if not textEditElementHandle.IsValid():
            return False

        textQuery = textEditElementHandle.GetITextQuery()
        textPart = DimensionTextPartId.Create(0, eDIMTEXTPART_Primary, eDIMTEXTSUBPART_Main)
        textBlock = textQuery.GetTextPart(textEditElementHandle, textPart)
        if textBlock is None or textBlock.IsEmpty():
            return False

        # Get the current text from the text block
        currentText = textBlock.ToString().GetWCharCP()

        # Open a dialog box to edit the text
        root = tk.Tk()
        root.withdraw()  # Hide the root window
        newText = simpledialog.askstring("Edit Text", "Enter new text:", initialvalue=currentText)

        if newText is not None:
            # Update the text block with the new text
            textBlock.ReplaceText(newText, textBlock.CreateStartCaret(), textBlock.CreateEndCaret())
            textEditElementHandle.GetElementDescr () # force load of element descr into editelementhandle
            # Create the element with the updated text block
            newTextElementHandle = EditElementHandle()
            if TextElemHandler.CreateElement(newTextElementHandle, textEditElementHandle, textBlock) == TextBlockToElementResult.eTEXTBLOCK_TO_ELEMENT_RESULT_Success:
                newTextElementHandle.ReplaceInModel(textEditElementHandle.ElementRef)
                MessageCenter.ShowInfoMessage("Text updated successfully.", "", False)
            else:
                MessageCenter.ShowErrorMessage("Failed to update text element.", "", False)
        else:
            MessageCenter.ShowErrorMessage("Text update canceled.", "", False)

        return True

    def _OnRestartTool(self):
        """
        Restart the tool by installing a new instance of TextEditTool.

        :return: None
        """
        TextEditTool.InstallNewInstance(self.ToolId)

    @staticmethod
    def InstallNewInstance(toolId):
        """
        Create and install a new instance of the TextEditTool.

        :param toolId: Identifier for the tool.
        :type toolId: int
        """
        tool = TextEditTool(toolId)
        tool.InstallTool()

# Install the tool
TextEditTool.InstallNewInstance(1)