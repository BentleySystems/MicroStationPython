# $Copyright:(c) 2024 Bentley Systems, Incorporated. All rights reserved. $

import os
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *
import sys

ModifyMultipleElements_Color = 1
ModifyMultipleElements_Weight = 2
ModifyMultipleElements_LineStyle = 3
ModifyMultipleElements_Level = 4
ModifyMultipleElements_TextStyle = 5

'''
Use the following key-ins to test the tool:
- Modify Text Style: "modifyelement textstyle <Text Style Name>"
- Modify Element Weight: "modifyelement weight"
- Modify Element Colour: "modifyelement colour"
- Modify Element Level: "modifyelement level <Level Name>"
- Modify Element Line Style: "modifyelement linestyle"
'''

"""
A class to modify DGN elements based on different modification modes.
"""

class ModifyElement(DgnElementSetTool):

    def __init__(self, toolId, m_modifyMode):
        """
        Initializes the ModifyElements tool with the given tool ID and modify mode.

        Args:
            toolId (int): The ID of the tool.
            m_modifyMode (int): The mode of modification to be applied.
        """
        DgnElementSetTool.__init__(self, toolId) # C++ base's __init__ must be called.
        self.m_transform = Transform()
        self.m_self = self # Keep self reference
        self.m_modifyMode = m_modifyMode
        
    def _SetupForModify(self, ev, isDynamics):
        """
        Sets up the necessary parameters for modifying an element based on the given event.
        Args:
            ev: The event containing the point information for the modification.
            isDynamics (bool): A flag indicating whether the modification is dynamic.
        Returns:
            bool: True if the setup was successful, False otherwise.
        """
        anchorPt = DPoint3d()

        # Base class saves the location that was used to accept the element, selection set, or fence.
        if not self._GetAnchorPoint(anchorPt):
            return False

        vec = DVec3d()
        
        # Setup translation from accept point to this button event point.
        vec.DifferenceOf(ev.Point, anchorPt)
        self.m_transform.InitFrom(vec)

        return True
    
    def getTextStyle(self, styleName):
        """
        Retrieve or create a text style by name in the active DGN file.

        :param styleName: The name of the text style to retrieve or create.
        :type styleName: str
        
        :return: The text style object if found or successfully created, otherwise False.
        :rtype: DgnTextStyle or bool

        This method attempts to retrieve a text style by its name from the active DGN file.
        If the text style does not exist and the name is not "Test Style", the method returns False.
        If the text style does not exist and the name is "Test Style", a new text style is created
        with default properties (height and width set to 2000), added to the active DGN file, and
        then returned. If the creation or addition of the text style fails, the method returns False.
        """
        m_textStyleObj = DgnTextStyle.GetByName(str(styleName), self.dgnFile)
        if not m_textStyleObj and styleName != "Test Style":
            return False
        elif not m_textStyleObj:
            style = DgnTextStyle(styleName, self.dgnFile)
            if style:
                # Set properties for backward style
                style.SetDoubleProperty(TextStyleProperty.eTextStyle_Height, 2000)
                style.SetDoubleProperty(TextStyleProperty.eTextStyle_Width, 2000)
                # Add the text style to the active DGN file
                result = style.Add(self.dgnFile)
                return DgnTextStyle.GetByName(str(styleName), self.dgnFile) if BentleyStatus.eSUCCESS == result else False
        return m_textStyleObj
    
    def getLevel(self, levelName):
        """
        Retrieves or creates a level in the design file by its name.
        :param str levelName: The name of the level to retrieve or create.
        
        :return: A handle to the level if successful, or False if the level cannot be retrieved or created.
        :rtype: LevelHandle or bool
        
        :raises AttributeError: If `self.dgnFile` is None or does not have the required methods.
        
        This method first checks if the design file (`self.dgnFile`) is available. If not, it returns False.
        It then attempts to retrieve the level from the level cache. If the level does not exist and the
        name is not "Test Level", it returns False. If the level name is "Test Level" or the level does
        not exist, it attempts to create the level. If creation fails, it returns False. Otherwise, it
        writes the level to the cache and returns the level handle.
        """
        if self.dgnFile is None:
            return False

        levelCatch = self.dgnFile.GetLevelCache()
        if levelCatch is None:
            return False

        LevelHandle = levelCatch.GetLevelByName(levelName)
        if not LevelHandle.IsValid() and levelName != "Test Level":
            return False
        elif not LevelHandle.IsValid():
            LevelHandle = levelCatch.CreateLevel(levelName, LEVEL_NULL_CODE, LEVEL_NULL_ID)
            if not LevelHandle.IsValid():
                return False
            levelCatch.Write()

        return LevelHandle

    def _OnElementModify(self, elementHandle):
        """
        Modifies the properties of a given element based on the current modification mode.
        Parameters:
        elementHandle (ElementHandle): The handle of the element to be modified.
        The function supports the following modification modes:
        - ModifyMultipleElements_TextStyle: Modifies the text style of text elements.
        - ModifyMultipleElements_Weight: Modifies the weight of elements.
        - ModifyMultipleElements_Color: Modifies the color of elements.
        - ModifyMultipleElements_Level: Modifies the level of elements.
        - ModifyMultipleElements_LineStyle: Modifies the line style of elements.
        The function performs the following steps:
        1. Retrieves the active DGN model.
        2. Displays a message indicating whether the DGN model was selected successfully.
        3. Depending on the modification mode, performs the corresponding modification on the element.
        4. Displays a message indicating whether the modification was successful or not.
        """
        ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
        self.dgnModel = ACTIVEMODEL.GetDgnModel()
        if self.dgnModel != None:
            MessageCenter.ShowInfoMessage("DGN Model selected successfully.", "", False)
        else:
            MessageCenter.ShowErrorMessage("No DGN Model selected.", "", False)
        self.dgnFile = self.dgnModel.GetDgnFile()

        if self.m_modifyMode == ModifyMultipleElements_TextStyle:
            if elementHandle.IsValid() and (elementHandle.ElementType == eTEXT_NODE_ELM or elementHandle.ElementType == eTEXT_ELM):
                textEditElementHandle = EditElementHandle(elementHandle.ElementId, self.dgnModel)
                oldRef = textEditElementHandle.ElementRef
                textEdit = textEditElementHandle.GetITextEdit() # We have made sure(in _OnPostLocate) in this case that only text elements get selected.
                # Extract the TextBlock from the Text element.
                textPart = DimensionTextPartId.Create(0, eDIMTEXTPART_Primary, eDIMTEXTSUBPART_Main)
                textBlock = textEdit.GetTextPart(elementHandle, textPart)
                if not textBlock is None and not textBlock.IsEmpty():
                    startCaret = textBlock.CreateStartCaret()
                    endCaret = textBlock.CreateEndCaret()
                    styleName = " ".join(sys.argv) if len(sys.argv) > 0 else "Test Style" # Get the style name from the command line argument.
                    textStyle = self.getTextStyle(styleName)
                    if not textStyle:
                        MessageCenter.ShowErrorMessage("TextStyle '{}' does not exists.".format(styleName), "", False)
                        return
                    textBlock.ApplyTextStyle(textStyle, True, startCaret, endCaret) # Apply the text style to the text block.
                    textBlock.PerformLayout()
                    textEdit.ReplaceTextPart(textEditElementHandle, textPart, textBlock)
                    textEdit.GetTextPart(textEditElementHandle, textPart)
                    result = textEditElementHandle.ReplaceInModel(oldRef) # Replace the text element in the model.
                    if result == BentleyStatus.eSUCCESS:
                        MessageCenter.ShowInfoMessage("Text modification successfully.", "", False)
                    else:
                        MessageCenter.ShowErrorMessage("Text modification failed.", "", False)
        
        if self.m_modifyMode == ModifyMultipleElements_Weight:
            elementEditElementHandle = EditElementHandle(elementHandle.ElementId, self.dgnModel)
            oldRef = elementEditElementHandle.ElementRef
            elementPropsGetter = ElementPropertiesGetter(elementEditElementHandle) # Get the properties of the element.
            elementPropsSetter = ElementPropertiesSetter() # Set the properties of the element.
            weight = elementPropsGetter.GetWeight() # Get the weight of the element.
            if weight >= 0 and weight <= 30:
                newWeight = weight+1
            else:
                newWeight = 0
            elementPropsSetter.SetWeight(newWeight) # Set the weight of the element.
            elementPropsSetter.Apply(elementEditElementHandle)
            result = elementEditElementHandle.ReplaceInModel(oldRef) # Replace the element in the model.
            if result == BentleyStatus.eSUCCESS:
                MessageCenter.ShowInfoMessage("Element weight modified successfully.", "", False)
            else:
                MessageCenter.ShowErrorMessage("Element weight was not modified.", "", False)
        
        if self.m_modifyMode == ModifyMultipleElements_Color:
            elementEditElementHandle = EditElementHandle(elementHandle.ElementId, self.dgnModel)
            oldRef = elementEditElementHandle.ElementRef
            elementPropsGetter = ElementPropertiesGetter(elementEditElementHandle) # Get the properties of the element.
            elementPropsSetter = ElementPropertiesSetter() # Set the properties of the element.
            colour = elementPropsGetter.GetColor() # Get the colour of the element.
            if colour >= 0 and colour <= 30:
                newColour = colour+1
            else:
                newColour = 0
            elementPropsSetter.SetColor(newColour) # Set the colour of the element.
            elementPropsSetter.Apply(elementEditElementHandle)
            result = elementEditElementHandle.ReplaceInModel(oldRef) # Replace the element in the model.
            if result == BentleyStatus.eSUCCESS:
                MessageCenter.ShowInfoMessage("Element colour modified successfully.", "", False)
            else:
                MessageCenter.ShowErrorMessage("Element colour was not modified.", "", False)
        
        if self.m_modifyMode == ModifyMultipleElements_Level:
            elementEditElementHandle = EditElementHandle(elementHandle.ElementId, self.dgnModel)
            oldRef = elementEditElementHandle.ElementRef
            elementPropsGetter = ElementPropertiesGetter(elementEditElementHandle) # Get the properties of the element.
            elementPropsSetter = ElementPropertiesSetter() # Set the properties of the element.
            levelName = " ".join(sys.argv) if len(sys.argv) > 0 else "Test Level" # Get the level name from the command line argument.
            m_Level = self.getLevel(levelName) # Get the level of the element.
            if not m_Level:
                MessageCenter.ShowErrorMessage("Level '{}' does not exists.".format(levelName), "", False)
                return
            levelId = m_Level.GetLevelId()
            elementPropsSetter.SetLevel(levelId) # Set the level of the element.
            elementPropsSetter.Apply(elementEditElementHandle)
            result = elementEditElementHandle.ReplaceInModel(oldRef) # Replace the element in the model.
            if result == BentleyStatus.eSUCCESS:
                MessageCenter.ShowInfoMessage("Element level modified successfully.", "", False)
            else:
                MessageCenter.ShowErrorMessage("Element level was not modified.", "", False)
        
        if self.m_modifyMode == ModifyMultipleElements_LineStyle:
            elementEditElementHandle = EditElementHandle(elementHandle.ElementId, self.dgnModel)
            oldRef = elementEditElementHandle.ElementRef
            elementPropsGetter = ElementPropertiesGetter(elementEditElementHandle) # Get the properties of the element.
            elementPropsSetter = ElementPropertiesSetter() # Set the properties of the element.
            style = elementPropsGetter.GetLineStyle() # Get the line style of the element.
            if style >= 0 and style <= 6:
                newStyle = style+1
            else:
                newStyle = 0
            elementPropsSetter.SetLinestyle(newStyle, None) # Set the line style of the element.
            elementPropsSetter.Apply(elementEditElementHandle)
            result = elementEditElementHandle.ReplaceInModel(oldRef) # Replace the element in the model.
            if result == BentleyStatus.eSUCCESS:
                MessageCenter.ShowInfoMessage("Element line style modified successfully.", "", False)
            else:
                MessageCenter.ShowErrorMessage("Element line style was not modified.", "", False)
        else:
            MessageCenter.ShowErrorMessage("The selected element is not valid for modification.", "", False)
            return
        
    def _OnRestartTool(self):
        """
        Restarts the tool by installing a new instance of ModifyElement with the current ToolId and modify mode.

        This method is typically called to reset the tool's state and ensure it is ready for a new operation.

        Args:
            self: The instance of the class that contains this method.

        Returns:
            None
        """
        ModifyElement.InstallNewInstance(self.ToolId, self.m_modifyMode)

    def InstallNewInstance(toolId, m_modifyMode):
        """
        Installs a new instance of the ModifyElement tool with the given tool ID and modify mode.

        Args:
            toolId (int): The ID of the tool to be installed.
            m_modifyMode (str): The mode in which the tool should operate.

        Returns:
            None
        """
        tool = ModifyElement(toolId, m_modifyMode)
        tool.InstallTool()

def modifyTextStyle():
    ModifyElement.InstallNewInstance(1, ModifyMultipleElements_TextStyle)

def modifyElementWeight():
    ModifyElement.InstallNewInstance(1, ModifyMultipleElements_Weight)

def modifyLineStyle():
    ModifyElement.InstallNewInstance(1, ModifyMultipleElements_LineStyle)

def modifyElementColour():
    ModifyElement.InstallNewInstance(1, ModifyMultipleElements_Color)

def modifyElementLevel():
    ModifyElement.InstallNewInstance(1, ModifyMultipleElements_Level)

if __name__ == "__main__":
    keyinXml = os.path.dirname(__file__) + '/ModifyMultipleElements.commands.xml'
    PythonKeyinManager.GetManager().LoadCommandTableFromXml(WString(__file__), WString(keyinXml))