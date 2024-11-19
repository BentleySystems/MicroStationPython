##--------------------------------------------------------------------------------------+
#
# $Source: \MSPythonTests\PlatformTests\PublishedTests\DgnPlatformTest\CopyContext_Test.py $
#
# $Copyright: (c) 2013 Bentley Systems, Incorporated. All rights reserved. $
#
#--------------------------------------------------------------------------------------#/
import os
import pytest
from abc import ABC, abstractmethod
from enum import Enum
import ctypes
import re

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from util import *
from conftest import *

srcDgnFileName = '3dMetricGeneral.dgn'
detDgnFileName = '2dMetricGeneral.dgn'

##=================================================================================##/###
#@bsiclass                                                     Ping.Chen  05/2024
#===============#===============#===============#===============#===============#======#/
class CopyContextTestBase (IQueryProperties):
    #@abstractmethod
    def _PrepareSource (self):  #Setup source color table, levels, etc.
        pass

    #@abstractmethod
    def _PrepareDestination (self):  #Setup destination color table, levels, etc.
        pass

    #@abstractmethod
    def _InitCopyOptions (self, copyContext):  #Change default copy options...
        pass

    #@abstractmethod
    def _CreateSourceElements (self): #Create elements to be added to source file and copied...
        pass

    #@abstractmethod
    def _ValidateElement (self, eh): #Inspect copy for expected result...
        pass

    def loadDgnFileByFileName (fileName):
        dataDir = os.environ['MSPYTESTDATA']
        ret = DgnDocument.CreateFromFileName (fileName, dataDir, -101, DgnDocument.FetchMode.eWrite)

        if (ret[1] != DgnFileStatus.eDGNFILE_STATUS_Success):
            assert False

        dgnFile = DgnFile (ret[0], DgnFileOpenMode.eReadWrite)
        dgnFile.LoadDgnFile ()
        dgnFile.FillDictionaryModel ()

        return dgnFile

    #def loadDgnModel (self, dgnFileName):
    #    self.dgnFile = CopyContextTestBase.loadDgnFileByFileName (dgnFileName)
    #    self.model, retVal = self.dgnFile.LoadRootModelById (self.dgnFile.DefaultModelId, True)

    def GetDgnModel (self):
        return self.model

    def GetDgnFile (self):
        return self.dgnFile

    def __init__ (self):
        DgnPlatformFixture_Initialize ()
        super ().__init__ ()


    def __del__ (self):
        pass


    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def init (self, srcIs3d, dstIs3d, sameFile):
        #Different source/destintation models...could be in same file or different files...
        srcSeedFile = CopyContextTestBase.loadDgnFileByFileName ("3dMetricGeneral.dgn")
        self.m_srcTDM = createTempDgnFileFromSeedFile (srcSeedFile)

        if sameFile:
            self.m_dstTDM = self.m_srcTDM
        else:
            destSeedFile = CopyContextTestBase.loadDgnFileByFileName ("2dMetricGeneral.dgn")
            self.m_dstTDM = createTempDgnFileFromSeedFile (destSeedFile)  #CopyContextTestBase.loadDgnFileByFileName ("2dMetricGeneral.dgn")

        EXPECT_EQ (True, None != self.m_srcTDM) #"Failed to create source file.\n"
        EXPECT_EQ (True, None != self.m_dstTDM) #"Failed to create destination file.\n"

        self.m_srcModel, ret = self.m_srcTDM.CreateNewModel ("ModelS", DgnModelType.eNormal, srcIs3d)
        self.m_dstModel, ret = self.m_dstTDM.CreateNewModel ("ModelD", DgnModelType.eNormal, dstIs3d)

        EXPECT_EQ (True, None != self.m_srcModel) #"Failed to create source model.\n"
        EXPECT_EQ (True, None != self.m_dstModel) #"Failed to create destination model.\n"

        self.m_isSetup = False

        self.m_agenda = ElementAgenda ()

    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def CreateDefaultTestElements (self):
        eeh = EditElementHandle ()

        #Create simple open element...
        ASSERT_TRUE (eSUCCESS == LineHandler.CreateLineElement (eeh, None, DSegment3d (0, 0, 0, 0, 0, 0), self.m_srcModel.Is3d (), self.m_srcModel))
        self.m_agenda.Insert (eeh)

        #Create simple closed element...
        ASSERT_TRUE (eSUCCESS == EllipseHandler.CreateEllipseElement (eeh, None, DEllipse3d.From (0, 0, 0, 1, 0, 0, 0, 1, 0, 0, msGeomConst_2pi), self.m_srcModel.Is3d (), self.m_srcModel))
        self.m_agenda.Insert (eeh)

        #Create complex element with public children...
        groupAgenda = ElementAgenda  ()

        ASSERT_TRUE (eSUCCESS == LineHandler.CreateLineElement (eeh, None, DSegment3d (0, 0, 0, 0, 0, 0), self.m_srcModel.Is3d (), self.m_srcModel))
        groupAgenda.Insert (eeh)

        ASSERT_TRUE (eSUCCESS == EllipseHandler.CreateEllipseElement (eeh, None, DEllipse3d.From (0, 0, 0, 1, 0, 0, 0, 1, 0, 0, msGeomConst_2pi), self.m_srcModel.Is3d (), self.m_srcModel))
        groupAgenda.Insert (eeh)

        ASSERT_TRUE (eSUCCESS == NormalCellHeaderHandler.CreateGroupCellElement (eeh, groupAgenda))
        self.m_agenda.Insert (eeh)

        #Create complex element with private children...
        holeAgenda = ElementAgenda ()
        solidEeh = EditElementHandle ()

        ASSERT_TRUE (eSUCCESS == EllipseHandler.CreateEllipseElement (solidEeh, None, DEllipse3d.From (0, 0, 0, 2, 0, 0, 0, 2, 0, 0, msGeomConst_2pi), self.m_srcModel.Is3d (), self.m_srcModel))
        ASSERT_TRUE (eSUCCESS == EllipseHandler.CreateEllipseElement (eeh, None, DEllipse3d.From (0, 0, 0, 1, 0, 0, 0, 1, 0, 0, msGeomConst_2pi), self.m_srcModel.Is3d (), self.m_srcModel))
        holeAgenda.Insert (eeh)

        ASSERT_TRUE (eSUCCESS == GroupedHoleHandler.CreateGroupedHoleElement (eeh, solidEeh, holeAgenda))
        self.m_agenda.Insert (eeh)

        #Create text element...
        textBlock = TextBlock (self.m_srcModel)

        textBlock.AppendText ("Hello!")
        ASSERT_TRUE (eSUCCESS == TextHandlerBase.CreateElement (eeh, None, textBlock))
        self.m_agenda.Insert (eeh)


    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def WriteSourceElements (self, remapper):
        for curr in self.m_agenda:
            if (False == curr.IsValid ()):
                continue

            if (remapper):
                remapper.Apply (curr)

            curr.AddToModel ()


    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def DoCopyTest (self):
        #Only want to call these once...in case of repeated tests...
        if (False == self.m_isSetup):    
            self._PrepareSource () #Make sure source/destination are setup...
            self._PrepareDestination ()
            self.m_isSetup = True

        self.m_agenda.Empty () #Empty in case of multiple copy test using same source and destination...

        self._CreateSourceElements ()
        EXPECT_EQ (False, self.m_agenda.IsEmpty ()) #"Failed to create source element(s).\n"

        copier = ElementCopyContext (self.m_dstModel)      #Bentley.DgnPlatform. required for VS2012
        self._InitCopyOptions (copier)

        for curr in self.m_agenda:
            if (False == curr.IsValid ()):
                continue

            EXPECT_EQ (eSUCCESS, copier.DoCopy (curr)) #"Failed to copy element.\n"


        DependencyManager.ProcessAffected () #Finish dependency id remap...

        for curr in self.m_agenda:
            if (False == curr.IsValid ()):
                continue

            EXPECT_EQ (self.m_dstModel, curr.GetModelRef ().GetDgnModel ()) #"Failed copied element validation.\n"
            self._ValidateElement (curr)


