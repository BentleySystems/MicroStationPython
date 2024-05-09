import os
import pytest

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *

INVALID_MODELID = -2

class DimCreateData (IDimCreateData):
    def __init__(self):
        super ().__init__ ()
        self.m_dirFormatter = None

    def setValues(self, dimStyle, textStyle, rMatrix, symbology, dirFormatter):
        self.m_dimStyle = dimStyle
        self.m_textStyle = textStyle
        self.m_rMatrix = rMatrix
        self.m_symbology = symbology
        self.m_dirFormatter = dirFormatter

    def _GetDimStyle(self):
        return self.m_dimStyle
    
    def _GetTextStyle(self):
        return self.m_textStyle
   
    def _GetSymbology(self):
        return self.m_symbology
 
    def _GetLevelID(self):
        return 0
      
    def _GetViewNumber(self):
        return 1
 
    def _GetDimRMatrix(self):
        return self.m_rMatrix
  
    def _GetViewRMatrix(self):
        return self.m_rMatrix
    
    def _GetDirFormat (self):
        return self.m_dirFormatter
       
    def _GetAnnScaleAllowed (self):
        return True
    
# function to get folder location
def getRoot(fileLocation):
    origin  = os.getenv ("SrcRoot")
    # origin  = "E:\\MicrostationVenus5\\source\\"
    if not origin:
        return origin
    origin += fileLocation
    return origin

