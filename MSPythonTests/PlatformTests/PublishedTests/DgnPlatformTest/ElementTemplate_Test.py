
#--------------------------------------------------------------------------------------#
#
#     $Source: ElementTemplate_Test.py $
#
#  $Copyright: (c) 2014 Bentley Systems, Incorporated. All rights reserved. $
#
#--------------------------------------------------------------------------------------#/
import os
import pytest
import ctypes

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from util import *

s_nLinesCreated = 0
s_nEllipseCreated = 0

dgnFileName = '2dMetricGeneral.dgn'

#=================================================================================##/##
#
# Base class used by all element template tests
#
# @bsiclass                                                     Ping.Chen     04/2024
#===============*===============*===============*===============*===============*======#/
class TestElementTestToolkitFixture :
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
        self.m_primaryDgnFileP = self.loadDgnFileByFileName (dgnFileName)
        self.m_defaultModel, retVal = self.m_primaryDgnFileP.LoadRootModelById (self.m_primaryDgnFileP.DefaultModelId, True)

    def GetDgnModel (self):
        return self.m_defaultModel

    def GetDgnFile (self):
        return self.m_primaryDgnFileP

    def setup_method (self):
        DgnPlatformFixture_Initialize ()
        self.loadDgnModel ()
        self.m_uorsPerMeter = self.m_defaultModel.GetModelInfo ().GetUorPerMeter()
        self.m_linearsModel = self.CreateModel ("Linears")


    def teardown_method (self):
        st = self.m_primaryDgnFileP.DeleteModel (self.m_linearsModel)
        self.m_primaryDgnFileP.ProcessChanges (DgnSaveReason.eFileClose)
        assert self.m_primaryDgnFileP.FindModelIdByName(dgnFileName) == INVALID_MODELID
        self.m_primaryDgnFileP.Release ()

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def CreateModel (self, modelName):
        model, result = self.GetDgnFile ().CreateNewModel (modelName, DgnModelType.eNormal, False)
        EXPECT_TRUE (None != model) # "SETUP FAILURE: Create model failed"
        return model

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def GetFirstAvailableLevel (self, dgnFile):
        #Use first available level
        levelCache = self.m_primaryDgnFileP.GetLevelCache ()

        it = iter (levelCache)
        level = next (it)

        return level.GetLevelId ()

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Bill.Steinbock                  04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    #def ConvertUorsToMeters (self, uors):
    #    return uors/self.m_uorsPerMeter


    #-------------------------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     11/2012
    #---------------#---------------#---------------#---------------#---------------#---------------#------#/
    #def GetHatchValues (self, eh, hatchSpacings, hatchAngles):
    #    elmHandler = eh.GetHandler ()
    #    areaQueryObj = elmHandler

    #    if (None == areaQueryObj):
    #        return False

    #    patternParams = PatternParams ()
    #    hatchLines = DwgHatchDefLineArray ()
    #    paternOrigin = DPoint3d ()
    #    patIndex = 0

    #    if (False == areaQueryObj.GetPattern (eh, patternParams, hatchLines, paternOrigin, patIndex)):
    #        return False

    #    hatchSpacings.x = patternParams.GetPrimarySpacing()
    #    hatchSpacings.y = patternParams.GetSecondarySpacing()
    #    hatchAngles.x = patternParams.GetPrimaryAngle()
    #    hatchAngles.y = patternParams.GetSecondaryAngle()

    #    return True

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    #def GetPatternParams (self, eh, patternParams):
    #    elmHandler = eh.GetHandler ()
    #    areaQueryObj = elmHandler

    #    if (None == areaQueryObj):
    #        return False

    #    hatchLines = DwgHatchDefLineArray ()
    #    paternOrigin = DPoint3d ()
    #    patIndex = 0

    #    if (Fales == areaQueryObj.GetPattern (eh, patternParams, hatchLines, paternOrigin, patIndex)):
    #        return False

    #    return True

    #---------------------------------------------------------------------------------##/##
    # Create linestyle param. The distance values are in meters and need to be converted
    # to UORs to match how are in MicroStation.
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def CreateLineStyleParams (self, dScale = 1.0, dPhase = 1.0, eWidth = 1.0, fPhase = 1.0, gScale = 1.0, scale = 1.0):
        lineStyleParams = LineStyleParams ()

        if (scale != 0.0):
            lineStyleParams.modifiers *= STYLEMOD_SCALE
            lineStyleParams.scale = scale
   
        if (dScale != 0.0):
            lineStyleParams.modifiers *= STYLEMOD_DSCALE
            lineStyleParams.dashScale = dScale

        if (gScale != 0.0):
            lineStyleParams.modifiers *= STYLEMOD_GSCALE
            lineStyleParams.gapScale = gScale

##ifdef NO_PARAM_PASSED_IN
#        if (sWidth != 0.0):
#            lineStyleParams.modifiers *= STYLEMOD_SWIDTH
#            lineStyleParams.startWidth = sWidth * self.m_uorsPerMeter
##endif

        if (eWidth != 0.0):
            lineStyleParams.modifiers *= STYLEMOD_EWIDTH
            lineStyleParams.endWidth = eWidth * self.m_uorsPerMeter 


        shiftDistanceDefined = False

        if (dPhase != 0.0):
            shiftDistanceDefined = True
            lineStyleParams.modifiers &= ~STYLEMOD_CENTERPHASE
            lineStyleParams.modifiers &= ~STYLEMOD_FRACTPHASE
            lineStyleParams.modifiers |= STYLEMOD_DISTPHASE
            lineStyleParams.distPhase = dPhase * self.m_uorsPerMeter 


        if (False == shiftDistanceDefined):
            if (fPhase != 0.0):
                lineStyleParams.modifiers &= ~STYLEMOD_CENTERPHASE
                lineStyleParams.modifiers &= ~STYLEMOD_DISTPHASE
                lineStyleParams.modifiers |= STYLEMOD_FRACTPHASE
                lineStyleParams.fractPhase = fPhase

        return lineStyleParams

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    #def CreatePatternParams (self, space1 = 0, angle1 = 0, space2 = 0, angle2 = 0, scale = 0, cellName = ""):
    #    # This should return PatternParam as it would exist in MicroStation memory ie UORs and Radians
    #    patternStyleParams = PatternParams ()

    #    patternStyleParams.SetPrimarySpacing (space1 * self.m_uorsPerMeter)
    #    patternStyleParams.SetPrimaryAngle (angle1 * msGeomConst_radiansPerDegree)
    #    patternStyleParams.SetSecondarySpacing (space2 * self.m_uorsPerMeter)

    #    if ("" == cellName):
    #        patternStyleParams.SetSecondaryAngle (angle2 * msGeomConst_radiansPerDegree)
    #    else:
    #        patternStyleParams.SetScale (scale)
    #        patternStyleParams.TestElementTemplateTestsFixture.SetCellName (cellName)

    #    return patternStyleParams


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def CreateGradientColor (self, angle = 45.0, mode = GradientMode.eLinear):
        fillColor = GradientSymb ()

        colors = RgbColorDefArray ()
        colors.append (RgbColorDef ())
        colors.append (RgbColorDef ())

        values = DoubleArray ()
        values.append (0.0)
        values.append (0.0)

        fillColor.SetAngle (angle * msGeomConst_radiansPerDegree)
        fillColor.SetMode (mode)

        colors[0].red   = 10
        colors[0].blue  = 10
        colors[0].green = 10
        values[0]       = 0.0

        colors[1].red   = 255
        colors[1].blue  = 200
        colors[1].green = 10
        values[1]       = 1.0

        fillColor.SetKeys (colors, values)

        return fillColor

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def CreateTextStyleOverrideParams (self, textScale, fontNum=0, characterSpacing = 1.0):
        textParams = TextParamWide ()
        textParams.Initialize ()

        if (0.0 != textScale.y):
            textParams.exFlags.StyleOverrides = True
            textParams.overridesFromStyle.height = True
            textScale.y = textScale.y * self.m_uorsPerMeter

        if (0.0 != textScale.x):
            textParams.exFlags.StyleOverrides = True
            textParams.overridesFromStyle.width = True
            textScale.x = textScale.x * self.m_uorsPerMeter

        if (0 != fontNum):
            textParams.font = fontNum
            textParams.exFlags.StyleOverrides = True
            textParams.overridesFromStyle.fontNo = True

        if (0.0 != characterSpacing):
            textParams.exFlags.StyleOverrides = True
            textParams.overridesFromStyle.interCharSpacing  = True
            textParams.flags.InterCharSpacing = True
            textParams.characterSpacing = characterSpacing * self.m_uorsPerMeter

        return textParams

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def GetOrCreateTextStyleId (self, dgnFile):
        collection = TextStyleCollection (dgnFile)
        it = iter (collection)

        try:
            testStyle = next (it)
        except StopIteration:
            #Create Text Style.
            textStyle = DgnTextStyle ("TestTextStyle", dgnFile)
            EXPECT_EQ (True, textStyle!= None) # "DgnTextStyle.eGetSettings method failed."

            textStyle.SetDoubleProperty (eTextStyle_Width, 1.0*self.m_uorsPerMeter)
            textStyle.SetDoubleProperty (eTextStyle_Height, 1.0*self.m_uorsPerMeter)
            textStyle.SetUInt32Property (eTextStyle_Color, 3)
            textStyle.SetBoolProperty (eTextStyle_ColorFlag, True)

            if (eSUCCESS != textStyle.Add ()):
                return 0

            dgnFile.ProcessChanges (DgnSaveReason.eApplInitiated)
            return textStyle.GetID ()    # TextStyles are - type-cast required for VS2012

        if (testStyle != None):
            return testStyle.GetID ()    # TextStyles are - type-cast required for VS2012

        return 0

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def GetOrCreateMlineStyleById (self, dgnFile):
        collection = MultilineStyleCollection (dgnFile)
        it = iter (collection)

        try:
            mlineStyle = next (it)
        except StopIteration:
            mlineStyle = MultilineStyle.Create ("TestMline", dgnFile)

            # Must have 1 profile
            styleprof = MultilineProfile ()

            # signed_int = ctypes.c_int(-1)
            # signed_value = signed_int.value
            #Use -1 to add it at the end
            endPos = ctypes.c_uint(-1).value
            if (eSUCCESS != mlineStyle.InsertProfile (styleprof, endPos)):
                return 0

            if (eSUCCESS != mlineStyle.Add ()):
                return 0

            dgnFile.ProcessChanges (DgnSaveReason.eApplInitiated)
            return mlineStyle.GetID ()

        if (mlineStyle!= None):
            return mlineStyle.GetID ()

        return 0


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def GetOrCreateDimensionStyleById (self, dgnFile):
        collection = DimStyleCollection (dgnFile)
        it = iter (collection)

        try:
            dimStyle = next (it)
        except StopIteration:
            dimStyle = DimensionStyle ("TestDimensionStyle", dgnFile)
            if (eSUCCESS != dimStyle.Add (dgnFile)):
                return 0

            dgnFile.ProcessChanges (DgnSaveReason.eApplInitiated)
            return dimStyle.GetID ()

        if (dimStyle!= None):
            return dimStyle.GetID ()

        return 0