##=================================================================================##/###
#Test color remap when elements are copied between files with different color tables.
#@bsiclass                                                     Ping.Chen  05/2024
#===============#===============#===============#===============#===============#======#/
class CopyContextTestColorRemap (CopyContextTestBase):
    class TstType (Enum):
        TABLE_INDEX_Same = 0,           #! RGB of color table index is the same in both source/destination.
        TABLE_INDEX_Different = 1,      #! RGB of color table index is different in source/destination.
        TABLE_INDEX_Background = 2,     #! Test that background color index is never changed.

        EXTENDED_INDEX_Same = 3,        #! RGB for extended color exists in source/destination, closest 0-255 match required remap.
        EXTENDED_INDEX_Different = 4,   #! RGB for extended color exists with different extended index in source/destination.
        EXTENDED_INDEX_New = 5,         #! RGB for extended color only exists in source.

        EXTENDED_BOOK_Same = 6,         #! RGB for book color exists in source/destination at same extended index.
        EXTENDED_BOOK_Different = 7,    #! RGB for book color exists with different book name in source/destination.
        EXTENDED_BOOK_New = 8,          #! RGB for book color only exists in source.

    class TstColorId (Enum):
        COLORID_Black = 0,
        COLORID_White = 1,
        COLORID_Red = 2,
        COLORID_Green = 3,
        COLORID_Blue = 4,
        COLORID_Cyan = 5,
        COLORID_Magenta = 6,
        COLORID_Yellow = 7,
        COLORID_DarkGrey = 8,
        COLORID_MediumGrey = 9,
        COLORID_Violet = 10,

    def __init__ (self):
        super ().__init__ ()
        self.init (True, True, False)
        self.m_colorTest = CopyContextTestColorRemap.TstType.TABLE_INDEX_Same
        self.m_preserveTableIndex = True


    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def GetTestColor (id):
        s_rgbColors =[
            0x000000,   #black    = 0
            0xFFFFFF,   #white    = 1
            0x0000FF,   #red      = 2
            0x00FF00,   #green    = 3
            0xFF0000,   #blue     = 4
            0xFFFF00,   #cyan     = 5
            0xFF00FF,   #magenta  = 6
            0x00FFFF,   #yellow   = 7
            0x555555,   #dgrey    = 8
            0x888888,   #mgrey    = 9
            0x800080,   #violet   = 10
            ]

        return s_rgbColors[id.value[0]]


    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def _PrepareSource (self):
        colorMap = DgnColorMap.GetForFile (self.m_srcModel.GetDgnFile ())

        #Setup some known color indices with rgb mis-match...
        colorMap.GetTbgrColors ()[0]   = CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Red)
        colorMap.GetTbgrColors ()[1]   = CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Green)
        colorMap.GetTbgrColors ()[2]   = CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Blue)

        #Setup a couple common entries for preserving index during closest rgb remap...
        colorMap.GetTbgrColors ()[3]   = CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Violet)
        colorMap.GetTbgrColors ()[4]   = CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Violet)

        #Create some known rgb values so we can test for exact match with extended color's "closest" match index...
        colorMap.GetTbgrColors ()[5]   = CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Cyan)
        colorMap.GetTbgrColors ()[6]   = CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Yellow)
        colorMap.GetTbgrColors ()[7]   = CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Magenta)

        #setup different background colors...
        colorMap.GetTbgrColors ()[255] = CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_MediumGrey)

        colorMap.SetForFile (self.m_srcModel.GetDgnFile (), "")

        #Create some common rgb colors ahead of time to control extended color index...
        colorMap.CreateElementColor (IntColorDef (CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Red)),    None, None, self.m_srcModel.GetDgnFile ())
        colorMap.CreateElementColor (IntColorDef (CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Green)),  None, None, self.m_srcModel.GetDgnFile ())
        colorMap.CreateElementColor (IntColorDef (CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Blue)),   None, None, self.m_srcModel.GetDgnFile ())
 
        #Create some named rgb colors...
        colorMap.CreateElementColor (IntColorDef (CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Cyan)),   "BOOK1", "CYAN",   self.m_srcModel.GetDgnFile ())
        colorMap.CreateElementColor (IntColorDef (CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Yellow)), "BOOK1", "YELLOW", self.m_srcModel.GetDgnFile ())

        #Create rgb/book colors that only exist in source...
        colorMap.CreateElementColor (IntColorDef (CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Violet)), None, None, self.m_srcModel.GetDgnFile ())
        colorMap.CreateElementColor (IntColorDef (CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Magenta)), "BOOK1", "MAGENTA", self.m_srcModel.GetDgnFile ())


    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def _PrepareDestination (self):
        colorMap = DgnColorMap.GetForFile (self.m_dstModel.GetDgnFile ())

        #Setup some known color indices with rgb mis-match...
        colorMap.GetTbgrColors ()[0]   = CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Green)
        colorMap.GetTbgrColors ()[1]   = CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Blue)
        colorMap.GetTbgrColors ()[2]   = CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Red)

        #Setup a couple common entries for preserving index during closest rgb remap...
        colorMap.GetTbgrColors ()[3]   = CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Violet)
        colorMap.GetTbgrColors ()[4]   = CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Violet)

        #Create some known rgb values so we can test for exact match with extended color's "closest" match index...
        colorMap.GetTbgrColors ()[5]   = CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Cyan)
        colorMap.GetTbgrColors ()[6]   = CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Yellow)
        colorMap.GetTbgrColors ()[7]   = CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Magenta)

        #setup different background colors...
        colorMap.GetTbgrColors ()[255] = CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_DarkGrey)

        colorMap.SetForFile (self.m_dstModel.GetDgnFile (), "")

        #Create some common rgb colors ahead of time to control extended color index...
        colorMap.CreateElementColor (IntColorDef (CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Red)),   None, None, self.m_dstModel.GetDgnFile ())
        colorMap.CreateElementColor (IntColorDef (CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Blue)),  None, None, self.m_dstModel.GetDgnFile ())
        colorMap.CreateElementColor (IntColorDef (CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Green)), None, None, self.m_dstModel.GetDgnFile ())

        #Create some named rgb colors...
        colorMap.CreateElementColor (IntColorDef (CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Cyan)),   "BOOK1", "CYAN",   self.m_srcModel.GetDgnFile ())
        colorMap.CreateElementColor (IntColorDef (CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Yellow)), "BOOK2", "YELLOW", self.m_srcModel.GetDgnFile ())


    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def _InitCopyOptions (self, copyContext):
        copyContext.SetKeepRefColorIndexOnCopy (self.m_preserveTableIndex)


    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def _CreateSourceElements (self):
        remapper = ElementPropertiesSetter ()

        remapper.SetChangeEntireElement (True)
        remapper.SetColor (self.GetSourceElementColor ())

        self.CreateDefaultTestElements ()
        self.WriteSourceElements (remapper)


    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def GetSourceElementColor (self):
        if self.m_colorTest == CopyContextTestColorRemap.TstType.TABLE_INDEX_Same:
            return 4
        elif self.m_colorTest == CopyContextTestColorRemap.TstType.TABLE_INDEX_Different:
            return 0
        elif self.m_colorTest ==  CopyContextTestColorRemap.TstType.TABLE_INDEX_Background:
            return 255
        elif self.m_colorTest ==  CopyContextTestColorRemap.TstType.EXTENDED_INDEX_Same:
            return DgnColorMap.GetForFile (self.m_srcModel.GetDgnFile ()).CreateElementColor (IntColorDef (CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Red)),     None, None, self.m_srcModel.GetDgnFile ())
        elif self.m_colorTest ==  CopyContextTestColorRemap.TstType.EXTENDED_INDEX_Different:
            return DgnColorMap.GetForFile (self.m_srcModel.GetDgnFile ()).CreateElementColor (IntColorDef (CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Green)),   None, None, self.m_srcModel.GetDgnFile ())
        elif self.m_colorTest ==  CopyContextTestColorRemap.TstType.EXTENDED_INDEX_New:
            return DgnColorMap.GetForFile (self.m_srcModel.GetDgnFile ()).CreateElementColor (IntColorDef (CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Violet)),  None, None, self.m_srcModel.GetDgnFile ())
        elif self.m_colorTest == CopyContextTestColorRemap.TstType.EXTENDED_BOOK_Same:
            return DgnColorMap.GetForFile (self.m_srcModel.GetDgnFile ()).CreateElementColor (IntColorDef (CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Cyan)),    None, None, self.m_srcModel.GetDgnFile ())
        elif self.m_colorTest == CopyContextTestColorRemap.TstType.EXTENDED_BOOK_Different:
            return DgnColorMap.GetForFile (self.m_srcModel.GetDgnFile ()).CreateElementColor (IntColorDef (CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Yellow)),  None, None, self.m_srcModel.GetDgnFile ())
        elif self.m_colorTest == CopyContextTestColorRemap.TstType.EXTENDED_BOOK_New:
            return DgnColorMap.GetForFile (self.m_srcModel.GetDgnFile ()).CreateElementColor (IntColorDef (CopyContextTestColorRemap.GetTestColor (CopyContextTestColorRemap.TstColorId.COLORID_Magenta)), None, None, self.m_srcModel.GetDgnFile ())
        else:
            return 4    #same as CopyContextTestColorRemap.TstType.TABLE_INDEX_Same


    ##----------------------------------------------------------------------------------#/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def _EachColorCallback (self, arg):
        if (0 != (arg.GetPropertyFlags () and PROPSCALLBACK_FLAGS_ElementIgnoresID)):
            return

        srcColorMap = DgnColorMap.GetForFile (self.m_srcModel.GetDgnFile ())
        ASSERT_TRUE (None != srcColorMap)
        srcStatus = srcColorMap.ExtractElementColorInfo (srcColorDef, srcColorIndex, srcIsTrueColor, srcBookName, srcEntryName, self.GetSourceElementColor (), self.m_srcModel.GetDgnFile ())
        EXPECT_EQ (eSUCCESS, srcStatus)

        dstColorMap = DgnColorMap.GetForFile (self.m_dstModel.GetDgnFile ())
        ASSERT_TRUE (None != dstColorMap)
        dstStatus = dstColorMap.ExtractElementColorInfo (dstColorDef, dstColorIndex, dstIsTrueColor, dstBookName, dstEntryName, arg.GetStoredValue (), self.m_dstModel.GetDgnFile ())
        EXPECT_EQ (eSUCCESS, dstStatus)

        EXPECT_EQ (srcIsTrueColor, dstIsTrueColor) #Expect color to remain either color table index or extended index...

        if self.m_colorTest == CopyContextTestColorRemap.TstType.TABLE_INDEX_Same:
            EXPECT_EQ (dstIsTrueColor, False)
            EXPECT_EQ (srcColorIndex, dstColorIndex) #Expect index to be preserved...
            EXPECT_EQ (srcColorDef.m_int, dstColorDef.m_int) #Expect rgb to be the same...

        if self.m_colorTest ==  CopyContextTestColorRemap.TstType.TABLE_INDEX_Different:
            EXPECT_EQ (dstIsTrueColor, False)
            if (self.m_preserveTableIndex):
            
                EXPECT_EQ (srcColorIndex, dstColorIndex) #Expect index to be preserved...
                EXPECT_NE (srcColorDef.m_int, dstColorDef.m_int) #Expect rgb to be different...            
            else:
                EXPECT_NE (srcColorIndex, dstColorIndex) #Expect index to be different...
                EXPECT_EQ (srcColorDef.m_int, dstColorDef.m_int) #Expect rgb to be the same...

        if self.m_colorTest ==  CopyContextTestColorRemap.TstType.TABLE_INDEX_Background:
            EXPECT_EQ (dstIsTrueColor, False)
            EXPECT_EQ (srcColorIndex, dstColorIndex) #Expect index to be preserved...
            EXPECT_NE (srcColorDef.m_int, dstColorDef.m_int) #Expect rgb to be different...

        if self.m_colorTest ==  CopyContextTestColorRemap.TstType.EXTENDED_BOOK_Same or self.m_colorTest ==  CopyContextTestColorRemap.TstType.EXTENDED_BOOK_Different or self.m_colorTest == CopyContextTestColorRemap.TstType.EXTENDED_BOOK_New:
            EXPECT_STREQ (srcBookName, dstBookName)
            EXPECT_STREQ (srcEntryName, dstEntryName)
            #Fall through...

            EXPECT_EQ (dstIsTrueColor, True)
            EXPECT_EQ (srcColorDef.m_int, dstColorDef.m_int) #Expect rgb to be the same always...

            closeColorDef = IntColorDef ()
            EXPECT_EQ (eSUCCESS, dstColorMap.ExtractElementColorInfo (closeColorDef, None, None, None, None, dstColorIndex, self.m_dstModel.GetDgnFile ()))
            EXPECT_EQ (closeColorDef.m_int, dstColorDef.m_int) #Expect rgb of "closest" match from fixed color table to be the same (exact match)...

        if self.m_colorTest ==  CopyContextTestColorRemap.TstType.EXTENDED_INDEX_Same or self.m_colorTest ==  CopyContextTestColorRemap.TstType.EXTENDED_INDEX_Different or self.m_colorTest ==  CopyContextTestColorRemap.TstType.EXTENDED_INDEX_New:
            EXPECT_EQ (dstIsTrueColor, True)
            EXPECT_EQ (srcColorDef.m_int, dstColorDef.m_int) #Expect rgb to be the same always...

            closeColorDef = IntColorDef ()
            EXPECT_EQ (eSUCCESS, dstColorMap.ExtractElementColorInfo (closeColorDef, None, None, None, None, dstColorIndex, self.m_dstModel.GetDgnFile ()))
            EXPECT_EQ (closeColorDef.m_int, dstColorDef.m_int) #Expect rgb of "closest" match from fixed color table to be the same (exact match)...


    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def _GetQueryPropertiesMask ():
        return ELEMENT_PROPERTY_Color


    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def _ValidateElement (self, eh):
        PropertyContext.QueryElementProperties (eh, self)


    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def DoColorTest (self, tstType, preserveIndex = False):
        self.m_preserveTableIndex = preserveIndex
        self.m_colorTest = tstType
        self.DoCopyTest ()


