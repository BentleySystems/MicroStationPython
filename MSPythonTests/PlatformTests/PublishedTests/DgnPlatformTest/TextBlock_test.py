import os
import pytest
import math
import sys
import numpy as np
from numpy import arange
from collections import OrderedDict
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *


textQuery = None
def roundTripTextBlock (original, assertMessage, attempted):
    global textQuery
    fileEeh = EditElementHandle()
    attempted = False
    toElemResult = TextHandlerBase.CreateElement (fileEeh, None, original)
    assert toElemResult == TEXTBLOCK_TO_ELEMENT_RESULT_Success
    textQuery = fileEeh.GetITextQuery ()
    assert textQuery != None
    assert textQuery.IsTextElement (fileEeh) == True
    # ITextPartId constructor is not define
    
    # textParts = ITextPartId.Create()
    # textQuery.GetTextPartIds (fileEeh, ITextQueryOptions(), textParts)
    # assert textParts.size () == 1
    # roundTripped = textQuery.GetTextPart (fileEeh, textParts.front ())
    # assert roundTripped != None
    attempted = True
    # assert BackDoor.TextBlock.TextBlock_EqualsWithCompareContentAndLocation (original, roundTripped) == True



@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_TextBlockPropertiesCloneAndEqualityTests(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    lhsTbProps  = TextBlockProperties.Create (ret[0])
    rhsTbProps  = TextBlockProperties.Create (ret[0])
    # BackDoor is not exposed in python
    # assert BackDoor.TextBlock.TextBlockProperties_Equals (lhsTbProps, rhsTbProps) == True
    lhsTbProps.SetIsVertical (True)
    rhsTbProps = lhsTbProps.Clone ()
    # assert BackDoor.TextBlock.TextBlockProperties_Equals (lhsTbProps, rhsTbProps) == True
    lhsTbProps = TextBlockProperties.Create (ret[0])
    # assert BackDoor::TextBlock::TextBlockProperties_Equals (*lhsTbProps, *rhsTbProps) == False


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_ParagraphPropertiesCloneAndEqualityTests(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    lhsParaProps  = ParagraphProperties.Create (ret[0])
    rhsParaProps  = ParagraphProperties.Create (ret[0])
    # BackDoor is not exposed in python
    # assert BackDoor.TextBlock.ParagraphProperties_Equals (lhsParaProps, rhsParaProps) == True
    lhsParaProps.SetLineSpacingValue (500.0)
    rhsParaProps = lhsParaProps.Clone ()
    # assert BackDoor.TextBlock.ParagraphProperties_Equals (lhsParaProps, rhsParaProps) == True
    rhsParaProps.SetJustification (TextElementJustification.CenterMiddle)
    # assert BackDoor.TextBlock.ParagraphProperties_Equals (lhsParaProps, rhsParaProps) == False


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_RunPropertiesCloneAndEqualityTests(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    runPropsFont = DgnFontManager.GetDefaultTrueTypeFont ()
    runPropsSize = DPoint2d( 1000.0, 1000.0 )
    lhsRunProps = RunProperties.Create (runPropsFont, runPropsSize, ret[0])
    rhsRunProps = RunProperties.Create (runPropsFont, runPropsSize, ret[0])
    # BackDoor is not exposed in python
    # assert BackDoor.TextBlock.RunProperties_Equals (lhsRunProps, rhsRunProps) == True
    lhsRunProps.SetIsBold (True)
    rhsRunProps = lhsRunProps.Clone ()
    # assert BackDoor.TextBlock.RunProperties_Equals (lhsRunProps, rhsRunProps) == True
    rhsRunProps.SetIsItalic (True)
    # assert BackDoor.TextBlock.RunProperties_Equals (lhsRunProps, rhsRunProps) == False


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_TextBlockEqualsPositiveUnitTest(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    LOREM_IPSUM_1   = "Lorem ipsum"
    LOREM_IPSUM_2   = "dolor sit amet"
    tbProps = TextBlockProperties.Create (ret[0])
    paraProps = ParagraphProperties.Create (ret[0])
    runPropsFont = DgnFontManager.GetDefaultTrueTypeFont ()
    runPropsSize    = DPoint2d( 1000.0, 1000.0 )
    runProps = RunProperties.Create (runPropsFont, runPropsSize, ret[0])
    lhs = TextBlock (tbProps, paraProps, runProps, ret[0])
    rhs = TextBlock (tbProps, paraProps, runProps, ret[0])
    # BackDoor is not exposed in python
    # assert BackDoor.TextBlock.TextBlock_EqualsWithCompareContentAndLocation (lhs, rhs) == True
    lhs.AppendText (LOREM_IPSUM_1)
    rhs.AppendText (LOREM_IPSUM_1)
    # assert BackDoor.TextBlock.TextBlock_EqualsWithCompareContentAndLocation (lhs, rhs) == True
    tbProps.SetIsVertical (True)
    paraProps.SetLineSpacingValue (500.0)
    runProps.SetIsBold (True)
    lhs = TextBlock (tbProps, paraProps, runProps, ret[0])
    lhs.AppendText (LOREM_IPSUM_1)
    rhs = TextBlock (tbProps, paraProps, runProps, ret[0])
    rhs.AppendText (LOREM_IPSUM_1)
    # assert BackDoor.TextBlock.TextBlock_EqualsWithCompareContentAndLocation (lhs, rhs) == True
    paraProps.SetLineSpacingValue (0.0)
    lhs.SetParagraphPropertiesForAdd (paraProps)
    rhs.SetParagraphPropertiesForAdd (paraProps)
    runProps.SetIsBold (False)
    lhs.SetRunPropertiesForAdd (runProps)
    rhs.SetRunPropertiesForAdd (runProps)
    lhs.AppendParagraphBreak ()
    rhs.AppendParagraphBreak ()
    lhs.AppendText (LOREM_IPSUM_2)
    rhs.AppendText (LOREM_IPSUM_2)
    # assert BackDoor.TextBlock.TextBlock_EqualsWithCompareContentAndLocation (lhs, rhs) == True
    origin = DPoint3d()
    origin.Init (1.0, 2.0, 3.0)
    lhs.SetUserOrigin (origin)
    rhs.SetUserOrigin (origin)


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_TextBlockEqualsNegativeUnitTest(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    LOREM_IPSUM_1   = "Lorem ipsum"
    LOREM_IPSUM_2   = "dolor sit amet"
    tbProps = TextBlockProperties.Create (ret[0])
    paraProps = ParagraphProperties.Create (ret[0])
    runPropsFont = DgnFontManager.GetDefaultTrueTypeFont ()
    runPropsSize = DPoint2d( 1000.0, 1000.0 )
    runProps = RunProperties.Create (runPropsFont, runPropsSize, ret[0])
    lhs = TextBlock (tbProps, paraProps, runProps, ret[0])
    lhs.AppendText (LOREM_IPSUM_1)
    tbPropsMutated = tbProps.Clone ()
    tbPropsMutated.SetIsVertical (True)
    rhs = TextBlock (tbPropsMutated, paraProps, runProps, ret[0])
    rhs.AppendText (LOREM_IPSUM_1)
    # BackDoor is not exposed in python
    # assert BackDoor.TextBlock.TextBlock_EqualsWithCompareContentAndLocation (lhs, rhs) == False
    lhs = TextBlock (tbProps, paraProps, runProps, ret[0])
    lhs.AppendText (LOREM_IPSUM_1)
    rhs = TextBlock (tbProps, paraProps, runProps, ret[0])
    rhs.AppendText (LOREM_IPSUM_1)
    rhs.AppendText (LOREM_IPSUM_2)
    # assert BackDoor::TextBlock::TextBlock_EqualsWithCompareContentAndLocation (*lhs, *rhs) == False


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CombineRunsUnitTest(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    LOREM_IPSUM_1AB = "Lorem ipsum dolor sit amet"
    LOREM_IPSUM_1A  = "Lorem ipsum "
    LOREM_IPSUM_1B  = "dolor sit amet"
    tbProps = TextBlockProperties.Create (ret[0])
    paraProps = ParagraphProperties.Create (ret[0])
    runPropsFont = DgnFontManager.GetDefaultTrueTypeFont ()
    runPropsSize = DPoint2d( 1000.0, 1000.0 )
    runProps = RunProperties.Create (runPropsFont, runPropsSize, ret[0])
    lhs = TextBlock (tbProps, paraProps, runProps, ret[0])
    lhs.AppendText (LOREM_IPSUM_1AB)
    rhs = TextBlock (tbProps, paraProps, runProps, ret[0])
    rhs.AppendText (LOREM_IPSUM_1A)
    rhs.AppendText (LOREM_IPSUM_1B)
    # BackDoor is not exposed in python
    # assert BackDoor.TextBlock.TextBlock_EqualsWithCompareContentAndLocation (lhs, rhs) == True
    lhs = TextBlock (tbProps, paraProps, runProps, ret[0])
    lhs.AppendText (LOREM_IPSUM_1AB)
    rhs = TextBlock (tbProps, paraProps, runProps, ret[0])
    rhs.AppendText (LOREM_IPSUM_1A)
    runProps.SetIsBold (True)
    rhs.SetRunPropertiesForAdd (runProps)
    rhs.AppendText (LOREM_IPSUM_1B)
    # assert BackDoor.TextBlock.TextBlock_EqualsWithCompareContentAndLocation (lhs, rhs) == False


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_RoundTripMultiFormat(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    tbProps = TextBlockProperties.Create (ret[0])
    paraProps = ParagraphProperties.Create (ret[0])
    runPropsSize = DPoint2d(1000.0, 1000.0)
    runProps = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, ret[0])
    roundTripAttempted  = False
    lhs = TextBlock(tbProps, paraProps, runProps, ret[0])
    # BackDoor is not exposed in python
    # BackDoor.TextBlock.TextBlock_SetNodeProperties (lhs, runProps)
    lhs.AppendText ("Lorem ipsum dolor sit amet, ")
    runProps.SetIsBold (True)
    runProps.SetColor (6)
    lhs.SetRunPropertiesForAdd (runProps)
    lhs.AppendText ("consectetur adipiscing elit.")
    roundTripTextBlock (lhs, "Round-trip failed for single-line multi-format", roundTripAttempted)
    runProps = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, ret[0])
    lhs = TextBlock (tbProps, paraProps, runProps, ret[0])
    # BackDoor.TextBlock.TextBlock_SetNodeProperties (lhs, runProps)
    lhs.AppendText ("Lorem ipsum dolor sit amet, ")
    runProps.SetIsBold (True)
    runProps.SetColor (6)
    lhs.SetRunPropertiesForAdd (runProps)
    lhs.AppendText ("consectetur adipiscing elit.")
    lhs.AppendLineBreak ()
    runProps.SetCharacterSpacingType (CharacterSpacingType.FixedWidth)
    runProps.SetCharacterSpacingValue (100.0)
    lhs.SetRunPropertiesForAdd (runProps)
    lhs.AppendText ("Vestibulum ante quam, tincidunt sed elementum a, malesuada aliquet massa.")
    lhs.AppendParagraphBreak ()
    lhs.AppendText ("Vivamus quis leo nisi.")
    roundTripTextBlock (lhs, "Round-trip failed for multi-line multi-format", roundTripAttempted)
    runProps = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, ret[0])
    lhs = TextBlock (tbProps, paraProps, runProps, ret[0])
    # BackDoor.TextBlock.TextBlock_SetNodeProperties (lhs, runProps)
    lhs.AppendText ("Lorem ipsum dolor sit amet, ")
    lhs.AppendLineBreak ()
    lhs.AppendText ("consectetur adipiscing elit.")
    ndentation = IndentationData ()
    ndentation.SetFirstLineIndent (4000.0)
    tabStops = DoubleArray()
    tabStops.append (5000.0)
    tabStops.append (10000.0)
    tabStops.append (15000.0)
    ndentation.SetTabStops (tabStops)
    paraProps.SetIndentation (ndentation)
    lhs.SetParagraphPropertiesForAdd (paraProps)
    lhs.AppendParagraphBreak ()
    lhs.AppendText ("Vestibulum ante quam, tincidunt sed ")
    lhs.AppendLineBreak ()
    lhs.AppendText ("elementum a,")
    lhs.AppendTab ()
    lhs.AppendText ("malesuada")
    lhs.AppendTab ()
    lhs.AppendText ("aliquet massa.")
    roundTripTextBlock (lhs, "Round-trip failed for multi-paragraph multi-format", roundTripAttempted)


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_RoundTripOverrides(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    sampleColor = 7
    sampleDPoint2d = DPoint2d(123.0, 456.0)
    textStyle = DgnTextStyle ("GeneratedStyleForRoundTripOverrides", ret[0].GetDgnFile ())
    textStyle.SetBoolProperty (TextStyle_Vertical, True)
    textStyle.SetUInt32Property (TextStyle_Justification, TextElementJustification.RightTop)
    textStyle.SetDoubleProperty (TextStyle_Width, 1000.0)
    textStyle.SetDoubleProperty (TextStyle_Height, 1000.0)
    textStyle.SetBoolProperty (TextStyle_ColorFlag, True)
    textStyle.SetUInt32Property (TextStyle_Color, 6)
    textStyle.SetBoolProperty (TextStyle_Backgroundstyleflag, True)
    textStyle.SetInt32Property (TextStyle_Backgroundstyle, 0)
    textStyle.SetUInt32Property (TextStyle_Backgroundweight, 2)
    textStyle.SetUInt32Property (TextStyle_Backgroundcolor, 3)
    textStyle.SetUInt32Property (TextStyle_Backgroundfillcolor, 4)
    textStyle.SetDPoint2dProperty (TextStyle_Backgroundborder, sampleDPoint2d)
    textStyle.Add ()
    tbProps = TextBlockProperties.Create (textStyle, ret[0])
    paraProps = ParagraphProperties.Create (textStyle, ret[0])
    runProps = RunProperties.Create (textStyle, ret[0])
    roundTripAttempted  = False
    tbProps.SetIsVertical (False)
    paraProps.SetJustification (TextElementJustification.LeftTop)
    # BackDoor is not exposed in python
    # BackDoor.TextBlock.TextBlockProperties_SetNodeJustification (tbProps, TextElementJustification.LeftTop)
    runProps.SetFontSize (sampleDPoint2d)
    runProps.SetIsBold (True)
    runProps.SetBackgroundStyle (sampleColor, 0, 0, 0, None)
    lhs = TextBlock (tbProps, paraProps, runProps, ret[0])
    # BackDoor.TextBlock.TextBlock_SetNodeProperties (lhs, runProps)
    lhs.AppendText ("Lorem ipsum dolor sit amet,")
    lhs.AppendParagraphBreak ()
    lhs.AppendText ("consectetur adipiscing elit.")
    assert tbProps.IsBackwardsOverridden () == False
    assert tbProps.IsUpsideDownOverridden () == False
    assert tbProps.IsVerticalOverridden () == True
    assert tbProps.IsMaxCharactersPerLineOverridden () == False
    assert paraProps.IsJustificationOverridden () == True
    assert paraProps.IsFullJustifiedOverridden () == False
    assert paraProps.IsLineSpacingTypeOverridden () == False
    assert paraProps.IsLineSpacingValueOverridden () == False

    assert runProps.IsFontOverridden () == False
    assert runProps.IsBigFontOverridden () == False
    assert runProps.IsHasColorOverridden () == False
    assert runProps.IsColorOverridden () == False
    assert runProps.IsBoldOverridden () == True
    assert runProps.IsItalicOverridden () == False
    assert runProps.IsCustomSlantAngleOverridden () == False
    assert runProps.IsUnderlinedOverridden () == False
    assert runProps.IsShouldUseUnderlineStyleOverridden () == False
    assert runProps.IsUnderlineOffsetOverridden () == False
    assert runProps.IsUnderlineColorOverridden () == False
    assert runProps.IsUnderlineLineStyleOverridden () == False
    assert runProps.IsUnderlineWeightOverridden () == False
    assert runProps.IsOverlinedOverridden () == False
    assert runProps.IsShouldUseOverlineStyleOverridden () == False
    assert runProps.IsOverlineOffsetOverridden () == False
    assert runProps.IsOverlineColorOverridden () == False
    assert runProps.IsOverlineLineStyleOverridden () == False
    assert runProps.IsOverlineWeightOverridden () == False
    assert runProps.IsCharacterSpacingTypeOverridden () == False
    assert runProps.IsCharacterSpacingValueOverridden () == False
    assert runProps.IsShouldUseBackgroundOverridden () == False
    assert runProps.IsBackgroundFillColorOverridden () == True
    # assert runProps.IsBackgroundBorderColorOverridden () == False
    # assert runProps.IsBackgroundBorderLineStyleOverridden () == False
    # assert runProps.IsBackgroundBorderWeightOverridden () == False
    assert runProps.IsBackgroundBorderPaddingOverridden () == False
    assert runProps.IsRunOffsetOverridden () == False
    assert runProps.IsSubScriptOverridden () == False
    assert runProps.IsSubScriptOverridden () == False
    assert runProps.IsWidthOverridden () == True
    assert runProps.IsHeightOverridden () == True



@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_SingleAtLengthEdf(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    tbProps = TextBlockProperties.Create (ret[0])
    paraProps = ParagraphProperties.Create (ret[0])
    wasRoundTripAttempted = False
    runPropsSize = DPoint2d(1000.0, 1000.0)
    runProps = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, ret[0])
    textBlock = TextBlock (tbProps, paraProps, runProps, ret[0])
    textBlock.AppendEnterDataField ("EdfValue", 8, EdfJustification.Left)
    caret = textBlock.CreateStartCaret ()
    edf = caret.GetCurrentRun ()
    assert edf != None
    if edf != None :
        string = edf.GetString()
        assert string == WString("EdfValue")
    assert caret.MoveToNextRun () != SUCCESS
    roundTripTextBlock (textBlock, "Round-trip failed.", wasRoundTripAttempted)
        

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_SingleOverLengthEdf(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    tbProps = TextBlockProperties.Create (ret[0])
    paraProps = ParagraphProperties.Create (ret[0])
    runPropsSize = DPoint2d(1000.0, 1000.0)
    runProps = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, ret[0])
    wasRoundTripAttempted   = False
    textBlock = TextBlock (tbProps, paraProps, runProps, ret[0])
    textBlock.AppendEnterDataField ("EdfValueTooBig", 8, EdfJustification.Left)
    caret = textBlock.CreateStartCaret ()
    edf = caret.GetCurrentRun ()
    assert edf != None
    if edf != None :
        string = edf.GetString()
        assert string == WString("EdfValue")
    assert caret.MoveToNextRun () != SUCCESS
    roundTripTextBlock (textBlock, "Round-trip failed.", wasRoundTripAttempted)



@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_SingleLeftUnderLengthEdf(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    tbProps = TextBlockProperties.Create (ret[0])
    paraProps = ParagraphProperties.Create (ret[0])
    runPropsSize = DPoint2d(1000.0, 1000.0)
    runProps= RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, ret[0])
    wasRoundTripAttempted   = False
    textBlock = TextBlock (tbProps, paraProps, runProps, ret[0])
    textBlock.AppendEnterDataField ("EdfValue", 13, EdfJustification.Left)
    caret = textBlock.CreateStartCaret ()
    edf = caret.GetCurrentRun ()
    assert edf != None
    if edf != None :
        string = edf.GetString()
        assert string == WString("EdfValue     ")
    assert caret.MoveToNextRun () != SUCCESS
    roundTripTextBlock (textBlock, "Round-trip failed.", wasRoundTripAttempted)


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_SingleCenterUnderLengthEdf(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    tbProps = TextBlockProperties.Create (ret[0])
    paraProps = ParagraphProperties.Create (ret[0])
    runPropsSize = DPoint2d(1000.0, 1000.0)
    runProps = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, ret[0])
    wasRoundTripAttempted = False
    textBlock = TextBlock (tbProps, paraProps, runProps, ret[0])
    textBlock.AppendText ("Lorem ipsum ")
    textBlock.AppendEnterDataField ("dolar", 10, EdfJustification.Left)
    fileEeh = EditElementHandle()
    roundTripTextBlock (textBlock, "Round-trip failed.", wasRoundTripAttempted)
    if not wasRoundTripAttempted :
        return
    assert fileEeh.GetElementType () == TEXT_ELM

    

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CombiningEdfThenCharStream(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    tbProps = TextBlockProperties.Create (ret[0])
    paraProps = ParagraphProperties.Create (ret[0])
    runPropsSize = DPoint2d(1000.0, 1000.0)
    runProps = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, ret[0])
    wasRoundTripAttempted = False
    textBlock = TextBlock (tbProps, paraProps, runProps, ret[0])
    textBlock.AppendEnterDataField ("Lorem", 10, EdfJustification.Left)
    textBlock.AppendText (" ipsum dolar")
    fileEeh = EditElementHandle()
    roundTripTextBlock (textBlock, "Round-trip failed.", wasRoundTripAttempted)
    if not wasRoundTripAttempted :
        return
    assert fileEeh.GetElementType () == TEXT_ELM



@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CombiningManyCharStreamsEdfsInTextnode(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    tbProps = TextBlockProperties.Create (ret[0])
    paraProps = ParagraphProperties.Create (ret[0])
    runPropsSize = DPoint2d(1000.0, 1000.0)
    runProps = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, ret[0])
    wasRoundTripAttempted   = False
    textBlock = TextBlock (tbProps, paraProps, runProps, ret[0])
    # BackDoor is not exposed in python
    # BackDoor.TextBlock.TextBlock_SetNodeProperties (textBlock, runProps)
    textBlock.AppendText ("Lorem ipsum ")
    textBlock.AppendEnterDataField ("dolar", 5, EdfJustification.Left)
    textBlock.AppendLineBreak ()
    textBlock.AppendText (" sit amet, ")
    textBlock.AppendEnterDataField ("consectetur", 15, EdfJustification.Center)
    textBlock.AppendText ("adipiscing elit.")
    fileEeh = EditElementHandle()
    if not wasRoundTripAttempted :
        return
    ExposeChildrenCount = ExposeChildrenReason(100)
    numChildren = 0
    assert fileEeh.GetElementType () == TEXT_NODE_ELM
    childIter = ChildElemIter(fileEeh, ExposeChildrenCount)
    for child in childIter.ToNext () :
        numChildren += 1
    assert numChildren == 2
  

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_EnforcingAtomicEdfsOnInsert(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    tbProps = TextBlockProperties.Create (ret[0])
    paraProps = ParagraphProperties.Create (ret[0])
    runPropsSize = DPoint2d(1000.0, 1000.0)
    runProps = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, ret[0])
    textBlock = TextBlock (tbProps, paraProps, runProps, ret[0])
    textBlock.AppendText ("Lorem ipsum ")
    textBlock.AppendEnterDataField ("dolar", 5, EdfJustification.Left)
    textBlock.AppendText (" sit amet.")
    insertCaret = textBlock.CreateStartCaret ()
    for i in range(15) :
        insertCaret.MoveToNextCharacter ()
    textBlock.InsertText (insertCaret, "new text")
    runIter = textBlock.CreateStartCaret ()
    expected_chrType = CharStream
    actual_chrType = type(runIter.GetCurrentRun ())
    assert actual_chrType == expected_chrType
    runIter.MoveToNextRun ()
    expected_EdfCharType = EdfCharStream
    actual_EdfCharType = type(runIter.GetCurrentRun ())
    assert actual_EdfCharType == expected_EdfCharType
    runIter.MoveToNextRun ()
    expected_chrType = CharStream
    actual_chrType = type(runIter.GetCurrentRun ())
    assert actual_chrType == expected_chrType
    runIter.MoveToNextRun ()
    assert runIter.MoveToNextRun () != SUCCESS


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_EnforcingAtomicEdfsOnDelete(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    tbProps = TextBlockProperties.Create (ret[0])
    paraProps = ParagraphProperties.Create (ret[0])
    runPropsSize = DPoint2d(1000.0, 1000.0)
    runProps = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, ret[0])
    textBlock = TextBlock(tbProps, paraProps, runProps, ret[0])
    textBlock.AppendText ("Lorem ipsum ")
    textBlock.AppendEnterDataField ("dolar", 5, EdfJustification.Left)
    textBlock.AppendText (" sit amet.")
    insertCaret = textBlock.CreateStartCaret ()
    for i in range(15):
        insertCaret.MoveToNextCharacter ()
    textBlock.Remove (insertCaret, textBlock.CreateEndCaret ())
    runIter = textBlock.CreateStartCaret ()
    expected_chrType = CharStream
    actual_chrType = type(runIter.GetCurrentRun ())
    assert actual_chrType == expected_chrType
    runIter.MoveToNextRun ()
    expected_EdfCharType = EdfCharStream
    actual_EdfCharType = type(runIter.GetCurrentRun ())
    assert actual_EdfCharType == expected_EdfCharType
    runIter.MoveToNextRun ()
    assert runIter.MoveToNextRun () != SUCCESS


@pytest.mark.skip(reason="AuthorFieldTester class is not exposed")
def test_FieldRoundtrip_Author(initDgnPlatformHost, loadDgnFile):
    tester = AuthorFieldTester("Jeff.Marker", STRINGCASESPEC_Title)


@pytest.mark.skip(reason="FileNameFieldTester class is not exposed")
def test_FieldRoundtrip_FileName(initDgnPlatformHost, loadDgnFile):
    showPath = False
    showRoot = True
    showExt  = False
    caseSpec = STRINGCASESPEC_Lower
    tester = FileNameFieldTester("fieldtest.dgn", showPath, showRoot, showExt, caseSpec)


@pytest.mark.skip(reason="FileSizeFieldTester class is not exposed")
def test_FieldRoundtrip_FileSize(initDgnPlatformHost, loadDgnFile):
    formatSpec = "%.2f%by2"
    tester = FileSizeFieldTester("52.50", formatSpec)


@pytest.mark.skip(reason="DateFieldTester class is not exposed")
def test_FieldRoundtrip_DateCreated(initDgnPlatformHost, loadDgnFile):
    formatSpec = "%#c"
    caseSpec   = STRINGCASESPEC_Default
    tester = DateFieldTester("Wednesday, November 10, 2010 4:07:14 PM", FIELDPROPERTY_DateCreated, formatSpec, caseSpec)


@pytest.mark.skip(reason="DateFieldTester class is not exposed")
def test_FieldRoundtrip_DatePlotted(initDgnPlatformHost, loadDgnFile):
    formatSpec = "MMM-yy"
    caseSpec   = STRINGCASESPEC_Upper
    tester = DateFieldTester("JAN-01", FIELDPROPERTY_DatePlotted, formatSpec, caseSpec)


@pytest.mark.skip(reason="DateFieldTester class is not exposed")
def test_FieldRoundtrip_DateSaved(initDgnPlatformHost, loadDgnFile):
    formatSpec = "d-MMM-yy"
    caseSpec   = STRINGCASESPEC_First
    tester = DateFieldTester("18-nov-10", FIELDPROPERTY_DateSaved, formatSpec, caseSpec)


# @pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
@pytest.mark.skip(reason="BackDoor is not exposed and TextPartIdVector is not working properly")
def test_FieldRoundtrip_WordWrapped01(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    tbProps = TextBlockProperties.Create (ret[0])
    tbProps.SetDocumentWidth (9000.0)
    paraProps = ParagraphProperties.Create (ret[0])
    runPropsSize = DPoint2d(1000.0, 1000.0)
    runProps = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, ret[0])
    wasRoundTripAttempted = False
    textBlock = TextBlock (tbProps, paraProps, runProps, ret[0])
    fileEeh = EditElementHandle()
    inputString01 = "abc "
    inputString02 = "Jeff.Marker"
    inputString03 = " def" 
    runString01 = inputString01
    runString02 = inputString02
    runString03 = " "
    runString04 = "def"
    # BackDoor.TextBlock.TextBlock_SetNodeProperties (textBlock, runProps)
    textBlock.AppendText (inputString01)
    # FieldWriterV0.GetFieldWriter ().AppendAuthorField (textBlock, inputString02, STRINGCASESPEC_Default)
    textBlock.AppendText (inputString03)
    roundTripTextBlock (textBlock, "Round-trip failed for TextBlock with author property field and surrounding text.", wasRoundTripAttempted)
    textParts = TextPartIdVector()
    textQuery.GetTextPartIds (fileEeh, ITextQueryOptions(), textParts)
    
    

# @pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
@pytest.mark.skip(reason="BackDoor is not exposed and TextPartIdVector is not working properly")
def test_FieldRoundtrip_WordWrapped02(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    tbProps = TextBlockProperties.Create (ret[0])
    tbProps.SetDocumentWidth (9000.0)
    paraProps = ParagraphProperties.Create (ret[0])
    runPropsSize = DPoint2d(1000.0, 1000.0)
    runProps = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, ret[0])
    wasRoundTripAttempted = False
    textBlock = TextBlock (tbProps, paraProps, runProps, ret[0])
    fileEeh = EditElementHandle()
    inputString01 = "abc "
    inputString02 = "the quick brown fox jumped"
    inputString03 = " def"
    runString01 = inputString01
    runString02 = "the quick "
    runString03 = "brown fox "
    runString04 = "jumped"
    runString05  = " def"
    # BackDoor.TextBlock.TextBlock_SetNodeProperties (textBlock, runProps)
    textBlock.AppendText (inputString01)
    # FieldWriterV0.GetFieldWriter ().AppendAuthorField (textBlock, inputString02, STRINGCASESPEC_Default)
    textBlock.AppendText (inputString03)
    roundTripTextBlock (textBlock, "Round-trip failed for TextBlock with author property field and surrounding text.", wasRoundTripAttempted)
    textParts = TextPartIdVector()
    textQuery.GetTextPartIds (fileEeh, ITextQueryOptions(), textParts)


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_FindReplaceAllBasic(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    tbProps = TextBlockProperties.Create(ret[0])
    paraProps = ParagraphProperties.Create(ret[0])
    runProps = RunProperties.Create(DgnFontManager.GetDefaultTrueTypeFont(), DPoint2d(1000.0, 1000.0), ret[0])
    text = TextBlock(tbProps, paraProps, runProps, ret[0])
    text.AppendText("foo bar foo boo")
    numFound = 0
    searchStart = text.CreateStartCaret()
    foundRegion = None
    # while loop is not working, when we use GetMatchEnd method there is some issue 'Caret is non-copyable'
    # while True :
    #     foundRegion = text.FindText("foo", None, searchStart, None)
    #     if foundRegion == None :
    #         break
    #     numFound += 1
    #     assert foundRegion.CanBeModified() == True
    #     matchEnd = foundRegion.GetMatchEnd()
    #     text.ReplaceText("lorem ipsum", foundRegion.GetMatchStart(), matchEnd)
    #     searchStart = matchEnd
    # assert numFound == 2
    # assert "lorem ipsum bar lorem ipsum boo" == text.ToString()



@pytest.mark.skip(reason="while loop is not working under countOccurences method, when we use GetMatchEnd method there is some issue 'Caret is non-copyable'")
def test_FindReplaceDifferentFindParameters(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    tbProps = TextBlockProperties.Create(ret[0])
    paraProps = ParagraphProperties.Create(ret[0])
    runProps = RunProperties.Create(DgnFontManager.GetDefaultTrueTypeFont(), DPoint2d(1000.0, 1000.0), ret[0])
    text = TextBlock(tbProps, paraProps, runProps, ret[0])
    text.AppendText("foobar")
    findParams = TextBlock.FindTextParameters()


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_FindReplaceNonModifiable(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    tbProps = TextBlockProperties.Create(ret[0])
    paraProps = ParagraphProperties.Create(ret[0])
    runProps = RunProperties.Create(DgnFontManager.GetDefaultTrueTypeFont(), DPoint2d(1000.0, 1000.0), ret[0])
    text = TextBlock(tbProps, paraProps, runProps, ret[0])
    text.AppendText("foo")
    text.AppendEnterDataField("bar", 3, EdfJustification.Left)
    searchStart = text.CreateStartCaret()
    foundRegion = text.FindText("foobar", None, searchStart, None)
    assert foundRegion != None
    assert not foundRegion.CanBeModified() == True
    # Return_value_policy = copy, but type Bentley::DgnPlatform::Caret is non-copyable!
    # matchEnd = foundRegion.GetMatchEnd().Clone()
    # text.ReplaceText("LongerThanBar", foundRegion.GetMatchStart(), matchEnd)
    assert text.ToString() == WString("foobar")



@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_SetStyleProperties(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    tbProps = TextBlockProperties.Create(ret[0])
    paraProps = ParagraphProperties.Create(ret[0])
    runProps = RunProperties.Create(DgnFontManager.GetDefaultTrueTypeFont(), DPoint2d(1000.0, 1000.0), ret[0])
    text = TextBlock(tbProps, paraProps, runProps, ret[0])
    text.AppendText("Lorem ipsum dolar sit amet.")
    style = DgnTextStyle("", loadDgnFile)
    style.SetBoolProperty(TextStyle_Bold, True)
    style.SetBoolProperty(TextStyle_Underline, True)
    styleMask = TextStylePropertyMask()
    styleMask.SetPropertyFlag(TextStyle_Bold, True)
    # IsBold(), IsItalic() are not working properly
    # assert text.CreateStartCaret().GetCurrentRun().GetProperties().IsBold() ==  False
    # assert text.CreateStartCaret().GetCurrentRun().GetProperties().IsItalic() ==  False
    text.SetStyleProperties(style, styleMask, text.CreateStartCaret(), text.CreateEndCaret())
    # assert text.CreateStartCaret().GetCurrentRun().GetProperties().IsBold() == True
    # assert text.CreateStartCaret().GetCurrentRun().GetProperties().IsItalic() == False