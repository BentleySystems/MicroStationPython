from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *
from TextExampleCreateTextStyles import *


'''
Sample demonstrating how to create a text node element with single or multiple lines of text
'''

def CreateTextByStyle(styleName):
    """
    Creates text elements based on the style defined in the given enum.
    """
    RemoveExistingElements()
    if not DgnTextStyle.ExistsByName(styleName, activeDgnFile):
        CreateTextStyle(styleName)
    PlaceText(styleName)

def PlaceText(styleName: str):
    """
    Places text and text node elements using the specified style name.
    """
    global activeModel, dgnModel, activeDgnFile
    unitsPerStorage = dgnModel.GetModelInfo().GetUorPerStorage()    
    style = DgnTextStyle.GetByName(styleName, activeDgnFile)

    if not CreateTextElement(DPoint3d(45 * unitsPerStorage, 120 * unitsPerStorage, 0), style):
        MessageCenter.ShowErrorMessage("Failed to create text element.","",False)

    if not CreateTextNode(DPoint3d(45 * unitsPerStorage, 70 * unitsPerStorage, 0), style):
        MessageCenter.ShowErrorMessage("Failed to create text node element.","",False)

# Create a text node element with multiple lines of text
def CreateTextNode(basePoint:DPoint3d, textStyle:DgnTextStyle):
    """
    Creates a multi-line text node element at a given base point.

    Parameters:
        basePoint (DPoint3d): The 3D base point for the text node.
        textStyle (DgnTextStyle): The text style to use for the text node.

    Returns:
        bool: True if the text node is successfully created, False otherwise.
    """
    global activeModel
    global dgnModel

    textBlockProps = TextBlockProperties.Create(dgnModel)
    paragraphProps = ParagraphProperties.Create(dgnModel)
    runProps = RunProperties.Create(textStyle, dgnModel)
    textBlock = TextBlock(textBlockProps, paragraphProps, runProps, dgnModel)

    # Add multiple lines of text to the text block
    textBlock.AppendText(f"Style Used: {textStyle.GetName()}")
    textBlock.AppendLineBreak()
    textBlock.AppendLineBreak()
    textBlock.AppendLineBreak()

    textBlock.AppendText("First Line")
    textBlock.AppendLineBreak()
    textBlock.AppendLineBreak()
    textBlock.AppendLineBreak()

    textBlock.AppendText("Second Line")
    textBlock.AppendLineBreak()
    textBlock.AppendLineBreak()
    textBlock.AppendLineBreak()

    textBlock.AppendText("Third Line")
    textBlock.SetUserOrigin(basePoint)

    textNodeHandle = EditElementHandle()
    status = TextElemHandler.CreateElement(textNodeHandle, None, textBlock)

    if TextBlockToElementResult.eTEXTBLOCK_TO_ELEMENT_RESULT_Success != status:
        return False

    return BentleyStatus.eSUCCESS == textNodeHandle.AddToModel()

# Create a single-line text element
def CreateTextElement(basePoint:DPoint3d, textStyle:DgnTextStyle):
    """
    Creates a single-line text element at a given base point.

    Parameters:
        basePoint (DPoint3d): The 3D base point for the text element.
        textStyle (DgnTextStyle): The text style to use for the text element.

    Returns:
        bool: True if the text element is successfully created, False otherwise.
    """
    global activeModel
    global dgnModel

    textBlockProps = TextBlockProperties.Create(dgnModel)
    paragraphProps = ParagraphProperties.Create(dgnModel)
    runProps = RunProperties.Create(textStyle, dgnModel)
    textBlock = TextBlock(textBlockProps, paragraphProps, runProps, dgnModel)

    # Add heading text to the text block
    textBlock.AppendText("Heading Text")
    textBlock.SetUserOrigin(basePoint)

    textElementHandle = EditElementHandle()
    status = TextElemHandler.CreateElement(textElementHandle, None, textBlock)

    if TextBlockToElementResult.eTEXTBLOCK_TO_ELEMENT_RESULT_Success != status:
        return False

    return BentleyStatus.eSUCCESS == textElementHandle.AddToModel()