##---------------------------------------------------------------------------------##/###
#Tests color remapping when copying between files.
#@bsimethod                                                    Ping.Chen  05/2024
#---------------#---------------#---------------#---------------#---------------#------#/
def test_TestCopyContextTestColorRemap_CopyContextRemapColor ():
    test = CopyContextTestColorRemap ()
    #Test with table color index remapping disallowed...
    test.DoColorTest (CopyContextTestColorRemap.TstType.TABLE_INDEX_Same, True)
    test.DoColorTest (CopyContextTestColorRemap.TstType.TABLE_INDEX_Different, True)
    test.DoColorTest (CopyContextTestColorRemap.TstType.TABLE_INDEX_Background, True)

    #Test with table color index remapping allowed...
    test.DoColorTest (CopyContextTestColorRemap.TstType.TABLE_INDEX_Same)
    test.DoColorTest (CopyContextTestColorRemap.TstType.TABLE_INDEX_Different)
    test.DoColorTest (CopyContextTestColorRemap.TstType.TABLE_INDEX_Background)

    #Test un-named extended colors...
    test.DoColorTest (CopyContextTestColorRemap.TstType.EXTENDED_INDEX_Same)
    test.DoColorTest (CopyContextTestColorRemap.TstType.EXTENDED_INDEX_Different)
    test.DoColorTest (CopyContextTestColorRemap.TstType.EXTENDED_INDEX_New)

    #Test named extended colors...
    test.DoColorTest (CopyContextTestColorRemap.TstType.EXTENDED_BOOK_Same)
    test.DoColorTest (CopyContextTestColorRemap.TstType.EXTENDED_BOOK_Different)
    test.DoColorTest (CopyContextTestColorRemap.TstType.EXTENDED_BOOK_New)