#===========================================================================================================================##/##
# TestElementTemplateTestsFixture                                                                                                            #
#                                                                                                                                 #
# @bsiclass                                                     Ping.Chen     04/2024                                           #
#                                                                                                                                 #
# Template Steps:                                                                                                                 #
# 1) Create the Template                       - TemplateCreate() Method                                                          #
# 2) Write Values to Template                  - TemplateAdd() Methods                                                            #
# 3) Compare Expected to Actual for Equality   - TemplateEq() Methods                                                             #
# 4) Set Change Values in Template             - TemplateSet() Methods                                                            #
# 5) Compare Expected to Actual for Inequality - TemplateEq() Methods                                                             #
# 6) Check to see if Template Exists           - TemplateExists() Method                                                          #
# 7) Write Extra Values to Template            - TemplateAdd() Methods                                                            #
#===============*===============*===============*===============*===============*===============*===============*===============##/
class TestElementTemplateTestsFixture (TestElementTestToolkitFixture):
    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def CreatePrimaryTemplate (self, templatePath = "TestGroup\\Default"):
        self.m_primaryDgnFileP = super ().GetDgnFile ()
        self.m_primaryPElementTemplate = None

        # create the template
        result, self.m_primaryPElementTemplate = ElementTemplateUtils.CreateByPath (templatePath, self.m_primaryDgnFileP)
        if (eETSTATUS_Success != result):
            return False

        self.m_primaryEtInstance = self.m_primaryPElementTemplate.GetOrCreateDefaultInstance ()
        return True


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def PrimaryTemplateExists (self):
        templatePath = self.m_primaryPElementTemplate.GetFullPath ()
        pOwner = self.m_primaryPElementTemplate.GetOwner ()
        EXPECT_TRUE (None != pOwner)

        pOwner.Write (self.m_primaryPElementTemplate)

        # ensure we can find the element template node by path
        self.m_primaryPElementTemplate = ElementTemplateUtils.FindTemplateNodeByPath (templatePath.GetWCharCP(), pOwner)
        EXPECT_TRUE (self.m_primaryPElementTemplate != None)

        self.m_primaryEtInstance = self.m_primaryPElementTemplate.GetDefaultInstance ()
        EXPECT_TRUE (self.m_primaryEtInstance != None)

        return True

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqLevelName (etInstance, expected, index=0):
        actual = WString ()
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.GetLevelName (actual, etInstance, index))
        return WString (expected) == actual

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqLevelId (etInstance, expected, modelRef, index=0):
        retVal, actual = ElementTemplateParamsHelper.GetLevelId (modelRef, etInstance, index)
        EXPECT_TRUE (eETSTATUS_Success == retVal)
        return expected == actual

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqElementColorDef (etInstance,  expected, dgnFile, modelRef, index=0):
        retVal, actual = ElementTemplateParamsHelper.GetElementColor (modelRef, etInstance, index)
        EXPECT_TRUE (eETSTATUS_Success == retVal)
        return DgnColorMap.CreateElementColor (expected, None, None, dgnFile) == actual


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqLineWeight (etInstance, expected, index=0):
        retVal, actual = ElementTemplateParamsHelper.GetWeight (etInstance, index)
        EXPECT_TRUE (eETSTATUS_Success == retVal)
        return expected == actual


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqLineStyleName (etInstance, expectedName, expectedStyle, modelRef, index=0):
        retVal, actualName, actualStyle = ElementTemplateParamsHelper.GetLineStyleName (modelRef, etInstance, index)
        EXPECT_TRUE (eETSTATUS_Success == retVal)
        if (WString (expectedName) != actualName):
            return False

        return expectedStyle == actualStyle


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqLineStyleId (etInstance, expectedId, expectedStyle, modelRef, index=0):
        retVal, actualId, actualStyle = ElementTemplateParamsHelper.GetLineStyleId (modelRef, etInstance, index)
        EXPECT_TRUE (eETSTATUS_Success == retVal)
        if (expectedId != actualId):
            return False

        return expectedStyle == actualStyle


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqLineStyleParams (etInstance, expected, uorsPerMeter, index=0):
        actual = LineStyleParams ()
        actual.Init ()

        # NEEDSWORK: there is no good way to default-initialize a class via published API...
        # -it's a non-aggregate due to inheritance
        # -it has no conclassor
        # -its Init() method is unpublished
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.GetLineStyleParams (actual, uorsPerMeter, etInstance, index))
        if (actual.dashScale != expected.dashScale):
            return False

        #  can either set distPhase or fractPhase but not both
        if (0 != actual.distPhase):
            if (actual.distPhase != expected.distPhase):
                return False
        else:
            if (actual.fractPhase != expected.fractPhase):
                return False

        if (actual.endWidth != expected.endWidth):
            return False
        if (actual.gapScale != expected.gapScale):
            return False

        return actual.scale == expected.scale

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqElementClass (etInstance, expected, index=0):
        retVal, actual = ElementTemplateParamsHelper.GetElementClass (etInstance, index)
        EXPECT_TRUE (eETSTATUS_Success == retVal)
        return expected == actual


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqTransparency (etInstance, expected, index=0):
        retVal, actual = ElementTemplateParamsHelper.GetTransparency (etInstance, index)
        EXPECT_TRUE (eETSTATUS_Success == retVal)
        return expected == actual

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqPriority (etInstance, expected, index=0):
        retVal, actual = ElementTemplateParamsHelper.GetPriority (etInstance, index)
        EXPECT_TRUE (eETSTATUS_Success == retVal)
        return expected == actual

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqAreaMode (etInstance, expected, index=0):
        retVal, actual = ElementTemplateParamsHelper.GetAreaMode (etInstance, index)
        EXPECT_TRUE (eETSTATUS_Success == retVal)
        return expected == actual


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqSolidFillColor (etInstance,  expected, modelRef, dgnFile, index=0):
        retVal, actual, gradientsymb = ElementTemplateParamsHelper.GetFillColorIdOrGradientSpecification (modelRef, etInstance, index)
        if (actual == 0):
            return False

        return DgnColorMap.CreateElementColor (expected, None, None, dgnFile) == actual


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqGradientFillColor (etInstance, expected, modelRef, index=0):
        retVal, color, actual = ElementTemplateParamsHelper.GetFillColorIdOrGradientSpecification (modelRef, etInstance, index)
        if (actual == None):
            return False

        if (expected.GetAngle () != actual.GetAngle ()):
            return False

        return expected.GetMode () == actual.GetMode ()


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqFillMode (etInstance, expected, index=0):
        retVal, actual = ElementTemplateParamsHelper.GetFillMode (etInstance, index)
        EXPECT_TRUE (eETSTATUS_Success == retVal)
        return expected == actual


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqCellName (etInstance, expected, index=0):
        actual = WString ()
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.GetCellName (actual, etInstance, index))
        return WString (expected) == actual

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqCellScale (etInstance, expected, index=0):
        actual = DPoint3d (0.0, 0.0, 0.0) 
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.GetCellScale (actual, etInstance, index))
        if (expected.x != actual.x):
            return False
        if (expected.y != actual.y):
            return False

        return expected.z == actual.z


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqTerminatorCellName (etInstance, expected, index=0):
        actual = WString ()
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.GetTerminatorCellName (actual, etInstance, 0))
        return WString (expected) == actual


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqTerminatorScale (etInstance, expected, index=0):
        retVal, actual = ElementTemplateParamsHelper.GetTerminatorScale (etInstance, index)
        EXPECT_TRUE (eETSTATUS_Success == retVal)
        return expected == actual


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqActivePointSpecification (etInstance, expectedPointType, expectedPointString, index=0):
        retVal, actualPointType, actualPointString = ElementTemplateParamsHelper.GetActivePointSpecification (etInstance, index)
        EXPECT_TRUE (eETSTATUS_Success == retVal)
        if (actualPointType != eACTIVEPOINTTYPE_ZeroLengthLine):
            if (WString (expectedPointString) != actualPointString):
                return False

        return expectedPointType == actualPointType


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqTextStyleName (etInstance, expected, index=0):
        actual = WString ()
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.GetTextStyleName (actual, etInstance, index))
        return WString (expected) == actual


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqTextStyleId (etInstance, expected, modelRef, index=0):
        retVal, actual = ElementTemplateParamsHelper.GetTextStyleId (modelRef, etInstance, index)
        EXPECT_TRUE (eETSTATUS_Success == retVal)
        return expected == actual


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqTextStyleOverride (self, etInstance, expected, expectedScale, index=0):
        retVal, actual, actualScale, actualLength = ElementTemplateParamsHelper.GetTextParamsAndScale (self.m_defaultModel, self.m_uorsPerMeter, etInstance, index)
        EXPECT_TRUE (eETSTATUS_Success == retVal)
        if (expectedScale.x != actualScale.x):
            return False
        if (expectedScale.y != actualScale.y):
            return False
        EXPECT_TRUE (actual == expected)
        return True


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqPatternCellName (etInstance, expected, index=0):
        actual = WString ()
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.GetPatternCellName (actual, etInstance, index))
        return WString (expected) == actual


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqPatternDeltaValues (etInstance, expectedX, expectedY, index=0):
        actualX = ECValue ()
        actualY = ECValue ()
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.GetPatternDeltaValues (actualX, actualY, etInstance, index))
        if (expectedX != actualX.GetDouble ()):
            return False

        return expectedY == actualY.GetDouble ()


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqPatternAngle (etInstance, expected, index=0):
        retVal, actual = ElementTemplateParamsHelper.GetPatternAngle (etInstance, index)
        EXPECT_TRUE (eETSTATUS_Success == retVal)
        return expected == actual


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqPatternScale (etInstance, expected, index=0):
        retVal, actual = ElementTemplateParamsHelper.GetPatternScale (etInstance, index)
        EXPECT_TRUE (eETSTATUS_Success == retVal)
        return expected == actual


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqHatchDeltaValues (etInstance, expectedX, expectedY, index=0):
        actualX = ECValue ()
        actualY = ECValue ()
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.GetHatchDeltaValues (actualX, actualY, etInstance, index))
        if (expectedX != actualX.GetDouble ()):
            return False

        return expectedY == actualY.GetDouble ()


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqHatchAngleValues (etInstance, expectedX, expectedY, index=0):
        actualX = ECValue ()
        actualY = ECValue ()
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.GetHatchAngleValues (actualX, actualY, etInstance, index))
        if (expectedX != actualX.GetDouble ()):
            return False

        return expectedY == actualY.GetDouble ()


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqMlineStyleName (etInstance, expected, index=0):
        actual = WString ()
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.GetMlineStyleName (actual, etInstance, index))
        return WString (expected) == actual


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqMlineStyleId (etInstance, expected, file, index=0):
        retVal, mlineStyle = ElementTemplateParamsHelper.GetMlineStyle(file, etInstance, index)
        EXPECT_TRUE (eETSTATUS_Success == retVal)
        actual = mlineStyle.GetID()
   
        return expected == actual


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqDimensionStyleName (etInstance, expected, index=0):
        actual = WString ()
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.GetDimensionStyleName (actual, etInstance, index))
        return WString (expected) == actual


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqDimensionStyleId (etInstance, expected, file, index=0):
        retVal, dimStyle = ElementTemplateParamsHelper.GetDimensionStyle(file, etInstance, index)
        actual = dimStyle.GetID()
   
        return expected == actual


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqMaterialNameAndPalette (etInstance, expectedMaterial, expectedPalette, index=0):
        actualMaterial = WString ()
        actualPalette = WString ()
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.GetMaterialNameAndPalette (actualMaterial, actualPalette, etInstance, index))
        if (WString (expectedMaterial) != actualMaterial):
            return False

        return WString (expectedPalette) == actualPalette
    

     #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqDetailSymbolStyleName (etInstance, expected, index=0):
        actual = WString ()
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.GetDetailSymbolStyleName (actual, etInstance, index))
        return WString (expected) == actual


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetLevelByName (etInstance, levelName, index=0):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetLevelByName (etInstance, WString (levelName), index))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetLevelById (self, etInstance, dgnFile, levelId = 0, index=0):
        if (levelId == 0):
            levelId = super ().GetFirstAvailableLevel (dgnFile)

        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetLevelById (etInstance, levelId, dgnFile, index))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetElementColor (etInstance, elementColorDef, dgnFile, index=0):
        elementColorInteger = DgnColorMap.CreateElementColor (elementColorDef, None, None, dgnFile)
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetElementColor (etInstance, elementColorInteger, dgnFile, index))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetLineWeight (etInstance, lineWeight, index=0):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetLineWeight (etInstance, lineWeight, index))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetLineStyleByName (etInstance, lineName, index=0):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetLineStyleByName (etInstance, WString (lineName), index))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetLineStyleById (etInstance, lineID, dgnFile, index=0):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetLineStyleById (etInstance, lineID, dgnFile, index))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetLineStyleParams (etInstance, lineStyleParams, modelRef, index=0):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetLineStyleParams (etInstance, lineStyleParams, modelRef, index))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetElementClass (etInstance, elementClass, index=0):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetElementClass (etInstance, elementClass, index))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetTransparency (etInstance, transparency, index=0):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetTransparency (etInstance, transparency, index))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetPriority (etInstance, priority, index=0):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetPriority (etInstance, priority, index))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetAreaMode (etInstance, isHole = False, index=0):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetAreaMode (etInstance, isHole, index))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetSolidFillColor (etInstance,  solidColorDef, dgnFile, index=0):
        solidColorInteger = DgnColorMap.CreateElementColor (solidColorDef, None, None, dgnFile)
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetElementFillToSolidColor (etInstance, solidColorInteger, dgnFile, index))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetGradientFillColor (etInstance, fillColor = None, index=0):
        if (fillColor == None):
            fillColor = GradientSymb ()
            fillColor.SetAngle (45.0*msGeomConst_radiansPerDegree)
            fillColor.SetMode (GradientMode.eLinear)

            keyColors = RgbColorDefArray ()
            keyLocations = DoubleArray ()

            keyLocations.append (0.0)
            colorDef0 = RgbColorDef ()
            colorDef0.red = 255
            colorDef0.blue = 0
            colorDef0.green = 0
            keyColors.append (colorDef0)

            keyLocations.append (1.0)
            colorDef1 = RgbColorDef ()
            colorDef1.red = 255
            colorDef1.blue = 255
            colorDef1.green = 255
            keyColors.append (colorDef1)

            fillColor.SetKeys (keyColors, keyLocations)

        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetElementFillToGradient (etInstance, fillColor, index))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetFillMode (etInstance, fillMode, index=0):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetFillMode (etInstance, fillMode, index))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetCellName (etInstance, cellName, index=0):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetCellName (etInstance, WString (cellName), index))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetCellScale (etInstance, cellScale, index=0):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetCellScale (etInstance, cellScale, index))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetTerminatorCellName (etInstance, cellName, index=0):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetTerminatorCellName (etInstance, WString (cellName), index))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetTerminatorScale (etInstance, scale, index=0):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetTerminatorScale (etInstance, scale, index))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetActivePointSpecification (etInstance, pointType, activePointString, index=0):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetActivePointSpecification (etInstance, pointType, WString (activePointString), index))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetTextStyleByName (etInstance, textStyleName, index=0):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetTextStyleByName (etInstance, WString (textStyleName), index))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetTextStyleById (self, etInstance, dgnFile, styleId = 0, index=0):
        if (0 == styleId):
            styleId = self.GetOrCreateTextStyleId (dgnFile)

        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetTextStyleById (etInstance, styleId, dgnFile, index))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetTextStyleOverride (self, etInstance, textScale, textParams, lineLength=0, index=0):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetTextStyleOverride (etInstance, textScale, textParams, lineLength, self.m_defaultModel, index))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetPatternCellName (etInstance, cellName, index=0):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetPatternCellName (etInstance, WString (cellName), index))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetPatternDeltaValues (etInstance, deltaxValue, deltayValue, index=0):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetPatternDeltaValues (etInstance, deltaxValue, deltayValue, index))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetPatternAngle (etInstance, angle, index=0):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetPatternAngle (etInstance, angle, index))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetPatternScale (etInstance, scale, index=0):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetPatternScale (etInstance, scale, index))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetHatchDeltaValues (etInstance, deltaxValue, deltayValue, index=0):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetHatchDeltaValues (etInstance, deltaxValue, deltayValue, index))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetHatchAngleValues (etInstance, angle1Value, angle2Value, index=0):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetHatchAngleValues (etInstance, angle1Value, angle2Value, index))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetMlineStyleByName (etInstance, mLineStyleName, index=0):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetMlineStyleByName (etInstance, WString (mLineStyleName), index))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetMlineStyleById (self, etInstance, dgnFile, styleId = 0, index=0):
        if (0 == styleId):
            styleId = self.GetOrCreateMlineStyleById (dgnFile)

        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetMlineStyleById (etInstance, styleId, dgnFile, index))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetDimensionStyleByName (etInstance, dimensionStyleName, index=0):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetDimensionStyleByName (etInstance, WString (dimensionStyleName), index))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetDimensionStyleById (self, etInstance, dgnFile, styleId = 0, index=0):
        if (0 == styleId):
            styleId = self.GetOrCreateDimensionStyleById (dgnFile)

        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetDimensionStyleById (etInstance, styleId, dgnFile, index))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetMaterialNameAndPalette (etInstance, material, palette, index=0):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetMaterialNameAndPalette (etInstance, WString (material), WString (palette), index))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    #def SetMaterialById (etInstance, MaterialId materialId, modelRef, index=0)

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SetDetailSymbolStyleByName (etInstance, styleName, index=0):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.SetDetailSymbolStyleByName (etInstance, WString (styleName), index))

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddLevelByName (etInstance, levelName):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddLevelByName (etInstance, WString (levelName)))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddLevelById (self, etInstance, dgnFile, levelId = 0):
        if (levelId == 0):
            levelId = super ().GetFirstAvailableLevel (dgnFile)

        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddLevelById (etInstance, levelId, dgnFile))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddElementColor (etInstance,  elementColorDef, dgnFile):
        elementColorInteger = DgnColorMap.CreateElementColor (elementColorDef, None, None, dgnFile)
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddElementColor (etInstance, elementColorInteger, dgnFile))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddLineWeight (etInstance, lineWeight):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddLineWeight (etInstance, lineWeight))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddLineStyleByName (etInstance, lineName):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddLineStyleByName (etInstance, WString (lineName)))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddLineStyleById (etInstance, lineID, dgnFile):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddLineStyleById (etInstance, lineID, dgnFile))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddLineStyleParams (etInstance, lineStyleParams, modelRef):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddLineStyleParams (etInstance, lineStyleParams, modelRef))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddElementClass (etInstance, elementClass):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddElementClass (etInstance, elementClass))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddTransparency (etInstance, transparency):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddTransparency (etInstance, transparency))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddPriority (etInstance, priority):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddPriority (etInstance, priority))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddAreaMode (etInstance, isHole = False):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddAreaMode (etInstance, isHole))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddSolidFillColor (etInstance,  solidColorDef, dgnFile):
        solidColorInteger = DgnColorMap.CreateElementColor (solidColorDef, None, None, dgnFile)
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddSolidFillColor (etInstance, solidColorInteger, dgnFile))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddGradientFillColor (etInstance, fillColor = None):
        if (fillColor == None):

            fillColor = GradientSymb.Create()
            fillColor.SetAngle (45.0*msGeomConst_radiansPerDegree)
            fillColor.SetMode (GradientMode.eLinear)

            keyColors = RgbColorDefArray ()
            keyLocations = DoubleArray ()

            keyLocations.append (0.0)

            colorDef0 = RgbColorDef ()
            colorDef0.red = 255
            colorDef0.blue = 0
            colorDef0.green = 0
            keyColors.append (colorDef0)

            keyLocations.append (1.0)
            colorDef1 = RgbColorDef ()
            colorDef1.red = 255
            colorDef1.blue = 255
            colorDef1.green = 255
            keyColors.append (colorDef1)

            fillColor.SetKeys (keyColors, keyLocations)

        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddGradientFillColor (etInstance, fillColor))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddFillMode (etInstance, fillMode):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddFillMode (etInstance, fillMode))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddCellName (etInstance, cellName):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddCellName (etInstance, WString (cellName)))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddCellScale (etInstance, cellScale):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddCellScale (etInstance, cellScale))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddTerminatorCellName (etInstance, cellName):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddTerminatorCellName (etInstance, WString (cellName)))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddTerminatorScale (etInstance, scale):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddTerminatorScale (etInstance, scale))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddActivePointSpecification (etInstance, pointType, activePointString):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddActivePointSpecification (etInstance, pointType, WString (activePointString)))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddTextStyleByName (etInstance, textStyleName):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddTextStyleByName (etInstance, WString (textStyleName)))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddTextStyleById (self, etInstance, dgnFile, styleId = 0):
        if (0 == styleId):
            styleId = self.GetOrCreateTextStyleId (dgnFile)

        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddTextStyleById (etInstance, styleId, dgnFile))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddTextStyleOverride (self, etInstance, textParams, textScale, lineLength=0):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddTextStyleOverride (etInstance, textScale, textParams, lineLength, self.m_defaultModel))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddPatternCellName (etInstance, cellName):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddPatternCellName (etInstance, WString (cellName)))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddPatternDeltaValues (etInstance, deltaxValue, deltayValue):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddPatternDeltaValues (etInstance, deltaxValue, deltayValue))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddPatternAngle (etInstance, angle):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddPatternAngle (etInstance, angle))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddPatternScale (etInstance, scale):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddPatternScale (etInstance, scale))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddHatchDeltaValues (etInstance, deltaxValue, deltayValue):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddHatchDeltaValues (etInstance, deltaxValue, deltayValue))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddHatchAngleValues (etInstance, angle1Value, angle2Value):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddHatchAngleValues (etInstance, angle1Value, angle2Value))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddMlineStyleByName (etInstance, mLineStyleName):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddMlineStyleByName (etInstance, WString (mLineStyleName)))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddMlineStyleById (self, etInstance, dgnFile, styleId = 0):
        if (0 == styleId):
            styleId = self.GetOrCreateMlineStyleById (dgnFile)

        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddMlineStyleById (etInstance, styleId, dgnFile))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddDimensionStyleByName (etInstance, dimensionStyleName):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddDimensionStyleByName (etInstance, WString (dimensionStyleName)))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddDimensionStyleById (self, etInstance, dgnFile, styleId = 0):
        if (0 == styleId):
            styleId = self.GetOrCreateDimensionStyleById (dgnFile)

        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddDimensionStyleById (etInstance, styleId, dgnFile))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddMaterialNameAndPalette (etInstance, material, palette):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddMaterialNameAndPalette (etInstance, WString (material), WString (palette)))


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AddDetailSymbolStyleByName (etInstance, styleName):
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateParamsHelper.AddDetailSymbolStyleByName (etInstance, WString (styleName)))

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def LevelNameTest (self):
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\LevelNameTest"))
        TestElementTemplateTestsFixture.AddLevelByName (self.m_primaryEtInstance, "LevelName")
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqLevelName (self.m_primaryEtInstance, "LevelName"))
        TestElementTemplateTestsFixture.SetLevelByName (self.m_primaryEtInstance, "NotLevelName")
        EXPECT_FALSE (TestElementTemplateTestsFixture.EqLevelName (self.m_primaryEtInstance, "LevelName"))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        TestElementTemplateTestsFixture.AddLevelByName (self.m_primaryEtInstance, "NewLevelName")

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def LevelIdTest (self):
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\LevelIdTest"))
        self.AddLevelById (self.m_primaryEtInstance, self.m_primaryDgnFileP)
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqLevelId (self.m_primaryEtInstance, super ().GetFirstAvailableLevel (self.m_primaryDgnFileP), self.m_defaultModel))
        self.SetLevelById (self.m_primaryEtInstance, self.m_primaryDgnFileP)
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqLevelId (self.m_primaryEtInstance, super ().GetFirstAvailableLevel (self.m_primaryDgnFileP), self.m_defaultModel))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        self.AddLevelById (self.m_primaryEtInstance, self.m_primaryDgnFileP)

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)
        return True

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def ElementColorTest (self):
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\ElementColorTest"))
        TestElementTemplateTestsFixture.AddElementColor (self.m_primaryEtInstance, IntColorDef(230, 10, 0, 0), self.m_primaryDgnFileP)
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqElementColorDef (self.m_primaryEtInstance, IntColorDef(230, 10, 0, 0), self.m_primaryDgnFileP, self.m_defaultModel))
        TestElementTemplateTestsFixture.SetElementColor (self.m_primaryEtInstance, IntColorDef(160, 30, 10, 70), self.m_primaryDgnFileP)
        EXPECT_FALSE (TestElementTemplateTestsFixture.EqElementColorDef (self.m_primaryEtInstance, IntColorDef(230, 10, 0, 0), self.m_primaryDgnFileP, self.m_defaultModel))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        TestElementTemplateTestsFixture.AddElementColor (self.m_primaryEtInstance, IntColorDef(240, 20, 15, 0), self.m_primaryDgnFileP)

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def LineWeightTest (self):
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\LineWeightTest"))
        TestElementTemplateTestsFixture.AddLineWeight (self.m_primaryEtInstance, 0)
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqLineWeight (self.m_primaryEtInstance, 0))
        TestElementTemplateTestsFixture.SetLineWeight (self.m_primaryEtInstance, 1)
        EXPECT_FALSE (TestElementTemplateTestsFixture.EqLineWeight (self.m_primaryEtInstance, 0))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        TestElementTemplateTestsFixture.AddLineWeight (self.m_primaryEtInstance, 3)

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def LineStyleNameTest (self):
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\LineStyleNameTest"))
        TestElementTemplateTestsFixture.AddLineStyleByName (self.m_primaryEtInstance, "LineStyleName")
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqLineStyleName (self.m_primaryEtInstance, "LineStyleName", False, self.m_defaultModel))
        TestElementTemplateTestsFixture.SetLineStyleByName (self.m_primaryEtInstance, "NotLineStyleName")
        EXPECT_FALSE (TestElementTemplateTestsFixture.EqLineStyleName (self.m_primaryEtInstance, "LineStyleName", False, self.m_defaultModel))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        TestElementTemplateTestsFixture.AddLineStyleByName (self.m_primaryEtInstance, "NewLineStyleName")

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def LineStyleIdTest (self):
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\LineStyleIdTest"))
        TestElementTemplateTestsFixture.AddLineStyleById (self.m_primaryEtInstance, 0, self.m_primaryDgnFileP)
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqLineStyleId (self.m_primaryEtInstance, 0, False, self.m_defaultModel))
        TestElementTemplateTestsFixture.SetLineStyleById (self.m_primaryEtInstance, 1, self.m_primaryDgnFileP)
        EXPECT_FALSE (TestElementTemplateTestsFixture.EqLineStyleId (self.m_primaryEtInstance, 0, False, self.m_defaultModel))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        TestElementTemplateTestsFixture.AddLineStyleById (self.m_primaryEtInstance, 2, self.m_primaryDgnFileP)

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def LineStyleParamsTest (self):
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\LineStyleParamsTest"))
        TestElementTemplateTestsFixture.AddLineStyleParams (self.m_primaryEtInstance, self.CreateLineStyleParams(), self.m_defaultModel)
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqLineStyleParams (self.m_primaryEtInstance, self.CreateLineStyleParams(), self.m_uorsPerMeter))
        TestElementTemplateTestsFixture.SetLineStyleParams (self.m_primaryEtInstance, self.CreateLineStyleParams(2.0, 2.0, 2.0, 2.0, 2.0, 2.0), self.m_defaultModel)
        EXPECT_FALSE (TestElementTemplateTestsFixture.EqLineStyleParams (self.m_primaryEtInstance, self.CreateLineStyleParams(), self.m_uorsPerMeter))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        TestElementTemplateTestsFixture.AddLineStyleParams (self.m_primaryEtInstance, self.CreateLineStyleParams(), self.m_defaultModel)

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def ElementClassTest (self):
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\ElementClassTest"))
        TestElementTemplateTestsFixture.AddElementClass (self.m_primaryEtInstance, DgnElementClass.ePrimary)
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqElementClass (self.m_primaryEtInstance, DgnElementClass.ePrimary))
        TestElementTemplateTestsFixture.SetElementClass (self.m_primaryEtInstance, DgnElementClass.eConstruction)
        EXPECT_FALSE (TestElementTemplateTestsFixture.EqElementClass (self.m_primaryEtInstance, DgnElementClass.ePrimary))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        TestElementTemplateTestsFixture.AddElementClass (self.m_primaryEtInstance, DgnElementClass.eLinearPatterned)

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def TransparencyTest (self):
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\TransparencyTest"))
        TestElementTemplateTestsFixture.AddTransparency (self.m_primaryEtInstance, 0.0)
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqTransparency (self.m_primaryEtInstance, 0.0))
        TestElementTemplateTestsFixture.SetTransparency (self.m_primaryEtInstance, 50.0)
        EXPECT_FALSE (TestElementTemplateTestsFixture.EqTransparency (self.m_primaryEtInstance, 0.0))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        TestElementTemplateTestsFixture.AddTransparency (self.m_primaryEtInstance, 25.0)

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def PriorityTest (self):
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\PriorityTest"))
        TestElementTemplateTestsFixture.AddPriority (self.m_primaryEtInstance, 500)
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqPriority (self.m_primaryEtInstance, 500))
        TestElementTemplateTestsFixture.SetPriority (self.m_primaryEtInstance, 250)
        EXPECT_FALSE (TestElementTemplateTestsFixture.EqPriority (self.m_primaryEtInstance, 500))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        TestElementTemplateTestsFixture.AddPriority (self.m_primaryEtInstance, 125)

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AreaModeTest (self):
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\AreaModeTest"))
        TestElementTemplateTestsFixture.AddAreaMode (self.m_primaryEtInstance, False)
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqAreaMode (self.m_primaryEtInstance, False))
        TestElementTemplateTestsFixture.SetAreaMode (self.m_primaryEtInstance, True)
        EXPECT_FALSE (TestElementTemplateTestsFixture.EqAreaMode (self.m_primaryEtInstance, False))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        TestElementTemplateTestsFixture.AddAreaMode (self.m_primaryEtInstance, True)

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def SolidFillColorTest (self):
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\SolidFillColorTest"))
        TestElementTemplateTestsFixture.AddSolidFillColor (self.m_primaryEtInstance, IntColorDef(230, 10, 0, 0), self.m_primaryDgnFileP)
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqSolidFillColor (self.m_primaryEtInstance, IntColorDef(230, 10, 0, 0), self.m_defaultModel, self.m_primaryDgnFileP))
        TestElementTemplateTestsFixture.SetSolidFillColor (self.m_primaryEtInstance, IntColorDef(160, 65, 5, 0), self.m_primaryDgnFileP)
        EXPECT_FALSE (TestElementTemplateTestsFixture.EqSolidFillColor (self.m_primaryEtInstance, IntColorDef(230, 10, 0, 0), self.m_defaultModel, self.m_primaryDgnFileP))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        TestElementTemplateTestsFixture.AddSolidFillColor (self.m_primaryEtInstance, IntColorDef(150, 50, 20, 0), self.m_primaryDgnFileP)

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def GradientFillColorTest (self):
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\GradientFillColorTest"))
        TestElementTemplateTestsFixture.AddGradientFillColor (self.m_primaryEtInstance, self.CreateGradientColor())
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqGradientFillColor (self.m_primaryEtInstance, self.CreateGradientColor(), self.m_defaultModel))
        TestElementTemplateTestsFixture.SetGradientFillColor (self.m_primaryEtInstance, self.CreateGradientColor(135.0))
        EXPECT_FALSE (TestElementTemplateTestsFixture.EqGradientFillColor (self.m_primaryEtInstance, self.CreateGradientColor(), self.m_defaultModel))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        TestElementTemplateTestsFixture.AddGradientFillColor (self.m_primaryEtInstance, self.CreateGradientColor())

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def FillModeTest (self):
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\FillModeTest"))
        TestElementTemplateTestsFixture.AddFillMode (self.m_primaryEtInstance, eFILLMODE_Outlined)
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqFillMode (self.m_primaryEtInstance, eFILLMODE_Outlined))
        TestElementTemplateTestsFixture.SetFillMode (self.m_primaryEtInstance, eFILLMODE_Filled)
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqFillMode (self.m_primaryEtInstance, eFILLMODE_Filled))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        TestElementTemplateTestsFixture.AddFillMode (self.m_primaryEtInstance, eFILLMODE_Filled)

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def CellNameTest (self):
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\CellNameTest"))
        TestElementTemplateTestsFixture.AddCellName (self.m_primaryEtInstance, "CellName")
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqCellName (self.m_primaryEtInstance, "CellName"))
        TestElementTemplateTestsFixture.SetCellName (self.m_primaryEtInstance, "NotCellName")
        EXPECT_FALSE (TestElementTemplateTestsFixture.EqCellName (self.m_primaryEtInstance, "CellName"))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        TestElementTemplateTestsFixture.AddCellName (self.m_primaryEtInstance, "NewCellName")

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def CellScaleTest (self):
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\CellScaleTest"))
        TestElementTemplateTestsFixture.AddCellScale (self.m_primaryEtInstance, DPoint3d(1.0, 2.0, 1.0))
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqCellScale (self.m_primaryEtInstance, DPoint3d(1.0, 2.0, 1.0)))
        TestElementTemplateTestsFixture.SetCellScale (self.m_primaryEtInstance, DPoint3d(3.0, 1.0, 3.0))
        EXPECT_FALSE (TestElementTemplateTestsFixture.EqCellScale (self.m_primaryEtInstance, DPoint3d(1.0, 2.0, 1.0)))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        TestElementTemplateTestsFixture.AddCellScale (self.m_primaryEtInstance, DPoint3d(4.0, 9.0, 5.0))

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def TerminatorCellNameTest (self):
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\TerminatorCellNameTest"))
        TestElementTemplateTestsFixture.AddTerminatorCellName (self.m_primaryEtInstance, "TerminatorCellName")
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqTerminatorCellName (self.m_primaryEtInstance, "TerminatorCellName"))
        TestElementTemplateTestsFixture.SetTerminatorCellName (self.m_primaryEtInstance, "NotTerminatorCellName")
        EXPECT_FALSE (TestElementTemplateTestsFixture.EqTerminatorCellName (self.m_primaryEtInstance, "TerminatorCellName"))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        TestElementTemplateTestsFixture.AddTerminatorCellName (self.m_primaryEtInstance, "NewTerminatorCellName")

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def TerminatorScaleTest (self):
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\TerminatorScaleTest"))
        TestElementTemplateTestsFixture.AddTerminatorScale (self.m_primaryEtInstance, 1.0)
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqTerminatorScale (self.m_primaryEtInstance, 1.0))
        TestElementTemplateTestsFixture.SetTerminatorScale (self.m_primaryEtInstance, 2.0)
        EXPECT_FALSE (TestElementTemplateTestsFixture.EqTerminatorScale (self.m_primaryEtInstance, 1.0))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        TestElementTemplateTestsFixture.AddTerminatorScale (self.m_primaryEtInstance, 5.0)

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def ActivePointSpecificationTest (self):
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\ActivePointSpecificationTest"))
        TestElementTemplateTestsFixture.AddActivePointSpecification (self.m_primaryEtInstance, eACTIVEPOINTTYPE_ZeroLengthLine, "ignoredString")
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqActivePointSpecification (self.m_primaryEtInstance, eACTIVEPOINTTYPE_ZeroLengthLine, "ignoredString"))
        TestElementTemplateTestsFixture.SetActivePointSpecification (self.m_primaryEtInstance, eACTIVEPOINTTYPE_Cell, "usedString")
        EXPECT_FALSE (TestElementTemplateTestsFixture.EqActivePointSpecification (self.m_primaryEtInstance, eACTIVEPOINTTYPE_ZeroLengthLine, "ignoredString"))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        TestElementTemplateTestsFixture.AddActivePointSpecification (self.m_primaryEtInstance, eACTIVEPOINTTYPE_Cell, "newString")

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def TextStyleNameTest (self):
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\TextStyleNameTest"))
        TestElementTemplateTestsFixture.AddTextStyleByName (self.m_primaryEtInstance, "TextStyleName")
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqTextStyleName (self.m_primaryEtInstance, "TextStyleName"))
        TestElementTemplateTestsFixture.SetTextStyleByName (self.m_primaryEtInstance, "NotTextStyleName")
        EXPECT_FALSE (TestElementTemplateTestsFixture.EqTextStyleName (self.m_primaryEtInstance, "TextStyleName"))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        TestElementTemplateTestsFixture.AddTextStyleByName (self.m_primaryEtInstance, "NewTextStyleName")

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def TextStyleIdTest (self):
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\TextStyleIdTest"))
        self.AddTextStyleById (self.m_primaryEtInstance, self.m_primaryDgnFileP)
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqTextStyleId (self.m_primaryEtInstance, self.GetOrCreateTextStyleId (self.m_primaryDgnFileP), self.m_defaultModel))
        self.SetTextStyleById (self.m_primaryEtInstance, self.m_primaryDgnFileP)
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqTextStyleId (self.m_primaryEtInstance, self.GetOrCreateTextStyleId (self.m_primaryDgnFileP), self.m_defaultModel))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        self.AddTextStyleById (self.m_primaryEtInstance, self.m_primaryDgnFileP)

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def TextStyleOverrideTest (self):
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\TextStyleOverrideTest"))
        textScale = DPoint2d (1.0, 2.0)
        tso = self.CreateTextStyleOverrideParams(textScale)
        self.AddTextStyleOverride (self.m_primaryEtInstance, tso, textScale)
        EXPECT_TRUE (self.EqTextStyleOverride (self.m_primaryEtInstance, tso, textScale))

        modTextScale = DPoint2d(3.0, 8.0)
        modTso = self.CreateTextStyleOverrideParams(modTextScale)

        self.SetTextStyleOverride (self.m_primaryEtInstance, modTextScale, modTso)
       
        chkTextScale = DPoint2d(2.0, 2.0)
        chkTso = self.CreateTextStyleOverrideParams(chkTextScale)

        EXPECT_FALSE (self.EqTextStyleOverride (self.m_primaryEtInstance, chkTso, chkTextScale))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        self.AddTextStyleOverride (self.m_primaryEtInstance, chkTso, chkTextScale)

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def PatternCellNameTest (self):
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\PatternCellNameTest"))
        TestElementTemplateTestsFixture.AddPatternCellName (self.m_primaryEtInstance, "PatternCellName")
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqPatternCellName (self.m_primaryEtInstance, "PatternCellName"))
        TestElementTemplateTestsFixture.SetPatternCellName (self.m_primaryEtInstance, "NotPatternCellName")
        EXPECT_FALSE (TestElementTemplateTestsFixture.EqPatternCellName (self.m_primaryEtInstance, "PatternCellName"))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        TestElementTemplateTestsFixture.AddPatternCellName (self.m_primaryEtInstance, "NewPatternCellName")

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def PatternDeltaValuesTest (self):
        # deltas are in meters
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\PatternDeltaValuesTest"))
        TestElementTemplateTestsFixture.AddPatternDeltaValues (self.m_primaryEtInstance, 2.0, 3.0)
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqPatternDeltaValues (self.m_primaryEtInstance, 2.0, 3.0))
        TestElementTemplateTestsFixture.SetPatternDeltaValues (self.m_primaryEtInstance, 7.0, 4.0)
        EXPECT_FALSE (TestElementTemplateTestsFixture.EqPatternDeltaValues (self.m_primaryEtInstance, 2.0, 3.0))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        TestElementTemplateTestsFixture.AddPatternDeltaValues (self.m_primaryEtInstance, 1.0, 6.0)

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def PatternAngleTest (self):
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\PatternAngleTest"))
        TestElementTemplateTestsFixture.AddPatternAngle (self.m_primaryEtInstance, 1.0)
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqPatternAngle (self.m_primaryEtInstance, 1.0))
        TestElementTemplateTestsFixture.SetPatternAngle (self.m_primaryEtInstance, 3.0)
        EXPECT_FALSE (TestElementTemplateTestsFixture.EqPatternAngle (self.m_primaryEtInstance, 1.0))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        TestElementTemplateTestsFixture.AddPatternAngle (self.m_primaryEtInstance, 7.0)

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def PatternScaleTest (self):
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\PatternScaleTest"))
        TestElementTemplateTestsFixture.AddPatternScale (self.m_primaryEtInstance, 3.0)
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqPatternScale (self.m_primaryEtInstance, 3.0))
        TestElementTemplateTestsFixture.SetPatternScale (self.m_primaryEtInstance, 8.0)
        EXPECT_FALSE (TestElementTemplateTestsFixture.EqPatternScale (self.m_primaryEtInstance, 3.0))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        TestElementTemplateTestsFixture.AddPatternScale (self.m_primaryEtInstance, 6.0)

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def HatchDeltaValuesTest (self):
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\HatchDeltaValuesTest"))
        TestElementTemplateTestsFixture.AddHatchDeltaValues (self.m_primaryEtInstance, 15.0, 6.0)
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqHatchDeltaValues (self.m_primaryEtInstance, 15.0, 6.0))
        TestElementTemplateTestsFixture.SetHatchDeltaValues (self.m_primaryEtInstance, 75.0, 2.0)
        EXPECT_FALSE (TestElementTemplateTestsFixture.EqHatchDeltaValues (self.m_primaryEtInstance, 15.0 ,6.0))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        TestElementTemplateTestsFixture.AddHatchDeltaValues (self.m_primaryEtInstance, 5.0, 29.0)

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def HatchAngleValuesTest (self):
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\HatchAngleValuesTest"))
        TestElementTemplateTestsFixture.AddHatchAngleValues (self.m_primaryEtInstance, 8.0, 1.0)
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqHatchAngleValues (self.m_primaryEtInstance, 8.0, 1.0))
        TestElementTemplateTestsFixture.SetHatchAngleValues (self.m_primaryEtInstance, 90.0, 5.0)
        EXPECT_FALSE (TestElementTemplateTestsFixture.EqHatchAngleValues (self.m_primaryEtInstance, 8.0, 1.0))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        TestElementTemplateTestsFixture.AddHatchAngleValues (self.m_primaryEtInstance, 4.0, 14.0)

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def MlineStyleNameTest (self):
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\MlineStyleNameTest"))
        TestElementTemplateTestsFixture.AddMlineStyleByName (self.m_primaryEtInstance, "MlineStyleName")
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqMlineStyleName (self.m_primaryEtInstance, "MlineStyleName"))
        TestElementTemplateTestsFixture.SetMlineStyleByName (self.m_primaryEtInstance, "NotMlineStyleName")
        EXPECT_FALSE (TestElementTemplateTestsFixture.EqMlineStyleName (self.m_primaryEtInstance, "MlineStyleName"))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        TestElementTemplateTestsFixture.AddMlineStyleByName (self.m_primaryEtInstance, "NewMlineStyleName")

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def MlineStyleIdTest (self):
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\MlineStyleIdTest"))
        self.AddMlineStyleById (self.m_primaryEtInstance, self.m_primaryDgnFileP)
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqMlineStyleId (self.m_primaryEtInstance, self.GetOrCreateMlineStyleById (self.m_primaryDgnFileP), self.m_primaryDgnFileP))
        self.SetMlineStyleById (self.m_primaryEtInstance, self.m_primaryDgnFileP)
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqMlineStyleId (self.m_primaryEtInstance, self.GetOrCreateMlineStyleById (self.m_primaryDgnFileP), self.m_primaryDgnFileP))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        self.AddMlineStyleById (self.m_primaryEtInstance, self.m_primaryDgnFileP)

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def DimensionStyleNameTest (self):
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\DimensionStyleNameTest"))
        TestElementTemplateTestsFixture.AddDimensionStyleByName (self.m_primaryEtInstance, "DimensionStyleName")
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqDimensionStyleName (self.m_primaryEtInstance, "DimensionStyleName"))
        TestElementTemplateTestsFixture.SetDimensionStyleByName (self.m_primaryEtInstance, "NotDimensionStyleName")
        EXPECT_FALSE (TestElementTemplateTestsFixture.EqDimensionStyleName (self.m_primaryEtInstance, "DimensionStyleName"))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        TestElementTemplateTestsFixture.AddDimensionStyleByName (self.m_primaryEtInstance, "NewDimensionStyleName")

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def DimensionStyleIdTest (self):
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\DimensionStyleIdTest"))
        self.AddDimensionStyleById (self.m_primaryEtInstance, self.m_primaryDgnFileP)
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqDimensionStyleId (self.m_primaryEtInstance, self.GetOrCreateDimensionStyleById (self.m_primaryDgnFileP), self.m_primaryDgnFileP))
        self.SetDimensionStyleById (self.m_primaryEtInstance, self.m_primaryDgnFileP)
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqDimensionStyleId (self.m_primaryEtInstance, self.GetOrCreateDimensionStyleById (self.m_primaryDgnFileP), self.m_primaryDgnFileP))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        self.AddDimensionStyleById (self.m_primaryEtInstance, self.m_primaryDgnFileP)

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True

    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def MaterialNameAndPaletteTest (self):
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\MaterialNameAndPaletteTest"))
        TestElementTemplateTestsFixture.AddMaterialNameAndPalette (self.m_primaryEtInstance, "Material", "Palette")
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqMaterialNameAndPalette (self.m_primaryEtInstance, "Material", "Palette"))
        TestElementTemplateTestsFixture.SetMaterialNameAndPalette (self.m_primaryEtInstance, "NotMaterial", "NotPalette")
        EXPECT_FALSE (TestElementTemplateTestsFixture.EqMaterialNameAndPalette (self.m_primaryEtInstance, "Material", "Palette"))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        TestElementTemplateTestsFixture.AddMaterialNameAndPalette (self.m_primaryEtInstance, "Material", "Palette")

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)
        return True


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def DetailSymbolStyleNameTest (self):
        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\DetailSymbolStyleNameTest"))
        TestElementTemplateTestsFixture.AddDetailSymbolStyleByName (self.m_primaryEtInstance, "DetailSymbolStyleName")
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqDetailSymbolStyleName (self.m_primaryEtInstance, "DetailSymbolStyleName"))
        TestElementTemplateTestsFixture.SetDetailSymbolStyleByName (self.m_primaryEtInstance, "NotDetailSymbolStyleName")
        EXPECT_FALSE (TestElementTemplateTestsFixture.EqDetailSymbolStyleName (self.m_primaryEtInstance, "DetailSymbolStyleName"))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        TestElementTemplateTestsFixture.AddDetailSymbolStyleByName (self.m_primaryEtInstance, "NewDetailSymbolStyleName")

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)
        return True

