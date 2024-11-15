#--------------------------------------------------------------------------------------#
#
#  $Source: \MSPython\MSPythonTests\PlatformTests\PublishedTests\DgnPlatformTest\DimensionHandler_Test.py.py $
#
#  $Copyright: (c) 2014 Bentley Systems, Incorporated. All rights reserved. $
#
#--------------------------------------------------------------------------------------#
import os
import pytest

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from util import *
from conftest import *

dgnFileName = '2dMetricGeneral.dgn'
dimensionStyleName = "DimensionTestStyle"

#---------------------------------------------------------------------------------#
# @bsistruct                                    Ping.Chen                   04/2024
#---------------#---------------#---------------#---------------#---------------#------#
class DimCreateData (IDimCreateData):
    #---------------------------------------------------------------------------------#
    # @bsimethod                                    Ping.Chen                   04/2024
    #---------------#---------------#---------------#---------------#---------------#------#
    def __init__(self, dimStyle, textStyle, rMatrix, symbology, dirFormatter):
        super ().__init__ ()
        self.setValues (dimStyle, textStyle, rMatrix, symbology, dirFormatter)

    #---------------------------------------------------------------------------------#
    # @bsimethod                                    Ping.Chen                   04/2024
    #---------------#---------------#---------------#---------------#---------------#------#
    def setValues(self, dimStyle, textStyle, rMatrix, symbology, dirFormatter):
        self.m_dimStyle = dimStyle
        self.m_textStyle = textStyle
        self.m_rMatrix = rMatrix
        self.m_symbology = symbology
        self.m_dirFormatter = dirFormatter

    #---------------------------------------------------------------------------------#
    # @bsimethod                                    Ping.Chen                   04/2024
    #---------------#---------------#---------------#---------------#---------------#------#
    def _GetDimStyle(self):
        return self.m_dimStyle

    #---------------------------------------------------------------------------------#
    # @bsimethod                                    Ping.Chen                   04/2024
    #---------------#---------------#---------------#---------------#---------------#------#
    def _GetTextStyle(self):
        return self.m_textStyle

    #---------------------------------------------------------------------------------#
    # @bsimethod                                    Ping.Chen                   04/2024
    #---------------#---------------#---------------#---------------#---------------#------#
    def _GetSymbology(self):
        return self.m_symbology

    #---------------------------------------------------------------------------------#
    # @bsimethod                                    Ping.Chen                   04/2024
    #---------------#---------------#---------------#---------------#---------------#------#
    def _GetLevelID(self):
        return LEVEL_DEFAULT_LEVEL_ID

    #---------------------------------------------------------------------------------#
    # @bsimethod                                    Ping.Chen                   04/2024
    #---------------#---------------#---------------#---------------#---------------#------#
    def _GetViewNumber(self):
        return 0

    #---------------------------------------------------------------------------------#
    # @bsimethod                                    Ping.Chen                   04/2024
    #---------------#---------------#---------------#---------------#---------------#------#
    def _GetDimRMatrix(self):
        return self.m_rMatrix

    #---------------------------------------------------------------------------------#
    # @bsimethod                                    Ping.Chen                   04/2024
    #---------------#---------------#---------------#---------------#---------------#------#
    def _GetViewRMatrix(self):
        return self.m_rMatrix

    #---------------------------------------------------------------------------------#
    # @bsimethod                                    Ping.Chen                   04/2024
    #---------------#---------------#---------------#---------------#---------------#------#
    def _GetDirFormat (self):
        return self.m_dirFormatter

    #---------------------------------------------------------------------------------#
    # @bsimethod                                    Ping.Chen                   04/2024
    #---------------#---------------#---------------#---------------#---------------#------#
    def _GetAnnScaleAllowed (self):
        return True

#---------------------------------------------------------------------------------#
# @bsimethod                                                    Ping.Chen    04/2024
#---------------#---------------#---------------#---------------#---------------#------#
def expectNoShields (eh):
    dimQuery = eh.GetHandler ()
    propMask = dimQuery.GetOverrideFlags (eh)

    if (None == propMask):
        ASSERT_TRUE (False)

    EXPECT_FALSE (propMask.AnyBitSet())


#---------------------------------------------------------------------------------#
# @bsimethod                                                    Ping.Chen    04/2024
#---------------#---------------#---------------#---------------#---------------#------#
def expectExactlyOneShield (eh, prop):
    dimQuery = eh.GetHandler ()
    propMask = dimQuery.GetOverrideFlags (eh)

    if (None == propMask):
        ASSERT_TRUE (False)

    EXPECT_TRUE (propMask.AnyBitSet())
    EXPECT_TRUE (propMask.GetPropertyBit (prop))

    propMask.SetPropertyBit (prop, False)
    EXPECT_FALSE (propMask.AnyBitSet())


#---------------------------------------------------------------------------------#
# @bsimethod                                                    Ping.Chen    04/2024
#---------------#---------------#---------------#---------------#---------------#------#
def expectPropertyValue (eh, prop, value):
    dimQuery = eh.GetHandler()
    elemStyle = dimQuery.GetDimensionStyle (eh)

    retVal, elemValue = elemStyle.GetDoubleProp (prop)
    EXPECT_EQ (elemValue, value)


#---------------------------------------------------------------------------------#
# @bsimethod                                                    Ping.Chen    04/2024
#---------------#---------------#---------------#---------------#---------------#------#
def dimHandlerTest_createLinearDimension (dimStyle, dgnCache):
    textStyle = DgnTextStyle ("", dgnCache.GetDgnFile())

    dimRMatrix = RotMatrix ()
    dimRMatrix.InitIdentity()

    symbology = Symbology (0,0,0)
    dirFormatter = DirectionFormatter.Create ()

    createData = DimCreateData (dimStyle, textStyle, dimRMatrix, symbology, dirFormatter)

    dimType = DimensionType.eSizeArrow
    is3d = dgnCache.Is3d()

    eeh = EditElementHandle ()
    DimensionHandler.CreateDimensionElement (eeh, createData, dimType, is3d, dgnCache)

    return eeh


#*---------------------------------------------------------------------------------**//**
# @bsimethod                                                    Ping.Chen      04/2024
#---------------+---------------+---------------+---------------+---------------+------*/
def isDPoint3dNear (left, right, epsilon):
    EXPECT_NEAR (left.x, right.x, epsilon)
    EXPECT_NEAR (left.y, right.y, epsilon)
    EXPECT_NEAR (left.z, right.z, epsilon)

    return (abs (left.x - right.x) < epsilon and
            abs (left.y - right.y) < epsilon and
            abs (left.z - right.z) < epsilon)