##=================================================================================##/###
#Test level remap when elements are copied between files with different level tables.
#@bsiclass                                                     Ping.Chen  05/2024
#===============#===============#===============#===============#===============#======#/
class CopyContextTestLevelRemap (CopyContextTestBase):
    def __init__ (self):
        super ().__init__ ()
        self.init (True, True, False)
        self.m_firstCreatedLevelId = 0
        self.m_levelName = '\0'


    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def _PrepareSource (self):
        levelCache = self.m_srcModel.GetDgnFile ().GetLevelCache ()
        level = levelCache.CreateLevel ("CCTEST_Level1", LEVEL_NULL_CODE, LEVEL_NULL_ID)
        ASSERT_TRUE (None != level) #"Failed to create source level.\n"

        self.m_firstCreatedLevelId = level.GetLevelId ()

        level = levelCache.CreateLevel ("CCTEST_Level2", LEVEL_NULL_CODE, LEVEL_NULL_ID)
        ASSERT_TRUE (None != level) #"Failed to create source level.\n"

        level = levelCache.CreateLevel ("CCTEST_Level3", LEVEL_NULL_CODE, LEVEL_NULL_ID)
        ASSERT_TRUE (None != level) #"Failed to create source level.\n"


    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def _PrepareDestination (self):
        levelCache = self.m_dstModel.GetDgnFile ().GetLevelCache ()
        level = levelCache.CreateLevel ("CCTEST_Level1", LEVEL_NULL_CODE, LEVEL_NULL_ID)
        ASSERT_TRUE (None != level) #"Failed to create destination level.\n"

        #We are assuming seed files started out with same level table...
        EXPECT_EQ (level.GetLevelId (), self.m_firstCreatedLevelId) #"###Source/Destination seed levels tables differ.\n"

        level = levelCache.CreateLevel ("CCTEST_Level3", LEVEL_NULL_CODE, LEVEL_NULL_ID)
        ASSERT_TRUE (None != level) #"Failed to create destination level.\n"


    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def _InitCopyOptions (self, copyContext):
        copyContext.SetLevelHandling (CopyContextLevelOption.eCopyIfNotFound) #This is the default behavior...


    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def _CreateSourceElements (self):
        self.CreateDefaultTestElements ()

        levelCache = self.m_srcModel.GetDgnFile ().GetLevelCache ()
        level = levelCache.GetLevelByName (self.m_levelName)
        ASSERT_TRUE (None != level) #"Failed to find source level."

        remapper = ElementPropertiesSetter ()
        remapper.SetChangeEntireElement (True)
        remapper.SetLevel (level.GetLevelId ())

        self.WriteSourceElements (remapper)


    ##----------------------------------------------------------------------------------#/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def _EachLevelCallback (self, arg):
        if (0 != (arg.GetPropertyFlags () and PROPSCALLBACK_FLAGS_ElementIgnoresID)):
            return

        ASSERT_TRUE (LEVEL_DEFAULT_LEVEL_ID != arg.GetStoredValue ())

        dstLevelCache = self.m_dstModel.GetDgnFile ().GetLevelCache ()
        dstLevel = dstLevelCache.GetLevel (arg.GetStoredValue ())

        ASSERT_TRUE (dstLevel != None) #"Failed to find destination level."
        EXPECT_STREQ (dstLevel.GetName (), self.m_levelName) #"Failed source/destination level name match."


    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def _GetQueryPropertiesMask (self):
        return ELEMENT_PROPERTY_Level


    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def _ValidateElement (self, eh):
        PropertyContext.QueryElementProperties (eh, self)


    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def DoLevelTest (self, levelName):
        self.m_levelName = levelName
        self.DoCopyTest ()


