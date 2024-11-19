#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import os
import sys
import pytest
import shutil
import tempfile

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *

m_eeh = EditElementHandle()
INVALID_MODELID = -2

m_Raster_in_ref_1_ID    = 587        
m_Raster_in_ref_2_ID    = 577        
m_Raster_in_self_ref_ID = 608

def CountElementOfType(model, elementType):
    count = 0
    for elementRef in model.GetElementsCollection():
        if( elementRef.GetElementType() == elementType):
            count = count + 1
    return count

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CreateRasterAttachment_Example_emptyFilename(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    identityTransform = Transform()
    
    extentInUOR = DPoint2d()
    extentInUOR.x = 100.0
    extentInUOR.y = 100.0
    
    # Invalid filename
    pMoniker = DgnDocumentMoniker.CreateFromFileName("########.###",None)
    assert pMoniker != None
    assert BentleyStatus.eSUCCESS == IRasterAttachmentEdit.CreateRasterAttachment(m_eeh, None, pMoniker, identityTransform, extentInUOR, ret[0])
    
    # Verify there are no Raster Attachment in the cache
    frameCollection = RasterFrameElementCollection(ret[0])
    # collection = iter(frameCollection)
    collection = list(frameCollection)
    assert collection.__len__ () == 0  #__eq__(None)
    
    # add the raster attachment to the cache
    assert BentleyStatus.eSUCCESS == m_eeh.AddToModel()
    
    # verify the raster attachment is now in the cache.
    frameCollectionAfter = RasterFrameElementCollection(ret[0])
    collection = iter(frameCollectionAfter)
    assert collection != None
    
    rasterFrameCR = next(collection)
    pIRasterAttachmentQuery = rasterFrameCR.GetHandler()
    portalName = pIRasterAttachmentQuery.GetAttachMoniker(rasterFrameCR).GetPortableName()
    assert WString("########.###") == portalName
    
    
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CreateRasterAttachment_Example(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    identityTransform = Transform()
    
    extentInUOR = DPoint2d()
    extentInUOR.x = 100.0
    extentInUOR.y = 100.0
    
    pMoniker = DgnDocumentMoniker.CreateFromRawData(repr(WString("MyFilename.tif")), 
                                                    repr(WString("MyFilespec.tif")),
                                                    None, repr(IRasterAttachmentQuery.GetSearchPath(ret[0])),False, None)
    
    assert BentleyStatus.eSUCCESS == IRasterAttachmentEdit.CreateRasterAttachment(m_eeh, None, pMoniker, 
                                                    identityTransform, extentInUOR, ret[0])
    
    # Verify there are no Raster Attachment in the cache
    frameCollection = RasterFrameElementCollection(ret[0])
    collection = list(frameCollection)
    assert collection.__len__ () == 0 #__eq__(None)
    
    # add the raster attachment to the cache
    assert BentleyStatus.eSUCCESS == m_eeh.AddToModel()
    
    # verify the raster attachment is now in the cache.
    frameCollectionAfter = RasterFrameElementCollection(ret[0])
    collection = iter(frameCollectionAfter)
    assert collection != None
    
    # Validate filename
    rasterFrameCR = next(collection)
    pIRasterAttachmentQuery = rasterFrameCR.GetHandler()
    portalName = pIRasterAttachmentQuery.GetAttachMoniker(rasterFrameCR).GetPortableName()
    assert WString("MyFilename.tif") == portalName

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])    
def test_CreateRaster8788_Example_ByteMap(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    origin = DPoint3d()
    origin.x = 0.0
    origin.y = 0.0
    origin.z = 0.0
    scale = 1.0
    format = MSRasterElemTypes.eBYTE_DATA_RASTER
    imageSize = Point2d()
    imageSize.x = 80
    imageSize.y = 40
    foreground = 1
    background = 0
    inputBufferSize = imageSize.x * imageSize.y

    imageBuffer = bytearray ()

    for row in range(0, imageSize.y):
        for col in range(0, imageSize.x):
            imageBuffer.append(col%256)

    assert BentleyStatus.eSUCCESS == RasterHdrHandler.Create(m_eeh, None, origin, scale, format, bytes(imageBuffer), imageSize, foreground, background, ret[0])

    # Verify there are no Raster Attachment in the cache
    assert 0 == CountElementOfType(ret[0], eRASTER_HDR)
    
    # add the raster attachment to the cache
    assert BentleyStatus.eSUCCESS == m_eeh.AddToModel()
    
    # verify the raster attachment is now in the cache.
    assert 1 == CountElementOfType(ret[0], eRASTER_HDR)
    
    # Extract buffer and compare values
    rasterHdrEh = ElementHandle(m_eeh.GetElementId(), ret[0])
    assert rasterHdrEh.IsValid()
    
    pRasterHdrHandler = rasterHdrEh.GetHandler()
    assert True == (pRasterHdrHandler != None)

    colorTable = UInt32Array ()
    retVal, imageBufferOut = pRasterHdrHandler.GetByteMap(rasterHdrEh, imageBuffer.__len__(), colorTable)
    assert BentleyStatus.eSUCCESS == retVal
    
    # CommitInfo buffer indexes are shift down by one position, 1 <- 2, 0 <- 1, 0 -> 255
    # Convert back input buffer before comparing the two
    # Initialize buffer with something...
    remapColor = []
    if pRasterHdrHandler.GetBackgroundIndex(rasterHdrEh):
        val = pRasterHdrHandler.GetBackgroundIndex(rasterHdrEh) - 1
    else:
        val = 255
    remapColor.append(val)
    for i in range(1, 256):
        remapColor.append(i-1)
    
    pBufferIn = 0
    pBufferOut = 0
    
    for row in range(0, imageSize.y):
        for col in range(0, imageSize.x):
            inIndex = remapColor[imageBuffer[pBufferIn]]
            outIndex = imageBufferOut[pBufferOut]
            assert inIndex == outIndex
            pBufferOut = pBufferOut + 1
            pBufferIn = pBufferIn + 1
    
# skipping for now as similar test giving access violation
# @pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
# def test_CreateRaster8788_Example_BitMap(initDgnPlatFormHost, loadDgnFile):

@pytest.mark.parametrize('fileName', ['RasterOverrides.dgn'])  
def test_RasterOverrides_ReadDirectRef(initDgnPlatformHost, loadDgnFileReadOnly):
    # ret = loadDgnFileReadOnly.CreateNewModel("Test", DgnModelType.eNormal, False)
    loadDgnFileReadOnly.FillDictionaryModel()
    rootModelId = loadDgnFileReadOnly.FindModelIdByName("Ref_1")
    assert INVALID_MODELID != rootModelId
    
    rootP = loadDgnFileReadOnly.LoadRootModelById(rootModelId, True, True, True)
    
    assert BentleyStatus.eSUCCESS == rootP[0].ReadAndLoadDgnAttachments(DgnAttachmentLoadOptions())
    
    ref2PArray = rootP[0].GetDgnAttachments()
    ref2PIter = iter(ref2PArray)
    ref2P = next(ref2PIter)
    
    assert None != ref2P
    
    pOvr = RasterOverridesCollection.GetFrom(ref2P)
    assert None != pOvr
    
    rasterInRef2Eh = ElementHandle(m_Raster_in_ref_2_ID, ref2P)
    assert rasterInRef2Eh.IsValid()

    pRasterOvr = pOvr.GetRasterOverrides(rasterInRef2Eh.GetElementRef())
    assert None != pRasterOvr
    
    assert pRasterOvr.IsOverridden(RasterOverrides.eRASTER_OVR_View4)
    assert not pRasterOvr.GetValue(RasterOverrides.eRASTER_OVR_View4)
    
    assert pRasterOvr.IsOverridden(RasterOverrides.eRASTER_OVR_View5)
    assert not pRasterOvr.GetValue(RasterOverrides.eRASTER_OVR_View5)   
    
    flags = (RasterOverrides.eRASTER_OVR_Invert | RasterOverrides.eRASTER_OVR_Transparency | 
             RasterOverrides.eRASTER_OVR_Clip | RasterOverrides.eRASTER_OVR_View4 | 
             RasterOverrides.eRASTER_OVR_View5 | RasterOverrides.eRASTER_OVR_Print)
    
    toggleValues = RasterOverrides.eRASTER_OVR_Invert | RasterOverrides.eRASTER_OVR_Transparency
    assert pRasterOvr.ovrFlags == flags
    assert pRasterOvr.toggleValues == toggleValues
    
#@pytest.mark.skip(reason="NEEDS WORK: Fix Me")
@pytest.mark.parametrize('fileName', ['rasterOverrides.dgn'])  
def test_RasterOverrides_ReadNestedRef(initDgnPlatformHost, loadDgnFileReadOnly):
    ret = loadDgnFileReadOnly.CreateNewModel("Test", DgnModelType.eNormal, False)
    loadDgnFileReadOnly.FillDictionaryModel()    
    rootP = loadDgnFileReadOnly.LoadRootModelById(loadDgnFileReadOnly.FindModelIdByName("nested_ref"), True, True, True)
    
    assert BentleyStatus.eSUCCESS == rootP[0].ReadAndLoadDgnAttachments(DgnAttachmentLoadOptions())
    
    ref1PArray = rootP[0].GetDgnAttachments()
    ref1PIter = iter(ref1PArray)
    print(ref1PIter)
    ref1P = next(ref1PIter)
    print(ref1P)
    
    assert None != ref1P
    
    pOvrRef1 = RasterOverridesCollection.GetFrom(ref1P)
    print(pOvrRef1)
    assert None != pOvrRef1
    
    ref2PArray = ref1P.GetDgnAttachments()
    ref2PIter = iter(ref2PArray)
    ref2P = next(ref2PIter)
    
    assert None != ref2P
    
    pOvrRef2 = RasterOverridesCollection.GetFrom(ref2P)
    assert None != pOvrRef2
    
    rasterInRef2Eh = ElementHandle(m_Raster_in_ref_2_ID, ref2P)
    assert rasterInRef2Eh.IsValid()

    pRasterOvr = pOvrRef2.GetRasterOverrides(rasterInRef2Eh.GetElementRef())
    assert None != pRasterOvr  
    
    flags = RasterOverrides.eRASTER_OVR_Invert | RasterOverrides.eRASTER_OVR_Transparency | RasterOverrides.eRASTER_OVR_Clip | RasterOverrides.eRASTER_OVR_View1 |  RasterOverrides.eRASTER_OVR_View2 | RasterOverrides.eRASTER_OVR_View4 | RasterOverrides.eRASTER_OVR_View5 | RasterOverrides.eRASTER_OVR_Print
    
    toggleValues = RasterOverrides.eRASTER_OVR_Invert | RasterOverrides.eRASTER_OVR_Transparency | RasterOverrides.eRASTER_OVR_View4 | RasterOverrides.eRASTER_OVR_Print

    assert pRasterOvr.ovrFlags == flags
    assert pRasterOvr.toggleValues == toggleValues
    
@pytest.mark.parametrize('fileName', ['rasterOverrides.dgn'])  
def test_RasterOverrides_ReadSelfRef(initDgnPlatformHost, loadDgnFileReadOnly):
    loadDgnFileReadOnly.FillDictionaryModel()
    rootModelId = loadDgnFileReadOnly.FindModelIdByName("self_ref")
    assert INVALID_MODELID != rootModelId
    
    rootP = loadDgnFileReadOnly.LoadRootModelById(rootModelId, True, True, True)
    
    assert BentleyStatus.eSUCCESS == rootP[0].ReadAndLoadDgnAttachments(DgnAttachmentLoadOptions())
    
    self_refPArray = rootP[0].GetDgnAttachments()
    self_refPIter = iter(self_refPArray)
    self_refP = next(self_refPIter)
    
    pOvr = RasterOverridesCollection.GetFrom (self_refP)
    assert None != self_refP
    
    rasterInRef2Eh = ElementHandle(m_Raster_in_self_ref_ID, self_refP)
    assert rasterInRef2Eh.IsValid()
    
    pRasterOvr = pOvr.GetRasterOverrides(rasterInRef2Eh.GetElementRef())
    assert None != pRasterOvr
    
    flags = (RasterOverrides.eRASTER_OVR_Invert | RasterOverrides.eRASTER_OVR_Transparency | 
             RasterOverrides.eRASTER_OVR_Clip | RasterOverrides.eRASTER_OVR_View1 | 
             RasterOverrides.eRASTER_OVR_View2 | RasterOverrides.eRASTER_OVR_View3 | 
             RasterOverrides.eRASTER_OVR_View4 | RasterOverrides.eRASTER_OVR_View5 | 
             RasterOverrides.eRASTER_OVR_View6 | RasterOverrides.eRASTER_OVR_View7 | 
             RasterOverrides.eRASTER_OVR_View8 | RasterOverrides.eRASTER_OVR_Print)
    
    toggleValues = RasterOverrides.eRASTER_OVR_Invert | RasterOverrides.eRASTER_OVR_Transparency
    
    assert pRasterOvr.ovrFlags == flags
    assert pRasterOvr.toggleValues == toggleValues

@pytest.mark.parametrize('fileName', ['rasterOverrides_empty.dgn'])     
def test_RasterOverrides_CreateDirectRef(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    # TxnManager is activated by default. In this test, I don't use transactions for
	# anything. When I close the file, I don't want the txn manager to hold on to ElementRefs.
	# Simply deactivating the txn manager is the simplest way to prevent this.    
    emptyDir = WString ()
    srcDgnFile = createTempDgnFileFromSeed (loadDgnFile)

    ITxnManager.GetManager().Deactivate()
    flags = (RasterOverrides.eRASTER_OVR_Invert | RasterOverrides.eRASTER_OVR_Clip |
             RasterOverrides.eRASTER_OVR_View1 | RasterOverrides.eRASTER_OVR_View3 | 
             RasterOverrides.eRASTER_OVR_View5 | RasterOverrides.eRASTER_OVR_View7 | 
             RasterOverrides.eRASTER_OVR_Print | RasterOverrides.eRASTER_OVR_BinaryPrintInvert)
    
    toggleValues = RasterOverrides.eRASTER_OVR_Invert | RasterOverrides.eRASTER_OVR_BinaryPrintInvert
    
    outFileName = "RasterOverrideTest_CreateDirectRef.dgn"
    
    # Creation
    assert BentleyStatus.eSUCCESS == srcDgnFile.FillDictionaryModel()
    rootModelId = srcDgnFile.FindModelIdByName("Ref_1")
    assert INVALID_MODELID != rootModelId
    
    rootP = srcDgnFile.LoadRootModelById(rootModelId, True, True, True)
    
    assert BentleyStatus.eSUCCESS == rootP[0].ReadAndLoadDgnAttachments(DgnAttachmentLoadOptions())
    
    ref2PArray = rootP[0].GetDgnAttachments()
    ref2PIter = iter(ref2PArray)
    ref2P = next(ref2PIter)
    rastersOvr = RasterOverridesCollection.GetFrom(ref2P)
    
    rasterInRef2Eh = ElementHandle(m_Raster_in_ref_2_ID, ref2P)
    assert rasterInRef2Eh.IsValid()
    
    rasterOvr = rastersOvr.GetRasterOverrides(rasterInRef2Eh.GetElementRef())
    rasterOvr.SetValue(RasterOverrides.eRASTER_OVR_Invert, True)
    rasterOvr.SetValue(RasterOverrides.eRASTER_OVR_Transparency, False)
    rasterOvr.SetValue(RasterOverrides.eRASTER_OVR_Clip, False)
    rasterOvr.SetValue(RasterOverrides.eRASTER_OVR_View1, False)
    rasterOvr.SetValue(RasterOverrides.eRASTER_OVR_View2, True)
    rasterOvr.SetValue(RasterOverrides.eRASTER_OVR_View3, False)
    rasterOvr.SetValue(RasterOverrides.eRASTER_OVR_View4, True)
    rasterOvr.SetValue(RasterOverrides.eRASTER_OVR_View5, False)
    rasterOvr.SetValue(RasterOverrides.eRASTER_OVR_View6, True)
    rasterOvr.SetValue(RasterOverrides.eRASTER_OVR_View7, False)
    rasterOvr.SetValue(RasterOverrides.eRASTER_OVR_View8, True)
    rasterOvr.SetValue(RasterOverrides.eRASTER_OVR_Print, False)
    rasterOvr.SetValue(RasterOverrides.eRASTER_OVR_BinaryPrintInvert, True)
    rasterOvr.SetValue(RasterOverrides.eRASTER_OVR_Drape, True)
    
    assert BentleyStatus.eSUCCESS == rastersOvr.Write(ref2P)
    
    # After the write we should have sync the overrides to their effective value.
    assert rastersOvr.GetRasterOverrides(rasterInRef2Eh.GetElementRef()).ovrFlags == flags
    assert rastersOvr.GetRasterOverrides(rasterInRef2Eh.GetElementRef()).toggleValues == toggleValues
    
    assert BentleyStatus.eSUCCESS == srcDgnFile.ProcessChanges (DgnSaveReason.eApplInitiated, 0)
    tempdir = tempfile.TemporaryDirectory()
    newFile =  tempdir.name + '\\' + outFileName
    shutil.copyfile (str (srcDgnFile.GetFileName ()), newFile)
    
    doc = DgnDocument.CreateForLocalFile(newFile)
    assert doc is not None

    dgnFile = DgnFile(doc, DgnFileOpenMode.eReadOnly)
    dgnFile.LoadDgnFile()
    assert BentleyStatus.eSUCCESS == dgnFile.FillDictionaryModel()
    rootModelId = dgnFile.FindModelIdByName("Ref_1")
    assert INVALID_MODELID != rootModelId
    
    rootP = dgnFile.LoadRootModelById(rootModelId, True, True, True)
    
    assert BentleyStatus.eSUCCESS == rootP[0].ReadAndLoadDgnAttachments(DgnAttachmentLoadOptions())
    
    ref2PArray = rootP[0].GetDgnAttachments()
    ref2PIter = iter(ref2PArray)
    ref2P = next(ref2PIter)
    
    pOvr = RasterOverridesCollection.GetFrom(ref2P)
    assert None != pOvr
    assert pOvr.HasOverride()
    
    rasterInRef2Eh = ElementHandle(m_Raster_in_ref_2_ID, ref2P)
    assert rasterInRef2Eh.IsValid()
    
    pRasterOvr = pOvr.GetRasterOverrides(rasterInRef2Eh.GetElementRef())
    assert None != pRasterOvr
    
    assert pRasterOvr.ovrFlags == flags
    assert pRasterOvr.toggleValues == toggleValues
 
# skipping for now as similar test is failing as some functions are not exposed
# @pytest.mark.parametrize('fileName', ['rasterOverrides_empty.dgn'])  
# def test_RasterOverrides_CreateNestedRef(initDgnPlatFormHost, loadDgnFile):

# skipping for now as similar test is failing as some functions are not exposed
# @pytest.mark.parametrize('fileName', ['rasterOverrides_empty.dgn'])  
# def test_RasterOverrides_CreateDirectRefFromNewDgn(initDgnPlatFormHost, loadDgnFile): 

# skipping for now as similar test is failing as some functions are not exposed
# @pytest.mark.parametrize('fileName', ['rasterOverrides_empty.dgn'])  
# def test_RasterOverrides_CreateNestedRefFromNewDgn(initDgnPlatFormHost, loadDgnFile):
