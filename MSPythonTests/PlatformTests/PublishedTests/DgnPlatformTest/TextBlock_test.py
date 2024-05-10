#--------------------------------------------------------------------------------------+
#     $Source: TextBlock_Test.py $
#  $Copyright: (c) 2015 Bentley Systems, Incorporated. All rights reserved. $
#--------------------------------------------------------------------------------------/
import os
import pytest

from abc import ABC, abstractmethod

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from util import *

dgnFileName = '2dMetricGeneral.dgn'

#=================================================================================#
# @bsiclass                                                     Ping.Chen     04/2024
#===============+===============+===============+===============+===============+======/
class TestTextBlockTestFixture:
    def loadDgnFileByFileName (self, fileName):
        dataDir = os.environ['MSPYTESTDATA']
        ret = DgnDocument.CreateFromFileName (fileName, dataDir, -101, DgnDocument.FetchMode.eWrite)

        if (ret[1] != DgnFileStatus.eDGNFILE_STATUS_Success):
            assert False

        dgnFile = DgnFile (ret[0], DgnFileOpenMode.eReadWrite)
        dgnFile.LoadDgnFile ()
        dgnFile.FillDictionaryModel ()

        return dgnFile

    def loadDgnModel (self):
        self.dgnFile = self.loadDgnFileByFileName (dgnFileName)
        self.model, retVal = self.dgnFile.LoadRootModelById (self.dgnFile.DefaultModelId, True)

    def GetDgnModel (self):
        return self.model

    def GetDgnFile (self):
        return self.dgnFile

    def setup_method (self):
        self.is3d = False
        DgnPlatformFixture_Initialize ()
        self.loadDgnModel ()

    def teardown_method (self):
        #self.dgnFile.ProcessChanges(DgnSaveReason.eFileClose)
        self.dgnFile.Release ()

    #---------------------------------------------------------------------------------#
    # @bsimethod                                                    Ping.Chen     04/2024
    #---------------#---------------#---------------#---------------#---------------#------/
    def test_TextBlock_TextBlockPropertiesCloneAndEqualityTests (self):
        #"2D DGN"
        #"Creates a TextBlockProperties object, clones and mutates it, and ensures it reports equal/non-equal as expected.",

        lhsTbProps  = TextBlockProperties.Create (self.GetDgnModel ())
        rhsTbProps  = TextBlockProperties.Create (self.GetDgnModel ())

        #TODO...
        #ASSERT_TRUE (BackDoor.TextBlock.TextBlockProperties_Equals (lhsTbProps, rhsTbProps)) #<< "Two blank TextBlockProperties should be equal, but report False"

        lhsTbProps.SetIsVertical (True)

        rhsTbProps = lhsTbProps.Clone ()

        #TODO...
        #ASSERT_TRUE (BackDoor.TextBlock.TextBlockProperties_Equals (lhsTbProps, rhsTbProps)) #<< "Mutated and cloned TextBlockProperties should be equal, but report False"

        lhsTbProps = TextBlockProperties.Create (self.GetDgnModel ())

        #TODO...
        #ASSERT_FALSE (BackDoor.TextBlock.TextBlockProperties_Equals (lhsTbProps, rhsTbProps)) #<< "Mutated TextBlockProperties should NOT be equal, but report True"


    #---------------------------------------------------------------------------------#
    # @bsimethod                                                    Ping.Chen     04/2024
    #---------------#---------------#---------------#---------------#---------------#------/
    def test_TextBlock_ParagraphPropertiesCloneAndEqualityTests (self):
        #"2D DGN",
        #"Creates a ParagraphProperties object, clones and mutates it, and ensures it reports equal/non-equal as expected.",

        lhsParaProps    = ParagraphProperties.Create (self.GetDgnModel ())
        rhsParaProps    = ParagraphProperties.Create (self.GetDgnModel ())

        #TODO...
        #ASSERT_TRUE (BackDoor.TextBlock.ParagraphProperties_Equals (lhsParaProps, rhsParaProps)) #<< "Two blank ParagraphProperties should be equal, but report False"

        lhsParaProps.SetLineSpacingValue (500.0)

        rhsParaProps = lhsParaProps.Clone ()

        #TODO...
        #ASSERT_TRUE (BackDoor.TextBlock.ParagraphProperties_Equals (lhsParaProps, rhsParaProps)) #<< "Mutated and cloned ParagraphProperties should be equal, but report False"

        rhsParaProps.SetJustification (TextElementJustification.eCenterMiddle)

        #TODO...
        #ASSERT_FALSE (BackDoor.TextBlock.ParagraphProperties_Equals (lhsParaProps, rhsParaProps)) #<< "Mutated ParagraphProperties should NOT be equal, but report True"


    #---------------------------------------------------------------------------------#
    # @bsimethod                                                    Ping.Chen     04/2024
    #---------------#---------------#---------------#---------------#---------------#------/
    def test_TextBlock_RunPropertiesCloneAndEqualityTests (self):
        #"2D DGN",
        #"Creates a RunProperties object, clones and mutates it, and ensures it reports equal/non-equal as expected.",

        runPropsFont    = DgnFontManager.GetDefaultTrueTypeFont ()
        runPropsSize    = DPoint2d (1000.0, 1000.0)
        lhsRunProps     = RunProperties.Create (runPropsFont, runPropsSize, self.GetDgnModel ())
        rhsRunProps     = RunProperties.Create (runPropsFont, runPropsSize, self.GetDgnModel ())

        #TODO...
        #ASSERT_TRUE (BackDoor.TextBlock.RunProperties_Equals (lhsRunProps, rhsRunProps)) #<< "Two blank RunProperties should be equal, but report False"
                                                                                        
        lhsRunProps.SetIsBold (True)                                                      
                                                                                        
        rhsRunProps = lhsRunProps.Clone ()                                                
                                                                                        
        #TODO...
        #ASSERT_TRUE (BackDoor.TextBlock.RunProperties_Equals (lhsRunProps, rhsRunProps)) #<< "Mutated and cloned RunProperties should be equal, but report False"

        rhsRunProps.SetIsItalic (True)
        #TODO...
        #ASSERT_FALSE (BackDoor.TextBlock.RunProperties_Equals (lhsRunProps, rhsRunProps)) #<< "Mutated RunProperties should NOT be equal, but report True"


    #---------------------------------------------------------------------------------#
    # @bsimethod                                                    Ping.Chen     04/2024
    #---------------#---------------#---------------#---------------#---------------#------/
    def test_TextBlock_TextBlockEqualsPositiveUnitTest (self):
        #"2D DGN",
        #"Mutates a representative set of TextBlock aspects, and ensures that the equality checker returns True.",

        LOREM_IPSUM_1   = "Lorem ipsum"
        LOREM_IPSUM_2   = "dolor sit amet"

        tbProps         = TextBlockProperties.Create (self.GetDgnModel ())
        paraProps       = ParagraphProperties.Create (self.GetDgnModel ())
        runPropsFont    = DgnFontManager.GetDefaultTrueTypeFont ()
        runPropsSize    = DPoint2d (1000.0, 1000.0)
        runProps        = RunProperties.Create (runPropsFont, runPropsSize, self.GetDgnModel ())

        lhs = TextBlock (tbProps, paraProps, runProps, self.GetDgnModel ())
        rhs = TextBlock (tbProps, paraProps, runProps, self.GetDgnModel ())

        #TODO... EXPECT_TRUE (BackDoor.TextBlock.TextBlock_EqualsWithCompareContentAndLocation (lhs, rhs)) #<< "Two empty TextBlocks should be equal, but report False"

        lhs.AppendText (LOREM_IPSUM_1)
        rhs.AppendText (LOREM_IPSUM_1)

        #TODO... EXPECT_TRUE (BackDoor.TextBlock.TextBlock_EqualsWithCompareContentAndLocation (lhs, rhs)) #<< "Adding the same text to two empty TextBlocks should be equal, but report False"

        tbProps.SetIsVertical (True)
        paraProps.SetLineSpacingValue (500.0)
        runProps.SetIsBold (True)

        lhs = TextBlock (tbProps, paraProps, runProps, self.GetDgnModel ())
        lhs.AppendText (LOREM_IPSUM_1)

        rhs = TextBlock (tbProps, paraProps, runProps, self.GetDgnModel ())
        rhs.AppendText (LOREM_IPSUM_1)

        #TODO... EXPECT_TRUE (BackDoor.TextBlock.TextBlock_EqualsWithCompareContentAndLocation (lhs, rhs)) #<< "Adding the same text to two formatted TextBlocks should be equal, but report False"

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

        #TODO... EXPECT_TRUE (BackDoor.TextBlock.TextBlock_EqualsWithCompareContentAndLocation (lhs, rhs)) #<< "Adding a new paragraph to two formatted TextBlocks should be equal, but report False"

        origin = DPoint3d ()
        origin.Init (1.0, 2.0, 3.0)
        lhs.SetUserOrigin (origin)
        rhs.SetUserOrigin (origin)

        #TODO... EXPECT_TRUE (BackDoor.TextBlock.TextBlock_EqualsWithCompareContentAndLocation (lhs, rhs)) #<< "Changing the origin of two TextBlocks should be equal, but report False"


    #---------------------------------------------------------------------------------#
    # @bsimethod                                                    Ping.Chen     04/2024
    #---------------#---------------#---------------#---------------#---------------#------/
    def test_TextBlock_TextBlockEqualsNegativeUnitTest (self):
        #"2D DGN",
        #"Mutates a representative set of TextBlock aspects, and ensures that the equality checker returns False.",

        LOREM_IPSUM_1   = "Lorem ipsum"
        LOREM_IPSUM_2   = "dolor sit amet"

        tbProps         = TextBlockProperties.Create (self.GetDgnModel ())
        paraProps       = ParagraphProperties.Create (self.GetDgnModel ())
        runPropsFont    = DgnFontManager.GetDefaultTrueTypeFont ()
        runPropsSize    = DPoint2d (1000.0, 1000.0)
        runProps        = RunProperties.Create (runPropsFont, runPropsSize, self.GetDgnModel ())

        lhs = TextBlock (tbProps, paraProps, runProps, self.GetDgnModel ())
        lhs.AppendText (LOREM_IPSUM_1)

        tbPropsMutated = tbProps.Clone ()
        tbPropsMutated.SetIsVertical (True)

        rhs = TextBlock (tbPropsMutated, paraProps, runProps, self.GetDgnModel ())
        rhs.AppendText (LOREM_IPSUM_1)

        #TODO... EXPECT_FALSE (BackDoor.TextBlock.TextBlock_EqualsWithCompareContentAndLocation (lhs, rhs)) #<< "Two TextBlock with same text but different TextBlockProperties should be NOT equal, but report True"

        lhs = TextBlock (tbProps, paraProps, runProps, self.GetDgnModel ())
        lhs.AppendText (LOREM_IPSUM_1)

        rhs = TextBlock (tbProps, paraProps, runProps, self.GetDgnModel ())
        rhs.AppendText (LOREM_IPSUM_1)
        rhs.AppendText (LOREM_IPSUM_2)

        #TODO... (BackDoor.TextBlock.TextBlock_EqualsWithCompareContentAndLocation (lhs, rhs)) #<< "Two TextBlock with different text but same properties should be NOT equal, but report True"


    #---------------------------------------------------------------------------------#
    # @bsimethod                                                    Ping.Chen     04/2024
    #---------------#---------------#---------------#---------------#---------------#------/
    def test_TextBlock_CombineRunsUnitTest (self):
        #"2D DGN",
        #"Creates multiple TextBlock objects that should be equivalent, even though they were created differently, and ensures that they are considered equal.",
        #"Ensures that formatted runs are combined as appropriate (e.g. with like-formatting).")

        LOREM_IPSUM_1AB = "Lorem ipsum dolor sit amet"
        LOREM_IPSUM_1A  = "Lorem ipsum "
        LOREM_IPSUM_1B  = "dolor sit amet"

        tbProps         = TextBlockProperties.Create (self.GetDgnModel ())
        paraProps       = ParagraphProperties.Create (self.GetDgnModel ())
        runPropsFont    = DgnFontManager.GetDefaultTrueTypeFont ()
        runPropsSize    = DPoint2d (1000.0, 1000.0)
        runProps        = RunProperties.Create (runPropsFont, runPropsSize, self.GetDgnModel ())

        lhs = TextBlock (tbProps, paraProps, runProps, self.GetDgnModel ())
        lhs.AppendText (LOREM_IPSUM_1AB)

        rhs = TextBlock (tbProps, paraProps, runProps, self.GetDgnModel ())
        rhs.AppendText (LOREM_IPSUM_1A)
        rhs.AppendText (LOREM_IPSUM_1B)

        #TODO... EXPECT_TRUE (BackDoor.TextBlock.TextBlock_EqualsWithCompareContentAndLocation (lhs, rhs)) #<< "Like-formatted runs should have been combined, but TextBlocks report NOT equal"
    
        lhs = TextBlock (tbProps, paraProps, runProps, self.GetDgnModel ())
        lhs.AppendText (LOREM_IPSUM_1AB)

        rhs = TextBlock (tbProps, paraProps, runProps, self.GetDgnModel ())
        rhs.AppendText (LOREM_IPSUM_1A)
    
        runProps.SetIsBold (True)
        rhs.SetRunPropertiesForAdd (runProps)
    
        rhs.AppendText (LOREM_IPSUM_1B)

        #TODO... EXPECT_FALSE (BackDoor.TextBlock.TextBlock_EqualsWithCompareContentAndLocation (lhs, rhs)) #<< "Unlike-formatted runs should NOT have been combined, but TextBlocks report equal"


    #---------------------------------------------------------------------------------#
    # @bsimethod                                                    Ping.Chen     04/2024
    #---------------#---------------#---------------#---------------#---------------#------/
    def roundTripTextBlock1 (original, assertMessage, attempted, fileEeh):
        attempted = False

        toElemResult = TextHandlerBase.CreateElement (fileEeh, None, original)
        ASSERT_EQ (eTEXTBLOCK_TO_ELEMENT_RESULT_Success, toElemResult) #<< "Could not generate text element(s)."

        textQuery = fileEeh.GetITextQuery ()
        ASSERT_TRUE (None != textQuery) #<< "Generated element does not support ITextQuery."
        ASSERT_TRUE (textQuery.IsTextElement (fileEeh)) #<< "Generated element does not think it's a text element."

        textParts = TextPartIdVector ()
        textQuery.GetTextPartIds (fileEeh, ITextQueryOptions (), textParts)
        ASSERT_EQ (1, textParts.__len__ ()) #<< "Generated element does not have one piece of text."

        roundTripped = textQuery.GetTextPart (fileEeh, textParts[0])
        ASSERT_TRUE (roundTripped != None) #<< "Generated element could create a TextBlock for its single text part."

        attempted = True

        #TODO... EXPECT_TRUE (BackDoor.TextBlock.TextBlock_EqualsWithCompareContentAndLocation (original, roundTripped)) #<< (assertMessage ? assertMessage : "TextBlock round-trip failed.")


    #---------------------------------------------------------------------------------#
    # @bsimethod                                                    Ping.Chen     04/2024
    #---------------#---------------#---------------#---------------#---------------#------/
    def roundTripTextBlock (original, assertMessage, attempted):
        fileEeh = EditElementHandle ()
        TestTextBlockTestFixture.roundTripTextBlock1 (original, assertMessage, attempted, fileEeh)


    #---------------------------------------------------------------------------------#
    # @bsimethod                                                    Ping.Chen     04/2024
    #---------------#---------------#---------------#---------------#---------------#------/
    def roundTripSingleLineSingleFormat (tbProps, paraProps, runProps, dgnModel, message, roundTripAttempted):
        lhs = TextBlock (tbProps, paraProps, runProps, dgnModel)
        lhs.AppendText ("Lorem ipsum dolor sit amet.")
        TestTextBlockTestFixture.roundTripTextBlock (lhs, message, roundTripAttempted)


    #---------------------------------------------------------------------------------#
    # @bsimethod                                                    Ping.Chen     04/2024
    #---------------#---------------#---------------#---------------#---------------#------/
    def roundTripMultiLineSingleFormat (tbProps, paraProps, runProps, dgnModel, message, roundTripAttempted):
        # While node properties are not strictly required at run-time, and their absence will still produce valid TextBlocks,
        #  when read back in they will be present, thus we will set them here to make equality checking easier.

        lhs = TextBlock (tbProps, paraProps, runProps, dgnModel)
        #TODO: BackDoor.TextBlock.TextBlock_SetNodeProperties (lhs, runProps)
    
        lhs.AppendText ("Lorem ipsum dolor sit amet,")
        lhs.AppendLineBreak ()
        lhs.AppendText ("consectetur adipiscing elit.")
        lhs.AppendParagraphBreak ()
        lhs.AppendText ("Vestibulum ante quam, tincidunt sed")
        lhs.AppendLineBreak ()
        lhs.AppendText ("elementum a, malesuada aliquet massa.")
        lhs.AppendLineBreak ()
        lhs.AppendText ("Vivamus quis leo nisi.")
    
        TestTextBlockTestFixture.roundTripTextBlock (lhs, message, roundTripAttempted)


    def DO_ROUNDTRIP (roundTripFunc, tbProps, paraProps, runProps, dgnModel, ASSERT_MESSAGE, roundTripAttempted):
        roundTripFunc (tbProps, paraProps, runProps, dgnModel, ASSERT_MESSAGE, roundTripAttempted)
        if (False == roundTripAttempted):
            return

    #---------------------------------------------------------------------------------#
    # @bsimethod                                                    Ping.Chen     04/2024
    #---------------#---------------#---------------#---------------#---------------#------/
    def roundTripSingleFormat (dgnModel, roundTripFunc):
        tbProps             = TextBlockProperties.Create (dgnModel)
        paraProps           = ParagraphProperties.Create (dgnModel)
        runPropsSize        = DPoint2d (1000.0, 1000.0)
        runProps            = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, dgnModel)
        roundTripAttempted  = False

        #...............................................................................................................................................

        # No formatting
        ASSERT_MESSAGE = "Round-trip failed for no formatting"
        TestTextBlockTestFixture.DO_ROUNDTRIP (roundTripFunc, tbProps, paraProps, runProps, dgnModel, ASSERT_MESSAGE, roundTripAttempted)

        #...............................................................................................................................................
    
        # Note that only RunProperties can dictate text style ID.
        #  Do not set text style ID on just TextBlockProperties or ParagraphProperties and expect it to round-trip.
    
        # Purposefully ignoring these text node-only properties: SetMaxCharactersPerLine, SetDocumentWidth
        tbProps = TextBlockProperties.Create (dgnModel)
        tbProps.SetIsBackwards (True)

        ASSERT_MESSAGE = "Round-trip failed for TextBlockProperties.SetIsBackwards"
        TestTextBlockTestFixture.DO_ROUNDTRIP (roundTripFunc, tbProps, paraProps, runProps, dgnModel, ASSERT_MESSAGE, roundTripAttempted)

        tbProps = TextBlockProperties.Create (dgnModel)
        tbProps.SetIsUpsideDown (True)

        ASSERT_MESSAGE = "Round-trip failed for TextBlockProperties.SetIsUpsideDown"
        TestTextBlockTestFixture.DO_ROUNDTRIP (roundTripFunc, tbProps, paraProps, runProps, dgnModel, ASSERT_MESSAGE, roundTripAttempted)

        tbProps = TextBlockProperties.Create (dgnModel)
        tbProps.SetIsViewIndependent (True)

        ASSERT_MESSAGE = "Round-trip failed for TextBlockProperties.SetIsViewIndependent"
        TestTextBlockTestFixture.DO_ROUNDTRIP (roundTripFunc, tbProps, paraProps, runProps, dgnModel, ASSERT_MESSAGE, roundTripAttempted)

        tbProps = TextBlockProperties.Create (dgnModel)
        tbProps.SetIsVertical (True)

        ASSERT_MESSAGE = "Round-trip failed for TextBlockProperties.SetIsVertical"
        TestTextBlockTestFixture.DO_ROUNDTRIP (roundTripFunc, tbProps, paraProps, runProps, dgnModel, ASSERT_MESSAGE, roundTripAttempted)

        tbProps = TextBlockProperties.Create (dgnModel)

        #...............................................................................................................................................

        indentation = IndentationData ()
        indentation.SetFirstLineIndent (1000.0)
        indentation.SetHangingIndent (4000.0)
    
        tabStops = DoubleArray ()
        tabStops.append (2000.0)
        tabStops.append (4000.0)
        tabStops.append (6000.0)
    
        indentation.SetTabStops (tabStops)
    
        # Justification is tricky... since TextBlock has to round-trip text nodes, technically there is a "node justification", as well as justification
        #  for each individual paragraph. Setting paragraph properties to a justification is all you really want, but simply doing that leaves the
        #  node justification unset. If we persist to a text element (which we will here), we loose the ability to have a unique node justification when
        #  read back in, it will be assumed to be the first paragraph's justification (for lack of anything better). Thus, unless you manually set node
        #  justification on the source, the equals check will fail when round-tripped. I do not want to put a special case in equality checking for this.
    
        # It should also be noted that some RunProperties are inter-related, and thus cannot be tested in isolation
        #  (e.g. you need to enable italics for custom slant angle to be round-tripped).
    
        # Purposefully ignoring these text node-only properties: SetIsFullJustified, SetLineSpacingType, SetLineSpacingValue
        #TODO... BackDoor.TextBlock.TextBlockProperties_SetNodeJustification (tbProps, TextElementJustification.eCenterMiddle)
        paraProps = ParagraphProperties.Create (dgnModel)
        paraProps.SetJustification (TextElementJustification.eCenterMiddle)
        ASSERT_MESSAGE = "Round-trip failed for ParagraphProperties.SetJustification"
        TestTextBlockTestFixture.DO_ROUNDTRIP (roundTripFunc, tbProps, paraProps, runProps, dgnModel, ASSERT_MESSAGE, roundTripAttempted)

        tbProps = TextBlockProperties.Create (dgnModel)
    
        paraProps = ParagraphProperties.Create (dgnModel)
        paraProps.SetIndentation (indentation)
        ASSERT_MESSAGE = "Round-trip failed for ParagraphProperties.SetIndentation"
        TestTextBlockTestFixture.DO_ROUNDTRIP (roundTripFunc, tbProps, paraProps, runProps, dgnModel, ASSERT_MESSAGE, roundTripAttempted)

        paraProps = ParagraphProperties.Create (dgnModel)

        #...............................................................................................................................................

        sampleColor         = 5
        sampleLineStyle     = 2
        sampleLineWeight    = 3
        sampleDPoint2d      = DPoint2d (123.0, 456.0)

        # Purposefully ignoring SetShouldIgnoreLSB because that requires an MText document type, which cannot be directly created.
        runProps = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, dgnModel)
        runProps.SetColor (2)
        ASSERT_MESSAGE = "Round-trip failed for RunProperties.SetColor"
        TestTextBlockTestFixture.DO_ROUNDTRIP (roundTripFunc, tbProps, paraProps, runProps, dgnModel, ASSERT_MESSAGE, roundTripAttempted)

        runProps = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, dgnModel)
        runProps.SetIsBold (True)
        ASSERT_MESSAGE = "Round-trip failed for RunProperties.SetIsBold"
        TestTextBlockTestFixture.DO_ROUNDTRIP (roundTripFunc, tbProps, paraProps, runProps, dgnModel, ASSERT_MESSAGE, roundTripAttempted)

        runProps = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, dgnModel)
        runProps.SetIsItalic (True)
        ASSERT_MESSAGE = "Round-trip failed for RunProperties.SetIsItalic"
        TestTextBlockTestFixture.DO_ROUNDTRIP (roundTripFunc, tbProps, paraProps, runProps, dgnModel, ASSERT_MESSAGE, roundTripAttempted)

        runProps = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, dgnModel)
        runProps.SetIsItalic (True)
        ASSERT_MESSAGE = "Round-trip failed for RunProperties.SetIsItalic"
        TestTextBlockTestFixture.DO_ROUNDTRIP (roundTripFunc, tbProps, paraProps, runProps, dgnModel, ASSERT_MESSAGE, roundTripAttempted)

        runProps.SetCustomSlantAngle (PI / 6.0)
        ASSERT_MESSAGE = "Round-trip failed for RunProperties.SetCustomSlantAngle"
        TestTextBlockTestFixture.DO_ROUNDTRIP (roundTripFunc, tbProps, paraProps, runProps, dgnModel, ASSERT_MESSAGE, roundTripAttempted)

        runProps = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, dgnModel)
        runProps.SetIsUnderlined (True)
        ASSERT_MESSAGE = "Round-trip failed for RunProperties.SetIsUnderlined"
        TestTextBlockTestFixture.DO_ROUNDTRIP (roundTripFunc, tbProps, paraProps, runProps, dgnModel, ASSERT_MESSAGE, roundTripAttempted)

        runProps.SetUnderlineOffset (100.0)
        ASSERT_MESSAGE = "Round-trip failed for RunProperties.SetUnderlineOffset"
        TestTextBlockTestFixture.DO_ROUNDTRIP (roundTripFunc, tbProps, paraProps, runProps, dgnModel, ASSERT_MESSAGE, roundTripAttempted)

        runProps.SetShouldUseUnderlineStyle (True)
        ASSERT_MESSAGE = "Round-trip failed for RunProperties.SetShouldUseUnderlineStyle"
        TestTextBlockTestFixture.DO_ROUNDTRIP (roundTripFunc, tbProps, paraProps, runProps, dgnModel, ASSERT_MESSAGE, roundTripAttempted)

        runProps.SetUnderlineStyle (sampleColor, sampleLineStyle, sampleLineWeight)
        ASSERT_MESSAGE = "Round-trip failed for RunProperties.SetUnderlineStyle"
        TestTextBlockTestFixture.DO_ROUNDTRIP (roundTripFunc, tbProps, paraProps, runProps, dgnModel, ASSERT_MESSAGE, roundTripAttempted)

        runProps = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, dgnModel)
        runProps.SetIsOverlined (True)
        ASSERT_MESSAGE = "Round-trip failed for RunProperties.SetIsOverlined"
        TestTextBlockTestFixture.DO_ROUNDTRIP (roundTripFunc, tbProps, paraProps, runProps, dgnModel, ASSERT_MESSAGE, roundTripAttempted)

        runProps.SetOverlineOffset (100.0)
        ASSERT_MESSAGE = "Round-trip failed for RunProperties.SetOverlineOffset"
        TestTextBlockTestFixture.DO_ROUNDTRIP (roundTripFunc, tbProps, paraProps, runProps, dgnModel, ASSERT_MESSAGE, roundTripAttempted)

        runProps.SetShouldUseOverlineStyle (True)
        ASSERT_MESSAGE = "Round-trip failed for RunProperties.SetShouldUseOverlineStyle"
        TestTextBlockTestFixture.DO_ROUNDTRIP (roundTripFunc, tbProps, paraProps, runProps, dgnModel, ASSERT_MESSAGE, roundTripAttempted)

        runProps.SetOverlineStyle (sampleColor, sampleLineStyle,sampleLineWeight)
        ASSERT_MESSAGE = "Round-trip failed for RunProperties.SetOverlineStyle"
        TestTextBlockTestFixture.DO_ROUNDTRIP (roundTripFunc, tbProps, paraProps, runProps, dgnModel, ASSERT_MESSAGE, roundTripAttempted)

        runProps = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, dgnModel)
        runProps.SetCharacterSpacingType (CharacterSpacingType.eFixedWidth)

        ASSERT_MESSAGE = "Round-trip failed for RunProperties.SetCharacterSpacingType"
        TestTextBlockTestFixture.DO_ROUNDTRIP (roundTripFunc, tbProps, paraProps, runProps, dgnModel, ASSERT_MESSAGE, roundTripAttempted)

        runProps = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, dgnModel)
        runProps.SetCharacterSpacingValue (200.0)

        ASSERT_MESSAGE = "Round-trip failed for RunProperties.SetCharacterSpacingValue"
        TestTextBlockTestFixture.DO_ROUNDTRIP (roundTripFunc, tbProps, paraProps, runProps, dgnModel, ASSERT_MESSAGE, roundTripAttempted)

        runProps = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, dgnModel)
        runProps.SetShouldUseBackground (True)

        ASSERT_MESSAGE = "Round-trip failed for RunProperties.SetShouldUseBackground"
        TestTextBlockTestFixture.DO_ROUNDTRIP (roundTripFunc, tbProps, paraProps, runProps, dgnModel, ASSERT_MESSAGE, roundTripAttempted)

        runProps.SetBackgroundStyle (sampleColor,sampleColor,sampleLineStyle,sampleLineWeight,sampleDPoint2d)
        ASSERT_MESSAGE = "Round-trip failed for RunProperties.SetBackgroundStyle"
        TestTextBlockTestFixture.DO_ROUNDTRIP (roundTripFunc, tbProps, paraProps, runProps, dgnModel, ASSERT_MESSAGE, roundTripAttempted)

        runProps = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, dgnModel)
        runProps.SetRunOffset (sampleDPoint2d)

        ASSERT_MESSAGE = "Round-trip failed for RunProperties.SetRunOffset"
        TestTextBlockTestFixture.DO_ROUNDTRIP (roundTripFunc, tbProps, paraProps, runProps, dgnModel, ASSERT_MESSAGE, roundTripAttempted)

        runProps = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, dgnModel)
        runProps.SetIsSubScript (True)

        ASSERT_MESSAGE = "Round-trip failed for RunProperties.SetIsSubScript"
        TestTextBlockTestFixture.DO_ROUNDTRIP (roundTripFunc, tbProps, paraProps, runProps, dgnModel, ASSERT_MESSAGE, roundTripAttempted)

        runProps = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, dgnModel)
        runProps.SetIsSuperScript (True)

        ASSERT_MESSAGE = "Round-trip failed for RunProperties.SetIsSuperScript"
        TestTextBlockTestFixture.DO_ROUNDTRIP (roundTripFunc, tbProps, paraProps, runProps, dgnModel, ASSERT_MESSAGE, roundTripAttempted)

        #...............................................................................................................................................

        # Just get a sampling of text style properties.
        textStyle = DgnTextStyle ("GeneratedStyleForRoundTripSingleFormat", dgnModel.GetDgnFile ())
        textStyle.SetBoolProperty (eTextStyle_Vertical,         True)                            # Resides on TextBlockProperties
        textStyle.SetUInt32Property (eTextStyle_Justification,    TextElementJustification.eCenterMiddle)   # Resides on ParagraphProperties
        textStyle.SetDoubleProperty (eTextStyle_Width,            1000.0)                        # Resides on RunProperties
        textStyle.SetDoubleProperty (eTextStyle_Height,           1000.0)                        # Resides on RunProperties
        textStyle.SetBoolProperty (eTextStyle_ColorFlag,        True)                            # Resides on RunProperties
        textStyle.SetUInt32Property (eTextStyle_Color,            6)                             # Resides on RunProperties
    
        textStyle.Add()
    
        tbProps     = TextBlockProperties.Create (textStyle, dgnModel)
        paraProps   = ParagraphProperties.Create (textStyle, dgnModel)
        runProps    = RunProperties.Create (textStyle, dgnModel)

        ASSERT_MESSAGE = "Round-trip failed for text style formatting"
        TestTextBlockTestFixture.DO_ROUNDTRIP (roundTripFunc, tbProps, paraProps, runProps, dgnModel, ASSERT_MESSAGE, roundTripAttempted)

    #---------------------------------------------------------------------------------#
    # @bsimethod                                                    Ping.Chen     04/2024
    #---------------#---------------#---------------#---------------#---------------#------/
    def test_TextBlock_RoundTripSingleLineSingleFormat (self):
        #"2D DGN",
        #"Creates single-line single-format TextBlocks, generate elements, read them back, and ensures that the TextBlocks are equal.",

        TestTextBlockTestFixture.roundTripSingleFormat (self.GetDgnModel (), TestTextBlockTestFixture.roundTripSingleLineSingleFormat)


    #---------------------------------------------------------------------------------#
    # @bsimethod                                                    Ping.Chen     04/2024
    #---------------#---------------#---------------#---------------#---------------#------/
    def test_TextBlock_RoundTripMultiLineSingleFormat (self):
        #"2D DGN",
        #"Creates multi-line single-format TextBlocks, generate elements, read them back, and ensures that the TextBlocks are equal.",

        TestTextBlockTestFixture.roundTripSingleFormat (self.GetDgnModel (), TestTextBlockTestFixture.roundTripMultiLineSingleFormat)


    #---------------------------------------------------------------------------------#
    # @bsimethod                                                    Ping.Chen     04/2024
    #---------------#---------------#---------------#---------------#---------------#------/
    def test_TextBlock_RoundTripMultiFormat (self):
        #"2D DGN",
        #"Creates multi-format TextBlocks, generate elements, read them back, and ensures that the TextBlocks are equal.",
        #"")

        tbProps             = TextBlockProperties.Create (self.GetDgnModel ())
        paraProps           = ParagraphProperties.Create (self.GetDgnModel ())
        runPropsSize        = DPoint2d (1000.0, 1000.0)
        runProps            = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, self.GetDgnModel ())
        roundTripAttempted  = False
    
        #...............................................................................................................................................
    
        lhs = TextBlock (tbProps, paraProps, runProps, self.GetDgnModel ())
        #TODO: BackDoor.TextBlock.TextBlock_SetNodeProperties (lhs, runProps)
    
        lhs.AppendText ("Lorem ipsum dolor sit amet, ")
    
        runProps.SetIsBold (True)
        runProps.SetColor (6)
        lhs.SetRunPropertiesForAdd (runProps)
    
        lhs.AppendText ("consectetur adipiscing elit.")
    
        TestTextBlockTestFixture.roundTripTextBlock (lhs, "Round-trip failed for single-line multi-format", roundTripAttempted)
        if (False == roundTripAttempted):
            return

        #...............................................................................................................................................
        runProps    = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, self.GetDgnModel ())
        lhs         = TextBlock (tbProps, paraProps, runProps, self.GetDgnModel ())
    
        #TODO: BackDoor.TextBlock.TextBlock_SetNodeProperties (lhs, runProps)
    
        lhs.AppendText ("Lorem ipsum dolor sit amet, ")
    
        runProps.SetIsBold (True)
        runProps.SetColor (6)
        lhs.SetRunPropertiesForAdd (runProps)
    
        lhs.AppendText ("consectetur adipiscing elit.")
        lhs.AppendLineBreak ()
    
        runProps.SetCharacterSpacingType (CharacterSpacingType.eFixedWidth)
        runProps.SetCharacterSpacingValue (100.0)
        lhs.SetRunPropertiesForAdd (runProps)
    
        lhs.AppendText ("Vestibulum ante quam, tincidunt sed elementum a, malesuada aliquet massa.")
        lhs.AppendParagraphBreak ()
    
        lhs.AppendText ("Vivamus quis leo nisi.")
    
        TestTextBlockTestFixture.roundTripTextBlock (lhs, "Round-trip failed for multi-line multi-format", roundTripAttempted)
        if (False == roundTripAttempted):
            return

        #...............................................................................................................................................
        runProps    = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, self.GetDgnModel ())
        lhs         = TextBlock (tbProps, paraProps, runProps, self.GetDgnModel ())
    
        #TODO: BackDoor.TextBlock.TextBlock_SetNodeProperties (lhs, runProps)
    
        lhs.AppendText ("Lorem ipsum dolor sit amet, ")
        lhs.AppendLineBreak ()
        lhs.AppendText ("consectetur adipiscing elit.")
    
        indentation = IndentationData ()
        indentation.SetFirstLineIndent (4000.0)
    
        tabStops = T_DoubleVector ()
        tabStops.append (5000.0)
        tabStops.append (10000.0)
        tabStops.append (15000.0)
    
        indentation.SetTabStops (tabStops)
        
        paraProps.SetIndentation (indentation)
        lhs.SetParagraphPropertiesForAdd (paraProps)
    
        lhs.AppendParagraphBreak ()
        lhs.AppendText ("Vestibulum ante quam, tincidunt sed ")
        lhs.AppendLineBreak ()
        lhs.AppendText ("elementum a,")
        lhs.AppendTab ()
        lhs.AppendText ("malesuada")
        lhs.AppendTab ()
        lhs.AppendText ("aliquet massa.")

        TestTextBlockTestFixture.roundTripTextBlock (lhs, "Round-trip failed for multi-paragraph multi-format", roundTripAttempted)
        if (False == roundTripAttempted):
            return
    
        # Don't forget to reset paraProps and runProps if adding another test.


    #---------------------------------------------------------------------------------#
    # @bsimethod                                                    Ping.Chen     04/2024
    #---------------#---------------#---------------#---------------#---------------#------/
    def test_TextBlock_RoundTripOverrides (self):
        #"2D DGN",
        #"Creates TextBlocks based on text styles, changes the TextBlock's properties, and ensures that overrides are set and persisted.",
        #"")

        sampleColor     = 7
        sampleDPoint2d  = DPoint2d (123.0, 456.0)
    
        textStyle = DgnTextStyle ("GeneratedStyleForRoundTripOverrides", self.GetDgnModel ().GetDgnFile ())
    
        textStyle.SetBoolProperty (eTextStyle_Vertical,             True)
        textStyle.SetUInt32Property (eTextStyle_Justification,        TextElementJustification.eRightTop)
    
        textStyle.SetDoubleProperty (eTextStyle_Width,                1000.0)
        textStyle.SetDoubleProperty (eTextStyle_Height,               1000.0)
        textStyle.SetBoolProperty (eTextStyle_ColorFlag,            True)
        textStyle.SetUInt32Property (eTextStyle_Color,                6)
        textStyle.SetBoolProperty (eTextStyle_Backgroundstyleflag,  True)
        textStyle.SetInt32Property (eTextStyle_Backgroundstyle,      0)
        textStyle.SetUInt32Property (eTextStyle_Backgroundweight,     2)
        textStyle.SetUInt32Property (eTextStyle_Backgroundcolor,      3)
        textStyle.SetUInt32Property (eTextStyle_Backgroundfillcolor,  4)
        textStyle.SetDPoint2dProperty (eTextStyle_Backgroundborder,     sampleDPoint2d)

        textStyle.Add ()

        tbProps             = TextBlockProperties.Create (textStyle, self.GetDgnModel ())
        paraProps           = ParagraphProperties.Create (textStyle, self.GetDgnModel ())
        runProps            = RunProperties.Create (textStyle, self.GetDgnModel ())
        roundTripAttempted  = False

        tbProps.SetIsVertical (False)
        paraProps.SetJustification (TextElementJustification.eLeftTop)
        #TODO: BackDoor.TextBlock.TextBlockProperties_SetNodeJustification (tbProps, TextElementJustification.ieLeftTop)
        runProps.SetFontSize (sampleDPoint2d)
        runProps.SetIsBold (True)
        runProps.SetBackgroundStyle (sampleColor, None, None, None, None)

        lhs = TextBlock (tbProps, paraProps, runProps, self.GetDgnModel ())
        #TODO: BackDoor.TextBlock.TextBlock_SetNodeProperties (lhs, runProps)

        lhs.AppendText ("Lorem ipsum dolor sit amet,")
        lhs.AppendParagraphBreak ()
        lhs.AppendText ("consectetur adipiscing elit.")

        ASSERT_FALSE (tbProps.IsBackwardsOverridden ())
        ASSERT_FALSE (tbProps.IsUpsideDownOverridden ())
        ASSERT_TRUE (tbProps.IsVerticalOverridden ())
        ASSERT_FALSE (tbProps.IsMaxCharactersPerLineOverridden ())
    
        ASSERT_TRUE (paraProps.IsJustificationOverridden ())
        ASSERT_FALSE (paraProps.IsFullJustifiedOverridden ())
        ASSERT_FALSE (paraProps.IsLineSpacingTypeOverridden ())
        ASSERT_FALSE (paraProps.IsLineSpacingValueOverridden ())
    
        ASSERT_FALSE (runProps.IsFontOverridden ())
        ASSERT_FALSE (runProps.IsBigFontOverridden ())
        ASSERT_FALSE (runProps.IsHasColorOverridden ())
        ASSERT_FALSE (runProps.IsColorOverridden ())
        ASSERT_TRUE (runProps.IsBoldOverridden ())
        ASSERT_FALSE (runProps.IsItalicOverridden ())
        ASSERT_FALSE (runProps.IsCustomSlantAngleOverridden ())
        ASSERT_FALSE (runProps.IsUnderlinedOverridden ())
        ASSERT_FALSE (runProps.IsShouldUseUnderlineStyleOverridden ())
        ASSERT_FALSE (runProps.IsUnderlineOffsetOverridden ())
        ASSERT_FALSE (runProps.IsUnderlineColorOverridden ())
        ASSERT_FALSE (runProps.IsUnderlineLineStyleOverridden ())
        ASSERT_FALSE (runProps.IsUnderlineWeightOverridden ())
        ASSERT_FALSE (runProps.IsOverlinedOverridden ())
        ASSERT_FALSE (runProps.IsShouldUseOverlineStyleOverridden ())
        ASSERT_FALSE (runProps.IsOverlineOffsetOverridden ())
        ASSERT_FALSE (runProps.IsOverlineColorOverridden ())
        ASSERT_FALSE (runProps.IsOverlineLineStyleOverridden ())
        ASSERT_FALSE (runProps.IsOverlineWeightOverridden ())
        ASSERT_FALSE (runProps.IsCharacterSpacingTypeOverridden ())
        ASSERT_FALSE (runProps.IsCharacterSpacingValueOverridden ())
        ASSERT_FALSE (runProps.IsShouldUseBackgroundOverridden ())
        ASSERT_TRUE (runProps.IsBackgroundFillColorOverridden ())
        ASSERT_FALSE (runProps.IsBackgroundBorderColorOverridden ())
        ASSERT_FALSE (runProps.IsBackgroundBorderLineStyleOverridden ())
        ASSERT_FALSE (runProps.IsBackgroundBorderWeightOverridden ())
        ASSERT_FALSE (runProps.IsBackgroundBorderPaddingOverridden ())
        ASSERT_FALSE (runProps.IsRunOffsetOverridden ())
        ASSERT_FALSE (runProps.IsSubScriptOverridden ())
        ASSERT_FALSE (runProps.IsSuperScriptOverridden ())
        ASSERT_TRUE (runProps.IsWidthOverridden ())
        ASSERT_TRUE (runProps.IsHeightOverridden ())

        TestTextBlockTestFixture.roundTripTextBlock (lhs, "Round-trip failed for multi-paragraph multi-format", roundTripAttempted)
        if (False == roundTripAttempted):
            return


    #---------------------------------------------------------------------------------------
    # @bsimethod                                                   Ping.Chen     07/2010
    #---------------------------------------------------------------------------------------
    def test_TextBlock_SingleAtLengthEdf (self):
        #"2D DGN",
        #"Creates a TextBlock with a single EDF (at-length), and round-trips.",
        #"")

        tbProps                 = TextBlockProperties.Create (self.GetDgnModel ())
        paraProps               = ParagraphProperties.Create (self.GetDgnModel ())
        runPropsSize            = DPoint2d (1000.0, 1000.0)
        runProps                = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, self.GetDgnModel ())
        wasRoundTripAttempted   = False
        textBlock               = TextBlock (tbProps, paraProps, runProps, self.GetDgnModel ())

        textBlock.AppendEnterDataField ("EdfValue", 8, EdfJustification.eLeft)

        caret = textBlock.CreateStartCaret ()
        edf   = caret.GetCurrentRun ()
    
        EXPECT_NE (None, edf) #<< "The first run is not an EdfCharStream."
    
        if (None != edf):
            EXPECT_EQ (0, edf.GetString ().CompareTo ("EdfValue")) #<< "The value string does not match."

        EXPECT_NE (eSUCCESS, caret.MoveToNextRun ()) #<< "More than one run exists."
    
        TestTextBlockTestFixture.roundTripTextBlock (textBlock, "Round-trip failed.", wasRoundTripAttempted)


    #---------------------------------------------------------------------------------------
    # @bsimethod                                                   Ping.Chen     07/2010
    #---------------------------------------------------------------------------------------
    def test_TextBlock_SingleOverLengthEdf (self):
        #"2D DGN",
        #"Creates a TextBlock with a single EDF (over-length), and round-trips.",
        #"Ensures that the EDF gets truncated correctly because it was over-length.")

        tbProps                 = TextBlockProperties.Create (self.GetDgnModel ())
        paraProps               = ParagraphProperties.Create (self.GetDgnModel ())
        runPropsSize            = DPoint2d (1000.0, 1000.0)
        runProps                = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, self.GetDgnModel ())
        wasRoundTripAttempted   = False
        textBlock               = TextBlock (tbProps, paraProps, runProps, self.GetDgnModel ())
    
        # This will throw an BeDataAssert because the string we are providing exceeds the total length we are providing.
        #BeTest.SetThrowOnAssert (False)

        textBlock.AppendEnterDataField ("EdfValueTooBig", 8, EdfJustification.eLeft)

        #BeTest.SetThrowOnAssert (True)

        caret = textBlock.CreateStartCaret ()
        edf   = caret.GetCurrentRun ()

        EXPECT_NE (None, edf) #<< "The first run is not an EdfCharStream."

        if (None != edf):
            EXPECT_EQ (0, edf.GetString ().CompareTo ("EdfValue")) #<< "The value string was not truncated correctly."

        EXPECT_NE (eSUCCESS, caret.MoveToNextRun ()) #<< "More than one run exists."

        TestTextBlockTestFixture.roundTripTextBlock (textBlock, "Round-trip failed.", wasRoundTripAttempted)


    #---------------------------------------------------------------------------------------
    # @bsimethod                                                   Ping.Chen     07/2010
    #---------------------------------------------------------------------------------------
    def test_TextBlock_SingleLeftUnderLengthEdf (self):
        #"2D DGN",
        #"Creates a TextBlock with a single EDF (under-length), and round-trips.",
        #"Ensures that the EDF gets padded correctly because it was under-length.")

        tbProps                 = TextBlockProperties.Create (self.GetDgnModel ())
        paraProps               = ParagraphProperties.Create (self.GetDgnModel ())
        runPropsSize            = DPoint2d (1000.0, 1000.0)
        runProps                = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, self.GetDgnModel ())
        wasRoundTripAttempted   = False    
        textBlock               = TextBlock (tbProps, paraProps, runProps, self.GetDgnModel ())

        textBlock.AppendEnterDataField ("EdfValue", 13, EdfJustification.eLeft)

        caret = textBlock.CreateStartCaret ()
        edf   = caret.GetCurrentRun ()
    
        EXPECT_NE (None, edf) #<< "The first run is not an EdfCharStream."
    
        if (None != edf):
            EXPECT_EQ (0, edf.GetString ().CompareTo ("EdfValue     ")) #<< "The value string was not padded correctly."

        EXPECT_NE (eSUCCESS, caret.MoveToNextRun ()) #<< "More than one run exists."
    
        TestTextBlockTestFixture.roundTripTextBlock (textBlock, "Round-trip failed.", wasRoundTripAttempted)


    #---------------------------------------------------------------------------------------
    # @bsimethod                                                   Ping.Chen     07/2010
    #---------------------------------------------------------------------------------------
    def test_TextBlock_SingleCenterUnderLengthEdf (self):
        #"2D DGN",
        #"Creates a TextBlock with a single EDF (under-length, center), and round-trips.",
        #"Ensures that the EDF gets padded correctly because it was under-length.")

        tbProps                 = TextBlockProperties.Create (self.GetDgnModel ())
        paraProps               = ParagraphProperties.Create (self.GetDgnModel ())
        runPropsSize            = DPoint2d (1000.0, 1000.0)
        runProps                = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, self.GetDgnModel ())
        wasRoundTripAttempted   = False    
        textBlock               = TextBlock (tbProps, paraProps, runProps, self.GetDgnModel ())

        textBlock.AppendEnterDataField ("EdfValue", 13, EdfJustification.eCenter)

        caret = textBlock.CreateStartCaret ()
        edf   = caret.GetCurrentRun ()
    
        EXPECT_NE (None, edf) #<< "The first run is not an EdfCharStream."
    
        if (None != edf):
            EXPECT_EQ (0, edf.GetString ().CompareTo ("   EdfValue  ")) #<< "The value string was not padded correctly."

        EXPECT_NE (eSUCCESS, caret.MoveToNextRun ()) #<< "More than one run exists."
    
        TestTextBlockTestFixture.roundTripTextBlock (textBlock, "Round-trip failed.", wasRoundTripAttempted)


    #---------------------------------------------------------------------------------------
    # @bsimethod                                                   Ping.Chen     07/2010
    #---------------------------------------------------------------------------------------
    def test_TextBlock_SingleRightUnderLengthEdf (self):
        #"2D DGN",
        #"Creates a TextBlock with a single EDF (under-length, right), and round-trips.",
        #"Ensures that the EDF gets padded correctly because it was under-length.")

        tbProps                 = TextBlockProperties.Create (self.GetDgnModel ())
        paraProps               = ParagraphProperties.Create (self.GetDgnModel ())
        runPropsSize            = DPoint2d (1000.0, 1000.0)
        runProps                = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, self.GetDgnModel ())
        wasRoundTripAttempted   = False    
        textBlock               = TextBlock (tbProps, paraProps, runProps, self.GetDgnModel ())

        textBlock.AppendEnterDataField ("EdfValue", 13, EdfJustification.eRight)

        caret = textBlock.CreateStartCaret ()
        edf   = caret.GetCurrentRun ()
    
        EXPECT_NE (None, edf) #<< "The first run is not an EdfCharStream."
    
        if (None != edf):
            EXPECT_EQ (0, edf.GetString ().CompareTo ("     EdfValue")) #<< "The value string was not padded correctly."

        EXPECT_NE (eSUCCESS, caret.MoveToNextRun ()) #<< "More than one run exists."
    
        TestTextBlockTestFixture.roundTripTextBlock (textBlock, "Round-trip failed.", wasRoundTripAttempted)


    #---------------------------------------------------------------------------------------
    # @bsimethod                                                   Ping.Chen     07/2010
    #---------------------------------------------------------------------------------------
    def test_TextBlock_SingleBlankEdf (self):
        #"2D DGN",
        #"Creates a TextBlock with a single EDF (under-length, blank), and round-trips.",
        #"Ensures that the EDF gets padded correctly because it was under-length.")

        tbProps                 = TextBlockProperties.Create (self.GetDgnModel ())
        paraProps               = ParagraphProperties.Create (self.GetDgnModel ())
        runPropsSize            = DPoint2d (1000.0, 1000.0)
        runProps                = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, self.GetDgnModel ())
        wasRoundTripAttempted   = False    
        textBlock               = TextBlock (tbProps, paraProps, runProps, self.GetDgnModel ())

        textBlock.AppendEnterDataField ("", 10, EdfJustification.eLeft)

        caret = textBlock.CreateStartCaret ()
        edf   = caret.GetCurrentRun ()
    
        EXPECT_NE (None, edf) #<< "The first run is not an EdfCharStream."
    
        if (None != edf):
            EXPECT_EQ (0, edf.GetString ().CompareTo ("          ")) #<< "The value string was not padded correctly."

        EXPECT_NE (eSUCCESS, caret.MoveToNextRun ()) #<< "More than one run exists."
    
        TestTextBlockTestFixture.roundTripTextBlock (textBlock, "Round-trip failed.", wasRoundTripAttempted)

    
    #---------------------------------------------------------------------------------------
    # @bsimethod                                                   Ping.Chen     07/2010
    #---------------------------------------------------------------------------------------
    def test_TextBlock_CombiningCharStreamThenEdf (self):
        #"2D DGN",
        #"Creates a TextBlock with a CharStream and then an EDF (under-length), and round-trips.",
        #"Ensures that a single text element was produced (even though we had two runs).")

        tbProps                 = TextBlockProperties.Create (self.GetDgnModel ())
        paraProps               = ParagraphProperties.Create (self.GetDgnModel ())
        runPropsSize            = DPoint2d (1000.0, 1000.0)
        runProps                = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, self.GetDgnModel ())
        wasRoundTripAttempted   = False
        textBlock               = TextBlock (tbProps, paraProps, runProps, self.GetDgnModel ())

        textBlock.AppendText ("Lorem ipsum ")
        textBlock.AppendEnterDataField ("dolar", 10, EdfJustification.eLeft)
    
        fileEeh = EditElementHandle ()
        TestTextBlockTestFixture.roundTripTextBlock1 (textBlock, "Round-trip failed.", wasRoundTripAttempted, fileEeh)
        if (False == wasRoundTripAttempted):
            return
    
        EXPECT_EQ (TEXT_ELM, fileEeh.GetElementType ()) #<< "Persisted element is a not a single text element."


    #---------------------------------------------------------------------------------------
    # @bsimethod                                                   Ping.Chen     07/2010
    #---------------------------------------------------------------------------------------
    def test_TextBlock_CombiningEdfThenCharStream (self):
        #"2D DGN",
        #"Creates a TextBlock with an EDF (under-length) and then a CharStream, and round-trips.",
        #"Ensures that a single text element was produced (even though we had two runs).")

        tbProps                 = TextBlockProperties.Create (self.GetDgnModel ())
        paraProps               = ParagraphProperties.Create (self.GetDgnModel ())
        runPropsSize            = DPoint2d (1000.0, 1000.0)
        runProps                = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, self.GetDgnModel ())
        wasRoundTripAttempted   = False    
        textBlock               = TextBlock (tbProps, paraProps, runProps, self.GetDgnModel ())

        textBlock.AppendEnterDataField ("Lorem", 10, EdfJustification.eLeft)
        textBlock.AppendText (" ipsum dolar")
    
        fileEeh = EditElementHandle ()
        TestTextBlockTestFixture.roundTripTextBlock1 (textBlock, "Round-trip failed.", wasRoundTripAttempted, fileEeh)
        if (False == wasRoundTripAttempted):
            return
    
        EXPECT_EQ (TEXT_ELM, fileEeh.GetElementType ()) #<< "Persisted element is a not a single text element."


    #---------------------------------------------------------------------------------------
    # @bsimethod                                                   Ping.Chen     07/2010
    #---------------------------------------------------------------------------------------
    def test_TextBlock_CombiningManyCharStreamsEdfs (self):
        #"2D DGN",
        #"Creates a TextBlock with several EDFs (under-length) and CharStreams, and round-trips.",
        #"Ensures that a single text element was produced (even though we had multiple runs).")

        tbProps                 = TextBlockProperties.Create (self.GetDgnModel ())
        paraProps               = ParagraphProperties.Create (self.GetDgnModel ())
        runPropsSize            = DPoint2d (1000.0, 1000.0)
        runProps                = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, self.GetDgnModel ())
        wasRoundTripAttempted   = False    
        textBlock               = TextBlock (tbProps, paraProps, runProps, self.GetDgnModel ())

        textBlock.AppendText ("Lorem ipsum ")
        textBlock.AppendEnterDataField ("dolar", 5, EdfJustification.eLeft)
        textBlock.AppendText (" sit amet, ")
        textBlock.AppendEnterDataField ("consectetur", 15, EdfJustification.eCenter)
        textBlock.AppendText ("adipiscing elit.")

        fileEeh = EditElementHandle ()
        TestTextBlockTestFixture.roundTripTextBlock1 (textBlock, "Round-trip failed.", wasRoundTripAttempted, fileEeh)
        if (False == wasRoundTripAttempted):
            return
    
        EXPECT_EQ (TEXT_ELM, fileEeh.GetElementType ()) #<< "Persisted element is a not a single text element."


    #---------------------------------------------------------------------------------------
    # @bsimethod                                                   Ping.Chen     07/2010
    #---------------------------------------------------------------------------------------
    def test_TextBlock_CombiningManyCharStreamsEdfsInTextnode (self):
        #"2D DGN",
        #"Creates a TextBlock with several EDFs (under-length), CharStreams, and breaks, and then round-trips.",
        #"Ensures that the appropriate number of text element was produced (even though we had multiple runs per line).")

        tbProps                 = TextBlockProperties.Create (self.GetDgnModel ())
        paraProps               = ParagraphProperties.Create (self.GetDgnModel ())
        runPropsSize            = DPoint2d (1000.0, 1000.0)
        runProps                = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, self.GetDgnModel ())
        wasRoundTripAttempted   = False    
        textBlock               = TextBlock (tbProps, paraProps, runProps, self.GetDgnModel ())

        #TODO: BackDoor.TextBlock.TextBlock_SetNodeProperties (textBlock, runProps)

        textBlock.AppendText ("Lorem ipsum ")
        textBlock.AppendEnterDataField ("dolar", 5, EdfJustification.eLeft)
        textBlock.AppendLineBreak ()
        textBlock.AppendText (" sit amet, ")
        textBlock.AppendEnterDataField ("consectetur", 15, EdfJustification.eCenter)
        textBlock.AppendText ("adipiscing elit.")
    
        fileEeh = EditElementHandle ()
        TestTextBlockTestFixture.roundTripTextBlock1 (textBlock, "Round-trip failed.", wasRoundTripAttempted, fileEeh)
        if (False == wasRoundTripAttempted):
            return
    
        ExposeChildrenReason : ExposeChildrenCount = 100
        numChildren             = 0

        EXPECT_EQ (TEXT_NODE_ELM, fileEeh.GetElementType ()) #<< "Persisted element is a not a text node."

        #TODO...
        #for (ChildElemIter childIter (fileEeh, ExposeChildrenCount) childIter != None childIter = childIter.ToNext ()):
        #    ++numChildren
        childIter = ChildElemIter(fileEeh, ExposeChildrenCount)
        for child in childIter.ToNext () :
        	numChildren += 1
    
        EXPECT_EQ (2, numChildren) #<< "Runs were not combined into 2 child elements."


    #---------------------------------------------------------------------------------------
    # @bsimethod                                                   Ping.Chen     07/2010
    #---------------------------------------------------------------------------------------
    def test_TextBlock_EnforcingAtomicEdfsOnInsert (self):
        #"2D DGN",
        #"Ensures the TextBlock API does not allow you to insert text in the middle of an atomic (e.g. EDF) run.",
        #"Even though the API technically allows you to insert anywhere, we must prevent the corruption of atomic runs.")

        tbProps                 = TextBlockProperties.Create (self.GetDgnModel ())
        paraProps               = ParagraphProperties.Create (self.GetDgnModel ())
        runPropsSize            = DPoint2d (1000.0, 1000.0)
        runProps                = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, self.GetDgnModel ())
        textBlock               = TextBlock (tbProps, paraProps, runProps, self.GetDgnModel ())

        textBlock.AppendText ("Lorem ipsum ")
        textBlock.AppendEnterDataField ("dolar", 5, EdfJustification.eLeft)
        textBlock.AppendText (" sit amet.")
    
        insertCaret = textBlock.CreateStartCaret ()
    
        for i in range (0, 15):
            insertCaret.MoveToNextCharacter ()
    
        # This will throw an BeDataAssert because the string we are providing exceeds the total length we are providing.
        #BeTest.SetThrowOnAssert (False)

        textBlock.InsertText (insertCaret, "new text")

        #BeTest.SetThrowOnAssert (True)

        runIter = textBlock.CreateStartCaret ()

        EXPECT_TRUE (CharStream == type (runIter.GetCurrentRun ())) #<< "Unexpected run type."
        runIter.MoveToNextRun ()
    
        EXPECT_TRUE (EdfCharStream == type (runIter.GetCurrentRun ())) #<< "Unexpected run type."
        runIter.MoveToNextRun ()
    
        EXPECT_TRUE (CharStream == type (runIter.GetCurrentRun ())) #<< "Unexpected run type."
        runIter.MoveToNextRun ()

        EXPECT_NE (eSUCCESS, runIter.MoveToNextRun ()) #<< "Too many runs."


    #---------------------------------------------------------------------------------------
    # @bsimethod                                                   Ping.Chen     07/2010
    #---------------------------------------------------------------------------------------
    def test_TextBlock_EnforcingAtomicEdfsOnDelete (self):
        #"2D DGN",
        #"Ensures the TextBlock API does not allow you to delete in the middle of an atomic (e.g. EDF) run.",
        #"Even though the API technically allows you to delete anywhere, we must prevent the corruption of atomic runs."

        tbProps                 = TextBlockProperties.Create (self.GetDgnModel ())
        paraProps               = ParagraphProperties.Create (self.GetDgnModel ())
        runPropsSize            = DPoint2d (1000.0, 1000.0)
        runProps                = RunProperties.Create (DgnFontManager.GetDefaultTrueTypeFont (), runPropsSize, self.GetDgnModel ())
        textBlock               = TextBlock (tbProps, paraProps, runProps, self.GetDgnModel ())

        textBlock.AppendText ("Lorem ipsum ")
        textBlock.AppendEnterDataField ("dolar", 5, EdfJustification.eLeft)
        textBlock.AppendText (" sit amet.")

        insertCaret = textBlock.CreateStartCaret ()

        for i in range (0, 15):
            insertCaret.MoveToNextCharacter ()
    
        # This will throw an BeDataAssert because the string we are providing exceeds the total length we are providing.
        #BeTest.SetThrowOnAssert (False)

        textBlock.Remove (insertCaret, textBlock.CreateEndCaret ())

        #BeTest.SetThrowOnAssert (True)

        runIter = textBlock.CreateStartCaret ()

        EXPECT_TRUE (CharStream == type (runIter.GetCurrentRun ())) #<< "Unexpected run type."
        runIter.MoveToNextRun ()

        EXPECT_TRUE (EdfCharStream == type (runIter.GetCurrentRun ())) #<< "Unexpected run type."
        runIter.MoveToNextRun ()

        EXPECT_NE (eSUCCESS, runIter.MoveToNextRun ()) #<< "Too many runs."

    #---------------------------------------------------------------------------------------
    # @bsimethod                                                   Ping.Chen     04/2024
    #---------------------------------------------------------------------------------------
    def test_TextBlock_FindReplaceAllBasic (self):
        tbProps = TextBlockProperties.Create(self.GetDgnModel())
        paraProps = ParagraphProperties.Create(self.GetDgnModel())
        runProps = RunProperties.Create(DgnFontManager.GetDefaultTrueTypeFont(), DPoint2d (1000.0, 1000.0), self.GetDgnModel())

        text = TextBlock(tbProps, paraProps, runProps, self.GetDgnModel())
        text.AppendText("foo bar foo boo")

        numFound = 0
        searchStart = text.CreateStartCaret()
        foundRegion = text.FindText("foo", None, searchStart, None)
        while foundRegion != None:
            numFound += 1

            EXPECT_TRUE(foundRegion.CanBeModified())

            matchEnd = foundRegion.GetMatchEnd().Clone()
            text.ReplaceText("lorem ipsum", foundRegion.GetMatchStart(), matchEnd)

            searchStart = matchEnd

            foundRegion = text.FindText("foo", None, searchStart, None)

        EXPECT_TRUE(2 == numFound)
        EXPECT_TRUE(0 == WString ("lorem ipsum bar lorem ipsum boo").CompareTo (text.ToString()))


    #---------------------------------------------------------------------------------------
    # @bsimethod                                                   Ping.Chen     04/2024
    #---------------------------------------------------------------------------------------
    def countOccurences (text, searchExpr, findParams):
        numFound = 0
        searchStart = text.CreateStartCaret()
        foundRegion = text.FindText (searchExpr, findParams, searchStart, None)

        while foundRegion != None:
            numFound += 1
            searchStart = foundRegion.GetMatchEnd().Clone()

            foundRegion = text.FindText (searchExpr, findParams, searchStart, None)

        return numFound


    #---------------------------------------------------------------------------------------
    # @bsimethod                                                   Ping.Chen     04/2024
    #---------------------------------------------------------------------------------------
    def test_TextBlock_FindReplaceDifferentFindParameters (self):
        tbProps = TextBlockProperties.Create(self.GetDgnModel())
        paraProps = ParagraphProperties.Create(self.GetDgnModel())
        runProps = RunProperties.Create(DgnFontManager.GetDefaultTrueTypeFont(), DPoint2d (1000.0, 1000.0), self.GetDgnModel())

        text = TextBlock(tbProps, paraProps, runProps, self.GetDgnModel())
        text.AppendText("foobar")

        findParams = TextBlock.FindTextParameters ()

        EXPECT_TRUE(0 == TestTextBlockTestFixture.countOccurences(text, "\\d+", findParams))

        text.AppendText(" 123")

        EXPECT_TRUE(0 == TestTextBlockTestFixture.countOccurences(text, "\\d+", findParams))

        findParams.SetUseRegularExpressions(True)

        EXPECT_TRUE(1 == TestTextBlockTestFixture.countOccurences(text, "\\d+", findParams))


    #---------------------------------------------------------------------------------------
    # @bsimethod                                                   Ping.Chen     04/2024
    #---------------------------------------------------------------------------------------
    def test_TextBlock_FindReplaceNonModifiable (self):
        tbProps = TextBlockProperties.Create(self.GetDgnModel())
        paraProps = ParagraphProperties.Create(self.GetDgnModel())
        runProps = RunProperties.Create(DgnFontManager.GetDefaultTrueTypeFont(), DPoint2d (1000.0, 1000.0), self.GetDgnModel())

        text = TextBlock(tbProps, paraProps, runProps, self.GetDgnModel())
        text.AppendText("foo")
        text.AppendEnterDataField("bar", 3, EdfJustification.eLeft)

        searchStart = text.CreateStartCaret()
        foundRegion = text.FindText("foobar", None, searchStart, None)
        ASSERT_TRUE(None != foundRegion)

        EXPECT_TRUE(False == foundRegion.CanBeModified())

        matchEnd = foundRegion.GetMatchEnd().Clone()
        text.ReplaceText("LongerThanBar", foundRegion.GetMatchStart(), matchEnd)

        EXPECT_TRUE(0 == WString ("foobar").CompareTo (text.ToString()))


    #---------------------------------------------------------------------------------------
    # @bsimethod                                                   Ping.Chen     04/2015
    #---------------------------------------------------------------------------------------
    def test_TextBlock_SetStyleProperties (self):
        tbProps = TextBlockProperties.Create(self.GetDgnModel())
        paraProps = ParagraphProperties.Create(self.GetDgnModel())
        runProps = RunProperties.Create(DgnFontManager.GetDefaultTrueTypeFont(), DPoint2d (1000.0, 1000.0), self.GetDgnModel())

        text = TextBlock(tbProps, paraProps, runProps, self.GetDgnModel())
        text.AppendText("Lorem ipsum dolar sit amet.")

        style = DgnTextStyle ("", self.GetDgnFile())
        style.SetBoolProperty(eTextStyle_Bold, True)
        style.SetBoolProperty(eTextStyle_Underline, True)
        
        styleMask = TextStylePropertyMask ()
        styleMask.SetPropertyFlag(eTextStyle_Bold, True)

        EXPECT_TRUE(False == text.CreateStartCaret().GetCurrentRun().GetProperties().IsBold())
        EXPECT_TRUE(False == text.CreateStartCaret().GetCurrentRun().GetProperties().IsItalic())

        text.SetStyleProperties(style, styleMask, text.CreateStartCaret(), text.CreateEndCaret())

        EXPECT_TRUE(text.CreateStartCaret().GetCurrentRun().GetProperties().IsBold())
        EXPECT_TRUE(False == text.CreateStartCaret().GetCurrentRun().GetProperties().IsItalic())

#---------------------------------------------------------------------------------------
# @bsistruct
#---------------------------------------------------------------------------------------
class IFieldTester (ABC):

    @abstractmethod
    def AddFieldToTextBlock (self, textBlock):
        pass

    @abstractmethod
    def ReadAndVerifyField  (self, caret):
        pass