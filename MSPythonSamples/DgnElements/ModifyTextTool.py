# $Copyright:(c) 2025 Bentley Systems, Incorporated. All rights reserved. $

import os
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

class ModifyTextTool(DgnElementSetTool):

    def __init__(self, toolId):
        """
        Initialize the ModifyTextTool.

        :param toolId: Identifier for the tool.
        :type toolId: int
        """
        DgnElementSetTool.__init__(self, toolId)
        self.m_self = self # Keep self reference.

    def _OnElementModify(self, elementHandle):
        """
        Modify the text of a given element in the DGN model.
        This method checks if the provided element handle is valid and if the element is of type text or text node.
        If valid, it retrieves the text from the element, toggles its case (upper to lower or lower to upper),
        and replaces the text in the model.
        
        :param elementHandle: Handle to the element to be modified.
        :type elementHandle: ElementHandle
        
        :returns: None
        """
        ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
        dgnModel = ACTIVEMODEL.GetDgnModel()
        if dgnModel != None:
            MessageCenter.ShowInfoMessage("DGN Model selected successfully.", "", False)
        else:
            MessageCenter.ShowErrorMessage("No DGN Model selected.", "", False)
        
        if elementHandle.IsValid() and (elementHandle.ElementType == eTEXT_NODE_ELM or elementHandle.ElementType == eTEXT_ELM):
            # Create an editable handle for the element using its ID and the DGN model.
            textEditElementHandle = EditElementHandle(elementHandle.ElementId, dgnModel)
            oldRef = textEditElementHandle.ElementRef
            # Retrieve the text query and edit interfaces for the element.
            textQuery = textEditElementHandle.GetITextQuery()
            textEdit = textEditElementHandle.GetITextEdit()
            textPart = DimensionTextPartId.Create(0, eDIMTEXTPART_Primary, eDIMTEXTSUBPART_Main)
            textBlock = textQuery.GetTextPart(textEditElementHandle, textPart)
            planeString = str(textBlock.ToString())
            # Toggle the case of the text in the text block.
            if planeString.islower():
                updatedString = planeString.upper()
            else:
                updatedString = planeString.lower()
            startCaret = textBlock.CreateStartCaret()
            endCaret = textBlock.CreateEndCaret()

            # Replace the text in text block with the updated upper case text.
            textBlock.ReplaceText(updatedString, startCaret, endCaret)
            textEdit.ReplaceTextPart(textEditElementHandle, textPart, textBlock)
            textEdit.GetTextPart(textEditElementHandle, textPart)
            if BentleyStatus.eSUCCESS == textEditElementHandle.ReplaceInModel(oldRef): # Replace the text element in the model.
                MessageCenter.ShowInfoMessage("Text was modified successfully.", "", False)
            else:
                MessageCenter.ShowErrorMessage("Text was not modified.", "", False)
            self._OnRestartTool()
            return
    
    def _OnRestartTool(self):
        """
        Restart the ModifyTextTool with the current ToolId.

        This method reinstalls a new instance of the ModifyTextTool using the 
        current ToolId. It is typically called to restart the tool with the 
        same configuration.

        :return: None
        """
        ModifyTextTool.InstallNewInstance(self.ToolId)

    def InstallNewInstance(toolId):
        """
        Create and install a new instance of ModifyTextTool.

        :param toolId: Identifier for the tool to be created and installed.
        :type toolId: int
        """
        tool = ModifyTextTool(toolId)
        tool.InstallTool()

if __name__ == "__main__":
    ModifyTextTool.InstallNewInstance(1)