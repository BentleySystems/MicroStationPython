from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *
from enum import Enum

'''
Sample demonstrating how to create a text Style based on the provided style name
'''

# Enum defining various text style names
class TextExampleStyles(Enum):
    ExampleStyle_Vertical = "ExampleStyle_Vertical"
    ExampleStyle_Normal = "ExampleStyle_Normal"
    ExampleStyle_UpsideDown = "ExampleStyle_UpsideDown"
    ExampleStyle_Backward = "ExampleStyle_Backward"
    Example2_Style = "Example2_Style"
    
def CreateTextStyle(styleName: str):
    """
    Creates a text style in the active DGN file based on the provided style name.
    
    Args:
    - styleName (str): The name of the style to be created.

    Returns:
    - bool: True if style is successfully created, False otherwise.
    """
    activeModel = ISessionMgr.ActiveDgnModelRef
    activeDgnFile = activeModel.GetDgnFile()

    # Check if the style already exists
    if DgnTextStyle.ExistsByName(styleName, activeDgnFile):
        msgStr = f"Style {styleName} already exists."
        MessageCenter.ShowInfoMessage(msgStr,"",False)
        return True
    
    if activeDgnFile is not None:
        # Handle different style creation based on the style name
        if styleName ==TextExampleStyles.ExampleStyle_Backward.value:
            style = DgnTextStyle(styleName, activeDgnFile)
            if style:
                # Set properties for backward style
                backOffset= DPoint2d(1.0,1.0)
                style.SetBoolProperty(TextStyleProperty.eTextStyle_Backwards, True)
                style.SetBoolProperty(TextStyleProperty.eTextStyle_Backgroundstyleflag, True)
                style.SetInt32Property(TextStyleProperty.eTextStyle_Backgroundstyle, 4)
                style.SetUInt32Property(TextStyleProperty.eTextStyle_Backgroundweight, 4)
                style.SetUInt32Property(TextStyleProperty.eTextStyle_Backgroundcolor, 4)
                style.SetUInt32Property(TextStyleProperty.eTextStyle_Backgroundfillcolor, 3)
                style.SetDPoint2dProperty(TextStyleProperty.eTextStyle_Backgroundborder, backOffset)
                style.SetDoubleProperty(TextStyleProperty.eTextStyle_Height, 90000)
                style.SetDoubleProperty(TextStyleProperty.eTextStyle_Width, 90000)
                # Add the text style to the active DGN file
                result = style.Add(activeDgnFile)
                return BentleyStatus.eSUCCESS == result
            
        elif styleName == TextExampleStyles.ExampleStyle_UpsideDown.value:
            style = DgnTextStyle(styleName, activeDgnFile)
            if style:
                #  Set properties for upside-down style (underline and overline)
                style.SetBoolProperty(TextStyleProperty.eTextStyle_Upsidedown, True)
                style.SetBoolProperty(TextStyleProperty.eTextStyle_Underline, True)
                style.SetBoolProperty(TextStyleProperty.eTextStyle_Underlinestyleflag, True)
                style.SetBoolProperty(TextStyleProperty.eTextStyle_Overline, True)
                style.SetBoolProperty(TextStyleProperty.eTextStyle_Overlinestyleflag, True)
                style.SetDoubleProperty(TextStyleProperty.eTextStyle_UnderlineOffset, 0.5)
                style.SetDoubleProperty(TextStyleProperty.eTextStyle_OverlineOffset, 0.5)
                style.SetUInt32Property(TextStyleProperty.eTextStyle_Underlinecolor, 2)
                style.SetUInt32Property(TextStyleProperty.eTextStyle_Underlineweight, 2)
                style.SetUInt32Property(TextStyleProperty.eTextStyle_Overlinecolor, 2)
                style.SetUInt32Property(TextStyleProperty.eTextStyle_Overlineweight, 2)
                style.SetInt32Property(TextStyleProperty.eTextStyle_Underlinestyle, 2)
                style.SetInt32Property(TextStyleProperty.eTextStyle_Overlinestyle,2)
                style.SetDoubleProperty(TextStyleProperty.eTextStyle_Height, 90000)
                style.SetDoubleProperty(TextStyleProperty.eTextStyle_Width, 90000)
                # Add the text style to the active DGN file
                result = style.Add(activeDgnFile)
                return BentleyStatus.eSUCCESS == result
            
        elif styleName == TextExampleStyles.ExampleStyle_Vertical.value:        
        # Create a new text style
            style = DgnTextStyle(styleName, activeDgnFile)
            if style:
                # Set properties for vertical text style
                style.SetBoolProperty(TextStyleProperty.eTextStyle_Vertical, True)
                style.SetUInt32Property(TextStyleProperty.eTextStyle_LineSpacingType, DgnLineSpacingType.eExact)
                style.SetDoubleProperty(TextStyleProperty.eTextStyle_LineSpacing, 2)
                style.SetDoubleProperty(TextStyleProperty.eTextStyle_InterCharSpacing, 2)
                style.SetDoubleProperty(TextStyleProperty.eTextStyle_Height, 90000)
                style.SetDoubleProperty(TextStyleProperty.eTextStyle_Width, 90000)
                lineOffset = DPoint2d.From(5.0, 5.0)
                style.SetDPoint2dProperty(TextStyleProperty.eTextStyle_LineOffset, lineOffset)
                # Add the text style to the active DGN file
                result = style.Add(activeDgnFile)
                return BentleyStatus.eSUCCESS == result
            
        elif styleName == TextExampleStyles.ExampleStyle_Normal.value:            
            # Create a new text style
            style = DgnTextStyle(styleName, activeDgnFile)
            if style:
                # Set properties for normal style (bold, italics, slant)
                style.SetBoolProperty(TextStyleProperty.eTextStyle_Bold, True)
                style.SetBoolProperty(TextStyleProperty.eTextStyle_Italics, True)
                style.SetDoubleProperty(TextStyleProperty.eTextStyle_Slant, ((30 * PI)/180))
                style.SetDoubleProperty(TextStyleProperty.eTextStyle_Height, 90000)
                style.SetDoubleProperty(TextStyleProperty.eTextStyle_Width, 90000)
                # Add the style
                result = style.Add(activeDgnFile)
                return BentleyStatus.eSUCCESS == result
            
        elif styleName == TextExampleStyles.Example2_Style.value:            
            # Create a new text style
            style = DgnTextStyle(styleName, activeDgnFile)
            # Set properties for Example2 style
            if style:
                style.SetDoubleProperty(TextStyleProperty.eTextStyle_Height, 90000)
                style.SetDoubleProperty(TextStyleProperty.eTextStyle_Width, 90000)
                # Add the style
                result = style.Add(activeDgnFile)
                return BentleyStatus.eSUCCESS == result
    return False    