# fetch given file from the directory
def getFileFromDirectory(fileName, fileDir):
    ret = DgnDocument.CreateFromFileName (fileName, fileDir, -101, DgnDocument.FetchMode.eWrite)

    if (ret[1] != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False

    dgnFile = DgnFile (ret[0], DgnFileOpenMode.eReadWrite)
    dgnFile.LoadDgnFile ()
    dgnFile.FillDictionaryModel ()
    return dgnFile

# function to set view group active
def setActiveViewGroup(dgnFile):
    viewGroups = dgnFile.GetViewGroups()

    #GetActiveViewGroupId is not published by __PUBLISH_SECTION_START__ and __PUBLISH_SECTION_END__ in C++ side, 
    #need to publish this in C++ side
    m_viewGroup = viewGroups.FindByElementId (dgnFile.GetActiveViewGroupId())
    
    return m_viewGroup

# prerequisite function to get folder location and dgn file
def setUpTest(fileName):
    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    dgnFile = getFileFromDirectory(fileName, fileDir)
    assert dgnFile != None
    return dgnFile

# get a particular attachment from a list of attachments
def getAttachment(attachments, name):
    for refP in attachments:
        if name == refP.GetLogicalName():
            return refP
    return None
 
@pytest.mark.skip(reason="NEEDS WORK: Fix me")
#  Test to get attachment from a dgn file
def test_GetAttachment(initDgnPlatformHost):
    dgnFile = setUpTest("AttachmentTestFile.dgn")
    m_viewGroup = setActiveViewGroup(dgnFile)  #Need to fix
    assert dgnFile != None
    masterID = dgnFile.FindModelIdByName("Default")
    assert masterID != INVALID_MODELID
    masterModel = dgnFile.LoadRootModelById(masterID, True, True, True)
    # fetch attachments from given dgn model
    assert BentleyStatus.eSUCCESS == masterModel[0].ReadAndLoadDgnAttachments(DgnAttachmentLoadOptions())
    attachments = masterModel[0].GetDgnAttachments()
    assert attachments != None
    # get a particular attachment from a list of attcahments
    attach = getAttachment(attachments ,"Tag")
    assert attach != None
    # fitSaveAndVerify("GetAttachment", m_viewGroup)

# Test to remove attachments from the dgn file
def test_RemoveAttachment(initDgnPlatformHost):
    dgnFile = setUpTest("AttachmentTestFile.dgn")
    assert dgnFile != None
    masterID = dgnFile.FindModelIdByName("Default")
    assert masterID != INVALID_MODELID
    masterModel = dgnFile.LoadRootModelById(masterID, True, True, True)
    # fetch attachments from given dgn model
    assert BentleyStatus.eSUCCESS == masterModel[0].ReadAndLoadDgnAttachments(DgnAttachmentLoadOptions())
    attachments = masterModel[0].GetDgnAttachments()
    assert attachments != None
    # get a particular attachment from a list of attcahments
    attach = getAttachment(attachments ,"Tag")
    assert attach != None
    # remove fetched attachment form the dgn model
    masterModel[0].DeleteDgnAttachment(attach)
    assert None == getAttachment(attachments ,"Tag")

# Test to create a new attachment for existing file
def test_CreateAttachmentFromExistingFile(initDgnPlatformHost):
    dgnFile = setUpTest("Tags.dgn")
    moniker = dgnFile.GetDocument().GetMoniker()
    assert None != moniker
    # dgnFile1 = setUpTest("Transparency.dgn")
    assert dgnFile != None
    masterID = dgnFile.FindModelIdByName("Default")
    assert masterID != INVALID_MODELID
    masterModel = dgnFile.LoadRootModelById(masterID, True, True, True)
    newattachment = None
    # create a new dgn attachment and write it to model
    newattachment = masterModel[0].CreateDgnAttachment(moniker,"Default", True)
    assert newattachment[0] != eDGNOPEN_STATUS_FileNotFound
    assert newattachment[0] != eDGNMODEL_STATUS_NotFound
    assert 0 == newattachment[0]
    assert BentleyStatus.eSUCCESS == newattachment[1].WriteToModel()

# Test to locate existing attachment
def test_LocateAttachment(initDgnPlatformHost):
    dgnFile = setUpTest("AttachmentTestFile.dgn")
    assert dgnFile != None
    masterID = dgnFile.FindModelIdByName("Default")
    assert masterID != INVALID_MODELID
    masterModel = dgnFile.LoadRootModelById(masterID, True, True, True)
    # fetch attachments from given dgn model
    assert BentleyStatus.eSUCCESS == masterModel[0].ReadAndLoadDgnAttachments(DgnAttachmentLoadOptions())
    attachments = masterModel[0].GetDgnAttachments()
    assert attachments != None
    # get a particular attachment from a list of attcahments
    newattachment = getAttachment(attachments ,"Tag")
    assert newattachment != None
    location = DPoint3d()
    # fetch current origin of the attachment
    newattachment.GetMasterOrigin(location)
    # set new origin for the attachment and write it to model
    newlocation = DPoint3d.From(location.x /2  , location.y /2 , 0)
    newattachment.SetMasterOrigin(newlocation)
    assert BentleyStatus.eSUCCESS == newattachment.WriteToModel()

# Test to set reference origin of the attachment
def test_SetAttachmentOrigin(initDgnPlatformHost):
    dgnFile = setUpTest("AttachmentTestFile.dgn")
    assert dgnFile != None
    masterID = dgnFile.FindModelIdByName("Default")
    assert masterID != INVALID_MODELID
    masterModel = dgnFile.LoadRootModelById(masterID, True, True, True)
    # fetch attachments from given dgn model
    assert BentleyStatus.eSUCCESS == masterModel[0].ReadAndLoadDgnAttachments(DgnAttachmentLoadOptions())
    attachments = masterModel[0].GetDgnAttachments()
    assert attachments != None
    # get a particular attachment from a list of attcahments
    newattachment = getAttachment(attachments ,"Tag")
    assert newattachment != None
    #  set reference origin for fetched attachment and write it to model
    newattachment.SetRefOrigin(DPoint3d.From(27000  , 20000 , 0))
    assert BentleyStatus.eSUCCESS == newattachment.WriteToModel()

# Test to scale attachment
def test_ScalAttachment(initDgnPlatformHost):
    dgnFile = setUpTest("AttachmentTestFile.dgn")
    assert dgnFile != None
    masterID = dgnFile.FindModelIdByName("Default")
    assert masterID != INVALID_MODELID
    masterModel = dgnFile.LoadRootModelById(masterID, True, True, True)
    assert BentleyStatus.eSUCCESS == masterModel[0].ReadAndLoadDgnAttachments(DgnAttachmentLoadOptions())
    attachments = masterModel[0].GetDgnAttachments()
    assert attachments != None
    newattachment = getAttachment(attachments ,"Tag")
    assert newattachment != None
    # set new scale factor for the attachment and write to model
    newattachment.SetStoredScale(newattachment.GetStoredScale()*50)
    assert BentleyStatus.eSUCCESS == newattachment.WriteToModel()

# Test to rotate attachment
def test_RotateAttachment(initDgnPlatformHost):
    dgnFile = setUpTest("AttachmentTestFile.dgn")
    assert dgnFile != None
    masterID = dgnFile.FindModelIdByName("Default")
    assert masterID != INVALID_MODELID
    masterModel = dgnFile.LoadRootModelById(masterID, True, True, True)
    assert BentleyStatus.eSUCCESS == masterModel[0].ReadAndLoadDgnAttachments(DgnAttachmentLoadOptions())
    attachments = masterModel[0].GetDgnAttachments()
    assert attachments != None
    newattachment = getAttachment(attachments ,"Tag")
    assert newattachment != None
    # define rotation matrix and then set it for the attachment and also write it to model
    rotation = RotMatrix.FromRowValues (0, -1, 0, 1, 0, 0, 0, 0, 1)
    newattachment.SetRotMatrix(rotation)
    assert BentleyStatus.eSUCCESS == newattachment.WriteToModel()

# Test to display and not display attachment
def test_IsDisplayedAttachment(initDgnPlatformHost):
    dgnFile = setUpTest("AttachmentTestFile.dgn")
    assert dgnFile != None
    masterID = dgnFile.FindModelIdByName("Default")
    assert masterID != INVALID_MODELID
    masterModel = dgnFile.LoadRootModelById(masterID, True, True, True)
    assert BentleyStatus.eSUCCESS == masterModel[0].ReadAndLoadDgnAttachments(DgnAttachmentLoadOptions())
    attachments = masterModel[0].GetDgnAttachments()
    assert attachments != None
    newattachment = getAttachment(attachments ,"Tag")
    assert newattachment != None

    # set display as true for attachment and write changes to model
    newattachment.SetIsDisplayed(True, True)
    assert True == newattachment.IsDisplayed()
    assert BentleyStatus.eSUCCESS == newattachment.WriteToModel()

    # set display as false for attachment and write changes to model
    newattachment.SetIsDisplayed(False, True)
    assert False == newattachment.IsDisplayed()
    assert BentleyStatus.eSUCCESS == newattachment.WriteToModel()

# Test to craete new style text for attachment
# need to complete this and one more test
def test_CreateNewDimStyleText(initDgnPlatformHost):
    dgnFile = setUpTest("AttachmentTestFile.dgn")
    assert dgnFile != None
    masterID = dgnFile.FindModelIdByName("Default")
    assert masterID != INVALID_MODELID
    masterModel = dgnFile.LoadRootModelById(masterID, True, True, True)

    m_textStyle = DgnTextStyle ("TestTextStyle", dgnFile)
    # assert True == m_textStyle.IsValid()
    assert BentleyStatus.eSUCCESS == m_textStyle.SetDoubleProperty (eTextStyle_Height, 10000.0)
    assert BentleyStatus.eSUCCESS == m_textStyle.SetDoubleProperty (eTextStyle_Width, 10000.0)
    assert BentleyStatus.eSUCCESS == m_textStyle.SetUInt32Property (eTextStyle_Color, 3)
    assert BentleyStatus.eSUCCESS == m_textStyle.SetBoolProperty (eTextStyle_ColorFlag, True)
    assert BentleyStatus.eSUCCESS == m_textStyle.Add ()

    m_dimStyle = DimensionStyle("TestDimStyle", dgnFile)
    # assert True == m_dimStyle.IsValid()
    assert BentleyStatus.eSUCCESS == m_dimStyle.SetTextStyleProp (m_textStyle, eDIMSTYLE_PROP_Text_TextStyle_TEXTSTYLE)
    assert BentleyStatus.eSUCCESS == m_dimStyle.Add()

    dirFormatter = DirectionFormatter.Create ()
    dimRMatrix = RotMatrix()
    dimRMatrix.InitIdentity()

    symbology = Symbology (1,1,1)
    symbology.style = 0
    symbology.weight = 0
    symbology.color = 0
    
    dimDataObj = DimCreateData()
    dimDataObj.setValues(m_dimStyle, m_textStyle, dimRMatrix, symbology, dirFormatter)

    m_dimEeh = EditElementHandle()
    assert BentleyStatus.eSUCCESS == DimensionHandler.CreateDimensionElement(m_dimEeh, dimDataObj, DimensionType.eSizeArrow, False, masterModel[0])