##---------------------------------------------------------------------------------##/###
#Tests level remapping when copying between files.
#@bsimethod                                                    Ping.Chen  05/2024
#---------------#---------------#---------------#---------------#---------------#------#/
def test_TestCopyContextTestLevelRemap_CopyContextRemapLevel ():
    test = CopyContextTestLevelRemap ()
    test.DoLevelTest ("CCTEST_Level1")
    test.DoLevelTest ("CCTEST_Level2")
    test.DoLevelTest ("CCTEST_Level3")


##=================================================================================##/###
#Test tag remap when elements are copied between files.
#@bsiclass                                                     Ping.Chen  05/2024
#===============#===============#===============#===============#===============#======#/
class CopyContextTestTagRemap (CopyContextTestBase):
    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def __init__ (self):
        super ().__init__ ()
        self.init (True, True, False)
        self.m_tagSetName = WString ()

    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def _InitCopyOptions (self, copyContext):
        pass

    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def _PrepareSource (self):
        tagDefs = DgnTagDefinitionArray ()
        for i in range (3):
            tagDefs.append (DgnTagDefinition ())
        #[DgnTagDefinition () for _ in range (3)]

        value = DgnTagValue (ctypes.c_long (1).value)

        tagDefs[0].name = "TAG1"
        tagDefs[1].name = "TAG2"
        tagDefs[2].name = "TAG3"

        tagDefs[0].tagValue = value
        tagDefs[1].tagValue = value
        tagDefs[2].tagValue = value

        eeh = EditElementHandle ()
        EXPECT_EQ (eSUCCESS, TagSetHandler.Create (eeh, tagDefs, ctypes.c_int32(3).value, "TAGSET1", None, True, self.m_srcModel.GetDgnFile ())) #"Failed to create tag set.\n"
        eeh.AddToModel ()

        EXPECT_EQ (eSUCCESS, TagSetHandler.Create (eeh, tagDefs, ctypes.c_int32(3).value, "TAGSET2", None, True, self.m_srcModel.GetDgnFile ())) #"Failed to create tag set.\n"
        eeh.AddToModel ()

        EXPECT_EQ (eSUCCESS, TagSetHandler.Create (eeh, tagDefs, ctypes.c_int32(3).value, "TAGSET3", None, True, self.m_srcModel.GetDgnFile ())) #"Failed to create tag set.\n"
        eeh.AddToModel ()

        EXPECT_EQ (eSUCCESS, TagSetHandler.Create (eeh, tagDefs, ctypes.c_int32(3).value, "TAGSET4", None, True, self.m_srcModel.GetDgnFile ())) #"Failed to create tag set.\n"
        eeh.AddToModel ()

        EXPECT_EQ (eSUCCESS, TagSetHandler.Create (eeh, tagDefs, ctypes.c_int32(3).value, "TAGSET5", None, True, self.m_srcModel.GetDgnFile ())) #"Failed to create tag set.\n"
        eeh.AddToModel ()


    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def _PrepareDestination (self):
        #tagDefs = [DgnTagDefinition () for _ in range (4)]
        tagDefs = DgnTagDefinitionArray ()
        for i in range (4):
            tagDefs.append (DgnTagDefinition ())
                       
        value = DgnTagValue (ctypes.c_long (2).value)

        tagDefs[0].name = "TAG1"
        tagDefs[1].name = "TAG2"
        tagDefs[2].name = "TAG3"
        tagDefs[3].name = "TAG4"

        tagDefs[0].tagValue = value
        tagDefs[1].tagValue = value
        tagDefs[2].tagValue = value
        tagDefs[3].tagValue = value

        eeh = EditElementHandle ()
        #Exact match with source...
        EXPECT_EQ (eSUCCESS, TagSetHandler.Create (eeh, tagDefs, ctypes.c_int32(3).value, "TAGSET1", None, True, self.m_dstModel.GetDgnFile ())) #"Failed to create tag set.\n"
        eeh.AddToModel ()

        #More entries than source...
        EXPECT_EQ (eSUCCESS, TagSetHandler.Create (eeh, tagDefs, ctypes.c_int32(4).value, "TAGSET2", None, True, self.m_dstModel.GetDgnFile ())) #"Failed to create tag set.\n"
        eeh.AddToModel ()

        #Less entries than source...
        EXPECT_EQ (eSUCCESS, TagSetHandler.Create (eeh, tagDefs, ctypes.c_int32(2).value, "TAGSET3", None, True, self.m_dstModel.GetDgnFile ())) #"Failed to create tag set.\n"
        eeh.AddToModel ()

        #Additional entries and different attribute ids than source...
        tagDefs[0].id = 1
        tagDefs[1].id = 3
        tagDefs[2].id = 2
        tagDefs[3].id = 4

        EXPECT_EQ (eSUCCESS, TagSetHandler.Create (eeh, tagDefs, ctypes.c_int32(4).value, "TAGSET4", None, False, self.m_dstModel.GetDgnFile ())) #"Failed to create tag set.\n"
        eeh.AddToModel ()


    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def _CreateSourceElements (self):
        textStyle = DgnTextStyle ("TextStyle", self.m_srcModel.GetDgnFile ())

        #All source tag sets have 3 sequential tags...
        for iTag in range (0, 3):
            tagName = "TAG{}".format (iTag+1)
            tagInfo = ITagCreateData (tagName, self.m_tagSetName, textStyle, self.m_srcModel.GetDgnFile ())
            EXPECT_EQ (False, tagInfo == None) #"Failed to create tag info.\n"

            #Create 2 tags for every entry to test that subsequent copies also work...
            eeh = EditElementHandle ()
            EXPECT_EQ (eSUCCESS, TagElementHandler.CreateTagElement (eeh, None, tagInfo, self.m_srcModel, self.m_srcModel.Is3d (), DPoint3d.From (0, 0, 0), RotMatrix (), None))
            self.m_agenda.Insert (eeh)

            eeh = EditElementHandle ()
            EXPECT_EQ (eSUCCESS, TagElementHandler.CreateTagElement (eeh, None, tagInfo, self.m_srcModel, self.m_srcModel.Is3d (), DPoint3d.From (0, 0, 0), RotMatrix (), None))
            self.m_agenda.Insert (eeh)

        self.WriteSourceElements (None)


    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def _ValidateElement (self, eh):
        setIndex = 0
        parts = self.m_tagSetName.split("TAGSET")
        if len(parts) > 1:
            setIndex = int(parts[1])

        match = re.search(r'TAGSET(\d+)', self.m_tagSetName)
        if match:
            setIndex = int(match.group(1))

        dstTagSpec = DgnTagSpec ()
        dstTagDef = DgnTagDefinition ()

        EXPECT_EQ (eSUCCESS, TagElementHandler.Extract (dstTagSpec, eh, self.m_dstModel)) #"Failed to extract tag spec.\n"
        EXPECT_EQ (eSUCCESS, TagElementHandler.Extract (dstTagDef, eh, self.m_dstModel)) #"Failed to extract tag defintion.\n"

        srcTagSetEeh = EditElementHandle ()
        srcTagDef = DgnTagDefinition ()

        EXPECT_EQ (eSUCCESS, TagSetHandler.GetByName (srcTagSetEeh, self.m_tagSetName, self.m_srcModel.GetDgnFile ())) #"Failed to find source tag set.\n"
        EXPECT_EQ (eSUCCESS, TagSetHandler.ExtractTagDefByName (srcTagSetEeh, srcTagDef, dstTagSpec.TagName)) #"Failed to find source tag definition by name.\n"

        if setIndex == 3:
            #Verify that tag set name conflict has been resolved...
            EXPECT_STREQ (dstTagDef.name, srcTagDef.name) #"Failed source/destination tag name match."
            EXPECT_STRNE (dstTagSpec.TagSetSpec.TagSetName, self.m_tagSetName) #"Failed source/destination tag set name remap."
            EXPECT_STREQ (dstTagSpec.TagSetSpec.TagSetName, "TAGSET3_1") #"Failed source/destination tag set name remap."
            EXPECT_EQ (dstTagDef.id, srcTagDef.id) #"Failed source/destination tag id match."
        elif setIndex == 4:
            #Verify that tag attribute id has been remapped...
            EXPECT_STREQ (dstTagDef.name, srcTagDef.name) #"Failed source/destination tag name match."
            EXPECT_STREQ (dstTagSpec.TagSetSpec.TagSetName, self.m_tagSetName) #"Failed source/destination tag set name match."

            if dstTagDef.id == 1:
                EXPECT_EQ (1, srcTagDef.id) #"Failed source/destination tag id remap."
            elif dstTagDef.id == 2:
                EXPECT_EQ (3, srcTagDef.id) #"Failed source/destination tag id remap."
            elif dstTagDef.id == 3:
                EXPECT_EQ (2, srcTagDef.id) #"Failed source/destination tag id remap."
            elif dstTagDef.id == 4:
                EXPECT_EQ (4, srcTagDef.id) #"Failed source/destination tag id remap."
            else:
                assert (False)
        else:
                EXPECT_STREQ (dstTagDef.name, srcTagDef.name) #"Failed source/destination tag name match."
                EXPECT_STREQ (dstTagSpec.TagSetSpec.TagSetName, self.m_tagSetName) #"Failed source/destination tag set name match."
                EXPECT_EQ (dstTagDef.id, srcTagDef.id) #"Failed source/destination tag id match."


    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def DoTagTest (self, tagSetName):
        self.m_tagSetName = tagSetName
        self.DoCopyTest ()