#===========================================================================================================================##/##
# ElementTemplateSymbologyTests                                                                                                   #
#                                                                                                                                 #
# @bsiclass                                                     Ping.Chen     04/2024                                           #
#                                                                                                                                 #
# Symbology Steps:                                                                                                                #
# 1) Create the Template                                             - TemplateCreate() Method                                    #
# 2) Write Values to Template                                        - TemplateAdd() Methods                                      #
# 3) Check to see if Template Exists                                 - TemplateExists() Method                                    #
# 4) Create the Element                                              - SymbologyCreate() Methods                                  #
# 5) Attach the Template to the Element and Apply Template Symbology - SymbologyApply() Methods                                   #
# 6) Extract the Symbology from Element                                                                                           #
# 7) Compare Symbology to Template using Direct Values               - TemplateEq() Methods                                       #
#===============*===============*===============*===============*===============*===============*===============*===============##/
class TestElementTemplateSymbologyTests (TestElementTemplateTestsFixture):
    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def CreateLineElement (eeh, model):
        global s_nLinesCreated

        segment = DSegment3d (0,0,0, 0,0,0)
        segment.point[1][0] += 10000
        segment.point[0][1] = segment.point[1][1] = s_nLinesCreated * 10000
        s_nLinesCreated += 1
        return LineHandler.CreateLineElement (eeh, None, segment, model.Is3d(), model)


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def CreateEllipseElement (eeh, model):
        global s_nEllipseCreated

        center = DPoint3d ()
        center.Init (10000.0, s_nEllipseCreated * 10000.0, 0)
        s_nEllipseCreated = s_nEllipseCreated * 1

        axis1 = 5000.0 
        axis2 = 3000.0 
        rotation = 0.0

        status = EllipseHandler.CreateEllipseElement(eeh, None, center, axis1, axis2, rotation, model.Is3d(), model)
        if(status != eSUCCESS):
            EXPECT_TRUE(False) # "EllipseHandler.CreateEllipseElement method failed."
            return ERROR

        #Check that a valid element is created.
        if(eeh == None):
            EXPECT_TRUE (False) # "Element is not valid which means Ellipse element is not created."
            return ERROR

        return eSUCCESS


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def EqElementColor (etInstance, expected, dgnFile, modelRef, index=0):
        retVal, actual = ElementTemplateParamsHelper.GetElementColor (modelRef, etInstance, index)
        EXPECT_TRUE (eETSTATUS_Success == retVal)
        return expected == actual


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def ApplyTemplateSymbology (self, eeh, templatePath = "TestGroup\\Default"):
        EXPECT_TRUE (eSUCCESS == eeh.AddToModel())

        elementRef = eeh.GetElementRef()

        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateUtils.SetReferencedTemplateID (eeh, self.m_primaryPElementTemplate.GetId(), True))

        eeh.ReplaceInModel(elementRef)

        actualTemplatePath = WString ()
        EXPECT_TRUE (eETSTATUS_Success == ElementTemplateUtils.GetPathForReferencedTemplate (actualTemplatePath, eeh.GetElementRef()))
        EXPECT_TRUE (templatePath == actualTemplatePath.GetWCharCP ())

        return True



    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def FillModeSymbologyTest (self, unfinished):
        ellipseEeh = EditElementHandle ()

        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\FillModeSymbologyTest"))
        TestElementTemplateTestsFixture.AddFillMode (self.m_primaryEtInstance, eFILLMODE_Outlined)
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        EXPECT_TRUE (eSUCCESS == TestElementTemplateSymbologyTests.CreateEllipseElement(ellipseEeh, self.m_defaultModel))
        EXPECT_TRUE (self.ApplyTemplateSymbology (ellipseEeh, "TestGroup\\FillModeSymbologyTest"))

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True

    
    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def AreaModeSymbologyTest (self, unfinished):
        lineEeh = EditElementHandle ()

        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\AreaModeSymbologyTest"))
        TestElementTemplateTestsFixture.AddAreaMode (self.m_primaryEtInstance, False)
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        EXPECT_TRUE (eSUCCESS == TestElementTemplateSymbologyTests.CreateLineElement (lineEeh, self.m_defaultModel))
        EXPECT_TRUE (self.ApplyTemplateSymbology (ellipseEeh, "TestGroup\\AreaModeSymbologyTest"))

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)
        return True

    
    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def TerminatorScaleSymbologyTest (self, unfinished):
        lineEeh = EditElementHandle () #Needs a cell!

        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\TerminatorScaleSymbologyTest"))
        TestElementTemplateTestsFixture.AddTerminatorScale (self.m_primaryEtInstance, 3.0)
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        EXPECT_TRUE (eSUCCESS == TestElementTemplateSymbologyTests.CreateLineElement (lineEeh, self.m_defaultModel))
        EXPECT_TRUE (self.ApplyTemplateSymbology (lineEeh, "TestGroup\\TerminatorScaleSymbologyTest"))

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)
        return True

    
    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def CellScaleSymbologyTest (self, unfinished):
        lineEeh = EditElementHandle () #Needs a cell!

        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\CellScaleSymbologyTest"))
        TestElementTemplateTestsFixture.AddCellScale (self.m_primaryEtInstance, DPoint3d(3.0, 1.0, 3.0))
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        EXPECT_TRUE (eSUCCESS == TestElementTemplateSymbologyTests.CreateLineElement (lineEeh, self.m_defaultModel))
        EXPECT_TRUE (self.ApplyTemplateSymbology (lineEeh, "TestGroup\\CellScaleSymbologyTest"))

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)
        return True

    
    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def CellNameSymbologyTest (self, unfinished):
        lineEeh = EditElementHandle () #Needs a cell!

        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\CellNameSymbologyTest"))
        TestElementTemplateTestsFixture.AddCellName (self.m_primaryEtInstance, "CellNameSymbologyTest")
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        EXPECT_TRUE (eSUCCESS == TestElementTemplateSymbologyTests.CreateLineElement (lineEeh, self.m_defaultModel))
        EXPECT_TRUE (self.ApplyTemplateSymbology (lineEeh, "TestGroup\\CellNameSymbologyTest"))

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)
        return True

    
    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def TextStyleNameSymbologyTest (self, unfinished):
        lineEeh = EditElementHandle () #I assume that a special element is needed for this.

        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\TextStyleNameSymbologyTest"))
        TestElementTemplateTestsFixture.AddTextStyleByName (self.m_primaryEtInstance, "TextStyleNameSymbologyTest")
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        EXPECT_TRUE (eSUCCESS == TestElementTemplateSymbologyTests.CreateLineElement (lineEeh, self.m_defaultModel))
        EXPECT_TRUE (self.ApplyTemplateSymbology (lineEeh, "TestGroup\\TextStyleNameSymbologyTest"))

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)
        return True

    
    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def MlineStyleNameSymbologyTest (self, unfinished):
        lineEeh = EditElementHandle () #I assume that a special element is needed for this.

        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\MlineStyleNameSymbologyTest"))
        TestElementTemplateTestsFixture.AddMlineStyleByName (self.m_primaryEtInstance, "MlineStyleNameSymbologyTest")
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        EXPECT_TRUE (eSUCCESS == TestElementTemplateSymbologyTests.CreateLineElement (lineEeh, self.m_defaultModel))
        EXPECT_TRUE (self.ApplyTemplateSymbology (lineEeh, "TestGroup\\MlineStyleNameSymbologyTest"))

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)
        return True

    
    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def DimensionStyleNameSymbologyTest (self, unfinished):

        lineEeh = EditElementHandle () #I assume that a special element is needed for this.

        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\DimensionStyleNameSymbologyTest"))
        TestElementTemplateTestsFixture.AddDimensionStyleByName (self.m_primaryEtInstance, "DimensionStyleNameSymbologyTest")
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        EXPECT_TRUE (eSUCCESS == TestElementTemplateSymbologyTests.CreateLineElement (lineEeh, self.m_defaultModel))
        EXPECT_TRUE (self.ApplyTemplateSymbology (lineEeh, "TestGroup\\DimensionStyleNameSymbologyTest"))

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)
        return True

    
    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def LineStyleNameSymbologyTest (self, unfinished):

        lineEeh = EditElementHandle ()

        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\LineStyleNameSymbologyTest"))
        TestElementTemplateTestsFixture.AddLineStyleByName (self.m_primaryEtInstance, "LineStyleNameSymbologyTest")
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        EXPECT_TRUE (eSUCCESS == TestElementTemplateSymbologyTests.CreateLineElement (lineEeh, self.m_defaultModel))
        EXPECT_TRUE (self.ApplyTemplateSymbology (lineEeh, "TestGroup\\LineStyleNameSymbologyTest"))

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)
        return True

    
    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def TransparencySymbologyTest (self):
        lineEeh = EditElementHandle ()

        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\TransparencySymbologyTest"))
        TestElementTemplateTestsFixture.AddTransparency (self.m_primaryEtInstance, 50)   #  beteen 0.0 - 100.0
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        EXPECT_TRUE (eSUCCESS == TestElementTemplateSymbologyTests.CreateLineElement (lineEeh, self.m_defaultModel))
        EXPECT_TRUE (self.ApplyTemplateSymbology (lineEeh, "TestGroup\\TransparencySymbologyTest"))
        propQuery = ElementPropertiesGetter (lineEeh)      # transparency returned in 0.0 . 1.0 
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqTransparency (self.m_primaryEtInstance, propQuery.GetTransparency ()* 100.0))

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True

    
    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def PrioritySymbologyTest (self):
        if (self.m_defaultModel.Is3d()):
            return True

        lineEeh = EditElementHandle ()

        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\PrioritySymbologyTest"))
        TestElementTemplateTestsFixture.AddPriority (self.m_primaryEtInstance, 250)
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        EXPECT_TRUE (eSUCCESS == TestElementTemplateSymbologyTests.CreateLineElement (lineEeh, self.m_defaultModel))
        EXPECT_TRUE (self.ApplyTemplateSymbology (lineEeh, "TestGroup\\PrioritySymbologyTest"))
        propQuery = ElementPropertiesGetter (lineEeh)
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqPriority (self.m_primaryEtInstance, propQuery.GetDisplayPriority ()))

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)

        return True

    
    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def ClassSymbologyTest (self):
        lineEeh = EditElementHandle ()

        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\ClassSymbologyTest"))
        TestElementTemplateTestsFixture.AddElementClass (self.m_primaryEtInstance, DgnElementClass.ePrimary)
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        EXPECT_TRUE (eSUCCESS == TestElementTemplateSymbologyTests.CreateLineElement (lineEeh, self.m_defaultModel))
        EXPECT_TRUE (self.ApplyTemplateSymbology (lineEeh, "TestGroup\\ClassSymbologyTest"))
        propQuery = ElementPropertiesGetter (lineEeh)
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqElementClass (self.m_primaryEtInstance, propQuery.GetElementClass ()))

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)
        return True

    
    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def WeightSymbologyTest (self):
        lineEeh = EditElementHandle ()

        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\WeightSymbologyTest"))
        TestElementTemplateTestsFixture.AddLineWeight (self.m_primaryEtInstance, 3)
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        EXPECT_TRUE (eSUCCESS == TestElementTemplateSymbologyTests.CreateLineElement (lineEeh, self.m_defaultModel))
        EXPECT_TRUE (self.ApplyTemplateSymbology (lineEeh, "TestGroup\\WeightSymbologyTest"))
        propQuery = ElementPropertiesGetter (lineEeh)
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqLineWeight (self.m_primaryEtInstance, propQuery.GetWeight ()))

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)
        return True

    
    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def LevelSymbologyTest (self):
        lineEeh = EditElementHandle ()

        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\LevelSymbologyTest"))
        self.AddLevelById (self.m_primaryEtInstance, self.m_primaryDgnFileP)
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        EXPECT_TRUE (eSUCCESS == TestElementTemplateSymbologyTests.CreateLineElement (lineEeh, self.m_defaultModel))
        EXPECT_TRUE (self.ApplyTemplateSymbology (lineEeh, "TestGroup\\LevelSymbologyTest"))
        propQuery = ElementPropertiesGetter (lineEeh)
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqLevelId (self.m_primaryEtInstance, propQuery.GetLevel (), self.m_defaultModel))

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)
        return True

    
    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def MaterialSymbologyTest (self, unfinished):
        lineEeh = EditElementHandle ()

        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\MaterialSymbologyTest"))
        TestElementTemplateTestsFixture.AddMaterialNameAndPalette (self.m_primaryEtInstance, "MaterialSymbologyTest", "PaletteSymbologyTest")
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        EXPECT_TRUE (eSUCCESS == TestElementTemplateSymbologyTests.CreateLineElement (lineEeh, self.m_defaultModel))
        EXPECT_TRUE (self.ApplyTemplateSymbology (lineEeh, "TestGroup\\MaterialSymbologyTest"))

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)
        return True

    
    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def LineStyleParamsSymbologyTest (self, unfinished):
        lineEeh = EditElementHandle ()

        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\LineStyleParamsSymbologyTest"))
        TestElementTemplateTestsFixture.AddLineStyleParams (self.m_primaryEtInstance, self.CreateLineStyleParams (), self.m_defaultModel)
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        EXPECT_TRUE (eSUCCESS == TestElementTemplateSymbologyTests.CreateLineElement (lineEeh, self.m_defaultModel))
        EXPECT_TRUE (self.ApplyTemplateSymbology (lineEeh, "TestGroup\\LineStyleParamsSymbologyTest"))

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)
        return True

    
    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def ElementColorSymbologyTest (self):
        lineEeh = EditElementHandle ()

        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\ColorSymbologyTest"))
        TestElementTemplateTestsFixture.AddElementColor (self.m_primaryEtInstance, IntColorDef(230, 10, 0, 0), self.m_primaryDgnFileP)
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        EXPECT_TRUE (eSUCCESS == TestElementTemplateSymbologyTests.CreateLineElement (lineEeh, self.m_defaultModel))
        EXPECT_TRUE (self.ApplyTemplateSymbology (lineEeh, "TestGroup\\ColorSymbologyTest"))
        propQuery = ElementPropertiesGetter (lineEeh)
        EXPECT_TRUE (TestElementTemplateTestsFixture.EqElementColor (self.m_primaryEtInstance, propQuery.GetColor (), self.m_primaryDgnFileP, self.m_defaultModel))

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)
        return True

    
    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def ElementFillColorSymbologyTest (self, unfinished):
        ellipseEeh = EditElementHandle ()

        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\ElementFillColorSymbologyTest"))
        TestElementTemplateTestsFixture.AddSolidFillColor (self.m_primaryEtInstance, IntColorDef(230, 10, 0, 0), self.m_primaryDgnFileP)
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        EXPECT_TRUE (eSUCCESS == TestElementTemplateSymbologyTests.CreateEllipseElement(ellipseEeh, self.m_defaultModel))
        EXPECT_TRUE (self.ApplyTemplateSymbology (ellipseEeh, "TestGroup\\ElementFillColorSymbologyTest"))

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)
        return True

    
    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def ActivePointSymbologyTest (self, unfinished):
        lineEeh = EditElementHandle ()

        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\ActivePointSymbologyTest"))
        TestElementTemplateTestsFixture.AddActivePointSpecification (self.m_primaryEtInstance, eACTIVEPOINTTYPE_ZeroLengthLine, "Ignored String")
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        EXPECT_TRUE (eSUCCESS == TestElementTemplateSymbologyTests.CreateLineElement (lineEeh, self.m_defaultModel))
        EXPECT_TRUE (self.ApplyTemplateSymbology (lineEeh, "TestGroup\\ActivePointSymbologyTest"))

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)
        return True

    
    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def TextParamsAndScaleSymbologyTest (self, unfinished):
        lineEeh = EditElementHandle ()

        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\TextParamsAndScaleSymbologyTest"))

        textScale = DPoint2d(1.0, 2.0)

        self.AddTextStyleOverride (self.m_primaryEtInstance, self.CreateTextStyleOverrideParams(textScale), textScale)
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        EXPECT_TRUE (eSUCCESS == TestElementTemplateSymbologyTests.CreateLineElement (lineEeh, self.m_defaultModel))
        EXPECT_TRUE (self.ApplyTemplateSymbology (lineEeh, "TestGroup\\TextParamsAndScaleSymbologyTest"))

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)
        return True

    
    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def PatternCellSymbologyTest (self, unfinished):
        lineEeh = EditElementHandle ()

        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\PatternCellSymbologyTest"))
        TestElementTemplateTestsFixture.AddElementColor (self.m_primaryEtInstance, IntColorDef(230, 10, 0, 0), self.m_primaryDgnFileP)
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        EXPECT_TRUE (eSUCCESS == TestElementTemplateSymbologyTests.CreateLineElement (lineEeh, self.m_defaultModel))
        EXPECT_TRUE (self.ApplyTemplateSymbology (lineEeh, "TestGroup\\PatternCellSymbologyTest"))

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)
        return True


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def XHatchSymbologyTest (self, unfinished):
        lineEeh = EditElementHandle ()

        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\XHatchSymbologyTest"))
        TestElementTemplateTestsFixture.AddElementColor (self.m_primaryEtInstance, IntColorDef(230, 10, 0, 0), self.m_primaryDgnFileP)
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        EXPECT_TRUE (eSUCCESS == TestElementTemplateSymbologyTests.CreateLineElement (lineEeh, self.m_defaultModel))
        EXPECT_TRUE (self.ApplyTemplateSymbology (lineEeh, "TestGroup\\XHatchSymbologyTest"))

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)
        return True


    #---------------------------------------------------------------------------------##/##
    # @bsimethod                                    Ping.Chen                     04/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def DetailSymbolStyleSymbologyTest (self, unfinished):
        lineEeh = EditElementHandle ()

        EXPECT_TRUE (self.CreatePrimaryTemplate ("TestGroup\\DetailSymbolStyleSymbologyTest"))
        TestElementTemplateTestsFixture.AddDetailSymbolStyleByName (self.m_primaryEtInstance, "DetailSymbolStyleSymbologyTest")
        EXPECT_TRUE (self.PrimaryTemplateExists ())
        EXPECT_TRUE (eSUCCESS == TestElementTemplateSymbologyTests.CreateLineElement (lineEeh, self.m_defaultModel))
        EXPECT_TRUE (self.ApplyTemplateSymbology (lineEeh, "TestGroup\\DetailSymbolStyleSymbologyTest"))

        ElementTemplateUtils.DeleteFromFile (self.m_primaryPElementTemplate)
        return True

    #===========================================================================================================================##/##
    # ExerciseTemplateTest                                                                                                            #
    #                                                                                                                                 #
    # @bsiclass                                                     Ping.Chen     04/2024                                           #
    #                                                                                                                                 #
    # Template Steps:                                                                                                                 #
    # 1) Create the Template                       - TemplateCreate() Method                                                          #
    # 2) Write Values to Template                  - TemplateAdd() Methods                                                            #
    # 3) Compare Expected to Actual for Equality   - TemplateEq() Methods                                                             #
    # 4) Set Change Values in Template             - TemplateSet() Methods                                                            #
    # 5) Compare Expected to Actual for Inequality - TemplateEq() Methods                                                             #
    # 6) Check to see if Template Exists           - TemplateExists() Method                                                          #
    # 7) Write Extra Values to Template            - TemplateAdd() Methods                                                            #
    #===============*===============*===============*===============*===============*===============*===============*===============##/
    def test_ElementTemplateTests_ExerciseTemplateTest (self):       
        EXPECT_TRUE (self.LevelNameTest ())
        EXPECT_TRUE (self.LevelIdTest ())
        EXPECT_TRUE (self.ElementColorTest ())
        EXPECT_TRUE (self.LineWeightTest ())
        EXPECT_TRUE (self.LineStyleNameTest ())
        EXPECT_TRUE (self.LineStyleIdTest ())
        EXPECT_TRUE (self.LineStyleParamsTest ())
        EXPECT_TRUE (self.ElementClassTest ())
        EXPECT_TRUE (self.TransparencyTest ())
        EXPECT_TRUE (self.PriorityTest ())
        EXPECT_TRUE (self.AreaModeTest ())
        EXPECT_TRUE (self.SolidFillColorTest ())
        EXPECT_TRUE (self.GradientFillColorTest ())
        EXPECT_TRUE (self.FillModeTest ())
        EXPECT_TRUE (self.CellNameTest ())
        EXPECT_TRUE (self.CellScaleTest ())
        EXPECT_TRUE (self.TerminatorCellNameTest ())
        EXPECT_TRUE (self.TerminatorScaleTest ())
        EXPECT_TRUE (self.ActivePointSpecificationTest ())
        EXPECT_TRUE (self.TextStyleNameTest ())
        EXPECT_TRUE (self.TextStyleIdTest ())
        EXPECT_TRUE (self.TextStyleOverrideTest ())
        EXPECT_TRUE (self.PatternCellNameTest ())
        EXPECT_TRUE (self.PatternDeltaValuesTest ())
        EXPECT_TRUE (self.PatternAngleTest ())
        EXPECT_TRUE (self.PatternScaleTest ())
        EXPECT_TRUE (self.HatchDeltaValuesTest ())
        EXPECT_TRUE (self.HatchAngleValuesTest ())
        EXPECT_TRUE (self.MlineStyleNameTest ())
        EXPECT_TRUE (self.MlineStyleIdTest ())
        EXPECT_TRUE (self.DimensionStyleNameTest ())
        EXPECT_TRUE (self.DimensionStyleIdTest ())
        EXPECT_TRUE (self.MaterialNameAndPaletteTest ())
        #EXPECT_TRUE (MaterialIdTest ())
        EXPECT_TRUE (self.DetailSymbolStyleNameTest ())
    

    #===========================================================================================================================##/##
    # ExerciseSymbologyTest                                                                                                           #
    #                                                                                                                                 #
    # @bsiclass                                                     Ping.Chen     04/2024                                           #
    #                                                                                                                                 #
    # Symbology Steps:                                                                                                                #
    # 1) Create the Template                                             - TemplateCreate() Method                                    #
    # 2) Write Values to Template                                        - TemplateAdd() Methods                                      #
    # 3) Check to see if Template Exists                                 - TemplateExists() Method                                    #
    # 4) Create the Element                                              - SymbologyCreate() Methods                                  #
    # 5) Attach the Template to the Element and Apply Template Symbology - SymbologyApply() Methods                                   #
    # 6) Extract the Symbology from Element                                                                                           #
    # 7) Compare Symbology to Template using Direct Values               - TemplateEq() Methods                                       #
    #===============*===============*===============*===============*===============*===============*===============*===============##/
    def test_ElementTemplateSymbologyTests_ExerciseSymbologyTest (self):
    #ifdef NOT_FINISHED
        # EXPECT_TRUE (self.FillModeSymbologyTest (True))
        # EXPECT_TRUE (self.AreaModeSymbologyTest (True))
        # EXPECT_TRUE (self.TerminatorScaleSymbologyTest (True))
        # EXPECT_TRUE (self.CellScaleSymbologyTest (True))
        # EXPECT_TRUE (self.CellNameSymbologyTest (True))
        # EXPECT_TRUE (self.TextStyleNameSymbologyTest (True))
        # EXPECT_TRUE (self.MlineStyleNameSymbologyTest (True))
        # EXPECT_TRUE (self.DimensionStyleNameSymbologyTest (True))
        # EXPECT_TRUE (self.LineStyleNameSymbologyTest (True))
    #endif
        EXPECT_TRUE (self.TransparencySymbologyTest ())
        EXPECT_TRUE (self.PrioritySymbologyTest ())
        EXPECT_TRUE (self.ClassSymbologyTest ())
        EXPECT_TRUE (self.WeightSymbologyTest ())
        EXPECT_TRUE (self.LevelSymbologyTest ())
    #ifdef NOT_FINISHED
        # EXPECT_TRUE (self.MaterialSymbologyTest (True))
        # EXPECT_TRUE (self.LineStyleParamsSymbologyTest (True))
        # EXPECT_TRUE (self.ElementColorSymbologyTest ())
        # EXPECT_TRUE (self.ElementFillColorSymbologyTest (True))
        # EXPECT_TRUE (self.ActivePointSymbologyTest (True))
        # EXPECT_TRUE (self.TextParamsAndScaleSymbologyTest (True))
        # EXPECT_TRUE (self.PatternCellSymbologyTest (True))
        # EXPECT_TRUE (self.XHatchSymbologyTest (True))
        # EXPECT_TRUE (self.DetailSymbolStyleSymbologyTest (True))
    #endif