#---------------------------------------------------------------------------------#
# @bsimethod                                                    Ping.Chen    04/2024
#---------------#---------------#---------------#---------------#---------------#------#
def dimHandlerTest_createLinearDimensionWithPoints (dimStyle, dgnCache):
    status = eERROR
    eeh = EditElementHandle (dimHandlerTest_createLinearDimension (dimStyle, dgnCache), True)

    if (None == eeh):
        return eeh, status

    dimEdit = eeh.GetHandler()
    if (None == dimEdit):
        return eeh, status

    point1 = DPoint3d ( 0,      0, 0)
    point2 = DPoint3d ( 100000, 0, 0 )

    if (0 != dimEdit.GetNumPoints (eeh)):
        return eeh, status

    dimEdit.InsertPoint (eeh, point1, None, dimStyle, -1)
    if (1 != dimEdit.GetNumPoints (eeh)):
        return eeh, status

    dimEdit.InsertPoint (eeh, point2, None, dimStyle, -1)
    if (2 != dimEdit.GetNumPoints (eeh)):
        return eeh, status

    testPoint = DPoint3d ()
    dimEdit.ExtractPoint (eeh, testPoint, 0)
    if (False == isDPoint3dNear (point1, testPoint, EPSILON)):
        return eeh, status

    dimEdit.ExtractPoint (eeh, testPoint, 1)
    if (False == isDPoint3dNear (point2, testPoint, EPSILON)):
        return eeh, status

    status = eSUCCESS
    return eeh, status


#---------------------------------------------------------------------------------#
# @bsimethod                                                    Ping.Chen    04/2024
#---------------#---------------#---------------#---------------#---------------#------#
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DimensionHandler_CreateDimension (initDgnPlatformHost, loadDgnFileReadOnly, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFileReadOnly)
    dgnCache, retVal = dgnFile.LoadRootModelById (dgnFile.DefaultModelId, True)
    if (None == dgnCache):
        ASSERT_TRUE (False)

    dimStyle = DimensionStyle ("", dgnCache.GetDgnFile())
    eeh = dimHandlerTest_createLinearDimension (dimStyle, dgnCache)

    if (None == eeh):
        ASSERT_TRUE (False)

#---------------------------------------------------------------------------------#
# @bsimethod                                                    Ping.Chen    04/2024
#---------------#---------------#---------------#---------------#---------------#------#
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DimensionHandler_InsertPoints (initDgnPlatformHost, loadDgnFileReadOnly, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFileReadOnly)
    dgnCache, retVal = dgnFile.LoadRootModelById (dgnFile.DefaultModelId, True)
    if (None == dgnCache):
        ASSERT_TRUE (False)

    dimStyle = DimensionStyle("", dgnCache.GetDgnFile())

    eeh, status = dimHandlerTest_createLinearDimensionWithPoints (dimStyle, dgnCache)
    if (eSUCCESS != status):
        ASSERT_TRUE (False)


#---------------------------------------------------------------------------------#
# @bsimethod                                                    Ping.Chen    04/2024
#---------------#---------------#---------------#---------------#---------------#------#
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DimensionHandler_CreateWithNoStyle_ExpectNoShields (initDgnPlatformHost, loadDgnFileReadOnly, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFileReadOnly)
    dgnCache, retVal = dgnFile.LoadRootModelById (dgnFile.DefaultModelId, True)
    if (None == dgnCache):
        ASSERT_TRUE (False)

    # Create an unnamed style
    dimStyle = DimensionStyle ("", dgnCache.GetDgnFile())

    # Create a dimension with the unnamed style
    eeh, status = dimHandlerTest_createLinearDimensionWithPoints (dimStyle, dgnCache)
    if (eSUCCESS != status):
        ASSERT_TRUE (False)

    # Since the dimension is using style:<none>, it should not have any shields
    expectNoShields (eeh)


