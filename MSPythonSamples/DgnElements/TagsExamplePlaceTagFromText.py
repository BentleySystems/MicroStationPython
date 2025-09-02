# $Copyright:(c) 2025 Bentley Systems, Incorporated. All rights reserved. $

import os
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

s_tagSetName = "TagExampleTagSet"
s_textStyleName = "TagExampleStyle"

class PlaceTagFromText(DgnElementSetTool):

    def __init__(self, toolId):
        """
        Initialize the TagsExamplePlaceTagFromText tool.

        :param toolId: Identifier for the tool.
        :type toolId: int
        """
        DgnElementSetTool.__init__(self, toolId)
        self.m_self = self # Keep self reference.
    
    def GetOrCreateTextStyle(self):
        """
        Retrieves an existing text style by name or creates a new one if it does not exist.

        This function attempts to get a text style with the specified name from the DGN file.
        If the text style does not exist, it creates a new one with predefined properties such as
        color, width, height, bold, italics, and underline, and then adds it to the DGN file.

        :return: The retrieved or newly created text style.
        :rtype: DgnTextStyle
        """
        # Retrieve the DGN file from the active model.
        dgnFile = GetDgnModel().DgnFile
        myStyle = DgnTextStyle.GetByName(s_textStyleName, dgnFile)
        if myStyle == None:
            myStyle = DgnTextStyle.Create(str(s_textStyleName), dgnFile)
            myStyle.SetProperty(eTextStyle_Color, 3)
            myStyle.SetProperty(eTextStyle_ColorFlag, True)
            myStyle.SetProperty(eTextStyle_Width, 1000.0)
            myStyle.SetProperty(eTextStyle_Height, 1000.0)
            myStyle.SetProperty(eTextStyle_Bold, True)
            myStyle.SetProperty(eTextStyle_Italics, True)
            myStyle.SetProperty(eTextStyle_Underline, True)
            myStyle.Add()
        return myStyle
    
    def setTagValue(self, tagEeh, text):
        """
        Set the value of a tag element based on the provided text.

        :param tagEeh: The element handle of the tag element.
        :type tagEeh: ElementHandle
        :param text: The text value to set for the tag element.
        :type text: str
        
        :raises ValueError: If the text cannot be converted to the appropriate type for the tag.
        """
        value = DgnTagValue()
        if BentleyStatus.eSUCCESS == TagElementHandler.GetAttributeValue(tagEeh, value):
            # Check if the tag type is CHAR or WCHAR and set the tag value accordingly.
            if value.GetTagType() == eMS_TAGTYPE_CHAR or value.GetTagType() == eMS_TAGTYPE_WCHAR:
                tagValue = DgnTagValue(text)
                # Set the tag value for CHAR or WCHAR types.
                TagElementHandler.SetAttributeValue(tagEeh, tagValue)
            elif value.GetTagType() == eMS_TAGTYPE_SINT or value.GetTagType() == eMS_TAGTYPE_LINT:
                # Set the tag value for SINT or LINT types.
                tagValue = DgnTagValue(int(text))
                TagElementHandler.SetAttributeValue(tagEeh, tagValue)
            elif value.GetTagType() == eMS_TAGTYPE_DOUBLE:
                # Set the tag value for DOUBLE types.
                tagValue = DgnTagValue(float(text))
                TagElementHandler.SetAttributeValue(tagEeh, tagValue)
    
    def isLongString(self, text):
        """
        Check if the given text consists entirely of digits.

        :param text: The text to be checked.
        :type text: str
        
        :return: True if the text consists only of digits, False otherwise.
        :rtype: bool
        """
        for char in text:
            if not char.isdigit():
                return False
        return True
    
    def isDoubleString(self, text):
        """
        Check if the given text represents a valid double-precision floating-point number.
        This function verifies if the input string `text` can be interpreted as a double-precision 
        floating-point number. It checks for the presence of digits, a single decimal point, 
        and optionally an exponent part (indicated by 'e' or 'E').
        
        :param text: The input string to be checked.
        :type text: str
        
        :return: True if the string represents a valid double-precision floating-point number, False otherwise.
        :rtype: bool
        """
        eCount = 0
        dotCount = 0
        for char in text:
            if char in ['e', 'E']:
                eCount += 1
                if eCount > 1:
                    return False
            elif char == '.':
                dotCount += 1
                if dotCount > 1:
                    return False
            elif char in ['+', '-']:
                continue
            elif not char.isdigit():
                return False
        return True

    def _OnElementModify(self, elementHandle):
        """
        Modify an element by adding a tag based on its text content.

        This method checks if the provided element is a valid text element or text node.
        If valid, it creates a tag element and attaches it to the text element with a specific tag name
        based on the content of the text. The tag is then added to the model.

        :param elementHandle: Handle to the element to be modified.
        :type elementHandle: ElementHandle
        """
        dgnModel = GetDgnModel()
        activeDgnFile = dgnModel.DgnFile
        if elementHandle.IsValid() and(elementHandle.ElementType == eTEXT_NODE_ELM or elementHandle.ElementType == eTEXT_ELM):
            # Initialize handles for tag and text elements.
            tagEditElementHandle = EditElementHandle()
            textEditElementHandle = EditElementHandle(elementHandle.ElementId, dgnModel)
            # Retrieve the text content from the text element handle.
            target = textEditElementHandle.ElementRef
            textQuery = textEditElementHandle.GetITextQuery()
            textPart = DimensionTextPartId.Create(0, eDIMTEXTPART_Primary, eDIMTEXTSUBPART_Main)
            textBlock = textQuery.GetTextPart(textEditElementHandle, textPart)
            text = str(textBlock.ToString())
            # Determine the tag name based on the content of the text.
            tagName = "Description"
            if self.isLongString(text):
                tagName = "Code"
            elif self.isDoubleString(text):
                tagName = "Measure"
            tagSetName = s_tagSetName
            # Set up the orientation, text style, and tag information for the new tag element.
            orientation = RotMatrix()
            style = self.GetOrCreateTextStyle()
            tagInfo = ITagCreateData(str(tagName), str(tagSetName), style, activeDgnFile)
            m_origin = DPoint3d()
            # Create a tag element and attach it to the text element.
            if BentleyStatus.eSUCCESS == TagElementHandler.CreateTagElement(tagEditElementHandle, None, tagInfo, dgnModel, dgnModel.Is3d(), m_origin, orientation, target):
                self.setTagValue(tagEditElementHandle, text)
                tagEditElementHandle.AddToModel()
                MessageCenter.ShowInfoMessage("Tag was added successfully.", "", False)
                self._OnRestartTool()
            else:
                MessageCenter.ShowErrorMessage("Tag was not created.", "", False)
                self._OnRestartTool()
    
    def _OnRestartTool(self):
        """
        Restart the tool by installing a new instance of PlaceTagFromText.

        This method is called to restart the tool, which involves creating and 
        installing a new instance of the PlaceTagFromText class using the current 
        ToolId.

        :return: None
        """
        PlaceTagFromText.InstallNewInstance(self.ToolId)

    def InstallNewInstance(toolId):
        """
        Install a new instance of the PlaceTagFromText tool.

        :param toolId: The identifier for the tool to be installed.
        :type toolId: int
        """
        tool = PlaceTagFromText(toolId)
        tool.InstallTool()