##---------------------------------------------------------------------------------##/###
#Tests tag set name/tag attrId remapping when copying between files.
#@bsimethod                                                    Ping.Chen  05/2024
#---------------#---------------#---------------#---------------#---------------#------#/
def test_TestCopyContextTestTagRemap_CopyContextRemapTags ():
    test = CopyContextTestTagRemap ()
    test.DoTagTest ("TAGSET1")
    test.DoTagTest ("TAGSET2")
    test.DoTagTest ("TAGSET3")
    test.DoTagTest ("TAGSET4")
    test.DoTagTest ("TAGSET5")

    #Test that subsequent clone operations give same result...
    test.DoTagTest ("TAGSET1")
    test.DoTagTest ("TAGSET2")
    test.DoTagTest ("TAGSET3")
    test.DoTagTest ("TAGSET4")
    test.DoTagTest ("TAGSET5")


##=================================================================================##/###
#Test shared cell remap when elements are copied between files.
#@bsiclass                                                     Ping.Chen  05/2024
#===============#===============#===============#===============#===============#======#/
class CopyContextTestSharedCellRemap (CopyContextTestBase):
    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  11/10
    #---------------#---------------#---------------#---------------#---------------#------#/
    def __init__ (self):
        super ().__init__ ()
        self.init (True, True, False)
        self.m_expectedDependents = 0
        self.m_anonymousIndex = -1
        self.m_resolveConflicts = False 
        self.m_cellName = '\0'
        self.m_scDefIds = []


    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  11/10
    #---------------#---------------#---------------#---------------#---------------#------#/
    def GetCurrentSCIndex (self):
        scIndex = 0
        match = re.search(r'SC(\d+)', self.m_cellName)
        if match:
            scIndex = int(match.group (1))

        return scIndex


    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def CreateSharedCellDef (self, name, anonymous, model, is3d, size, color1, color2):
        remapper = ElementPropertiesSetter ()

        remapper.SetChangeEntireElement (True)

        eeh = EditElementHandle ()
        childEeh = EditElementHandle ()

        SharedCellDefHandler.CreateSharedCellDefElement (eeh, name, is3d, model)
        SharedCellDefHandler.SetAnonymous (eeh, anonymous)

        EXPECT_EQ (eSUCCESS, LineHandler.CreateLineElement (childEeh, None, DSegment3d (-size, 0, 0, size, 0, 0), is3d, model))
        remapper.SetColor (color1)
        EXPECT_EQ (True, remapper.Apply (childEeh))
        EXPECT_EQ (eSUCCESS, SharedCellDefHandler.AddChildElement (eeh, childEeh))

        EXPECT_EQ (eSUCCESS, LineHandler.CreateLineElement (childEeh, None, DSegment3d (0, -size, 0, 0, size, 0), is3d, model))
        remapper.SetColor (color2)
        EXPECT_EQ (True, remapper.Apply (childEeh))
        EXPECT_EQ (eSUCCESS, SharedCellDefHandler.AddChildElement (eeh, childEeh))

        EXPECT_EQ (eSUCCESS, SharedCellDefHandler.AddChildComplete (eeh))

        eeh.AddToModel ()

        #Save source shared cell defs ids for created anonymous instances...
        if (self.m_srcModel == model):
            self.m_scDefIds.append (eeh.GetElement ().ehdr.uniqueId)


    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def _PrepareSource (self):
        colorMap = DgnColorMap.GetForFile (self.m_srcModel.GetDgnFile ())

        #Setup some known color indices...
        colorMap.SetTbgrColor (ctypes.c_int32(0x0000FF).value, 1) #Red   - Same as destination
        colorMap.SetTbgrColor (ctypes.c_int32(0x00FF00).value, 2) #Green - Different from destination
        colorMap.SetTbgrColor (ctypes.c_int32(0xFF0000).value, 3) #Blue  - Different from destination

        colorMap.SetForFile (self.m_srcModel.GetDgnFile (), "")

        #Create shared celldef for exact match test...
        self.CreateSharedCellDef ("SC1", False, self.m_srcModel, True, 1.0, 1, 1)

        #Create shared celldef for geometry match test w/color remap required...
        self.CreateSharedCellDef ("SC2", False, self.m_srcModel, True, 1.0, 1, 3)

        #Create anonymous shared celldef for exact geom match test w/color mis-match...
        self.CreateSharedCellDef ("SC3", False, self.m_srcModel, True, 1.0, 1, 2)

        #Create shared celldef for geometry size mismatch...
        self.CreateSharedCellDef ("SC4", False, self.m_srcModel, True, 1.0, 1, 1)

        #Create shared celldef that doesn't exist in destination...
        self.CreateSharedCellDef ("SC5", False, self.m_srcModel, True, 1.0, 1, 1)

        #Create anonymous shared celldef for exact match test...
        self.CreateSharedCellDef ("SC6", True, self.m_srcModel, True, 1.0, 1, 1)

        #Create anonymous shared celldef for geometry match test w/color remap required...
        self.CreateSharedCellDef ("SC7", True, self.m_srcModel, True, 1.0, 1, 2)

        #Create anonymous shared celldef for exact geom match test w/color mis-match...
        self.CreateSharedCellDef ("SC8", True, self.m_srcModel, True, 1.0, 1, 2)

        #Create anonymous shared celldef for geometry size mismatch...
        self.CreateSharedCellDef ("SC9", True, self.m_srcModel, True, 1.0, 1, 1)

        #Create anonymous shared celldef that doesn't exist in destination...
        self.CreateSharedCellDef ("SC10", True, self.m_srcModel, True, 1.0, 1, 1)


    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def _PrepareDestination (self):
        colorMap = DgnColorMap.GetForFile (self.m_dstModel.GetDgnFile ())

        #Setup some known color indices...
        colorMap.SetTbgrColor (ctypes.c_int32(0x0000FF).value, 1) #[1] = 0x0000FF #Red   - Same as source
        colorMap.SetTbgrColor (ctypes.c_int32(0xFF0000).value, 2) #[2] = 0xFF0000 #Blue  - Different from source
        colorMap.SetTbgrColor (ctypes.c_int32(0x00FF00).value, 3) #[3] = 0x00FF00 #Green - Different from source

        colorMap.SetForFile (self.m_dstModel.GetDgnFile (), "")

        #Create shared celldef for exact match test...
        self.CreateSharedCellDef ("SC1", False, self.m_dstModel, True, 1.0, 1, 1)

        #Create shared celldef for geometry match test w/color remap required...
        self.CreateSharedCellDef ("SC2", False, self.m_dstModel, True, 1.0, 1, 2)

        #Create shared celldef for exact geom match test w/color mis-match...
        self.CreateSharedCellDef ("SC3", False, self.m_dstModel, True, 1.0, 1, 2)

        #Create shared celldef for geometry size mismatch...
        self.CreateSharedCellDef ("SC4", False, self.m_dstModel, True, 2.0, 1, 1)

        #Create anonymous shared celldef for exact match test...
        self.CreateSharedCellDef ("SC6", True, self.m_dstModel, True, 1.0, 1, 1)

        #Create anonymous shared celldef for geometry match test w/color remap required...
        self.CreateSharedCellDef ("SC7", True, self.m_dstModel, True, 1.0, 1, 3)

        #Create anonymous shared celldef for exact geom match test w/color mis-match...
        self.CreateSharedCellDef ("SC8", True, self.m_dstModel, True, 1.0, 1, 2)

        #Create anonymous shared celldef for geometry size mismatch...
        self.CreateSharedCellDef ("SC9", True, self.m_dstModel, True, 2.0, 1, 1)

        self.m_anonymousIndex = 6


    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def _InitCopyOptions (self, copyContext):
        #NOTE: Default is SharedCellNameConflicts.HasDefId...None isn't important we was always try to match anonymous anyway...
        copyContext.SetSharedCellNameConflicts (ElementCopyContext.SharedCellNameConflictsEnum.eAll if self.m_resolveConflicts else ElementCopyContext.SharedCellNameConflictsEnum.eHasDefId)


    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def _CreateSourceElements (self):
        eeh = EditElementHandle ()
        SharedCellHandler.CreateSharedCellElement (eeh, None, self.m_cellName, None, None, None, self.m_srcModel.Is3d (), self.m_srcModel)

        scIndex = self.GetCurrentSCIndex ()
        #Must add dependency for anonymous shared cells...
        if (scIndex >= self.m_anonymousIndex):
            SharedCellHandler.SetDefinitionID (eeh, self.m_scDefIds[scIndex-1])

        EXPECT_EQ (eSUCCESS, SharedCellHandler.CreateSharedCellComplete (eeh)) 
        self.m_agenda.Insert (eeh)

        self.WriteSourceElements (None)


    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def _ValidateElement (self, eh):
        scInstQuery = eh.GetHandler ()
        ASSERT_TRUE (None != scInstQuery) #"Unexpected element."

        scDefEh = EditElementHandle (scInstQuery.GetDefinition (eh, eh.GetDgnFile ()))

        ASSERT_TRUE (scDefEh.IsValid ()) #"Unable to fine shared cell def."

        scDefnQuery = scDefEh.GetHandler ()
        ASSERT_TRUE (None != scDefnQuery) #"Unexpected element."

        ret0, sCellName = scInstQuery.ExtractName (eh)
        EXPECT_EQ (eSUCCESS, ret0)

        ret1, scDefName = scDefnQuery.ExtractName (scDefEh)
        EXPECT_EQ (eSUCCESS, ret1)

        EXPECT_STREQ (sCellName, scDefName) #"Shared cell instance name doesn't match definition."

        scIndex = self.GetCurrentSCIndex ()
        if scIndex == 3:
            EXPECT_STREQ ("SC3_1" if self.m_resolveConflicts else self.m_cellName, scDefName) #"Shared cell instance name remapped incorrectly."
        elif scIndex == 4:
            EXPECT_STREQ ("SC4_1" if self.m_resolveConflicts else self.m_cellName, scDefName) #"Shared cell instance name remapped incorrectly."
        else:
            EXPECT_STREQ (self.m_cellName, scDefName) #"Shared cell instance name doesn't match definition."

        if (True == scDefnQuery.IsAnonymous (scDefEh)):
            depRefs = ElementRefVec ()
            EXPECT_EQ (self.m_expectedDependents, scDefEh.GetElementRef ().GetDependents (depRefs))


    ##---------------------------------------------------------------------------------##/###
    #@bsimethod                                                    Ping.Chen  05/2024
    #---------------#---------------#---------------#---------------#---------------#------#/
    def DoSharedCellTest (self, cellName, expectedDependents = 0, resolveConflicts = True):
        self.m_cellName = cellName
        self.m_expectedDependents = expectedDependents
        self.m_resolveConflicts = resolveConflicts
        self.DoCopyTest ()