#---------------------------------------------------------------------------------#
# @bsimethod                                                    Ping.Chen    04/2024
#---------------#---------------#---------------#---------------#---------------#------#
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DimensionHandler_CreateWithStyle_ExpectNoShields (initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    dgnCache, retVal = dgnFile.LoadRootModelById (dgnFile.DefaultModelId, True)
    if (None == dgnCache):
        ASSERT_TRUE (False)

    # Create a real style and add it to the file
    testName = "TestName"
    dimStyle = DimensionStyle (testName, dgnCache.GetDgnFile())
    dimStyle.Add()
    #if (eSUCCESS != dimStyle.Add()):
    #    ASSERT_TRUE (False)

    # Create a dimension with the unmodified style
    eeh, status = dimHandlerTest_createLinearDimensionWithPoints (dimStyle, dgnCache)
    if (eSUCCESS != status):
        ASSERT_TRUE (False)

    # Since the dimension was created with a 'pure' style, it should not have any shields
    expectNoShields (eeh)

    DimensionStyle.Delete (testName, dgnFile)
    #dgnFile.ProcessChanges (DgnSaveReason.eApplInitiated)
    #dgnFile.Release ()

#---------------------------------------------------------------------------------#
# @bsimethod                                                    Ping.Chen    04/2024
#---------------#---------------#---------------#---------------#---------------#------#
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DimensionHandler_CreateWithModifiedStyle_ExpectShields (initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    dgnCache, retVal = dgnFile.LoadRootModelById (dgnFile.DefaultModelId, True)
    if (None == dgnCache):
        ASSERT_TRUE (False)

    # Create a real style and add it to the file
    testName = "TestName"
    dimStyle = DimensionStyle (testName, dgnCache.GetDgnFile())
    dimStyle.Add()
    #if (eSUCCESS != dimStyle.Add()):
    #    ASSERT_TRUE (False)

    dimStyle.SetDoubleProp (2.0, eDIMSTYLE_PROP_General_DimensionScale_DOUBLE)

    # Create a dimension with the modified style
    eeh, status = dimHandlerTest_createLinearDimensionWithPoints (dimStyle, dgnCache)
    if (eSUCCESS != status):
        ASSERT_TRUE (False)

    # Since the dimension was created with a 'dirty' style, it should a shield
    expectExactlyOneShield (eeh, eDIMSTYLE_PROP_General_DimensionScale_DOUBLE)

    # The property value should match the modified style.
    expectPropertyValue (eeh, eDIMSTYLE_PROP_General_DimensionScale_DOUBLE, 2.0)

    DimensionStyle.Delete (testName, dgnFile)
    #dgnFile.ProcessChanges (DgnSaveReason.eApplInitiated)
    #dgnFile.Release ()

#---------------------------------------------------------------------------------#
# @bsimethod                                                    Ping.Chen    04/2024
#---------------#---------------#---------------#---------------#---------------#------#
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DimensionHandler_ModifyDimension_ExpectShields (initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    dgnCache, retVal = dgnFile.LoadRootModelById (dgnFile.DefaultModelId, True)
    if (None == dgnCache):
        ASSERT_TRUE (False)

    # Create a real style and add it to the file
    testName = "TestName"
    dimStyle = DimensionStyle (testName, dgnCache.GetDgnFile())

    dimStyle.SetBooleanProp  (True, eDIMSTYLE_PROP_Text_OverrideHeight_BOOLINT)
    dimStyle.SetBooleanProp  (True, eDIMSTYLE_PROP_Text_OverrideWidth_BOOLINT )
    dimStyle.SetDistanceProp (5000, eDIMSTYLE_PROP_Text_Height_DISTANCE, None)
    dimStyle.SetDistanceProp (5000, eDIMSTYLE_PROP_Text_Width_DISTANCE,  None)

    dimStyle.Add()
    #if (eSUCCESS != dimStyle.Add()):
    #    ASSERT_TRUE (False)

    # Create a dimension with the unmodified style
    eeh, status = dimHandlerTest_createLinearDimensionWithPoints (dimStyle, dgnCache)
    if (eSUCCESS != status):
        ASSERT_TRUE (False)

    # Since the dimension was created with a 'clean' style, it should not have shields
    expectNoShields (eeh)

    # Modify the style and push the modifications onto the element
    dimEdit = eeh.GetHandler ()
    elemStyle = dimEdit.GetDimensionStyle (eeh)

    propToEdit = eDIMSTYLE_PROP_ExtensionLine_Offset_DOUBLE

    retVal, value = elemStyle.GetDoubleProp (propToEdit)
    elemStyle.SetDoubleProp (2.0*value, propToEdit)
    dimEdit.ApplyDimensionStyle (eeh, elemStyle, True)

    eeh.AddToModel ()
 
    #tdm.CopyFileTo ("JoshTest0609.dgn")

    # Now we expect that the dimension will a shield
    expectExactlyOneShield (eeh, propToEdit)

    # The property value should match the modified style.
    expectPropertyValue (eeh, propToEdit, 2.0*value)

    DimensionStyle.Delete (testName, dgnFile)
    #dgnFile.ProcessChanges (DgnSaveReason.eApplInitiated)
    #dgnFile.Release ()

#---------------------------------------------------------------------------------#
# @bsimethod                                                    Ping.Chen    04/2024
#---------------#---------------#---------------#---------------#---------------#------#
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DimensionHandler_ModifyDimension_WithExistingShields(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    dgnCache, retVal = dgnFile.LoadRootModelById (dgnFile.DefaultModelId, True)
    if (None == dgnCache):
        ASSERT_TRUE (False)

    # Create a real style and add it to the file
    testName = "TestName"
    dimStyle = DimensionStyle (testName, dgnCache.GetDgnFile())

    dimStyle.SetBooleanProp  (True, eDIMSTYLE_PROP_Text_OverrideHeight_BOOLINT)
    dimStyle.SetBooleanProp  (True, eDIMSTYLE_PROP_Text_OverrideWidth_BOOLINT )
    dimStyle.SetDistanceProp (5000, eDIMSTYLE_PROP_Text_Height_DISTANCE, None)
    dimStyle.SetDistanceProp (5000, eDIMSTYLE_PROP_Text_Width_DISTANCE,  None)

    dimStyle.Add()
    #if (eSUCCESS != dimStyle.Add()):
    #    ASSERT_TRUE (False)

    # Modify the style before creating the dimension

    propToEdit = eDIMSTYLE_PROP_ExtensionLine_Offset_DOUBLE

    ret, value = dimStyle.GetDoubleProp (propToEdit)

    modifiedValue = 2.0*value
    EXPECT_NE (value, modifiedValue)

    dimStyle.SetDoubleProp (modifiedValue, propToEdit)

    # Create a dimension with the modified style
    eeh, status = dimHandlerTest_createLinearDimensionWithPoints (dimStyle, dgnCache)
    if (eSUCCESS != status):
        ASSERT_TRUE (False)

    dimStyle = None  # just to be sure we don't use it below

    expectExactlyOneShield (eeh, propToEdit)

    # Verify that the modified value is there
    expectPropertyValue (eeh, propToEdit, modifiedValue)

    # Modify the element style and apply it to the element
    dimEdit = eeh.GetHandler ()
    elemStyle = dimEdit.GetDimensionStyle (eeh)
    newModifiedValue = 2.0*modifiedValue
    elemStyle.SetDoubleProp (newModifiedValue, propToEdit)

    # !!!! This is the unique part of the test  !!!!
    # We are applying a modified style to an element that already has a shield on
    # the modified property.  We expect the property to be modified and the shield
    # to be unaffected.
    dimEdit.ApplyDimensionStyle (eeh, elemStyle, True)

    # Verify that the new modified value is there
    expectPropertyValue (eeh, propToEdit, newModifiedValue)

    # There should still only be one shield
    expectExactlyOneShield (eeh, propToEdit)

    DimensionStyle.Delete (testName, dgnFile)
    #dgnFile.ProcessChanges (DgnSaveReason.eApplInitiated)
    #dgnFile.Release ()
    

#---------------------------------------------------------------------------------#
# @bsimethod                                                    Ping.Chen    04/2024
#---------------#---------------#---------------#---------------#---------------#------#
@pytest.mark.parametrize('fileName', ['3dMetricGeneral.dgn'])
def test_DimensionHandler_SaveStyleUpdateDimension (initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    dgnCache, retVal = dgnFile.LoadRootModelById (dgnFile.DefaultModelId, True)
    if (None == dgnCache):
        ASSERT_TRUE (False)

    # Create a style and add it to the file
    testName = "TestName"
    dimStyle = DimensionStyle (testName, dgnCache.GetDgnFile())

    dimStyle.SetBooleanProp (False, eDIMSTYLE_PROP_BallAndChain_ShowTextLeader_BOOLINT)

    dimStyle.Add()
    #if (eSUCCESS != dimStyle.Add()):
    #    ASSERT_TRUE (False)

    # Create a dimension which refers to the style
    createdDim, status = dimHandlerTest_createLinearDimensionWithPoints (dimStyle, dgnCache)
    if (eSUCCESS != status):
        ASSERT_TRUE (False)

    if (eSUCCESS != createdDim.AddToModel ()):
        ASSERT_TRUE (False)

    # Read the dimension and verify the property is as expected
    dimElementID     = createdDim.GetElementId()
    initialElemRef   = dgnCache.FindElementByID (dimElementID)
    initialDimInFile = EditElementHandle (initialElemRef, dgnCache)

    dimQuery = initialDimInFile.GetHandler ()
    if (None == dimQuery):
        ASSERT_TRUE (False)

    initialElemStyle = dimQuery.GetDimensionStyle (initialDimInFile)

    matrix1 = RotMatrix ()
    EXPECT_EQ(eSUCCESS, dimQuery.GetRotationMatrix(createdDim, matrix1))
    quat1 = DPoint4d (0.0, 0.0, 0.0, 0.0)
    matrix1.GetQuaternion (quat1, False)
    RotMatrix.FromQuaternion (quat1)
    #EXPECT_EQ(eERROR, eSUCCESS) # just placed here free break.

    retVal, propValue = initialElemStyle.GetBooleanProp (eDIMSTYLE_PROP_BallAndChain_ShowTextLeader_BOOLINT)
    ASSERT_EQ (False, propValue)

    # Read the style from the file, modify it and save it.  This should change the dimension.
    dimStyleFromFile = DimensionStyle.GetByName (testName, dgnCache.GetDgnFile())
    if (None == dimStyleFromFile):
        ASSERT_TRUE (False)

    retVal, propValue = dimStyleFromFile.GetBooleanProp (eDIMSTYLE_PROP_BallAndChain_ShowTextLeader_BOOLINT)
    ASSERT_EQ (False, propValue)

    dimStyleFromFile.SetBooleanProp (True, eDIMSTYLE_PROP_BallAndChain_ShowTextLeader_BOOLINT)

    if (eSUCCESS != dimStyleFromFile.Replace()):
        ASSERT_TRUE (False)

    # Read the dimension and verify the property is as expected
    dgnCache.FindElementByID (dimElementID)
    updatedDimInFile =EditElementHandle(initialElemRef, dgnCache)

    updatedElemStyle = dimQuery.GetDimensionStyle (updatedDimInFile)

    retVal, propValue = updatedElemStyle.GetBooleanProp (eDIMSTYLE_PROP_BallAndChain_ShowTextLeader_BOOLINT)
    ASSERT_EQ (True, propValue)

    #NEEDSWORK_CR disabling this because it fails on RELEASE x86 builds (only)
    #expectNoShields (updatedDimInFile)

    DimensionStyle.Delete (testName, dgnFile)
    #dgnFile.ProcessChanges (DgnSaveReason.eApplInitiated)
    #dgnFile.Release ()


#---------------------------------------------------------------------------------#
# @bsimethod                                    Ping.Chen                  04/2024
#---------------#---------------#---------------#---------------#---------------#------#
@pytest.mark.parametrize('fileName', ['dim_cust_text.dgn'])
def test_DimensionHandler_DimensionTextPoints (initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    dgnCache, retVal = dgnFile.LoadRootModelById (dgnFile.DefaultModelId, True)
    if (None == dgnCache):
        ASSERT_TRUE (False)

    dimElement = EditElementHandle ()
    ASSERT_TRUE (eSUCCESS == dimElement.FindByID(124, dgnCache))
    
    hdlr = dimElement.GetHandler()
    ASSERT_TRUE (None != hdlr)

    offset = DPoint2d (0.0, 0.0)
    ASSERT_TRUE (eSUCCESS == hdlr.GetTextOffset (dimElement, 0, offset))
    ASSERT_TRUE (abs(offset.x) < mgds_fc_epsilon)
    ASSERT_TRUE (abs(offset.y) < mgds_fc_epsilon)


#---------------------------------------------------------------------------------#
# @bsimethod                                    Ping.Chen                  04/2024
#---------------#---------------#---------------#---------------#---------------#------#
@pytest.mark.parametrize('fileName', ['dim_radial_note.dgn'])
def test_DimensionHandler_DimensionRadialNoteTest (initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    dgnCache, retVal = dgnFile.LoadRootModelById (dgnFile.DefaultModelId, True)
    if (None == dgnCache):
        ASSERT_TRUE (False)

    dimElement = EditElementHandle ()
    ASSERT_TRUE (eSUCCESS == dimElement.FindByID(124, dgnCache))
    
    hdlr = dimElement.GetHandler()
    ASSERT_TRUE (None != hdlr)

    textParts = TextPartIdVector ()
    hdlr.GetTextPartIds(dimElement, ITextQueryOptions (), textParts)
    for iter in  textParts:    
        textBlock = hdlr.GetTextPart (dimElement, iter)
        if (textBlock == None):
            continue

        str = textBlock.ToString()
        ASSERT_TRUE (False == str.IsEmpty())


#---------------------------------------------------------------------------------#
# @bsimethod                                    Ping.Chen                  04/2024
#---------------#---------------#---------------#---------------#---------------#------#
@pytest.mark.parametrize('fileName', ['dim_radial_center.dgn'])
def test_DimensionHandler_DimensionCenterlineTest (initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    dgnCache, retVal = dgnFile.LoadRootModelById (dgnFile.DefaultModelId, True)
    if (None == dgnCache):
        ASSERT_TRUE (False)

    dimElement = EditElementHandle ()
    ASSERT_TRUE (eSUCCESS == dimElement.FindByID(124, dgnCache))
    
    hdlr = dimElement.GetHandler()
    ASSERT_TRUE (None != hdlr)

    textParts = TextPartIdVector ()
    hdlr.GetTextPartIds(dimElement, ITextQueryOptions (), textParts)

    ASSERT_TRUE (0 == textParts.__len__ ())


#---------------------------------------------------------------------------------#
# @bsimethod                                    Ping.Chen                  04/2024
#---------------#---------------#---------------#---------------#---------------#------#
@pytest.mark.parametrize('fileName', ['problem_dims.dgn'])
def test_DimensionHandler_GetViewRotation (initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    dgnCache, retVal = dgnFile.LoadRootModelById (dgnFile.DefaultModelId, True)
    if (None == dgnCache):
        ASSERT_TRUE (False)

    graphicElemList = dgnCache.GetGraphicElements ()
    if (None == graphicElemList):
        return

    for elemRef in graphicElemList:
        element = ElementHandle (elemRef, dgnCache)
        hdlr = element.GetHandler ()
        if (None == hdlr or False == isinstance (hdlr, DimensionHandler)):
            continue

        element.GetElementId()
        rotMatrix = RotMatrix ()
        ASSERT_TRUE (eSUCCESS == hdlr.GetViewRotation(element, rotMatrix))

    dimElement1 = EditElementHandle ()
    ASSERT_TRUE (eSUCCESS == dimElement1.FindByID (157174, dgnCache))

    hdlr:DimensionHandler = dimElement1.GetHandler()
    rotMatrix = RotMatrix ()
    ASSERT_TRUE (eSUCCESS == hdlr.GetViewRotation(dimElement1, rotMatrix))

    dimElement2 = EditElementHandle ()
    ASSERT_TRUE (eSUCCESS == dimElement2.FindByID(157521, dgnCache))
    ASSERT_TRUE (eSUCCESS == hdlr.GetViewRotation(dimElement1, rotMatrix))


#---------------------------------------------------------------------------------#
# @bsimethod                                    Ping.Chen                  04/2024
#---------------#---------------#---------------#---------------#---------------#------#
@pytest.mark.parametrize('fileName', ['dim_center.dgn'])
def test_DimensionHandler_DimensionGetCenterMark(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    dgnCache, retVal = dgnFile.LoadRootModelById (dgnFile.DefaultModelId, True)
    if (None == dgnCache):
        ASSERT_TRUE (False)

    dimElement = EditElementHandle ()
    ASSERT_TRUE (eSUCCESS == dimElement.FindByID(124, dgnCache))
    
    hdlr = dimElement.GetHandler()
    ASSERT_TRUE (None != hdlr)
    
    dimStyle = hdlr.GetDimensionStyle (dimElement)
    ASSERT_TRUE (dimStyle != None)
    #TODO compare center mark height


#---------------------------------------------------------------------------------#
# @bsimethod                                    Ping.Chen                  04/2024
#---------------#---------------#---------------#---------------#---------------#------#
@pytest.mark.parametrize('fileName', ['dim_with_dflt_txt_and_zero_style_size.dgn'])
def test_DimensionHandler_DimensionGetTextHeight(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    dgnCache, retVal = dgnFile.LoadRootModelById (dgnFile.DefaultModelId, True)
    if (None == dgnCache):
        ASSERT_TRUE (False)

    dimElement = EditElementHandle ()
    ASSERT_TRUE (eSUCCESS == dimElement.FindByID(137, dgnCache))
    
    hdlr = dimElement.GetHandler()
    ASSERT_TRUE (None != hdlr)

    dimStyle = hdlr.GetDimensionStyle (dimElement)
    ASSERT_TRUE (None != dimStyle)

    retVal, textStyle = dimStyle.GetTextStyleProp (eDIMSTYLE_PROP_Text_TextStyle_TEXTSTYLE)
    ASSERT_TRUE (None != textStyle)

    retVal, height = textStyle.GetDoubleProperty (eTextStyle_Height)
    EXPECT_EQ (height, 4572.0)


#---------------------------------------------------------------------------------#
# @bsimethod                                    Ping.Chen                  04/2024
#---------------#---------------#---------------#---------------#---------------#------#
@pytest.mark.parametrize('fileName', ['leader.dgn'])
def test_DimensionHandler_DimensionGetNoteTextHeight (initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    model = dgnFile.FindModelIdByName ("D")
    dgnCache, error= dgnFile.LoadRootModelById (model, True)
    if (None == dgnCache):
        ASSERT_TRUE (False)

    dimElement = EditElementHandle ()
    ASSERT_TRUE (eSUCCESS == dimElement.FindByID(64929, dgnCache))
    
    hdlr = dimElement.GetHandler()
    ASSERT_TRUE (None != hdlr)
    
    dimStyle = hdlr.GetDimensionStyle (dimElement)
    ASSERT_TRUE (None != dimStyle)

    retVal, textStyle = dimStyle.GetTextStyleProp (eDIMSTYLE_PROP_Text_TextStyle_TEXTSTYLE)
    ASSERT_TRUE (None != textStyle)

    retVal, height = textStyle.GetDoubleProperty (eTextStyle_Height)

    ret, termHeight = dimStyle.GetDoubleProp (eDIMSTYLE_PROP_Terminator_Height_DOUBLE)

    retVal, annotationScale = hdlr.HasAnnotationScale (dimElement)
    
    EXPECT_EQ (termHeight*annotationScale*height, 101600.00*0.5)
    #EXPECT_EQ (height, 4572.0)


#---------------------------------------------------------------------------------#
# @bsimethod                                    Ping.Chen                  04/2024
#---------------#---------------#---------------#---------------#---------------#------#
@pytest.mark.parametrize('fileName', ['dim_ord_from_export.dgn'])
def test_DimensionHandler_OrdinateDimensionTextBlock (initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    dgnCache, retVal = dgnFile.LoadRootModelById (dgnFile.DefaultModelId, True)
    if (None == dgnCache):
        ASSERT_TRUE (False)

    dimElement = EditElementHandle ()
    ASSERT_TRUE (eSUCCESS == dimElement.FindByID(733, dgnCache))
    
    hdlr = dimElement.GetHandler()
    ASSERT_TRUE (None != hdlr)

    textParts = TextPartIdVector ()
    hdlr.GetTextPartIds(dimElement, ITextQueryOptions (), textParts)
    for iter in  textParts:
        ASSERT_TRUE (None != iter)
        #This test currently fails because we are not able to get the text part of a non stroked dimension
        #TextBlockPtr textBlock = hdlr.GetTextPart (dimElement, iter)
        #EXPECT_EQ(textBlock.IsValid(), True)

        #WString strOut = textBlock.ToString()
        #EXPECT_STREQ(strOut.GetWCharCP(), "*")



#---------------------------------------------------------------------------------#
# @bsimethod                                    Ping.Chen                  04/2024
#---------------#---------------#---------------#---------------#---------------#------#
@pytest.mark.parametrize('fileName', ['leader_only.dgn'])
def test_DimensionHandler_DimensionVisibleBit (initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    dgnCache, retVal = dgnFile.LoadRootModelById (dgnFile.DefaultModelId, True)
    if (None == dgnCache):
        ASSERT_TRUE (False)

    dimElement = EditElementHandle ()
    ASSERT_TRUE (eSUCCESS == dimElement.FindByID(7395, dgnCache))

    hdr = dimElement.GetElement().hdr.dhdr
    EXPECT_EQ (0, hdr.props.b.invisible)


#---------------------------------------------------------------------------------#
# @bsistruct                                    Ping.Chen                   04/2024
#---------------#---------------#---------------#---------------#---------------#------#
class TestDimensionTestFixture :
    #---------------------------------------------------------------------------------#
    # @bsimethod                                    Ping.Chen                   04/2024
    #---------------#---------------#---------------#---------------#---------------#------#
    def loadDgnFileByFileName (self, fileName):
        dataDir = os.environ['MSPYTESTDATA']
        ret = DgnDocument.CreateFromFileName (fileName, dataDir, -101, DgnDocument.FetchMode.eWrite)

        if (ret[1] != DgnFileStatus.eDGNFILE_STATUS_Success):
            assert False

        dgnFile = DgnFile (ret[0], DgnFileOpenMode.eReadWrite)
        dgnFile.LoadDgnFile ()
        dgnFile.FillDictionaryModel ()

        return dgnFile

    #---------------------------------------------------------------------------------#
    # @bsimethod                                    Ping.Chen                   04/2024
    #---------------#---------------#---------------#---------------#---------------#------#
    def loadDgnModel (self):
        seedFile = self.loadDgnFileByFileName (dgnFileName)
        self.dgnFile = createTempDgnFileFromSeedFile (seedFile)
        self.model, retVal = self.dgnFile.LoadRootModelById (self.dgnFile.DefaultModelId, True)

    #---------------------------------------------------------------------------------#
    # @bsimethod                                    Ping.Chen                   04/2024
    #---------------#---------------#---------------#---------------#---------------#------#
    def GetDgnModel (self):
        return self.model

    #---------------------------------------------------------------------------------#
    # @bsimethod                                    Ping.Chen                   04/2024
    #---------------#---------------#---------------#---------------#---------------#------#
    def GetDgnFile (self):
        return self.dgnFile

    #---------------------------------------------------------------------------------#
    # @bsimethod                                    Ping.Chen                   04/2024
    #---------------#---------------#---------------#---------------#---------------#------#
    def setup_method (self):
        DgnPlatformFixture_Initialize ()
        self.loadDgnModel ()

        textStyle = DgnTextStyle (dimensionStyleName, self.GetDgnFile ())
        textStyle.SetDoubleProperty (eTextStyle_Height, 10000.0)
        textStyle.SetDoubleProperty (eTextStyle_Width, 10000.0)

        textStyle.Add ()
        self.m_textStyle = textStyle

        dimStyle = DimensionStyle (dimensionStyleName, self.GetDgnFile ())
        dimStyle.SetTextStyleProp (self.m_textStyle, eDIMSTYLE_PROP_Text_TextStyle_TEXTSTYLE)
        dimStyle.Add ()
        self.m_dimStyle = dimStyle

    #---------------------------------------------------------------------------------#
    # @bsimethod                                    Ping.Chen                   04/2024
    #---------------#---------------#---------------#---------------#---------------#------#
    def teardown_method (self):
        DgnTextStyle.Delete (dimensionStyleName, self.dgnFile)
        DimensionStyle.Delete (dimensionStyleName, self.dgnFile)
        #self.dgnFile.ProcessChanges(DgnSaveReason.eFileClose)
        #self.dgnFile.Release ()

    #---------------------------------------------------------------------------------#
    # @bsimethod                                    Ping.Chen                  04/2024
    #---------------#---------------#---------------#---------------#---------------#------#
    def CreateDimDefaults (self):
        dimRMatrix = RotMatrix ()
        dimRMatrix.InitIdentity()

        symbology = Symbology (0,0,0)
        dirFormatter = DirectionFormatter.Create ()

        return DimCreateData (self.m_dimStyle, self.m_textStyle, dimRMatrix, symbology, dirFormatter)


    #---------------------------------------------------------------------------------#
    # @bsimethod                                    Ping.Chen                  04/2024
    #---------------#---------------#---------------#---------------#---------------#------#
    def InsertPoints (self, eeh, points):
        dimEdit = eeh.GetHandler()

        if (None == dimEdit):
            return eERROR

        if (0 != dimEdit.GetNumPoints (eeh)):
            return eERROR
    
        index = 0
        for iter in points:
            dimEdit.InsertPoint (eeh, iter, None, self.m_dimStyle, -1)
            if (index +1 != dimEdit.GetNumPoints (eeh)):
                return eERROR
            
            index += 1

        return eSUCCESS


    #---------------------------------------------------------------------------------#
    # @bsimethod                                    Ping.Chen                  04/2024
    #---------------#---------------#---------------#---------------#---------------#------#
    def CreateLinearDimension (self, eeh, dimType, tmpPoint):
        status = DimensionHandler.CreateDimensionElement (eeh, self.CreateDimDefaults(), dimType, self.GetDgnModel().Is3d(), self.GetDgnModel ())
        ASSERT_TRUE (eSUCCESS == status)

        points = DPoint3dArray ()

        tmpPoint0 = tmpPoint
        points.append (tmpPoint0)

        tmpPoint1 = tmpPoint
        tmpPoint1.x += 100000
        points.append (tmpPoint1)

        tmpPoint2 = tmpPoint
        tmpPoint2.x += 200000
        points.append (tmpPoint2)
    
        status = self.InsertPoints (eeh, points)
        ASSERT_TRUE (eSUCCESS == status)

        addStatus = eeh.AddToModel ()
        ASSERT_TRUE (eSUCCESS == addStatus)


    #---------------------------------------------------------------------------------#
    # @bsimethod                                    Ping.Chen                  04/2024
    #---------------#---------------#---------------#---------------#---------------#------#
    def CreateAngularDimension (self, dimType, tmpPointIn):
        eeh = EditElementHandle ()
        status = DimensionHandler.CreateDimensionElement (eeh, self.CreateDimDefaults(), dimType, self.GetDgnModel().Is3d(), self.GetDgnModel ())
        ASSERT_TRUE (eSUCCESS == status)
        
        tmpPoint = DPoint3d (tmpPointIn.x, tmpPointIn.y, tmpPointIn.z)
        points = DPoint3dArray ()
        points.append(tmpPoint)
    
        point2 = DPoint3d (tmpPoint.x, tmpPoint.y, tmpPoint.z)
        point2.x += 100000
        points.append(point2)

        point3 = DPoint3d (tmpPoint.x, tmpPoint.y, tmpPoint.z)
        point3.x -= 100000
        points.append(point3)

        status = self.InsertPoints (eeh, points)
        ASSERT_TRUE (eSUCCESS == status)

        addStatus = eeh.AddToModel ()
        ASSERT_TRUE (eSUCCESS == addStatus)

        #Chord angle
        eeh = EditElementHandle ()
        status = DimensionHandler.CreateDimensionElement (eeh, self.CreateDimDefaults(), dimType, self.GetDgnModel().Is3d(), self.GetDgnModel ())
        ASSERT_TRUE (eSUCCESS == status)

        tmpPoint = DPoint3d (tmpPointIn.x, tmpPointIn.y, tmpPointIn.z)
        tmpPoint.x += 200000

        points = DPoint3dArray ()
        points.append(tmpPoint)
    
        point2 = DPoint3d (tmpPoint.x, tmpPoint.y, tmpPoint.z)
        point2.x += 100000
        point2.y += 100000
        points.append(point2)

        point3 = DPoint3d (tmpPoint.x, tmpPoint.y, tmpPoint.z)
        point3.x -= 100000
        point3.y -= 100000
        points.append (point3)

        status = self.InsertPoints (eeh, points)
        ASSERT_TRUE (eSUCCESS == status)

        addStatus = eeh.AddToModel ()
        ASSERT_TRUE (eSUCCESS == addStatus)


    #---------------------------------------------------------------------------------#
    # @bsimethod                                    Ping.Chen                  04/2024
    #---------------#---------------#---------------#---------------#---------------#------#
    def AddText (self, eeh, testString, textPart):
        hdlr = eeh.GetHandler()

        textBlock  = TextBlock (self.m_textStyle, self.GetDgnModel())
        textBlock.AppendText (testString.GetWCharCP())
        ASSERT_TRUE (ITextEdit.eReplaceStatus_Success == hdlr.ReplaceTextPart (eeh, textPart, textBlock))

        addedtextBlock = hdlr.GetTextPart (eeh, textPart)
        return addedtextBlock.ToString()


    #---------------------------------------------------------------------------------#
    # @bsimethod                                    Ping.Chen                  04/2024
    #---------------#---------------#---------------#---------------#---------------#------#
    def test_TestDimensionTestFixture_Create_LinearTypes (self):
        origin = DPoint3d (0, 0, 0)
        element = EditElementHandle ()
        self.CreateLinearDimension (element, DimensionType.eSizeArrow, origin)

        baseValue = 100000
        count = 1
        increment = 4

        origin.Init (baseValue*count*increment, baseValue*count*increment, baseValue*count*increment)
        self.CreateLinearDimension (element, DimensionType.eSizeStroke, origin)
    
        count += 1
        origin.Init (baseValue*count*increment, baseValue*count*increment, baseValue*count*increment)
        self.CreateLinearDimension (element, DimensionType.eLocateSingle, origin)

        count += 1
        origin.Init (baseValue*count*increment, baseValue*count*increment, baseValue*count*increment)
        self.CreateLinearDimension (element, DimensionType.eLocateStacked, origin)

        count += 1
        origin.Init (baseValue*count*increment, baseValue*count*increment, baseValue*count*increment)
        self.CreateLinearDimension (element, DimensionType.eCustomLinear, origin)

        #self.GetDgnFile().ProcessChanges(DgnSaveReason.eApplInitiated)


    #---------------------------------------------------------------------------------#
    # @bsimethod                                    Ping.Chen                  04/2024
    #---------------#---------------#---------------#---------------#---------------#------#
    def test_TestDimensionTestFixture_CreateAngularTypes(self):
        origin = DPoint3d(0, 0, 0)
        self.CreateAngularDimension (DimensionType.eAngleSize, origin)

        baseValue = 100000
        count = 1
        increment = 4
    
        origin.Init (baseValue*count*increment, baseValue*count*increment, baseValue*count*increment)
        self.CreateAngularDimension (DimensionType.eArcSize, origin)

        count += 1
        origin.Init (baseValue*count*increment, baseValue*count*increment, baseValue*count*increment)
        self.CreateAngularDimension (DimensionType.eAngleLocation, origin)

        count += 1
        origin.Init (baseValue*count*increment, baseValue*count*increment, baseValue*count*increment)
        self.CreateAngularDimension (DimensionType.eArcLocation, origin)

        count += 1
        origin.Init (baseValue*count*increment, baseValue*count*increment, baseValue*count*increment)
        self.CreateAngularDimension (DimensionType.eAngleLines, origin)

        count += 1
        origin.Init (baseValue*count*increment, baseValue*count*increment, baseValue*count*increment)
        self.CreateAngularDimension (DimensionType.eAngleAxis, origin)

        count += 1
        origin.Init (baseValue*count*increment, baseValue*count*increment, baseValue*count*increment)
        self.CreateAngularDimension (DimensionType.eAngleAxisX, origin)

        count += 1
        origin.Init (baseValue*count*increment, baseValue*count*increment, baseValue*count*increment)
        self.CreateAngularDimension (DimensionType.eAngleAxisY, origin)

        #self.GetDgnFile().ProcessChanges(DgnSaveReason.eApplInitiated)


    #---------------------------------------------------------------------------------#
    # @bsimethod                                    Ping.Chen                  04/2024
    #---------------#---------------#---------------#---------------#---------------#------#
    def test_TestDimensionTestFixture_CreateRadialTypes(self):
        origin = DPoint3d(0, 0, 0)
        self.CreateAngularDimension (DimensionType.eRadius, origin)

        baseValue = 100000
        count = 1
        increment = 4

        origin.Init (baseValue*count*increment, baseValue*count*increment, baseValue*count*increment)
        self.CreateAngularDimension (DimensionType.eDiameter, origin)

        count += 1
        origin.Init (baseValue*count*increment, baseValue*count*increment, baseValue*count*increment)
        self.CreateAngularDimension (DimensionType.eDiameterParallel, origin)

        count += 1
        origin.Init (baseValue*count*increment, baseValue*count*increment, baseValue*count*increment)
        self.CreateAngularDimension (DimensionType.eDiameterPerpendicular, origin)

        count += 1
        origin.Init (baseValue*count*increment, baseValue*count*increment, baseValue*count*increment)
        self.CreateAngularDimension (DimensionType.eRadiusExtended, origin)

        count += 1
        origin.Init (baseValue*count*increment, baseValue*count*increment, baseValue*count*increment)
        self.CreateAngularDimension (DimensionType.eDiameterExtended, origin)

        count += 1
        origin.Init (baseValue*count*increment, baseValue*count*increment, baseValue*count*increment)
        self.CreateAngularDimension (DimensionType.eCenter, origin)

        self.GetDgnFile().ProcessChanges(DgnSaveReason.eApplInitiated)


    #---------------------------------------------------------------------------------#
    # @bsimethod                                    Ping.Chen                  04/2024
    #---------------#---------------#---------------#---------------#---------------#------#
    def test_TestDimensionTestFixture_CreateOrdinateDimension(self):
        origin = DPoint3d (0,0,0)
        element = EditElementHandle ()
        self.CreateLinearDimension (element, DimensionType.eOrdinate, origin)

        hdlr = element.GetHandler()
        ASSERT_TRUE(None != hdlr)

        textParts = TextPartIdVector ()
        hdlr.GetTextPartIds(element, ITextQueryOptions (), textParts)
        for iter in  textParts:
            ASSERT_TRUE (None != iter)

            textBlock = hdlr.GetTextPart (element, iter)
            EXPECT_EQ (True, None != textBlock)

            strOut = textBlock.ToString()
            EXPECT_STREQ(strOut.GetWCharCP(), "*")


        self.GetDgnFile().ProcessChanges(DgnSaveReason.eApplInitiated)


    #---------------------------------------------------------------------------------#
    # @bsimethod                                    Ping.Chen                  04/2024
    #---------------#---------------#---------------#---------------#---------------#------#
    def test_TestDimensionTestFixture_CreateLabelLineDimension(self):
        origin = DPoint3d (0,0,0)
        element = EditElementHandle ()
        self.CreateLinearDimension (element, DimensionType.eLabelLine, origin)
        self.GetDgnFile().ProcessChanges(DgnSaveReason.eApplInitiated)


    #---------------------------------------------------------------------------------#
    # @bsimethod                                    Ping.Chen                  04/2024
    #---------------#---------------#---------------#---------------#---------------#------#
    def test_TestDimensionTestFixture_ApplyDimensionStyle (self):
        file = self.GetDgnFile()
        dimStyle = DimensionStyle("", file)
        ASSERT_TRUE (None != dimStyle) # "DimensionStyle method failed."
        dimRMatrix = RotMatrix ()
        dimRMatrix.InitIdentity()

        symbology = Symbology (0,0,0)
        dirFormatter = DirectionFormatter.Create ()

        dimDataObj = DimCreateData (dimStyle, self.m_textStyle, dimRMatrix, symbology, dirFormatter)

        dimEeh = EditElementHandle ()
        EXPECT_EQ(eSUCCESS, DimensionHandler.CreateDimensionElement(dimEeh, dimDataObj, DimensionType.eSizeArrow, self.GetDgnModel().Is3d(), self.GetDgnModel()))
        ASSERT_TRUE (None != dimEeh)
        EXPECT_EQ(eSUCCESS, dimEeh.AddToModel())
    
        elmHandler= dimEeh.GetHandler ()
        oldRef = dimEeh.GetElementRef()
        ASSERT_TRUE (None != oldRef)

        hdlr = elmHandler
        EXPECT_TRUE(None != hdlr)
        #Get dimension style.
        dimStyle = hdlr.GetDimensionStyle(dimEeh)
        if (dimStyle.GetName().IsEmpty ()):
            dimStyleAdd = DimensionStyle("TestDimStyle", file)
            ASSERT_TRUE (None != dimStyleAdd) # "DimensionStyle method failed."
            EXPECT_EQ(eSUCCESS, dimStyleAdd.Add())
            hdlr.ApplyDimensionStyle(dimEeh, dimStyleAdd, True)
            DimensionStyle.Delete ("TestDimStyle", file)


    #---------------------------------------------------------------------------------#
    # @bsimethod                                    Ping.Chen                  04/2024
    #---------------#---------------#---------------#---------------#---------------#------#
    def test_TestDimensionTestFixture_ReplaceText(self):
        eeh = EditElementHandle (dimHandlerTest_createLinearDimension (self.m_dimStyle, self.GetDgnModel()), True)

        hdlr = eeh.GetHandler()
        #Insert points.
        center = DPoint3d (0,0,0)
        hdlr.InsertPoint(eeh, center, None, self.m_dimStyle, -1)
        center.x -= 1000
        hdlr.InsertPoint(eeh, center, None, self.m_dimStyle, -1)
        center.x += 2000
        hdlr.InsertPoint(eeh, center, None, self.m_dimStyle, -1)

        if (eSUCCESS != eeh.AddToModel ()):
            ASSERT_TRUE (False)

        oldElemRef = eeh.GetElementRef() 
        #Query Text Part Ids
        textParts = TextPartIdVector ()
        hdlr.GetTextPartIds(eeh, ITextQueryOptions (), textParts)

        partIdCount = 0
        for iter in  textParts:
            partIdCount += 1
            if (iter == None):
                print ("T_ITextPartIdPtrVector.iterator is None.\n")
            else:
                textBlock = hdlr.GetTextPart (eeh, iter)
                if (textBlock == None):
                    print ("TextBlock is None.\n")
                elif (textBlock.IsEmpty ()):
                    print ("TextBlock is empty.\n")
                else:
                    print ("TextBlock.ToString:")
                    print (textBlock.ToString().GetWCharCP ())
                    print ("\n")

        #cout # "TextPartIds Count: " # partIdCount # endl
        #Replace first part id.
        iter = textParts[0]
        textBlock1 = hdlr.GetTextPart (eeh, iter)
        startCaret1 = textBlock1.CreateStartCaret()
        endCaret1 = textBlock1.CreateEndCaret()
        textBlock1.Remove(startCaret1, endCaret1)
        textBlock1.AppendText("Test1")
        EXPECT_EQ(ITextEdit.eReplaceStatus_Success, hdlr.ReplaceTextPart (eeh, iter, textBlock1))
        #Proceed to next part
        #iter
        #Replace second part id.
        textBlock2 = hdlr.GetTextPart (eeh, iter)
        startCaret2 = textBlock2.CreateStartCaret()
        endCaret2 = textBlock2.CreateEndCaret()
        textBlock2.Remove(startCaret2, endCaret2)
        textBlock2.AppendText("Test1")
        EXPECT_EQ(ITextEdit.eReplaceStatus_Success, hdlr.ReplaceTextPart (eeh, iter, textBlock2))
        EXPECT_EQ(eSUCCESS, eeh.ReplaceInModel (oldElemRef))
        #AddDimensionToLine(eeh)


    #---------------------------------------------------------------------------------#
    # @bsimethod                                    Ping.Chen                  04/2024
    #---------------#---------------#---------------#---------------#---------------#------#
    def test_TestDimensionTestFixture_InsertText (self):
        eeh = EditElementHandle ()
        center = DPoint3d (0,0,0)
        self.CreateLinearDimension (eeh, DimensionType.eSizeArrow, center)

        textPart = DimensionTextPartId.Create (0, eDIMTEXTPART_Primary, eDIMTEXTSUBPART_Main)

        #Single line
        testString = WString ("Test Line")
        str = self.AddText (eeh, testString, textPart)        
        EXPECT_STREQ (str.GetWCharCP(), testString.GetWCharCP())

        #Multi line
        testString = WString ("First Line")
        testString.AppendA ('\r')
        testString.AppendA ("Second Line")
        str = self.AddText (eeh, testString, textPart)
        EXPECT_STREQ (str.GetWCharCP(), testString.GetWCharCP())

        #Single line value CR. This fails even in 8.11
        testString = WString ("First Line")
        testString.AppendA ('\r')
        str = self.AddText (eeh, testString, textPart)
        #EXPECT_STREQ (str.GetWCharCP(), testString.GetWCharCP())

        #Pre value Post CR
        testString = WString ("TestFirst Line")
        testString.AppendA ('\r')
        testString.AppendA ("Second Line")
        str = self.AddText (eeh, testString, textPart)
        EXPECT_STREQ (str.GetWCharCP(), testString.GetWCharCP())

        #Pre value Post CR
        testString = WString ("First Line")
        testString.AppendA ('\r')
        testString.AppendA ("*")
        testString.AppendA ('\r')
        testString.AppendA ("Second Line")
        str = self.AddText (eeh, testString, textPart)
        EXPECT_STREQ (str.GetWCharCP(), testString.GetWCharCP())


    #---------------------------------------------------------------------------------#
    # @bsimethod                                    Ping.Chen                  04/2024
    #---------------#---------------#---------------#---------------#---------------#------#
    def test_TestDimensionTestFixture_SlantAngle (self):
        eeh = EditElementHandle ()
        center = DPoint3d (0,0,0)
        self.m_dimStyle.SetIntegerProp (3, eDIMSTYLE_PROP_General_Alignment_INTEGER)
        self.CreateLinearDimension (eeh, DimensionType.eSizeArrow, center)
    
        rMatrix = RotMatrix ()
        hdlr = eeh.GetHandler()
        hdlr.GetRotationMatrix(eeh, rMatrix)

        xVec = DVec3d ()
        yVec = DVec3d ()
        zVec= DVec3d ()
        rMatrix.GetColumns (xVec, yVec, zVec)
        slantRadians  = msGeomConst_piOver2  - xVec.AngleTo (yVec)
        ASSERT_TRUE (abs(slantRadians) < mgds_fc_epsilon) #By default it is zero

        yVec.RotateXY(msGeomConst_piOver4)
        rMatrix = RotMatrix.From2Vector (xVec, yVec)
        rMatrix.GetColumns (xVec, yVec, zVec)
        slantRadians  = yVec.AngleTo (xVec)
        hdlr.SetRotationMatrix(eeh, rMatrix)


    #---------------------------------------------------------------------------------#
    # @bsimethod                                    Ping.Chen                  04/2024
    #---------------#---------------#---------------#---------------#---------------#------#
    def test_TestDimensionTestFixture_SetProxyCell(self):
        eeh = EditElementHandle ()
        center = DPoint3d (0,0,0)
        self.CreateLinearDimension (eeh, DimensionType.eSizeArrow, center)

        sharedCellDef = EditElementHandle ()
        SharedCellDefHandler.CreateSharedCellDefElement (sharedCellDef, "SharedCellTest", self.GetDgnModel().Is3d(), self.GetDgnModel())

        lineElement= EditElementHandle ()
        end = DPoint3d(1000, 1000, 1000)
        lineSeg = DSegment3d (center, end)
        EXPECT_EQ (eSUCCESS, LineHandler.CreateLineElement (lineElement, None, lineSeg, self.GetDgnModel().Is3d(), self.GetDgnModel()))

        EXPECT_EQ (eSUCCESS, SharedCellDefHandler.AddChildComplete (sharedCellDef))
        EXPECT_EQ (eSUCCESS, sharedCellDef.AddToModel())

        sharedCell = EditElementHandle ()
        SharedCellHandler.CreateSharedCellElement (sharedCell, None, "SharedCellTest", center, None, None, self.GetDgnModel().Is3d(), self.GetDgnModel())
        EXPECT_EQ (eSUCCESS, SharedCellHandler.CreateSharedCellComplete (sharedCell))
        EXPECT_EQ (eSUCCESS, sharedCell.AddToModel())

        hdlr = eeh.GetHandler()
        rMatrix = RotMatrix ()
        rMatrix.InitIdentity()
        cellId = sharedCell.GetElementId()
        EXPECT_EQ (eSUCCESS, hdlr.SetProxyCell (eeh, cellId, center, rMatrix))

        ret, proxCell = hdlr.GetProxyCell (eeh, None, None)
        EXPECT_EQ (eSUCCESS, ret)

        EXPECT_EQ (eSUCCESS, hdlr.DeletePoint (eeh, -1))
        ret, proxCell = hdlr.GetProxyCell (eeh, None,  None)
        EXPECT_EQ (eERROR, ret)
        #SharedCellHandlerTest.CreateDef (sharedCellDef, , m_eehLines)


