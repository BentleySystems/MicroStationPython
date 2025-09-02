# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright:(c) 2025 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''

from math import pi
import os
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *
from MSPyDgnView import *

s_tagSetName = "TagExampleTagSet"
s_textStyleName = "TagExampleStyle"

class TagsExampleHelper:
    def TagSetExists(self):
        """
        Check if a tag set exists in the current DGN file.

        :return: True if the tag set exists, False otherwise.
        :rtype: bool
        """
        # Check if the tag set exists in the DGN file
        dgnFile = GetDgnModel().DgnFile
        if dgnFile == None:
            return False
        tagEeh = EditElementHandle()
        return BentleyStatus.eSUCCESS == TagSetHandler.GetByName(tagEeh, s_tagSetName, dgnFile)

class TagsExampleCreateTagSet:
    def __init__(self):
        """
        Initialize the TagsExampleCreateTagSet class.
        """

    def GetTagSetName(self):
        return s_tagSetName
    
    def InitDgnTagDefinition(self, tagDef, tagName, tagStyleName, tagPrompt):
        """
        Initializes a DGN tag definition with the provided parameters.

        :param tagDef: The tag definition object to be initialized.
        :type tagDef: object
        :param tagName: The name of the tag.
        :type tagName: str
        :param tagStyleName: The style name of the tag.
        :type tagStyleName: str
        :param tagPrompt: The prompt for the tag.
        :type tagPrompt: str
        """
        tagDef.name = tagName
        tagDef.styleName = tagStyleName
        tagDef.prompt = tagPrompt

    def GetOrCreateTextStyleName(self):
        """
        Retrieves an existing text style by name or creates a new one if it does not exist.
        This method attempts to find a text style with the specified name in the current DGN file.
        If the text style does not exist, it creates a new one with predefined properties such as
        color, width, height, bold, italics, and underline. The new text style is then added to the
        DGN file.
        :return: The name of the retrieved or newly created text style.
        :rtype: str
        """
        dgnFile = GetDgnModel().DgnFile
        # Attempt to retrieve an existing text style by name or create a new one if it does not exist
        myStyle = DgnTextStyle.GetByName(s_textStyleName, dgnFile)
        if not myStyle:
            myStyle = DgnTextStyle(s_textStyleName, dgnFile) # Create a new text style.
            myStyle.SetInt32Property(eTextStyle_Color, 3)
            myStyle.SetBoolProperty (eTextStyle_ColorFlag, True)
            myStyle.SetDoubleProperty(eTextStyle_Width, 1000.0)
            myStyle.SetDoubleProperty(eTextStyle_Height, 1000.0)
            myStyle.SetBoolProperty (eTextStyle_Bold, True)
            myStyle.SetBoolProperty (eTextStyle_Italics, True)
            myStyle.SetBoolProperty (eTextStyle_Underline, True)
            myStyle.Add()

        return myStyle.Name if myStyle else ""

    def createTagSet(self, tagDefs, numTagDefs, setName):
        """
        Create a tag set in the DGN file.

        :param tagDefs: The definitions of the tags to be included in the tag set.
        :type tagDefs: list
        :param numTagDefs: The number of tag definitions.
        :type numTagDefs: int
        :param setName: The name of the tag set to be created.
        :type setName: str
        
        :return: None
        :rtype: None
        :raises: Exception if the tag set creation fails.
        """
        # Create a tag set in the DGN file with the provided tag definitions and name
        dgnFile = GetDgnModel().DgnFile
        tagSetEditElementHandle = EditElementHandle()
        status = TagSetHandler.Create(tagSetEditElementHandle, tagDefs, numTagDefs, str(setName), None, True, dgnFile, 0)
        if status == BentleyStatus.eSUCCESS or tagSetEditElementHandle.IsValid():
            tagSetEditElementHandle.AddToModel()
            MessageCenter.ShowInfoMessage("Tag Set was added successfully.", "", False)
        else:
            MessageCenter.ShowErrorMessage("Tag Set was not created.", "", False)

    def initCreateTagSet(self):
        """
        Creates a tag set with predefined tag definitions and values.

        This method initializes a tag set with three tag definitions: "Description", "Code", and "Measure".
        Each tag definition is assigned a text style, a prompt string, and a default value.

        The tag definitions are:
        - "Description": A string tag with the prompt "Prompt String" and default value "Hello".
        - "Code": An integer tag with the prompt "Prompt Long" and default value 123.
        - "Measure": A double tag with the prompt "Prompt Double" and default value 3.4.

        The tag set is then created with these tag definitions.

        :return: None
        """
        # Retrieve the tag set name and text style name
        tagSetName = WString(self.GetTagSetName())
        styleName = str(self.GetOrCreateTextStyleName())
        # Initialize tag definitions with names, styles, and prompts
        tagDefs = DgnTagDefinitionArray()
        tagDefs.append(DgnTagDefinition())
        tagDefs.append(DgnTagDefinition())
        tagDefs.append(DgnTagDefinition())
        self.InitDgnTagDefinition(tagDefs[0], "Description", styleName, "Prompt String")
        self.InitDgnTagDefinition(tagDefs[1], "Code", styleName, "Prompt Long")
        self.InitDgnTagDefinition(tagDefs[2], "Measure", styleName, "Prompt Double")
        # Set default values for the tag definitions and create the tag set
        tagDefs[0].tagValue.SetTagValue("Hello")
        tagDefs[1].tagValue.SetTagValue(123)
        tagDefs[2].tagValue.SetTagValue(3.4)
        self.createTagSet(tagDefs, 3, tagSetName)
        return
    
    def _OnRestartTool(self):
        TagsExampleCreateTagSet.InstallNewInstance()

def GetDgnModel():
    """
    Retrieves the active DGN model reference.

    This function accesses the active DGN model reference from the session manager.
    If a DGN model is successfully retrieved, an informational message is displayed.
    Otherwise, an error message is shown.

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
    
def tagsExample_createTagSet():
    """
    Creates a tag set if it does not already exist.

    This function checks if a tag set already exists using the `TagSetExists` method
    from the `TagsExampleHelper` class. If the tag set exists, it shows an informational
    message indicating that the tag set already exists. If the tag set does not exist,
    it creates a new tag set using the `createTagSet` method from the `TagsExampleCreateTagSet` class.

    Returns:
        None
    """
    if TagsExampleHelper().TagSetExists():
        message = "Tag Set already exists."
        MessageCenter.ShowInfoMessage(message, "", False)
        return
    else:
        TagsExampleCreateTagSet().initCreateTagSet()
        
if __name__ == "__main__":
    keyinXml = os.path.dirname(__file__) + '/TagsExampleCreateTagSet.commands.xml'
    PythonKeyinManager.GetManager().LoadCommandTableFromXml(WString(__file__), WString(keyinXml))