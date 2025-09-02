# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright:(c) 2022 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *
from MSPyDgnView import *

'''
Sample demonstrating how to create text block
''' 

'''
Function to text nodes in model in MicroStation using python.
sampleTexts[String array]: Collection of strings to display.
'''
def createsMultipleTextBlock(sampleTexts):
    textString1 = sampleTexts[0]
    textString2 = sampleTexts[1]
    textString3 = sampleTexts[2]
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    dgnFile = dgnModel.DgnFile
    if dgnFile != None:
        MessageCenter.ShowInfoMessage("The DGN File exists.", "", False)
    else:
        MessageCenter.ShowErrorMessage("The DGN File does not exists.", "", False)
    masterID = dgnModel.ModelId
    if masterID != INVALID_MODELID:
        MessageCenter.ShowInfoMessage("The DGN Model ID is valid.", "", False)
    else:
        MessageCenter.ShowErrorMessage("The DGN Model ID is invalid.", "", False)
    m_defaultModel = dgnFile.LoadRootModelById(masterID, True, True, True)

    # Create a variable to add the text properties.
    textBlockProperties = TextBlockProperties.Create(dgnModel)
    # Create a variable to add the paragraph properties.
    paragraphProperties = ParagraphProperties.Create(dgnModel)
    # Create a text font.
    runPropertiesFont = DgnFontManager.GetDefaultTrueTypeFont()
    # Create a text size.
    runPropertiesSize = DPoint2d(1000.0, 1000.0)
    # Add the text properties.
    runProperties = RunProperties.Create(runPropertiesFont, runPropertiesSize, dgnModel)
    # Textblock added the text strings to be displayed with the before-mentioned properties.
    textBlock = TextBlock(textBlockProperties, paragraphProperties, runProperties, m_defaultModel[0])
    textBlock.AppendText(textString1)
    textBlock.AppendText(textString2)
    textBlock.AppendText(textString3)
    textEditElementHandle = EditElementHandle()
    result = TextHandlerBase.CreateElement(textEditElementHandle, None, textBlock)
    if result == eTEXTBLOCK_TO_ELEMENT_RESULT_Success:
        textEditElementHandle.AddToModel()
        MessageCenter.ShowInfoMessage("Text block successfully added.", "", False)
    else:
        MessageCenter.ShowErrorMessage("Text block not added.", "", False)

#main
if __name__ == "__main__":
    sampleTexts = ["Text is useful for annotating models and sheets.\n",
                   "The attributes of text are typically controlled by a Text Style.\n",
                   "For example, you can use a Text Style to control the font, justification and size of text in your models.\n"]
    createsMultipleTextBlock(sampleTexts)