def CreateTextBlockExample2 (): 
    RemoveExistingElements()   
    global activeModel
    global dgnModel

    unitsPerStorage = dgnModel.GetModelInfo().GetUorPerStorage()

    style = DgnTextStyle.GetByName(TextExampleStyles.Example2_Style.value, activeDgnFile)
    if not style:
        CreateTextStyle(TextExampleStyles.Example2_Style.value)

    origin = DPoint3d(45 * unitsPerStorage, 120 * unitsPerStorage, 0)
    textBlockProps = TextBlockProperties.Create(dgnModel)
    paraProps = ParagraphProperties.Create(dgnModel)
    runProps = RunProperties.Create(style, dgnModel)
    textBlock = TextBlock(textBlockProps, paraProps, runProps, dgnModel)
    indentation = IndentationData()
    indentation.SetFirstLineIndent (1000.0)
    indentation.SetHangingIndent (5000.0)
    paraProps.SetIndentation (indentation)
    paraProps.SetIsFullJustified(False)
    paraProps.SetJustification(TextElementJustification.eLeftTop)
    textBlock.SetParagraphPropertiesForAdd (paraProps)

    # We are going to add three lines of text to this paragraph.
    # Bold and color 2
    # Italic and color 3
    # Bold/Italic and color 4

    runProps = textBlock.GetRunPropertiesForAdd ().Clone ()
    runProps.SetColor (2)
    runProps.SetIsBold (True)
    runProps.SetIsItalic (False)
    textBlock.SetRunPropertiesForAdd (runProps)
    textBlock.AppendText("This is example of Bold text.")
    textBlock.AppendLineBreak()

    runProps = textBlock.GetRunPropertiesForAdd ().Clone ()
    runProps.SetColor (3)
    runProps.SetIsBold (False)
    runProps.SetIsItalic (True)
    textBlock.SetRunPropertiesForAdd (runProps)
    textBlock.AppendText("This is example of Italic text.")
    textBlock.AppendLineBreak()

    runProps = textBlock.GetRunPropertiesForAdd ().Clone ()
    runProps.SetColor (4)
    runProps.SetIsBold (True)
    runProps.SetIsItalic (True)
    textBlock.SetRunPropertiesForAdd (runProps)
    textBlock.AppendText("This is example of Bold/Italic text.")
    textBlock.AppendParagraphBreak()

    #Set paragraph properties
    paraProps = textBlock.GetParagraphPropertiesForAdd ().Clone ()
    paraProps.SetIsFullJustified(True)
    paraProps.SetJustification(TextElementJustification.eCenterMiddle)
    textBlock.SetParagraphPropertiesForAdd (paraProps)

    #We are going to add two lines of text to this paragraph with Stacked Fraction of type DiagonalBar and HorizontalBar.
    runProps = textBlock.GetRunPropertiesForAdd ().Clone ()
    runProps.SetColor (5)
    runProps.SetIsBold (True)
    runProps.SetIsItalic (False)
    textBlock.SetRunPropertiesForAdd (runProps)

    textBlock.AppendText("This is example of Diagonal Bar Fraction ")
    textBlock.AppendStackedFraction ("11", "23", StackedFractionType.eDiagonalBar, StackedFractionAlignment.eTop)
    textBlock.AppendLineBreak()

    textBlock.AppendText("This is example of Horizontal Bar Fraction ")
    textBlock.AppendStackedFraction ("151", "253", StackedFractionType.eHorizontalBar, StackedFractionAlignment.eMiddle)    

    textBlock.SetUserOrigin(origin)

    textElementHandle = EditElementHandle()
    status = TextElemHandler.CreateElement(textElementHandle, None, textBlock)

    if TextBlockToElementResult.eTEXTBLOCK_TO_ELEMENT_RESULT_Success != status:
        return False

    return BentleyStatus.eSUCCESS == textElementHandle.AddToModel()    

def RemoveExistingElements():
    """
    Deletes all visible graphical elements from the active DGN model.
    """
    global activeModel
    global dgnModel
    global activeDgnFile

    # Initialize the active DGN model and file
    activeModel = ISessionMgr.ActiveDgnModelRef
    activeDgnFile = activeModel.GetDgnFile()
    dgnModel = activeModel.GetDgnModel()

    for elementRef in dgnModel.GetGraphicElements():
        editElementHandle = EditElementHandle(elementRef, dgnModel)
        msElement = editElementHandle.GetElement()

        if msElement.ehdr.isGraphics and not msElement.hdr.dhdr.props.b.invisible:
            editElementHandle.DeleteFromModel()
