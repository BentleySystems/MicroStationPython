import os
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *
from TextExampleCreateTextStyles import *
from TextExampleCreateText import *
from enum import Enum


'''
Sample demonstrating how to create text with 4 different styles.
'''

# Function to create all four text styles
def CreateAllFourTextStyles():
    """
    Creates all the four text styles defined in the TextExampleStyles enum.
    If any of the styles fail to be created, an error message is shown.
    """
    for style in TextExampleStyles:
        # Attempt to create the text style, show error if it fails
        if not CreateTextStyle(style.value):
            MessageCenter.ShowErrorMessage(f"Failed to create {style.value}", "", False)
            return
    MessageCenter.ShowInfoMessage("All four text styles created.", "", False)

def CreateText_Vertical():
    """
    Creates text using the vertical style defined in the TextExampleStyles enum.
    """
    CreateTextByStyle(TextExampleStyles.ExampleStyle_Vertical.value)

def CreateText_NORMAL():
    """
    Creates text using the normal style defined in the TextExampleStyles enum.
    """
    CreateTextByStyle(TextExampleStyles.ExampleStyle_Normal.value)

def CreateText_UPSIDE_DOWN():
    """
    Creates text using the upside-down style defined in the TextExampleStyles enum.
    """
    CreateTextByStyle(TextExampleStyles.ExampleStyle_UpsideDown.value)

def CreateText_BACKWARDS():
    """
    Creates text using the backwards style defined in the TextExampleStyles enum.
    """
    CreateTextByStyle(TextExampleStyles.ExampleStyle_Backward.value)

def CreateText_Example2():
    """
    Creates text for Example 2. Shows info message if creation is successful.
    """
    if CreateTextBlockExample2():
        MessageCenter.ShowInfoMessage("Example 2 text created", "", False)

# Main execution block
if __name__ == "__main__":
    # Path to the keyin XML file
    keyinXml = os.path.dirname(__file__) + '/TextExample.commands.xml'
    # Load the command table from the XML
    PythonKeyinManager.GetManager().LoadCommandTableFromXml(WString(__file__), WString(keyinXml))