##---------------------------------------------------------------------------------##/###
#Tests shared cell remapping when copying between files.
#@bsimethod                                                    Ping.Chen  05/2024
#---------------#---------------#---------------#---------------#---------------#------#/
def test_TestCopyContextTestSharedCellRemap_CopyContextRemapSharedCell ():
    test = CopyContextTestSharedCellRemap ()
    #Test clone of named shared cells without resolving name conflicts...
    test.DoSharedCellTest ("SC1", 0, False)
    test.DoSharedCellTest ("SC2", 0, False)
    test.DoSharedCellTest ("SC3", 0, False)
    test.DoSharedCellTest ("SC4", 0, False)

    #Now test clone with name remapping/geometry compare...
    test.DoSharedCellTest ("SC1",  1)
    test.DoSharedCellTest ("SC2",  1)
    test.DoSharedCellTest ("SC3",  1)
    test.DoSharedCellTest ("SC4",  1)
    test.DoSharedCellTest ("SC5",  1)
    test.DoSharedCellTest ("SC6",  1)
    test.DoSharedCellTest ("SC7",  1)
    test.DoSharedCellTest ("SC8",  1)
    test.DoSharedCellTest ("SC9",  1)
    test.DoSharedCellTest ("SC10", 1)

    #Test that subsequent clone operations give same result...
    test.DoSharedCellTest ("SC1",  2)
    test.DoSharedCellTest ("SC2",  2)
    test.DoSharedCellTest ("SC3",  2)
    test.DoSharedCellTest ("SC4",  2)
    test.DoSharedCellTest ("SC5",  2)
    test.DoSharedCellTest ("SC6",  2)
    test.DoSharedCellTest ("SC7",  2)
    test.DoSharedCellTest ("SC8",  2)
    test.DoSharedCellTest ("SC9",  2)
    test.DoSharedCellTest ("SC10", 2)