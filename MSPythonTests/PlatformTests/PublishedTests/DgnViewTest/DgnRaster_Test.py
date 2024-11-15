#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import os
import pytest

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *

# function to get dgn model from dgn file
def getModel (dgnFile, modelName):
    modelID = dgnFile.FindModelIdByName (modelName)
    dgnModel = dgnFile.LoadRootModelById (modelID, True, True)
    dgnFile.FillSectionsInModel (dgnModel[0], DgnModelSections.eModel)
    return dgnModel

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

# Test to fix extent (not complete)
@pytest.mark.skip(reason="NEEDS WORK: Fix me")
def test_TR218060_FixExtentOnLoad(initDgnPlatformHost):
    fileName = "rastst05.dgn"
    fileLocation = "DgnPlatformTestData\\data\\DgnViewTest\\RasterApiTest\\"
    fileDir = getRoot(fileLocation)
    dgnFile = getFileFromDirectory(fileName, fileDir)
    
    ret = getModel(dgnFile, "Model")
    # assert ret[0].GetGraphicElements() != None
    # rasterElmRefP = None
    # for ref in  graphicEle:
    #     if ref.GetElementType() == RASTER_FRAME_ELM :
    #         rasterElmRefP = ref
    #         break

# Test to fit and then display raster (not complete)
@pytest.mark.skip(reason="NEEDS WORK: Fix me")
def test_FitAndDisplayRaster(initDgnPlatformHost):
    fileNameList = ["new2d_clip_adjacentHoles.dgn", "new2d_clip_advanced.dgn", "new2d_clip_advancedInRef.dgn", "new2d_clip_autoCross.dgn", "new2d_clip_BoundaryOverlap.dgn", "new2d_clip_bspline.dgn", "new2d_clip_circleWithHole.dgn", "new2d_clip_disjointHole.dgn", "new2d_clip_simple.dgn", "new2d_clip_simpleWithHoles.dgn", "new3d_clip_disjoint.dgn", "new3d_clip_disjointWithHoles.dgn", "new3d_clip_disjointWithOverlappingHoles.dgn", "new3d_Clip_with_Zvalue.dgn"]
    fileLocation = "DgnPlatformTestData\\data\\DgnViewTest\\RasterApiTest\\ClipTest\\"
    fileDir = getRoot(fileLocation)
    for i in range(len(fileNameList)):
        dgnFile = getFileFromDirectory(fileNameList[i], fileDir)
        ret = getModel(dgnFile, "Default")
        assert ret != None
        validRasterCount = 0
        # rasterCollection = DgnRasterCollection.GetRasters(ret[0])
        # for rasterP in rasterCollection:
        #     assert None != rasterP.GetRasterSource()
        #     assert RASTERFILE_STATUS_Opened == rasterP.GetRasterSource().GetRasterFile().GetStatus()
        #     validRasterCount += 1

# Test to locate interior (not complete)
@pytest.mark.skip(reason="NEEDS WORK: Fix me")
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_Locate_Interior(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    if loadDgnFile == None:
       assert False
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = getModel(dgnFile, "Default")
    assert ret[0] != None

    fileLoc = "DgnPlatformTestData\\data\\"
    dataDir = getRoot(fileLoc)
    ret1 = DgnDocument.CreateFromFileName ("chkmrk.bmp", dataDir, -101, DgnDocument.FetchMode.eWrite)

    if (ret1[1] != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False

    dgnFile = DgnFile (ret1[0], DgnFileOpenMode.eReadWrite)
    dgnFile.LoadDgnFile ()
    dgnFile.FillDictionaryModel ()

    fullPath = dataDir + "chkmrk.bmp"
    pMoniker = DgnDocumentMoniker.CreateFromRawData(fullPath, fullPath, None, None, False, None)
    assert pMoniker != None
    # paramsObj = DgnRasterOpenParams()
    # openParams = DgnRasterOpenParams.Create (pMoniker, True)
    # assert openParams != None