def GetDgnModel():
    """
    Retrieves the active DGN model reference.

    This function accesses the active DGN model reference from the session manager.
    If a DGN model is successfully retrieved, an informational message is displayed.
    If no DGN model is selected, an error message is shown.

    Returns:
        dgnModel: The active DGN model reference if available, otherwise None.
    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    if dgnModel != None:
        MessageCenter.ShowInfoMessage("DGN Model selected successfully.", "", False)
    else:
        MessageCenter.ShowErrorMessage("No DGN Model selected.", "", False)
    return dgnModel

def TagSetExists():
    """
    Check if a tag set exists in the current DGN model.

    This function checks if a tag set with the specified name exists in the 
    current DGN model file. It returns True if the tag set exists, otherwise 
    returns False.

    :return: True if the tag set exists, False otherwise.
    :rtype: bool
    """
    dgnFile = GetDgnModel().DgnFile
    if dgnFile == None:
        return False
    tagEditElementHandle = EditElementHandle()
    return BentleyStatus.eSUCCESS == TagSetHandler.GetByName(tagEditElementHandle, s_tagSetName, dgnFile)

if __name__ == "__main__":
    if not TagSetExists():
        MessageCenter.ShowErrorMessage("Tag Set does not exist. Please create tag set first using key-in 'CREATE TAGSET'.", "", False)
    else:
        PlaceTagFromText.InstallNewInstance(1)